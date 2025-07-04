#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

struct shape
{
    int rayon;
    int x;
    int y;
};

struct rect
{
    int largeur;
    int hauteur;
    int x;
    int y;
};

void remplir_shape(vector <shape> &s)
{
    shape sh;
    bool fin=false;
    do
    {
        cout<<endl<<"rayon ?"<<endl;
        cin>>sh.rayon;
        cout<<"position x ?"<<endl;
        cin>>sh.x;
        cout<<"position y"<<endl;
        cin>>sh.y;
        s.push_back(sh);
        cout<<"as tu finis ? oui ? tape 1 sinon tape 0"<<endl;
        cin>>fin;
    } while (fin==false);
    
}

void remplir_rect(vector <rect> &r)
{
    rect re;
    bool fin=false;
    do
    {
        cout<<endl<<"largeur ?"<<endl;
        cin>>re.largeur;
        cout<<"hauteur ?"<<endl;
        cin>>re.hauteur;
        cout<<"position x ?"<<endl;
        cin>>re.x;
        cout<<"position y"<<endl;
        cin>>re.y;
        r.push_back(re);
        cout<<"as tu finis ? oui ? tape 1 sinon tape 0"<<endl;
        cin>>fin;
    } while (fin==false);
    
}

int main()
{

    vector <shape> s;
    vector <rect> r;

    remplir_shape(s);
    remplir_rect(r);

    RenderWindow window(VideoMode(1000,1000),"cercle et rectangle");

    while(window.isOpen())
    {
        Event event;
        window.clear();
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }
        }

        for(int i=0;i<s.size();i+=1)
        {
            CircleShape cercle(s[i].rayon);
            cercle.setFillColor(Color::Red);
            cercle.setPosition(s[i].x-s[i].rayon,s[i].y-s[i].rayon);
            window.draw(cercle);
        }

        for(int i=0;i<r.size();i+=1)
        {
            RectangleShape rectangle(Vector2f(r[i].largeur,r[i].hauteur));
            rectangle.setFillColor(Color::Green);
            rectangle.setPosition(r[i].x-r[i].largeur/2,r[i].y-r[i].hauteur/2);
            window.draw(rectangle);
        }

       
        window.display();

    }

    return 0;
}