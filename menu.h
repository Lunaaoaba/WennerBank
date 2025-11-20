#ifndef MENU_H
#define MENU_H


void menuTest();

void InicioPrograma();
void menuBienvenida();

void iniciarSesionCliente(bool& sesionActiva, int& idUsuarioActual, int& tipoUsuarioActual);
void iniciarSesionEmpleado(bool& sesionActiva, int& idUsuarioActual, int& tipoUsuarioActual);

#endif
