#ifndef ASTEROIDJEU_COORDONNEES_H
#define ASTEROIDJEU_COORDONNEES_H

#include "../Header Files/Vecteur.h"

class Coordonnees {
    public:
        // méthode statique, car l'espace sera le même pour tous les objets de cette classe
        static void initialiserEspace(int const &longueur, int const &hauteur);
        // Coordonnees();
        Coordonnees(float px = longueurEspace/2.f, float py = hauteurEspace/2.f);

        // inline pour meilleur performance du code
        inline float getX() const {return x;};
        inline float getY() const {return y;};

        void operator+=(Vecteur const &vecteur);

    private:
        void recalculer();
        float x{0};
        float y{0};

        // ces variables sont statqiue, partagées dans toutes les objets de cette classe
        static int longueurEspace;
        static int hauteurEspace;
};

#endif // ASTEROIDJEU_COORDONNEES_H