#include "../Header Files/Missile.h"
#include "../Header Files/GestionnaireRessources.h"

Missile::Missile(Coordonnees const& p_position, float rotation) : ElementEspace{"../images/missile.png"}
{
    type = TypeElement::MISSILE;
    position = p_position;
    sprite.setRotation(rotation);
    vitesse = Vecteur::creerDepuisAngle(VITESSE, rotation);
    son.setBuffer(GestionnaireRessources<sf::SoundBuffer>::getRessources("../soundEffects/laser.wav"));
    son.play();
}

void Missile::reagirCollision(TypeElement typeAutre) {
    if(typeAutre != TypeElement::VAISSEAU) {
        detruit = true;
    }
}