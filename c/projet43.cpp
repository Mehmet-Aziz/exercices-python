#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;
using namespace sf;

struct Rectangle
{
    float x ,y , l , h , vx , vy;
};

void ajoute_rectangle(vector <Rectangle> &r)
{
    Rectangle re;
    re.h= 100;
    re.l=100; 
    re.x= re.l/2 +rand()% (1000- int(re.l)); 
    re.y= re.y/2 + rand()% (1000- int(re.y));
    float a=1+rand()% 100;
    re.vx=a/10000 * (rand()%2 ==0 ? 1 :-1);
    float b=1+rand()% 100;
    re.vy=b/10000 * (rand()%2 ==0 ? 1 :-1);
    r.push_back(re);
}

Rectangle nouveau_rectagle()
{
    Rectangle re;
    re.h= 100;
    re.l=100; 
    re.x= re.l/2 +rand()% (1000- int(re.l)); 
    re.y= re.y/2 + rand()% (1000- int(re.y));
    float a=1+rand()% 100;
    re.vx=a/10000 * (rand()%2 ==0 ? 1 :-1);
    float b=1+rand()% 100;
    re.vy=b/10000 ;
    return re;
}


 

int main()
{
    srand(time(NULL));
    vector <Rectangle> r;
    for(int i=0;i<5;i+=1)
    {
    ajoute_rectangle(r);
    }
    RenderWindow window(VideoMode(1000,1000),"dodge les rectangles");

    float joueurX =500 , joueurY=1000 , joueurL=50 , joueurH=50;
    RectangleShape joueur (Vector2f(joueurL,joueurH));
    joueur.setFillColor(Color::Red);

    bool fin=false ; //false en cours de jeu , true = game over 






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

            if(Keyboard::isKeyPressed(Keyboard::Up))
            {
                joueurY-=10;
            }
            if(Keyboard::isKeyPressed(Keyboard::Down))
            {
                joueurY+=10;
            }
            if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                joueurX-=10;
            }
            if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                joueurX+=10;
            }



        }


        if(fin==false)
        {

            for(int i=0;i<r.size();i+=1)
            {
                if(r[i].y + r[i].h/2>=990)
                {
                  r[i]=nouveau_rectagle();
                }
            }

        for(int i=0;i<r.size();i+=1)
        {
            RectangleShape rect(Vector2f(r[i].l,r[i].h));
            rect.setFillColor(Color::Green);

            r[i].x+=r[i].vx;
            r[i].y+=r[i].vy;

            if(r[i].x - r[i].l/2<0 || r[i].x + r[i].l/2>1000)
            {
                r[i].vx=-r[i].vx;
            }
            if(r[i].y - r[i].h/2<0 || r[i].y + r[i].h/2>1000)
            {
                r[i].vy=-r[i].vy;
            }

            rect.setPosition(r[i].x-r[i].l/2,r[i].y-r[i].h/2);
            window.draw(rect);
        }

        joueur.setPosition(joueurX-joueurL,joueurY-joueurH);
        window.draw(joueur);
        }

        window.display();
    }
}