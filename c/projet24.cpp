#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    int rayon=100;
    int x=500;
    int y=500;
    const int DIMW=1000;
    float vitesse=1.0;
    int couleur=0;    

    RenderWindow window(VideoMode(DIMW,DIMW),"cercle change de couleur + bouge");

    CircleShape shape(rayon);

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

            if(event.type==Event::KeyPressed && event.key.code == Keyboard::C)
            {
                couleur+=1;
                if(couleur>2)
                {
                    couleur=0;
                }

                switch(couleur)
                {
                    case 0 : shape.setFillColor(Color::Red); break;
                    case 1 : shape.setFillColor(Color::Green); break;
                    case 2 : shape.setFillColor(Color::Blue); break;
                }

            }

            if(event.type==Event::KeyPressed && event.key.code==Keyboard::R)
            {
                x=500;
                y=500;
                shape.setPosition(x-rayon,y-rayon);
            }
            
        }

        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            x-=vitesse;
        }
         if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            x+=vitesse;
        }
         if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            y-=vitesse;
        }
         if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            y+=vitesse;
        }

        shape.setPosition(x-rayon , y-rayon);
        window.draw(shape);
        window.display();
    }


}