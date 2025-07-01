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
    const int DIMW=1000;
    RenderWindow window(VideoMode(DIMW,DIMW),"catch me if you can");
    window.setFramerateLimit(60);

    int x=rand() % DIMW;
    int y=rand() % DIMW;

    CircleShape shape(30);
    shape.setFillColor(Color::Blue);



    int score=0;



      // Préparation police & texte
    Font font;
    if (!font.loadFromFile("DejaVuSans.ttf")) {
        cerr << "Erreur : impossible de charger la police !" << endl;
        return 1;
    }
    Text texteScore;
    texteScore.setFont(font);
    texteScore.setCharacterSize(24);
    texteScore.setFillColor(Color::Black);



    while(window.isOpen())
    {
        Event event;

        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            window.close();


            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                int sourisX = event.mouseButton.x;
                int sourisY = event.mouseButton.y;

                // Calcul distance clic-centre cercle
                float dist = sqrt(pow(sourisX - x, 2) + pow(sourisY - y, 2));
                if (dist < 30)
                {
                    // Bravo, tu as cliqué dans le cercle !
                    score++;

                    // Nouvelle position aléatoire
                    x = 30 + rand() % (DIMW - 2 * 30);
                    y = 30 + rand() % (DIMW - 2 * 30);
                }
            }


        }

        // Mise à jour position cercle
        shape.setPosition(x - 30, y - 30);

        // Mise à jour score affiché
        texteScore.setString("Score : " + to_string(score));
        texteScore.setPosition(10, 10);

        window.clear(Color::White); // Fond blanc pour bien voir
        window.draw(shape);
        window.draw(texteScore);
        window.display();


    }

    return 0;
}

