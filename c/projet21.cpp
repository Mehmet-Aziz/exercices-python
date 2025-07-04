#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void choix(int &a , int &b)
{
    cout<<endl<<"choisis le rayon "<<endl;
    cin>>a;
    cout<<"choisis la couleur 1.RED .2GREEN 3.BLUE"<<endl;
    cin>>b;
}

int main()
{
    RenderWindow window(VideoMode(1000,1000),"CHOIX COULEUR ET RAYON");
    int a , b;
    choix(a,b);
    CircleShape shape(a);
    switch(b)
    {
        case 1 :
        shape.setFillColor(Color::Red);
        break;

        case 2:
        shape.setFillColor(Color::Green);
        break;

        case 3:
        shape.setFillColor(Color::Blue);
        break;

        default :
        shape.setFillColor(Color::Yellow);
        break;

    }

    shape.setPosition(500-a, 500-a);

    while(window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
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

    return 0;
}
