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

void ajouter_un_cercle(Cercle &c)
{
    c.rayon=30+rand()% 60;
    c.x=c.rayon+rand()% (1000-2*c.rayon);
    c.y=c.rayon+rand()% (1000-2*c.rayon);
}

int main()
{
    srand(time(NULL));
    Cercle c;
    ajouter_un_cercle(c);
    bool fin=false;
    int score=0;
     sf::Clock chrono;

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"error"<<endl;
        return 1;
    }


    RenderWindow window(VideoMode(1000,1000),"Attrape cercle");

    CircleShape shape(c.rayon);
    shape.setFillColor(Color::Blue);
    shape.setPosition(c.x-c.rayon,c.y-c.rayon);

    Text affichage;
    affichage.setFont(font);
    affichage.setFillColor(Color::Red);
    affichage.setPosition(10,850);
    affichage.setCharacterSize(20);

    Text fin_de_jeu;
    fin_de_jeu.setFont(font);
    fin_de_jeu.setFillColor(Color::Red);
    fin_de_jeu.setPosition(300,400);
    fin_de_jeu.setCharacterSize(30);


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
                float dist=sqrt(pow(sourisX-c.x,2)+pow(sourisY-c.y,2));

                if(dist<c.rayon)
                {
                    score+=1;
                    ajouter_un_cercle(c);
                }

            }

            float temps=chrono.getElapsedTime().asSeconds();
            if(temps>30 && fin==false)
            {
                fin=true;
            }

            if(fin==false)
            {
              shape.setPosition(c.x - c.rayon, c.y - c.rayon);
              window.draw(shape);  

              affichage.setString("score" + to_string(score)+"\nTEMPS : " + to_string(30-temps) ); 
            }
            window.draw(affichage);

            if(fin==true)
            {
                fin_de_jeu.setString("GAME OVER  \nSCORE:"+ to_string(score));
            }
            window.draw(fin_de_jeu);

            if (Keyboard::isKeyPressed(Keyboard::R))
            {
                score = 0;
                chrono.restart();
                ajouter_un_cercle(c);
                fin = false;
            }


        }
        window.draw(shape);
        window.display();
    }
    return 0;
}