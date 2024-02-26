#ifndef ASTEROIDJEU_MISSILE_H
#define ASTEROIDJEU_MISSILE_H

#include "../Header Files/elementEspace.h"

class Missile : public ElementEspace {
    public:
        Missile(Coordonnees const& p_position, float rotation);
        virtual void reagirCollision(TypeElement typeAutre) override;

    protected:
        //ee

    private:
        static constexpr float VITESSE = 2000;
};

#endif //ASTEROIDJEU_MISSILE_H