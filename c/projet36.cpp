/*

Suite a l'incomprehension du projet35 je le refais pas a pas 

1. Repars d’un mini-objectif (micro-victoire à chaque étape)

N’essaie jamais d’avoir tout d’un coup.
Avance étape par étape, en testant chaque partie isolément :
Mini-étapes possibles :

    Ouvre une fenêtre SFML.

    Affiche UN cercle (fixe, pas de mouvement).

    Gère le clic sur ce cercle → changer la couleur ou ajouter +1 au score.

    Ajoute le mouvement à ce cercle, rebond aux bords.

    Passe à DEUX cercles (un vector de cercles), puis 5.

    Gère le clic sur chacun (boucle sur le vector).

    Quand un cercle est cliqué, le remplacer par un nouveau.

    Ajoute score, chrono, reset.

    Finalise l’affichage du texte, du game over, etc.

*/

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


//etape 1 : ouvrire une fenetre
int main()
{
    RenderWindow window(VideoMode(1000,1000),"projet36 refaire projet35 pas a pas");

    while(window.isOpen())
    {
        Event event;

        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.display();
    }
    return 0;
}