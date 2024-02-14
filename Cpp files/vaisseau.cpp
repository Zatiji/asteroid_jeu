#include "../Header Files/vaisseau.h"
#include <iostream>

//constructeur
Vaisseau::Vaisseau(sf::Color couleur) {
    if (!texture.loadFromFile("../images/vaisseau.png")) {
        std::cerr << "L'image du vaisseau n'a pas été trouvé dans le directory" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setColor(couleur);
}

void Vaisseau::avancer() {
    sprite.move(10, 0);
}

void Vaisseau::afficher(sf::RenderWindow &fenetre) {
    fenetre.draw(sprite);
}