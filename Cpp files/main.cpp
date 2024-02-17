#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Header Files/vaisseau.h"

using namespace std;

int main() {
    sf::RenderWindow fenetre{sf::VideoMode{800,600}, "Asteroid"};
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
