#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <math.h>

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

Cercle ajoute()
{
    Cercle c;
    c.rayon=30+rand()% 60;
    c.x=c.rayon + rand()% 800;
    c.y=c.rayon + rand()% 800;
    c.vx=0.05;
    c.vy=0.075;
    return c;
}

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(1000,1000),"projet by gpt");

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"erreur"<<endl;
        return 1;
    }

    Text affichage , tempss , perdu;
    affichage.setFont(font);
    affichage.setCharacterSize(20);
    affichage.setFillColor(Color::Red);
    affichage.setPosition(10 , 900);

    tempss.setFont(font);
    tempss.setCharacterSize(20);
    tempss.setFillColor(Color::Red);
    tempss.setPosition(890 , 10);

    perdu.setFont(font);
    perdu.setCharacterSize(20);
    perdu.setFillColor(Color::Red);
    perdu.setPosition(890 , 10);

    vector <Cercle> c;
    int score =0;
    int highscore=0;
    bool fin=false;
    sf::Clock chrono;

    for(int i=0;i<5;i+=1)
    {
        c.push_back(ajoute());
    }

    while(window.isOpen())
    {
        Event event;

        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }

            if(event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                int sourisX=event.mouseButton.x , sourisY=event.mouseButton.y;
                for(int i=0;i<c.size();i++)
                {
                    float dist=sqrt(pow(sourisX-c[i].x,2)+pow(sourisY-c[i].y,2));
                    if(dist<c[i].rayon)
                    {
                        score+=1;
                        c[i]=ajoute();
                        
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

        window.clear();
        
        if(fin==false)
        {
            for(int i=0;i<c.size();i+=1)
            {
                c[i].x+=c[i].vx;
                c[i].y+=c[i].vy;

                if(c[i].x-c[i].rayon<0 || c[i].x + c[i].rayon>1000)
                {
                    c[i].vx=-c[i].vx;
                }
                 if(c[i].y-c[i].rayon<0 || c[i].y + c[i].rayon>1000)
                {
                    c[i].vy=-c[i].vy;
                }

                CircleShape shape(c[i].rayon);
                shape.setFillColor(Color::Blue);
                shape.setPosition(c[i].x-c[i].rayon,c[i].y-c[i].rayon);
                window.draw(shape);
            }
            affichage.setString("score : " + to_string(int(score)));
            tempss.setString("temps : " + to_string(int(30-temps)));
            window.draw(affichage);
            window.draw(tempss);

        }

        if(fin==true)
        {
            perdu.setString("game over \nscore" + to_string(int(score)) + "  \nhighscore  " + to_string(int(highscore))  );
            window.draw(perdu);

            if(Keyboard::isKeyPressed(Keyboard::R))
            {
                score=0;
                chrono.restart();
                fin=false;
                c.clear();
                for(int i=0;i<5;i+=1)
                {
                    c.push_back(ajoute());
                }
            }
        }

        window.display();

    }
    return 0;
}