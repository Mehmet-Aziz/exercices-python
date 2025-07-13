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
    affichage.setColor(Color::Red);
    affichage.setPosition(10 , 900);

    tempss.setFont(font);
    tempss.setCharacterSize(20);
    tempss.setColor(Color::Red);
    tempss.setPosition(890 , 10);

    perdu.setFont(font);
    perdu.setCharacterSize(20);
    perdu.setColor(Color::Red);
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
                    float dist=sqrt(pow(sourisX-c[i].rayon,2)+pow(sourisY-c[i].rayon,2));
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
        

    }

}