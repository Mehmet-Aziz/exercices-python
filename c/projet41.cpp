#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;
using namespace sf;

struct Balle
{
    float r;
    float x , y;
    float vx , vy;
};

Balle ajoute_balle()
{
    Balle b;
    b.r=10;
    b.x=490;
    b.y=490;
    float a=1+rand()% 100;
    b.vx=a/10000 * (rand()%2 ==0 ? 1 : -1);
    float c=1+rand()% 100;
    b.vy= c / 10000 * (rand()%2 ==0 ? 1 : -1);
    return b;
}

int main()
{
    srand(time(NULL));
    Balle b=ajoute_balle();
    bool etat=false; //false = menu et true=sur le jeu

    RenderWindow window(VideoMode(1000,1000),"pong");


        float rect1X=0 , rect1Y=500;
        float rect1L=10 , rect1H=100;

        RectangleShape rect1 (Vector2f(rect1L,rect1H));
        rect1.setFillColor(Color::Red);


        float rect2X=990 , rect2Y=500;
        float rect2L=10 , rect2H=100;

        RectangleShape rect2 (Vector2f(rect2L,rect2H));
        rect2.setFillColor(Color::Red);
        

        CircleShape rond(b.r);
        rond.setFillColor(Color::Blue);



    while(window.isOpen())
    {
        window.clear();
        Event event;


        b.x+=b.vx;
        b.y+=b.vy;
        float d1=sqrt(pow(b.x-rect1X,2)+pow(b.y-rect1Y,2));
        float d2=sqrt(pow(b.x-rect2X,2)+pow(b.y-rect2Y,2));
        if(b.y<0 || b.y>1000 || d1<b.r || d2<b.r)
        {
            b.vy=-b.vy;
        }
        


        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }

        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            rect1Y-=10;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            rect1Y+=10;
        }
        if (Keyboard::isKeyPressed(Keyboard::Z))
        {
            rect2Y-=10;
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            rect2Y+=10;
        }





        }











        rect1.setPosition(rect1X,rect1Y);
        rect2.setPosition(rect2X,rect2Y);
        rond.setPosition(b.x,b.y);
        window.draw(rect1);
        window.draw(rect2);
        window.draw(rond);


        window.display();
    }



    return 0;
}