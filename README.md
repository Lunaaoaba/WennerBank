# WennerBank - Sistema de Gestion Bancaria

## Descripcion del Proyecto
**WennerBank** es una aplicacion de consola desarrollada en C++ que simula un sistema integral de gestion bancaria. El proyecto esta diseNIado bajo el paradigma de **Programacion Orientada a Objetos (POO)** y se centra en la administracion eficiente de usuarios, cuentas y transacciones financieras mediante un sistema robusto de persistencia de datos en archivos.

El sistema permite la interaccion de tres roles diferenciados (**Cliente, Empleado y Administrador**), cada uno con permisos y funcionalidades especificas, simulando el flujo de operaciones de una entidad bancaria real.

---
## Caracteristicas Principales

#### Gestion de Usuarios y Roles
El sistema implementa una jerarquia de clases para manejar distintos tipos de usuarios con seguridad y escalabilidad:
* **Clientes:** Pueden registrarse, crear multiples cuentas bancarias, consultar saldos y realizar operaciones.
* **Empleados:** Encargados de la gestion operativa. Tienen acceso a listados, busquedas avanzadas y pueden gestionar el estado (baja logica) de clientes y cuentas.
* **Administrador:** Un rol unico con privilegios elevados para la gestion de personal y auditoria de fondos.

#### Productos Financieros
* **Cuentas Bancarias:** Creacion de cuentas con generacion automatica de **ID, CVU y Alias** unicos. Soporte para depositos, retiros y transferencias entre cuentas.
* **Transacciones:** Registro historico de movimientos (en desarrollo).

#### Seguridad y DiseNIo Tecnico
* **Persistencia de Datos:** Todos los registros (clientes, empleados, cuentas) se almacenan en archivos binarios (`.dat`) para asegurar la continuidad de la informacion entre ejecuciones.
* **Patron Singleton:** Implementado en la clase `Administrador` para garantizar la existencia de una unica instancia de control en todo el sistema, protegiendo las credenciales de acceso y centralizando la logica de administracion.
* **Identificadores Inmutables:** DiseNIo robusto donde los IDs clave (Legajo, ID Cliente, CVU) se generan automaticamente y no pueden ser modificados, garantizando la integridad referencial de la base de datos.

---
## Arquitectura del Sistema

El proyecto se estructura sobre una jerarquia de herencia solida para maximizar la reutilizacion de codigo:

1.  **Clase Base `Persona`**: Maneja datos personales comunes (DNI, Nombre, Apellido, Domicilio, Fecha de Nacimiento).
2.  **Clase `Usuario` (Hereda de Persona)**: ANIade la capa de autenticacion (Email, ContraseNIa, Estado de Usuario).
3.  **Clases Derivadas**:
    * `Cliente`: Hereda de Usuario y se vincula con sus productos financieros.
    * `Empleado`: Hereda de Usuario, aNIadiendo Legajo y Clave de Operacion.
    * `Administrador`: Hereda de Empleado, implementando el patron Singleton.

---
## Tecnologias y Herramientas
* **Lenguaje:** C++
* **Librerias:**
    * `<cstdio>` para el manejo eficiente de archivos binarios.
    * `<ctime>` para la gestion de fechas y horas (`Fecha`, `Tiempo`).
    * `rlutil` para la interfaz de usuario en consola (colores y posicionamiento).
* **Paradigma:** Programacion Orientada a Objetos (Encapsulamiento, Herencia, Polimorfismo).


###### muejeje >:D
