#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#include "../include/Brique.h"

Texture Brique::_texture;

Brique::Brique()
    : _rec(Quads, 4)
{}

Brique::~Brique()
{}

void Brique::setPosElem(int indice, int posX, int posY)
{
    if (indice < 0 || indice > (int)_rec.getVertexCount())
    {
        cerr << "Brique::setPosElem : Erreur, indice incorrect.\n";
        exit(1);
    }

    _rec[indice].position = Vector2f(posX, posY);
}

void Brique::setTexCoord(int indice, int posX, int posY)
{
    if (indice < 0 || indice > (int)_rec.getVertexCount())
    {
        cerr << "Brique::setTexCoord : Erreur, indice incorrect.\n";
        exit(1);
    }

    _rec[indice].texCoords = Vector2f(posX, posY);
}

 void Brique::chargerTexture(const std::string &cheminFichier)
 {
     if (!_texture.loadFromFile(cheminFichier))
     {
        cerr << "Brique::chargerTexture : Erreur, fichier introuvable.\n";
        exit(1);
     }
 }

void Brique::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // on applique la transformation
    states.transform *= getTransform();

    // on applique la texture du tileset
    states.texture = &_texture;

    // et on dessine enfin le tableau de vertex
    target.draw(_rec, states);
}

void Brique::setCoul(Color c)
{
    for (int i = 0; i < (int)_rec.getVertexCount(); i++)
        _rec[i].color = c;
}

IntRecRB Brique::getBoudingBox() const
{
    IntRecRB res;

    res.left = _rec[0].position.x;
    res.top = _rec[0].position.y;
    res.right = res.left + 25;
    res.bottom = res.top + 15;
    res.center = res.left + 25 * 0.5;

    return res;
}
