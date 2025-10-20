#ifndef CONFIG_H
#define CONFIG_H

// NOMBRES DE ARCHIVOS
const char* NOMBRE_ARCHIVO_CLIENTES = "clientes.dat";
const char* NOMBRE_ARCHIVO_EMPLEADOS = "empleados.dat";
const char* NOMBRE_ARCHIVO_CUENTAS = "cuentas.dat";
const char* NOMBRE_ARCHIVO_PRESTAMOS = "prestamos.dat";
const char* NOMBRE_ARCHIVO_TRANSACCIONES = "transacciones.dat";

// DATOS FIJOS DE LA CUENTA DEL BANCO
int ID_CLIENTE_BANCO = 0; // id ficticio para el "cliente" banco, es 0 pq no es un cliente real
int ID_CUENTA_BANCO = 1;
const char* PREFIJO_CLIENTE = "CL";
const char* PREFIJO_CUENTA = "CU";
const char* NOMBRE_CUENTA_BANCO = "Fondos Centrales del Banco";
const char* CVU_CUENTA_BANCO = "0000000001";
const char* ALIAS_CUENTA_BANCO = "WENNER.BANK.FONDOS";
// 
//  CuentaBancaria cuentaDelBanco(
//             ID_CUENTA_BANCO,
//             ID_CLIENTE_BANCO,
//             NOMBRE_CUENTA_BANCO,
//             CVU_CUENTA_BANCO,
//             ALIAS_CUENTA_BANCO,
//             10000000.00
//         );

#endif