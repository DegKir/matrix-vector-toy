cmake_minimum_required(VERSION 3.0)

project(MyMathProject)

# Устанавливаем пути для исходных файлов
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# Исходные файлы для теста MathVector
set(MATHVECTOR_TEST
    ${TESTS_DIR}/mathvector_main.cpp
    ${SRC_DIR}/mathvector.cpp
)

# Исходные файлы для теста Matrix
set(MATRIX_TEST
    ${TESTS_DIR}/matrix_main.cpp
    ${SRC_DIR}/matrix.cpp
    ${SRC_DIR}/mathvector.cpp
)

# Исходные файлы для нового теста
set(NEW_TEST
    ${TESTS_DIR}/main.cpp
    ${SRC_DIR}/matrix.cpp
    ${SRC_DIR}/mathvector.cpp
)

# Исходные файла для теста солверов
set(SOLVER_TEST
    ${TESTS_DIR}/solver_test.cpp
    ${SRC_DIR}/matrix.cpp
    ${SRC_DIR}/mathvector.cpp
    ${SRC_DIR}/solver.cpp
)

# Заголовочные файлы
set(HEADERS
    ${INCLUDE_DIR}/mathvector.h
    ${INCLUDE_DIR}/matrix.h
    ${INCLUDE_DIR}/solver.h
)

# Исполняемые файлы для тестирования MathVector, Matrix и нового теста
add_executable(MathVectorTest ${MATHVECTOR_TEST} ${HEADERS})
add_executable(MatrixTest ${MATRIX_TEST} ${HEADERS})
add_executable(NewTest ${NEW_TEST} ${HEADERS})
add_executable(SolverTest ${SOLVER_TEST} ${HEADERS})

# Путь к заголовочным файлам
target_include_directories(MathVectorTest PUBLIC ${INCLUDE_DIR})
target_include_directories(MatrixTest PUBLIC ${INCLUDE_DIR})
target_include_directories(NewTest PUBLIC ${INCLUDE_DIR})
target_include_directories(SolverTest PUBLIC ${INCLUDE_DIR})
