#include "tipoUsuario.h"
#include "funciones.h"
#include "config.h"
#include <cstring>
#include <iostream>
using namespace std;

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
// void modificarCliente(Cliente* clienteModificado){
// }

// !!! implementar el filtrado de clientes eliminados
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
        cout << reg.mostrarDatos() << endl;
        i++;
        cout << "---------------------" << endl;
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
// EL VOID LO CAMBIE A UN BOOL
bool buscarClienteId(int idCliente, Cliente &clienteEncontrado){
FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
if(archivo==nullptr){
    cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }
    Cliente reg;
    bool encontrado = false;
    
    // Leer hasta el final del archivo o hasta encontrar la coincidencia
    while (fread(&reg, sizeof(Cliente), 1, archivo) == 1) { 
        if (reg.getIdCliente() == idCliente) {
            clienteEncontrado = reg;
            encontrado = true;
            break;
        }
    }
    fclose(archivo);
    return encontrado;
}

bool buscarClienteDni(int dni, Cliente &clienteEncontrado){
FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
if(archivo==nullptr){
    cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }
    Cliente reg;
    bool encontrado = false;
    
    while (fread(&reg, sizeof(Cliente), 1, archivo) == 1) { 
        if (reg.getDni() == dni) {
            clienteEncontrado = reg;
            encontrado = true;
            break;
        }
    }
    fclose(archivo);
    return encontrado;
}

void buscarClienteNombre(const char* nombre, Cliente &clienteEncontrado){
FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    Cliente reg;
    if(archivo==nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;
        
        while(fread(&reg, sizeof(Cliente), 1, archivo) == 1){ 
        if(strcmp(reg.getNombre(), nombre) == 0){
            clienteEncontrado = reg; 
            fclose(archivo); 
            return; 
        }
    }

    fclose(archivo); // Cierra el archivo si no se encontró antes
}
    }
// }

void buscarClienteApellido(const char* apellido, Cliente &clienteEncontrado){
FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    Cliente reg;
    if(archivo==nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;
        
        while(fread(&reg, sizeof(Cliente), 1, archivo) == 1){
        if(strcmp(reg.getApellido(), apellido) == 0){
            clienteEncontrado = reg;
            fclose(archivo);
            return;
        }
    }

    fclose(archivo);
}
}

void buscarClienteLocalidad(const char* localidad, Cliente &clienteEncontrado){
FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    Cliente reg;
    if(archivo==nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;

        while(fread(&reg, sizeof(Cliente), 1, archivo) == 1){
        if(strcmp(reg.getLocalidad(), localidad) == 0){
            clienteEncontrado = reg;
            fclose(archivo);
            return;
        }
    }

    fclose(archivo);
}
}

void buscarClienteEdad(int edad, Cliente &clienteEncontrado){
FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    Cliente reg;
    if(archivo==nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;

        while(fread(&reg, sizeof(Cliente), 1, archivo) == 1){
        if(reg.getEdad() == edad){
            clienteEncontrado = reg;
            fclose(archivo);
            return;
        }
    }

    fclose(archivo);
}
}

void buscarClienteNacimiento(Fecha fechaNacimiento, Cliente &clienteEncontrado){
FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    Cliente reg;
    if(archivo==nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;

        while(fread(&reg, sizeof(Cliente), 1, archivo) == 1){
        if(reg.getFechaNacimiento().esIgual(fechaNacimiento)){ 
            clienteEncontrado = reg;
            fclose(archivo);
            return;
        }
    }

    fclose(archivo);
}
}
