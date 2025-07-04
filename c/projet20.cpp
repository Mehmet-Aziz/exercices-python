#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{

    RenderWindow window(VideoMode(800,800),"affichage cercle");

    CircleShape shape(100);
    shape.setFillColor(Color::Blue);
    shape.setPosition(300,300);

    while(window.isOpen())
    {
        Event event;

        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();

    }

}