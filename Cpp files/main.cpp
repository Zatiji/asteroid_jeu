#include <SFML/Graphics.hpp>
#include "../Header Files/vaisseau.h"
#include "../Header Files/Jeu.h"
#include <exception>


using namespace std;

const int HAUTEUR_FENETRE = 600;
const int LONGUEUR_FENETRE = 800;

int main() {
    sf::RenderWindow fenetre{sf::VideoMode{LONGUEUR_FENETRE, HAUTEUR_FENETRE}, "Asteroids"};
    Coordonnees::initialiserEspace(LONGUEUR_FENETRE, HAUTEUR_FENETRE);
    auto espace = Espace{};
    auto jeu = Jeu{espace};

    while(fenetre.isOpen()) {
        try {
            auto evenement = sf::Event{};
            while(fenetre.pollEvent(evenement)) {
                if(evenement.type == sf::Event::Closed) {
                    fenetre.close();
                }
                if(evenement.type == sf::Event::KeyPressed && !jeu.estEnCours()) {
                    jeu.demarrer();
                }
            }

            espace.actualiser();
            espace.gererCollisions();

            fenetre.clear();
            espace.afficher(fenetre);
            jeu.afficher(fenetre);
            fenetre.display();

            espace.nettoyer();
        } catch(std::exception const& exception) {
            jeu.initialiserException(exception);
        }
    }
    return 0;
}
