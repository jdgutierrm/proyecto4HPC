**METODOLOGÍA PCAM**

**Particionamiento.**

En la etapa de particionamiento los cálculos se descomponen en pequeñas tareas. Usualmente es independiente de la arquitectura o del modelo de programación. Un buen particionamiento divide tanto los cálculos asociados con el problema como los datos sobre los cuales opera.

T1→ Definir y asignar valores a la Matriz 1 y Matriz 2.
T2→ Comprobar que el número de Columnas de la matriz 1 sea igual al número de filas de la matriz 2, esto para que sea posible la multiplicación entre estas matrices.
T3→ Definir la matriz resultado
T4→ Se recorren las columnas de la matriz resultado, para obtener la posición en la columna.

T5→ Se recorren las filas de la matriz resultado, para obtener la posición en la columna.
T6→ Asignar la posición de la matriz a calcular
T7→ Multiplicar los elementos de la fila correspondiente a la matriz 1 con los elementos correspondiente a la columna de la matriz 2.
T8→ Sumar los elementos multiplicados.
T9→ Asignar el resultado de la suma a la posición de la matriz resultado correspondiente, seleccionada en la tarea T2.
(Este procedimiento se repite hasta completar la matriz resultado)

**Comunicación**

Las tareas generadas por una partición están propuestas para ejecutarse concurrentemente pero no pueden, en general, ejecutarse independientemente. Los cálculos en la ejecución de una tarea normalmente requerirán de datos asociados con otras tareas. Los datos deben transferirse entre las tareas y así permitir que los cálculos procedan. Este flujo de información se especifica en esta fase.

T1→ T2 envía el número de columnas de la matriz 1 y el número de filas de la matriz 2.( en T2 si se cumple la condición asignada termina el programa, si no el programa continúa su ejecución)

T1→ T3 envía  el número de filas de la matriz 1 y el número de columnas de la matriz 2.

T4→ T6 envía el número de la posición en la columna.

T5→ T6 envía el número de la posición en la fila.

T7→ T8 envía resultados de las multiplicación de los elementos.

T8→ T9 envía la suma.

T9← T8 recibe la suma y la añade a la matriz resultado.


**Aglomeración**

Las tareas y las estructuras de comunicación definidas en las dos primeras etapas del diseño son evaluadas con respecto a los requerimientos de ejecución y costos de implementación. Si es necesario, las tareas son combinadas en tareas más grandes para mejorar la ejecución o para reducir los costos de comunicación y sincronización. 
T4, T5, T6, T7, T8, T9→ Ya que son procesos que se realizan múltiples veces se pueden realizar con memoria compartida(Para OpenMP)

**Mapeo**

Cada tarea es asignada a un procesador de tal modo que intente satisfacer las metas de competencia al maximizar la utilización del procesador y minimizar los costos de comunicación. 

T4, T5, T6, T7, T8, T9→ Corren eficientemente en multithreading con OpenMP y memoria compartida, para compartir datos entre tareas.

T1,T2,T3→ para estas tareas no es posible la aplicación de multithreading con OpenMP y memoria compartida.
