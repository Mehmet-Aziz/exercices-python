#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <time.h>
#include <vector>

using namespace std;
using namespace sf;


enum Ecran { MENU , JEU };

bool sourisSur(const Vector2i& souris , const RectangleShape& bouton)
{
    FloatRect bounds = bouton.getGlobalBounds();
    return bounds.contains(static_cast<float>(souris.x), static_cast<float>(souris.y));
}

int main()
{
    RenderWindow window(VideoMode(1000,1000),"MENU");

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"error"<<endl;
        return 1;
    }


    RectangleShape boutonJouer(Vector2f(200,50));
    boutonJouer.setPosition(200,150);
    boutonJouer.setFillColor(Color(100,200,100));
    Text txtJouer("Jouer", font ,24);
    txtJouer.setPosition(260,160);

    RectangleShape boutonQuitter(Vector2f(200,50));
    boutonQuitter.setPosition(200,230);
    boutonQuitter.setFillColor(Color(200,100,100));
    Text txtQuitter("Quitter" , font , 24);
    txtQuitter.setPosition(245,240);

    Text titre("Menu", font , 36);
    titre.setPosition(140,50);
    titre.setFillColor(Color::Blue);

    Text txtJeu("Jeu en cours \n presse echap pour revenir au menu", font , 24);
    txtJeu.setPosition(80,180);

    Ecran ecranactuel = MENU;

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }

            if(ecranactuel== MENU)
            {
                if(event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
                {
                    Vector2i souris = Mouse::getPosition(window);
                    if(sourisSur(souris,boutonJouer))
                    {
                        ecranactuel=JEU;
                    }
                    if(sourisSur(souris,boutonQuitter))
                    {
                        window.close();
                    }
                }
            }
            else if(ecranactuel==JEU)
            {
                if(event.type==Event::KeyPressed && event.key.code==Keyboard::Escape)
                {
                    ecranactuel=MENU;
                }
            }
        }

        window.clear(Color::White);

        if(ecranactuel==MENU)
        {
            window.draw(titre);
            window.draw(boutonJouer);
            window.draw(txtJouer);
            window.draw(boutonQuitter);
            window.draw(txtQuitter);
        }
        else if(ecranactuel==JEU)
        {
            window.draw(txtJeu);
        }

        window.display();
    }

    return 0;
}