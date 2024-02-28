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
        void ajouterPoints(int points);
        inline bool estEnCours() const { return enCours; };
        void afficher(sf::RenderWindow& fenetre) const;
        void initialiserException(std::exception const& exception);

    protected:

    private:
        void rafraichirTexte();
        void rafraichirMeilleurScore();

        Espace& espace;
        bool enCours{false};
        int score{};
        int meilleurScore{};
        sf::Text texteScore{};
        sf::Text texteMeilleurScore{};
        sf::Sprite spriteAccueil{};
        sf::Font police{};
        std::unique_ptr<sf::Text> texteException{nullptr};
};


#endif //ASTEROIDJEU_JEU_H
