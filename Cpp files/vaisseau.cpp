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
    //on rappelle l'lagorithme de déplacement, définie dans la classe mère
    ElementEspace::mettreAJour(temps);
}

void Vaisseau::reagirCollision() {
    if(!detruit) {
        detruit = true;
        explosion.demarrer(position);
    }
}

void Vaisseau::afficher(sf::RenderWindow &fenetre) const {
    if(!detruit) {
        // on affiche le vaisseau par "default mode"
        ElementEspace::afficher(fenetre);
    } else {
        // on affiche avec la version override de vaisseau pour changer de sprite
        explosion.afficher(fenetre);
    }
}