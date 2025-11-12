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

// (!!!) modificar luego para que se pueda especificar el dato a modificar, y en caso de no querer-
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
    validarCadena(nuevoNombre, 50);
    clienteModificado.setNombre(nuevoNombre);

    cout << "Nuevo apellido: ";
    validarCadena(nuevoApellido, 50);
    clienteModificado.setApellido(nuevoApellido);

    cout << "Nueva localidad: ";
    validarCadena(nuevaLocalidad, 50);
    clienteModificado.setLocalidad(nuevaLocalidad);

    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb+");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }

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


// ----------------------------------------------------------------------
//             FUNCIONES PARA EL CLIENTE
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE CLIENTES
// ----------------------------------------------------------------------
// como las busquedas usan todas el mismo patron, las agrupe en una funcion:
// le mande sobrecarga mas q nada pq sirve ya q es uno de los criterios evaluativos
// las q son "texto" usan la version de char y los q son numeros usan la de int

//SOBRECARGA - el q usa int: (ID, DNI, FECHA_NACIMIENTO, EDAD)
bool buscarCliente(const char* criterio, int valor, Cliente& encontrado){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }

    bool seEncontro = false;
    while(fread(&encontrado, sizeof(Cliente), 1, archivo)){
        // se skipea al eliminado por gil
        if(encontrado.getUsuarioEliminado()) continue;
        // comparaciones
        if(strcmp(criterio, "ID") == 0) if(encontrado.getIdCliente() == valor) seEncontro = true;
        else if(strcmp(criterio, "DNI") == 0) if(encontrado.getDni() == valor) seEncontro = true;
        else if(strcmp(criterio, "EDAD") == 0) if(encontrado.getEdad() == valor) seEncontro = true;
        else cout << "Criterio de busqueda no reconocido." << endl;

        if(seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

//SOBRECARGA - el q usa char: (NOMBRE, APELLIDO, LOCALIDAD)
bool buscarCliente(const char* criterio, const char* valor, Cliente& encontrado){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }

    bool seEncontro = false;
    while(fread(&encontrado, sizeof(Cliente), 1, archivo)){
        // se skipea al eliminado por gil
        if(encontrado.getUsuarioEliminado()) continue;
        // comparaciones
        if(strcmp(criterio, "NOMBRE") == 0) if(encontrado.getNombre() == valor) seEncontro = true;
        else if(strcmp(criterio, "APELLIDO") == 0) if(encontrado.getApellido() == valor) seEncontro = true;
        else if(strcmp(criterio, "LOCALIDAD") == 0) if(encontrado.getLocalidad() == valor) seEncontro = true;
        else cout << "Criterio de busqueda no reconocido." << endl;

        if(seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

//funcion fuera de sobrecarga pq funciona de otra manera
bool buscarClienteNacimiento(Fecha fechaNacimiento, Cliente &clienteEncontrado){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
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

void buscarClienteNombre(const char* nombre, Cliente &clienteEncontrado){
}

void buscarClienteApellido(const char* apellido, Cliente &clienteEncontrado){
}

void buscarClienteLocalidad(const char* localidad, Cliente &clienteEncontrado){
}

void buscarClienteEdad(int edad, Cliente &clienteEncontrado){
}

