#include "funciones.h"
#include "cuentaBancaria.h"
#include "menu.h"
#include <iostream>
#include <cstdlib> 
#include <cstdio>// LIBRERIA PARA USO DE ARCHIVOS

using namespace std;

// NOTA: /ORDENAR/ Y /REHACER/ LAS FUNCIONES MARCADAS COMO REHACER
// SE DEBEN REHACER LAS FUNCIONES (y casi todo) DE ARCHIVOS PORQUE UTILIZAN OTRA LIBRERIA, NO <cstdio>
// SE NOTA BASTANTE EL USO DE LA IA
// SE DEBEN ORDENAR PORQUE NO FIGURAN IGUAL EN EL .H    // listo


// ----------------------------------------------------------------------

void crearCuenta()
{
    system("cls");
    cout << "--- CREAR CUENTA ---" << endl;
    int idCta, idCli;
    double sal;
    cout << "Ingrese ID de la cuenta: ";
    cin >> idCta;
    cout << "Ingrese ID del cliente: ";
    cin >> idCli;
    cout << "Ingrese saldo inicial: $";
    cin >> sal;
    
    // Validación básica: asegurarse de que el ID no sea 0 (valor del constructor por defecto)
    if (idCta == 0) {
        cout << "ERROR: El ID de la cuenta no puede ser 0." << endl;
        return;
    }
    
    cuentaBancaria nuevaCuenta(idCta, idCli, sal);
    if (guardarCuenta(nuevaCuenta))
    {
        cout << "Cuenta creada exitosamente!" << endl;
    }
    else
    {
        cout << "ERROR al crear la cuenta. Intente nuevamente (revisar permisos de archivo). " << endl;
    }
}

void iniciarSesion() 
{
    system("cls");
    cout << "--- INICIAR SESION ---" << endl;
    int idCta;
    cout << "Ingrese ID de la Cuenta: ";
    cin >> idCta;
    
    cuentaBancaria cuenta = buscarCuenta(idCta);
    
    // Si la cuenta encontrada no es la cuenta vacía (ID 0) y no está eliminada
    if (cuenta.getIdCuenta() != 0 && !cuenta.getEliminado()) 
    {
        cout << "Cuenta encontrada!" << endl;
        // Llama al menú de cuenta, pasando la cuenta por referencia (necesario para persistencia)
        menuCuenta(cuenta); 
    } 
    else
    {
        cout << "ERROR: Cuenta no encontrada o eliminada." << endl;
    }
}

void eliminarCuenta()
{
    system("cls");
    cout << "--- ELIMINAR CUENTA ---" << endl;
    int idCta;
    cout << "Ingrese ID de la cuenta a eliminar: ";
    cin >> idCta;
    
    // borrarCuenta marca la cuenta como eliminada y llama a modificarCuenta
    if (borrarCuenta(idCta))
    {
        cout << "Cuenta eliminada (marcada como tal)!" << endl;
    }
    else
    {
        cout << "ERROR: Cuenta no encontrada o ya estaba eliminada." << endl;
    }
}

void listarCuentas()
{
    system("cls");
    cout << "--- LISTAR CUENTAS ACTIVAS ---" << endl;
    listarTodasCuentas();
    cout << "\n--- Fin de la lista ---" << endl;
}

// ----------------------------------------------------------------------

// Realiza el depósito en la cuenta y guarda el cambio en el archivo.
bool realizarDeposito(cuentaBancaria &cuenta, double monto)
{
    // 1. Ejecuta la lógica de la clase (imprime el resultado en consola y actualiza el saldo en memoria)
    cuenta.depositar(monto);

    // 2. Guarda el cambio persistente en el archivo de datos
    if (monto > 0) {
        if (modificarCuenta(cuenta)) {
            return true;
        } else {
            cout << "ERROR: No se pudo guardar el deposito en el archivo." << endl;
            // Opcional: revertir el cambio en memoria si el guardado falla
            return false;
        }
    }
    return false;
}

// Realiza el retiro de la cuenta y guarda el cambio en el archivo.
bool realizarRetiro(cuentaBancaria &cuenta, double monto)
{
    // 1. Ejecuta la lógica de la clase (verifica saldo, actualiza en memoria e imprime resultado)
    bool exito = cuenta.retirar(monto);

    // 2. Si el retiro fue exitoso, guarda el cambio persistente
    if (exito) {
        if (modificarCuenta(cuenta)) {
            return true;
        } else {
            cout << "ERROR: No se pudo guardar el retiro en el archivo." << endl;
            // Opcional: revertir el cambio en memoria si el guardado falla
            return false;
        }
    }
    return false;
}

// ----------------------------------------------------------------------

// REHACER modificarCuenta
/*
// Función auxiliar para modificar un registro existente en el archivo
bool modificarCuenta(const cuentaBancaria &cuentaModificada)
{
    // Abre el archivo en modo binario, lectura/escritura (ios::in | ios::out)
    fstream archivo("cuentas.dat", ios::binary | ios::in | ios::out); 
    cuentaBancaria cuentaLeida;

    if (archivo.is_open())
    {
        while (archivo.read(reinterpret_cast<char *>(&cuentaLeida), sizeof(cuentaBancaria)))
        {
            // Busca la cuenta por ID
            if (cuentaLeida.getIdCuenta() == cuentaModificada.getIdCuenta())
            {
                // Se encontró el registro. 
                // Mueve el puntero de archivo hacia atrás por el tamaño del registro
                archivo.seekp(-sizeof(cuentaBancaria), ios::cur); 
                
                // Sobrescribe el registro con los nuevos datos
                archivo.write(reinterpret_cast<const char *>(&cuentaModificada), sizeof(cuentaBancaria));
                archivo.close();
                return true;
            }
        }
        archivo.close();
    }
    // Si no se pudo abrir el archivo o no se encontró la cuenta
    return false;
}
*/
// REHACER guardarCuenta
/*
bool guardarCuenta(const cuentaBancaria &nuevaCuenta)
{
    // Modo: binario | agregar al final (ios::app)
    ofstream archivo("cuentas.dat", ios::binary | ios::app);
    if (archivo.is_open())
    {
        archivo.write(reinterpret_cast<const char *>(&nuevaCuenta), sizeof(cuentaBancaria));
        archivo.close();
        return true;
    }
    return false;
}
*/
// REHACER buscarCuenta
/*
cuentaBancaria buscarCuenta(int idCuenta)
{
    cuentaBancaria cuentaLeida;
    ifstream archivo("cuentas.dat", ios::binary); // Modo: solo lectura

    if (archivo.is_open())
    {
        while (archivo.read(reinterpret_cast<char *>(&cuentaLeida), sizeof(cuentaBancaria)))
        {
            // Busca la cuenta por ID y que NO esté eliminada
            if (cuentaLeida.getIdCuenta() == idCuenta && !cuentaLeida.getEliminado())
            {
                archivo.close();
                return cuentaLeida; // ¡Encontrada y activa!
            }
        }
        archivo.close();
    }
    // Retorna una cuenta vacía (ID 0) si no se encuentra o está eliminada
    return cuentaBancaria();
}
*/
// REHACER borrarCuenta
/*
bool borrarCuenta(int idCuenta)
{
    // Busca solo cuentas activas
    cuentaBancaria cuenta = buscarCuenta(idCuenta); 

    // Verifica que la cuenta exista (ID != 0) y no esté ya eliminada (aunque buscarCuenta ya filtra)
    if (cuenta.getIdCuenta() != 0)
    {
        // Marca la cuenta como eliminada
        cuenta.setEliminado(true); 
        
        // Usa la función de modificación para escribir el cambio en el archivo
        if(modificarCuenta(cuenta)){
            return true;
        }
    }
    // Si la cuenta no se encuentra o no se pudo modificar, retorna false
    return false; 
}
*/
//REHACER listarTodasCuentas
/*
void listarTodasCuentas()
{
    cuentaBancaria cuentaLeida;
    ifstream archivo("cuentas.dat", ios::binary);
    int contador = 0; // Contador para saber si se encontraron cuentas

    if (archivo.is_open())
    {
        while (archivo.read(reinterpret_cast<char *>(&cuentaLeida), sizeof(cuentaBancaria))) 
        {
            // Solo muestra las cuentas activas
            if (!cuentaLeida.getEliminado())
            {
                cout << "------------------------" << endl;
                cuentaLeida.mostrarDatos();
                contador++;
            }
        }
        if (contador == 0) {
            cout << "No hay cuentas activas para listar." << endl;
        }
        archivo.close();
    } else {
        cout << "ERROR: No se pudo abrir el archivo de datos." << endl;
    }
}

*/