// #include "ArchivoClientes.h"
#include "tipoUsuario.h"
#include "config.h"
#include <cstdio>
using namespace std;


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
    while (fread(&reg, sizeof(Cliente), 1, archivo) == 1){
        if(reg.getIdCliente() > maxId){
            maxId = reg.getIdCliente();
        }
    }
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