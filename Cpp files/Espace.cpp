#include "../Header Files/Espace.h"
#include <iostream>

Espace::Espace() { }

void Espace::ajouter(std::unique_ptr<ElementEspace> element) {
    aAjouter.push_back(std::move(element));
}

void Espace::actualiser() {
    auto tempsBoucle = chrono.restart().asSeconds();
    for(auto i{0u}; i<elements.size(); ++i) {
        elements[i]->actualiser(tempsBoucle);
    }
}

void Espace::gererCollisions() {
    for(auto i{0u}; i<elements.size(); ++i) {
        for(auto j{0u}; j<elements.size(); ++j) {
            if(i != j) {
                elements[i]->testerCollision(*elements[j]);
            }
        }
    }
}

void Espace::afficher(sf::RenderWindow& fenetre) const {
    for(auto& element : elements) {
        element->afficher(fenetre);
    }
}

// retirer les lélments du vector
void Espace::nettoyer() {
    if(aVider) {
        elements.clear();
        aVider = false;
    }
    auto finTableau = std::remove_if(std::begin(elements), std::end(elements), [](auto& element){return element->estDetruit();});
    elements.erase(finTableau, std::end(elements));
    for(auto& element : aAjouter) {
        elements.push_back(std::move(element));
    }
    aAjouter.clear();
}

void Espace::vider() {
    aVider = true;
}