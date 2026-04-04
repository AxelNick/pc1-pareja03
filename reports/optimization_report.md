# Reporte de Optimizaciones y Sanitizers

En esta parte del laboratorio, probamos compilar nuestro código con distintas banderas de `g++` para ver cómo afectaban el peso final del ejecutable. Estos fueron los resultados:

* **Sin optimizar (-O0):** El archivo pesó **151 KB**. Como era de esperarse, es el más pesado porque el compilador deja todo el código intacto para que podamos usar un debugger sin problemas.
* **Optimizado para tamaño (-Os):** Bajó a **140 KB**. Cumplió su función de ahorrar espacio en el disco.
* **Modo Release (-O2):** Quedó en **137 KB**. Nos pareció muy interesante que la bandera enfocada en velocidad terminara haciendo el archivo más ligero de todos. Esto pasa porque el compilador recorta todo el código que no se usa.

**Sobre el uso de Sanitizers:**
Quisimos usar el AddressSanitizer (`-fsanitize=address,undefined`) para buscar errores de memoria, pero tuvimos un problema técnico: al usar Windows con el entorno MSYS2/UCRT64, el compilador no trae la librería `libasan` por defecto, así que nos dio un error de enlazado (linker). 
Aun así, estamos seguros de que nuestro código es seguro en memoria porque evitamos el clásico error de desbordamiento (overflow) calculando el punto medio como `left + (right - left) / 2`, y tenemos cuidado con los límites del arreglo.