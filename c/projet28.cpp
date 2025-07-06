#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{

    int score=0;

    RenderWindow window(VideoMode(1000,1000),"affichage score");

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"erreur"<<endl;
        return 1;
    }

    Text text;
    text.setFont(font);
    text.setFillColor(Color::White);
    text.setCharacterSize(15);
    text.setPosition(15,975);

    CircleShape shape(100);
    shape.setFillColor(Color::Green);
    shape.setPosition(400,400);

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


        if(Keyboard::isKeyPressed(Keyboard::Escape))
        {
            Color couleur(rand()% 256 , rand()% 256 , rand()% 256 );
            shape.setFillColor(couleur);
            score+=1;
        }

        text.setString("score " + to_string(score));
        window.draw(text);
        window.draw(shape);
        window.display();

    }
    return 0;
}