#ifndef ASTEROIDJEU_VECTEUR_H
#define ASTEROIDJEU_VECTEUR_H

// comme la plupart des paramètres des méthodes de Vecteur sont public, je le met en «struct»
struct Vecteur {
    void operator+=(Vecteur const& autre);
    void operator-=(Vecteur const& autre);
    Vecteur operator*(float coefficient) const;
    static Vecteur creerDepuisAngle(float taille, float angleEnDegre);
    float x{0.f};
    float y{0.f};
};
#endif