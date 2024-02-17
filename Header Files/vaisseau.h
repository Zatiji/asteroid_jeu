#ifndef ASTEROIDJEU_VAISSEAU_H
#define ASTEROIDJEU_VAISSEAU_H

#include <SFML/Graphics.hpp>
#include "../Header Files/Vecteur.h"

class Vaisseau {
    public:
    Vaisseau(sf::Color const couleur = sf::Color::White);

    void actualiserEtat();
    void mettreAJour(const float &temps);
    void afficher(sf::RenderWindow &fenetre) const;

    private:
    sf::Texture texture{};
    sf::Sprite sprite{};
    Vecteur vitesse{0.f, 0.f};

    bool accelerationEnCours{false};
    bool tourneGauche{false};
    bool tourneDroite{false};

    static constexpr float ACCELERATION{900.f};
    static constexpr float COEFF_FROTTEMENT{2.f};
    static constexpr float VITESSE_ANGULAIRE{100.f};
};


#endif //ASTEROIDJEU_VAISSEAU_H
