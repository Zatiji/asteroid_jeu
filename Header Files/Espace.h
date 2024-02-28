#ifndef ASTEROIDJEU_ESPACE_H
#define ASTEROIDJEU_ESPACE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "elementEspace.h"

class Espace {
    public:
        Espace();
        void ajouter(std::unique_ptr<ElementEspace> element);
        void actualiser();
        void gererCollisions();
        void afficher(sf::RenderWindow& fenetre) const;
        void nettoyer();
        void vider();
        inline bool estVide() const {return elements.empty() && aAjouter.empty();};

    protected:

    private:
        std::vector<std::unique_ptr<ElementEspace>> elements{};
        std::vector<std::unique_ptr<ElementEspace>> aAjouter{};
        sf::Clock chrono{};
        bool aVider{false};
};
#endif //ASTEROIDJEU_ESPACE_H