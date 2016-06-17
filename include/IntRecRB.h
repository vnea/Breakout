#ifndef INTRECRB_H
#define INTRECRB_H

#include <SFML/Graphics.hpp>

class IntRecRB : public sf::IntRect
{
    public :
        IntRecRB();
        virtual ~IntRecRB();

        int right;
        int bottom;
        float center;
};

#endif // INTRECRB_H
