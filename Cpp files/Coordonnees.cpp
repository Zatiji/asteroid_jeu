#include "../Header Files/Coordonnees.h"
#include <iostream>
#include <cmath>
#include <algorithm>

int Coordonnees::longueurEspace{0};
int Coordonnees::hauteurEspace{0};



Coordonnees::Coordonnees(float px, float py) : x(px), y(py){
    // On envoie un message d'erreur si une coordonnée est créé avant l'initialisation de l'espace
    if(longueurEspace == 0 || hauteurEspace == 0) {
        std::cerr << "ATTENTION: une coordonnée a été créée avant l'initialisation de l'espace!" << std::endl;
    }
    Coordonnees::recalculer();
}

void Coordonnees::operator+=(Vecteur const &vecteur) {
    x += vecteur.x;
    y += vecteur.y;
    recalculer();
}

void Coordonnees::initialiserEspace(int const &longueur, int const &hauteur) {
    // On envoie un message d'erreur si l'espace était déja initialisé
    if(longueurEspace != 0 || hauteurEspace != 0) {
        std::cerr << "ATTENTION: l'espace était déja défini" << std::endl;
    }
    longueurEspace = longueur;
    hauteurEspace = hauteur;
}

void Coordonnees::recalculer() {
    while(x < 0){
        x += float(longueurEspace);
    }
    while(x > float(longueurEspace)){
        x -= float(longueurEspace);
    }
    while(y < 0){
        y += float(hauteurEspace);
    }
    while(y > float(hauteurEspace)) {
        y -= float(hauteurEspace);
    }
}

float Coordonnees::calculerDistance(const Coordonnees &autre) const {
    auto delta = Vecteur{std::min({abs(x - autre.x), abs(x-autre.x-longueurEspace), abs(x-autre.x+longueurEspace)}),
                         std::min({abs(y - autre.y), abs(y - autre.y - longueurEspace), abs(y - autre.y + longueurEspace)})};
    return sqrt(delta.x*delta.x + delta.y*delta.y);
}

