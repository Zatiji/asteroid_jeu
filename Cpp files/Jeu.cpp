#include "../Header Files/Jeu.h"
#include "../Header Files/vaisseau.h"
#include "../Header Files/Asteroid.h"
#include "../Header Files/GestionnaireRessources.h"
#include "../images/font.h"
#include <exception>
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>

using namespace std::string_literals;



Jeu::Jeu(Espace& p_espace) : espace{p_espace} {
    if(!police.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size)) throw std::runtime_error{"Police introuvable"};
    texteScore.setFont(police);
    texteScore.move(0, 30);

    auto fichier = std::ifstream{"meilleurScore.txt"};
    if(fichier.is_open()) {
        fichier >> meilleurScore;
    }
    fichier.close();

    rafraichirMeilleurScore();
    try {
        spriteAccueil.setTexture(GestionnaireRessources<sf::Texture>::getRessources("../images/accueil.png"));
    } catch(std::exception const& exception) {
        initialiserException(exception);
    }
}

void Jeu::demarrer() {
    enCours = true;
    score = 0;
    rafraichirTexte();
    espace.ajouter(std::make_unique<Vaisseau>(*this, espace, sf::Color::White));
    espace.ajouter(std::make_unique<Asteroide>(*this, espace));
    espace.ajouter(std::make_unique<Asteroide>(*this, espace));
    espace.ajouter(std::make_unique<Asteroide>(*this, espace));
}

void Jeu::terminer() {
    enCours = false;
    if(score > meilleurScore) {
        meilleurScore = score;
        rafraichirMeilleurScore();

        // À cause de clion et leur cmake, le fichier sera crée et stocké dans le dossier "cmake-build-debug"
        auto fichier = std::ofstream{"meilleurScore.txt"};
        if(fichier.is_open()) {
            fichier << meilleurScore;
        } else {
            throw std::runtime_error{"impossible d'ouvrir le fichier meilleurScore.txt en écriture"};
        }
        fichier.close();
    }
    espace.vider();
}

void Jeu::afficher(sf::RenderWindow &fenetre) const {
    if (texteException) {
        fenetre.draw(*texteException);
    } else {
        if (!enCours && espace.estVide()) {
            fenetre.draw(spriteAccueil);
        } else {
            fenetre.draw(texteScore);
        }
        fenetre.draw(texteMeilleurScore);
    }
}

void Jeu::initialiserException(std::exception const& exception) {
    texteException = std::make_unique<sf::Text>();
    texteException->setFont(police);
    texteException->setString(exception.what());
    texteException->setFillColor(sf::Color::Red);
}

void Jeu::ajouterPoints(int points) {
    score += points;
    rafraichirTexte();
}

void Jeu::rafraichirTexte() {
    texteScore.setString("Score : "s + std::to_string(score));
}

void Jeu::rafraichirMeilleurScore() {
    texteScore.setString("Meilleur Score : "s + std::to_string(meilleurScore));
}