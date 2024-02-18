#include "../Header Files/Coordonnees.h"
#include <iostream>

int Coordonnees::longueurEspace{0};
int Coordonnees::hauteurEspace{0};



Coordonnees::Coordonnees(float px, float py) {
    // On envoie un message d'erreur si une coordonnée est créé avant l'initialisation de l'espace
    if(longueurEspace == 0 || hauteurEspace == 0) {
        std::cerr << "ATTENTION: une coordonnée a été créée avant l'initialisation de l'espace!" << std::endl;
    }
    x = px;
    y = py;
    Coordonnees::recalculer();
}

void Coordonnees::operator+=(const Vecteur &vecteur) {
    x += vecteur.x;
    y += vecteur.y;
    Coordonnees::recalculer();
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

