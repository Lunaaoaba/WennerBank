#ifndef CONFIG_H
#define CONFIG_H

// NOMBRES DE ARCHIVOS
const char* const NOMBRE_ARCHIVO_CLIENTES = "clientes.dat";
const char* const NOMBRE_ARCHIVO_EMPLEADOS = "empleados.dat";
const char* const NOMBRE_ARCHIVO_CUENTAS = "cuentas.dat";
const char* const NOMBRE_ARCHIVO_PRESTAMOS = "prestamos.dat";
const char* const NOMBRE_ARCHIVO_TRANSACCIONES = "transacciones.dat";

// DATOS FIJOS DE LA CUENTA DEL BANCO
const char* const ID_CUENTA_BANCO = "0001";
const char* const ID_CLIENTE_BANCO = "BANK0"; // Un ID ficticio para el "cliente" banco
const char* const NOMBRE_CUENTA_BANCO = "Fondos Centrales del Banco";
const char* const CVU_CUENTA_BANCO = "0000000001";
const char* const ALIAS_CUENTA_BANCO = "WENNER.BANK.FONDOS";
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