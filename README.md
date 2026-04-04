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
* **Factibilidad:** Con un máximo de 10,000 elementos, el algoritmo es altamente factible, resolviéndose en aproximadamente 14 pasos.
* **Finitud:** Se garantiza la finitud porque en cada iteración el intervalo `[left, right]` se reduce estrictamente a la mitad, convergiendo a una condición donde `left > right`.
* **Correctitud:** Basada en el **invariante de bucle**: "Si el target está en el arreglo, su índice está dentro del rango actual `[left, right]`". Se utiliza la **monotonicidad** del arreglo ordenado para descartar mitades.



### Complejidad Computacional
* **Temporal (Peor Caso):** $O(\log n)$
* **Temporal (Mejor Caso):** $O(1)$ (si el elemento está en el centro).
* **Espacial:** $O(1)$ (solo utiliza variables escalares fijas).

---

## 2. Evidencia Experimental

### Comparación de Builds (Compilación)
| Build | Bandera | Tamaño del Ejecutable | Observaciones |
|-------|---------|-----------------------|---------------|
| Depuración | `-O0` | 151 KB | Fácil de depurar, sin optimizaciones. |
| Compacto | `-Os` | 140 KB | Optimizado para espacio. |
| Release | `-O2` | 137 KB | El más ligero y rápido. |

### Microoptimización vs Algoritmo
Se comparó el impacto de una estructura de datos eficiente (`vector::reserve`) frente a la inserción ingenua:
* **Sin reserve:** 21.11 ms (promedio)
* **Con reserve:** 10.23 ms (promedio)
* **Conclusión:** La elección correcta de herramientas de la STL (`reserve`) tuvo un impacto del 50% de mejora, superando el beneficio de cualquier bandera de compilación.

### Profiling y Cobertura
* **Profiling (gprof):** El tiempo se concentra en la creación de la entrada $O(n)$; la búsqueda en sí es tan rápida que el profiler la registra cerca de 0.0s debido a su complejidad logarítmica.
* **Cobertura:** 100% de líneas cubiertas. Se probaron casos normales, bordes (1 elemento) y fallidos.
* **Sanitizers:** ASan y UBSan no detectaron errores de memoria, confirmando la robustez de la solución en el manejo de índices.

---

## 3. Guía de Uso

### Compilación
```bash
g++ -std=c++17 -O2 tests/tests.cpp src/solution.cpp -o programa