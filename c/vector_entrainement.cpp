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
                cout<<"nombre trouver à l'indice "<<i<<endl;
            }
        }
        cout<<"tu as finis ?"<<endl;
        cin>>fin;
    }while(fin==false);
}

/*
🧪 Objectif niveau 3

    Permettre à l’utilisateur de saisir un nombre, et supprimer toutes ses occurrences du vector.

⚡ Explication

    Pourquoi toutes ? Comme on l’a vu, un même nombre peut apparaître à plusieurs indices (ex : 5 aux indices 2, 4, 6).

    Suppression sur vector : On utilise erase() pour enlever un élément à un indice précis.

    ⚠️ Quand tu supprimes un élément, les indices décalent : il faut faire attention !
*/


void supprime(vector <entier> &e)
{   
    int choix;
    cout<<"quel element a supp ?"<<endl;
    cin>>choix;
    for(int i=e.size()-1;i>=0;i-=1)
    {
        if(e[i].entier==choix)
        {
            e.erase(e.begin()+i);
        }
    }
    
}

/*
🧪 Niveau 4 : Trier un vector
🧠 Objectif

    Ajouter une fonction qui trie ton vector<entier> soit en ordre croissant,
    soit en ordre décroissant (tu peux proposer le choix à l’utilisateur).
*/

void trie (vector<entier> &e)
{
    int choix;
    cout<<"veux tu trier par 1.ordre croissant ou par ordre 2.decroissant ?"<<endl;
    cin>>choix;
    int temp;
    if(choix==1)
    {
        for(j=0;j<e.size();j+=1)
        {
            for(int i=0;i<e.size()-1;i+=1)
            {
                if(e[i].entier>=e[i+1].entier)
                {
                temp=e[i].entier;
                e[i].entier=e[i+1].entier;
                e[i+1].entier=temp;
                }
            }
        }    
        for(int i=0;i<e.size();i+=1)
        {
            cout<<e[i].entier<<" ";
        }
    
    }
    if(choix==2)
    {
        for(j=0;j<e.size();j+=1)
        {
            for(int i=0;i<e.size()-1;i+=1)
            {
            
                if(e[i].entier<=e[i+1].entier)
                {
                temp=e[i].entier;
                e[i].entier=e[i+1].entier;
                e[i+1].entier=temp;
                }
            }
        }   
        for(int i=0;i<e.size();i+=1)
        {
            cout<<e[i].entier<<" ";
        }
    }
}

/*
avec chat gpt , alternative plus poussée 
#include <algorithm> // à inclure absolument !

void trier(vector<entier> &e)
{
    int choix;
    cout << "Choisir le mode de tri : 1 pour croissant, 2 pour décroissant : ";
    cin >> choix;

    if (choix == 1)
    {
        sort(e.begin(), e.end(), [](const entier &a, const entier &b) {
            return a.entier < b.entier;
        });
        cout << "✅ Trié par ordre croissant." << endl;
    }
    else if (choix == 2)
    {
        sort(e.begin(), e.end(), [](const entier &a, const entier &b) {
            return a.entier > b.entier;
        });
        cout << "✅ Trié par ordre décroissant." << endl;
    }
    else
    {
        cout << "❌ Choix invalide." << endl;
    }
}

*/

int main()
{
    vector<entier> e;
    ajout(e);
    affiche(e);
    recherche(e);
    supprime(e);
    affiche(e);
    trie(e);
    return 0;
}