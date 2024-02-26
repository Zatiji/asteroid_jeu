#include "../Header Files/Explosion.h"
#include <iostream>

Explosion::Explosion(const Coordonnees &p_position) : ElementEspace{"../images/explosion.png"} {
    position = p_position;
}

void Explosion::mettreAJour(const float &temps) {
        age += temps;
    if (age < DUREE_VIE) {
        sprite.setScale(age/DUREE_VIE, age/DUREE_VIE);
    } else {
        detruit = true;
    }
}

void Explosion::reagirCollision(TypeElement typeAutre) {

}