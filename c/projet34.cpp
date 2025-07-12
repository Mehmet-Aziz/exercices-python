//cercle qui bouge 

#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <math.h>

using namespace std;
using namespace sf;

struct Cercle
{
    int rayon;
    float x;
    float y;
    float vx;
    float vy;
};

void ajoute_cercle(Cercle &c)
{
    c.rayon= 30+rand()% 60;
    c.x= c.rayon + rand()% 800;
    c.y=c.rayon + rand()% 800;
    c.vx=0.05;
    c.vy=0.05;
}

int main()
{

    srand(time(NULL));
    Cercle c;
    ajoute_cercle(c);

    bool fin=false;
    int score=0;
    int highscore=0;

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
    affichage.setPosition(10,900);

    tempss.setFont(font);
    tempss.setCharacterSize(20);
    tempss.setFillColor(Color::Red);
    tempss.setPosition(900,10);

    perdu.setFont(font);
    perdu.setCharacterSize(20);
    perdu.setFillColor(Color::Red);
    perdu.setPosition(200,400);

    RenderWindow window(VideoMode(1000,1000),"CERCLE EN MOUVEMENT");

    CircleShape shape(c.rayon);
    shape.setFillColor(Color::White);
    shape.setPosition(c.x-c.rayon,c.y-c.rayon);

    sf::Clock chrono;

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
                int sourisX=event.mouseButton.x;
                int sourisY=event.mouseButton.y;
                float dist=sqrt(pow(sourisX-c.x,2)+pow(sourisY-c.y,2));
                if(dist<c.rayon)
                {
                    score+=1;
                    ajoute_cercle(c);
                    Color color(rand()% 255 , rand()% 255 , rand()% 255 );
                    shape.setFillColor(color);
                }
            }


        }

        float temps=chrono.getElapsedTime().asSeconds();

        if(temps>30 && fin==false)
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
            shape.setRadius(c.rayon);
            shape.setPosition(c.x-c.rayon,c.y-c.rayon);
            c.x+=c.vx;
            c.y+=c.vy;

            if(c.y - c.rayon < 0 || c.y+c.rayon>1000)
            {
                c.vy=-c.vy;
            }
            if(c.x - c.rayon < 0 || c.x+c.rayon>1000)
            {
                c.vx=-c.vx;
            }



            affichage.setString("score : " + to_string(int(score)));
            tempss.setString(to_string(int(30-temps)));
        }

        if(fin==true)
        {
            perdu.setString("game over \n highscore : " + to_string(int(highscore))+ "\n score : " + to_string(int(score))+ "\n touche R : recommencer");

            if(Keyboard::isKeyPressed(Keyboard::R))
            {
                score=0;
                chrono.restart();
                ajoute_cercle(c);
                fin=false;
            }
        }

        if(fin==true)
        {
            window.draw(perdu);
        }
        window.draw(affichage);
        window.draw(tempss);
        window.draw(shape);
        window.display();
    }


return 0;
}