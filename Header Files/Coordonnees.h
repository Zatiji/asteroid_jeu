#ifndef ASTEROIDJEU_COORDONNEES_H
#define ASTEROIDJEU_COORDONNEES_H

#include "../Header Files/Vecteur.h"

class Coordonnees {
    public:
        // méthode statique, car l'espace sera le même pour tous les objets de cette classe
        static void initialiserEspace(int &longueur, int &hauteur);
        Coordonnees();
        Coordonnees(float px, float py);

        // inline pour meilleur performance du code
        inline float getX() const {return x;};
        inline float getY() const {return y;};

        void operator+=(Vecteur const &vecteur);

    private:
        void recalculer(); //--------------
        float x{longueurEspace/2.f}; //-------------
        float y{hauteurEspace/2.f}; //--------------

        // ces variables sont statqiue, partagées dans toutes les objets de cette classe
        static int longueurEspace;
        static int hauteurEspace;
};

#endif // ASTEROIDJEU_COORDONNEES_H