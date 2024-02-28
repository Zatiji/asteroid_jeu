#ifndef ASTEROIDJEU_VAISSEAU_H
#define ASTEROIDJEU_VAISSEAU_H

#include <SFML/Graphics.hpp>
#include "../Header Files/Vecteur.h"
#include "../Header Files/Coordonnees.h"
#include "../Header Files/elementEspace.h"
#include "../Header Files/Explosion.h"
#include "../Header Files/Espace.h"
#include "../Header Files/Jeu.h"

class Vaisseau : public ElementEspace{
    public:
        explicit Vaisseau(Jeu& p_jeu, Espace& p_espace, sf::Color const& couleur);
        virtual void reagirCollision(TypeElement typeAutre) override;


        protected:
            // mettre override après l,appelle d'une fonction de classe fille modifié pour remarquer les erreurs de frappe
            virtual void mettreAJour(float temps) override;

    private:
        void actualiserEtat();

        bool accelerationEnCours{false};
        bool tourneAGauche{false};
        bool tourneADroite{false};

        Jeu& jeu;
        Espace& espace;
        sf::Clock dernierTir{};

        static constexpr float ACCELERATION{700.f};
        static constexpr float COEFF_FROTTEMENTS{2.f};
        static constexpr float VITESSE_ANGULAIRE{100.f};
};


#endif //ASTEROIDJEU_VAISSEAU_H
