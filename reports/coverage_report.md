# Reporte de Cobertura de Pruebas

Para asegurarnos de que el algoritmo fuera robusto, escribimos nuestros propios tests usando la librería estándar `<cassert>`. Estructuramos el código siguiendo el patrón AAA (Arrange, Act, Assert) para mantener las pruebas legibles.

Nuestras pruebas cubren el 100% de las ramas de la función `searchBinary`. Evaluamos lo siguiente:
1. **Caso ideal:** Que encuentre el número exacto en el medio (entra al `if`).
2. **Descarte izquierdo/derecho:** Que el algoritmo sepa recortar el arreglo hacia ambos lados (entra al `else if` y al `else`).
3. **Casos borde y errores:** Le pusimos "trampas", como pasarle un arreglo de un solo elemento, o pedirle buscar números exageradamente grandes o negativos que ni siquiera estaban en la lista.

En todos los casos, el bucle `while` demostró su **finitud**: siempre terminó correctamente y devolvió `-1` cuando no encontró el objetivo, sin quedarse en un bucle infinito ni romper el programa.