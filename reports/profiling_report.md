# Reporte de Profiling y Benchmark

## 1. Benchmark: Microoptimización vs Algoritmo / STL
Para demostrar cómo la comprensión de las estructuras de datos impacta el rendimiento, realizamos un microexperimento aislando la construcción del arreglo de entrada usando `std::chrono`. Comparamos un llenado ingenuo vs uno pre-asignado.

**Resultados del Benchmark (Llenando 10 millones de elementos):**
* Tiempo usando `push_back` ingenuo: **~20.69 ms** (promedio)
* Tiempo usando `push_back` con `reserve()`: **~9.96 ms** (promedio)

**Conclusión:** Evitar que el `std::vector` reasigne dinámicamente su memoria bajo el capó redujo el tiempo de ejecución a la mitad. Esto demuestra que utilizar correctamente las herramientas de la librería estándar (STL) y entender la complejidad espacial tiene un impacto inmensamente superior a simplemente cambiar una bandera de compilación.

## 2. Profiling (gprof)
Al ejecutar el código con la bandera espía `-pg`, el análisis confirmó nuestra teoría de complejidad. Debido a que la Búsqueda Binaria tiene una complejidad logarítmica O(log n), su tiempo de ejecución es de apenas nanosegundos. El 99% del esfuerzo del procesador se concentró exclusivamente en construir el arreglo inicial (O(n)), no en buscar el elemento.