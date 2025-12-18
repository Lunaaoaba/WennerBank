#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "menuCliente.h"
#include "ArchivoClientes.h"
#include "ArchivoCuentas.h"
#include "ArchivoTransacciones.h"
#include "funciones.h"
#include "menuCuenta.h"
#include "config.h"
#include "art.h"

using namespace std;

void redibujarMenuCliente(const Cliente& clienteActual, const char* idFormateado){
    colorTexto(7);
    limpiarPantalla();

    rlutil::locate(35, 3);
    cout << char(201); centrarTexto("", char(205), 50); cout << char(187);
    rlutil::locate(35, 4);
    cout << char(186); centrarTexto("MENU PRINCIPAL", ' ', 50); cout << char(186);
    rlutil::locate(35, 5);
    cout << char(200); centrarTexto("", char(205), 50); cout << char(188);

    rlutil::locate(40, 7);
    colorTexto(6);
    cout << "Cliente: " << clienteActual.getNombre() << " " << clienteActual.getApellido();
    colorTexto(7);
    rlutil::locate(40, 8);
    cout << "ID: " << idFormateado;

    rlutil::locate(44, 11);
    cout << "Ver mis cuentas";
    rlutil::locate(44, 12);
    cout << "Ingresar a una cuenta";
    rlutil::locate(44, 13);
    cout << "Crear nueva cuenta";
    rlutil::locate(44, 14);
    cout << "Ver historial de transacciones";
    rlutil::locate(44, 15);
    cout << "Cerrar una cuenta";
    rlutil::locate(44, 16);
    cout << "Ver saldo total";
    rlutil::locate(44, 17);
    cout << "Ver mis datos personales";
    rlutil::locate(44, 18);
    cout << "Modificar mis datos";
    rlutil::locate(44, 19);
    cout << "Cambiar contrase" << char(164) << "a";
    rlutil::locate(44, 20);
    cout << "Cerrar sesi" << char(162) << "n";
}

void menuCliente(int idCliente){
    ArchivoClientes objClientes;
    Cliente clienteActual;

    if(!objClientes.buscarCliente("ID", idCliente, clienteActual)){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo cargar la informaci" << char(162) << "n del cliente.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    bool continuar = true;
    while(continuar){
        rlutil::hidecursor();
        int opcion = 0;
        bool curs = true;

        colorTexto(7);
        limpiarPantalla();

        rlutil::locate(35, 3);
        cout << char(201); centrarTexto("", char(205), 50); cout << char(187);
        rlutil::locate(35, 4);
        cout << char(186); centrarTexto("MENU CLIENTE", ' ', 50); cout << char(186);
        rlutil::locate(35, 5);
        cout << char(200); centrarTexto("", char(205), 50); cout << char(188);

        rlutil::locate(40, 7);
        colorTexto(6);
        cout << "Cliente: " << clienteActual.getNombre() << " " << clienteActual.getApellido();
        colorTexto(7);

        char idFormateado[15];
        formatearId(idFormateado, "CL", idCliente, 6);
        rlutil::locate(40, 8);
        cout << "ID: " << idFormateado;

        rlutil::locate(44, 11);
        cout << "Ver mis cuentas";
        rlutil::locate(44, 12);
        cout << "Ingresar a una cuenta";
        rlutil::locate(44, 13);
        cout << "Crear nueva cuenta";
        rlutil::locate(44, 14);
        cout << "Ver historial de transacciones";
        rlutil::locate(44, 15);
        cout << "Cerrar una cuenta";
        rlutil::locate(44, 16);
        cout << "Ver saldo total";
        rlutil::locate(44, 17);
        cout << "Ver mis datos personales";
        rlutil::locate(44, 18);
        cout << "Modificar mis datos";
        rlutil::locate(44, 19);
        cout << "Cambiar contrase" << char(164) << "a";
        rlutil::locate(44, 20);
        cout << "Cerrar sesi" << char(162) << "n";

        while(curs){
            rlutil::locate(42, 11 + opcion);
            cout << char(175);
            int tecla = rlutil::getkey();

            rlutil::locate(42, 11 + opcion);
            cout << " ";

            switch(tecla){
                case 14:
                    opcion--;
                    if(opcion < 0) opcion = 9;
                    break;

                case 15:
                    opcion++;
                    if(opcion > 9) opcion = 0;
                    break;

                case 1:
                    curs = false;
                    rlutil::showcursor();
                    limpiarPantalla();

                    switch(opcion){
                        case 0:
                            verMisCuentas(idCliente);
                            curs = true;
                            rlutil::hidecursor();
                            redibujarMenuCliente(clienteActual, idFormateado);
                            break;

                        case 1:
                            ingresarACuenta(idCliente);
                            curs = true;
                            rlutil::hidecursor();
                            redibujarMenuCliente(clienteActual, idFormateado);
                            break;

                        case 2:
                            crearMiCuenta(idCliente);
                            curs = true;
                            rlutil::hidecursor();
                            redibujarMenuCliente(clienteActual, idFormateado);
                            break;

                        case 3:
                            verMisTransacciones(idCliente);
                            curs = true;
                            rlutil::hidecursor();
                            redibujarMenuCliente(clienteActual, idFormateado);
                            break;

                        case 4:
                            cerrarMiCuenta(idCliente);
                            curs = true;
                            rlutil::hidecursor();
                            redibujarMenuCliente(clienteActual, idFormateado);
                            break;

                        case 5:
                            verSaldoTotal(idCliente);
                            curs = true;
                            rlutil::hidecursor();
                            redibujarMenuCliente(clienteActual, idFormateado);
                            break;

                        case 6:
                            verMisDatos(idCliente);
                            curs = true;
                            rlutil::hidecursor();
                            redibujarMenuCliente(clienteActual, idFormateado);
                            break;

                        case 7:
                            modificarMisDatos(idCliente);
                            curs = true;
                            rlutil::hidecursor();
                            redibujarMenuCliente(clienteActual, idFormateado);
                            break;

                        case 8:
                            cambiarPassword(idCliente);
                            curs = true;
                            rlutil::hidecursor();
                            redibujarMenuCliente(clienteActual, idFormateado);
                            break;

                        case 9:
                            continuar = false;
                            curs = false;
                            rlutil::showcursor();
                            break;
                    }
                    break;
            }
        }
    }
}

void verMisCuentas(int idCliente){
    ArchivoCuentas objCuentas;
    objCuentas.listarCuentasCliente(idCliente);
    rlutil::anykey();
}

void ingresarACuenta(int idCliente){
    int intentos = 0;
    const int maxIntentos = 3;

    while(intentos < maxIntentos){
        limpiarPantalla();
        colorTexto(7);

        rlutil::locate(30, 3);
        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
        rlutil::locate(30, 4);
        cout << char(186); centrarTexto("INGRESAR A CUENTA BANCARIA", ' ', 60); cout << char(186);
        rlutil::locate(30, 5);
        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);

        rlutil::locate(35, 8);
        colorTexto(6);
        cout << "Ingrese el ID de la cuenta: ";
        colorTexto(7);
        int idCuenta = validarEntero(1, 999999);

        cuentaBancaria cuentaActual;
        ArchivoCuentas objCuentas;
        if(!objCuentas.buscarCuenta("ID", idCuenta, cuentaActual)){
            rlutil::locate(35, 11);
            colorTexto(3);
            cout << "ERROR: No se encontr" << char(162) << " ninguna cuenta con ese ID.";
            colorTexto(7);
            intentos++;
            rlutil::locate(35, 12);
            cout << "Intentos restantes: " << maxIntentos - intentos;
            rlutil::locate(35, 14);
            cout << "Presione cualquier tecla para continuar...";
            rlutil::anykey();
            continue;
        }
        if(cuentaActual.getIdCliente() != idCliente){
            rlutil::locate(35, 11);
            colorTexto(3);
            cout << "ERROR: Esta cuenta no le pertenece.";
            colorTexto(7);
            intentos++;
            rlutil::locate(35, 12);
            cout << "Intentos restantes: " << maxIntentos - intentos;
            rlutil::locate(35, 14);
            cout << "Presione cualquier tecla para continuar...";
            rlutil::anykey();
            continue;
        }
        if(cuentaActual.getCuentaEliminada()){
            rlutil::locate(35, 11);
            colorTexto(3);
            cout << "ERROR: Esta cuenta est" << char(160) << " cerrada.";
            colorTexto(7);
            intentos++;
            rlutil::locate(35, 12);
            cout << "Intentos restantes: " << maxIntentos - intentos;
            rlutil::locate(35, 14);
            cout << "Presione cualquier tecla para continuar...";
            rlutil::anykey();
            continue;
        }

        menuCuenta(idCliente, idCuenta);
        return;
    }

    limpiarPantalla();
    rlutil::locate(40, 15);
    colorTexto(3);
    cout << "Ha superado el n" << char(163) << "mero m" << char(160) << "ximo de intentos.";
    colorTexto(7);
    rlutil::locate(40, 17);
    cout << "Presione cualquier tecla para continuar...";
    rlutil::anykey();
}

void crearMiCuenta(int idCliente){
    ArchivoCuentas objCuentas;
    objCuentas.crearCuenta(idCliente);
    rlutil::anykey();
}

void verMisDatos(int idCliente){
    limpiarPantalla();
    colorTexto(7);

    Cliente clienteActual;
    ArchivoClientes objClientes;
    if(objClientes.buscarCliente("ID", idCliente, clienteActual)){
        rlutil::locate(30, 3);
        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
        rlutil::locate(30, 4);
        cout << char(186); centrarTexto("MIS DATOS PERSONALES", ' ', 60); cout << char(186);
        rlutil::locate(30, 5);
        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);

        rlutil::locate(1, 7);
        cout << clienteActual.mostrarDatos() << endl;
    }
    else{
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo cargar la informaci" << char(162) << "n.";
        colorTexto(7);
    }
    rlutil::locate(1, 25);
    cout << "Presione cualquier tecla para continuar...";
    rlutil::anykey();
}

void modificarMisDatos(int idCliente){
    ArchivoClientes objClientes;
    objClientes.modificarDatosCliente(idCliente);
}

void verMisTransacciones(int idCliente){
    limpiarPantalla();
    colorTexto(7);

    ArchivoCuentas objCuentas;
    ArchivoTransacciones objTransacciones;

    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de cuentas.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    cuentaBancaria cuentaActual;
    int totalCuentas = 0;

    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(cuentaActual.getIdCliente() == idCliente && !cuentaActual.getCuentaEliminada()){
            totalCuentas++;
        }
    }
    fclose(archivo);

    if(totalCuentas == 0){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "No tienes cuentas activas para mostrar transacciones.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    rlutil::locate(25, 3);
    cout << char(201); centrarTexto("", char(205), 70); cout << char(187);
    rlutil::locate(25, 4);
    cout << char(186); centrarTexto("MIS TRANSACCIONES", ' ', 70); cout << char(186);
    rlutil::locate(25, 5);
    cout << char(200); centrarTexto("", char(205), 70); cout << char(188);

    rlutil::locate(30, 8);
    colorTexto(6);
    cout << "Seleccione una cuenta para ver sus transacciones:";
    colorTexto(7);

    archivo = fopen("cuentas.dat", "rb");
    int linea = 10;
    int contador = 1;

    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(cuentaActual.getIdCliente() == idCliente && !cuentaActual.getCuentaEliminada()){
            char idFormateado[15];
            formatearId(idFormateado, "CU", cuentaActual.getIdCuenta(), 6);

            rlutil::locate(35, linea);
            cout << contador << ". " << idFormateado << " - " << cuentaActual.getNombreCuenta();
            rlutil::locate(70, linea);
            cout << "($" << fixed << setprecision(2) << cuentaActual.getSaldo() << ")";
            linea++;
            contador++;
        }
    }
    fclose(archivo);

    rlutil::locate(35, linea + 1);
    cout << contador << ". Volver al men" << char(163) << " anterior";

    rlutil::locate(30, linea + 3);
    cout << char(175) << " Opci" << char(162) << "n: ";
    int opcion = validarEntero(1, contador);

    if(opcion == contador) return;

    archivo = fopen("cuentas.dat", "rb");
    contador = 1;
    int idCuentaSeleccionada = -1;

    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(cuentaActual.getIdCliente() == idCliente && !cuentaActual.getCuentaEliminada()){
            if(contador == opcion){
                idCuentaSeleccionada = cuentaActual.getIdCuenta();
                break;
            }
            contador++;
        }
    }
    fclose(archivo);

    if(idCuentaSeleccionada != -1){
        objTransacciones.listarTransaccionesCuenta(idCuentaSeleccionada);
        rlutil::locate(1, 25);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
    }
}

void cerrarMiCuenta(int idCliente){
    limpiarPantalla();
    colorTexto(7);

    ArchivoCuentas objCuentas;

    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de cuentas.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    cuentaBancaria cuentaActual;
    int totalCuentas = 0;

    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(cuentaActual.getIdCliente() == idCliente && !cuentaActual.getCuentaEliminada()){
            totalCuentas++;
        }
    }
    fclose(archivo);

    if(totalCuentas == 0){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "No tienes cuentas activas para cerrar.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("CERRAR CUENTA BANCARIA", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);

    rlutil::locate(35, 8);
    colorTexto(6);
    cout << "Seleccione la cuenta que desea cerrar:";
    colorTexto(7);

    archivo = fopen("cuentas.dat", "rb");
    int linea = 10;
    int contador = 1;

    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(cuentaActual.getIdCliente() == idCliente && !cuentaActual.getCuentaEliminada()){
            char idFormateado[15];
            formatearId(idFormateado, "CU", cuentaActual.getIdCuenta(), 6);

            rlutil::locate(35, linea);
            cout << contador << ". " << idFormateado << " - " << cuentaActual.getNombreCuenta();
            rlutil::locate(70, linea);
            cout << "($" << fixed << setprecision(2) << cuentaActual.getSaldo() << ")";
            linea++;
            contador++;
        }
    }
    fclose(archivo);

    rlutil::locate(35, linea + 1);
    cout << contador << ". Cancelar operaci" << char(162) << "n";

    rlutil::locate(30, linea + 3);
    cout << char(175) << " Opci" << char(162) << "n: ";
    int opcion = validarEntero(1, contador);

    if(opcion == contador) return;

    archivo = fopen("cuentas.dat", "rb");
    contador = 1;
    int idCuentaSeleccionada = -1;

    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(cuentaActual.getIdCliente() == idCliente && !cuentaActual.getCuentaEliminada()){
            if(contador == opcion){
                idCuentaSeleccionada = cuentaActual.getIdCuenta();
                break;
            }
            contador++;
        }
    }
    fclose(archivo);

    if(idCuentaSeleccionada != -1){
        cuentaBancaria cuentaACerrar;
        if(objCuentas.buscarCuenta("ID", idCuentaSeleccionada, cuentaACerrar)){
            if(cuentaACerrar.getSaldo() != 0.0){
                limpiarPantalla();
                rlutil::locate(40, 15);
                colorTexto(3);
                cout << "ERROR: La cuenta debe tener saldo $0.00 para cerrarla.";
                colorTexto(7);
                rlutil::locate(40, 16);
                cout << "Saldo actual: $" << fixed << setprecision(2) << cuentaACerrar.getSaldo();
                rlutil::locate(40, 18);
                cout << "Presione cualquier tecla para continuar...";
                rlutil::anykey();
                return;
            }
        }

        objCuentas.eliminarCuenta(idCuentaSeleccionada);
        rlutil::anykey();
    }
}

void verSaldoTotal(int idCliente){
    limpiarPantalla();
    colorTexto(7);

    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de cuentas.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    cuentaBancaria cuentaActual;
    double saldoTotal = 0.0;
    int totalCuentas = 0;

    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("RESUMEN FINANCIERO", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);

    rlutil::locate(35, 8);
    colorTexto(6);
    cout << "Mis Cuentas Bancarias:";
    colorTexto(7);

    int linea = 10;

    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(cuentaActual.getIdCliente() == idCliente && !cuentaActual.getCuentaEliminada()){
            char idFormateado[15];
            formatearId(idFormateado, "CU", cuentaActual.getIdCuenta(), 6);

            rlutil::locate(38, linea);
            cout << idFormateado << " - " << cuentaActual.getNombreCuenta();

            rlutil::locate(70, linea);
            colorTexto(2);
            cout << "$" << fixed << setprecision(2) << cuentaActual.getSaldo();
            colorTexto(7);

            saldoTotal += cuentaActual.getSaldo();
            totalCuentas++;
            linea++;
        }
    }
    fclose(archivo);

    if(totalCuentas == 0){
        rlutil::locate(40, 12);
        colorTexto(3);
        cout << "No tienes cuentas bancarias activas.";
        colorTexto(7);
    }
    else{
        rlutil::locate(38, linea + 1);
        cout << string(45, char(196));

        rlutil::locate(38, linea + 3);
        colorTexto(6);
        cout << "SALDO TOTAL:";
        colorTexto(7);

        rlutil::locate(70, linea + 3);
        colorTexto(2);
        cout << "$" << fixed << setprecision(2) << saldoTotal;
        colorTexto(7);

        rlutil::locate(38, linea + 5);
        cout << "Total de cuentas: ";
        colorTexto(2);
        cout << totalCuentas;
        colorTexto(7);
    }

    rlutil::locate(35, linea + 8);
    cout << "Presione cualquier tecla para continuar...";
    rlutil::anykey();
}

void cambiarPassword(int idCliente){
    limpiarPantalla();
    colorTexto(7);

    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("CAMBIAR CONTRASENA", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);

    Cliente clienteActual;
    ArchivoClientes objClientes;
    if(!objClientes.buscarCliente("ID", idCliente, clienteActual)){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo cargar la informaci" << char(162) << "n del cliente.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    rlutil::locate(35, 8);
    colorTexto(6);
    cout << "Ingrese su contrase" << char(164) << "a actual:";
    colorTexto(7);
    rlutil::locate(35, 9);
    char passwordActual[50];
    validarCadena(passwordActual, 50);

    if(strcmp(clienteActual.getContrasena(), passwordActual) != 0){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: Contrase" << char(164) << "a actual incorrecta.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    rlutil::locate(35, 11);
    colorTexto(6);
    cout << "Ingrese su nueva contrase" << char(164) << "a:";
    colorTexto(7);
    rlutil::locate(35, 12);
    char passwordNueva[50];
    validarCadena(passwordNueva, 50);

    if(strlen(passwordNueva) < 6){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: La contrase" << char(164) << "a debe tener al menos 6 caracteres.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    rlutil::locate(35, 14);
    colorTexto(6);
    cout << "Confirme su nueva contrase" << char(164) << "a:";
    colorTexto(7);
    rlutil::locate(35, 15);
    char passwordConfirm[50];
    validarCadena(passwordConfirm, 50);

    if(strcmp(passwordNueva, passwordConfirm) != 0){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: Las contrase" << char(164) << "as no coinciden.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    clienteActual.setContrasena(passwordNueva);

    if(objClientes.modificarCliente(clienteActual)){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(2);
        cout << " Contrase" << char(164) << "a cambiada exitosamente!";
        colorTexto(7);
    }
    else{
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo cambiar la contrase" << char(164) << "a.";
        colorTexto(7);
    }

    rlutil::locate(40, 17);
    cout << "Presione cualquier tecla para continuar...";
    rlutil::anykey();
}
