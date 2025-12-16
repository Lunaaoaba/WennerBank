#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <cstring>
#include <iostream>
#include "transaccion.h"
#include "cuentaBancaria.h"
#include "fecha.h"
#include "archivoTransacciones.h"
#include "config.h"
#include "art.h"
#include "funciones.h"  

using namespace std;

ArchivoTransacciones::ArchivoTransacciones(const char* nombre){ strcpy(_nombreArchivo, nombre); }

bool ArchivoTransacciones::guardarTransaccion(const Transaccion& transaccion){
    FILE* archivo = fopen(_nombreArchivo, "ab");
    if(archivo == nullptr) return false;
    fwrite(&transaccion, sizeof(Transaccion), 1, archivo);
    fclose(archivo);
    return true;
}

int ArchivoTransacciones::generarIdTransaccion(){
    FILE* archivo = fopen(_nombreArchivo, "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1;
    
    Transaccion reg;
    while(fread(&reg, sizeof(Transaccion), 1, archivo) == 1){
        if(reg.getIdTransaccion() > maxId){
            maxId = reg.getIdTransaccion();
        }
    }
    fclose(archivo);
    return maxId + 1;
}

void ArchivoTransacciones::listarTransacciones(){
    FILE* archivo = fopen(_nombreArchivo, "rb");
    if(archivo == nullptr){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de transacciones.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    Transaccion transaccionActual;
    int i = 0;
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(20, 3);
    cout << char(201); centrarTexto("", char(205), 80); cout << char(187);
    rlutil::locate(20, 4);
    cout << char(186); centrarTexto("LISTADO DE TRANSACCIONES", ' ', 80); cout << char(186);
    rlutil::locate(20, 5);
    cout << char(200); centrarTexto("", char(205), 80); cout << char(188);
    
    rlutil::locate(1, 7);

    while (fread(&transaccionActual, sizeof(Transaccion), 1, archivo) == 1){
        char idFormateado[15];
        formatearId(idFormateado, "TR", transaccionActual.getIdTransaccion(), 6);
        
        cout << "  ID Transacci" << char(162) << "n: " << idFormateado << endl;
        cout << transaccionActual.mostrarDatos() << endl;
        cout << "  " << string(76, char(196)) << endl << endl;
        i++;
    }
    if(i == 0){
        colorTexto(3);
        cout << "  No hay transacciones registradas." << endl;
        colorTexto(7);
    }
    else{
        colorTexto(2);
        cout << "  Total: " << i << " transacciones" << endl;
        colorTexto(7);
    }

    fclose(archivo);
}

void ArchivoTransacciones::listarTransaccionesCuenta(int idCuenta){
    FILE* archivo = fopen(_nombreArchivo, "rb");
    if(archivo == nullptr){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de transacciones.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    Transaccion transaccionActual;
    int i = 0;
    
    limpiarPantalla();
    colorTexto(7);
    
    char idCuentaFormateado[15];
    formatearId(idCuentaFormateado, "CU", idCuenta, 6);
    
    rlutil::locate(20, 3);
    cout << char(201); centrarTexto("", char(205), 80); cout << char(187);
    rlutil::locate(20, 4);
    cout << char(186); centrarTexto("TRANSACCIONES DE LA CUENTA " + string(idCuentaFormateado), ' ', 80); cout << char(186);
    rlutil::locate(20, 5);
    cout << char(200); centrarTexto("", char(205), 80); cout << char(188);
    
    rlutil::locate(1, 7);

    while(fread(&transaccionActual, sizeof(Transaccion), 1, archivo) == 1){
        if(transaccionActual.getIdCuentaOrigen() == idCuenta || transaccionActual.getIdCuentaDestino() == idCuenta){
            char idFormateado[15];
            formatearId(idFormateado, "TR", transaccionActual.getIdTransaccion(), 6);
            
            cout << "  ID Transacci" << char(162) << "n: " << idFormateado << " ";
            
            // Indicar si es entrada o salida con colores
            if(transaccionActual.getIdCuentaOrigen() == idCuenta && transaccionActual.getIdCuentaDestino() == idCuenta){
                colorTexto(6);
                cout << "[INTERNO]";
                colorTexto(7);
            }
            else if(transaccionActual.getIdCuentaOrigen() == idCuenta){
                colorTexto(3);
                cout << "[SALIDA -]";
                colorTexto(7);
            }
            else{
                colorTexto(2);
                cout << "[ENTRADA +]";
                colorTexto(7);
            }
            cout << endl;
            
            cout << transaccionActual.mostrarDatos() << endl;
            cout << "  " << string(76, char(196)) << endl << endl;
            i++;
        }
    }
    if(i == 0){
        colorTexto(3);
        cout << "  No hay transacciones registradas para esta cuenta." << endl;
        colorTexto(7);
    }
    else{
        colorTexto(2);
        cout << "  Total: " << i << " transacciones" << endl;
        colorTexto(7);
    }

    fclose(archivo);
}

bool ArchivoTransacciones::buscarTransaccion(int idTransaccion, Transaccion& encontrada){
    FILE* archivo = fopen(_nombreArchivo, "rb");
    if(archivo == nullptr){
        rlutil::locate(1, 1);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        colorTexto(7);
        return false;
    }

    while(fread(&encontrada, sizeof(Transaccion), 1, archivo) == 1){
        if(encontrada.getIdTransaccion() == idTransaccion){
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}