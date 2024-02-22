#include "../Header Files/Explosion.h"

Explosion::Explosion() : ElementEspace{"../images/explosion.png"} {

}

void Explosion::demarrer(const Coordonnees &p_position) {
    position = p_position;
    demarree = true;
}

void Explosion::mettreAJour(const float &temps) {
    if(demarree) {
        age += temps;
    }
    if (age < DUREE_VIE) {
        sprite.setScale(age/DUREE_VIE, age/DUREE_VIE);
    }
}

void Explosion::afficher(sf::RenderWindow &fenetre) const {
    if (age < DUREE_VIE) {
        ElementEspace::afficher(fenetre);
    }
}

void Explosion::reagirCollision() {

}