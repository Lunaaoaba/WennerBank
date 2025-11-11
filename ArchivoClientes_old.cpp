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
            Fecha fecha = reg.getEdad();

            if (hora.getHoras() == hora.getHoras() &&
                hora.getMinutos() == hora.getMinutos() &&
                hora.getSegundos() == hora.getSegundos()){ 
                clienteEncontrado = reg;
                fclose(archivo);
                return;
            }
    }

    fclose(archivo);
}
}

// ----------------------------------------------------------------------
//             FUNCIONES PARA MODIFICAR CLIENTES
// ----------------------------------------------------------------------
int obtenerPosicionCliente(int idCliente){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    Cliente reg;
    if(archivo==nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return -2;

        int pos = 0;
        while(fread(&reg, sizeof(Cliente), 1, archivo) == 1){
        if(reg.getIdCliente() == idCliente){
            fclose(archivo);
            return pos;
        }
        pos++; // Pasa al siguiente índice
    }

    fclose(archivo);
    return -1; // No se encontró el IdCliente.
}
}
bool modificarCliente(Cliente clienteModificado){
    int pos = obtenerPosicionCliente(clienteModificado.getIdCliente());
    if (pos < 0){
        cout << "ERROR: Cliente con ID " << clienteModificado.getIdCliente() << " no encontrado o error de archivo." << endl;
        return false;
    } 
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    if(archivo==nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;
}
        long int desplazamiento = (long int)pos * sizeof(Cliente);

    // fseek(puntero_archivo, desplazamiento_en_bytes, origen_del_desplazamiento)
    // SEEK_SET (o 0) indica que el desplazamiento es desde el inicio del archivo.
    fseek(archivo, desplazamiento, SEEK_SET);

    //Escribe el objeto 'clienteModificado' en la posición actual del archivo.
    // Esto SOBRESCRIBE el registro existente.
    size_t escritos = fwrite(&clienteModificado, sizeof(Cliente), 1, archivo);
    

    fclose(archivo);
// RETORNA TRUE si se escribió exactamente 1 registro.
    return (escritos == 1);
}

