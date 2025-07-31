#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;
using namespace sf;


struct Oiseau
{
    float r;
    float x;
    float y;
    float vy;
};


void init_Oiseau(Oiseau &o)
{
    o.r=10;
    o.x=10;
    o.y=500;
    o.vy=0.005;
}

struct Tuyeau1
{
    float x , y , l , h , vx;
};

struct Tuyeau2
{
    float x , y , l , h , vx;
};


void init_Tuyeau1 (Tuyeau1 &t)
{
    t.x= 500;
    t.y=0;
    t.l=50;
    t.h=10+rand()%600;
    t.vx=-0.005; 
}

void init_Tuyeau2(Tuyeau2 &t2 , Tuyeau1 t1)
{
    t2.x=t1.x;
    t2.y=200+t1.h;
    t2.l=50;
    t2.h=1000-t2.y;
    t2.vx=-0.005; 

}

int main()
{
    srand(time(NULL));
    
    Oiseau o;
    init_Oiseau(o);
    vector<Tuyeau1> t1;
    vector<Tuyeau2> t2;
    
    for(int i=0;i<9;i+=1)
    {
    Tuyeau1 t11;
    Tuyeau2 t22;
    init_Tuyeau1(t11);
    t11.x = 500 + i * 150;
    init_Tuyeau2(t22,t11);
    t1.push_back(t11);
    t2.push_back(t22);
    }

    RenderWindow window(VideoMode(1000,1000),"flappy");

    CircleShape flappy(o.r);
    flappy.setFillColor(Color::Red);


   


    while(window.isOpen())
    {
        window.clear();
        Event event;

        while (window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }




            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up) 
            {
                o.vy = -0.0075;
            }
         

        }



       

        o.vy+=0.0000005;
        o.y+=o.vy;
       
        if(o.y +o.r<=0)
        {
            o.y=500;

        }
         if(o.y +o.r>=1000)
        {
            o.y=1000;
        }

        for(int i=0;i<t1.size();i+=1)
        {
        t1[i].x+=t1[i].vx;
        t2[i].x+=t2[i].vx;
        RectangleShape tuyeau1(Vector2f(t1[i].l,t1[i].h));
        tuyeau1.setFillColor(Color::Green);
        RectangleShape tuyeau2(Vector2f(t2[i].l,t2[i].h));
        tuyeau2.setFillColor(Color::Green);

            if(t1[i].x<0 && t2[i].x<0)
            {
                init_Tuyeau1(t1[i]);
                init_Tuyeau2(t2[i],t1[i]);
            }

        tuyeau1.setPosition(t1[i].x,t1[i].y);
        window.draw(tuyeau1);
        tuyeau2.setPosition(t2[i].x,t2[i].y);
        window.draw(tuyeau2);
        }
        flappy.setPosition(o.x-o.r,o.y-o.r);
        window.draw(flappy);

        window.display();
        
    }



    return 0;
}