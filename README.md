# TP2 - Recolectores y Productores - Taller de Programacion
Alumno: Tomas Szemzo - Padrón: 97771

Link al Repositorio: https://github.com/tszemzo/threads-tp2

## Resolución del Trabajo
 
En primer lugar, voy a incluir un UML con el modelo utilizado para la solución parcial y luego el gráfico provisto por la cátedra sobre el flujo en el trabajo práctico.
 
 UML:

![UML](assets/uml.png)

Flujo del trabajo práctico:

![TCP](assets/flow.png)

Como podemos ver en el gráfico, la idea del trabajo es que en el hilo principal (orchestrator en el trabajo), a partir de dos archivos que recibimos: el mapa y el archivo de trabajadores, podamos invocar a estos para poder recolectar y producir recursos que seran guardados en un inventario y luego, en caso que aplique, que se transformen en puntos de beneficio o recursos excedentes.

Habiendo finalizado el TP, los conceptos utilizados fueron los siguientes:

Primero me enfoque en parsear el archivo de trabajadores, diferenciándolos en dos entidades fuertemente marcadas: los recolectores y los productores. Como cada trabajador debe ser un hilo independiente, tanto productores como recolectores fueron almacenados en un arreglo de threads. En el caso de los recolectores, la implementacion escogida sobrecarga el operador () para que el thread sepa que correr. Para el caso de los productores, se utilizo un ProducerThread que modela a un thread de productores los cuales mediante herencia implementaron al mismo.

Ni bien cada trabajador es creado en el hilo principal, este va a empezar a correr y mediante condition variables se realiza la sincronizacion para los casos donde no hay recursos en el inventario (productores) o las colas bloqueantes se encuentran cerradas (recolectores). Basicamente aqui la idea radica en encontrar el recurso compartido (en este trabajo las colas y el inventario) y mediante dos primitivas: wait (bloquea el thread actual hasta que se despierte la condition variable) y notify_all (notifica a todos los waiting threads).

Luego, tenemos el parseo del mapa, en donde en mi solución cree un map_parser que su función es a partir del archivo recibido, llenar las colas bloqueantes, que luego los trabajadores, en particular, los recolectores, van a consumir.

Por ultimo, luego de que la sincronizacion para el llenado de las colas, el pasaje al inventario (recolectores) y el posterior consumo por parte de los productores es realizado, se liberan todos los threads correspondientes a los trabajadores y se imprimen los resultados finales por pantalla.
