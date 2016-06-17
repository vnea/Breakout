#ifndef MISSILE_H
#define MISSILE_H

#include "Non_Immediat.h"

class Missile : public Non_Immediat
{
    public:
        Missile();
        virtual ~Missile();
        virtual void utiliser();
    protected:
    private:
};

#endif // MISSILE_H
