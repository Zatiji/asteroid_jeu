#include "../Header Files/vaisseau.h"
#include "../Header Files/Missile.h"
#include <iostream>

//constructeur
Vaisseau::Vaisseau(Espace& p_espace, sf::Color const couleur) : ElementEspace{"../images/vaisseau.png"}, espace{p_espace} {
    type = TypeElement::VAISSEAU;
    sprite.setColor(couleur);
}

void Vaisseau::actualiserEtat() {
    accelerationEnCours = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    tourneGauche = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    tourneDroite = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && dernierTir.getElapsedTime().asSeconds() > 0.5) {
        espace.ajouter(std::make_unique<Missile>(position, sprite.getRotation()));
        dernierTir.restart();
    }
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
}

void Vaisseau::reagirCollision(TypeElement typeAutre) {
    if(typeAutre == TypeElement::ASTEROIDE) {
        detruit = true;
        espace.ajouter(std::make_unique<Explosion>(position));
    }
}