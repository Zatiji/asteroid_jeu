#include "../Header Files/GestionnaireRessource.h"
#include <iostream>

std::map<std::string_view, std::unique_ptr<sf::Texture>> GestionnaireRessource::textures{};

sf::Texture const& GestionnaireRessource::getTexture(std::string_view const& chemin) {
    auto recherche = textures.find(chemin);
    if(recherche == textures.end()) {
        textures.emplace(chemin, std::make_unique<sf::Texture>());
        if(!textures[chemin]->loadFromFile(chemin.data())) {
            std::cerr << "error" << std::endl;
        }
    }
    return *textures[chemin];
}