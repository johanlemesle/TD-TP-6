#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include "coords.h"
#include <vector>

class Sommet
{
    private :
        Coords m_position;
        bool m_selection;

    public :
        Sommet();
        Sommet(Coords pos, bool sel = false);
        ~Sommet();

        void saisir();
        void afficher() const;
        void selectionner();

        double getX() const;
        double getY() const;
        bool getSel() const;

        //void translaterSommet(std::vector<Sommet*>& vec)
        void translater(Coords translation);

        //void setPos(Coords position);

        friend Sommet operator+(const Sommet& a, const Sommet& b);

};

#endif // SOMMET_H_INCLUDED
