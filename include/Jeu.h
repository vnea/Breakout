#ifndef JEU_H
#define JEU_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "Barre.h"
#include "Balle.h"
#include "Brique.h"
#include "CollisionManager.h"

class Jeu
{
    public:
        Jeu(const std::string titreFen, int hauteurFen, int largeurFen);
        ~Jeu();

        void init();
        void run();

    private:
        sf::RenderWindow _fenetre;

        Barre _barre;
        Balle _balle;
        std::vector<Brique*> _tabBriques;
        CollisionManager _colMan;
};

#endif // JEU_H
