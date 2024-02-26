#ifndef ASTEROIDJEU_ASTEROID_H
#define ASTEROIDJEU_ASTEROID_H

#include <SFML/Graphics.hpp>
#include "../Header Files/Vecteur.h"
#include "../Header Files/Coordonnees.h"
#include "../Header Files/elementEspace.h"
#include "../Header Files/Espace.h"

class Asteroide : public ElementEspace {
    public:
         explicit Asteroide(Espace& p_espace, Asteroide* parent = nullptr);
         virtual void reagirCollision(TypeElement typeAutre) override;

    private:
        Espace& espace;
};

#endif