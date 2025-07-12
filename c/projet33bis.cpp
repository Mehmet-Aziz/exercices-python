//refaire le projet32

#include <iostream>
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
};

void ajoute_cercle(Cercle &c)
{
    c.rayon=30 + rand()% 60;
    c.x= c.rayon + rand()% (1000-2*c.rayon);
    c.y= c.rayon + rand()% (1000-2*c.rayon); 
}

int main()
{
    srand(time(NULL));
    int score=0;
    int high_score=0;
    Cercle c;
    ajoute_cercle(c);
    bool fin=false;

    RenderWindow window(VideoMode(1000,1000),"PROJET 32 AU PROPRE");

    CircleShape shape(c.rayon);
    shape.setFillColor(Color::White);
    shape.setPosition(400,400);
    Color color(rand()%255,rand()%255,rand()%255);


    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"error"<<endl;
        return 1;
    }

    Text temps;
    temps.setFont(font);
    temps.setCharacterSize(20);
    temps.setFillColor(Color::Red);
    temps.setPosition(880,10);

    Text affichage;
    affichage.setFont(font);
    affichage.setCharacterSize(20);
    affichage.setFillColor(Color::Red);
    affichage.setPosition(10,920);

    Text perdu;
    perdu.setFont(font);
    perdu.setCharacterSize(50);
    perdu.setFillColor(Color::Red);
    perdu.setPosition(300,400);


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


            if(fin==false && event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                int sourisX=event.mouseButton.x;
                int sourisY=event.mouseButton.y;
                float dist=sqrt(pow(sourisX-c.x,2)+pow(sourisY-c.y,2));
                if(dist<c.rayon)
                {
                    ajoute_cercle(c);
                    score+=1;
                }
            }

        }
    
        float temp = chrono.getElapsedTime().asSeconds();

        if(fin==false && temp>30)
        {
            fin=true;
            if(score>high_score)
            {
                high_score=score;
            }
        }
        
        window.clear();

        if(fin==false)
        {
            shape.setFillColor(color);
            shape.setPosition(c.x-c.rayon,c.y-c.rayon);


            temps.setString("temps : " + to_string(int(30-temp)));
            affichage.setString("score : " + to_string(int(score)));
        }
        if(fin==true)
        {
            perdu.setString("GAME OVER : \n scrore :" + to_string(int(score)) + "highscore :" + to_string(int(high_score)) + "\n appuis sur R pour recommencer");
            if(Keyboard::isKeyPressed(Keyboard::R))
            {
                score=0;
                chrono.restart();
                ajoute_cercle(c);
                fin=false;
            }
        }

        window.draw(shape);
        window.draw(temps);
        window.draw(affichage);
        if(fin==true)
        {
        window.draw(perdu);
        }
        window.display();
    }
    return 0;
}