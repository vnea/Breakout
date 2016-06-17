#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#include "include/Jeu.h"
#include "global.h"

int main()
{
    srand(time(NULL));

    Jeu j(TITRE_JEU, HAUTEUR_FEN, LARGEUR_FEN);

    j.run();

    return EXIT_SUCCESS;
}
