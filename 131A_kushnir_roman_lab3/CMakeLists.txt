cmake_minimum_required(VERSION 3.16)

project(MyArrayProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Вимикає GNU-розширення для чистого C++20

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(
        -Wall          # Увімкнути базові попередження
        -Wextra        # Увімкнути додаткові попередження
        -Wpedantic     # Строга відповідність стандарту
        -fdiagnostics-color=always # Кольоровий вивід помилок у терміналі VS Code
    )
endif()


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(131a_kushnir_roman_lab3_app
    main.cpp
    intarray.cpp
)

#cmake_minimum_required(VERSION 3.16)

#project(131a_kushnir_roman_lab3_project LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(131a_kushnir_roman_lab3_app
#main.cpp
#intarray.cpp
#)