# WennerBank - Sistema de Gestión Bancaria

## Descripción del Proyecto
**WennerBank** es una aplicación de consola desarrollada en C++ que simula un sistema integral de gestión bancaria. El proyecto está diseñado bajo el paradigma de **Programación Orientada a Objetos (POO)** y se centra en la administración eficiente de usuarios, cuentas y transacciones financieras mediante un sistema robusto de persistencia de datos en archivos.

El sistema permite la interacción de tres roles diferenciados (**Cliente, Empleado y Administrador**), cada uno con permisos y funcionalidades específicas, simulando el flujo de operaciones de una entidad bancaria real.

---
## Características Principales

#### Gestión de Usuarios y Roles
El sistema implementa una jerarquía de clases para manejar distintos tipos de usuarios con seguridad y escalabilidad:
* **Clientes:** Pueden registrarse, crear múltiples cuentas bancarias, consultar saldos y realizar operaciones.
* **Empleados:** Encargados de la gestión operativa. Tienen acceso a listados, búsquedas avanzadas y pueden gestionar el estado (baja lógica) de clientes y cuentas.
* **Administrador:** Un rol único con privilegios elevados para la gestión de personal y auditoría de fondos.

#### Productos Financieros
* **Cuentas Bancarias:** Creación de cuentas con generación automática de **ID, CVU y Alias** únicos. Soporte para depósitos, retiros y transferencias entre cuentas.
* **Préstamos y Transacciones:** Registro histórico de movimientos y gestión de créditos (en desarrollo).

#### Seguridad y Diseño Técnico
* **Persistencia de Datos:** Todos los registros (clientes, empleados, cuentas) se almacenan en archivos binarios (`.dat`) para asegurar la continuidad de la información entre ejecuciones.
* **Patrón Singleton:** Implementado en la clase `Administrador` para garantizar la existencia de una única instancia de control en todo el sistema, protegiendo las credenciales de acceso y centralizando la lógica de administración.
* **Identificadores Inmutables:** Diseño robusto donde los IDs clave (Legajo, ID Cliente, CVU) se generan automáticamente y no pueden ser modificados, garantizando la integridad referencial de la base de datos.

---
## Arquitectura del Sistema

El proyecto se estructura sobre una jerarquía de herencia sólida para maximizar la reutilización de código:

1.  **Clase Base `Persona`**: Maneja datos personales comunes (DNI, Nombre, Apellido, Domicilio, Fecha de Nacimiento).
2.  **Clase `Usuario` (Hereda de Persona)**: Añade la capa de autenticación (Email, Contraseña, Estado de Usuario).
3.  **Clases Derivadas**:
    * `Cliente`: Hereda de Usuario y se vincula con sus productos financieros.
    * `Empleado`: Hereda de Usuario, añadiendo Legajo y Clave de Operación.
    * `Administrador`: Hereda de Empleado, implementando el patrón Singleton.

---
## Tecnologías y Herramientas
* **Lenguaje:** C++
* **Librerías:**
    * `<cstdio>` para el manejo eficiente de archivos binarios.
    * `<ctime>` para la gestión de fechas y horas (`Fecha`, `Tiempo`).
    * `rlutil` para la interfaz de usuario en consola (colores y posicionamiento).
* **Paradigma:** Programación Orientada a Objetos (Encapsulamiento, Herencia, Polimorfismo).


###### muejeje >:D
