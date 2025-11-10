#include "ArchivoCuentas.h"
#include "cuentaBancaria.h"
#include "config.h"
#include <cstdio>
#include <iomanip>
#include <cstring>
using namespace std;

// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE CUENTAS
// ----------------------------------------------------------------------
bool guardarCuentas(const cuentaBancaria& cuenta){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CUENTAS, "ab");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
        return false;
    }
    fwrite(&cuenta, sizeof(cuentaBancaria), 1, archivo);
    fclose(archivo);
    return true;
}

int generarIdCuenta(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CUENTAS, "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1;
    cuentaBancaria reg;
    while(fread(&reg, sizeof(cuentaBancaria), 1, archivo) == 1) if(reg.getIdCuenta() > maxId) maxId = reg.getIdCliente();
    fclose(archivo);
    return maxId + 1;
}

cuentaBancaria crearCuenta(){
    cuentaBancaria nuevaCuenta;
    nuevaCuenta.cargarDatos();
    nuevaCuenta.setIdCuenta(generarIdCuenta());
    guardarCuentas(nuevaCuenta);
    return nuevaCuenta;
}

// void modificarCuenta(cuentaBancaria* cuentaModificada){

// }

void listarCuentas(){

}

// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE CUENTAS
// ----------------------------------------------------------------------

void buscarCuentaId(int idCuenta, cuentaBancaria &cuentaEncontrada){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CUENTAS, "rb");
    cuentaBancaria reg;
    if(archivo==nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;

        while(fread(&reg, sizeof(cuentaBancaria), 1, archivo) == 1){ 
        if(reg.getIdCuenta() == idCuenta){
            cuentaEncontrada = reg;
            fclose(archivo);
            return; // ¡Encontrado!
        }
    }

    fclose(archivo);
}

}

void buscarCuentaClienteId(int idCliente, cuentaBancaria &cuentaEncontrada){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CUENTAS, "rb");
    cuentaBancaria reg;
    if(archivo==nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;

        while(fread(&reg, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(reg.getIdCliente() == idCliente){
            cuentaEncontrada = reg;
            fclose(archivo);
            return;
        }
    }

    fclose(archivo);
}


}

void buscarCuentaCvu(const char* cvu, cuentaBancaria &cuentaEncontrada){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CUENTAS, "rb");
    cuentaBancaria reg;
    if(archivo==nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;

        while(fread(&reg, sizeof(cuentaBancaria), 1, archivo) == 1){
        // strcmp devuelve 0 si las cadenas son iguales.
        if(strcmp(reg.getCvu(), cvu) == 0){
            cuentaEncontrada = reg;
            fclose(archivo);
            return;
        }
    }

    fclose(archivo);
}
}

void buscarCuentaAlias(const char* alias, cuentaBancaria &cuentaEncontrada){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CUENTAS, "rb");
    cuentaBancaria reg;
    if(archivo==nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;
        
        while(fread(&reg, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(strcmp(reg.getAlias(), alias) == 0){
            cuentaEncontrada = reg;
            fclose(archivo);
            return;
        }
    }

    fclose(archivo);
}


}

void buscarCuentaNombre(const char* nombreCuenta, cuentaBancaria &cuentaEncontrada){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CUENTAS, "rb");
    cuentaBancaria reg;
    if(archivo==nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;

        while(fread(&reg, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(strcmp(reg.getNombreCuenta(), nombreCuenta) == 0){
            cuentaEncontrada = reg;
            fclose(archivo);
            return;
        }
    }

    fclose(archivo);
}

}

// // por las dudas
void buscarCuentaSaldo(double saldo, cuentaBancaria &cuentaEncontrada){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CUENTAS, "rb");
    cuentaBancaria reg;
    if(archivo==nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;

        while(fread(&reg, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(reg.getSaldo() == saldo){
            cuentaEncontrada = reg;
            fclose(archivo);
            return;
        }
    }

    fclose(archivo );
}

}

//----------------------------------------------------------------------
//             FUNCIONES PARA LA CUENTA BANCARIA
// ----------------------------------------------------------------------

void mostrarSaldo (double saldo) {
cout<<"Su balance es: $ " <<setprecision(2) << fixed << saldo << endl;
}