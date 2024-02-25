#include "../Header Files/vaisseau.h"
#include <iostream>

//constructeur
Vaisseau::Vaisseau(Espace& p_espace, sf::Color const couleur) : ElementEspace{"../images/vaisseau.png"}, espace{p_espace} {
    sprite.setColor(couleur);
}

void Vaisseau::actualiserEtat() {
    accelerationEnCours = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    tourneGauche = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    tourneDroite = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Vaisseau::mettreAJour(const float &temps) {

    Vaisseau::actualiserEtat();

    if(!detruit) {
        // Pour faire accélerer le vaisseau
        if(accelerationEnCours) {
            vitesse += Vecteur::creerDepuisAngle(ACCELERATION*temps, sprite.getRotation());
        }
        vitesse -= vitesse*COEFF_FROTTEMENT*temps;

        // Pour faire tourner le vaisseau
        if(tourneDroite) {
            vitesseAngulaire = VITESSE_ANGULAIRE;
        } else if (tourneGauche) {
            vitesseAngulaire = -VITESSE_ANGULAIRE;
        } else {
            vitesseAngulaire = 0;
        }
    }
     //explosion.actualiser(temps);
}

void Vaisseau::reagirCollision() {
    if(!detruit) {
        detruit = true;
        explosion.demarrer(position);
        espace.ajouter(explosion);
    }
}