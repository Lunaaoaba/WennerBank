#include "funciones.h"
#include "cuentaBancaria.h"
#include "menu.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>// LIBRERIA PARA USO DE ARCHIVOS
#include <windows.h>
#include <conio.h>
//#include "config.h" //Se incluye config.h para usar NOMBRE_ARCHIVO_CUENTAS
using namespace std;


// ----------------------------------------------------------------------
//              MOVER / MODIFICAR PARA LLEVAR A FUNCIONES.CPP
// ----------------------------------------------------------------------

const char* ARCHIVO_BINARIO = "Archivo Binario 1";
const char* ARCHIVO_TXT = "CuentasBancarias.txt";

int cargarDatos(cuentaBancaria lista[], int tam) {
    FILE* pa;
    pa = fopen("Archivo Binario 1", "rb"); // Usando el nombre del archivo de la imagen
    if (pa == nullptr) {
        return 0;
    }

    int i = 0;
    // Se lee la CLASE COMPLETA (CuentaBancaria)
    while (fread(&lista[i], sizeof(cuentaBancaria), 1, pa) == 1 && i < tam) {
        i++;
    }

    fclose(pa);
    return i;
}

bool guardarDatos(const cuentaBancaria lista[], int tam) {
    FILE* pa = fopen("Archivo Binario 1", "wb"); // Usando el nombre del archivo de la imagen
    if (pa == nullptr) {
        return false;
    }

    int escritos = fwrite(lista, sizeof(cuentaBancaria), tam, pa);

    fclose(pa);
    return escritos == tam;
}

void agregarDatos(){
    FILE *pa, *pa2; // 2 punteros que nos indicaran la direccion de un archivo
    cuentaBancaria c1, listaC[50];
    int encontro, ultimo, i;

    if (((pa = fopen("Archivo Binario 1", "a+b"))==nullptr)||(( pa2=fopen("Cuentas.txt","a+b"))==nullptr)){//LA FUNCION FOPEN PERMITE CREAR Y/O ABRIR UN ARCHIVO
        cout<< "No se puede abrir el archivo.";
        return;
    }
rewind(pa); //coloca el cursos al inicio
i=0;
while(!feof(pa)){
    if(fread(&c1, sizeof(cuentaBancaria), 1, pa)){//CON LA FUNCION FREAD ENVIAMOS LA INFORMACION DE UN ARCHIVO A UNA VARIABLE O ARRAY DESTINO
        listaC[i]=c1;
        i++;
    }
}
    limpiarEntrada();
    fflush(stdin);
    gotoxy(4,6); cout <<"AGREGAR NUEVOS REGISTROS\n";
    ultimo=i;

// Variables auxiliares para leer las cadenas (DNI, Nombre, etc. del código original)
    char idCuentaStr[5], idClienteStr[5], nombreStr[30], cvuStr[21];
    double saldoDouble;


    do{
        cursorOn(1,10);
        gotoxy(4,8); cout<<"Ingrese numero de cuenta: ";
        cin>> idCuentaStr;
        c1.setIdCuenta(idCuentaStr);

        encontro= 1;
        i=0;
        while (i < ultimo && encontro){
            if (c1.getIdCuenta(), listaC[i].getIdCuenta() == 0){
            encontro=0;
            }else
                i++;
// ----------------------------------------------------------------------
        }
    }

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
        if(encontro==0){
            cursorOff();
            gotoxy(4,22); cout << "NUMERO DE CUENTA YA EXISTENTE!";
            gotoxy(4,23); cout << "PRESIONE UNA TECLA PARA INGRESAR OTRO NUMERO..";
            getch();
            //gotoxy(4,22); cout << "
            //gotoxy(4,23); cout << "
            //gotoxy(4,28); cout << "
        }
        }while(encontro==0);
        limpiarEntrada();
        fflush(stdin);
        gotoxy(4, 10); cout <<"INGRESE SU ID CLIENTE:  ";
        cursorOn(true, 10);
        cin.getline(idClienteStr, 5);
        c1.setIdCliente(idClienteStr); // Setea ID Cliente
        cursorOff();
        gotoxy(4, 12); cout <<"INGRESE NOMBRE DE LA CUENTA:  ";
        cursorOn(true, 10);
        cin.getline(nombreStr, 30);
        c1.setNombreCuenta(nombreStr); // Setea Nombre de Cuenta
        cursorOff();
        gotoxy(4, 14); cout <<"INGRESE CVU (20 DIGITOS):  ";
        cursorOn(true, 10);
        cin.getline(cvuStr, 21);
        c1.setCvu(cvuStr); // Setea CVU
        cursorOff();
        gotoxy(4, 16); cout <<"INGRESE SALDO INICIAL: $  ";
        //gets(c1.saldo);
        gotoxy(4,16); cout <<"Ingrese monto: " ;
       cursorOn(true, 10);
       if (!(cin >> saldoDouble)) {
        saldoDouble = 0;
        limpiarEntrada();
    }
    c1.setSaldo(saldoDouble); // Setea Saldo
    cursorOff();


        fwrite(&c1, sizeof(cuentaBancaria),1,pa); //con la funcion fwrite almacenamos la informacion en el archivo binario
        fprintf(pa2, "%i %s %i %.2f\n", c1.getIdCuenta(), c1.getIdCliente(), c1.getNombreCuenta(), c1.getSaldo());//con la funcion fprintf almacenamos la informacion
        c1.setCuentaEliminada(false);
        fclose(pa);
        fclose(pa2);
        cursorOff();
        gotoxy(4,22); cout<< "CUENTA REGISTRADA CORRECTAMENTE. ";
        gotoxy(4,23); cout <<"PRESIONE UNA TECLA PARA VOLCER AL MENU PRINCIPAL..";
        getch();
        menuBase();
        }

  //ESTA FUNCION PERMITE ELIMINAR LOS DATOS DEL ARCHIVO
    void eliminarDatos(){
        FILE *pa, *pa2;
        cuentaBancaria c1, listaC[50];
        int i, encontro= 1, ultimo;
        char idCuentaBuscada[5];

        if(((pa=fopen("Archivo Binario 1", "a+b"))==nullptr)){
            cout << "No se puede abrir el archivo.\n";
            return;
        }

        rewind(pa); //coloca el cursor al inicio del archivo
        i=0;

        while(!feof(pa)){//recorre todo el archivo
            if(fread(&c1, sizeof(cuentaBancaria), 1, pa)){
                listaC[i]=c1;
                i++;
            }
        }
        fclose(pa);

        fflush(stdin);
        limpiarEntrada();
        gotoxy(30, 3); cout<< "WennerBank";
        gotoxy(4, 6); cout<< "ELIMINAR REGISTROS";
        gotoxy(30, 3); cout<< "Ingrese numero de cuenta: ";
        cin>> idCuentaBuscada;

        //PROCESO DE BUSQUEDA DE INFORMACION
        ultimo= i;
        i=0;
        while( i < ultimo && encontro){
            if((strcmp(idCuentaBuscada, listaC[i].getIdCuenta()) == 0) && (!listaC[i].getCuentaEliminada())) {
            encontro=0;
            }
            else
                i++;
        }

        if (encontro == 0){
            limpiarEntrada();
            gotoxy(4,6); cout<< "CUENTA: " << listaC[i].getIdCuenta();
            gotoxy(4,8); cout<< "CLIENTE ID: " << listaC[i].getIdCliente();
            gotoxy(4,10); cout<< "NOMBRE: " << listaC[i].getNombreCuenta();
            gotoxy(4,12); cout<< "CVU: " << listaC[i].getCvu();
            gotoxy(4,14); cout<< "SALDO: $" << listaC[i].getSaldo();

            listaC[i].setCuentaEliminada(true);

            //ABRE EL ARCHIVO PARA SOBRESCRIBIR
            if(((pa=fopen("Archivo Binario 1", "wb"))==nullptr)||((pa2=fopen("CuentasBancarias.txt", "wb"))==nullptr)){
                cout << "No se puede abrir el archivo.";
                return;
            }

            int escritos = fwrite(listaC, sizeof(cuentaBancaria), ultimo, pa);
            if((pa2=fopen("CuentasBancarias.txt", "w"))==nullptr){ // Cambiado a "w" para sobrescribir
            cout << "No se puede abrir el archivo TXT.";

            } else {
            i=0;
             while(i<ultimo){
        fwrite(&listaC[i], sizeof(cuentaBancaria), 1, pa);
        fprintf(pa2, "%i %s %s %i %.2f\n",listaC[i].getIdCuenta(),listaC[i].getIdCliente(),listaC[i].getNombreCuenta(),listaC[i].getSaldo());
        i++;
        }
        fclose(pa);
        fclose(pa2);
            }

        cursorOff();
        gotoxy(4,22); cout<< "CUENTA ELIMINADA CORRECTAMENTE. ";
        gotoxy(4,23); cout <<"PRESIONE UNA TECLA PARA VOLCER AL MENU PRINCIPAL..";

        }

        else{
            cursorOff();
            gotoxy(4,22); cout<< "NUMERO DE CUENTA NO REGISTRADA ";
            gotoxy(4,23); cout <<"PRESIONE UNA TECLA PARA VOLCER AL MENU PRINCIPAL..";

        }
        getch();
        menuBase();
    }

    //ESTA FUNCION PERMITE ACTUALIZAR UN DATO
    void actualizarDatos(){
         FILE *pa, *pa2;
        cuentaBancaria c1, listaC[50];
        int i, encontro= 1, ultimo,op;
        char idCuentaBuscada[5];

        if(((pa=fopen("Archivo Binario 1", "a+b"))==nullptr)){
            printf("No se puede abrir el archivo.\n");
            return;
        }
        rewind(pa); //coloca el cursor al inicio del archivo
        i=0;

        while(!feof(pa)){//recorre todo el archivo
            if(fread(&c1, sizeof(cuentaBancaria), 1, pa)){
                listaC[i]=c1;
                i++;
            }
        }
        fclose(pa);


        fflush(stdin);
        limpiarEntrada();
        gotoxy(30, 3); cout<< "WennerBank";
        gotoxy(4, 6); cout<< "MODIFICAR REGISTROS";
        gotoxy(30, 3); cout<< "Ingrese numero de cuenta: ";
        cin>> idCuentaBuscada;


        ultimo= i;
        i=0;
        while( i < ultimo && encontro){
            if(strcmp(idCuentaBuscada, listaC[i].getIdCuenta()) == 0)
            encontro=0;
            else
                i++;
        }

        if (encontro == 0){
            limpiarEntrada();
            gotoxy(4,6); cout<< "MODIFICAR REGISTROS";
            do{
            gotoxy(4,8); cout<< "1. ID CLIENTE: " << listaC[i].getIdCliente();
            gotoxy(4,10); cout<<"2. NOMBRE CUENTA: " << listaC[i].getNombreCuenta();
            gotoxy(4,12); cout<<"3. CVU: " << listaC[i].getCvu();
            gotoxy(4,14); cout<<"4. VOLVER AL MENU PRINCIPAL";
            gotoxy(4,16); cout<<"Ingrese la opcion a modificar: ";
            cin >> op;
            }while(op < 1 || op>4);
            if (op == 4) return;

            fflush(stdin);
            // Variables auxiliares para leer los nuevos valores
            char nuevoIdCliente[5], nuevoNombreCuenta[30], nuevoCvu[21];

            switch(op){
                case 1:
                //gotoxy(4,14);cout<<"
                gotoxy(4,8);cout<<"1. NUEVO ID CLIENTE: ";
                gets(nuevoIdCliente);
                listaC[i].setIdCliente(nuevoIdCliente);
                break;
                case 2:
               // gotoxy(4,14);cout<<"
                gotoxy(4,10);cout<<"2. NUEVO NOMBRE CUENTA: ";
                gets(nuevoNombreCuenta);
                listaC[i].setNombreCuenta(nuevoNombreCuenta);
                break;
                case 3:
                //gotoxy(4,14);cout<<"
                gotoxy(4,12);cout<<"3. NUEVO CVU: ";
                gets(nuevoCvu);
                listaC[i].setCvu(nuevoCvu);
                break;
            }

          if(((pa=fopen("Archivo Binario 1", "wb"))==nullptr)||((pa2=fopen("CuentasBancarias.txt", "w"))==nullptr)){ // Usamos 'w' para sobrescribir el TXT
            cout << "No se puede abrir el archivo para guardar.";
            return;
        }

            i=0;
        while(i<ultimo){
        fwrite(&listaC[i], sizeof(cuentaBancaria), 1, pa);
        fprintf(pa2, "%i %s %s %i %.2f\n",listaC[i].getIdCuenta(),listaC[i].getIdCliente(),listaC[i].getNombreCuenta(),listaC[i].getSaldo());
        i++;
        }

        fclose(pa);
        fclose(pa2);
        cursorOff();
        gotoxy(4,22); cout << "CUENTA ELIMINADA CORRECTAMENTE. ";
        gotoxy(4,23); cout <<"PRESIONE UNA TECLA PARA VOLCER AL MENU PRINCIPAL..";

        }

        else{
            cursorOff();
            gotoxy(4,22); cout<< "NUMERO DE CUENTA NO REGISTRADA ";
            gotoxy(4,23); cout <<"PRESIONE UNA TECLA PARA VOLCER AL MENU PRINCIPAL..";

        }
        getch();
        menuBase();

    }

    //ESTA FUNCION PERMITE BUSCAR INFORMACION ALMACENADA EN LOS ARCHIVOS
     void buscarDatos(){
     FILE *pa, *pa2;
        cuentaBancaria c1, listaC[50];
        int i, encontro= 1, ultimo,op;
        char idCuentaBuscada[5]; // Para la busqueda por ID de cuenta
        char nombreBuscado[30]; // Para la busqueda por nombre
        if(((pa=fopen("Archivo Binario 1", "a+b"))==nullptr)){
            cout << "No se puede abrir el archivo.\n";
            return;
        }

        rewind(pa); //coloca el cursor al inicio del archivo
        i=0;

        while(!feof(pa)){//recorre todo el archivo
            if(fread(&c1, sizeof(cuentaBancaria), 1, pa)){
                listaC[i]=c1;
                i++;
            }
        }
        fclose(pa);
        // Comprobación de que hay datos
        if (i == 0) {
        gotoxy(4, 22); std::cout << "NO HAY CUENTAS REGISTRADAS PARA BUSCAR.";
        getch();
        menuBase();
        return;
    }

        fflush(stdin);
        limpiarEntrada();
        gotoxy(30, 3); cout<< "WennerBank";
        gotoxy(4, 6); cout<< "BUSCAR INFORMACION";


        do{
                gotoxy(4,8);cout<<"1. Busqueda por Numero de Cuenta";
                gotoxy(4,10);cout<<"2. Busqueda por nombre";
                gotoxy(4,12);cout<<"Ingrese opcion: ";
                cin >>op;
        }while(op <0 || op > 2);

        limpiarEntrada();
        gotoxy(4,6); cout<< "INFORMACION DE LA CUENTA";

        if(op == 1){
            gotoxy(4,8); cout << "Ingrese numero de la cuenta:";
            cin >> idCuentaBuscada;

            ultimo= i;
            i=0;
           while( i < ultimo && encontro){
           if((strcmp(idCuentaBuscada, listaC[i].getIdCuenta()) == 0) && (!listaC[i].getCuentaEliminada()))
                encontro=0;
            else
                i++;
        }
    }

    else{
        fflush(stdin);
          gotoxy(4,8); cout<< "INGRESE NOMBRE DE LA CUENTA: ";
          gets(nombreBuscado);

        ultimo= i;
        i=0;
        while( i < ultimo && encontro){
     if((strcmp(listaC[i].getNombreCuenta(), nombreBuscado)==0) && (!listaC[i].getCuentaEliminada()))
                encontro=0;
            else
                i++;
        }
    }
 if (encontro == 0){
            limpiarEntrada();
            gotoxy(4,6); cout<< "BUSCAR INFORMACION";
            gotoxy(4,8); cout<< "ID CLIENTE: " << listaC[i].getIdCliente();
            gotoxy(4,10); cout<< "NOMBRE CUENTA: " << listaC[i].getNombreCuenta();
            gotoxy(4,12); cout<< "CVU: " << listaC[i].getCvu();
            gotoxy(4,14); cout<< "ID CUENTA: " << listaC[i].getIdCuenta();
            gotoxy(4,16); cout<< "SALDO: $" << listaC[i].getSaldo();

        }
        else{
            cursorOff();
            gotoxy(4,22); cout<< "NUMERO DE CUENTA NO ENCONTRADA ";
        }

        gotoxy(4,23); cout <<"PRESIONE UNA TECLA PARA VOLCER AL MENU PRINCIPAL..";
        getch();
        menuBase();
    }

    //eSTA FUNCION PERMITE REALIZAR UN DEPOSITOA UNA CUENTA EXISTENTE
    void manejoCuenta(){
         FILE *pa, *pa2;
        cuentaBancaria c1, listaC[50];
        int i, encontro= 1, ultimo, op;
        double monto; // <<--- Variable 'monto' agregada
        char idCuentaBuscada[5];

        if(((pa=fopen("Archivo Binario 1", "a+b"))==nullptr)){
            cout << "No se puede abrir el archivo.\n";
            return;
        }

        rewind(pa); //coloca el cursor al inicio del archivo
        i=0;

        while(!feof(pa)){//recorre todo el archivo
            if(fread(&c1, sizeof(cuentaBancaria), 1, pa)){
                listaC[i]=c1;
                i++;
            }
        }
        fclose(pa);

        if (i == 0) {
        gotoxy(4, 22); std::cout << "NO HAY CUENTAS REGISTRADAS.";
        getch();
        menuBase();
        return;
    }

        fflush(stdin);
        limpiarEntrada();
        gotoxy(30, 3); cout<< "WennerBank";
        gotoxy(4, 6); cout<< "MANEJO DE CUENTA";

        do{
            gotoxy(4, 8); cout <<"1. Depositar";
            gotoxy(4, 10); cout <<"2. Retirar";
            gotoxy(4, 12); cout <<" Ingrese opcion: ";
            cin>>op;
        }while(op <0 || op>2);

        limpiarEntrada();

        if(op == 1){
           gotoxy(4, 6); cout <<"DATOS DE LA CUENTA A DEPOSITAR";
           gotoxy(4, 8); cout <<"INGRESE NUMERO DE CUENTA: ";
          cin>>idCuentaBuscada;


        ultimo= i;
        i=0;
        while( i < ultimo && encontro){
       if((strcmp(idCuentaBuscada, listaC[i].getIdCuenta()) == 0) && (!listaC[i].getCuentaEliminada()))
            encontro=0;
        else
            i++;
    }

        if (encontro == 0){
            limpiarEntrada();
            gotoxy(4,6); cout<< "DATOS DE LA CUENTA A DEPOSITAR";
            gotoxy(4,8); cout<< "CUENTA: " << listaC[i].getIdCuenta();
            gotoxy(4,10); cout<< "NOMBRE: "<< listaC[i].getNombreCuenta();
            gotoxy(4,12); cout<< "SALDO ACTUAL: $"<< listaC[i].getSaldo();

            bool operacion_exitosa = false;

            if (op == 1){ // DEPOSITAR
            gotoxy(4, 20);cout << "INGRESE MONTO A DEPOSITAR: $";
            cin >> monto;
            limpiarEntrada();
            if (monto > 0) {
                operacion_exitosa = listaC[i].depositar(monto); // Usa el método depositar
            }
        }
        else{ // RETIRAR
            do{
                cursorOn(true, 10);
                gotoxy(4, 20); cout<<"INGRESE EL MONTO A RETIRAR: $";
                 cin>>monto;
                limpiarEntrada();

                if(monto > listaC[i].getSaldo()){
                    cursorOff();
                    gotoxy(4,22); cout<< "MONTO INSUFICIENTE. SALDO DISPONIBLE: $" << listaC[i].getSaldo();
                    gotoxy(4,23); cout<< "PRESIONE UNA TECLA PARA INGRESAR OTRO VALOR..";
                    getch();
                    // Limpia las líneas de error y la línea de monto
                    gotoxy(4,20);cout<< "                                                    ";
                    gotoxy(4,22); cout<< "                                                               ";
                    gotoxy(4,23); cout<< "                                                               ";
                }
            }while (monto > listaC[i].getSaldo());
            operacion_exitosa = listaC[i].retirar(monto); // Usa el método retirar
        }

        if (operacion_exitosa) {
            // Se reabre el archivo para SOBRESCRIBIR
            if(((pa=fopen("Archivo Binario 1", "wb"))==nullptr)||((pa2=fopen("CuentasBancarias.txt", "w"))==nullptr)){ // Cambiado a 'w'
              cout << "No se puede abrir el archivo para guardar.";
                return;
            }

            if(((pa=fopen("Archivo Binario 1", "wb"))==nullptr)||((pa2=fopen("CuentasBancarias.txt", "wb"))==nullptr)){
                cout << "No se puede abrir el archivo.";
                return;
            }
            i=0;

            while(i< ultimo){
               fwrite(&listaC[i], sizeof(cuentaBancaria), 1, pa);
        fprintf(pa2, "%i %s %s %i %.2f\n",listaC[i].getIdCuenta(),listaC[i].getIdCliente(),listaC[i].getNombreCuenta(),listaC[i].getSaldo());
        i++;
            }

        fclose(pa);
        fclose(pa2);
        gotoxy(4,22);cout<<"SE REALIZO EL DEPOSITO CORRECTAMENTE";

        }

        else{
        cursorOff();
         gotoxy(4,22);cout<<"INFORMACION DE LA CUENTA NO ENCONTRADA";
        }

    }

    else{
          gotoxy(4,6); cout<< "DATOS DE LA CUENTA A RETIRAR";
          gotoxy(4,8); cout<< "Ingrese numero de cuenta: ";
          cin >> idCuentaBuscada;

        ultimo= i;
        i=0;
        while( i < ultimo && encontro){
           if ((strcmp(idCuentaBuscada, listaC[i].getIdCuenta()) == 0) && (!listaC[i].getCuentaEliminada())) {
            encontro = 0;
        } else
            i++;
        }
           if (encontro == 0){
            limpiarEntrada();
            gotoxy(4,6); cout<< "DATOS DE LA CUENTA A RETIRAR";
            gotoxy(4,8); cout<< "Numero de cuenta: "<< listaC[i].getIdCuenta();
            gotoxy(4,10); cout<< "NOMBRE: "<< listaC[i].getNombreCuenta();
            gotoxy(4,12); cout<< "CVU: " << listaC[i].getCvu();
            gotoxy(4,14); cout<< "ID CLIENTE: " << listaC[i].getIdCliente();
            gotoxy(4,16); cout<< "SALDO ACTUAL: $" << listaC[i].getSaldo();

            bool operacion_exitosa = false;
            do{
                cursorOn(1,10);
                gotoxy(4,19); cout<<"Ingrese el monto a retirar: "; cin>>monto;
                if(monto > listaC[i].getSaldo()){
                    cursorOff();
            gotoxy(4,22); cout<< "MONTO DISPONIBLE";
            gotoxy(4,23); cout<< "PRESIONE UNA TECLA PARA INGRESAR OTRO VALOR..";
            getch();
            gotoxy(4,19); cout<< "                                              ";
            gotoxy(4,22); cout<< "                                              ";
            gotoxy(4,23); cout<< "                                              ";
                }
            }while (monto > listaC[i].getSaldo());
            operacion_exitosa = listaC[i].retirar(monto);
            if (operacion_exitosa) {
            if (((pa = fopen("Archivo Binario 1", "wb")) == nullptr) || ((pa2 = fopen("CuentasBancarias.txt", "wb")) == nullptr)) {
                cout << "No se puede abrir el archivo para guardar.";
                return;
            }

           for(int j=0; j < ultimo; j++){
                fwrite(&listaC[j], sizeof(cuentaBancaria), 1, pa);

                // CORRECCIÓN: Usar los getters de listaC[j] para todos los campos.
                // Ajusta el formato y los argumentos (ejemplo: 4 campos)
                fprintf(pa2, "%s %s %s %.2f\n",
                    listaC[j].getIdCuenta(),
                    listaC[j].getIdCliente(),
                    listaC[j].getNombreCuenta(),
                    listaC[j].getSaldo());
            }
            cursorOff();
             gotoxy(4,22);cout<<"SE REALIZO EL DEPOSITO CORRECTAMENTE";

      fclose(pa);
        fclose(pa2);
        }
                else{
                cursorOff();
    gotoxy(4,22);cout<<"INFORMACION DE LA CUENTA NO ENCONTRADA";
                }
    }

    gotoxy(4,23); cout <<"PRESIONE UNA TECLA PARA VOLCER AL MENU PRINCIPAL..";
        getch();
        menuBase();
    }

//ESTA FUNCION PERMITE REALIZAR UN TIPO DE REPORTE QUE SELECCIONAMOS
void reportes(){
    FILE *pa;
        cuentaBancaria c1, listaC[50];
        int i, encontro= 1, ultimo,op,f = 10,existe = 0 ;
        char tecla;
        char dniBuscado[5]; // Para la busqueda por DNI/ID Cliente
        double monto_min = 0, monto_max = 0;
        char num_cuentaBuscada[5];

        if(((pa=fopen("Archivo Binario 1", "a+b"))==nullptr)){
            cout << "No se puede abrir el archivo.\n";
            return;
        }

        rewind(pa); //coloca el cursor al inicio del archivo
        i=0;

        while(!feof(pa)){//recorre todo el archivo
            if(fread(&c1, sizeof(cuentaBancaria), 1, pa)){
                listaC[i]=c1;
                i++;
            }
        }
        fclose(pa);
        ultimo = i;
        if (ultimo == 0) {
        gotoxy(4, 22); std::cout << "NO HAY CUENTAS REGISTRADAS.";
        getch();
        menuBase();
        return;
    }
        fflush(stdin);
        limpiarEntrada();
        gotoxy(4,6); cout<< "REPORTES";

 do{
                gotoxy(4,8);cout<<"1. Reporte General de Cuentahabientes";
                gotoxy(4,10);cout<<"2. Reporte General de Cuentahabientes por ID Cliente";
                gotoxy(4,12);cout<<"3. Reporte General de Cuentahabientes por Saldo ";
                gotoxy(4,14);cout<<"4. Reporte de una Cuenta específica ";
                gotoxy(4,16);cout<<"Ingrese opcion: ";
                cin>>op;
        }while(op <0 || op > 4);
        limpiarEntrada();

        if(op==1){
            //PROCESO QUE MUESTRA REPORTES EN PANTALLA
             gotoxy(4,6);cout<<"REPORTE GENERAL DE CUENTAHABITANTES";
             ultimo=i;
             i=0;
             gotoxy(4,8);cout<<"CUENTA     ID CLIENTE    NOMBRE CUENTA     CVU     SALDO";
            gotoxy(4,9);cout<<"-----------------------------------------------------------------------------------------------";
            while(i<ultimo){
            existe=1;
          // if(!listaC[i].getCuentaEliminada()){
            gotoxy(4,f); cout<< listaC[i].getIdCuenta();
            gotoxy(15,f); cout<< listaC[i].getIdCliente();
            gotoxy(47,f); cout<<listaC[i].getNombreCuenta();
            gotoxy(62,f); cout<< listaC[i].getCvu();
            gotoxy(70,f); cout<< listaC[i].getSaldo();
            f++;
            i++;
            }


             if(existe == 0){
                cursorOff();
                 gotoxy(4,22);cout<<"NO SE ENCONTRARON REGISTROS!";
            }
            else{
            cursorOff();
            do{
               gotoxy(4,22);cout<<"DESEA GENERAR LA INFORMACION EN UN ARCHIVO TXT? SI[S] / NO[N]";
               tecla = getch();
            }while (tecla != 'S' && tecla != 's' && tecla != 'N' && tecla != 'n');

            if(tecla=='s'|| tecla == 'S'){
              generarArchivos(1,0,0,0,0,0);
                gotoxy(4,22);cout<<"INFORMACION GUARDADA CORRECTAMENTE EN EL ARCHIVO TXT";
            }
           else{
                 gotoxy(4,22);cout<<"";
            }
            }
        }

        if(op==2){

            gotoxy(4,6); cout << "REPORTE ID CLIENTE";
            gotoxy(4,6); cout <<"Ingrese ID Cliente (DNI):";
            cin>>dniBuscado;
            limpiarEntrada();
            gotoxy(4,6);cout<<"REPORTE GENERAL DE ID CLIENTE";

             ultimo=i;
             i=0;
            gotoxy(4,8);cout<<"CUENTA     ID CLIENTE    NOMBRE CUENTA     CVU     SALDO";
            gotoxy(4,9);cout<<"-----------------------------------------------------------------------------------------------";
            while(i < ultimo){
            // Compara ID Cliente y que NO esté eliminada
            if(strcmp(listaC[i].getIdCliente(), dniBuscado) == 0 && !listaC[i].getCuentaEliminada()){
                existe = 1;
                gotoxy(4,f); std::cout<< listaC[i].getIdCuenta();
                gotoxy(15,f); std::cout<< listaC[i].getIdCliente();
                gotoxy(28,f); std::cout<< listaC[i].getNombreCuenta();
                gotoxy(50,f); std::cout<< listaC[i].getCvu();
                gotoxy(70,f); std::cout<< listaC[i].getSaldo();
                f++;
            }
            i++;
        }
    }

               if(existe == 0){
                cursorOff();
                 gotoxy(4,22);cout<<"NO SE ENCONTRARON REGISTRO!";
            }
            else{
            cursorOff();
            do{
               gotoxy(4,22);cout<<"DESEA GENERAR LA INFORMACION EN UN ARCHIVO TXT? SI[S] / NO[N]";
               tecla = getch();
            }while (tecla != 'S' && tecla != 's' && tecla != 'N' && tecla != 'n');

            if(tecla=='s'|| tecla == 'S'){
              generarArchivos(1,0,0,0,0,0);
                gotoxy(4,22);cout<<"INFORMACION GUARDADA CORRECTAMENTE EN EL ARCHIVO TXT";
            }
           else{
                 gotoxy(4,22);cout<<"                                                              ";
            }
            }
        }



        if(op==3){
            gotoxy(4,6); cout << "REPORTE SALDO";
            gotoxy(4,8); cout << "Ingrese saldo minimo: ";
            cin>>monto_min;
            gotoxy(4,10);cout<<"Ingrese saldo maximo: ";
            cin>>monto_max;
            limpiarEntrada();
             gotoxy(4,6);cout<<"REPORTE GENERAL DE SALDOS";

             ultimo=i;
             i=0;
             gotoxy(4,8);cout<<"CUENTA     ID CLIENTE    NOMBRE CUENTA     CVU     SALDO";
            gotoxy(4,9);cout<<"-----------------------------------------------------------------------------------------------";
            while(i < ultimo){
            // Compara Saldo entre rangos y que NO esté eliminada
            if(listaC[i].getSaldo() >= monto_min && listaC[i].getSaldo() <= monto_max && !listaC[i].getCuentaEliminada()){
                existe = 1;
                gotoxy(4,f); std::cout<< listaC[i].getIdCuenta();
                gotoxy(15,f); std::cout<< listaC[i].getIdCliente();
                gotoxy(28,f); std::cout<< listaC[i].getNombreCuenta();
                gotoxy(50,f); std::cout<< listaC[i].getCvu();
                gotoxy(70,f); std::cout<< listaC[i].getSaldo();
                f++;
            }
            i++;
        }
    }

             if(existe == 0){
                cursorOff();
                 gotoxy(4,22);cout<<"NO SE ENCONTRARON REGISTRO!";
            }
            else{
            cursorOff();
            do{
               gotoxy(4,22);cout<<"DESEA GENERAR LA INFORMACION EN UN ARCHIVO TXT? SI[S] / NO[N]";
               tecla = getch();
            }while (tecla != 'S' && tecla != 's' && tecla != 'N' && tecla != 'n');

            if(tecla=='s'|| tecla == 'S'){
              generarArchivos(3,0,0,monto_min, monto_max,0);
                gotoxy(4,22);cout<<"INFORMACION GUARDADA CORRECTAMENTE EN EL ARCHIVO TXT";
            }
           else{
                 gotoxy(4,22);cout<<"";
            }
            }



        if(op==4){
            gotoxy(4,6); cout << "REPORTE DE UNA CUENTA";
            gotoxy(4,8); cout << "Ingrese numero de cuenta: ";
            cin>>num_cuentaBuscada;

            limpiarEntrada();
            gotoxy(4,6); cout << "REPORTE DE UNA CUENTA";

             ultimo=i;
             i=0;
            gotoxy(4,8);cout<<"CUENTA     ID CLIENTE    NOMBRE CUENTA     CVU     SALDO";
            gotoxy(4,9);cout<<"-----------------------------------------------------------------------------------------------";
           while(i < ultimo){
            // Compara ID Cuenta y que NO esté eliminada
            if(strcmp(listaC[i].getIdCuenta(), num_cuentaBuscada) == 0 && !listaC[i].getCuentaEliminada()){
                existe = 1;
                gotoxy(4,f); std::cout<< listaC[i].getIdCuenta();
                gotoxy(15,f); std::cout<< listaC[i].getIdCliente();
                gotoxy(28,f); std::cout<< listaC[i].getNombreCuenta();
                gotoxy(50,f); std::cout<< listaC[i].getCvu();
                gotoxy(70,f); std::cout<< listaC[i].getSaldo();
                f++;
            }
            i++;
        }

               if(existe == 0){
                cursorOff();
                 gotoxy(4,22);cout<<"NO SE ENCONTRARON REGISTRO!";
            }
            else{
            cursorOff();
            do{
               gotoxy(4,22);cout<<"DESEA GENERAR LA INFORMACION EN UN ARCHIVO TXT? SI[S] / NO[N]";
               tecla = getch();
            }while (tecla != 'S' && tecla != 's' && tecla != 'N' && tecla != 'n');

            if(tecla=='s'|| tecla == 'S'){
              generarArchivos(3,0,0,monto_min, monto_max,0);
                gotoxy(4,22);cout<<"INFORMACION GUARDADA CORRECTAMENTE EN EL ARCHIVO TXT";
            }
           else{
                 gotoxy(4,22);cout<<"";
            }
            }

        gotoxy(4,23); cout <<"PRESIONE UNA TECLA PARA VOLCER AL MENU PRINCIPAL..";
        getch();
        menuBase();
    }
}

    //ESTA FUNCION CREA EL ARCHIVO DE TEXTO CON LA INFORMACION DEL REPORTE, SE LE ENVIAN PARAMETROS DE ACUESTO AL REPORTE QUE QUEREMOS GENERAR
    void generarArchivo(int op, char* id_cliente_buscado, char* id_cuenta_buscado, double monto_min, double monto_max){
       ILE *pa, *pa2;
        cuentaBancaria c1, listaC[50];
        int i, encontro= 1, ultimo;

        if(((pa=fopen("Archivo Binario 1", "rb"))==nullptr)){
            cout << "No se puede abrir el archivo.\n";
            return;
        }

        rewind(pa); //coloca el cursor al inicio del archivo
        i=0;

        while(!feof(pa)){//recorre todo el archivo
            if(fread(&c1, sizeof(cuentaBancaria), 1, pa)){
                listaC[i]=c1;
                i++;
            }
        }
        fclose(pa);


        if(op==1){
            if(((pa=fopen("Reporte General. txt","w"))==nullptr)){
                cout << "No se puede abrir el archivo. ";
                return;
            }

            // Escribir la cabecera
    fprintf(pa_txt, "=================================================================================\n");
    if(op == 1) fprintf(pa_txt, "REPORTE GENERAL DE CUENTAS ACTIVAS\n");
    else if(op == 2) fprintf(pa_txt, "REPORTE POR ID CLIENTE: %s\n", id_cliente_buscado);
    else if(op == 3) fprintf(pa_txt, "REPORTE POR RANGO DE SALDO: $%.2f - $%.2f\n", monto_min, monto_max);
    else if(op == 4) fprintf(pa_txt, "REPORTE DE CUENTA ESPECÍFICA: %s\n", id_cuenta_buscado);

    fprintf(pa_txt, "=================================================================================\n");
    fprintf(pa_txt, "ID_CUENTA | ID_CLIENTE | NOMBRE CUENTA | SALDO\n");
    fprintf(pa_txt, "---------------------------------------------------------------------------------\n");
            ultimo=i;
            i=0;// Escribir la cabecera

             // Recorrer la lista y aplicar el filtro
    i=0;
    int registros_escritos = 0;
    while(i < ultimo){
        // Solo procesamos cuentas que NO estén eliminadas
        if(!listaC[i].getCuentaEliminada()){
            bool cumple_filtro = false;

            // Lógica de filtrado
            if(op == 1){ // General
                cumple_filtro = true;
            }
            else if(op == 2){ // Por ID Cliente
                // Se usa strcmp ya que getIdCliente devuelve char*
                if(strcmp(listaC[i].getIdCliente(), id_cliente_buscado) == 0){
                    cumple_filtro = true;
                }
            }
            else if(op == 3){ // Por Rango de Saldo
                if(listaC[i].getSaldo() >= monto_min && listaC[i].getSaldo() <= monto_max){
                    cumple_filtro = true;
                }
            }
            else if(op == 4){ // Por ID Cuenta
                 // Se usa strcmp ya que getIdCuenta devuelve char*
                if(strcmp(listaC[i].getIdCuenta(), id_cuenta_buscado) == 0){
                    cumple_filtro = true;
                }
            }

            // Escribir en el archivo si cumple el filtro
            if(cumple_filtro){
                // ***************************************************************
                // CORRECCIÓN: Uso de Getters en fprintf
                // ***************************************************************
                fprintf(pa_txt, "%s | %s | %s | %.2f\n",
                    listaC[i].getIdCuenta(),
                    listaC[i].getIdCliente(),
                    listaC[i].getNombreCuenta(),
                    listaC[i].getSaldo());
                registros_escritos++;
            }
        }
        i++;
    }

    // Pie de página
    fprintf(pa_txt, "---------------------------------------------------------------------------------\n");
    fprintf(pa_txt, "Total de registros encontrados: %d\n", registros_escritos);

    fclose(pa_txt); // Cerrar el archivo de texto
}
    //FUNCION GOTOXY, SIRVE PARA POSICIONAR LOS MENSAJES EN UNA ZONA DE LA PANTALLA
    void gotoxy(){
        HANDLE hcon;
        hcon=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X= x;
        dwPOS.Y= y;
        SetConsoleCursorPosition(hcon,dwPos);
    }

    void cuadro(int x1, int y1, int x2, int y2){
        int i;
        for(i=x1;i<x2;i++){
            gotoxy(i,y1);printf("Ä");
            gotoxy(i,y2);printf("Ä");
        }
             for(i=y1;i<y2;i++){
            gotoxy(i,x1);printf("'");
            gotoxy(i,x2);printf("'");
        }
         gotoxy(x1,y1);printf("Ú");
         gotoxy(x1,y2);printf("Á");
         gotoxy(x2,y1);printf("¿");
        gotoxy(x2,y2);printf("Ù");
    }

    //funcion limpia area
    void limpiaEntrada(){
        int i, j;
        for(i=6;i<=23;i++){
            for(j=4;j<=75;j++){
                gotoxy(j,i);printf("");}}
            }

  //funcion para ocultar el cursor
  void cursorOff(){
    CONSOLE_CURSOR_INFO cursor ={1,FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
  }

  void curnosrOn(bool visible, DWORD size){
    if(soze == 0){
        size = 20;
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursos.dwSize = size;
    SetConsoleCursorInfo(console, &lpcursor);
  }

































































