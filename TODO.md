# Proyecto `push_swap`

## Resumen

El programa recibe una lista de enteros, la almacena en el stack `a` y ordena sus elementos de forma ascendente usando únicamente operaciones de Push_swap. El stack `b` comienza vacío y el número más pequeño debe quedar en la cima de `a` al finalizar.

El proyecto exige cuatro estrategias de ordenación en C. La estrategia se selecciona mediante una opción de línea de comandos y, si no se indica ninguna, se utiliza la estrategia adaptativa.

## Reglas y operaciones

Existen dos stacks:

- `a`: contiene los valores de entrada.
- `b`: comienza vacío.

| Operación | Efecto |
| --- | --- |
| `sa` | Intercambia los dos primeros elementos del stack `a`. No hace nada si hay solo uno o ningún elemento |
| `sb` | Intercambia los dos primeros elementos del stack `b`. No hace nada si hay solo uno o ningún elemento |
| `ss` | Ejecuta `sa` y `sb` simultáneamente. |
| `pa` | Mueve el primer elemento del stack `b` a la cima del stack `a`. No hace nada si `b` está vacío |
| `pb` | Mueve el primer elemento del stack `a` a la cima del stack `b`. No hace nada si `a` está vacío |
| `ra` | Desplaza hacia arriba todos los elementos del stack `a` una posición, convirtiendo el primer elemento en el último. |
| `rb` | Desplaza hacia arriba todos los elementos del stack `b` una posición, convirtiendo el primer elemento en el último. |
| `rr` | Ejecuta `ra` y `rb` simultáneamente. |
| `rra` | Desplaza hacia abajo todos los elementos del stack `a` una posición, convirtiendo el último elemento en el primero. |
| `rrb` | Desplaza hacia abajo todos los elementos del stack `b` una posición, convirtiendo el último elemento en el primero. |
| `rrr` | Ejecuta `rra` y `rrb` simultáneamente. |

Las operaciones sobre stacks con menos de dos elementos no producen ningún efecto.

## Índice de desorden

El índice de desorden se calcula sobre el stack `a` original, antes de realizar movimientos:

$$
\text{desorden} = \frac{\text{pares invertidos}}{\text{pares totales}}
$$

Un par está invertido cuando un número mayor aparece antes que uno menor. `0` representa un stack ordenado y `1` el máximo desorden posible. Si `n < 2`, el índice se considera `0` para evitar una división entre cero.

## Estrategias obligatorias

La complejidad debe analizarse según el número de operaciones Push_swap generadas, no según una implementación tradicional sobre arrays.

### Estrategia simple: `O(n²)`

Implementar un algoritmo base adaptado a dos stacks, como inserción, selección, burbuja o extracción repetida del mínimo o del máximo.

### Estrategia intermedia: `O(n√n)`

Implementar una estrategia basada en bloques, chunks o rangos. Una opción recomendada es dividir los valores indexados en aproximadamente `√n` chunks.

### Estrategia compleja: `O(n log n)`

Implementar una estrategia como radix sort adaptado a Push_swap, merge sort con dos stacks o una partición equivalente que cumpla la cota declarada.

### Estrategia adaptativa

Debe elegir el método según el índice de desorden:

| Índice de desorden | Método | Complejidad objetivo |
| --- | --- | --- |
| `desorden < 0,2` | Método para entradas casi ordenadas | `O(n)` |
| `0,2 ≤ desorden < 0,5` | Chunks o rangos | `O(n√n)` |
| `desorden ≥ 0,5` | Método complejo, por ejemplo radix | `O(n log n)` |

El repositorio debe justificar los umbrales y documentar las técnicas y las cotas de tiempo y espacio dentro del modelo de operaciones de Push_swap.

## Interfaz del programa

El ejecutable debe llamarse `push_swap`. El primer argumento numérico representa la cima inicial del stack `a`.

| Opción | Comportamiento |
| --- | --- |
| `--simple` | Fuerza la estrategia `O(n²)`. |
| `--medium` | Fuerza la estrategia `O(n√n)`. |
| `--complex` | Fuerza la estrategia `O(n log n)`. |
| `--adaptive` | Usa la estrategia adaptativa y es la opción predeterminada. |
| `--bench` | Muestra estadísticas por `stderr` después de ordenar. |

Los selectores deben funcionar con cualquier tamaño de entrada e índice de desorden. La salida normal debe contener únicamente las operaciones generadas, una por línea. Sin argumentos, el programa no muestra nada y termina correctamente.

## Gestión de los argumentos de entrada en `main`

- Comprobar `argc` y terminar correctamente, sin mostrar nada, cuando no se reciben argumentos.
- Recorrer `argv` y separar las opciones (`--simple`, `--medium`, `--complex`, `--adaptive` y `--bench`) de los valores numéricos.
- Permitir que las opciones aparezcan en cualquier posición, siempre que no se repitan de forma incompatible.
- Usar `--adaptive` como estrategia predeterminada cuando no se indique otra estrategia.
- Rechazar estrategias duplicadas o combinaciones de opciones incompatibles y enviar exactamente `Error\n` a `stderr`.
- Convertir cada argumento numérico a un `int` sin aceptar conversiones parciales, espacios no previstos, signos aislados ni caracteres adicionales.
- Detectar desbordamientos antes de convertir a `int`, incluidos valores fuera de `INT_MIN` y `INT_MAX`.
- Rechazar argumentos vacíos, valores que no sean enteros y números duplicados.
- Decidir explícitamente cómo tratar argumentos separados por espacios dentro de una misma cadena si se desea admitir ese formato.
- Guardar los valores parseados en la estructura inicial del stack `a` y dejar `b` vacío.
- Conservar la opción `--bench` como configuración del programa, sin imprimirla en `stdout`.
- Ante cualquier error de parsing o validación, liberar toda la memoria reservada y terminar con el mensaje exacto `Error\n` en `stderr`.
- Comprobar después del parsing que existe al menos un número que ordenar cuando se han proporcionado opciones.

## Validación y errores

Rechazar valores que no sean enteros, valores fuera del rango de `int`, números duplicados y opciones desconocidas. En caso de error, escribir exactamente `Error\n` en `stderr`.

## Modo benchmark

Con `--bench`, escribir exclusivamente en `stderr`:

- Índice de desorden inicial como porcentaje con dos decimales.
- Nombre de la estrategia y su clase de complejidad.
- Número total de operaciones.
- Conteo de `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb` y `rrr`.

`stdout` debe seguir conteniendo solo la secuencia de operaciones.

## Restricciones técnicas

- Lenguaje: C.
- Entrega mínima: `Makefile`, archivos `.h` y `.c`.
- El `Makefile` debe incluir `NAME`, `all`, `clean`, `fclean` y `re`, sin relink innecesario.
- No se permiten variables globales.
- Funciones autorizadas: `read`, `write`, `malloc`, `free`, `exit` y `ft_printf` o una función equivalente propia.
- Se permite utilizar `libft`.

## Bases para comenzar el proyecto

### 1. Representar los stacks

Elegir una lista enlazada con punteros al primer y último nodo o un array dinámico con sus tamaños. La representación debe permitir implementar `push`, `swap` y rotaciones sin duplicar lógica.

### 2. Separar responsabilidades

Organizar el proyecto en módulos:

- **Parsing y validación:** argumentos, conversión segura a `int`, duplicados y opciones.
- **Estructuras:** creación, liberación y consulta de los stacks.
- **Operaciones:** las once operaciones y la emisión de instrucciones.
- **Utilidades:** índices normalizados, posiciones y comprobación de orden.
- **Estrategias:** `simple`, `medium`, `complex` y `adaptive`.
- **Benchmark:** contador, desorden inicial y salida por `stderr`.

### 3. Normalizar los valores

Crear una copia ordenada y asignar a cada valor su posición relativa (`0` a `n - 1`). Esta compresión de coordenadas simplifica el tratamiento de negativos, valores grandes y radix sort.

### 4. Implementar operaciones primitivas

Comprobar individualmente `sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra` y sus variantes combinadas. Cada operación debe actualizar los stacks y su contador de benchmark.

### 5. Usar una API común

Todas las estrategias deben invocar la misma API de operaciones, sin manipular directamente la estructura interna de los stacks. Esto facilita las pruebas y el conteo.

### 6. Orden recomendado

1. Parsing, validación y memoria.
2. Estructuras `a` y `b`.
3. Operaciones primitivas y estado final.
4. Casos de cero a cinco elementos.
5. Estrategia simple.
6. Compresión de coordenadas y estrategia compleja.
7. Estrategia por chunks o rangos.
8. Desorden y estrategia adaptativa.
9. Benchmark y documentación de complejidades.

### 7. Pruebas mínimas

Verificar cada operación y comprobar que cada estrategia ordena entradas ordenadas, invertidas y aleatorias; maneja positivos, negativos y límites de `int`; rechaza duplicados e inválidos; deja `b` vacío; escribe solo operaciones en `stdout`; y produce estadísticas correctas con `--bench`.

## Resultado esperado

El binario debe ordenar cualquier entrada válida, utilizar la estrategia solicitada, respetar la salida exacta de Push_swap y justificar la complejidad de cada estrategia según las operaciones generadas.
