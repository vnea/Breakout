#include "../include/IntRecRB.h"

IntRecRB::IntRecRB()
    : right(left + width), bottom(top + height), center(left + width * 0.5)
{}

IntRecRB::~IntRecRB()
{
    //dtor
}
