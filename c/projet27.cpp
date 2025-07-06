#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{

    RenderWindow window(VideoMode(1000,1000),"affichage de texte");
    

    //pour charger la police de texte

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"erreur"<<endl;
        return 1;
    }

    Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(Color::White);
    text.setPosition(500 , 500);
    text.setString("Bienvenu ");

    while(window.isOpen())
    {
        window.clear();
        Event event;

        while (window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }
        }

        window.draw(text);
        window.display();
        
    }

    return 0;

}