#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Header Files/vaisseau.h"
#include "../Header Files/Coordonnees.h"

using namespace std;

const int HAUTEUR_FENETRE = 600;
const int LONGUEUR_FENETRE = 800;

int main() {
sf::RenderWindow fenetre{sf::VideoMode{LONGUEUR_FENETRE,HAUTEUR_FENETRE}, "Asteroid"};
    Coordonnees::initialiserEspace(LONGUEUR_FENETRE,HAUTEUR_FENETRE);
    auto vaisseau = Vaisseau{};
    auto chrono = sf::Clock{};
    while(fenetre.isOpen()) {
        auto evenement = sf::Event();
        while(fenetre.pollEvent(evenement)) {
            if(evenement.type == sf::Event::Closed) {
                fenetre.close();
            }
        }

        vaisseau.actualiserEtat();
        vaisseau.mettreAJour(chrono.restart().asSeconds());

        fenetre.clear(sf::Color::Black);
        vaisseau.afficher(fenetre);
        fenetre.display();
    }
    return 0;
}
