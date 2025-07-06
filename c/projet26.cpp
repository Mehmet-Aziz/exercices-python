#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    srand(time(NULL));
    int rayon1=30;
    int rayon2=30;
    int x1 =rayon1 + rand()%(1000-2*rayon1);
    int x2 =rayon2 + rand()%(1000-2*rayon2);
    int y1 =rayon1 + rand()%(1000-2*rayon1);
    int y2 =rayon2 + rand()%(1000-2*rayon2);


    CircleShape cercle1(rayon1);
    cercle1.setFillColor(Color::White);
    cercle1.setPosition(x1,y1);
    CircleShape cercle2(rayon2);
    cercle2.setFillColor(Color::White);
    cercle2.setPosition(x2,y2);
    


    RenderWindow window(VideoMode(1000,1000),"melange");

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

            if(event.type==Event::KeyPressed && event.key.code==Keyboard::Escape)
            {
                Color couleur(rand()% 256,rand()% 256,rand()% 256);
                cercle1.setFillColor(couleur);
                cercle2.setFillColor(couleur);
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            y1-=1;
            y2-=1;
        }
         if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            y1+=1;
            y2+=1;
        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            x1-=1;
            x2-=1;
        }
         if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            x1+=1;
            x2+=1;
        }

        if(Keyboard::isKeyPressed(Keyboard::R))
        {
            x1=500-30;
            y1=x1;
            x2=x1;
            y2=x1;
        }

        cercle1.setPosition(x1,y1);
        cercle2.setPosition(x2,y2);

        window.draw(cercle1);
        window.draw(cercle2);
        window.display();


    }   
    return 0;

}