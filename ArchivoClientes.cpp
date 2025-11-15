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

/*
(!!!) Despues, mañana 11/11 a la tarde/noche, sigo revisando y acomodando el documento,
ya que ya estaba haciendo varias funciones + otras cosas pero hubieron commits.

Revisar sobre los nuevos metodos de comparacion en Fecha y Tiempo, no deberian existir
notas al respecto en los archivos correspondientes (ArchivoEmpleados y ArchivoMovimientos).
*/
// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE CLIENTES
// ----------------------------------------------------------------------

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
    Cliente reg;
    while(fread(&reg, sizeof(Cliente), 1, archivo) == 1) if(reg.getIdCliente() > maxId) maxId = reg.getIdCliente();
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
    cin >> confirmacion;
    if(confirmacion == 'S' || confirmacion == 's'){
        if(guardarClientes(nuevoCliente)){
            cout << "Cliente creado con exito. ID Cliente: " << nuevoCliente.getIdCliente() << endl;
        }
        else{
            cout << "ERROR: No se pudo guardar el nuevo cliente." << endl;
        }
    }
    else cout << "Operacion cancelada." << endl;
    // 7. devolucion del cliente vacio o con datos segun confirmacion
    system("pause");
    return nuevoCliente;
}


// rehaciendo de 0 el modificarCliente pq se usó otra libreria OTRA VEZ!!


// ----------------------------------------------------------------------
//             FUNCIONES PARA EL CLIENTE
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE CLIENTES
// ----------------------------------------------------------------------

void listarClientes(){
    FILE* archivo = fopen("clientes.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;
    }
    Cliente reg;
    int i = 0;
    cout << "Listado de Clientes:" << endl;
    cout << "---------------------" << endl;
    while (fread(&reg, sizeof(Cliente), 1, archivo) == 1){
        // ya le meti el filtro de eliminados era una boludez
        if(!reg.getUsuarioEliminado()){
            cout << reg.mostrarDatos() << endl;
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
    Cliente reg;
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }
    while(fread(&reg, sizeof(Cliente), 1, archivo) == 1){
        Fecha fecha = reg.getFechaNacimiento();
        // compara los tres campos de la fecha
        if((fecha.getDia() == fechaNacimiento.getDia()) && (fecha.getMes() == fechaNacimiento.getMes()) && (fecha.getAnio() == fechaNacimiento.getAnio())){
        clienteEncontrado = reg;
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

