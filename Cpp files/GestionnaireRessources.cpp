#include "../Header Files/GestionnaireRessources.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

template<>
std::unordered_map<std::string_view, sf::Texture> GestionnaireRessources<sf::Texture>::ressources{};

template<>
std::unordered_map<std::string_view, sf::SoundBuffer> GestionnaireRessources<sf::SoundBuffer>::ressources{};
