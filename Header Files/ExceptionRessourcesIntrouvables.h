#ifndef ASTEROIDJEU_EXCEPTIONRESSOURCESINTROUVABLES_H
#define ASTEROIDJEU_EXCEPTIONRESSOURCESINTROUVABLES_H

#include <exception>
#include <string_view>
#include <string>

class ExceptionRessourcesIntrouvables : public std::exception {
    public:
        ExceptionRessourcesIntrouvables(std::string_view const& chemin);
        virtual const char* what() const noexcept;

    private:
        std::string messageErreur{};

    protected:
};


#endif //ASTEROIDJEU_EXCEPTIONRESSOURCESINTROUVABLES_H
