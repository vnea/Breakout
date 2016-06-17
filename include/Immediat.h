#ifndef IMMEDIAT_H
#define IMMEDIAT_H

#include "Bonus.h"

class Immediat : public Bonus
{
    public:
        Immediat();
        virtual ~Immediat();
        virtual void utiliser()=0;
    protected:
    private:
};

#endif // IMMEDIAT_H
