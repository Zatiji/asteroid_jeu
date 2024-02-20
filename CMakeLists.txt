cmake_minimum_required(VERSION 3.27)
project(asteroidJeu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES "Cpp files/main.cpp"
        "Header Files/vaisseau.h"
        "Cpp files/vaisseau.cpp"
        "Header Files/Vecteur.h"
        "Header Files/Vecteur.h"
        "Cpp files/Vecteur.cpp"
        "Cpp files/Coordonnees.cpp"
        "Header Files/Coordonnees.h"
        "Cpp files/Coordonnees.cpp"
        "Cpp files/Coordonnees.cpp"
        "Cpp files/Coordonnees.cpp"
        "Cpp files/Asteroid.cpp"
        "Header Files/Asteroid.h"
        "Header Files/elementEspace.h"
        "Cpp files/elementEspace.cpp")
add_executable(asteroidJeu ${SOURCE_FILES}
        "Cpp files/vaisseau.cpp"
        "Header Files/Vecteur.h"
        "Cpp files/Vecteur.cpp"
        "Cpp files/Coordonnees.cpp"
        "Header Files/Coordonnees.h"
        "Cpp files/Coordonnees.cpp"
        "Cpp files/Coordonnees.cpp"
        "Cpp files/Coordonnees.cpp"
        "Cpp files/Asteroid.cpp"
        "Header Files/Asteroid.h"
        "Header Files/elementEspace.h"
        "Cpp files/elementEspace.cpp")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(asteroidJeu ${SFML_LIBRARIES})
endif()