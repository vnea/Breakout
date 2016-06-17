#ifndef BARRE_H
#define BARRE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Balle.h"
#include "Bonus.h"

enum Direction
{
    GAUCHE,
    DROITE
};

class Balle;
class Barre
{
    public:
        Barre();
        ~Barre();

        void init(const std::string &cheminFichier, float vitesse);

        void deplacerVersGauche(float delta);
        void deplacerVersDroite(float delta);
        void lancerMissiles() const;
        void placerAuCentre(int hauteurFen, int largeurFen);

        sf::Sprite getSprite() const {return _sprite;}

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;

        float _vitesse;

        std::vector<Bonus*> _tabBonus;
};

#endif // BARRE_H
