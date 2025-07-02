#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;

int main()
{
    srand(time(NULL));

    const int DIMW = 1000;
    const int L = 100;
    const int H = 80;

    RenderWindow window(VideoMode(DIMW, DIMW), "rectangle");
    window.setFramerateLimit(60);

    // Position initiale du rectangle
    int x = L + rand() % (DIMW - 2*L);
    int y = H + rand() % (DIMW - 2*H);
    RectangleShape rect(Vector2f(L, H));
    rect.setFillColor(Color::Green);
    rect.setPosition(x, y);

    Font font;
    if (!font.loadFromFile("DejaVuSans.ttf")) {
        cerr << "Erreur : impossible de charger la police !" << endl;
        return 1;
    }

    int score = 0;
    Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(Color::Black);

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();

            // GESTION DU CLIC
            if(event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                int sourisX = event.mouseButton.x;
                int sourisY = event.mouseButton.y;
                // Test de collision
                if(sourisX >= x && sourisX <= x+L && sourisY >= y && sourisY <= y+H)
                {
                    score += 1;
                    // Nouvelle position aléatoire
                    x = L + rand() % (DIMW - 2*L);
                    y = H + rand() % (DIMW - 2*H);
                    rect.setPosition(x, y);
                }
            }
        }

        text.setString("Score : " + to_string(score));
        text.setPosition(10, 10);

        window.clear(Color::White);
        window.draw(rect);
        window.draw(text);
        window.display();
    }

    return 0;
}
