#include <iostream>
#include <vector>
#include <chrono>

int main() {
    const int SIZE = 10000000; // 10 millones de elementos

    // Experimento A: push_back ingenuo (sin reserve)
    auto startA = std::chrono::high_resolution_clock::now();
    std::vector<int> vecA;
    for (int i = 0; i < SIZE; ++i) {
        vecA.push_back(i);
    }
    auto endA = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> timeA = endA - startA;

    // Experimento B: push_back optimizado (con reserve)
    auto startB = std::chrono::high_resolution_clock::now();
    std::vector<int> vecB;
    vecB.reserve(SIZE); // Pre-asignamos la memoria
    for (int i = 0; i < SIZE; ++i) {
        vecB.push_back(i);
    }
    auto endB = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> timeB = endB - startB;

    std::cout << "Tiempo SIN reserve: " << timeA.count() << " ms\n";
    std::cout << "Tiempo CON reserve: " << timeB.count() << " ms\n";

    return 0;
}