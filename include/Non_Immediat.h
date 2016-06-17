#ifndef NON_IMMEDIAT_H
#define NON_IMMEDIAT_H

#include "Bonus.h"

class Non_Immediat : public Bonus
{
    public:
        Non_Immediat();
        virtual ~Non_Immediat();
        virtual void utiliser()=0;
    protected:
    private:
};

#endif // NON_IMMEDIAT_H
