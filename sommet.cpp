#include "sommet.h"
#include <iostream>

Sommet::Sommet()
{

}
Sommet::Sommet(Coords pos, bool sel) : m_position{pos}, m_selection{sel}
{

}
Sommet::~Sommet()
{

}
void Sommet::saisir()
{
    m_position.saisir();
    m_selection = false;
}
void Sommet::afficher() const
{
    m_position.afficher();
}
double Sommet::getX() const
{
    return m_position.getX();
}
double Sommet::getY() const
{
    return m_position.getY();
}
bool Sommet::getSel()   const
{
    return m_selection;
}
void Sommet::selectionner()
{
    m_selection = !m_selection;
}
void Sommet::translater(Coords translation)
{
    if (m_selection)
    {
        Coords pos(m_position.getX(), m_position.getY());
        m_position = pos + translation;
    }
}
/*
void Sommet::setPos(Coords position)
{
    m_position = position;
}
*/
Sommet operator+(const Sommet& a, const Sommet& b)
{
    return {a.m_position+b.m_position, a.m_selection};
}
