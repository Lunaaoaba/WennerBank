#ifndef MENU_H
#define MENU_H


// ---------------------------
// |   NUCLEO DEL PROGRAMA   |
// ---------------------------

void InicioPrograma();

// muestra la bienvenida y llama a las funciones de login/creacion
// usa referencias para cambiar las variables de sesion
void menuBienvenida();

// muestra el menu del cliente, usa el id para saber que mostrar
// y la referencia de sesion para poder cerrar sesion.
void menuCliente(int idUsuarioActivo, bool& sesionActiva);

// lo mismo para el empleado
void menuEmpleado(int idUsuarioActivo, bool& sesionActiva);

// lo mismo para el admin, no necesita el id porque es un singleton
void menuAdmin(bool& sesionActiva);

void iniciarSesionCliente(bool& sesionActiva, int& idUsuarioActual, int& tipoUsuarioActual);
void iniciarSesionEmpleado(bool& sesionActiva, int& idUsuarioActual, int& tipoUsuarioActual);

#endif
