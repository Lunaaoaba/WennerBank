#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <cstring>
#include "cliente.h"
#include "fecha.h"
#include "archivoClientes.h"
#include "funciones.h"
#include "funcionesArchivos.h"
#include "config.h"
#include "art.h"

using namespace std;


ArchivoClientes::ArchivoClientes(const char* nombre){ strcpy(_nombreArchivo, nombre); }

bool ArchivoClientes::guardarClientes(const Cliente& cliente){
    FILE* archivo = fopen("clientes.dat", "ab");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }
    fwrite(&cliente, sizeof(Cliente), 1, archivo);
    fclose(archivo);
    return true;
}

Cliente ArchivoClientes::crearCliente(){
    char nombre[50], apellido[50], localidad[50], mail[50], contrasena[50];
    int dni, idCliente;
    Fecha fechaNacimiento;
    bool estado = false;

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(35, 3);
    cout << char(201); centrarTexto("", char(205), 50); cout << char(187);
    rlutil::locate(35, 4);
    cout << char(186); centrarTexto("REGISTRO DE NUEVO CLIENTE", ' ', 50); cout << char(186);
    rlutil::locate(35, 5);
    cout << char(200); centrarTexto("", char(205), 50); cout << char(188);
    
    cout << endl << endl;
    rlutil::locate(40, 7);
    cout << "DNI: ";
    rlutil::locate(60, 7);
    dni = validarEntero(10000000, 99999999);
    while(existeDniCliente(dni)){
        rlutil::locate(60, 7);
        cout << string(20, ' ');
        rlutil::locate(40, 7);
        cout << string(40, ' ');
        rlutil::locate(40, 7);
        colorTexto(3);
        cout << "ERROR: DNI ya registrado";
        colorTexto(7);
        rlutil::msleep(1500);
        rlutil::locate(40, 7);
        cout << string(40, ' ');
        rlutil::locate(40, 7);
        cout << "DNI: ";
        rlutil::locate(60, 7);
        dni = validarEntero(10000000, 99999999);
    }
    
    rlutil::locate(40, 9);
    cout << "Nombre: ";
    rlutil::locate(60, 9);
    validarCadenaLetras(nombre, 50);
    
    rlutil::locate(40, 11);
    cout << "Apellido: ";
    rlutil::locate(60, 11);
    validarCadenaLetras(apellido, 50);
    
    rlutil::locate(40, 13);
    cout << "Localidad: ";
    rlutil::locate(60, 13);
    validarCadenaLetras(localidad, 50);
    
    rlutil::locate(40, 16);
    cout << "Fecha de Nacimiento:";
    fechaNacimiento.cargarFecha(60, 17);
    
    rlutil::locate(40, 21);
    cout << "Mail: ";
    rlutil::locate(60, 21);
    validarCadena(mail, 50);
    while(existeMail(mail)){
        rlutil::locate(40, 21);
        cout << string(40, ' ');
        rlutil::locate(40, 21);
        colorTexto(3);
        cout << "ERROR: Mail ya registrado";
        colorTexto(7);
        rlutil::msleep(1500);
        rlutil::locate(40, 21);
        cout << string(40, ' ');
        rlutil::locate(40, 21);
        cout << "Mail: ";
        rlutil::locate(60, 21);
        validarCadena(mail, 50);
    }
    
    rlutil::locate(40, 23);
    cout << "Contrase" << char(164) << "a (min 8 caracteres): ";
    rlutil::locate(60, 24);
    validarCadenaLargo(contrasena, 8, 50);

    idCliente = generarIdCliente();

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

    int edad = nuevoCliente.getEdad();
    if(edad < 18){
        rlutil::locate(40, 26);
        colorTexto(3);
        cout << "ERROR: El cliente debe ser mayor de edad";
        rlutil::locate(40, 27);
        cout << "(Edad actual: " << edad << " a" << char(164) << "os - Requerido: 18+)";
        colorTexto(7);
        rlutil::locate(40, 29);
        cout << "Presione cualquier tecla para continuar...";
        pausa();
        return Cliente();
    }

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(35, 3);
    cout << char(201); centrarTexto("", char(205), 50); cout << char(187);
    rlutil::locate(35, 4);
    cout << char(186); centrarTexto("CONFIRMACION DE DATOS", ' ', 50); cout << char(186);
    rlutil::locate(35, 5);
    cout << char(200); centrarTexto("", char(205), 50); cout << char(188);
    
    cout << endl << endl;
    rlutil::locate(40, 7);
    cout << "DNI: ";
    rlutil::locate(65, 7);
    cout << nuevoCliente.getDni();
    rlutil::locate(40, 8);
    cout << "Nombre: ";
    rlutil::locate(65, 8);
    cout << nuevoCliente.getNombre();
    rlutil::locate(40, 9);
    cout << "Apellido: ";
    rlutil::locate(65, 9);
    cout << nuevoCliente.getApellido();
    rlutil::locate(40, 10);
    cout << "Localidad: ";
    rlutil::locate(65, 10);
    cout << nuevoCliente.getLocalidad();
    rlutil::locate(40, 11);
    cout << "Fecha de Nacimiento: ";
    rlutil::locate(65, 11);
    cout << nuevoCliente.getFechaNacimiento().mostrarFecha() << " (Edad: " << nuevoCliente.getEdad() << " a" << char(164) << "os)";
    rlutil::locate(40, 12);
    cout << "Mail: ";
    rlutil::locate(65, 12);
    cout << nuevoCliente.getMail();
    rlutil::locate(40, 13);
    cout << "ID Cliente: ";
    rlutil::locate(65, 13);
    cout << nuevoCliente.getIdCliente();
    rlutil::locate(40, 17);
    colorTexto(6);
    cout << char(175) << " Confirma la creacion del cliente? (S/N): ";
    colorTexto(7);
    char confirmacion = validarSiNo();
    
    if(confirmacion == 'S' || confirmacion == 's'){
        if(guardarClientes(nuevoCliente)){
            rlutil::locate(40, 19);
            colorTexto(2);
            cout << " Cliente creado con exito!";
            colorTexto(7);
        }
        else{
            rlutil::locate(40, 19);
            colorTexto(3);
            cout << "ERROR: No se pudo guardar el nuevo cliente.";
            colorTexto(7);
        }
    }
    else{
        rlutil::locate(40, 19);
        colorTexto(6);
        cout << "Operacion cancelada.";
        colorTexto(7);
    }
    return nuevoCliente;
}

bool ArchivoClientes::modificarCliente(const Cliente& clienteModificado){
    int pos = posicionClientePorId(clienteModificado.getIdCliente());

    if(pos < 0){
        if(pos == -1){
            rlutil::locate(1, 1);
            colorTexto(3);
            cout << "ERROR: No se encontro el cliente con ID " << clienteModificado.getIdCliente() << "." << endl;
            colorTexto(7);
            return false;
        }
        if(pos == -2){
            rlutil::locate(1, 1);
            colorTexto(3);
            cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
            colorTexto(7);
            return false;
        }
    }
    FILE* archivo = fopen("clientes.dat", "rb+");
    if(archivo == nullptr){
        rlutil::locate(1, 1);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de clientes para modificar." << endl;
        colorTexto(7);
        return false;
    }

    fseek(archivo, static_cast<long>(pos) * (long)sizeof(Cliente), SEEK_SET);
    bool exito;
    if (fwrite(&clienteModificado, sizeof(Cliente), 1, archivo) == 1) exito = true;
    else exito = false;

    fclose(archivo);
    colorTexto(7);
    return exito;
}

bool ArchivoClientes::modificarDatosCliente(int idCliente){
    Cliente clienteAModificar;

    if(idCliente == 1){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se puede alterar este cliente.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        pausa();
        return false;
    }

    if(!buscarCliente("ID", idCliente, clienteAModificar)){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se encontro el cliente con ID " << idCliente << ".";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        pausa();
        return false;
    }
    if(clienteAModificar.getUsuarioEliminado()){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se encontro el cliente con ID " << idCliente << ".";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        pausa();
        return false;
    }

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("MODIFICACION DE DATOS DEL CLIENTE", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(35, 7);
    colorTexto(6);
    cout << "Datos actuales del cliente:";
    colorTexto(7);
    
    rlutil::locate(40, 9);
    cout << "DNI: " << clienteAModificar.getDni();
    rlutil::locate(40, 10);
    cout << "Nombre: " << clienteAModificar.getNombre();
    rlutil::locate(40, 11);
    cout << "Apellido: " << clienteAModificar.getApellido();
    rlutil::locate(40, 12);
    cout << "Localidad: " << clienteAModificar.getLocalidad();
    rlutil::locate(40, 13);
    cout << "Fecha de Nacimiento: " << clienteAModificar.getFechaNacimiento().mostrarFecha();
    rlutil::locate(40, 14);
    cout << "Mail: " << clienteAModificar.getMail();

    bool continuar = true;
    while(continuar){
        for(int i = 16; i <= 28; i++){
            rlutil::locate(35, i);
            cout << string(55, ' ');
        }
        
        rlutil::locate(35, 16);
        colorTexto(6);
        cout << "Seleccione el dato a modificar:";
        colorTexto(7);
        rlutil::locate(40, 18);
        cout << "1. Nombre";
        rlutil::locate(40, 19);
        cout << "2. Apellido";
        rlutil::locate(40, 20);
        cout << "3. Localidad";
        rlutil::locate(40, 21);
        cout << "4. Mail";
        rlutil::locate(40, 22);
        cout << "5. Contrase" << char(164) << "a";
        rlutil::locate(40, 23);
        cout << "6. Finalizar/Cancelar modificacion";
        
        rlutil::locate(35, 25);
        cout << char(175) << " Opcion: ";
        int opcion = validarEntero(1, 6);
        
        for(int i = 16; i <= 28; i++){
            rlutil::locate(35, i);
            cout << string(55, ' ');
        }
        
        switch(opcion){
            case 1: {
                char nuevoNombre[50];
                rlutil::locate(35, 18);
                colorTexto(6);
                cout << "Modificar Nombre";
                colorTexto(7);
                rlutil::locate(40, 20);
                cout << "Actual: " << clienteAModificar.getNombre();
                rlutil::locate(40, 21);
                cout << "Nuevo:  ";
                validarCadenaLetras(nuevoNombre, 50);
                clienteAModificar.setNombre(nuevoNombre);
                
                rlutil::locate(40, 10);
                cout << string(40, ' ');
                rlutil::locate(40, 10);
                cout << "Nombre: " << nuevoNombre;
                
                rlutil::locate(40, 23);
                colorTexto(2);
                cout << char(251) << " Nombre actualizado!";
                colorTexto(7);
                rlutil::msleep(1500);
                break;
            }
            case 2: {
                char nuevoApellido[50];
                rlutil::locate(35, 18);
                colorTexto(6);
                cout << "Modificar Apellido";
                colorTexto(7);
                rlutil::locate(40, 20);
                cout << "Actual: " << clienteAModificar.getApellido();
                rlutil::locate(40, 21);
                cout << "Nuevo:  ";
                validarCadenaLetras(nuevoApellido, 50);
                clienteAModificar.setApellido(nuevoApellido);
                
                rlutil::locate(40, 11);
                cout << string(40, ' ');
                rlutil::locate(40, 11);
                cout << "Apellido: " << nuevoApellido;
                
                rlutil::locate(40, 23);
                colorTexto(2);
                cout << char(251) << " Apellido actualizado!";
                colorTexto(7);
                rlutil::msleep(1500);
                break;
            }
            case 3: {
                char nuevaLocalidad[50];
                rlutil::locate(35, 18);
                colorTexto(6);
                cout << "Modificar Localidad";
                colorTexto(7);
                rlutil::locate(40, 20);
                cout << "Actual: " << clienteAModificar.getLocalidad();
                rlutil::locate(40, 21);
                cout << "Nueva:  ";
                validarCadenaLetras(nuevaLocalidad, 50);
                clienteAModificar.setLocalidad(nuevaLocalidad);
                
                rlutil::locate(40, 12);
                cout << string(40, ' ');
                rlutil::locate(40, 12);
                cout << "Localidad: " << nuevaLocalidad;
                
                rlutil::locate(40, 23);
                colorTexto(2);
                cout << char(251) << " Localidad actualizada!";
                colorTexto(7);
                rlutil::msleep(1500);
                break;
            }
            case 4: {
                char nuevoMail[50];
                rlutil::locate(35, 18);
                colorTexto(6);
                cout << "Modificar Mail";
                colorTexto(7);
                rlutil::locate(40, 20);
                cout << "Actual: " << clienteAModificar.getMail();
                rlutil::locate(40, 21);
                cout << "Nuevo:  ";
                validarCadena(nuevoMail, 50);
                while(existeMail(nuevoMail)){
                    rlutil::locate(40, 21);
                    cout << string(50, ' ');
                    rlutil::locate(40, 21);
                    colorTexto(3);
                    cout << "ERROR: Mail ya registrado";
                    colorTexto(7);
                    rlutil::msleep(1500);
                    rlutil::locate(40, 21);
                    cout << string(50, ' ');
                    rlutil::locate(40, 21);
                    cout << "Nuevo:  ";
                    validarCadena(nuevoMail, 50);
                }
                clienteAModificar.setMail(nuevoMail);
                
                rlutil::locate(40, 14);
                cout << string(40, ' ');
                rlutil::locate(40, 14);
                cout << "Mail: " << nuevoMail;
                
                rlutil::locate(40, 23);
                colorTexto(2);
                cout << char(251) << " Mail actualizado!";
                colorTexto(7);
                rlutil::msleep(1500);
                break;
            }
            case 5: {
                char contrasenaActual[50], nuevaContrasena[50];
                rlutil::locate(35, 18);
                colorTexto(6);
                cout << "Modificar Contrase" << char(164) << "a";
                colorTexto(7);
                rlutil::locate(40, 20);
                cout << "Contrase" << char(164) << "a actual: ";
                validarCadenaLargo(contrasenaActual, 8, 50);
                if(strcmp(clienteAModificar.getContrasena(), contrasenaActual) == 0){
                    rlutil::locate(40, 21);
                    cout << "Nueva contrase" << char(164) << "a:    ";
                    validarCadenaLargo(nuevaContrasena, 8, 50);
                    if(strcmp(contrasenaActual, nuevaContrasena) != 0){
                        clienteAModificar.setContrasena(nuevaContrasena);
                        rlutil::locate(40, 23);
                        colorTexto(2);
                        cout << char(251) << " Contrase" << char(164) << "a actualizada!";
                        colorTexto(7);
                    }
                    else{
                        rlutil::locate(40, 23);
                        colorTexto(3);
                        cout << "La contrase" << char(164) << "a no puede ser igual a la anterior";
                        colorTexto(7);
                    }
                }
                else{
                    rlutil::locate(40, 23);
                    colorTexto(3);
                    cout << "Contrase" << char(164) << "a incorrecta, operacion cancelada";
                    colorTexto(7);
                }
                rlutil::msleep(1500);
                break;
            }
            case 6: {
                rlutil::locate(40, 18);
                colorTexto(6);
                cout << "Finalizando modificacion...";
                colorTexto(7);
                rlutil::msleep(1000);
                continuar = false;
                break;
            }
        }
    }
    
    if(modificarCliente(clienteAModificar)){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(2);
        cout << char(251) << " Cliente modificado correctamente!";
        colorTexto(7);
        return true;
    }
    else{
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo modificar el cliente.";
        colorTexto(7);
        return false;
    }
}

bool ArchivoClientes::eliminarCliente(int idCliente){
    Cliente clienteAEliminar;

    if(idCliente == 1){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se puede eliminar este cliente.";
        colorTexto(7);

        return false;
    }

    if(!buscarCliente("ID", idCliente, clienteAEliminar)){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se encontro el cliente con ID " << idCliente << ".";
        colorTexto(7);

        return false;
    }

    if(clienteAEliminar.getUsuarioEliminado()){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: El cliente ya se encuentra eliminado.";
        colorTexto(7);

        return false;
    }

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("CONFIRMACION DE ELIMINACION", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(35, 7);
    colorTexto(6);
    cout << "Cliente a eliminar:";
    colorTexto(7);
    
    rlutil::locate(40, 9);
    cout << "ID: " << clienteAEliminar.getIdCliente();
    rlutil::locate(40, 10);
    cout << "DNI: " << clienteAEliminar.getDni();
    rlutil::locate(40, 11);
    cout << "Nombre: " << clienteAEliminar.getNombre() << " " << clienteAEliminar.getApellido();
    rlutil::locate(40, 12);
    cout << "Localidad: " << clienteAEliminar.getLocalidad();
    rlutil::locate(40, 13);
    cout << "Mail: " << clienteAEliminar.getMail();
    rlutil::locate(40, 14);
    cout << "Fecha Nacimiento: " << clienteAEliminar.getFechaNacimiento().mostrarFecha();
    
    rlutil::locate(35, 17);
    colorTexto(6);
    cout << char(175) << " Confirma la eliminacion del cliente? (S/N): ";
    colorTexto(7);
    char confirmacion = validarSiNo();
    
    if(confirmacion == 'S' || confirmacion == 's'){
        clienteAEliminar.setUsuarioEliminado(true);
        if(modificarCliente(clienteAEliminar)){
            rlutil::locate(40, 19);
            colorTexto(2);
            cout << char(251) << " Cliente eliminado correctamente!";
            colorTexto(7);
            rlutil::locate(40, 21);

            return true;
        }
        else{
            rlutil::locate(40, 19);
            colorTexto(3);
            cout << "ERROR: No se pudo eliminar el cliente.";
            colorTexto(7);
            rlutil::locate(40, 21);

            return false;
        }
    }
    else{
        rlutil::locate(40, 19);
        colorTexto(6);
        cout << "Operacion cancelada.";
        colorTexto(7);
        rlutil::locate(40, 21);

        return false;
    }
}

bool ArchivoClientes::restaurarCliente(int idCliente){
    Cliente clienteARestaurar;
    
    if(!buscarCliente("ID", idCliente, clienteARestaurar)){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se encontro el cliente con ID " << idCliente << ".";
        colorTexto(7);
        return false;
    }
    
    if(!clienteARestaurar.getUsuarioEliminado()){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: El cliente se encuentra activo.";
        colorTexto(7);
        return false;
    }
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("CONFIRMACION DE RESTAURACION", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(35, 7);
    colorTexto(6);
    cout << "Cliente a restaurar:";
    colorTexto(7);
    
    rlutil::locate(40, 9);
    cout << "ID: " << clienteARestaurar.getIdCliente();
    rlutil::locate(40, 10);
    cout << "DNI: " << clienteARestaurar.getDni();
    rlutil::locate(40, 11);
    cout << "Nombre: " << clienteARestaurar.getNombre() << " " << clienteARestaurar.getApellido();
    rlutil::locate(40, 12);
    cout << "Localidad: " << clienteARestaurar.getLocalidad();
    rlutil::locate(40, 13);
    cout << "Mail: " << clienteARestaurar.getMail();
    rlutil::locate(40, 14);
    cout << "Fecha Nacimiento: " << clienteARestaurar.getFechaNacimiento().mostrarFecha();
    
    rlutil::locate(35, 17);
    colorTexto(6);
    cout << char(175) << " Confirma la restauracion del cliente? (S/N): ";
    colorTexto(7);
    char confirmacion = validarSiNo();
    
    if(confirmacion == 'S' || confirmacion == 's'){
        clienteARestaurar.setUsuarioEliminado(false);
        if(modificarCliente(clienteARestaurar)){
            rlutil::locate(40, 19);
            colorTexto(2);
            cout << char(251) << " Cliente restaurado correctamente!";
            colorTexto(7);
            return true;
        }
        else{
            rlutil::locate(40, 19);
            colorTexto(3);
            cout << "ERROR: No se pudo restaurar el cliente.";
            colorTexto(7);
            return false;
        }
    }
    else{
        rlutil::locate(40, 19);
        colorTexto(6);
        cout << "Operacion cancelada.";
        colorTexto(7);
        return false;
    }
}

void ArchivoClientes::listarClientes(){
    FILE* archivo = fopen("clientes.dat", "rb");
    if(archivo == nullptr){
        limpiarPantalla();
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        colorTexto(7);
        return;
    }
    
    limpiarPantalla();
    colorTexto(7);
    
    cout << char(201); 
    for(int i = 0; i < 60; i++) cout << char(205); 
    cout << char(187) << endl;
    cout << char(186); 
    centrarTexto("LISTADO DE CLIENTES ACTIVOS", ' ', 60); 
    cout << char(186) << endl;
    cout << char(200); 
    for(int i = 0; i < 60; i++) cout << char(205); 
    cout << char(188) << endl << endl;
    
    Cliente clienteActual;
    int contador = 0;
    
    while (fread(&clienteActual, sizeof(Cliente), 1, archivo) == 1){
        if(!clienteActual.getUsuarioEliminado()){
            char idFormateado[20];
            formatearId(idFormateado, "CL-", clienteActual.getIdCliente(), 6);
            
            cout << "Cliente #" << (contador + 1) << endl;
            cout << "ID: " << idFormateado << endl;
            cout << "DNI: " << clienteActual.getDni() << endl;
            cout << "Nombre: " << clienteActual.getNombre() << " " << clienteActual.getApellido() << endl;
            cout << "Localidad: " << clienteActual.getLocalidad() << endl;
            cout << "Mail: " << clienteActual.getMail() << endl;
            cout << "Edad: " << clienteActual.getEdad() << " a" << char(164) << "os" << endl;
            cout << endl;
            for(int i = 0; i < 60; i++) cout << char(196);
            cout << endl << endl;
            contador++;
        }
    }
    
    if(contador == 0){
        colorTexto(3);
        cout << "No hay clientes registrados." << endl;
        colorTexto(7);
    }
    else{
        colorTexto(2);
        cout << "Total de clientes: " << contador << endl;
        colorTexto(7);
    }
    
    fclose(archivo);
}

void ArchivoClientes::listarTodosClientes(){
    FILE* archivo = fopen("clientes.dat", "rb");
    if(archivo == nullptr){
        limpiarPantalla();
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        colorTexto(7);
        return;
    }
    
    limpiarPantalla();
    colorTexto(7);
    
    cout << char(201); 
    for(int i = 0; i < 60; i++) cout << char(205); 
    cout << char(187) << endl;
    cout << char(186); 
    centrarTexto("LISTADO COMPLETO DE CLIENTES", ' ', 60); 
    cout << char(186) << endl;
    cout << char(200); 
    for(int i = 0; i < 60; i++) cout << char(205); 
    cout << char(188) << endl << endl;
    
    Cliente clienteActual;
    int contador = 0;
    
    while (fread(&clienteActual, sizeof(Cliente), 1, archivo) == 1){
        char idFormateado[20];
        formatearId(idFormateado, "CL-", clienteActual.getIdCliente(), 6);
        
        cout << "Cliente #" << (contador + 1);
        if(clienteActual.getUsuarioEliminado()){
            colorTexto(3);
            cout << " [ ELIMINADO ]";
            colorTexto(7);
        }
        cout << endl;
        cout << "ID: " << idFormateado << endl;
        cout << "DNI: " << clienteActual.getDni() << endl;
        cout << "Nombre: " << clienteActual.getNombre() << " " << clienteActual.getApellido() << endl;
        cout << "Localidad: " << clienteActual.getLocalidad() << endl;
        cout << "Mail: " << clienteActual.getMail() << endl;
        cout << "Edad: " << clienteActual.getEdad() << " a" << char(164) << "os" << endl;
        cout << endl;
        for(int i = 0; i < 60; i++) cout << char(196);
        cout << endl << endl;
        contador++;
    }
    
    if(contador == 0){
        colorTexto(3);
        cout << "No hay clientes registrados." << endl;
        colorTexto(7);
    }
    else{
        colorTexto(2);
        cout << "Total de clientes: " << contador << endl;
        colorTexto(7);
    }
    
    fclose(archivo);
}

//SOBRECARGA - el q usa int: (ID, DNI, EDAD)
bool ArchivoClientes::buscarCliente(const char* criterio, int valor, Cliente& encontrado){
    FILE* archivo = fopen("clientes.dat", "rb");
    if(archivo == nullptr){
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        colorTexto(7);
        return false;
    }
    bool seEncontro = false;
    while(fread(&encontrado, sizeof(Cliente), 1, archivo) == 1){
        if(strcmp(criterio, "ID") == 0){
            if(encontrado.getIdCliente() == valor) seEncontro = true;
        }
        else if(strcmp(criterio, "DNI") == 0) {
            if(encontrado.getDni() == valor) seEncontro = true;
        }
        else if(strcmp(criterio, "EDAD") == 0){
            if(encontrado.getEdad() == valor) seEncontro = true;
        }
        else {
            colorTexto(3);
            cout << "Criterio de b" << char(163) << "squeda no reconocido." << endl;
            colorTexto(7);
        }

        if(seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

//SOBRECARGA - el q usa char: (NOMBRE, APELLIDO, LOCALIDAD, MAIL)
bool ArchivoClientes::buscarCliente(const char* criterio, const char* valor, Cliente& encontrado){
    FILE* archivo = fopen("clientes.dat", "rb");
    if(archivo == nullptr){
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        colorTexto(7);
        return false;
    }
    bool seEncontro = false;
    while(fread(&encontrado, sizeof(Cliente), 1, archivo) == 1){
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
        else if(strcmp(criterio, "MAIL") == 0) {
            if(strcmp(encontrado.getMail(), valor) == 0) seEncontro = true;
        }
        else {
            colorTexto(3);
            cout << "Criterio de b" << char(163) << "squeda no reconocido." << endl;
            colorTexto(7);
        }

        if(seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

//funcion fuera de sobrecarga pq funciona de otra manera
bool ArchivoClientes::buscarClienteNacimiento(const Fecha& fechaNacimiento, Cliente& clienteEncontrado){
    FILE* archivo = fopen("clientes.dat", "rb");
    Cliente clienteActual;
    if(archivo == nullptr){
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        colorTexto(7);
        return false;
    }
    while(fread(&clienteActual, sizeof(Cliente), 1, archivo) == 1){
        Fecha fecha = clienteActual.getFechaNacimiento();
        if(compararFechas(fecha, fechaNacimiento)){
            clienteEncontrado = clienteActual;
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}

int ArchivoClientes::generarIdCliente(){
    FILE* archivo = fopen("clientes.dat", "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1;

    Cliente clienteActual;
    while(fread(&clienteActual, sizeof(Cliente), 1, archivo) == 1){
        if(clienteActual.getIdCliente() > maxId){
            maxId = clienteActual.getIdCliente();
        }
    }
    fclose(archivo);
    return maxId + 1;
}

int ArchivoClientes::posicionClientePorId(int idCliente){
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
