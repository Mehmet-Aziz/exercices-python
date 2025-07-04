#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    int x1=500;
    int x2=500;
    int y1=200;
    int y2=700;
    int rayon1=50;
    float v1=1.0;
    int rayon2=50;
    float v2=1.0;
    const int DIMW=1000;

    RenderWindow window(VideoMode(DIMW,DIMW),"plusieurs choses");

    CircleShape shape1(rayon1);
    shape1.setFillColor(Color::Green);
    CircleShape shape2(rayon2);
    shape2.setFillColor(Color::Blue);

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

            if(event.type==Event::KeyPressed && event.key.code==Keyboard::J)
            {
                rayon1+=1.0;
                shape1.setRadius(rayon1);
            }
             if(event.type==Event::KeyPressed && event.key.code==Keyboard::K)
            {
                rayon1-=1.0;
                shape1.setRadius(rayon1);
            }
            if(event.type==Event::KeyPressed && event.key.code==Keyboard::L)
            {
                v1+=1.0;
            }
            if(event.type==Event::KeyPressed && event.key.code==Keyboard::M)
            {
                v1-=0.5;
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            x1+=v1;
        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            x1-=v1;
        }
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            y1-=v1;
        }
        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            y1+=v1;
        }

         if(Keyboard::isKeyPressed(Keyboard::D))
        {
            x2+=v2;
        }
        if(Keyboard::isKeyPressed(Keyboard::Q))
        {
            x2-=v2;
        }
        if(Keyboard::isKeyPressed(Keyboard::Z))
        {
            y2-=v2;
        }
        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            y2+=v2;
        }

        if (x1>DIMW-rayon1)
        {
            x1=DIMW-rayon1;
        }
         if (x1<0+rayon1)
        {
            x1=0+rayon1;
        }
        if (y1>DIMW-rayon1)
        {
            y1=DIMW-rayon1;
        }
         if (y1<0+rayon1)
        {
            y1=0+rayon1;
        }
        if (x2>DIMW-rayon2)
        {
            x2=DIMW-rayon2;
        }
         if (x2<0+rayon2)
        {
            x2=0+rayon2;
        }
        if (y2>DIMW-rayon2)
        {
            y2=DIMW-rayon2;
        }
         if (y2<0+rayon2)
        {
            y2=0+rayon2;
        }


        shape1.setPosition(x1-rayon1,y1-rayon1);
        shape2.setPosition(x2-rayon2,y2-rayon2);

        window.draw(shape1);
        window.draw(shape2);
        window.display();

    }



    return 0;

}