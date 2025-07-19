#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <time.h>
#include <vector>

using namespace std;
using namespace sf;
const int DIMW=1000;

/*
//on repars de 0 , sur un nouveau projet

//ouvrir une fenetre et faire apparaitre un cercle au milieu de la fenetre

on va faire des intereactions avec la souris , si clique alors cercle devient rouge

*/

int main()
{
    int cx=DIMW/2;
    int cy=DIMW/2;
    int r=50;
    bool estRouge=false;

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
            if(event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                float mx=event.mouseButton.x ;
                float my=event.mouseButton.y ;
                float dist = sqrt(pow(mx-cx,2)+ pow(my-cy,2));
                if(dist<=r)
                {
                    estRouge=true;
                }
            }

        }

        CircleShape shape(50);
        shape.setFillColor(Color(0,0,255));
        if(estRouge==true)
        {
            shape.setFillColor(Color(255,0,0));
        }
        shape.setPosition(cx -r,cy -r);
        
        window.draw(shape);
        window.display();
    }
    return 0;
}