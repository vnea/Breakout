#include <iostream>
#include <cstdlib>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <algorithm>

using namespace std;
using namespace sf;

#include "../include/Balle.h"

Balle::Balle()
    : _estEnMouvement(false)
{}

Balle::~Balle()
{}

void Balle::init(const std::string cheminFicher, float vitesse)
{
    if (!_texture.loadFromFile(cheminFicher))
    {
        cerr << "Balle::init : Erreur, fichier incorrect.\n";
        exit(1);
    }

    _sprite.setTexture(_texture);

    _vitesse = vitesse;
    _dx = 1;
    _dy = -1;
    _angle = 60.0; // entre 30 et 60
    _estEnMouvement = false;
}

 void Balle::deplacerX(float delta)
 {
     _sprite.move((_dx * _vitesse * delta * cos((_angle * PI) / 180.0)), 0);
 }

 void Balle::deplacerY(float delta)
 {
     _sprite.move(0, (_dy * _vitesse * delta * sin((_angle * PI) / 180.0)));
 }

void Balle::placerAuCentre(const Barre &barre, int largeurFen)
{
    int posX, posY;

    posX = (largeurFen - _sprite.getGlobalBounds().width) / 2;
    posY = barre.getSprite().getPosition().y - _sprite.getGlobalBounds().height;

    _sprite.setPosition(posX, posY);
}

IntRecRB Balle::getBoundingBox() const
{
    IntRecRB res;

    res.left = getSprite().getPosition().x;
    res.top = getSprite().getPosition().y;
    res.right = res.left + getSprite().getGlobalBounds().width;
    res.bottom = res.top + getSprite().getGlobalBounds().height;
    res.center = res.left + getSprite().getGlobalBounds().width * 0.5;
    return res;
}

void Balle::suivreBarre(const Barre &barre)
{
    _sprite.setPosition(barre.getSprite().getPosition().x + (barre.getSprite().getGlobalBounds().width - _sprite.getGlobalBounds().width) / 2.0, _sprite.getPosition().y);
}

void Balle::angleAlea()
{

}
