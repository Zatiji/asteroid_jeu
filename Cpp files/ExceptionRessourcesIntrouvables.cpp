#include "../Header Files/ExceptionRessourcesIntrouvables.h"

using namespace std::string_literals;

ExceptionRessourcesIntrouvables::ExceptionRessourcesIntrouvables(std::string_view const& chemin) :messageErreur("Erreur, ressource introuvable :"s + chemin.data()) {
    //ctor
}

const char* ExceptionRessourcesIntrouvables::what() const noexcept {
    return messageErreur.c_str();
}