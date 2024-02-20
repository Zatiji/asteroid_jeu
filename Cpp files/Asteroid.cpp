#include "../Header Files/Asteroid.h"
#include <iostream>


//constructeur
Asteroide::Asteroide() : ElementEspace{"../images/asteroide.png"} {
    vitesse = {100, 20};
}