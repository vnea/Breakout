#ifndef BALLE_H
#define BALLE_H

#include <string>
#include <SFML/Graphics.hpp>

#include "Barre.h"
#include "IntRecRB.h"

double const PI = 3.14159265358979323846;

class Barre;
class Balle
{
    public:
        Balle();
        ~Balle();

        void init(const std::string cheminFicher, float vitesse);
        void deplacerX(float delta);
        void deplacerY(float delta);
        void placerAuCentre(const Barre &barre, int largeurFen);
        void suivreBarre(const Barre &barre);

        void setDx(float dx) {_dx = dx;}
        void setDy(float dy) {_dy = dy;}
        float getDx() const {return _dx;}
        float getDy() const {return _dy;}

        bool getEstEnMouvement() const {return _estEnMouvement;}
        void setEstEnMouvement(bool enMvmt = true) { _estEnMouvement = enMvmt;}

        void angleAlea();

        sf::Sprite getSprite() const {return _sprite;}
        IntRecRB getBoundingBox() const;

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;

        float _vitesse;
        float _dx;
        float _dy;

        double _angle;

        bool _estEnMouvement;
};

#endif // BALLE_H
