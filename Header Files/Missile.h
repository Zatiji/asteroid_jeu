#ifndef ASTEROIDJEU_MISSILE_H
#define ASTEROIDJEU_MISSILE_H

#include "../Header Files/elementEspace.h"
#include <SFML/Audio.hpp>

class Missile : public ElementEspace {
    public:
        Missile(Coordonnees const& p_position, float rotation);
        virtual void reagirCollision(TypeElement typeAutre) override;

    protected:

    private:
        sf::Sound son{};
        static constexpr float VITESSE{2000.f};
};

#endif //ASTEROIDJEU_MISSILE_H