#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <time.h>
#include <vector>

using namespace std;
using namespace sf;

/*

Pseudocode étape 1 — Démarrage du jeu Snake

1. Ouvre une fenêtre SFML 600x600 (ou 800x800)
2. Crée une variable “serpent” : une liste (vector) de positions (x, y)
   - Au début, un seul carré au centre
3. À chaque frame : 
   - Déplace le serpent dans la direction actuelle (au début : droite)
   - Affiche chaque case du serpent avec un RectangleShape
4. Gère la fermeture de la fenêtre

*/

struct Serpent
{
    float x ;
    float y;
};

Serpent ajoute()
{
    Serpent s;
    s.x=500;
    s.y=500;
    return s;
}


int main()
{

    RenderWindow window(VideoMode(1000,1000),"SNAKE");

    Serpent s;
    s=ajoute();

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
            if (event.type==Event::KeyPressed && event.key.code==Keyboard::Right) 
            {
                s.x+=1;
            }
            if (event.type==Event::KeyPressed && event.key.code==Keyboard::Left) 
            {
                s.x-=1;
            }
            if (event.type==Event::KeyPressed && event.key.code==Keyboard::Down) 
            {
                s.y+=1;
            }
            if (event.type==Event::KeyPressed && event.key.code==Keyboard::Up) 
            {
                s.y-=1;
            }
            
        }

        RectangleShape shape(Vector2f(20,20));
        shape.setPosition(s.x-5,s.y-5);
        shape.setFillColor(Color::Green);

        window.draw(shape);
        window.display();
    }

    return 0;
}
