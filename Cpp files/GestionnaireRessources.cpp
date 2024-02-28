#include "../Header Files/GestionnaireRessources.h"
#include <iostream>
#include "../Header Files/ExceptionRessourcesIntrouvables.h"

std::unordered_map<std::string_view, sf::Texture> GestionnaireRessources::ressources{};

sf::Texture const& GestionnaireRessources::getRessources(std::string_view const& chemin) {
    auto resultat = ressources.find(chemin);
    if (resultat == std::end(ressources)) {
        if (!ressources[chemin].loadFromFile(chemin.data())) {
            throw ExceptionRessourcesIntrouvables{chemin};
        }
        return ressources[chemin];
    }
    return resultat->second;
}