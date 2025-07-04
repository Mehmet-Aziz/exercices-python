#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{

    int rayon=40;
    int x=100;
    int y=100;
    float vitesse=1.0;

    const int DIMW=1000;

    RenderWindow window(VideoMode(DIMW,DIMW),"bouger le cercle");

    while(window.isOpen())
    {
        window.clear();
        Event event;

         CircleShape shape(rayon);
        shape.setFillColor(Color::Red);

        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }
        }

        shape.setPosition(x,y);

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
        window.draw(shape);
        window.display();

    }
    return 0;
}