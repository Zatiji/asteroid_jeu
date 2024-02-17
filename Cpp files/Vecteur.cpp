#include "../Header Files/Vecteur.h"
#include <cmath>

void Vecteur::operator+=(Vecteur const &autre) {
    x += autre.x;
    y += autre.y;
}

void Vecteur::operator-=(Vecteur const &autre) {
    x -= autre.x;
    y -= autre.y;
}

Vecteur Vecteur::operator*(float coefficient) const {
    return Vecteur{x*coefficient, y*coefficient};
}

Vecteur Vecteur::creerDepuisAngle(float const taille, float angleEnDegre) {
    // on doit convertir les radians en dégrées car pour les fonction cos et sin, les radians sont les paramètre de défault
    return Vecteur{static_cast<float>(taille*cos((angleEnDegre/180.f)*M_PI)), static_cast<float>(taille*sin((angleEnDegre/180)*M_PI))};
}