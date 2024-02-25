#ifndef ASTEROIDJEU_ELEMENTESPACE_H
#define ASTEROIDJEU_ELEMENTESPACE_H

#include <SFML/Graphics.hpp>
#include "../Header Files/Vecteur.h"
#include "../Header Files/Coordonnees.h"

class ElementEspace {
    public:
        virtual ~ElementEspace() = default;
        explicit ElementEspace(std::string_view const &cheminImage);
        // empêcher les copies d'objets
        ElementEspace(ElementEspace const &autre) = delete;
        void operator=(ElementEspace const &autre) = delete;
        void actualiser(const float &temps);
        virtual void afficher(sf::RenderWindow &fenetre) const;
        void testerCollision(ElementEspace &autre);
        // méthode abstraite: déclaré, mais pas définie, on est alors obligée de re déclarer cette méthode dans les classes filles
        virtual void reagirCollision() = 0;

        float getRayon();

    protected:
        virtual void mettreAJour(const float &temps);
        sf::Texture texture{};
        sf::Sprite sprite{};
        Coordonnees position{};
        Vecteur vitesse{0.f, 0.f};
        float vitesseAngulaire;
};

#endif