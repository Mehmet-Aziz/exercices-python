#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

struct cercle
{
    int x;
    int y;
    int rayon;
    int couleur;
};

void remplir(vector <cercle> &c)
{
    bool fin=false;
    cercle ce;
    do
    {
        cout<<endl<<"position x ?"<<endl;
        cin>>ce.x;
        cout<<endl<<"position y ?"<<endl;
        cin>>ce.y;
        cout<<endl<<"rayon ?"<<endl;
        cin>>ce.rayon;
        cout<<endl<<"couleur ? 1.RED , 2.GREEN , 3.BLUE"<<endl;
        cin>>ce.couleur;
        c.push_back(ce);
        cout<<endl<<"finis ? 'true' pour oui sinon 'false' "<<endl;
        cin>>fin;
    }
    while(fin==false);
}

int main()
{
    vector <cercle> c;
    remplir(c);
    RenderWindow window(VideoMode(1000,1000),"tableau de cercle");

    while(window.isOpen())
    {
        Event event;

        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            window.close();
        }

        window.clear();

        for(int i=0;i<c.size();i+=1)
        {
            CircleShape shape(c[i].rayon);
            switch(c[i].couleur)
            {
            
            case 1 :
            shape.setFillColor(Color::Red);
            break;

            case 2 :
            shape.setFillColor(Color::Green);
            break;

            case 3 :
            shape.setFillColor(Color::Blue);
            break;

            default :
            cout<<endl<<"erreur"<<endl;
            break;
            }
            shape.setPosition(c[i].x-c[i].rayon,c[i].y-c[i].rayon);
            window.draw(shape);
        }

        window.display();

    }
    return 0;
}