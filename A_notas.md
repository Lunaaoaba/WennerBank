
# LISTA DE COSAS PRINCIPALES FALTANTES:
## marcas:
### ✅ = Terminado
### ⚠️ = Revisar
### ⌛ = En proceso
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
estan los esqueletos pero no las funciones, no se si se necesita memoria dinamica, pero tengo una idea de como se hace.

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
    - validar
    