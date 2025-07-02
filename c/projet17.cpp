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

/*
#include <SFML/Graphics.hpp>  // Librairie graphique principale SFML (pour fenêtre, formes, texte)
#include <SFML/Window.hpp>    // (inclus dans Graphics, mais explicite)
#include <SFML/System.hpp>    // Pour gestion du temps, random, etc.
#include <iostream>           // Pour affichage erreurs dans le terminal
#include <cmath>              // Pour std::sqrt et std::pow (calcul distance)
using namespace sf;           // Pour éviter d’écrire sf:: devant chaque classe SFML
using namespace std;          // Idem pour std::

int main()
{
    // Définition de la taille de la fenêtre
    const int WIDTH = 800;      // Largeur en pixels
    const int HEIGHT = 600;     // Hauteur en pixels
    const float RAYON = 40.0f;  // Rayon du cercle

    // Création de la fenêtre graphique SFML
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Attrape le cercle !");
    window.setFramerateLimit(60); // Limite à 60 images/seconde pour un affichage fluide

    // Initialisation du générateur aléatoire avec l’horloge système (pour que la position du cercle soit différente à chaque exécution)
    srand(time(NULL));

    // Position initiale du centre du cercle (aléatoire, mais le cercle ne doit pas dépasser de la fenêtre)
    float x = RAYON + rand() % (WIDTH - 2 * (int)RAYON);   // x entre 40 et 760 si WIDTH=800
    float y = RAYON + rand() % (HEIGHT - 2 * (int)RAYON);  // y entre 40 et 560 si HEIGHT=600

    // Création du cercle (objet graphique)
    CircleShape cercle(RAYON);            // Crée un cercle de rayon 40 pixels
    cercle.setFillColor(Color::Red);      // Met la couleur de remplissage en rouge

    int score = 0;                        // Score du joueur (nombre de cercles attrapés)

    // Chargement de la police d’écriture pour afficher du texte
    Font font;
    if (!font.loadFromFile("DejaVuSans.ttf")) { // Change le nom si tu utilises une autre police
        cerr << "Erreur : impossible de charger la police !" << endl;
        return 1;  // On arrête le programme si la police n’a pas été trouvée
    }

    // Préparation du texte à afficher pour le score
    Text texteScore;
    texteScore.setFont(font);            // On utilise la police chargée juste avant
    texteScore.setCharacterSize(24);     // Taille du texte
    texteScore.setFillColor(Color::Black); // Couleur du texte

    // ----- BOUCLE PRINCIPALE DU JEU -----
    while (window.isOpen())
    {
        // ----- GESTION DES ÉVÉNEMENTS (clavier, souris, fermeture...) -----
        Event event;
        while (window.pollEvent(event))
        {
            // Si l’utilisateur clique sur la croix, on ferme la fenêtre
            if (event.type == Event::Closed)
                window.close();

            // Si un bouton de la souris est appuyé
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                // On récupère la position du clic (x, y)
                int sourisX = event.mouseButton.x;
                int sourisY = event.mouseButton.y;

                // Calcul de la distance entre le clic et le centre du cercle (théorème de Pythagore)
                float dist = sqrt(pow(sourisX - x, 2) + pow(sourisY - y, 2));
                if (dist < RAYON)
                {
                    // Si la distance est inférieure au rayon : le clic est dans le cercle
                    score++;  // On augmente le score

                    // Nouvelle position aléatoire pour le centre du cercle (toujours entièrement visible)
                    x = RAYON + rand() % (WIDTH - 2 * (int)RAYON);
                    y = RAYON + rand() % (HEIGHT - 2 * (int)RAYON);
                    // Le cercle apparaîtra ailleurs au prochain affichage
                }
            }
        }

        // ----- MISE À JOUR VISUELLE -----

        // On place le cercle à la nouvelle position (attention, setPosition place le coin haut-gauche du carré qui entoure le cercle)
        cercle.setPosition(x - RAYON, y - RAYON);

        // On prépare le texte à afficher (score)
        texteScore.setString("Score : " + to_string(score));
        texteScore.setPosition(10, 10); // Toujours en haut à gauche de la fenêtre

        // ----- AFFICHAGE -----
        window.clear(Color::White); // On efface la fenêtre et on la colore en blanc

        window.draw(cercle);        // On dessine le cercle
        window.draw(texteScore);    // On dessine le score

        window.display();           // On affiche tout à l’écran
    }

    // Fin du programme (quand la fenêtre est fermée)
    return 0;
}



*/