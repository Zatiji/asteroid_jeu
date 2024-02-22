#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Header Files/vaisseau.h"
#include "../Header Files/Asteroid.h"
#include <array>

using namespace std;

const int HAUTEUR_FENETRE = 600;
const int LONGUEUR_FENETRE = 800;

int main() {
sf::RenderWindow fenetre{sf::VideoMode{LONGUEUR_FENETRE,HAUTEUR_FENETRE}, "Asteroid"};
    Coordonnees::initialiserEspace(LONGUEUR_FENETRE,HAUTEUR_FENETRE);
    auto vaisseau = Vaisseau{};
    auto asteroide1 = Asteroide{};
    auto asteroide2 = Asteroide{};
    auto asteroide3 = Asteroide{};
    auto elements = std::array<ElementEspace*, 4>{&asteroide1, &asteroide2, &asteroide3, &vaisseau};
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
        for (auto* element : elements) {
            (*element).actualiser(tempsBoucle);
        }

        for (auto* element : elements) {
            for (auto* element2 : elements) {
                if (element != element2) {
                    (*element).testerCollision(*element2);
                }
            }
        }

        fenetre.clear(sf::Color::Black);
        for(auto* element : elements) {
            (*element).afficher(fenetre);
        }
        fenetre.display();
    }
    return 0;
}
