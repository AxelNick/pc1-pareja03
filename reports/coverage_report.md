# Reporte de Cobertura de Pruebas

Se diseñó un conjunto de pruebas utilizando el framework básico con `<cassert>` siguiendo el patrón AAA (Arrange, Act, Assert).

Nuestras pruebas alcanzan un **100% de cobertura de líneas y condiciones** en la función `searchBinary`, ya que evalúan:
1. **Caso de éxito exacto:** Entra al `if` principal (`nums[mid] == target`).
2. **Caso de descarte de mitad izquierda:** Entra al `else if` (`nums[mid] < target`).
3. **Caso de descarte de mitad derecha:** Entra al `else` por defecto.
4. **Casos borde y robustez:** Evaluamos un arreglo de 1 solo elemento y búsquedas de objetivos que están fuera de los rangos mínimo y máximo del arreglo, asegurando que el ciclo `while` finaliza correctamente (finitud) devolviendo `-1` sin crashear.