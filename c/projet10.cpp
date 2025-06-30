//on recommence de 0 avec SFML

//cree une fenetre

#include <SFML/Graphics.hpp>

using namespace sf; // Permet d'éviter de préfixer avec "sf::"

int main()
{


    // Crée une fenêtre 800x600 pixels, titre "Projet 10 - SFML"
    RenderWindow window(VideoMode(800, 600), "Projet 10 - SFML");



    while (window.isOpen())             //tant que la fenetre est ouverte    
    {
        Event event;                                //stock les evenements comme souris , clavier etc etc
        while (window.pollEvent(event))                 // Traite tous les événements qui sont arrivés depuis la dernière image
        {
            // Si l'utilisateur a cliqué sur la croix (fermer la fenêtre)

            if (event.type == Event::Closed)            // Nettoie la fenêtre (met tout en noir, prêt à dessiner dessus)
                window.close();                             // ferme la fenetre
        }

        window.clear();    // Efface l'écran (fond noir)
        window.display();  // Affiche la fenêtre (vide pour l'instant)
    }

    return 0;
}

