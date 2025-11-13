
# LISTA DE COSAS PRINCIPALES FALTANTES:
### **MARCAS:**
### ✅ = Terminado
### ⚠️ = Revisar
### ⌛ = En proceso
## ***ctrl + shift + v*** = mejor vista de las notas
### HACER:
1. funcion INICIAR SESION/CREAR CUENTA:
funcion para el menu "iniciarSesion" donde adentro estaran las siguentes funciones: 
    - "crearCuenta:"
    Para crear la cuenta se debe crear un nuevo 'cliente'.
    - "iniciarSesion:"
    Para Iniciar sesion (cliente) se deben validar los datos buscando desde el archivo clientes.dat' si el mail y contraseña existen y si son correctos.
    - "iniciarSesionEmpleado:" 
    Para iniciar sesion (empleado) se deben validar los datos, lo mismo que al cliente.
    - Para iniciar sesion como admin, debe entrar a iniciar sesion de empleado, sigue el mismo proceso (pensaba hacer un if de q si los datos coinciden, activar el bool de Permisos globales de la clase de admin)
    - variables principales:
        - bool 'sesionActiva'
        - int 'idUsuarioActual'
        - char[20] o int 'tipoUsuario'

2. funciones BORRAR CLIENTE/EMPLEADO/CUENTA:
estan los esqueletos pero no las funciones, tengo igual algunas a medio hacer, asi que solo es adaptarlo a lo que se necesita. Creo q se podria hacer sobrecarga.

3. funciones de busqueda:
estan los esqueletos pero no las funciones, no se si se necesita memoria dinamica, pero tengo una idea de como se hace.✅

4. funciones de modificacion:
no estan ni los esqueletos creo, y creo que se debe utilizar memoria dinamica.

5. funciones generar IDs, generar legajo y cvu: ⌛
siguen la misma logica del Id del cliente, es solo adaptar.

6. funcion generar Alias:
debe ser unico y podria tener un formato como mp si es q no es mucho lio, tengo que buscar como podria generarse. No tengo ni idea como se generaría pero capaz 

7. funciones de listado:
necesita memoria dinamica creo, me gustaria poner un contador para cada listado, para llevar un conteo de todo.

8. Asociar una cuenta al cliente / asociar la cuenta principal al empleado y al admin
Esto si que no se como hacerlo, pero la idea seria que al crear la cuenta de banco, en el setter del id cliente, se copie el id del cliente que tiene la sesion activa, para eso se debe tener iniciadas las variables comentadas en el primer punto, no se si voy a necesitar mas despues, pero por ahora esas son las mas importantes

9. Validaciones:
    - validar que no se repitan los mails al crear cuenta✅
    - validar el ingreso de fechas (año biciesto, si el dia maximo es 28, 31 o 31, etc) ✅

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# NOTAS:
### **== LUNA ==**
### NOTA 12/11:
MI ESTADO EN EL PROYECTO: despues de subir mis cambios arreglé un conflicto y actualmente no deje nada pendiente, puedo empezar con mi lista de "Cosas para hacer" sin problemas. Lo unico que podria hacer antes de eso es revisar los ultimos cambios bajados (no mios).
- cambios y conflictos arreglados
- mañana o el viernes (mas probable) sigo modificando ArchivoClientes y agrego la union de Cliente-Cuenta (es decir, modificar ArchivoCuentass), tambien voy a agregar archivos pre generados + administrador pre generado
### **MI PLAN DE TAREAS (para el viernes/sabado):**
- Realizar en el siguiente orden:

    1. Agregar archivos pre generados (+ admin):
        - Crear la función **"inicializarArchivos()"**.
        - Esta función debe verificar si **"clientes.dat"** existe. Si no, lo crea y guarda el *"Cliente Banco"* (ID 0).
        - Debe verificar si **"cuentas.dat"** existe. Si no, lo crea y guarda la *"Cuenta Banco"* (ID 1), vinculada al ID 0.
        - Debe verificar **"empleados.dat"**
        - El *Administrador* es un **Singleton** y **NO** se guarda en "**empleados.dat**"

    2. Terminar de modificar **"ArchivoClientes.cpp/.h .**
        - Revisar las funciones de búsqueda.
        - Revisar/Modificar la funcion **"modificarCliente()"**.
        - Implementar **"eliminarCliente(int idCliente);"**.

    3. Empezar a (y en lo posible terminar de) modificar **"ArchivoCuentas".**
        - Implementar/Revisar todas las funciones de búsqueda.
        - Implementar/Revisar **"modificarCuenta()"**.
        - Implementar **"cerrarCuentaLogico(int idCuenta)"**.

    4. hacer la adaptacion de **"ArchivoEmpleados"** con lo ya hecho en la de clientes ya que es basicamente similar en bastantes aspectos de la logica (no todo es similar!!)

    5. Terminar de implementar el inicio de sesion (que sea funcional).

    6. Crear la union **"Cliente-Cuenta"**
        - Asegurarse de que **"menuCliente()"** reciba el **int idClienteLogueado** desde la variable de sesión.
        - Implementar la opción *"Ver mis Cuentas"* llamando a **"listarCuentasPorCliente(idClienteLogueado)"**.
        - Implementar la opción *"Crear Cuenta"* llamando a **"crearNuevaCuentaBancaria(idClienteLogueado)"**.

    7. Crear **entidades** pre generadas:
        1. **"clientes.dat:** 5 clientes pre cargados.
        2. **"empleados.dat:"** 5 empleados pre cargados (+ administrador pre generado a parte).
        3. **"cuentas.dat:** 5 cuentas pre cargadas (1 x cliente) - *Aun no es posible*.
        4. **"transacciones.dat:"** *Aun no es posible.*
        5. **"prestamos.dat:"** *Aun no es posible.*
