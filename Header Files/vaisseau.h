#ifndef ASTEROIDJEU_VAISSEAU_H
#define ASTEROIDJEU_VAISSEAU_H

#include <SFML/Graphics.hpp>
#include "../Header Files/Vecteur.h"
#include "../Header Files/Coordonnees.h"
#include "../Header Files/elementEspace.h"
#include "../Header Files/Explosion.h"
#include "../Header Files/Espace.h"

class Vaisseau : public ElementEspace{
    public:
        explicit Vaisseau(Espace& p_espace, sf::Color const couleur = sf::Color::White);
        virtual void reagirCollision(TypeElement typeAutre) override;


        protected:
            // mettre override après l,appelle d'une fonction de classe fille modifié pour remarquer les erreurs de frappe
            virtual void mettreAJour(const float &temps) override;

    private:

        void actualiserEtat();

        bool accelerationEnCours{false};
        bool tourneGauche{false};
        bool tourneDroite{false};

        sf::Clock dernierTir;

        Espace& espace;

        static constexpr float ACCELERATION{900.f};
        static constexpr float COEFF_FROTTEMENT{2.f};
        static constexpr float VITESSE_ANGULAIRE{100.f};
};


#endif //ASTEROIDJEU_VAISSEAU_H
