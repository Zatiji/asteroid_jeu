#ifndef ASTEROIDJEU_VAISSEAU_H
#define ASTEROIDJEU_VAISSEAU_H

#include <SFML/Graphics.hpp>

class Vaisseau {
    public:
    Vaisseau(sf::Color couleur = sf::Color::White);

    void avancer();
    void afficher(sf::RenderWindow &fenetre);

    private:
    sf::Texture texture{};
    sf::Sprite sprite{};
};


#endif //ASTEROIDJEU_VAISSEAU_H
