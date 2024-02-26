#include "../Header Files/Missile.h"

Missile::Missile(Coordonnees const& p_position, float rotation) : ElementEspace{"../images/missile.png"}
{
    type = TypeElement::MISSILE;
    position = p_position;
    sprite.setRotation(rotation);
    vitesse = Vecteur::creerDepuisAngle(VITESSE, rotation);
}

void Missile::reagirCollision(TypeElement typeAutre) {
    if(typeAutre != TypeElement::VAISSEAU) {
        detruit = true;
    }
}