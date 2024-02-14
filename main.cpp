#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main() {
    sf::RenderWindow fenetre{sf::VideoMode{800,600}, "Asteroid"};
    auto cercle = sf::CircleShape{100};
    cercle.setFillColor(sf::Color{128, 255, 128});
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

        fenetre.clear(sf::Color::Blue);
        fenetre.draw(cercle);
        vaisseau.afficher(fenetre);
        fenetre.display();
    }
    return 0;
}
