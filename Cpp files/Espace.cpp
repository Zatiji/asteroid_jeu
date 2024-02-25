#include "../Header Files/Espace.h"
#include <iostream>

Espace::Espace() { }

void Espace::ajouter(ElementEspace& element) {
    elements.push_back(&element);
    std::cout << "nouvel element" <<std::endl;
}

void Espace::actualiser() {
    auto tempsBoucle = chrono.restart().asSeconds();
    for (auto* element : elements) {
        (*element).actualiser(tempsBoucle);
    }
}

void Espace::gererCollision() {
    for (auto i{0u}; i < elements.size() ; ++i) {
        for (auto j{0u}; j < elements.size() ; ++j) {
            if (i != j) {
                elements[i]->testerCollision(*elements[j]);
            }
        }
    }
}

void Espace::afficher(sf::RenderWindow& fenetre) const {
    for(auto* element : elements) {
        (*element).afficher(fenetre);
    }
}

// retirer les lélments du vector
void Espace::nettoyer() {
    auto finTableau =std::remove_if(std::begin(elements), std::end(elements), ElementEspace::estDetruit);
    elements.erase(finTableau, std::end(elements));
}