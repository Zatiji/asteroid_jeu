#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Header Files/vaisseau.h"
#include "../Header Files/Asteroid.h"
#include <array>
#include "../Header Files/Espace.h"

using namespace std;

const int HAUTEUR_FENETRE = 600;
const int LONGUEUR_FENETRE = 800;

int main() {
sf::RenderWindow fenetre{sf::VideoMode{LONGUEUR_FENETRE,HAUTEUR_FENETRE}, "Asteroid"};
    Coordonnees::initialiserEspace(LONGUEUR_FENETRE,HAUTEUR_FENETRE);
    auto espace = Espace{};
    auto vaisseau = Vaisseau{espace};
    auto asteroide1 = Asteroide{};
    auto asteroide2 = Asteroide{};
    auto asteroide3 = Asteroide{};

    bool partieDemaree = false;
    while(fenetre.isOpen()) {

        auto evenement = sf::Event();
        while(fenetre.pollEvent(evenement)) {
            if(evenement.type == sf::Event::Closed) {
                fenetre.close();
            }
            if(evenement.type == sf::Event::KeyPressed && !partieDemaree) {
                espace.ajouter(asteroide3);
                espace.ajouter(asteroide2);
                espace.ajouter(asteroide1);
                espace.ajouter(vaisseau);
                partieDemaree = true;
            }
        }

        espace.actualiser();
        espace.gererCollision();
        espace.nettoyer();


        fenetre.clear(sf::Color::Black);
        espace.afficher(fenetre);
        fenetre.display();
    }
    return 0;
}
