//plusieurs cercle à attraper

#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;
using namespace sf;


struct Cercle
{
    int rayon;
    int x;
    int y;
    float vx;
    float vy;
};

void ajoute_cercle(vector <Cercle> &ce)
{
    for(int i=0;i<5;i+=1)
    {
    Cercle c;
    c.rayon=30+rand()% 60;
    c.x=c.rayon +rand()% 800;
    c.y=c.rayon +rand()% 800;
    c.vx=0.005;
    c.vy=0.0075;
    ce.push_back(c);
    }
}

int main()
{
    srand(time(NULL));
    vector <Cercle> c;
    ajoute_cercle(c);

    bool fin=false;
    int score=0;
    int highscore=0;
    sf::Clock chrono;

    RenderWindow window(VideoMode(1000,1000),"plusieurs cercles en mouvements");

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

            if(fin==false && event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                int sourisX=event.mouseButton.x;
                int sourisY=event.mouseButton.y;
                for(int i=0;i<c.size();i++)
                {
                    float dist=sqrt(pow(sourisX-c[i].x,2)+pow(sourisY-c[i].y,2));
                    if(dist<c[i].rayon)
                    {
                        score+=1;
                        c.erase(c.begin()+i);

                        Cercle cer;
                        cer.rayon=30+rand()% 60;
                        cer.x=cer.rayon +rand()% 800;
                        cer.y=cer.rayon +rand()% 800;
                        cer.vx=0.005;
                        cer.vy=0.0075;
                        c.push_back(cer);

                        break;
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
            
        for(int i=0;i<c.size();i++)
        {
            CircleShape shape(c[i].rayon);
            shape.setFillColor(Color::Blue);
            shape.setPosition(c[i].x-c[i].rayon,c[i].y-c[i].rayon);
            window.draw(shape);
        }
         
        }

       
        window.display();
          
    }



    return 0;
}