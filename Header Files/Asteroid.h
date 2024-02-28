#ifndef ASTEROIDJEU_ASTEROID_H
#define ASTEROIDJEU_ASTEROID_H

#include <SFML/Graphics.hpp>
#include "../Header Files/Vecteur.h"
#include "../Header Files/Coordonnees.h"
#include "../Header Files/elementEspace.h"
#include "../Header Files/Espace.h"
#include "../Header Files/Jeu.h"

class Asteroide : public ElementEspace {
    public:
         explicit Asteroide(Jeu& p_jeu, Espace& p_espace, Asteroide* parent = nullptr);
         virtual void reagirCollision(TypeElement typeAutre) override;

    private:
        Espace& espace;
        Jeu& jeu;
};

#endif