#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//ouvrir une fenetre

int main()
{
    RenderWindow window(VideoMode(1000,1000),"FENETRE");
    
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
        window.display();
    }

    return 0;
}