#ifndef  ASTEROIDJEU_GESTIONNAIRERESSOURCE_H
#define ASTEROIDJEU_GESTIONNAIRERESSOURCE_H

#include <map>
#include <string_view>
#include <memory>
#include <SFML/Graphics.hpp>

class GestionnaireRessource {
    public:
        static sf::Texture const& getTexture(std::string_view const& chemin);

    protected:

    private:
        static std::map<std::string_view, std::unique_ptr<sf::Texture>> textures;
};

#endif // ASTEROIDJEU_GESTIONNAIRERESSOURCE_H