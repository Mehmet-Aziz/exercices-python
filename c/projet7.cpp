#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//introduction au graphics , premier hello world

#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Hello SFML!");

    // Charger la police
    Font font;
    if (!font.loadFromFile("DejaVuSans.ttf"))  // Mets le nom de ta police ici
    {
        return 1; // Erreur si la police n'est pas trouvée
    }

    // Créer le texte
    Text texte;
    texte.setFont(font);
    texte.setString("Hello World !");
    texte.setCharacterSize(48);
    texte.setFillColor(Color::White);
    texte.setPosition(200, 250);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Black);
        window.draw(texte);
        window.display();
    }
    return 0;
}


/*
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    // 1. Créer une fenêtre
    RenderWindow window(VideoMode(800, 600), "Hello SFML!");

    // 2. Charger une police (font)
    Font font;
    font.loadFromFile("arial.ttf"); // il faut le fichier arial.ttf dans le même dossier

    // 3. Préparer le texte à afficher
    Text texte;
    texte.setFont(font);
    texte.setString("Hello World !");
    texte.setCharacterSize(48); // Taille de police
    texte.setFillColor(Color::White); // Couleur du texte
    texte.setPosition(200, 250); // Position (en pixels)

    // 4. Boucle principale
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Black);   // Efface la fenêtre (noir)
        window.draw(texte);           // Affiche le texte
        window.display();             // Rafraîchit la fenêtre
    }

    return 0;
}

*/

