#include "../Header Files/Jeu.h"
#include "../Header Files/vaisseau.h"
#include "../Header Files/Asteroid.h"
#include "../Header Files/GestionnaireRessources.h"
#include "../images/font.h"
#include <exception>
#include <iostream>



Jeu::Jeu(Espace& p_espace) : espace{p_espace} {
    if(!police.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size)) throw std::runtime_error{"Police introuvable"};
    try {
        spriteAccueil.setTexture(GestionnaireRessources::getRessources("../images/accueil.png"));
    } catch(std::exception const& exception) {
        initialiserException(exception);
    }
}

void Jeu::demarrer() {
    enCours = true;
    espace.ajouter(std::make_unique<Vaisseau>(*this, espace, sf::Color::White));
    espace.ajouter(std::make_unique<Asteroide>(espace));
    espace.ajouter(std::make_unique<Asteroide>(espace));
    espace.ajouter(std::make_unique<Asteroide>(espace));
}

void Jeu::terminer() {
    enCours = false;
    espace.vider();
}

void Jeu::afficher(sf::RenderWindow &fenetre) const {
    std::cout << enCours << std::endl;
    if (!enCours) {
        fenetre.draw(spriteAccueil);
    }
    if (texteException) {
        fenetre.draw(*texteException);
    }
}

void Jeu::initialiserException(std::exception const& exception) {
    texteException = std::make_unique<sf::Text>();
    texteException->setFont(police);
    texteException->setString(exception.what());
    texteException->setFillColor(sf::Color::Red);
}
