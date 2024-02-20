#include "../Header Files/vaisseau.h"
#include <iostream>
# include "../Header Files/Coordonnees.h"

//constructeur
Vaisseau::Vaisseau(sf::Color const couleur) : ElementEspace{"../images/vaisseau.png"} {
    sprite.setColor(couleur);
}

void Vaisseau::actualiserEtat() {
    accelerationEnCours = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    tourneGauche = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    tourneDroite = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}
void Vaisseau::mettreAJour(const float &temps) {

    // Pour faire accélerer le vaisseau
    if(accelerationEnCours) {
        vitesse += Vecteur::creerDepuisAngle(ACCELERATION*temps, sprite.getRotation());
    }
    vitesse -= vitesse*COEFF_FROTTEMENT*temps;

    //on rappelle l'lagorithme de déplacement, définie dans la classe mère
    ElementEspace::mettreAJour(temps);

    // Pour faire tourner le vaisseau
    if(tourneDroite) {
        sprite.rotate(VITESSE_ANGULAIRE*temps);
    }
    if (tourneGauche) {
        sprite.rotate(-VITESSE_ANGULAIRE*temps);
    }
}