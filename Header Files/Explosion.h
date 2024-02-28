#ifndef ASTEROIDJEU_EXPLOSION_H
#define ASTEROIDJEU_EXPLOSION_H

#include "../Header Files/elementEspace.h"
#include <SFML/Audio.hpp>

class Explosion : public ElementEspace {
    public:
        Explosion(Coordonnees const& p_position);
        virtual void reagirCollision(TypeElement typeAutre) override;

    protected:
        virtual void mettreAJour(float temps) override;


    private:
        float age{0};
        sf::Sound son{};
        static constexpr float DUREE_VIE{0.1f};

};

#endif //ASTEROIDJEU_EXPLOSION_H