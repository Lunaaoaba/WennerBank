#include "tipoUsuario.h"
#include "config.h"
using namespace std;

// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE CLIENTES
// ----------------------------------------------------------------------
bool guardarClientes(const Cliente& cliente){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "ab");
    if(archivo == nullptr){
        cout << "Error al abrir el archivo de clientes." << endl;
        return false;
    }
    fwrite(&cliente, sizeof(Cliente), 1, archivo);
    fclose(archivo);
    return true;
}

int generarIdCliente(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1; // si no existe el archivo el primer id es 1
    
    Cliente reg;
    while(fread(&reg, sizeof(Cliente), 1, archivo) == 1) if(reg.getIdCliente() > maxId) maxId = reg.getIdCliente();
    fclose(archivo);
    return maxId + 1;
}

Cliente crearCliente(){
    Cliente nuevoCliente;
    nuevoCliente.cargarDatos();
    nuevoCliente.setIdCliente(generarIdCliente());
    guardarClientes(nuevoCliente);
    return nuevoCliente;
}

// modificar cliente (usa memoria dinamica para pasar el cliente modificado)
void modificarCliente(Cliente* clienteModificado){

}

void listarClientes(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    if(archivo == nullptr){
        cout << "Error al abrir el archivo de clientes." << endl;
        return;
    }
    Cliente reg;
    int i = 0;
    cout << "Listado de Clientes:" << endl;
    cout << "---------------------" << endl;
    while (fread(&reg, sizeof(Cliente), 1, archivo) == 1){
        reg.mostrarDatos();
        i++;
        cout << "---------------------" << endl;
    }
    if(i == 0){
        cout << "No hay clientes registrados." << endl;
        cout << "---------------------" << endl;
    }
    cout << "Total de clientes: " << i << endl;
    fclose(archivo);
}

// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE CLIENTES
// ----------------------------------------------------------------------
void buscarClienteId(int idCliente, Cliente &clienteEncontrado){

}
void buscarClienteDni(int dni, Cliente &clienteEncontrado){

}
void buscarClienteNombre(const char* nombre, Cliente &clienteEncontrado){

}
void buscarClienteApellido(const char* apellido, Cliente &clienteEncontrado){

}
void buscarClienteLocalidad(const char* localidad, Cliente &clienteEncontrado){

}
void buscarClienteEdad(int edad, Cliente &clienteEncontrado){

}
void buscarClienteNacimiento(Fecha fechaNacimiento, Cliente &clienteEncontrado){

}

// ----------------------------------------------------------------------
//             FUNCIONES PARA EL CLIENTE
// ----------------------------------------------------------------------