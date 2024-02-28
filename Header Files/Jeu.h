#ifndef ASTEROIDJEU_JEU_H
#define ASTEROIDJEU_JEU_H

#include "../Header Files/Espace.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <exception>

class Jeu {

    public:
        Jeu(Espace& p_espace);

        void demarrer();
        void terminer();
        inline bool estEnCours() const { return enCours; };
        void afficher(sf::RenderWindow& fenetre) const;
        void initialiserException(std::exception const& exception);

    protected:

    private:
        Espace& espace;
        bool enCours{false};
        sf::Sprite spriteAccueil{};
        std::unique_ptr<sf::Text> texteException{nullptr};
        sf::Font police{};


};


#endif //ASTEROIDJEU_JEU_H
