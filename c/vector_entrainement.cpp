#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
🧠 Objectif :

    Créer un vector<int>

    Ajouter des nombres dedans

    Les afficher proprement

📋 Instructions :

    Demander à l’utilisateur combien de nombres il veut entrer.

    Lire ces entiers et les ajouter au vector.

    Afficher le contenu du vector.
*/

struct entier
{
    int entier;
};

void ajout(vector<entier> &e)
{
    bool fin=false;
    do
    {
        entier temp;
        cout<<"ajoute un entier"<<endl;
        cin>>temp.entier;
        e.push_back(temp);
        cout<<"tu as finis ?"<<endl;
        cin>>fin;
    } while (fin==false);
    
}

void affiche(vector <entier> e)
{
    for(auto &t : e)
    {
        cout<<t.entier<<endl;
    }
}

int main()
{
    vector<entier> e;
    ajout(e);
    affiche(e);
    return 0;
}