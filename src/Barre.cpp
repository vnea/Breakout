#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "../include/Barre.h"

using namespace std;
using namespace sf;

Barre::Barre()
{}

Barre::~Barre()
{}

void Barre::init(const std::string &cheminFichier, float vitesse)
{
    if (!_texture.loadFromFile(cheminFichier))
    {
        cerr << "Barre::init : Erreur, chemin fichier inccorect.\n";
        exit(1);
    }

    _sprite.setTexture(_texture);
    _vitesse = vitesse;
}


void Barre::deplacerVersGauche(float delta)
{
    _sprite.move((-_vitesse * delta), 0);
}

void Barre::deplacerVersDroite(float delta)
{
    _sprite.move((_vitesse * delta), 0);
}

void Barre::placerAuCentre(int hauteurFen, int largeurFen)
{
    int posX, posY;

    posX = (largeurFen - _sprite.getGlobalBounds().width) / 2;
    posY = hauteurFen - _sprite.getGlobalBounds().height;

    _sprite.setPosition(posX, posY);
}
