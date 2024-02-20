#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Header Files/vaisseau.h"
#include "../Header Files/Coordonnees.h"
#include "../Header Files/Asteroid.h"

using namespace std;

const int HAUTEUR_FENETRE = 600;
const int LONGUEUR_FENETRE = 800;

int main() {
sf::RenderWindow fenetre{sf::VideoMode{LONGUEUR_FENETRE,HAUTEUR_FENETRE}, "Asteroid"};
    Coordonnees::initialiserEspace(LONGUEUR_FENETRE,HAUTEUR_FENETRE);
    auto vaisseau = Vaisseau{};
    auto asteroide = Asteroide{};
    auto chrono = sf::Clock{};
    while(fenetre.isOpen()) {
        auto evenement = sf::Event();
        while(fenetre.pollEvent(evenement)) {
            if(evenement.type == sf::Event::Closed) {
                fenetre.close();
            }
        }

        vaisseau.actualiserEtat();
        auto tempsBoucle = chrono.restart().asSeconds();
        vaisseau.mettreAJour(tempsBoucle);
        asteroide.mettreAJour(tempsBoucle);

        fenetre.clear(sf::Color::Black);
        asteroide.afficher(fenetre);
        vaisseau.afficher(fenetre);
        fenetre.display();
    }
    return 0;
}
