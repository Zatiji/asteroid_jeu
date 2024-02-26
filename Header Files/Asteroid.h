#ifndef ASTEROIDJEU_ASTEROID_H
#define ASTEROIDJEU_ASTEROID_H

#include <SFML/Graphics.hpp>
#include "../Header Files/Vecteur.h"
#include "../Header Files/Coordonnees.h"
#include "../Header Files/elementEspace.h"

class Asteroide : public ElementEspace {
    public:
         explicit Asteroide();
         virtual void reagirCollision(TypeElement typeAutre) override;

    private:
};

#endif