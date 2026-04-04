cmake_minimum_required(VERSION 3.10)
project(PC1_Algoritmos)

# Estándar C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir la carpeta donde está solution.hpp
include_directories(src)

# 1. EJECUTABLE DE PRUEBAS (Tests)
enable_testing()
add_executable(run_tests 
    tests/tests.cpp 
    src/solution.cpp
)
add_test(NAME PruebasAlgoritmos COMMAND run_tests)


# 2. EJECUTABLE DE BENCHMARK (Rendimiento)
add_executable(run_bench 
    bench/benchmark.cpp 
    src/solution.cpp
)

# 3. Registrar el test para ejecutar el benchmark
add_test(NAME PruebasAlgoritmos COMMAND run_tests)