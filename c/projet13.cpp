#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

struct Cercle
{
    float x;
    float y;
};

void remplir(vector <Cercle> &c)
{
    Cercle ce;
    int fin=0;
    do
    {
        cout<<"remplis le cercle"<<endl;
        cin>>ce.x;
        cin>>ce.y;
        c.push_back(ce);
        cout<<"finis ? 1 =oui , non =0"<<endl;
        cin>>fin;
    } while (fin==0);
    
}

int main()
{
    vector <Cercle> c;
    remplir(c);

    RenderWindow window(VideoMode(1000,1000),"cercles");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        for(int i=0;i<c.size();i+=1)
        {
            CircleShape shape(30);
            shape.setFillColor(Color::Red);
            shape.setPosition(c[i].x-30,c[i].y-30);
            window.draw(shape);

        }


        window.display();
    }    
    return 0;
}