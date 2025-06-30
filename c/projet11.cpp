#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Cercle SFML");

    // 1. Créer un cercle de rayon 50
    CircleShape cercle(50); // Rayon = 50 pixels

    // 2. Changer sa couleur (rouge)
    cercle.setFillColor(Color::Red);

    // 3. Placer le cercle au centre (attention : le "0,0" c'est en haut à gauche)
    // Position = (milieu largeur - rayon, milieu hauteur - rayon)
    cercle.setPosition(400 - 50, 300 - 50); // (largeur/2 - rayon, hauteur/2 - rayon)

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();         // Efface la fenêtre
        window.draw(cercle);    // DESSINE le cercle (IMPORTANT : AVANT le display)
        window.display();       // Affiche tout à l'écran
    }

    return 0;
}
