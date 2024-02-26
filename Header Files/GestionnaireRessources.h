#ifndef ASTEROIDJEU_GESTIONNAIRERESSOURCES_H
#define ASTEROIDJEU_GESTIONNAIRERESSOURCES_H

#include <SFML/Graphics.hpp>
#include <string_view>
#include <unordered_map>

class GestionnaireRessources {
    public:
        // on empêche la création d'obejt de cette classe
        GestionnaireRessources() = delete;
        static sf::Texture const& getRessources(std::string_view const& chemin);

    private:
        static std::unordered_map<std::string_view, sf::Texture> ressources;

    protected:

};

#endif //