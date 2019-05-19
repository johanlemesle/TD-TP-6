#include "svgfile.h"
#include "couleur.h"
#include "util.h"
#include "sommet.h"
#include "triangle.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void svgTest();
void AfficherMenu();
void menu();
void supprTous(std::vector<Sommet*>& vec1, std::vector<Triangle*>& vec2);
void ajouterSommet(std::vector<Sommet*>& vec);
void afficherSommets(std::vector<Sommet*>& vec);
void ajouterTriangle(const std::vector<Sommet*>& somm, std::vector<Triangle*>& tria);
void dessinerTriangles(const std::vector<Triangle*>& vec);
void selectionnerSommet(const std::vector<Sommet*>& vec);
void deselectionnerSommet(const std::vector<Sommet*>& vec);

int main()
{

    //svgTest();

    menu();

    return 0;
}
void translaterSommet(std::vector<Sommet*>& vec)
{
    Coords translation;
    std::cout << "Vecteur translation : ";
    translation.saisir();

    for(size_t i=0; i<vec.size(); ++i)
    {
        vec[i]->translater(translation);
        /*
        if (vec[i]->getSel())
        {
            Coords pos(vec[i]->getX(), vec[i]->getY());
            vec[i]->setPos(pos + translation);
        }
        */
    }
}
void deselectionnerSommet(const std::vector<Sommet*>& vec)
{
    int somm;
    do{
        std::cout << "Saisir indice du sommet a deselectionner :";
        std::cin >> somm;
    }while (somm < 0 || somm > (int)vec.size());

    if (vec[somm]->getSel() == true)
        vec[somm]->selectionner();
    else
        std::cout << "Deja deselectionne" << std::endl;
}
void selectionnerSommet(const std::vector<Sommet*>& vec)
{
    int somm;
    do{
        std::cout << "Saisir indice du sommet a selectionner :";
        std::cin >> somm;
    }while (somm < 0 || somm > (int)vec.size());

    if (vec[somm]->getSel() == false)
        vec[somm]->selectionner();
    else
        std::cout << "Deja selectionne" << std::endl;
}
void dessinerTriangles(const std::vector<Triangle*>& vec)
{
    Svgfile svgout;

    svgout.addGrid();

    for (size_t i=0; i<vec.size(); ++i)
    {
        vec[i]->dessiner(svgout);
    }
}
void ajouterTriangle(const std::vector<Sommet*>& somm, std::vector<Triangle*>& tria)
{
    Triangle *pt = nullptr;
    pt = new Triangle;
    pt->saisir(somm);

    tria.push_back(pt);
}
void afficherSommets(std::vector<Sommet*>& vec)
{
    std::cout << std::endl;
    //On affiche tout les sommets un par un ainsi que leur indice
    for (size_t i=0; i<vec.size(); ++i)
    {
        std::cout << i << ":";
        vec[i]->afficher();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void ajouterSommet(std::vector<Sommet*>& vec)
{
    Sommet *ps = nullptr;

    ps = new Sommet;

    ps->saisir();

    vec.push_back(ps);
}
void supprTous(std::vector<Sommet*>& vec1, std::vector<Triangle*>& vec2)
{
    for(size_t i=0; i<vec1.size(); ++i)
        delete vec1[i];

    for (size_t i=0; i<vec2.size(); ++i)
        delete vec2[i];
}
void AfficherMenu()
{
    std::cout << "0/ Quitter" << std::endl
              << "1/ Dessiner scene" << std::endl
              << "2/ Afficher tous sommets" << std::endl
              << "3/ Ajouter sommet" << std::endl
              << "4/ Ajouter triangle" << std::endl
              << "5/ Selectionner sommet" << std::endl
              << "6/ Deselectionner sommet" << std::endl
              << "7/ Translater sommet" << std::endl;
}
void menu()
{
    int choix;
    std::vector<Sommet*> mesSommets;
    std::vector<Triangle*> mesTriangles;

    ///util::startAutoCin("test2.txt", 50);
    AfficherMenu();
    do{
        std::cout << "Choix menu : ";
        std::cin >> choix;

        switch (choix)
        {
            case 0:
                ///Quitter
                supprTous(mesSommets, mesTriangles);
                break;
            case 1:
                ///Dessiner scene
                dessinerTriangles(mesTriangles);
                break;
            case 2:
                ///Afficher sommets
                afficherSommets(mesSommets);
                break;
            case 3:
                ///Ajouter sommet
                ajouterSommet(mesSommets);
                break;
            case 4:
                ///Ajouter triangle
                ajouterTriangle(mesSommets, mesTriangles);
                break;
            case 5:
                ///Selectionner sommet
                selectionnerSommet(mesSommets);
                break;
            case 6:
                ///Deselectionner sommet
                deselectionnerSommet(mesSommets);
                break;
            case 7:
                ///Translater sommet
                translaterSommet(mesSommets);
                break;
            default :
                std::cout << "Erreur, reessayez" << std::endl;
                break;
        }

    }while (choix!=0);

    ///util::stopAutoCin();
}
/// Code initial pour comprendre les ajouts de primitives
void svgTest()
{
    /// Sortie graphique dans le fichier output.svg
    /// ( options à voir svgfile.h au niveau du constructeur )
    Svgfile svgout;

    /// Dessin du repère cartésien (facultatif)
    // svgout.addGrid();

    /// On a perdu les dessins de sphères (une autre fois peut-être)

    /// Nouveau : on peut toujours utiliser les couleurs "red" "green"...
    /// Mais on a maintenant un type Couleur qui prend 3 composantes RVB
    /// Exemple pour déclarer du Jaune (beaucoup Rouge + Vert, pas de bleu)
    /// Chaque canal est dans l'intervalle [0..255]
    Couleur jaune{255, 200, 0};

    /// Dessin de disque : xcentre ycentre rayon couleur
    svgout.addDisk(100, 100, 30, jaune);
    svgout.addDisk(200, 100, 30, Couleur{100, 150, 200});
    svgout.addDisk(300, 100, 30, "pink");
    svgout.addDisk(400, 100, 30);

    /// Dessin de cercle : xcentre ycentre rayon epaisseur couleur
    svgout.addCircle(100, 200, 30, 10, "red");
    svgout.addCircle(200, 200, 30, 5, "red");
    svgout.addCircle(300, 200, 30, 1, "red");

    /// Dessin de triangle : x1 y1 x2 y2 x3 y3 couleur_remplissage ...
    ///                         epaisseur_bordure couleur_bordure
    svgout.addTriangle(100,300, 200,300, 150,250, "green", 0, "orange");

    /// Dessin de triangle : x1 y1 x2 y2 x3 y3 couleur_remplissage
    svgout.addTriangle(300,300, 400,300, 350,250, "green");

    /// Dessin de texte : xcentre ycentre texte couleur
    svgout.addText(100, 320, "Hello Triangles !", Couleur{0,100,0} );

    /// Dessin de texte : xcentre ycentre texte couleur
    svgout.addText(342, 320, 6*7, "black");

    /// Dessin de croix : xcentre ycentre taille couleur
    svgout.addCross(400, 200, 25);

    /// Dessin de segments : x1 y1 x2 y2 couleur
    svgout.addLine(300, 70, 400, 70);
    svgout.addLine(300, 130, 400, 130);
    svgout.addLine(340, 70, 300, 30, "blue");
    svgout.addLine(360, 70, 400, 30, "red");

    /// L'objet svgout est automatiquement libéré à la sortie
    /// de ce sous-programme : le fichier output.svg est alors fermé
}
