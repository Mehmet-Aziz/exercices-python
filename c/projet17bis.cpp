#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <math.h>

using namespace std;
using namespace sf;


int main()
{
    srand(time(NULL));
    const int DIMW =1000;
    RenderWindow window(VideoMode(DIMW,DIMW),"rattrapage du projet");
    window.setFramerateLimit(60);

    const int RAYON= 30.0;

    int x = RAYON + rand()% (DIMW - 2*RAYON);
    int y = RAYON + rand()% (DIMW - 2*RAYON);

    CircleShape cercle(RAYON);
    cercle.setFillColor(Color::Blue);

    int score = 0;

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf")) {
        cerr << "Erreur : impossible de charger la police !" << endl;
        return 1;
    }

    Text text;
    text.setFont(font);
    text.setCharacterSize(10);
    text.setFillColor(Color::White);

    while(window.isOpen())
    {
        Event event;

        while(window.pollEvent(event))
        {
            if (event.type==Event::Closed)
            {
                window.close();
            }

            if(event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                int sourisx=event.mouseButton.x;
                int sourisy=event.mouseButton.y;
                float dist = sqrt(pow(sourisx- x, 2) + pow(sourisy - y, 2));
                if (dist < RAYON)
                {
                    score+=1;
                     x = RAYON + rand()% (DIMW - 2*RAYON);
                     y = RAYON + rand()% (DIMW - 2*RAYON);
                }    
            }
            

        }

        cercle.setPosition(x-RAYON,y-RAYON);
        text.setString("score " + to_string(score));
        text.setPosition(10,DIMW-50);

        window.clear();
        window.draw(cercle);
        window.draw(text);
        window.display();
    }

    return 0;
}