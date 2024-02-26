#include "../Header Files/GestionnaireRessources.h"
#include <iostream>

std::unordered_map<std::string_view, sf::Texture> GestionnaireRessources::ressources{};

sf::Texture const& GestionnaireRessources::getRessources(std::string_view const& chemin) {
    auto resultat = ressources.find(chemin);
    if (resultat == std::end(ressources)) {
        if (!ressources[chemin].loadFromFile(chemin.data())) {
            std::cerr << "Erreur : impossible de charger la texture " << chemin << std::endl;
        }
        return ressources[chemin];
    }
    return resultat->second;
}