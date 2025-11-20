
# LISTA DE COSAS PRINCIPALES FALTANTES:
### **MARCAS:**
### ✅ = Terminado
### ⚠️ = Revisar
### ⌛ = En proceso
## ***ctrl + shift + v*** = mejor vista de las notas
### HACER:
1. ✅ funcion INICIAR SESION/CREAR CUENTA:
funcion para el menu "iniciarSesion" donde adentro estaran las siguentes funciones: 
    - "crearCuenta:"
    Para crear la cuenta se debe crear un nuevo 'cliente'.
    - "iniciarSesion:"
    Para Iniciar sesion (cliente) se deben validar los datos buscando desde el archivo clientes.dat' si el mail y contraseNIa existen y si son correctos.
    - "iniciarSesionEmpleado:" 
    Para iniciar sesion (empleado) se deben validar los datos, lo mismo que al cliente.
    - Para iniciar sesion como admin, debe entrar a iniciar sesion de empleado, sigue el mismo proceso (pensaba hacer un if de q si los datos coinciden, activar el bool de Permisos globales de la clase de admin)
    - variables principales:
        - bool 'sesionActiva'
        - int 'idUsuarioActual'
        - char[20] o int 'tipoUsuario'

2. ✅ funciones BORRAR CLIENTE/EMPLEADO/CUENTA:
estan los esqueletos pero no las funciones, tengo igual algunas a medio hacer, asi que solo es adaptarlo a lo que se necesita. Creo q se podria hacer sobrecarga.

3. ✅ funciones de busqueda:
estan los esqueletos pero no las funciones, no se si se necesita memoria dinamica, pero tengo una idea de como se hace.

4. ✅ funciones de modificacion:
no estan ni los esqueletos creo, y creo que se debe utilizar memoria dinamica.

5. ✅ funciones generar IDs, generar legajo y cvu:
siguen la misma logica del Id del cliente, es solo adaptar.

6. ✅ funcion generar Alias: ✅¿
debe ser unico y podria tener un formato como mp si es q no es mucho lio, tengo que buscar como podria generarse. No tengo ni idea como se generaria pero capaz 

7. ✅ funciones de listado: 
necesita memoria dinamica creo, me gustaria poner un contador para cada listado, para llevar un conteo de todo.

8. ✅ Asociar una cuenta al cliente / asociar la cuenta principal al empleado y al admin
Esto si que no se como hacerlo, pero la idea seria que al crear la cuenta de banco, en el setter del id cliente, se copie el id del cliente que tiene la sesion activa, para eso se debe tener iniciadas las variables comentadas en el primer punto, no se si voy a necesitar mas despues, pero por ahora esas son las mas importantes

9. ✅ Validaciones:
    - validar que no se repitan los mails al crear cuenta
    - validar el ingreso de fechas (aNIo biciesto, si el dia maximo es 28, 31 o 31, etc) 

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# NOTAS:
### **== LUNA ==**
### NOTA 14/11:
MI ESTADO EN EL PROYECTO: Corregi mas errores y conflictos, elimine ArchivoTransacciones pq la logica debe ser aplicada en ArchivosMovimientos

### **MI PLAN DE TAREAS (para el viernes/sabado):**
- Realizar en el siguiente orden:

    **TAREA [1] TERMINADA [✅]**
    
    1. Agregar archivos pre generados (+ admin):
        - Crear la funcion **"inicializarArchivos()"**.
        - Esta funcion debe verificar si **"clientes.dat"** existe. Si no, lo crea y guarda el *"Cliente Banco"* (ID 1).
        - Debe verificar si **"cuentas.dat"** existe. Si no, lo crea y guarda la *"Cuenta Banco"* (ID 1), vinculada al ID 1.
        - Debe verificar **"empleados.dat"**
        - El *Administrador* es un **Singleton** y **NO** se guarda en "**empleados.dat**"

    **TAREA [2] TERMINADA [✅]**

    2. Terminar de modificar **"ArchivoClientes.cpp/.h .**
        - Revisar las funciones de busqueda.
        - Revisar/Modificar la funcion **"modificarCliente()"**.
        - Implementar **"eliminarCliente(int idCliente);"**.

    **TAREA [3] TERMINADA [✅]** 
    <!-- pulir detalles esteticos como la muestra de saldo -->

    3. Empezar a (y en lo posible terminar de) modificar **"ArchivoCuentas".**
        - Implementar/Revisar todas las funciones de busqueda.
        - Implementar/Revisar **"modificarCuenta()"**.
        - Implementar **"cerrarCuentaLogico(int idCuenta)"**.

    **TAREA [4] TERMINADA [✅]**

    4. hacer la adaptacion de **"ArchivoEmpleados"** con lo ya hecho en la de clientes ya que es basicamente similar en bastantes aspectos de la logica (no todo es similar!!)

    **TAREA [5] TERMINADA [✅]**

    5. Terminar de implementar el inicio de sesion (que sea funcional).

    **TAREA [6] TERMINADA [✅]**

    6. Crear la union **"Cliente-Cuenta"**
        - Asegurarse de que **"menuCliente()"** reciba el **int idClienteLogueado** desde la variable de sesion.
        - Implementar la opcion *"Ver mis Cuentas"* llamando a **"listarCuentasPorCliente(idClienteLogueado)"**.
        - Implementar la opcion *"Crear Cuenta"* llamando a **"crearNuevaCuentaBancaria(idClienteLogueado)"**.

    7. Crear **entidades** pre generadas:
        1. **"clientes.dat:** 5 clientes pre cargados.
        2. **"empleados.dat:"** 5 empleados pre cargados (+ administrador pre generado a parte).
        3. **"cuentas.dat:** 5 cuentas pre cargadas (1 x cliente).
        4. **"transacciones.dat:"** *Aun no es posible.*
        5. **"prestamos.dat:"** *Aun no es posible.*

### NOTAS EXTRAS AL TERMINAR:
#### Aca pongo las cosas que vi a mitad del proceso para modificar:
- ❌ Validar que en el final del gmail se ingrese "@gmail.com".
- debo, SIN FALTA, modificar el 3er/4to informe ni idea cual era el ultimo (por las clases, fueron borrados algunos set y todos los gets fueron cambiados a const)

---

# **CHECKLIST:**

Funciones *funcionando*:
- ✅ Crear cliente
- ✅ Iniciar sesión cliente
- ✅ Iniciar sesión empleado
- ✅ Iniciar sesión admin
- ✅ Ver cuentas del cliente
- ✅ Crear cuenta bancaria
- ✅ Ingresar a cuenta
- ✅ Depositar dinero
- ✅ Retirar dinero
- ✅ Transferir dinero
- ✅ Modificar datos cuenta
- ✅ Cerrar cuenta

Funciones *no funcionando*:
- ❌ Préstamos
- ❌ Registro de movimientos

Detalles no terminados
- ⌛ Validaciones de ingresos (la mayoría ya esta, como un 80% minimo).
- ❌ Interfaz detallada y comodidad para el usuario (nada hecho, terrible, 0% 💀)