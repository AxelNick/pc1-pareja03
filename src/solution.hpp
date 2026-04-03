#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>

/**
 * @brief Clase que implementa algoritmos de búsqueda.
 * Sigue los principios de ADT: separa la interfaz de la implementación.
 */
class Solution {
public:
    /**
     * @brief Solución Óptima: Búsqueda Binaria.
     * Complejidad Temporal: O(log n)
     * Complejidad Espacial: O(1)
     * Precondición: El vector 'nums' debe estar ordenado.
     */
    int searchBinary(const std::vector<int>& nums, int target);

    /**
     * @brief Solución Ingenua: Búsqueda Lineal.
     * Complejidad Temporal: O(n)
     * Complejidad Espacial: O(1)
     */
    int searchLinear(const std::vector<int>& nums, int target);
};

#endif