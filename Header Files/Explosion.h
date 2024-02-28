#ifndef ASTEROIDJEU_EXPLOSION_H
#define ASTEROIDJEU_EXPLOSION_H

#include "../Header Files/elementEspace.h"
#include "../Header Files/Coordonnees.h"
#include <SFML/Audio.hpp>

class Explosion : public ElementEspace {
public:
    Explosion(const Coordonnees &p_position);
    virtual void reagirCollision(TypeElement typeAutre) override;

protected:
    virtual void mettreAJour(const float &temps) override;


private:
    float age{};
    static constexpr float DUREE_VIE{0.1f};
    sf::Sound son{};

};


#endif //ASTEROIDJEU_EXPLOSION_H