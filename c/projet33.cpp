//gestion du temps

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


int main()
{

    RenderWindow window(VideoMode(1000,1000),"gestion du temsp");

    sf::Clock chrono;

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"error"<<endl;
        return 1;
    }

    Text affichage;
    affichage.setFont(font);
    affichage.setCharacterSize(20);
    affichage.setFillColor(Color::Red);
    affichage.setPosition(10,10);

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


        float temps=chrono.getElapsedTime().asSeconds();

        affichage.setString("temps ecoule :  " + to_string(int(30-temps)));

        window.clear();
        window.draw(affichage);
        window.display();
    }

    return 0;
}