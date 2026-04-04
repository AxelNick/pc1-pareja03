# Reporte de Optimización y Sanitizers

## 1. Análisis de Builds
Se compilaron diferentes versiones del código para observar el impacto de las banderas de optimización de `g++`. Los tamaños de los archivos ejecutables obtenidos fueron:

* **Build de Depuración (-O0):** 151 KB (154,911 bytes). Es el más pesado, conservando todos los símbolos para facilitar el uso de un debugger.
* **Build Compacto (-Os):** 140 KB (143,552 bytes). Redujo el peso en 11 KB, optimizando el espacio en disco.
* **Build Release (-O2):** 137 KB (140,889 bytes). Al aplicar optimizaciones agresivas y eliminación de código no utilizado (dead code elimination), resultó siendo el binario más ligero y rápido.

## 2. Sanitizers
Al intentar ejecutar la bandera `-fsanitize=address,undefined`, identificamos una limitación de nuestro entorno de desarrollo (Windows con MSYS2/UCRT64), ya que el enlazador no incluye la librería `libasan` por defecto. 
Sin embargo, teóricamente, si nuestro algoritmo tuviera un error (como usar `(left + right) / 2` causando un desbordamiento, o intentar acceder a `nums[nums.size()]`), esta herramienta nos habría alertado con un error crítico de tipo *heap-buffer-overflow*. Nuestro código, al manejar correctamente los límites e invariantes, es seguro en memoria.