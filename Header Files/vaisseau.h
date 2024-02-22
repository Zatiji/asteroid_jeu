#ifndef ASTEROIDJEU_VAISSEAU_H
#define ASTEROIDJEU_VAISSEAU_H

#include <SFML/Graphics.hpp>
#include "../Header Files/Vecteur.h"
#include "../Header Files/Coordonnees.h"
#include "../Header Files/elementEspace.h"
#include "../Header Files/Explosion.h"

class Vaisseau : public ElementEspace{
    public:
        explicit Vaisseau(sf::Color const couleur = sf::Color::White);
        void actualiserEtat();
        virtual void reagirCollision() override;
        virtual void afficher(sf::RenderWindow &fenetre) const override;

        protected:
            // mettre override après l,appelle d'une fonction de classe fille modifié pour remarquer les erreurs de frappe
            virtual void mettreAJour(const float &temps) override;

    private:
        bool accelerationEnCours{false};
        bool tourneGauche{false};
        bool tourneDroite{false};
        bool detruit{false};

        Explosion explosion{};

        static constexpr float ACCELERATION{900.f};
        static constexpr float COEFF_FROTTEMENT{2.f};
        static constexpr float VITESSE_ANGULAIRE{100.f};
};


#endif //ASTEROIDJEU_VAISSEAU_H
