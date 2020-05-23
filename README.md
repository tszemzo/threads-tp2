# TP2 - Recolectores y Productores - Taller de Programacion
Alumno: Tomas Szemzo - Padrón: 97771

Link al Repositorio: https://github.com/tszemzo/threads-tp2

## Resolución del Trabajo
 
En primer lugar, voy a incluir un UML con el modelo utilizado para la solución parcial y luego el gráfico provisto por la cátedra sobre el flujo en el trabajo práctico.
 
 UML:

![UML](assets/uml.png)

Flujo del trabajo práctico:

![TCP](assets/flow.png)

Como podemos ver en el gráfico, la idea del trabajo es que en el hilo principal (main), a partir de dos archivos que recibimos: el mapa y el archivo de trabajadores, podamos invocar a estos para poder recolectar y producir recursos.

El trabajo práctico aun no esta finalizado, pero la idea que seguí para su realización fue la siguiente:

Primero me enfoque en parsear el archivo de trabajadores, diferenciándolos en dos entidades fuertemente marcadas: los recolectores y los productores. Como cada trabajador debe ser un hilo independiente, se creó a la clase Thread que representa un hilo de los cuales cada trabajador va a estar heredando.

Ni bien cada trabajador es creado en el hilo principal, este va a empezar a correr aunque parcialmente el run() de cada trabajador no tiene comportamiento, aca entrará en juego al condition variable que todavia no llegue a implementar.

Luego, tenemos el parseo del mapa, en donde en mi solución cree un map_parser que su función es a partir del archivo recibido, llenar las colas bloqueantes, que luego los trabajadores, en particular, los recolectores, van a consumir.

Una vez realizada esta parte, me resta continuar, con el llenado del inventario (que aún no existe en mi modelo) y con el que tendre que tener especial cuidado, ya que es un recurso compartido tanto por recolectores como productores.

Y por último, la “consumición” de los productores a medida que se va llenando el inventario para pasar a sumar puntos cuando corresponda.
