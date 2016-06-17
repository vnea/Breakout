#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#include "../include/Jeu.h"
#include "../global.h"

Jeu::Jeu(const std::string titreFen, int hauteurFen, int largeurFen)
    : _barre(), _balle(), _colMan(_barre, _balle, _tabBriques)
{
    _fenetre.create(sf::VideoMode(largeurFen, hauteurFen), titreFen);

    Brique::chargerTexture(CHEMIN_FICHIER_BRIQUE);

    for (unsigned int i = 0; i < 11; ++i)
    {
        _tabBriques.push_back(new Brique());

        _tabBriques[i]->setPosElem(0, 50 + 25 * i, 100);
        _tabBriques[i]->setPosElem(1, 50 + 25 * (i + 1), 100);
        _tabBriques[i]->setPosElem(2, 50 + 25 * (i + 1), 115);
        _tabBriques[i]->setPosElem(3, 50 + 25 * i, 115);


        _tabBriques[i]->setTexCoord(0, 0, 0);
        _tabBriques[i]->setTexCoord(1, 25, 0);
        _tabBriques[i]->setTexCoord(2, 25, 15);
        _tabBriques[i]->setTexCoord(3, 0, 15);
    }

    for (unsigned int i = 0; i < 11; ++i)
    {
        _tabBriques.push_back(new Brique());

        _tabBriques[i + 11]->setPosElem(0, 50 + 25 * i, 150);
        _tabBriques[i + 11]->setPosElem(1, 50 + 25 * (i + 1), 150);
        _tabBriques[i + 11]->setPosElem(2, 50 + 25 * (i + 1), 165);
        _tabBriques[i + 11]->setPosElem(3, 50 + 25 * i, 165);


        _tabBriques[i + 11]->setTexCoord(0, 0, 0);
        _tabBriques[i + 11]->setTexCoord(1, 25, 0);
        _tabBriques[i + 11]->setTexCoord(2, 25, 15);
        _tabBriques[i + 11]->setTexCoord(3, 0, 15);


    }
/*
    _tabBriques[0]->setCoul(Color::Blue);
    _tabBriques[1]->setCoul(Color::Red);
    _tabBriques[2]->setCoul(Color::Green);
    _tabBriques[3]->setCoul(Color::Yellow);
*/
    //_tabBriques.erase(_tabBriques.begin()+2);
}

Jeu::~Jeu()
{}

void Jeu::init()
{
    // Barre
    _barre.init(CHEMIN_FICHIER_BARRE, VITESSE_BARRE);
    _barre.placerAuCentre(HAUTEUR_FEN, LARGEUR_FEN);

    // Balle
    _balle.init(CHEMIN_FICHIER_BALLE, VITESSE_BALLE);
    _balle.placerAuCentre(_barre, LARGEUR_FEN);
}

void Jeu::run()
{
    sf::RenderStates s;
    float delta;
    Clock clock;
    init();

    while (_fenetre.isOpen())
    {

        Event event;
        while (_fenetre.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed :
                    _fenetre.close();
                break;

                case Event::KeyReleased :
                {
                    switch (event.key.code )
                    {
                        case Keyboard::Space :
                         _balle.setEstEnMouvement();
                        break;

                        default :
                        break;
                    }

                }

                default :
                break;
            }

        }

        delta = clock.restart().asSeconds();

        // Déplacement de la barre
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            _barre.deplacerVersGauche(delta);

            if (!_balle.getEstEnMouvement())
                _balle.suivreBarre(_barre);
        }

        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            _barre.deplacerVersDroite(delta);

            if (!_balle.getEstEnMouvement())
                _balle.suivreBarre(_barre);
        }

        _colMan.bloquerBarre(LARGEUR_FEN, delta);

        // Déplacement de la balle
        if (_balle.getEstEnMouvement())
        {
            _balle.deplacerX(delta);
            _colMan.collisionBalleBriqueX(delta);

            _balle.deplacerY(delta);
            _colMan.collisionBalleBriqueY(delta);

            _colMan.collisionBalleMur(HAUTEUR_FEN, LARGEUR_FEN);
            _colMan.collisionBalleBarre();
        }

        // Affichage des trucs...
        _fenetre.clear();
        _fenetre.draw(_barre.getSprite());
        _fenetre.draw(_balle.getSprite());

        for (unsigned int i = 0; i < _tabBriques.size(); ++i)
            _tabBriques[i]->draw(_fenetre, s);

        _fenetre.display();
    }
}
