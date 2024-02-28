#ifndef ASTEROIDJEU_ESPACE_H
#define ASTEROIDJEU_ESPACE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "elementEspace.h"

class Espace {
    public:
        Espace();
        void ajouter(std::unique_ptr<ElementEspace> element);
        void actualiser();
        void gererCollision();
        void afficher(sf::RenderWindow& fenetre) const;
        void nettoyer();
        void vider();

    protected:
        //ee

    private:
        std::vector<std::unique_ptr<ElementEspace>> elements{};
        sf::Clock chrono{};
        std::vector<std::unique_ptr<ElementEspace>> aAjouter{};
        bool aVider = false;
};
#endif //ASTEROIDJEU_ESPACE_H