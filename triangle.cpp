#include "triangle.h"
#include <iostream>

Triangle::Triangle()
{

}
Triangle::~Triangle()
{

}
void Triangle::afficher()   const
{
    for (int i=0; i<3; ++i)
        m_sommmet[i]->afficher();
    m_couleur.afficher();
}
void Triangle::saisir(const std::vector<Sommet*>& vec)
{
    int a,b,c;
    std::cout << "Saisir 3 indices sommets";
    std::cin >> a >> b >> c;

    m_sommmet[0] = vec[a];
    m_sommmet[1] = vec[b];
    m_sommmet[2] = vec[c];

    m_couleur.saisir();
}
void Triangle::dessiner(Svgfile& svgout)    const
{
    double x,y;

    svgout.addTriangle(m_sommmet[0]->getX(), m_sommmet[0]->getY(), m_sommmet[1]->getX(), m_sommmet[1]->getY(), m_sommmet[2]->getX(), m_sommmet[2]->getY(), m_couleur, 2, "black");

    for(int i=0; i<3; ++i)
    {
        x = m_sommmet[i]->getX();
        y = m_sommmet[i]->getY();
        svgout.addDisk(x, y, 5, "black");

        if (m_sommmet[i]->getSel())
            svgout.addCircle(x, y, 10, 3, "black");
    }
}
