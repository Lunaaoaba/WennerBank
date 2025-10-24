#ifndef CONFIG_H
#define CONFIG_H

// EXTERN = variable DEFINIDA en otro archivo, aca es solo la DECLARACION, asi no se crean tantas copias

// NOMBRES DE ARCHIVOS
extern const char* NOMBRE_ARCHIVO_CLIENTES;
extern const char* NOMBRE_ARCHIVO_EMPLEADOS;
extern const char* NOMBRE_ARCHIVO_CUENTAS;
extern const char* NOMBRE_ARCHIVO_PRESTAMOS;
extern const char* NOMBRE_ARCHIVO_TRANSACCIONES;

// DATOS FIJOS DE LA CUENTA DEL BANCO
extern int ID_CLIENTE_BANCO; // id ficticio para el "cliente" banco, es 0 pq no es un cliente real
extern int ID_CUENTA_BANCO;
extern const char* PREFIJO_CLIENTE;
extern const char* PREFIJO_CUENTA;
extern const char* NOMBRE_CUENTA_BANCO;
extern const char* CVU_CUENTA_BANCO;
extern const char* ALIAS_CUENTA_BANCO;

#endif

//  CuentaBancaria cuentaDelBanco(
//             ID_CUENTA_BANCO,
//             ID_CLIENTE_BANCO,
//             NOMBRE_CUENTA_BANCO,
//             CVU_CUENTA_BANCO,
//             ALIAS_CUENTA_BANCO,
//             10000000.00
//         );