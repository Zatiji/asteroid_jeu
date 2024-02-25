#ifndef ASTEROIDJEU_ESPACE_H
#define ASTEROIDJEU_ESPACE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "elementEspace.h"

class Espace {
    public:
        Espace();
        void ajouter(ElementEspace& element);
        void actualiser();
        void gererCollision();
        void afficher(sf::RenderWindow& fenetre) const;
        void nettoyer();

    protected:
        //ee

    private:
        std::vector<ElementEspace*> elements{};
        sf::Clock chrono{};
};
#endif //ASTEROIDJEU_ESPACE_H