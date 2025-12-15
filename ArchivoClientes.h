#ifndef ARCHIVOCLIENTES_H
#define ARCHIVOCLIENTES_H
#include "cliente.h"
#include "fecha.h"

class ArchivoClientes{
    private:
        char _nombreArchivo[30];
    public:
        ArchivoClientes(const char* nombre = "clientes.dat");

        bool guardarClientes(const Cliente& cliente);
        Cliente crearCliente();

        bool modificarCliente(const Cliente& clienteModificado);
        bool modificarDatosCliente(int idCliente);

        bool eliminarCliente(int idCliente);
        bool restaurarCliente(int idCliente);

        void listarClientes();
        void listarTodosClientes();

        bool buscarCliente(const char* criterio, int valor, Cliente& encontrado);
        bool buscarCliente(const char* criterio, const char* valor, Cliente& encontrado);
        bool buscarClienteNacimiento(const Fecha& fechaNacimiento, Cliente& clienteEncontrado);

        int generarIdCliente();
        int posicionClientePorId(int idCliente);
};

#endif