#define byte windows_byte
#include "rlutil.h"
#undef byte
#include "tipoUsuario.h"
#include "funciones.h"
#include "config.h"
#include "ArchivoClientes.h"
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
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "ab");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }
    fwrite(&cliente, sizeof(Cliente), 1, archivo);
    fclose(archivo);
    
    return true;
}

int generarIdCliente(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1;
    Cliente reg;
    while(fread(&reg, sizeof(Cliente), 1, archivo) == 1) if(reg.getIdCliente() > maxId) maxId = reg.getIdCliente();
    fclose(archivo);
    return maxId + 1;
}

Cliente crearCliente(){
    Cliente nuevoCliente;
    nuevoCliente.cargarDatos();
    int edad = nuevoCliente.getEdad();
    if(edad < 18){
        cout << "ERROR: El cliente debe ser mayor de edad (actual: " << edad << " años)." << endl;
        return Cliente();
    }
    nuevoCliente.setIdCliente(generarIdCliente());
    if(guardarClientes(nuevoCliente)) cout << "Cliente creado con exito. ID Cliente: " << nuevoCliente.getIdCliente() << endl;
    else cout << "ERROR: No se pudo guardar el nuevo cliente." << endl;
    return nuevoCliente;
}

//(usa memoria dinamica para pasar el cliente modificado)
// modificar luego para que se pueda especificar el dato a modificar, y en caso de no querer-
// modificar un dato, se mantenga el anterior, puede usarse un switch y getkey() de rlutil

bool modificarCliente(int idCliente, Cliente clienteModificado, int posicion){
    char nuevoNombre[50], nuevoApellido[50], nuevaLocalidad[50];

    if(!buscarClienteId(idCliente, clienteModificado, posicion)){
        cout << "ERROR: No se encontro el cliente con ID: " << idCliente << endl;
        return false;
    }
    cout << "Cliente encontrado: " << clienteModificado.mostrarDatos() << endl;
    cout << "-------------------------------------" << endl;
    cout << "Ingrese los nuevos datos del cliente:" << endl;

    cout << "Nuevo nombre: ";
    validarCadena("", nuevoNombre, 50);
    clienteModificado.setNombre(nuevoNombre);

    cout << "Nuevo apellido: ";
    validarCadena("", nuevoApellido, 50);
    clienteModificado.setApellido(nuevoApellido);

    cout << "Nueva localidad: ";
    validarCadena("", nuevaLocalidad, 50);
    clienteModificado.setLocalidad(nuevaLocalidad);

    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb+");
    if (archivo == nullptr) return false;

    fseek(archivo, posicion * sizeof(Cliente), SEEK_SET);
    fwrite(&clienteModificado, sizeof(Cliente), 1, archivo);
    fclose(archivo);

    cout << "Cliente modificado con éxito." << endl;
    return true;
}

void listarClientes(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;
    }
    Cliente reg;
    int i = 0;
    cout << "Listado de Clientes:" << endl;
    cout << "---------------------" << endl;
    while (fread(&reg, sizeof(Cliente), 1, archivo) == 1){
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


// ----------------------------------------------------------------------
//             FUNCIONES PARA EL CLIENTE
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE CLIENTES
// ----------------------------------------------------------------------

bool buscarClienteId(int idCliente, Cliente &clienteEncontrado, int posicion){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }
    Cliente reg;
    posicion = 0;
    while (fread(&reg, sizeof(Cliente), 1, archivo) == 1){
        if(reg.getIdCliente() == idCliente){
            clienteEncontrado = reg;
            fclose(archivo);
            return true;
        }
        posicion++;
    }
    fclose(archivo);
    return false;
}

// void buscarClienteDni(int dni, Cliente &clienteEncontrado){
// }

// void buscarClienteNombre(const char* nombre, Cliente &clienteEncontrado){
// }

// void buscarClienteApellido(const char* apellido, Cliente &clienteEncontrado){
// }

// void buscarClienteLocalidad(const char* localidad, Cliente &clienteEncontrado){
// }

// void buscarClienteEdad(int edad, Cliente &clienteEncontrado){
// }

// void buscarClienteNacimiento(Fecha fechaNacimiento, Cliente &clienteEncontrado){
// }
