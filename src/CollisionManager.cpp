#include <iostream>

using namespace std;

#include "../global.h"
#include "../include/CollisionManager.h"

CollisionManager::CollisionManager(Barre &barre, Balle &balle, vector<Brique*> &tabBriques)
    : _barre(barre), _balle(balle), _tabBriques(tabBriques)
{}

CollisionManager::~CollisionManager()
{}

 void CollisionManager::bloquerBarre(int largeurFen, float delta)
 {
     int posX = _barre.getSprite().getPosition().x;

     if (posX < 0)
        _barre.deplacerVersDroite(delta);
     else if (posX + _barre.getSprite().getGlobalBounds().width > largeurFen)
        _barre.deplacerVersGauche(delta);
 }

void CollisionManager::collisionBalleMur(int hauteurFen, int largeurFen)
{
    int posX, posY;

    posX = _balle.getSprite().getPosition().x;
    posY = _balle.getSprite().getPosition().y;

    if (posX <= 0)
        _balle.setDx(1);
    else if(posX + _balle.getSprite().getGlobalBounds().width >= largeurFen)
        _balle.setDx(-1);

    if (posY <=0)
        _balle.setDy(1);
    else if (posY + _balle.getSprite().getGlobalBounds().height >= hauteurFen)
    {
        cout << "Perdu" << endl;
        _balle.setEstEnMouvement(false);
        _barre.placerAuCentre(HAUTEUR_FEN, LARGEUR_FEN);
        _balle.placerAuCentre(_barre, LARGEUR_FEN);
    }

}

void CollisionManager::collisionBalleBarre()
{
    int posX;

    if (_balle.getSprite().getPosition().y + _balle.getSprite().getGlobalBounds().height > _barre.getSprite().getPosition().y)
    {
        posX = _balle.getSprite().getPosition().x;

        if ((_barre.getSprite().getPosition().x <= posX) && (posX + _balle.getSprite().getGlobalBounds().width <= _barre.getSprite().getPosition().x + _barre.getSprite().getGlobalBounds().width))
            _balle.setDy(-1);
    }
}

bool CollisionManager::_collisionBalleBrique(const IntRecRB &r1 , const IntRecRB &r2) const
{
    if (r1.bottom <= r2.top)
        return false;

    if (r1.top >= r2.bottom)
        return false;

    if (r1.right <= r2.left)
        return false;

    if (r1.left >= r2.right)
        return false;

    return true;
}

bool CollisionManager::collisionBalleBriqueX(float delta)
{
    IntRecRB r1, r2;

    for (int i = 0; i < (int)_tabBriques.size(); i++)
    {
        r1 = _balle.getBoundingBox();
        r2 = _tabBriques[i]->getBoudingBox();

        if (_collisionBalleBrique(r1, r2))
        {
            cout << delta;
            _tabBriques.erase(_tabBriques.begin() + i);
            _balle.setDx((-_balle.getDx()));
            _balle.deplacerX(delta);

            return true;
        }
    }

    return false;
}

bool CollisionManager::collisionBalleBriqueY(float delta)
{
    IntRecRB r1, r2;

    for (int i = 0; i < (int)_tabBriques.size(); i++)
    {
        r1 = _balle.getBoundingBox();
        r2 = _tabBriques[i]->getBoudingBox();

        if (_collisionBalleBrique(r1, r2))
        {
            _tabBriques.erase(_tabBriques.begin() + i);
            _balle.setDy((-_balle.getDy()));
            _balle.deplacerY(delta);

            return true;
        }
    }

    return false;
}
