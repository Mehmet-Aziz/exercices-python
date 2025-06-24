#include <SFML/Graphics.hpp>
using namespace sf;

//creation de fenetre et pouvoir la quitté

int main()
{

RenderWindow window(VideoMode(1000,1000),"titre");

while(window.isOpen())
{
     Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
}
    return 0;
}