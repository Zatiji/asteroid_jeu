#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Header Files/vaisseau.h"
#include <memory>
#include "../Header Files/Asteroid.h"

using namespace std;

const int HAUTEUR_FENETRE = 600;
const int LONGUEUR_FENETRE = 800;

int main() {
sf::RenderWindow fenetre{sf::VideoMode{LONGUEUR_FENETRE,HAUTEUR_FENETRE}, "Asteroid"};
    Coordonnees::initialiserEspace(LONGUEUR_FENETRE,HAUTEUR_FENETRE);
    auto espace = Espace{};

    auto pointeurVaisseau = std::unique_ptr<ElementEspace>(nullptr);

    bool partieDemaree = false;
    while(fenetre.isOpen()) {

        auto evenement = sf::Event();
        while(fenetre.pollEvent(evenement)) {
            if(evenement.type == sf::Event::Closed) {
                fenetre.close();
            }
            if(evenement.type == sf::Event::KeyPressed && !partieDemaree) {
                espace.ajouter(std::make_unique<Vaisseau>(espace, sf::Color::White));
                espace.ajouter(std::make_unique<Asteroide>());
                espace.ajouter(std::make_unique<Asteroide>());
                espace.ajouter(std::make_unique<Asteroide>());
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
