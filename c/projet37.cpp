#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <time.h>
#include <vector>

using namespace std;
using namespace sf;


/*

Suite a l'incomprehension du projet37 je le refais pas a pas 

1. Repars d’un mini-objectif (micro-victoire à chaque étape)

N’essaie jamais d’avoir tout d’un coup.
Avance étape par étape, en testant chaque partie isolément :
Mini-étapes possibles :

    Ouvre une fenêtre SFML.

    Affiche UN rectangle (fixe, pas de mouvement).

    Gère le clic sur ce cercle → changer la couleur ou ajouter +1 au score.

    Ajoute le mouvement à ce cercle, rebond aux bords.

    Passe à DEUX cercles (un vector de cercles), puis 5.

    Gère le clic sur chacun (boucle sur le vector).

    Quand un cercle est cliqué, le remplacer par un nouveau.

    Ajoute score, chrono, reset.

    Finalise l’affichage du texte, du game over, etc.

*/

struct Rectangle
{
    float x , y;
    float longeur , hauteur;
    float vx , vy;
};

Rectangle ajoute()
{
    Rectangle r;
    r.x=rand()% 1000;
    r.y=rand()% 1000;
    r.longeur=100;
    r.hauteur=100;
    r.vx=0.0075;
    r.vy=0.0075;
    return r;
}


int main()
{
    srand(time(NULL));
    vector <Rectangle> r;
    for(int i=0;i<5;i+=1)
    {
        r.push_back(ajoute());
    }
    RenderWindow window(VideoMode(1000,1000),"projet37 du debut");

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"erreur"<<endl;
        return 1;
    }

    Text affichage;
    affichage.setFont(font);
    affichage.setCharacterSize(20);
    affichage.setFillColor(Color::Red);
    affichage.setPosition(10,900);

    Text txtscore;
    txtscore.setFont(font);
    txtscore.setCharacterSize(20);
    txtscore.setFillColor(Color::Red);
    txtscore.setPosition(890 , 10);
    
    Text perdu;
    perdu.setFont(font);
    perdu.setCharacterSize(20);
    perdu.setFillColor(Color::Red);
    perdu.setPosition(435 , 430);


    int score=0;
    int highscore=0;
    sf::Clock chrono;
    bool fin=false;

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
            if(event.type==Event::MouseButtonPressed && event.mouseButton.button)
            {
                for(int i=0;i<r.size();i+=1)
                {
                float sourisX=event.mouseButton.x;
                float sourisY=event.mouseButton.y;
                if(sourisX>=r[i].x - r[i].longeur/2 && sourisX<=r[i].x+r[i].longeur/2 && sourisY>=r[i].y - r[i].hauteur/2 && sourisY<=r[i].y + r[i].hauteur/2)
                {
                    score++;
                    r[i]=ajoute();
                }
                }
            }

        }

        float temps=chrono.getElapsedTime().asSeconds();

        if(fin==false && temps>30)
        {
            fin=true;
            if(score>highscore)
            {
                highscore=score;
            }
        }


        if(fin==false)
        {
        for(int i=0;i<r.size();i+=1)
        {
        r[i].x+=r[i].vx;
        r[i].y+=r[i].vy;

        if(r[i].x - r[i].longeur/2<0 || r[i].x + r[i].longeur/2>1000 ||r[i].y - r[i].hauteur/2<0 || r[i].y + r[i].hauteur/2>1000)
        {
            r[i].vx=-r[i].vx;
            r[i].vy=-r[i].vy;

        }

        RectangleShape shape(Vector2f(100,100));
        shape.setFillColor(Color::Red);
        shape.setPosition(r[i].x - r[i].longeur/2,r[i].y - r[i].hauteur/2);
        window.draw(shape);
        } 

        affichage.setString("score : " + to_string(int(score)));
        txtscore.setString("temps : " + to_string(int(30-temps)) );
        }


         if(fin==true)
        {
            window.clear();
            perdu.setString("GAME OVER \n score : " + to_string(int(score)) + "\n highscore : " + to_string(int(highscore)));
            window.draw(perdu);

            if(Keyboard::isKeyPressed(Keyboard::R))
            {
                chrono.restart();
                fin=false;
                r.clear();
                score=0;
                for(int i=0;i<5;i++)
                {
                    r.push_back(ajoute());
                }
            }

        }

        window.draw(txtscore);
        window.draw(affichage);
        window.display();
    }
    
    return 0;
}
