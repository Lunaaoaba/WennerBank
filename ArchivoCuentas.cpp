#include <ctime>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream> 
#include "cuentaBancaria.h"
#include "cliente.h"
#include "funciones.h"
#include "funcionesArchivos.h"
#include "archivoClientes.h"
#include "archivoCuentas.h"
#include "archivoTransacciones.h"

using namespace std;

ArchivoCuentas::ArchivoCuentas(const char* nombre){ strcpy(_nombreArchivo, nombre); }

bool ArchivoCuentas::guardarCuentas(const cuentaBancaria& cuenta){
    FILE* archivo = fopen("cuentas.dat", "ab");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
        return false;
    }
    fwrite(&cuenta, sizeof(cuentaBancaria), 1, archivo);
    fclose(archivo);
    return true;
}

cuentaBancaria ArchivoCuentas::crearCuenta(int idCliente){
    Cliente cliente;
    ArchivoClientes obj;
    if(!obj.buscarCliente("ID", idCliente, cliente)){
        cout << "ERROR: No se encontro el cliente con ID " << idCliente << "." << endl;
        return cuentaBancaria();
    }
    if(cliente.getUsuarioEliminado()){
        cout << "ERROR: El cliente con ID " << idCliente << " esta inactivo." << endl;
        return cuentaBancaria();
    }

    int idCuenta;
    char nombreCuenta[50], cvu[11], alias[31];
    double saldo;
    bool cuentaEliminada = false;

    system("cls");
    cout << "----- CREACION DE NUEVA CUENTA BANCARIA -----" << endl;
    cout << "Cliente: " << cliente.getNombre() << " " << cliente.getApellido() << endl;
    cout << "ID Cliente: " << idCliente << endl << endl;

    cout << "Ingrese un nombre para la cuenta: ";
    validarCadenaLetras(nombreCuenta, 50);

    cout << "Imgrese un saldo inicial (min $0.00, max $999999999.99): $ ";
    saldo = validarDouble(0.0, 999999999.99);

    idCuenta = generarIdCuenta();
    generarCvu(cvu);
    generarAlias(alias);

    cuentaBancaria nuevaCuenta(
        idCuenta,
        idCliente,
        nombreCuenta,
        cvu,
        alias,
        saldo,
        cuentaEliminada
    );
    
    system("cls");
    cout << "----- CONFIRMACION DE DATOS -----" << endl;
    cout << "Cliente: " << cliente.getNombre() << " " << cliente.getApellido() << endl;
    cout << "ID Cliente: " << idCliente << endl << endl;
    cout << nuevaCuenta.mostrarDatos() << endl;
    
    cout << "\nConfirma la creacion de la cuenta? (S/N): ";
    char confirmacion = validarSiNo();
    if(confirmacion == 'S' || confirmacion == 's'){
        if(guardarCuentas(nuevaCuenta)){
            system("cls");
            cout << "\n----- CUENTA CREADA CON EXITO -----" << endl;
            cout << "ID Cuenta: " << idCuenta << endl;
            cout << "CVU: " << cvu << endl;
            cout << "Alias: " << alias << endl;
            cout << "Saldo inicial: $" << fixed << setprecision(2) << saldo << endl;
        }
        else{
            cout << "ERROR: No se pudo guardar la nueva cuenta." << endl;
            return cuentaBancaria();
        }
    }
    else{
        cout << "Operacion cancelada." << endl;
        return cuentaBancaria(); 
    }
    
    return nuevaCuenta;
}

bool ArchivoCuentas::modificarCuenta(const cuentaBancaria& cuentaModificada){
    int pos = posicionCuentaPorId(cuentaModificada.getIdCuenta());

    if(pos < 0){
        if(pos == -1){
            cout << "ERROR: No se encontro la cuenta con ID " << cuentaModificada.getIdCuenta() << "." << endl;
            return false;
        }
        if(pos == -2){
            cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
            return false;
        }
    }
    FILE* archivo = fopen("cuentas.dat", "rb+");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de cuentas para modificar." << endl;
        return false;
    }

    fseek(archivo, static_cast<long>(pos) * (long)sizeof(cuentaBancaria), SEEK_SET);
    bool exito;
    if (fwrite(&cuentaModificada, sizeof(cuentaBancaria), 1, archivo) == 1) exito = true;
    fclose(archivo);
    return exito;
}

bool ArchivoCuentas::modificarDatosCuenta(int idCuenta){
    cuentaBancaria cuentaAModificar;
    if(idCuenta == 1){
        cout << "ERROR: No se puede alterar esta cuenta." << endl;
        return false;
    }
    if(!buscarCuenta("ID", idCuenta, cuentaAModificar)){
        cout << "ERROR: No se encontro la cuenta con ID " << idCuenta << "." << endl;
        return false;
    }
    if(cuentaAModificar.getCuentaEliminada()){
        cout << "ERROR: No se encontro la cuenta con ID " << idCuenta << "." << endl;
        return false;
    }

    system("cls");
    cout << "----- MODIFICACION DE CUENTA BANCARIA -----" << endl;
    cout << "Datos actuales de la cuenta:" << endl;
    cout << cuentaAModificar.mostrarDatos() << endl << endl;

    bool continuar = true;
    while(continuar){
        cout << "Seleccione el dato a modificar:" << endl;
        cout << "1. Nombre de la cuenta bancaria" << endl;
        cout << "2. Volver a generar Alias" << endl;
        cout << "3. Finalizar/Cancelar modificacion" << endl << endl;
        // dsp cambiar a rlutil
        int opcion = validarEntero(1, 3);
        switch(opcion){
            case 1: {
                char nuevoNombre[50];
                cout << "Ingrese el nuevo nombre de la cuenta: ";
                validarCadenaLetras(nuevoNombre, 50);
                cuentaAModificar.setNombreCuenta(nuevoNombre);
                break;
            }
            case 2: {
                char nuevoAlias[31];
                generarAlias(nuevoAlias);
                cuentaAModificar.setAlias(nuevoAlias);
                cout << "Nuevo alias generado: " << nuevoAlias << endl;
                break;
            }
            case 3: {
                continuar = false;
                break;
            }
        }
    }
    if(modificarCuenta(cuentaAModificar)){
        cout << "Cuenta modificada correctamente." << endl;
        return true;
    }
    else{
        cout << "ERROR: No se pudo modificar la cuenta." << endl;
        return false;
    }
}

bool ArchivoCuentas::eliminarCuenta(int idCuenta){
    cuentaBancaria cuentaAEliminar;

    if(idCuenta == 1){
        cout << "ERROR: No se puede eliminar esta cuenta." << endl;
        return false;
    }

    if(!buscarCuenta("ID", idCuenta, cuentaAEliminar)){
        cout << "ERROR: No se encontro la cuenta con ID " << cuentaAEliminar.getIdCuenta() << "." << endl;
        return false;
    }

    if(cuentaAEliminar.getCuentaEliminada()){
        cout << "ERROR: La cuenta con ID " << cuentaAEliminar.getIdCuenta() << " ya se encuentra eliminada." << endl;
        return false;
    }

    system("cls");
    cout << "----- CONFIRMACION DE DATOS -----" << endl;
    cout << "Cuenta a eliminar:" << endl;
    cout << cuentaAEliminar.mostrarDatos() << endl;
    cout << "\nConfirma la eliminacion de la cuenta? (S/N): ";

    char confirmacion = validarSiNo();
    if(confirmacion == 'S' || confirmacion == 's'){
        cuentaAEliminar.setCuentaEliminada(true);
        if(modificarCuenta(cuentaAEliminar)){
            cout << "Cuenta con ID " << cuentaAEliminar.getIdCuenta() << " eliminada correctamente." << endl;
            return true;
        }
        else{
            cout << "ERROR: No se pudo eliminar la cuenta con ID " << idCuenta << "." << endl;
            return false;
        }
    }
    else if (confirmacion == 'N' || confirmacion == 'n') cout << "Operacion cancelada." << endl;
    else cout << "Entrada no reconocida. Operacion cancelada." << endl;
    return false;
}

bool ArchivoCuentas::restaurarCuenta(int idCuenta){
    cuentaBancaria cuentaARestaurar;
    if(!buscarCuenta("ID", idCuenta, cuentaARestaurar)){
        cout << "ERROR: No se encontro la cuenta con ID " << idCuenta << "." << endl;
        return false;
    }
    if(!cuentaARestaurar.getCuentaEliminada()){
        cout << "ERROR: La cuenta con ID " << idCuenta << " se encuentra activa." << endl;
        return false;
    }
    system("cls");
    cout << "----- CONFIRMACION DE DATOS -----" << endl;
    cout << "Cuenta a restaurar:" << endl;
    cout << cuentaARestaurar.mostrarDatos() << endl;
    cout << "\nConfirma la restauracion de la cuenta? (S/N): ";

    char confirmacion = validarSiNo();
    if(confirmacion == 'S' || confirmacion == 's'){
        cuentaARestaurar.setCuentaEliminada(false);
        if(modificarCuenta(cuentaARestaurar)){
            cout << "Cuenta con ID " << cuentaARestaurar.getIdCuenta() << " restaurada correctamente." << endl;
            return true;
        }
        else{
            cout << "ERROR: No se pudo restaurar la cuenta con ID " << cuentaARestaurar.getIdCuenta() << "." << endl;
            return false;
        }
    }
    else if (confirmacion == 'N' || confirmacion == 'n') cout << "Operacion cancelada." << endl;
    else cout << "Entrada no reconocida. Operacion cancelada." << endl;
    return false;
}

void ArchivoCuentas::listarCuentasCliente(int idCliente){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
        return;
    }
    
    cuentaBancaria cuentaActual;
    int contador = 0;
    
    system("cls");
    cout << "----- CUENTAS DEL CLIENTE ID=" << idCliente << " -----" << endl;
    cout << "----------------------------------------" << endl << endl;
    
    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(cuentaActual.getIdCliente() == idCliente && !cuentaActual.getCuentaEliminada()){
            cout << cuentaActual.mostrarDatos() << endl;
            contador++;
            cout << endl << "----------------------------------------" << endl << endl;
        }
    }
    
    fclose(archivo);
    
    if(contador == 0){
        cout << "El cliente no tiene cuentas bancarias activas." << endl;
    }
    else{
        cout << "Total de cuentas: " << contador << endl;
    }
}

void ArchivoCuentas::listarCuentas(){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
        return;
    }
    cuentaBancaria cuentaActual;
    int i = 0;
    cout << "----- LISTADO DE CUENTAS BANCARIAS -----" << endl;
    cout << "----------------------------------------" << endl << endl;
    while (fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(!cuentaActual.getCuentaEliminada()){
            cout << cuentaActual.mostrarDatos() << endl;
            i++;
            cout << endl << "----------------------------------------" << endl << endl;
        }
    }
    if(i == 0){
        cout << "ERROR: No hay cuentas bancarias registradas." << endl;
        cout << "--------------------------------" << endl << endl;
    }
    cout << "Total de cuentas bancarias: " << i << endl;
    fclose(archivo);
}

void ArchivoCuentas::listarTodasCuentas(){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
        return;
    }
    cuentaBancaria cuentaActual;
    int i = 0;
    cout << "----- LISTADO DE CUENTAS BANCARIAS -----" << endl;
    cout << "----------------------------------------" << endl << endl;
    while (fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        cout << cuentaActual.mostrarDatos() << endl;
        if(cuentaActual.getCuentaEliminada()) cout << "[ CUENTA ELIMINADA ]" << endl;
            i++;
            cout << endl << "----------------------------------------" << endl << endl;
    }
    if(i == 0){
        cout << "ERROR: No hay cuentas bancarias registradas." << endl;
        cout << "--------------------------------" << endl << endl;
    }
    cout << "Total de cuentas bancarias: " << i << endl;
    fclose(archivo);

}

bool ArchivoCuentas::buscarCuenta(const char* criterio, int valor, cuentaBancaria& encontrada){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
        return false;
    }
    bool seEncontro = false;
    while(fread(&encontrada, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(strcmp(criterio, "ID") == 0){
            if(encontrada.getIdCuenta() == valor){
                seEncontro = true;
                break;
            }
        }
        else if(strcmp(criterio, "IDCLIENTE") == 0){
            if(encontrada.getIdCliente() == valor){
                seEncontro = true;
                break;
            }
        }
        else if(strcmp(criterio, "SALDO") == 0){
            if(encontrada.getSaldo() == static_cast<double>(valor)){
                seEncontro = true;
                break;
            }
        }
        else cout << "Criterio de busqueda invalido." << endl;

        if (seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

bool ArchivoCuentas::buscarCuenta(const char* criterio, const char* valor, cuentaBancaria& encontrada){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
        return false;
    }
    bool seEncontro = false;
    while(fread(&encontrada, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(strcmp(criterio, "CVU") == 0){
            if(strcmp(encontrada.getCvu(), valor) == 0){
                seEncontro = true;
                break;
            }
        }
        else if(strcmp(criterio, "ALIAS") == 0){
            if(strcmp(encontrada.getAlias(), valor) == 0){
                seEncontro = true;
                break;
            }
        }
        else if(strcmp(criterio, "NOMBRECUENTA") == 0){
            if(strcmp(encontrada.getNombreCuenta(), valor) == 0){
                seEncontro = true;
                break;
            }
        }
        else cout << "Criterio de busqueda invalido." << endl;

        if (seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

bool ArchivoCuentas::depositar(int idCuenta, double monto){
    if(monto <= 0){
        cout << "ERROR: El monto debe ser mayor a 0." << endl;
        return false;
    }
    
    cuentaBancaria cuenta;
    if(!buscarCuenta("ID", idCuenta, cuenta)){
        cout << "ERROR: No se encontro la cuenta." << endl;
        return false;
    }
    if(cuenta.getCuentaEliminada()){
        cout << "ERROR: La cuenta esta cerrada." << endl;
        return false;
    }
    
    cuenta.setSaldo(cuenta.getSaldo() + monto);

    if(modificarCuenta(cuenta)){
        Fecha fechaActual;
        fechaActual.cargarFechaActual();
        Tiempo tiempoActual;
        tiempoActual.cargarTiempoActual();
        ArchivoTransacciones trActual;
        Transaccion nuevaTransaccion(
            trActual.generarIdTransaccion(),
            -1,
            idCuenta,
            monto,
            fechaActual,
            tiempoActual
        );
        trActual.guardarTransaccion(nuevaTransaccion);

        cout << "Deposito exitoso. Nuevo saldo: $" << fixed << setprecision(2) << cuenta.getSaldo() << endl;
        return true;
    }
    
    cout << "ERROR: No se pudo realizar el deposito." << endl;
    return false;
}

bool ArchivoCuentas::extraer(int idCuenta, double monto){
    if(monto <= 0){
        cout << "ERROR: El monto debe ser mayor a 0." << endl;
        return false;
    }
    
    cuentaBancaria cuenta;
    if(!buscarCuenta("ID", idCuenta, cuenta)){
        cout << "ERROR: No se encontro la cuenta." << endl;
        return false;
    }
    if(cuenta.getCuentaEliminada()){
        cout << "ERROR: La cuenta esta cerrada." << endl;
        return false;
    }
    if(cuenta.getSaldo() < monto){
        cout << "ERROR: Saldo insuficiente." << endl;
        return false;
    }
    
    cuenta.setSaldo(cuenta.getSaldo() - monto);
    
    if(modificarCuenta(cuenta)){
        Fecha fechaActual;
        fechaActual.cargarFechaActual();
        Tiempo tiempoActual;
        tiempoActual.cargarTiempoActual();
        ArchivoTransacciones trActual;
        Transaccion nuevaTransaccion(
            trActual.generarIdTransaccion(),
            idCuenta,
            -1,
            monto,
            fechaActual,
            tiempoActual
        );
        trActual.guardarTransaccion(nuevaTransaccion);
        cout << "Extraccion exitosa. Nuevo saldo: $" << cuenta.getSaldo() << endl;
        return true;
    }
    
    cout << "ERROR: No se pudo realizar la extraccion." << endl;
    return false;
}

bool ArchivoCuentas::transferir(int idCuentaOrigen, int idCuentaDestino, double monto){
    if(monto <= 0){
        cout << "ERROR: El monto debe ser mayor a 0." << endl;
        return false;
    }
    if(idCuentaOrigen == idCuentaDestino){
        cout << "ERROR: No se puede transferir a la misma cuenta." << endl;
        return false;
    }

    cuentaBancaria cuentaOrigen, cuentaDestino;
    if(!buscarCuenta("ID", idCuentaOrigen, cuentaOrigen)){
        cout << "ERROR: No se encontro la cuenta origen." << endl;
        return false;
    }
    if(!buscarCuenta("ID", idCuentaDestino, cuentaDestino)){
        cout << "ERROR: No se encontro la cuenta destino." << endl;
        return false;
    }
    if(cuentaOrigen.getCuentaEliminada() || cuentaDestino.getCuentaEliminada()){
        cout << "ERROR: Una de las cuentas esta cerrada." << endl;
        return false;
    }
    if(cuentaOrigen.getSaldo() < monto){
        cout << "ERROR: Saldo insuficiente en cuenta origen." << endl;
        return false;
    }
    
    // Realizar transferencia
    cuentaOrigen.setSaldo(cuentaOrigen.getSaldo() - monto);
    cuentaDestino.setSaldo(cuentaDestino.getSaldo() + monto);
    
    if(modificarCuenta(cuentaOrigen) && modificarCuenta(cuentaDestino)){
        Fecha fechaActual;
        fechaActual.cargarFechaActual();
        Tiempo tiempoActual;
        tiempoActual.cargarTiempoActual();
        ArchivoTransacciones trActual;

        Transaccion nuevaTransaccion(
            trActual.generarIdTransaccion(),
            idCuentaOrigen,
            idCuentaDestino,
            monto,
            fechaActual,
            tiempoActual
        );
        trActual.guardarTransaccion(nuevaTransaccion);

        cout << "Transferencia exitosa." << endl;
        cout << "Saldo cuenta origen: $" << cuentaOrigen.getSaldo() << endl;
        cout << "Saldo cuenta destino: $" << cuentaDestino.getSaldo() << endl;
        return true;
    }
    
    cout << "ERROR: No se pudo completar la transferencia." << endl;
    return false;
}

int ArchivoCuentas::generarIdCuenta(){
    FILE* archivo = fopen("cuentas.dat", "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1;
    
    cuentaBancaria reg;
    while(fread(&reg, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(reg.getIdCuenta() > maxId){
            maxId = reg.getIdCuenta();
        }
    }
    fclose(archivo);
    return maxId + 1;
}

void ArchivoCuentas::generarCvu(char* cvu){
    srand(static_cast<unsigned int>(time(nullptr)));
    bool cvuUnico = false;
    while(!cvuUnico){
        for(int i = 0; i < 10; i++){
            cvu[i] = static_cast<char>('0' + (rand() % 10));  // Dígito aleatorio 0-9
        }
        cvu[10] = '\0';
        if(!existeCvu(cvu)){
            cvuUnico = true;
        }
    }
}

void ArchivoCuentas::generarAlias(char* alias){
    srand(static_cast<unsigned>(time(nullptr)));
    // 35+35+35 = 105
    // 105^3 = 1,157,625 combinaciones posibles
    // orden aleatorio + repeticion de categorias
    const char* sustantivos[35] = {
        "TIGRE", "DRAGON", "FENIX", "COMETA", "RELOJ",
        "LIBRO", "ESPEJO", "CANDADO", "VOLCAN", "CRISTAL",
        "TRUENO", "ROBOT", "PIANO", "FARO", "CASTILLO",
        "PUENTE", "RELAMPAGO", "BRUJULA", "DIAMANTE", "CASCADA",
        "VELA", "PORTAL", "METEORO", "OASIS", "TORRE",
        "LAGO", "TEMPO", "MARCO", "CUBO", "PILAR",
        "CIRCO", "MANTO", "CLAVO", "TORNADO", "AURA"
    };
    const char* adjetivos[35] = {
        "INFINITO", "MAGICO", "VELOZ", "SILENCIOSO", "INVISIBLE",
        "DORADO", "BRILLANTE", "SALVAJE", "HELADO", "ARDIENTE",
        "COSMICO","FRAGIL", "PODEROSO", "OCULTO", "LIBRE",
        "REBELDE", "LEGENDARIO", "RADIANTE", "SECRETO", "DIVINO",
        "SERENO", "TRANQUILO", "FUGAZ", "SUAVE", "AGUDO",
        "LUMINOSO", "TENUE", "VASTO", "PURO", "ARIDO",
        "FIRME", "SOLIDO", "NITIDO", "LIVIANO", "INTENSO"
    };
    const char* verbos[35] = {
        "CORRER", "SALTAR", "VOLAR", "NADAR", "BRILLAR",
        "CANTAR", "BAILAR", "CRECER", "VIAJAR", "LEER",
        "JUGAR", "MIRAR", "BUSCAR", "CREAR", "PENSAR",
        "SENTIR", "VIVIR", "FLUIR", "GIRAR", "TOMAR",
        "ROMPER", "DAR", "MOVER", "GUIAR", "TEJER",
        "LLAMAR", "FORJAR", "GUARDAR", "PULSAR", "SEGUIR",
        "HABLAR", "SOÑAR", "FORMAR", "SUBIR", "BAJAR"
    };

    const char** categorias[3] = {sustantivos, adjetivos, verbos};
    bool aliasUnico = false;
    while(!aliasUnico){
        // Elige 3 palabras al azar       (categoría + posición)
        const char* palabra1 = categorias[rand() % 3] [rand() % 35];
        const char* palabra2 = categorias[rand() % 3] [rand() % 35];
        const char* palabra3 = categorias[rand() % 3] [rand() % 35];

        // Formato: "PALABRA1.PALABRA2.PALABRA3"
        sprintf(alias, "%s.%s.%s", palabra1, palabra2, palabra3);

        if(!existeAlias(alias)){
            aliasUnico = true;
        }
    }
}

// despues rehacer para q use sobrecarga
int ArchivoCuentas::posicionCuentaPorId(int idCuenta){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr) return -2;
    cuentaBancaria cuentaActual;
    int pos = 0;
    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(cuentaActual.getIdCuenta() == idCuenta){
            fclose(archivo);
            return pos;
        }
        pos++;
    }
    fclose(archivo);
    return -1;
}