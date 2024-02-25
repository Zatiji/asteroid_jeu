#ifndef ASTEROIDJEU_EXPLOSION_H
#define ASTEROIDJEU_EXPLOSION_H

#include "../Header Files/elementEspace.h"
#include "../Header Files/Coordonnees.h"

class Explosion : public ElementEspace {
public:
    Explosion();
    void demarrer(Coordonnees const& p_position);
    virtual void reagirCollision() override;

protected:
    virtual void mettreAJour(const float &temps) override;


private:
    bool demarree{false};
    float age{};
    static constexpr float DUREE_VIE{0.1f};

};


#endif //ASTEROIDJEU_EXPLOSION_H