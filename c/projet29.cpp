#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace std;
using namespace sf;


int main()
{

    RenderWindow window(VideoMode(1000,1000),"PROJET BOSS");

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"error"<<endl;
        return 1;
    }

    int score =0;

    Text scre;
    scre.setFont(font);
    scre.setCharacterSize(15);
    scre.setFillColor(Color::White);
    scre.setPosition(10,10);

    Text position;
    position.setFont(font);
    position.setCharacterSize(20);
    position.setFillColor(Color::Red);
    position.setPosition(10,975);

    int x=400;
    int y=400;
    CircleShape shape(100);
    shape.setFillColor(Color::Blue);
    shape.setPosition(x,y);

    int largeur=100;
    int hauteur=100;
    RectangleShape rect(Vector2f(largeur,hauteur));
    rect.setFillColor(Color::Blue);
    rect.setPosition(largeur,hauteur);

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

            if(event.type==Event::KeyPressed && event.key.code==Keyboard::R)
            {
                x=400;
                y=400;
                largeur=450;
                hauteur=450;
                shape.setPosition(x,y);
                rect.setPosition(largeur,hauteur);

            }

            if(event.type==Event::KeyPressed && event.key.code==Keyboard::Escape)
            {
                score+=1;
                Color couleur (rand()% 256 , rand()%256, rand()%256);
                shape.setFillColor(couleur);
            }

        }

        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            y-=1;
        }
          if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            y+=1;
        }
          if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            x-=1;
        }
          if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            x+=1;
        }

        if(Keyboard::isKeyPressed(Keyboard::Z))
        {
            hauteur-=1;
        }
          if(Keyboard::isKeyPressed(Keyboard::S))
        {
            hauteur+=1;
        }
          if(Keyboard::isKeyPressed(Keyboard::Q))
        {
            largeur-=1;
        }
          if(Keyboard::isKeyPressed(Keyboard::D))
        {
            largeur+=1;
        }


        if(x<00)
        {
            x=00;
        }
        if(x>800)
        {
            x=800;
        }
        if(y<00)
        {
            y=00;
        }
        if(y>800)
        {
            y=800;
        }
        

        if(largeur<00)
        {
            largeur=00;
        }
        if(largeur>900)
        {
            largeur=900;
        }
        if(hauteur<00)
        {
            hauteur=00;
        }
        if(hauteur>900)
        {
            hauteur=900;
        }


        rect.setPosition(largeur,hauteur);
        shape.setPosition(x,y);
        scre.setString("score :" + to_string(score));
        position.setString("Position :" + to_string(x)+ "  x  " +to_string(y)+ "  y" + "            "+ to_string(largeur)+ " x  "+to_string(hauteur)+" y ");
        window.draw(scre);
        window.draw(position);
        window.draw(shape);
        window.draw(rect);
        window.display();

    }
    return 0;
}