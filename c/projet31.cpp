#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;
using namespace sf;

struct cercle
{
    float rayon;
    float x;
    float y;   
};

void alea_cercle(cercle &ce)
{
    ce.rayon=30+rand()% 60;
    ce.x=ce.rayon + rand()% (1000- int(2* ce.rayon));
    ce.y=ce.rayon + rand()% (1000- int(2* ce.rayon));
}

int main()
{
srand(time(NULL));
cercle c;
alea_cercle(c);



int score =0;
sf::Clock chrono;
bool gameOver = false;


RenderWindow window(VideoMode(1000,1000),"avec score et temps");

Font font;
if(!font.loadFromFile("DejaVuSans.ttf"))
{
    cerr<<"error"<<endl;
    return 1;
}

Text point;
point.setFont(font);
point.setCharacterSize(20);
point.setFillColor(Color::Red);
point.setPosition(10,970);

Text perdu;
perdu.setFont(font);
perdu.setCharacterSize(20);
perdu.setFillColor(Color::Red);
perdu.setPosition(940,20);

CircleShape shape(c.rayon);
shape.setFillColor(Color::White);

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

        if(!gameOver && event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
        {

            int sourisX=event.mouseButton.x;
            int sourisY=event.mouseButton.y;
            float dist=sqrt(pow(sourisX-c.x,2)+pow(sourisY-c.y,2));
            if(dist<c.rayon)
            {
                score++;
                alea_cercle(c);
            }

        }

    }


    float temps = chrono.getElapsedTime().asSeconds();
    if(temps>30 && !gameOver)
    {
        gameOver=true;
    }
    if(gameOver==false)
    {
        perdu.setString("Temps restant : " + to_string(int(30-temps)));
    }
    if(gameOver==true)
    {
        window.clear();
        perdu.setPosition(300 ,300);
        perdu.setCharacterSize(40);
        perdu.setString("GAME OVER");
    }

    window.draw(perdu);
    shape.setPosition(c.x-c.rayon,c.y-c.rayon);
    window.draw(shape);
    point.setString("score :  " + to_string(score));
    window.draw(point);
    window.display();
}

return 0;
}