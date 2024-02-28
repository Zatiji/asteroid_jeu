#include "../Header Files/Explosion.h"
#include "../Header Files/GestionnaireRessources.h"

//#include <iostream>
//using namespace std;


Explosion::Explosion(Coordonnees const& p_position) : ElementEspace{"../images/explosion.png"}
{
    position = p_position;
    son.setBuffer(GestionnaireRessources<sf::SoundBuffer>::getRessource("../soundEffects/explosion.wav"));
    son.play();
}

void Explosion::mettreAJour(float temps) {
    age += temps;
    if(age < DUREE_VIE) {
        sprite.setScale(age/DUREE_VIE, age/DUREE_VIE);
    } else {
        sprite.setScale(0,0);
        if(son.getStatus() == sf::SoundSource::Stopped) {
            detruit = true;
        }
    }
}

void Explosion::reagirCollision(TypeElement typeAutre) {

}