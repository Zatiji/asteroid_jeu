#ifndef ASTEROIDJEU_ASTEROID_H
#define ASTEROIDJEU_ASTEROID_H

#include "../Header Files/elementEspace.h"
#include "../Header Files/Espace.h"
#include "../Header Files/Jeu.h"

class Asteroide : public ElementEspace {
    public:
         explicit Asteroide(Jeu& p_jeu, Espace& p_espace, Asteroide* parent = nullptr);
         virtual void reagirCollision(TypeElement typeAutre) override;

    private:
        Jeu& jeu;
        Espace& espace;
};

#endif //ASTEROIDJEU_ASTEROID_H