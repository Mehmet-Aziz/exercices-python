#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <time.h>
#include <vector>

using namespace std;
using namespace sf;


struct Rectangle
{
    float x , y;
    float longeur , hauteur;
    float vx , vy;
};

Rectangle ajouter_un_rectangle()
{
    Rectangle rect;
    rect.longeur=100;
    rect.hauteur=100;
    rect.x=100 + rand()% 800 ;
    rect.y=100 + rand()% 800 ;
    rect.vx=0.0075;
    rect.vy=0.0075;
    return rect;
}


int main()
{
    srand(time(NULL));

    RenderWindow window(VideoMode(1000,1000),"projet 37 de nouveau"); 
    
    vector <Rectangle> r;
    for(int i=0;i<5;i+=1)
    {
        r.push_back(ajouter_un_rectangle());
    }

    int score=0;
    int highscore=0;
    sf::Clock chrono;
    bool fin=false;

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"erreur"<<endl;
        return 1;
    }


    Text textscore;
    textscore.setFont(font);
    textscore.setCharacterSize(20);
    textscore.setFillColor(Color::Red);
    textscore.setPosition(10,900);

    Text textchrono;
    textchrono.setFont(font);
    textchrono.setCharacterSize(20);
    textchrono.setFillColor(Color::Red);
    textchrono.setPosition(900,10);

    Text perdu;
    perdu.setFont(font);
    perdu.setCharacterSize(30);
    perdu.setFillColor(Color::Red);
    perdu.setPosition(400,400);

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

            if(event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                for(int i=0;i<r.size();i++)
                {
                    int sourisX=event.mouseButton.x , sourisY=event.mouseButton.y;
                    if(sourisX>=r[i].x && sourisX<=r[i].x+r[i].longeur && sourisY >= r[i].y && sourisY<=r[i].y+r[i].hauteur)
                    {

                        score+=1;
                        r[i]=ajouter_un_rectangle();
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




        if(fin==true)
        {
            window.clear();
            perdu.setString("GAME OVER \n score :" + to_string(int(score)) + "\n highscore : " + to_string(int(highscore)) );

            if(Keyboard::isKeyPressed(Keyboard::R))
            {
                fin=false;
                chrono.restart();
                score=0;
                r.clear();
                for(int i=0;i<5;i+=1)
                {
                    r.push_back(ajouter_un_rectangle());
                }
            }

            window.draw(perdu);
        }


        //etape 4 : mouvement et rebond

        if(fin==false)
        {
        //etape 5 : vector de cercle
        for(int i=0;i<r.size();i+=1)
        {
        r[i].x+=r[i].vx;
        r[i].y+=r[i].vy;
        if(r[i].x-r[i].longeur/2<0 || r[i].x+r[i].longeur/2>1000)
        {
            r[i].vx=-r[i].vx;
        }
         if(r[i].y-r[i].hauteur/2<0 || r[i].y+r[i].hauteur/2>1000)
        {
            r[i].vy=-r[i].vy;
        }
        RectangleShape rec(Vector2f(r[i].longeur,r[i].hauteur));
        rec.setPosition(r[i].x-r[i].longeur/2,r[i].y-r[i].hauteur/2);
        rec.setFillColor(Color::Blue);
        window.draw(rec);
        rec.setPosition(r[i].x-r[i].longeur/2,r[i].y-r[i].hauteur/2);
        textchrono.setString("temps : " + to_string(int(30-temps)));
        }
        }
        window.draw(textchrono);
        textscore.setString("score : " + to_string(int(score)));
        window.draw(textscore);
        window.display();


    }
    return 0;
}