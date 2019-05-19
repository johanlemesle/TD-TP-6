#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "couleur.h"
#include "sommet.h"
#include "svgfile.h"
#include <vector>

class Triangle
{
    private :
        Sommet* m_sommmet[3];
        Couleur m_couleur;
        double m_epaisseurBordure;

    public :
        Triangle();
        ~Triangle();

        void saisir(const std::vector<Sommet*>& vec);
        void dessiner(Svgfile& svgout) const;
        void afficher() const;
};

#endif // TRIANGLE_H_INCLUDED
