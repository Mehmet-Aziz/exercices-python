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
#include <vector>
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

    vector <Cercle> c;
    for(int i=0;i<5;i++)
    {
        c.push_back(ajoute_cercle());
    }

    int score = 0;

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
                for(int i=0;i<c.size();i++)
                {
                int sourisX=event.mouseButton.x , sourisY=event.mouseButton.y;
                float dist=sqrt(pow(sourisX-c[i].x,2)+pow(sourisY-c[i].y,2));
                if(dist<c[i].rayon)
                {
                    //etape 3 : score ++
                    score+=1;
                    c[i]=ajoute_cercle();
                }
                }

            }
        }

        //etape 4 : mouvement et rebond


        //etape 5 : vector de cercle
        for(int i=0;i<c.size();i+=1)
        {
        c[i].x+=c[i].vx;
        c[i].y+=c[i].vy;
        if(c[i].x-c[i].rayon<0 || c[i].x+c[i].rayon>1000)
        {
            c[i].vx=-c[i].vx;
        }
         if(c[i].y-c[i].rayon<0 || c[i].y+c[i].rayon>1000)
        {
            c[i].vy=-c[i].vy;
        }
        CircleShape shape(c[i].rayon);
        shape.setPosition(c[i].x-c[i].rayon,c[i].y-c[i].rayon);
        shape.setFillColor(Color::Blue);
        window.draw(shape);
        shape.setPosition(c[i].x-c[i].rayon,c[i].y-c[i].rayon);
        shape.setRadius(c[i].rayon);
        }

        textscore.setString("score : " + to_string(int(score)));
        window.draw(textscore);
        window.display();
    }
    return 0;
}