#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>
#include <math.h>
using namespace std;
using namespace sf;

struct cercle
{
    int rayon;
    int x;
    int y;
};

void alea_cercle(cercle &ce)
{
ce.rayon= 30 + rand()% 60;
ce.x=ce.rayon + rand()% (1000-2*ce.rayon);
ce.y=ce.rayon + rand()% (1000-2*ce.rayon);
}


int main()
{
    srand(time(NULL));

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"erreur"<<endl;
        return 1;
    }

    int score =0;
    
    Text point;
    point.setFont(font);
    point.setCharacterSize(20);
    point.setFillColor(Color::White);
    point.setPosition(10,970);
    point.setString("score :" + to_string(score));


    cercle ce;
    alea_cercle(ce);

    RenderWindow window(VideoMode(1000,1000),"JEU ATTRAPE MOI");

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
                int sourisX=event.mouseButton.x;
                int sourisY=event.mouseButton.y;
                score+=1;

                float dist=sqrt(pow(sourisX-ce.x,2)+pow(sourisY-ce.y,2));
                if(dist<ce.rayon)
                {
                    alea_cercle(ce);
                    score+=1;

                }
            }
        }

        CircleShape shape(ce.rayon);
        Color couleur (120,20,255);
        shape.setFillColor(couleur);
        shape.setPosition(ce.x-ce.rayon,ce.y-ce.rayon);
        window.draw(shape);
        window.draw(point);
        window.display();
    }

}