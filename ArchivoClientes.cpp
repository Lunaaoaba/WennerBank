#define byte windows_byte
#include "rlutil.h"
#undef byte
#include "tipoUsuario.h"
#include "funciones.h"
#include "ArchivoClientes.h"
#include "funcionesArchivos.h"
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


// ------ FUNCIONES PARA MANEJO DE ARCHIVOS DE CLIENTES ------

bool guardarClientes(const Cliente& cliente){
    FILE* archivo = fopen("clientes.dat", "ab");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }
    fwrite(&cliente, sizeof(Cliente), 1, archivo);
    fclose(archivo);
    return true;
}

int generarIdCliente(){
    FILE* archivo = fopen("clientes.dat", "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1;
    Cliente clienteActual;
    while(fread(&clienteActual, sizeof(Cliente), 1, archivo) == 1) if(clienteActual.getIdCliente() > maxId) maxId = clienteActual.getIdCliente();
    fclose(archivo);
    return maxId + 1;
}

// nota: marco los pasos asi se entiende, para la entrega lo borro
Cliente crearCliente(){
    // 1. pedir datos
    char nombre[50], apellido[50], localidad[50], mail[50], contrasena[50];
    int dni, idCliente;
    Fecha fechaNacimiento;
    bool estado = false;
    // 2. ingreso de datos con validacion
    system("cls");
    cout << "----- CREACION DE NUEVO CLIENTE -----" << endl;
    cout << "Primer paso, ingrese sus datos:" << endl << endl;
    cout << "Ingrese DNI: ";
    dni = validarEntero(1000000, 99999999);
    cout << "Ingrese Nombre: ";
    validarCadenaLetras(nombre, 50);
    cout << "Ingrese Apellido: ";
    validarCadenaLetras(apellido, 50);
    cout << "Ingrese Localidad: ";
    validarCadenaLetras(localidad, 50);
    cout << "Ingrese Fecha de Nacimiento:" << endl;
    fechaNacimiento.cargarFecha();
    cout << "Ingrese Mail: ";
    validarCadena(mail, 50);
    while(existeMail(mail)){
        cout << "ERROR: Mail ya registrado." << endl;
        cout << "Ingrese el mail: ";
        validarCadena(mail, 50);
    }
    cout << "Ingrese Contrase" << char(164) << "a: ";
    validarCadenaLargo(contrasena, 8, 50);
    // 3. generar el id unico
    idCliente = generarIdCliente();
    // 4. crear el objeto / nuevo cliente (dsp lo meto en una linea, ahora lo dejo asi para q se vea mejor)
    Cliente nuevoCliente(
        dni,
        nombre,
        apellido,
        localidad,
        fechaNacimiento,
        mail,
        contrasena,
        estado,
        idCliente
    );
    // 5. validar mayoria de edad (no se hace al ingresar la fecha pq para ese entonces no esta el objeto creado)
    int edad = nuevoCliente.getEdad();
    if(edad < 18){
        cout << "ERROR: El cliente debe ser mayor de edad (actual: " << edad << " a" << char(164) << "os)." << endl;
        return Cliente(); // cliente vacio
    }
    // 6. mostrar y confirmar datos
    system("cls");
    cout << "----- CONFIRMACION DE DATOS -----" << endl;
    cout << nuevoCliente.mostrarDatos() << endl;
    cout << "\nConfirma la creacion del cliente? (S/N): ";
    char confirmacion;
    validarCadenaLetras(&confirmacion, 1);
    if(confirmacion == 'S' || confirmacion == 's'){
        if(guardarClientes(nuevoCliente)){
            cout << "Cliente creado con exito. ID Cliente: " << endl;
        }
        else{
            cout << "ERROR: No se pudo guardar el nuevo cliente." << endl;
        }
    }
    else cout << "Operacion cancelada." << endl;
    // 7. devolucion del cliente vacio o con datos segun confirmacion
    return nuevoCliente;
}

// despues rehacer para q use sobrecarga y funcione como buscarCliente
int posicionClientePorId(int idCliente){
    FILE* archivo = fopen("clientes.dat", "rb");
    if(archivo == nullptr) return -2;
    Cliente clienteActual;
    int pos = 0;
    while(fread(&clienteActual, sizeof(Cliente), 1, archivo) == 1){
        if(clienteActual.getIdCliente() == idCliente){
            fclose(archivo);
            return pos;
        }
        pos++;
    }
    fclose(archivo);
    return -1;
}

bool modificarCliente(const Cliente& clienteModificado){
    // saca la posicion del cliente con la funcion anterior
    int pos = posicionClientePorId(clienteModificado.getIdCliente());
    if(pos < 0){
        if(pos == -1){
            cout << "ERROR: No se encontro el cliente con ID " << clienteModificado.getIdCliente() << "." << endl;
            return false;
        }
        if(pos == -2){
            cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
            return false;
        }
    }
    // abre el archivo en lectura/escritura
    FILE* archivo = fopen("clientes.dat", "rb+");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes para modificar." << endl;
        return false;
    }
    // escribe en la posicion correspondiente (pos*sizeof hace q se mueva a la posicion del registro, SEEK_SET desde el inicio del archivo)
    fseek(archivo, (long)pos * sizeof(Cliente), SEEK_SET);
    bool exito;
    if (fwrite(&clienteModificado, sizeof(Cliente), 1, archivo) == 1) exito = true;
    else exito = false;

    fclose(archivo);
    return exito;
} 

bool modificarDatosCliente(int idCliente){
    Cliente clienteAModificar;

        if(!buscarCliente("ID", idCliente, clienteAModificar)){
        cout << "ERROR: No se encontro el cliente con ID " << idCliente << "." << endl;
        return false;
    }
    system("cls");
    cout << "Datos actuales del cliente:" << endl;
    cout << clienteAModificar.mostrarDatos() << endl << endl;

    while(true){
        cout << "Seleccione el dato a modificar:" << endl;
        cout << "1. Nombre" << endl;
        cout << "2. Apellido" << endl;
        cout << "3. Localidad" << endl;
        cout << "4. Mail" << endl;
        cout << "5. Contrase" << char(164) << "a" << endl;
        cout << "6. Finalizar/Cancelar modificación" << endl << endl;
        // dsp cambiar a rlutil
        int opcion = validarEntero(1, 6);
        switch(opcion){
            case 1: {
                char nuevoNombre[50];
                cout << "Ingrese el nuevo nombre: ";
                validarCadenaLetras(nuevoNombre, 50);
                clienteAModificar.setNombre(nuevoNombre);
                continue;
            }
            case 2: {
                char nuevoApellido[50];
                cout << "Ingrese el nuevo apellido: ";
                validarCadenaLetras(nuevoApellido, 50);
                clienteAModificar.setApellido(nuevoApellido);
                continue;
            }
            case 3: {
                char nuevaLocalidad[50];
                cout << "Ingrese la nueva localidad: ";
                validarCadenaLetras(nuevaLocalidad, 50);
                clienteAModificar.setLocalidad(nuevaLocalidad);
                continue;
            }
            case 4: {
                char nuevoMail[50];
                cout << "Ingrese el nuevo mail: ";
                validarCadena(nuevoMail, 50);
                while(existeMail(nuevoMail)){
                    cout << "ERROR: Mail ya registrado." << endl;
                    cout << "Ingrese el mail: ";
                    validarCadena(nuevoMail, 50);
                }
                clienteAModificar.setMail(nuevoMail);
                continue;
            }
            case 5: {
                char nuevaContrasena[50];
                cout << "Ingrese la nueva contrase" << char(164) << "a: ";
                validarCadenaLargo(nuevaContrasena, 8, 50);
                clienteAModificar.setContrasena(nuevaContrasena);
                continue;
            }
            case 6: {
                cout << "Modificacion finalizada..." << endl;
                break;
            }
        }
    }
    if(modificarCliente(clienteAModificar)){
        cout << "Cliente modificado correctamente." << endl;
        return true;
    }
    else{
        cout << "ERROR: No se pudo modificar el cliente." << endl;
        return false;
    }
}

bool eliminarCliente(int idCliente){
    Cliente clienteAEliminar;
    // busca el cliente por id
    if(!buscarCliente("ID", idCliente, clienteAEliminar)){
        cout << "ERROR: No se encontro el cliente con ID " << idCliente << "." << endl;
        return false;
    }
    // se fija si ya esta eliminado
    if(clienteAEliminar.getUsuarioEliminado()){
        cout << "ERROR: El cliente con ID " << idCliente << " ya se encuentra eliminado." << endl;
        return false;
    }
    // mostrar datos
    
    system("cls");
    cout << "----- CONFIRMACION DE DATOS -----" << endl;
    cout << "Cliente a eliminar:" << endl;
    cout << clienteAEliminar.mostrarDatos() << endl;
    cout << "\nConfirma la creacion del cliente? (S/N): ";
    char confirmacion;
    validarCadenaLetras(&confirmacion, 1);
    if(confirmacion == 'S' || confirmacion == 's'){
        // marca el cliente como eliminado
        clienteAEliminar.setUsuarioEliminado(true);

            // modifica el cliente en el archivo
        if(modificarCliente(clienteAEliminar)){
            cout << "Cliente con ID " << idCliente << " eliminado correctamente." << endl;
            return true;
        }
        else{
            cout << "ERROR: No se pudo eliminar el cliente con ID " << idCliente << "." << endl;
            return false;
        }
    }
    else cout << "Operacion cancelada." << endl;




}

// misma logica que eliminar pero al reves
bool restaurarCliente(int idCliente){
    Cliente clienteARestaurar;
    if(!buscarCliente("ID", idCliente, clienteARestaurar)){
        cout << "ERROR: No se encontro el cliente con ID " << idCliente << "." << endl;
        return false;
    }
    if(!clienteARestaurar.getUsuarioEliminado()){
        cout << "ERROR: El cliente con ID " << idCliente << " se encuentra activo." << endl;
        return false;
    }
    clienteARestaurar.setUsuarioEliminado(false);
    if(modificarCliente(clienteARestaurar)){
        cout << "Cliente con ID " << idCliente << " restaurado correctamente." << endl;
        return true;
    }
    else{
        cout << "ERROR: No se pudo restaurar el cliente con ID " << idCliente << "." << endl;
        return false;
    }
}

// ------ FUNCIONES PARA EL CLIENTE ------

// (etc)

// ------ FUNCIONES PARA BUSQUEDA DE CLIENTES ------

void listarClientes(){
    FILE* archivo = fopen("clientes.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;
    }
    Cliente clienteActual;
    int i = 0;
    cout << "Listado de Clientes:" << endl;
    cout << "---------------------" << endl;
    while (fread(&clienteActual, sizeof(Cliente), 1, archivo) == 1){
        // ya le meti el filtro de eliminados era una boludez
        if(!clienteActual.getUsuarioEliminado()){
            cout << clienteActual.mostrarDatos() << endl;
            i++;
            cout << "---------------------" << endl;
        }
    }
    if(i == 0){
        cout << "ERROR: No hay clientes registrados." << endl;
        cout << "---------------------" << endl;
        system("pause");
    }
    cout << "Total de clientes: " << i << endl;
    fclose(archivo);
}

// sin filtro de eliminados (para uso admin)
void listarTodosClientes(){
    FILE* archivo = fopen("clientes.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;
    }
    Cliente clienteActual;
    int i = 0;
    cout << "Listado de Clientes:" << endl;
    cout << "---------------------" << endl;
    while (fread(&clienteActual, sizeof(Cliente), 1, archivo) == 1){
        if(!clienteActual.getUsuarioEliminado()){
            cout << clienteActual.mostrarDatos() << endl;
            i++;
            cout << "---------------------" << endl;
        }
        if(clienteActual.getUsuarioEliminado()){
            cout << clienteActual.mostrarDatos() << endl;
            i++;
            cout << "[ CLIENTE ELIMINADO ]";
            cout << "---------------------" << endl;
        }
    }
    if(i == 0){
        cout << "ERROR: No hay clientes registrados." << endl;
        cout << "---------------------" << endl;
        system("pause");
    }
    cout << "Total de clientes: " << i << endl;
    fclose(archivo);
}

// como las busquedas usan todas el mismo patron, las agrupe en una funcion:
// le mande sobrecarga mas q nada pq sirve ya q es uno de los criterios evaluativos
// las q son "texto" usan la version de char y los q son numeros usan la de int
//SOBRECARGA - el q usa int: (ID, DNI, FECHA_NACIMIENTO, EDAD)
bool buscarCliente(const char* criterio, int valor, Cliente& encontrado){
    FILE* archivo = fopen("clientes.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }
    bool seEncontro = false;
    while(fread(&encontrado, sizeof(Cliente), 1, archivo)){
        // se skipea al eliminado por gil
        if(encontrado.getUsuarioEliminado()) continue;
        // comparaciones
        if(strcmp(criterio, "ID") == 0){
            if(encontrado.getIdCliente() == valor) seEncontro = true;
        }
        else if(strcmp(criterio, "DNI") == 0) {
            if(encontrado.getDni() == valor) seEncontro = true;
        }
        else if(strcmp(criterio, "EDAD") == 0){
            if(encontrado.getEdad() == valor) seEncontro = true;
        }
        else cout << "Criterio de busqueda no reconocido." << endl;

        if(seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

//SOBRECARGA - el q usa char: (NOMBRE, APELLIDO, LOCALIDAD)
bool buscarCliente(const char* criterio, const char* valor, Cliente& encontrado){
    FILE* archivo = fopen("clientes.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }
    bool seEncontro = false;
    while(fread(&encontrado, sizeof(Cliente), 1, archivo)){
        // se skipea al eliminado por gil
        if(encontrado.getUsuarioEliminado()) continue;
        // comparaciones
        if(strcmp(criterio, "NOMBRE") == 0){
            if(strcmp(encontrado.getNombre(), valor) == 0) seEncontro = true;
        }
        else if(strcmp(criterio, "APELLIDO") == 0) {
            if(strcmp(encontrado.getApellido(), valor) == 0) seEncontro = true;
        }
        else if(strcmp(criterio, "LOCALIDAD") == 0) {
            if(strcmp(encontrado.getLocalidad(), valor) == 0) seEncontro = true;
        }
        else cout << "Criterio de busqueda no reconocido." << endl;

        if(seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

//funcion fuera de sobrecarga pq funciona de otra manera
bool buscarClienteNacimiento(Fecha fechaNacimiento, Cliente &clienteEncontrado){
    FILE* archivo = fopen("clientes.dat", "rb");
    Cliente clienteActual;
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }
    while(fread(&clienteActual, sizeof(Cliente), 1, archivo) == 1){
        Fecha fecha = clienteActual.getFechaNacimiento();
        // compara los tres campos de la fecha ( lo pongo asi para q se vea mejor dsp lo cambio (funcion o algo))
        if((fecha.getDia() == fechaNacimiento.getDia())
        && (fecha.getMes() == fechaNacimiento.getMes())
        && (fecha.getAnio() == fechaNacimiento.getAnio())){
        clienteEncontrado = clienteActual;
        fclose(archivo);
        return true;
        }
    }
    fclose(archivo);
    return false;
}

bool buscarClienteId(int idCliente, Cliente &clienteEncontrado){
    return buscarCliente("ID", idCliente, clienteEncontrado);
} 

bool buscarClienteDni(int dni, Cliente &clienteEncontrado){
    return buscarCliente("DNI", dni, clienteEncontrado);
}

bool buscarClienteNombre(const char* nombre, Cliente &clienteEncontrado){
    return buscarCliente("NOMBRE", nombre, clienteEncontrado);
}

bool buscarClienteApellido(const char* apellido, Cliente &clienteEncontrado){
    return buscarCliente("APELLIDO", apellido, clienteEncontrado);
}

bool buscarClienteLocalidad(const char* localidad, Cliente &clienteEncontrado){
    return buscarCliente("LOCALIDAD", localidad, clienteEncontrado);
}

bool buscarClienteEdad(int edad, Cliente &clienteEncontrado){
    return buscarCliente("EDAD", edad, clienteEncontrado);
}