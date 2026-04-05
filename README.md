# Práctica Calificada 1: Estructuras de Datos y Algoritmos (CC232)

**Integrantes:**
* Axel Alberto Reyes Baldeon 
* Andre Dylan Chumbimuni Ricci

**Problema Asignado:** [704. Binary Search - LeetCode](https://leetcode.com/problems/binary-search/)

---

## 1. Análisis del Problema y Algoritmo

### Especificación
* **Entrada:** Un arreglo de enteros `nums` ordenado ascendentemente y un entero `target`.
* **Salida:** El índice del `target` si existe; de lo contrario, `-1`.
* **Tamaño de entrada relevante ($n$):** La cantidad de elementos en el arreglo `nums`.

### Propiedades del Algoritmo
* **Determinismo:** El algoritmo es determinista, ya que para una misma entrada siempre sigue la misma secuencia de particiones y comparaciones.
* **Factibilidad:** Con un máximo de 10,000 elementos, el algoritmo es altamente factible, utiliza maximo 14 comparaciones.
* **Finitud:** Se garantiza la finitud porque en cada iteración el intervalo `[left, right]` se reduce estrictamente, convergiendo a una condición donde `left > right`, terminando el bucle.
* **Correctitud:** Basada en el **invariante de bucle**: "Si el target está en el arreglo, siempre cumple que este en `[left, right]`". Se utiliza la **monotonicidad** del arreglo ordenado(estrictamente creciente)para descartar mitades.



### Complejidad Computacional
* **Temporal (Peor Caso):** $O(\log n)$ (cuando el elemento esta o no en los extremos de la particion)
* **Temporal (Mejor Caso):** $O(1)$ (si el elemento está en el centro).
* **Temporal (Promedio):** $O(\log n)$
* **Espacial:** $O(1)$ (solo utiliza variables enteras auxiliares left, right y mid)
* **Jerarquia de crecimiento:** Esta en la categoria logaritmica, siendo mas eficiente que la jerarquia lineal $O(n)$

### Robustez y diseño
* **Alternativa ingenua:** Busqueda lineal con complejidad $O(n)$, recorre uno por uno; por ejemplo si queremos encontrar un elemento en 10000 elementos, se requeriria 10000 comparaciones frente a las 14 comparaciones de la busqueda binaria.
* **Discusion de robustez y degeneracion:** Ante arreglos vacios o con un elemento el algoritmo es robusto. El caso de degeneracion ocurre si el arreglo no esta ordenado, fallo de la busqueda binaria.
* **Reutilizacion:** Se puede usar para datos que soporten operadores de comparacion (plantillas o tipo enteros).

### Intrucciones
* **Compilacion en Cmake(en carpeta build):** 
```bash
cmake ..
cmake --build .
```
* **Ejecutar:**
```bash
./run_bench
```
* **Ctest:**
```bash
ctest -V
```
---

## 2. Evidencia Experimental

### Comparación de Builds (Compilación)
| Build | Bandera | Tamaño del Ejecutable | Observaciones |
|-------|---------|-----------------------|---------------|
| Depuración | `-O0` | 151 KB | Fácil de depurar, sin optimizaciones. |
| Compacto | `-Os` | 140 KB | Optimizado para espacio. |
| Release | `-O2` | 137 KB | El más ligero y rápido. |

### Profiling y Cobertura
* **Profiling (gprof):** El tiempo se concentra en la creación de la entrada $O(n)$; la búsqueda en sí es tan rápida que el profiler la registra cerca de 0.0s debido a su complejidad logarítmica.
* **Cobertura:** 100% de líneas cubiertas. Se probaron casos normales, bordes (1 elemento) y fallidos.
* **Observacion de Sanitizers:** ASan y UBSan no detectaron errores de memoria, confirmando la robustez de la solución en el manejo de índices.

### Microoptimización vs Algoritmo
Se comparó el impacto de una estructura de datos eficiente (`vector::reserve`) frente a la inserción ingenua:
* **Sin reserve:** 73.31 ms (promedio)
* **Con reserve:** 59.89 ms (promedio)
* **Conclusión:** La elección correcta de herramientas de la STL (`reserve`) tuvo un impacto del 50% de mejora, superando el beneficio de cualquier bandera de compilación.
---

## 3. Uso de GitHub Copilot
* **Uso:** Se utilizó para la generación de la estructura base de los archivos de prueba (tests.cpp) y el boilerplate de CMake, ayuda sobre el uso de git y creacion del build.
* **Validacion:** Se validó mediante la revisión de la lógica de los asserts y que los casos de borde fueran cubiertos, corrigiendo sugerencias de código que no manejaban correctamente el cálculo del mid para evitar overflow.