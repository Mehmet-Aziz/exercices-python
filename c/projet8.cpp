#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1000,1000),"Salut, Robot");
    Texture texture;
    if(!texture.loadFromFile("robot_vrai.png"))
    {
        return 1;
    }

    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(200,200);

    while (window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        if (event.type==Event::Closed)
        {
            window.close();
        }
        
        window.clear();
        window.draw(sprite);
        window.display();

    }
    return 0;
}
