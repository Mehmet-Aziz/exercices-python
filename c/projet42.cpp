#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;
using namespace sf;


const int NB_CASES_X=20;
const int NB_CASES_Y=20;
const int TAILLE_CASE=25;


struct Pomme
{
    float r , x , y;
};

Pomme ajoute_pomme()
{
    Pomme p;
    p.r=8;
    p.x= p.r + rand()% 500-2*p.r;
    p.y= p.r + rand()% 500-2*p.r;
    return p;
}



int main()
{

    srand(time(NULL));

    Pomme p=ajoute_pomme();
   


    RenderWindow window(VideoMode(NB_CASES_X*TAILLE_CASE,NB_CASES_Y*TAILLE_CASE),"snake");

    CircleShape pomme(p.r);
    pomme.setFillColor(Color::Red);
    
    float snakeX=0 , snakeY=0 , snakeL=25 , snakeH=25 , snakeVX=25 , snakeVY=25;
    RectangleShape snake(Vector2f(snakeL,snakeH));
    snake.setFillColor(Color::Green);
    


    sf::Clock chrono;
    int score=0, highscore=0;

    while(window.isOpen())
    {
        window.clear();
        Event event;
        float temps=chrono.getElapsedTime().asMilliseconds();

        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::KeyPressed) 
            {
            if (event.key.code == Keyboard::Up)    { snakeVX = 0;   snakeVY = -TAILLE_CASE; }
            if (event.key.code == Keyboard::Down)  { snakeVX = 0;   snakeVY =  TAILLE_CASE; } //extrait de chatgpt
            if (event.key.code == Keyboard::Left)  { snakeVX = -TAILLE_CASE; snakeVY = 0; }
            if (event.key.code == Keyboard::Right) { snakeVX =  TAILLE_CASE; snakeVY = 0; }
            }

        }

        for(int i=0;i<NB_CASES_X;i+=1)
        {
            RectangleShape ligneX(Vector2f(1,NB_CASES_Y*TAILLE_CASE));
            ligneX.setPosition(i*TAILLE_CASE,0);
            ligneX.setFillColor(Color(100,100,100));
            window.draw(ligneX);
        }
        for(int i=0;i<NB_CASES_Y;i+=1)
        {
            RectangleShape ligneY(Vector2f(NB_CASES_X*TAILLE_CASE,1));
            ligneY.setPosition(0,i*TAILLE_CASE);
            ligneY.setFillColor(Color(100,100,100));
            window.draw(ligneY);
        }

        if(temps>200)
        {
            snakeX+=snakeVX;
            snakeY+=snakeVY;

            chrono.restart();
        }

        if(p.x<snakeX+snakeL && p.x+2*p.r>snakeX && p.y<snakeY+snakeH && p.y+2*p.r>snakeY)
        {
            score++;
            p=ajoute_pomme();
        }

        
           
        pomme.setPosition(p.x-p.r,p.y-p.r);
        snake.setPosition(snakeX,snakeY);
        window.draw(pomme);
        window.draw(snake);
        window.display();
    }



    return 0;
}