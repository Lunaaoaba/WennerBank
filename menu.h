#ifndef MENU_H
#define MENU_H
#include "cuentaBancaria.h"

void menuBase(); 

// CORREGIDO: Usar referencia (&) para que los cambios persistan en la cuenta.
void menuCuenta(cuentaBancaria &cuenta); 

#endif // MENU_H
