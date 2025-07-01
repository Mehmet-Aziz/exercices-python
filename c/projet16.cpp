#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
const int DIMW=1000;

RenderWindow window(VideoMode(DIMW,DIMW),"cercle mouvant");

CircleShape shape(30);
shape.setFillColor(Color::Red);

float x=DIMW/2;
float y=DIMW/2;

float vitesse=5.0;

while (window.isOpen())
{
    Event event;
    while(window.pollEvent(event))
    {
        if(event.type==Event::Closed)
        window.close();
    }

    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        x+=vitesse;
    }
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        x-=vitesse;
    }
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        y-=vitesse;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        y+=vitesse;
    }
    
    if(x>DIMW-30)
    {
        x=DIMW-30;
    }

     if(x<30)
    {
        x=30;
    }
    if(y>DIMW-30)
    {
        y=DIMW-30;
    }

     if(y<30)
    {
        y=30;
    }



    shape.setPosition(x-30,y-30);


    window.clear();
    window.draw(shape);
    window.display();

}

return 0;
}