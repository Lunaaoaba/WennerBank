# WennerBank - Sistema de Gestión Bancaria

## Integrantes de la cátedra
- **Kloster, Daniel** - Profesor
- **Wenner, Maximiliano** - Ayudante
- **Lara Campos, Brian** - Ayudante
- **Carbonari, Verónica** - Ayudante

## TP Final Programación II. 2025 2C
**Integrantes del grupo:**
- Baricalla, Luna Abril
- Picasso, Gabriela Belén

---

## Información del Proyecto
- **Tipo de proyecto:** Sistema de gestión de archivos
- **Nombre:** WennerBank - Sistema de gestión bancaria
- **Tema:** Sistema de gestión bancaria integral para administración de clientes, cuentas, transacciones y préstamos.

---

## Descripción
El sistema WennerBank es una aplicación de consola que permite gestionar las operaciones de una entidad bancaria, incluyendo:
- Gestión de usuarios (Clientes, Empleados y Administrador).
- Administración de cuentas bancarias (Creación, consulta y operaciones).
- Procesamiento de transacciones (Transferencias, depósitos, retiros).
- Sistema de autenticación y roles con permisos diferenciados.

---

## Funcionalidad del Programa

### Clientes
La persona ingresante al sistema tiene la capacidad de iniciar sesión con un mail y contraseña, y en caso de no poseer un usuario puede crearlo desde el menú del inicio (esto lo hace automáticamente un cliente).

El cliente, luego de iniciar sesión, tiene la posibilidad de:
- Crear cuentas bancarias con ID, CVU y Alias generados automáticamente
- Listar sus cuentas e ingresar a través de un ID
- Modificar sus datos cargados en el sistema
- Depositar y retirar dinero desde su cuenta bancaria
- Transferir saldo disponible a otras cuentas
- Modificar los datos de la cuenta

### Empleados
El empleado ingresa desde la opción "Iniciar sesión como empleado" donde debe ingresar su legajo y contraseña. Al entrar a su usuario, este tiene la capacidad de:
- Listar clientes y cuentas bancarias
- Activar y desactivar clientes o cuentas bancarias (baja lógica)
- Modificar datos
- Realizar búsquedas por filtros
- Ingresar, retirar y transferir dinero entre cuentas

### Administrador (Patrón Singleton)
Al iniciar sesión como empleado, si se detectan los datos del administrador, se inicia sesión a este tipo especial de usuario. El administrador tiene las mismas capacidades que el empleado y más:
- Crear, modificar y eliminar empleados
- Acceso a reportes completos del sistema
- Gestión completa de todas las operaciones bancarias

Para la clase "Administrador", se utiliza el **patrón Singleton** para asegurar la existencia de una única instancia de este rol en todo el sistema. Este diseño ofrece un acceso único y seguro, y mejora la seguridad al mantener sus credenciales fijas en el código en vez de un archivo de datos.

---

## Estructura de Herencia

### Jerarquía implementada en las clases base:
- **Persona** → **Usuario** → **Cliente**
- **Persona** → **Usuario** → **Empleado** → **Administrador** (Singleton)

### Clases de productos y utilidades:
Las clases **CuentaBancaria** y **Transaccion** no forman parte de la herencia, sino que se asocian a los clientes mediante composición vinculándose a través de IDs.

Se utilizan clases de utilidad como **Fecha** y **Tiempo** para obtener la fecha y hora actuales del sistema o para registrar el momento exacto de algún movimiento en el banco.

Toda la configuración de parámetros fijos, como los nombres de archivos .dat, y constantes del sistema, se centralizan en el archivo `config.h` para facilitar el mantenimiento.

---

## Archivos de Datos (.dat)

El sistema utiliza los siguientes archivos binarios para la persistencia de datos:

### clientes.dat
- idCliente : int *(clave principal)*
- dni : int *(de Persona)*
- nombre : char[50] *(de Persona)*
- apellido : char[50] *(de Persona)*
- localidad : char[50] *(de Persona)*
- fechaNacimiento : Fecha
- mail : char[50] *(de Usuario)*
- contrasena : char[50] *(de Usuario)*
- eliminado : bool *(de Usuario)*

### empleados.dat
- legajo : int *(clave principal)*
- dni : int *(de Persona)*
- nombre : char[50] *(de Persona)*
- apellido : char[50] *(de Persona)*
- localidad : char[50] *(de Persona)*
- fechaNacimiento : Fecha
- mail : char[50] *(de Usuario)*
- contrasena : char[50] *(de Usuario)*
- eliminado : bool *(de Usuario)*

### cuentas.dat
- idCuenta : int *(clave principal)*
- idCliente : int *(clave foránea)*
- nombreCuenta : char[50]
- cvu : char[11]
- alias : char[31]
- saldo : double
- cuentaEliminada : bool

### transacciones.dat
- idTransaccion : int *(clave principal)*
- idCuentaOrigen : int *(clave foránea)*
- idCuentaDestino : int *(clave foránea)*
- monto : double
- fechaTransaccion : Fecha
- horaTransaccion : Tiempo

---

## Clases Implementadas

### class Persona
```cpp
class Persona{
    protected:
        int _dni;
        char _nombre[50];
        char _apellido[50];
        char _localidad [50];
        Fecha _fechaNacimiento;
    public:
        Persona();
        Persona(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento);
        //get
        int getDni() const;
        const char* getNombre() const;
        const char* getApellido() const;
        const char* getLocalidad() const;
        Fecha getFechaNacimiento() const;
        int getEdad() const;
        //set
        void setDni(int dni);
        void setNombre(const char* nombre);
        void setApellido(const char* apellido);
        void setLocalidad(const char* localidad);
        void setFechaNacimiento(Fecha fechaNacimiento);
        //otros
        void cargarDatos();
        string mostrarDatos() const;
};
```

### class Usuario : public Persona
```cpp
class Usuario : public Persona{
    protected:
        char _mail[50];
        char _contrasena[50];
        bool _UsuarioEliminado;
    public:
        Usuario();
        Usuario(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool UsuarioEliminado);
        //set
        void setMail(const char* mail);
        void setContrasena(const char* contrasena);
        void setUsuarioEliminado(bool UsuarioEliminado);
        //get
        const char* getMail() const;
        const char* getContrasena() const;
        bool getUsuarioEliminado() const;
        //otros
        void cargarDatos();
        string mostrarDatos() const;
};
```

### class Cliente : public Usuario
```cpp
class Cliente : public Usuario{
    protected:
        int _idCliente;
    public:
        Cliente();
        Cliente(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool estado, int idCliente);
        //get
        int getIdCliente() const;
        //otros
        string mostrarDatos() const;
};
```

### class Empleado : public Usuario
```cpp
class Empleado : public Usuario{
    protected:
        int _legajo;
    public:
        Empleado();
        Empleado(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool UsuarioEliminado,  int legajo);
        //get
        int getLegajo() const;
        //otros
        string mostrarDatos() const;
};
```

### class Administrador : public Empleado (Singleton)
```cpp
class Administrador : public Empleado{
    private:
        Administrador();
        static Administrador* instancia;
        bool _permisosGlobales;
    public:
        static Administrador* getInstancia();
        Administrador(const Administrador&) = delete;
        void operator=(const Administrador&) = delete;
        bool getPermisosGlobales() const;
};
```

### class cuentaBancaria
```cpp
class cuentaBancaria{
    private:
        int _idCuenta;
        int _idCliente;
        char _nombreCuenta[50];
        char _cvu[11]; // 10 dígitos + '\0'
        char _alias[31]; // 30 caracteres + '\0'
        double _saldo;
        bool _cuentaEliminada;
    public:
        cuentaBancaria();
        cuentaBancaria(int idCuenta, int idCliente, const char* nombreCuenta, const char* cvu, const char* alias, double saldo, bool cuentaEliminada);
        //set
        void setIdCliente(int idCliente);
        void setNombreCuenta(const char* nombreCuenta);
        void setAlias(const char* alias);
        void setSaldo(double saldo);
        void setCuentaEliminada(bool cuentaEliminada);
        //get
        int getIdCuenta() const;
        int getIdCliente() const;
        const char* getNombreCuenta() const;
        const char* getCvu() const;
        const char* getAlias() const;
        double getSaldo() const;
        bool getCuentaEliminada() const;
        //otros
        void cargarDatos();
        string mostrarDatos() const;
};
```

### class Transaccion
```cpp
class Transaccion{
    private:
        int _idTransaccion;
        int _idCuentaOrigen;
        int _idCuentaDestino;
        double _monto;
        Fecha _fechaTransaccion;
        Tiempo _horaTransaccion;
    public:
        Transaccion();
        Transaccion(int idTransaccion, int idCuentaOrigen, int idCuentaDestino, double monto, Fecha fechaTransaccion, Tiempo horaTransaccion);
        //get
        int getIdTransaccion() const;
        int getIdCuentaOrigen() const;
        int getIdCuentaDestino() const;
        double getMonto() const;
        Fecha getFechaTransaccion() const;
        Tiempo getHoraTransaccion() const;
        //set
        void setIdCuentaOrigen(int idCuentaOrigen);
        void setIdCuentaDestino(int idCuentaDestino);
        void setMonto(double monto);
        void setFechaTransaccion(Fecha fechaTransaccion);
        void setHoraTransaccion(Tiempo horaTransaccion);
        //otros
        string mostrarDatos() const;
};
```

### class Fecha
```cpp
class Fecha{
    private:
        int _dia, _mes, _anio;
    public:
        Fecha();
        Fecha(int dia, int mes, int anio);
        
        int getDia() const;
        int getMes() const;
        int getAnio() const;

        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);

        void cargarFecha();
        void cargarFecha(int x, int y);
        void cargarFechaActual();
        string mostrarFecha() const;
};
```

### class Tiempo
```cpp
class Tiempo{
    private:
        int _hora, _minuto, _segundo;
    public:
        Tiempo();
        Tiempo(int hora, int minuto, int segundo);

        int getHora() const;
        int getMinuto() const;
        int getSegundo() const;

        void setHora(int horas);
        void setMinuto(int minutos);
        void setSegundo(int segundos);

        void cargarTiempo();
        void cargarTiempoActual();
        string mostrarTiempo() const;
};
```

---

## Reportes Implementados

### Reportes de Clientes:
- Cliente con más transacciones realizadas
- Monto total de las transferencias de un cliente por cada mes del año actual
- Cantidad de clientes por localidad
- Top 5 clientes con mayor monto transferido

### Reportes de Empleados:
- Empleados por localidad
- Empleados activos vs. dados de baja
- Empleados por rango de edad

### Reportes Financieros:
- Saldo total de todas las cuentas de clientes
- Monto promedio de las transacciones
- Ranking de cuentas con mayor saldo

---

## Tecnologías y Herramientas
- **Lenguaje:** C++
- **Librerías:**
  - `<cstdio>` para el manejo eficiente de archivos binarios
  - `<ctime>` para la gestión de fechas y horas
  - `rlutil.h` para la interfaz de usuario en consola (colores y posicionamiento)
- **Paradigma:** Programación Orientada a Objetos (Encapsulamiento, Herencia, Polimorfismo)
- **Patrón de Diseño:** Singleton (clase Administrador)
