#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <time.h>
#include <vector>

using namespace std;
using namespace sf;
const int DIMW=1000;


//on repars de 0 , sur un nouveau projet

//ouvrir une fenetre et faire apparaitre un cercle au milieu de la fenetre


int main()
{
    RenderWindow window(VideoMode(DIMW,DIMW),"nouveau projet");

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

        }

        CircleShape shape(50);
        shape.setFillColor(Color(0,0,255));
        shape.setPosition(DIMW/2 -50, DIMW/2 - 50);
        
        window.draw(shape);
        window.display();
    }
    return 0;
}