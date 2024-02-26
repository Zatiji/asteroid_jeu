#include "../Header Files/elementEspace.h"
#include "../Header Files/Coordonnees.h"
#include <iostream>

//constructeur
ElementEspace::ElementEspace(std::string_view const &cheminImage) {
    if (!texture.loadFromFile(cheminImage.data())) {
        std::cerr << "L'image de " << cheminImage << "n'a pas été trouvé dans le directory" << std::endl;
    }

    // Paramètres du sprite
    sprite.setTexture(texture);
    sprite.setOrigin((sprite.getLocalBounds().width)/2, (sprite.getLocalBounds().height)/2);
    sprite.setPosition(position.getX(), position.getY());
}

// Fonction d'affichage sur fenetre
void ElementEspace::afficher(sf::RenderWindow &fenetre) const {
    // On crée un matrice pour après utiliser la méthode transform de sf
    auto affichages = std::array<Vecteur, 9>{Vecteur{-1, -1}, Vecteur{0, -1}, Vecteur{1, -1},
                                             Vecteur{-1, 0}, Vecteur{0, 0}, Vecteur{1, 0},
                                             Vecteur{-1, 1}, Vecteur{0, 1}, Vecteur{1, 0}};

    // La boucle permet de d'afficher le vaisseau à travers deux côtés si il est en train de traverser une borne
    for (auto &affichage : affichages) {
        auto transformation = sf::Transform{};
        transformation.translate(affichage.x*Coordonnees::getLongueurEspace(), affichage.y*Coordonnees::getHauteurEspace());
        fenetre.draw(sprite, transformation);
    }
}

void ElementEspace::actualiser(const float &temps){
    mettreAJour(temps);
    // Pour faire accélerer le vaisseau
    auto deplacement = vitesse*temps;
    position += deplacement;
    sprite.setPosition(position.getX(), position.getY());
    sprite.rotate(vitesseAngulaire*temps);
}

float ElementEspace::getRayon() {
    return sprite.getLocalBounds().height/2.f;
}

void ElementEspace::testerCollision(ElementEspace &autre) {
    auto distance = position.calculerDistance(autre.position);
    if(distance < getRayon() + autre.getRayon()) {
        reagirCollision(autre.type);
    }
}

void ElementEspace::mettreAJour(float const &temps) {

}