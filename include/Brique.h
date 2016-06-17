#ifndef BRIQUE_H
#define BRIQUE_H

#include <string>
#include <SFML/Graphics.hpp>

#include "IntRecRB.h"
#include "Bonus.h"

class Brique : public sf::Drawable, public sf::Transformable
{
    public:
        Brique();
        ~Brique();

        static void chargerTexture(const std::string &cheminFichier);

        void setPosElem(int indice, int posX, int posY);
        void setTexCoord(int indice, int posX, int posY);
        void setCoul(sf::Color c);
        sf::VertexArray getRec() const {return _rec;}
        IntRecRB getBoudingBox() const;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        static sf::Texture _texture;
        sf::VertexArray _rec;

        Bonus *_bonus;
};

#endif // BRIQUE_H
