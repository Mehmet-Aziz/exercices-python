#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

struct cercle
{
    int x;
    int y;
    int rayon;
    string couleur;
    string nom;
};


void remplir(vector <cercle> &c)
{
    cercle ce;
    bool fin=false;
    do
    {
    cout<<endl<<"position en x ?"<<endl;
    cin>>ce.x;
    cout<<"position en y ?"<<endl;
    cin>>ce.y;
    cout<<"quelle est son rayon ?"<<endl;
    cin>>ce.rayon;
    cout<<"couleur ? (rgb)"<<endl;
    cin>>ce.couleur;
    cout<<"nom sur le cercle ?"<<endl;
    cin>>ce.nom;
    c.push_back(ce);
    cout<<"c'est finis ? 1 pour oui , 0 pour non "<<endl;
    cin>>fin;
    } while (fin==false);
}

int main()
{
    vector <cercle> c;
    remplir(c);

    Font font;
    if (!font.loadFromFile("DejaVuSans.ttf")) {
    cerr << "Erreur : impossible de charger la police DejaVuSans.ttf !" << endl;
    return 1;
}


    RenderWindow window(VideoMode(1000,1000),"Cercle avec nom");

    while (window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        for(int i=0;i<c.size();i++)
        {
            CircleShape shape(c[i].rayon);

            if(c[i].couleur=="red")
            shape.setFillColor(Color::Red);

            if(c[i].couleur=="green")
            shape.setFillColor(Color::Green);

            if(c[i].couleur=="blue")
            shape.setFillColor(Color::Blue);
            
            shape.setPosition(c[i].x-c[i].rayon,c[i].y-c[i].rayon);
            window.draw(shape);


            Text text;
            text.setFont(font);
            text.setString(c[i].nom);
            text.setCharacterSize(18);
            text.setFillColor(Color::White);
            text.setPosition((c[i].x+c[i].rayon)/2,(c[i].y+c[i].rayon)/2);
            window.draw(text);


            // Calcul du centre du cercle
            float centreX = c[i].x;
            float centreY = c[i].y;

            // Pour centrer, il faut décaler le texte de moitié de sa taille
            FloatRect bounds = text.getLocalBounds();
            text.setOrigin(bounds.width / 2, bounds.height / 2);

            // Placer le centre du texte au centre du cercle
            text.setPosition(centreX, centreY);
        }
        window.display();
    }
    
    return 0;
}