#include "../Header Files/vaisseau.h"

void Vaisseau::avancer() {
    cercle.move(10, 0);
}

void Vaisseau::afficher(sf::RenderWindow &fenetre) {
    fenetre.draw(cercle);
}