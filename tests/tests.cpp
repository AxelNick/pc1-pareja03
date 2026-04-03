#include <iostream>
#include <vector>
#include <cassert>
#include "../src/solution.hpp"

void runTests() {
    Solution sol;

    // 1. Caso Normal (Arrange)
    std::vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    // Act & Assert
    assert(sol.searchBinary(nums1, target1) == 4);

    // 2. Caso Normal: No existe
    int target2 = 2;
    assert(sol.searchBinary(nums1, target2) == -1);

    // 3. Caso Borde: Arreglo de 1 solo elemento
    std::vector<int> nums2 = {5};
    assert(sol.searchBinary(nums2, 5) == 0);
    assert(sol.searchBinary(nums2, -2) == -1);

    // 4. Caso Extremo: Target menor que el primer elemento o mayor que el último
    assert(sol.searchBinary(nums1, -100) == -1);
    assert(sol.searchBinary(nums1, 100) == -1);

    std::cout << "¡Todos los tests pasaron correctamente!" << std::endl;
}

int main() {
    runTests();
    return 0;
}