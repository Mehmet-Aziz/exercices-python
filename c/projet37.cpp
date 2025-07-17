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

int score=0;

vector <Rectangle> rect;
for(int i=0;i<5;i+=1)
{
rect.push_back(ajouter_un_rectangle());
}

srand(time(NULL));
RenderWindow window(VideoMode(1000,1000),"attrape rectangle");

Font font;
if(!font.loadFromFile("DejaVuSans.ttf"))
{
    cerr<<"erreur "<<endl;
    return 1;
}

Text affichage;
affichage.setFont(font);
affichage.setCharacterSize(20);
affichage.setFillColor(Color::Red);
affichage.setPosition(10,900);

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
            for(int i=0;rect.size();i+=1)
            {
            float sourisX=event.mouseButton.x;
            float sourisY=event.mouseButton.y;
            if(sourisX>=rect[i].x && sourisX<=rect[i].x+rect[i].longeur && sourisY>=rect[i].y && sourisY<=rect[i].y+rect[i].hauteur)
            {
                score+=1;
                rect.push_back(ajouter_un_rectangle());
            }
            }
        
        }
    

        affichage.setString("score : " + to_string(int(score)));


        for(int i=0;i<rect.size();i+=1)
        {
            rect[i].x+=rect[i].vx;
            rect[i].y+=rect[i].vy;
            if(rect[i].x-rect[i].longeur/2<0 || rect[i].x+rect[i].longeur/2>1000 || rect[i].y-rect[i].hauteur/2<0 || rect[i].y+rect[i].hauteur/2>1000)
            {
                rect[i].vx=-rect[i].vx;
                rect[i].vy=-rect[i].vy;
            }
            RectangleShape rectangle(Vector2f(rect[i].longeur,rect[i].hauteur));
            rectangle.setFillColor(Color::Red);
            rectangle.setPosition(rect[i].x-rect[i].longeur/2,rect[i].y-rect[i].hauteur/2);
            window.draw(rectangle);
        }

    }


    window.draw(affichage);
    window.display();
}

return 0;
}