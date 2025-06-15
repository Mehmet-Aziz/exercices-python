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


/*
🧩 Objectif niveau 2

    Ajouter une fonction qui cherche un entier donné par l'utilisateur et affiche s'il est présent ou non.
*/

void recherche(vector<entier> e)
{
    int nombre;
    bool fin=false;
    do
    {
        cout<<"met un nombre ?"<<endl;
        cin>>nombre;
        for(int i=0;i<e.size();i+=1)
        {
            if(e[i].entier==nombre)         //Modification pour faire apparaitre l'indice
            {
                cout<<"nombre trouver à l'indice "<<e[i].entier<<endl;
            }
        }
        cout<<"tu as finis ?"<<endl;
        cin>>fin;
    }while(fin==false);
}

int main()
{
    vector<entier> e;
    ajout(e);
    affiche(e);
    recherche(e);
    return 0;
}