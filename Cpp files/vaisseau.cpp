#include "../Header Files/vaisseau.h"
#include <iostream>
# include "../Header Files/Coordonnees.h"

//constructeur
Vaisseau::Vaisseau(sf::Color const couleur) {
    if (!texture.loadFromFile("../images/vaisseau.png")) {
        std::cerr << "L'image du vaisseau n'a pas été trouvé dans le directory" << std::endl;
    }

    // Paramètres du sprite
    sprite.setTexture(texture);
    sprite.setColor(couleur);
    sprite.setOrigin((sprite.getLocalBounds().width)/2, (sprite.getLocalBounds().height)/2);
    sprite.setPosition(position.getX(), position.getY());
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
    auto deplacement = vitesse*temps;
    position += deplacement;
    sprite.setPosition(position.getX(), position.getY());

    // Pour faire tourner le vaisseau
    if(tourneDroite) {
        sprite.rotate(VITESSE_ANGULAIRE*temps);
    }
    if (tourneGauche) {
        sprite.rotate(-VITESSE_ANGULAIRE*temps);
    }
}

void Vaisseau::afficher(sf::RenderWindow &fenetre) const {
    fenetre.draw(sprite);
}