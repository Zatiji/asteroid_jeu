#ifndef ASTEROIDJEU_VAISSEAU_H
#define ASTEROIDJEU_VAISSEAU_H

#include <SFML/Graphics.hpp>
#include "../Header Files/Vecteur.h"
#include "../Header Files/Coordonnees.h"
#include "../Header Files/elementEspace.h"

class Vaisseau : public ElementEspace{
    public:
        Vaisseau(sf::Color const couleur = sf::Color::White);
        void actualiserEtat();
        void mettreAJour(const float &temps);

    private:
        bool accelerationEnCours{false};
        bool tourneGauche{false};
        bool tourneDroite{false};

        static constexpr float ACCELERATION{900.f};
        static constexpr float COEFF_FROTTEMENT{2.f};
        static constexpr float VITESSE_ANGULAIRE{100.f};
};


#endif //ASTEROIDJEU_VAISSEAU_H
