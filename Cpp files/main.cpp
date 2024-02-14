#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Header Files/vaisseau.h"

using namespace std;

int main() {
    sf::RenderWindow fenetre{sf::VideoMode{800,600}, "Asteroid"};
    auto vaisseau = Vaisseau{};
    while(fenetre.isOpen()) {
        auto evenement = sf::Event();
        while(fenetre.pollEvent(evenement)) {
            if(evenement.type == sf::Event::Closed) {
                fenetre.close();
            }
            if(evenement.type == sf::Event::KeyPressed) {
                vaisseau.avancer();
            }
        }

        fenetre.clear(sf::Color::Black);
        vaisseau.afficher(fenetre);
        fenetre.display();
    }
    return 0;
}
