#ifndef ASTEROIDJEU_VAISSEAU_H
#define ASTEROIDJEU_VAISSEAU_H

#include <SFML/Graphics.hpp>

class Vaisseau {
    public:
    void avancer();
    void afficher(sf::RenderWindow &fenetre);

    private:
    sf::CircleShape cercle{30};
};


#endif //ASTEROIDJEU_VAISSEAU_H
