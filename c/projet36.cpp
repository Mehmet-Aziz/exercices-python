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
#include <math.h>
#include <time.h>

using namespace std;
using namespace sf;

//etape 2 : affichage d'un cercle
struct Cercle
{
    int rayon;
    float x;
    float y;
    float vx;
    float vy;
};

Cercle ajoute_cercle()
{
    Cercle c;
    c.rayon=30 + rand()% 70;
    c.x=c.rayon + rand()% 800;
    c.y=c.rayon + rand()% 800;
    c.vx=0.30;
    c.vy=0.20;
    return c;
}


//etape 1 : ouvrire une fenetre
int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(1000,1000),"projet36 refaire projet35 pas a pas");

    Cercle c=ajoute_cercle();
    int score = 0;
    CircleShape shape(c.rayon);
    shape.setPosition(c.x-c.rayon,c.y-c.rayon);
    shape.setFillColor(Color::Blue);

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"erreur"<<endl;
        return 1;
    }

    Text textscore;
    textscore.setFont(font);
    textscore.setFillColor(Color::Red);
    textscore.setPosition(10,900);
    while(window.isOpen())
    {
        window.clear();
        Event event;

        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }
            if(event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                int sourisX=event.mouseButton.x , sourisY=event.mouseButton.y;
                float dist=sqrt(pow(sourisX-c.x,2)+pow(sourisY-c.y,2));
                if(dist<c.rayon)
                {
                    //etape 3 : score ++
                    score+=1;
                    c=ajoute_cercle();
                }

            }
        }

        //etape 4 : mouvement et rebond

        c.x+=c.vx;
        c.y+=c.vy;
        if(c.x-c.rayon<0 || c.x+c.rayon>1000)
        {
            c.vx=-c.vx;
        }
         if(c.y-c.rayon<0 || c.y+c.rayon>1000)
        {
            c.vy=-c.vy;
        }

        textscore.setString("score : " + to_string(int(score)));
        shape.setPosition(c.x-c.rayon,c.y-c.rayon);
        shape.setRadius(c.rayon);
        window.draw(shape);
        window.draw(textscore);
        window.display();
    }
    return 0;
}