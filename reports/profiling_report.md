# Reporte de Profiling y Benchmark

Para nuestro bloque experimental, quisimos demostrar que entender la estructura de datos sirve mucho más que solo ponerle una bandera de optimización al compilador.

Hicimos un benchmark midiendo cuánto tarda la computadora en insertar 10 millones de números a un `std::vector`.
* Tiempo insertando datos a ciegas (solo `push_back`): **~17.40 ms**
* Tiempo avisándole al vector cuánta memoria iba a necesitar (`reserve`): **~7.06 ms**

**Conclusión:** Solo por entender cómo el vector maneja la memoria internamente y usar `reserve()`, bajamos el tiempo a menos de la mitad. El código bien pensado le gana a la fuerza bruta.

**Resultados de Profiling (gprof):**
Cuando analizamos el programa con la herramienta `gprof`, comprobamos exactamente lo que vimos en la teoría de clases. Como la Búsqueda Binaria tiene una complejidad de $O(\log n)$, la computadora la resuelve tan rápido que en el reporte de tiempo sale prácticamente 0.00 segundos. Todo el tiempo real del procesador se gasta en inicializar el arreglo de prueba, que es una tarea $O(n)$.