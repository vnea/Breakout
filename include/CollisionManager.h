#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Barre.h"
#include "Balle.h"
#include "Brique.h"
#include "IntRecRB.h"

class CollisionManager
{
    public :
        CollisionManager(Barre &barre, Balle &balle, std::vector<Brique*> &tabBriques);
        ~CollisionManager();

        void bloquerBarre(int largeurFen, float delta);
        void collisionBalleMur(int hauteurFen, int largeurFen);
        void collisionBalleBarre();
        bool collisionBalleBriqueX(float delta);
        bool collisionBalleBriqueY(float delta);

    private :
        Barre &_barre;
        Balle &_balle;
        std::vector<Brique*> &_tabBriques;

        bool _collisionBalleBrique(const IntRecRB &r1 , const IntRecRB &r2) const;
};

#endif // COLLISIONMANAGER_H
