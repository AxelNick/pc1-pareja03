#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>

class Solution {
public:
    // Solución Óptima: Búsqueda Binaria O(log n)
    int searchBinary(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // Evita el desbordamiento (overflow) de memoria
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Caso base: lo encontramos
            } 
            else if (nums[mid] < target) {
                left = mid + 1; // Descartamos la mitad izquierda
            } 
            else {
                right = mid - 1; // Descartamos la mitad derecha
            }
        }
        return -1; // No se encontró
    }

    // Solución Ingenua: Búsqueda Lineal O(n)
    int searchLinear(const std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

#endif // SOLUTION_HPP