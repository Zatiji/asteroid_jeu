#include "../Header Files/Jeu.h"

#include "../Header Files/vaisseau.h"
#include "../Header Files/Asteroid.h"
#include "../Header Files/GestionnaireRessources.h"
#include "../Header Files//font.h"
#include <exception>
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>

using namespace std::string_literals;

Jeu::Jeu(Espace& p_espace) : espace{p_espace} {
    if(!police.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size)) throw std::runtime_error{"Police introuvable"};
    texteScore.setFont(police);
    texteScore.move(0,30);
    texteMeilleurScore.setFont(police);

    auto fichier = std::ifstream{"meilleurScore.txt"};
    if(fichier.is_open()) {
        fichier >> meilleurScore;
    }
    fichier.close();

    rafraichirMeilleurScore();
    try {
        spriteAccueil.setTexture(GestionnaireRessources<sf::Texture>::getRessource("../images/accueil.png"));
    } catch(std::exception const& exception) {
        initialiserException(exception);
    }
}

void Jeu::demarrer() {
    enCours = true;
    score = 0;
    vague = 0;
    rafraichirTexte();
    espace.ajouter(std::make_unique<Vaisseau>(*this, espace, sf::Color::White));
    spawnerVague();
}

void Jeu::verifierVague() {
    if(!enCours) return;
    if(espace.compter(TypeElement::ASTEROIDE) == 0)
        spawnerVague();
}

void Jeu::spawnerVague() {
    auto generateur = std::mt19937{std::random_device{}()};
    auto distX = std::uniform_real_distribution<float>{0.f, float(Coordonnees::getLongueurEspace()) - 1.f};
    auto distY = std::uniform_real_distribution<float>{0.f, float(Coordonnees::getHauteurEspace()) - 1.f};
    auto distEdge = std::uniform_int_distribution<int>{0, 3};

    int nbMedium = std::min(vague, 5);
    int nbSmall  = std::min(std::max(0, vague - 2), 6);

    auto spawner = [&](float echelle) {
        float x, y;
        switch(distEdge(generateur)) {
            case 0: x = distX(generateur); y = 0.f; break;
            case 1: x = float(Coordonnees::getLongueurEspace()) - 1.f; y = distY(generateur); break;
            case 2: x = distX(generateur); y = float(Coordonnees::getHauteurEspace()) - 1.f; break;
            default: x = 0.f; y = distY(generateur); break;
        }
        espace.ajouter(std::make_unique<Asteroide>(*this, espace, Coordonnees{x, y}, echelle));
    };

    for(int i = 0; i < 3; ++i)        spawner(1.0f);
    for(int i = 0; i < nbMedium; ++i) spawner(1.0f / 1.4f);
    for(int i = 0; i < nbSmall; ++i)  spawner(1.0f / (1.4f * 1.4f));

    ++vague;
}

void Jeu::terminer() {
    enCours = false;
    if(score > meilleurScore) {
        meilleurScore = score;
        rafraichirMeilleurScore();
        auto fichier = std::ofstream{"meilleurScore.txt"};
        if(fichier.is_open()) {
            fichier << meilleurScore;
        } else {
            throw std::runtime_error{"Impossible d’ouvrir le fichier meilleurScore en écriture"};
        }
        fichier.close();
    }
    espace.vider();
}

void Jeu::afficher(sf::RenderWindow& fenetre) const {
    if(texteException) {
        fenetre.draw(*texteException);
    } else {
        if(!enCours && espace.estVide()) {
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
    texteMeilleurScore.setString("Meilleur score : " + std::to_string(meilleurScore));
}