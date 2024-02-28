#ifndef ASTEROIDJEU_ELEMENTESPACE_H
#define ASTEROIDJEU_ELEMENTESPACE_H

#include <SFML/Graphics.hpp>
#include "../Header Files/Vecteur.h"
#include "../Header Files/Coordonnees.h"

enum class TypeElement {VAISSEAU, ASTEROIDE, MISSILE, AUTRE};

class ElementEspace {
    public:
        virtual ~ElementEspace() = default;
        explicit ElementEspace(std::string_view const&);
        ElementEspace(ElementEspace const& autre) = delete;
        void operator=(ElementEspace const& autre) = delete;
        void actualiser(float temps);
        virtual void afficher(sf::RenderWindow& fenetre) const;

        inline bool estDetruit() const {return detruit;};

        float getRayon() const;
        void testerCollision(ElementEspace& autre);
        virtual void reagirCollision(TypeElement typeAutre) = 0;

    protected:
        virtual void mettreAJour(float temps);
        TypeElement type{TypeElement::AUTRE};
        bool detruit{false};
        sf::Sprite sprite{};
        Coordonnees position{400.f, 300.f};
        Vecteur vitesse{0.f, 0.f};
        float vitesseAngulaire{};
};

#endif