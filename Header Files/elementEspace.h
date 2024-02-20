#ifndef ASTEROIDJEU_ELEMENTESPACE_H
#define ASTEROIDJEU_ELEMENTESPACE_H

#include <SFML/Graphics.hpp>
#include "../Header Files/Vecteur.h"
#include "../Header Files/Coordonnees.h"

class ElementEspace {
    public:
        ElementEspace(std::string_view const &cheminImage);
        void mettreAJour(const float &temps);
        void afficher(sf::RenderWindow &fenetre) const;

    protected:
        sf::Texture texture{};
        sf::Sprite sprite{};
        Coordonnees position{};
        Vecteur vitesse{0.f, 0.f};
};

#endif