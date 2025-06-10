#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*
projet3

    🎯 Objectif : Créer un programme console qui gère une petite bibliothèque :

    Ajoute des livres

    Affiche les livres

    Recherche un livre par son titre

    Affiche tous les livres d’un auteur
*/

struct livre
{   
    char auteur[50];
    char nom[50];
    int annee;
};

void ajoute_livre(livre &l)
{   
    cout<<endl<<"quelle est le nom de l'auteur ?"<<endl;
    cin>>l.auteur;
    cout<<"quelle est le nom du livre ?"<<endl;
    cin>>l.nom;
    cout<<"parru en quelle année ?"<<endl;
    cin>>l.annee;
}

void affiche_livre(livre &l)
{
    cout<<"auteur :"<<endl<<l.auteur<<endl<<"nom :"<<endl<<l.nom<<endl<<"annee :"<<endl<<l.annee<<endl;
}

void recherche(livre &l)
{
    char same[50];
    cout<<"entrer le nom du livre recherché"<<endl;
    cin>>same;
        
    if(strcmp(same,l.nom)==0)
    {
        cout<<"livre retrouvé"<<endl;
    }
    else
    {
        cout<<"nous ne trouvons pas votre recherche"<<endl;
    }
}

int main()
{
    vector<livre> l;
    int vrai;
    int finis;
    do
    {
        livre temp;
        ajoute_livre(temp);
        l.push_back(temp);
        cout<<endl<<"ajoutons nous encore un auteur , 1 pour oui 0 pour non ?"<<endl;
        cin>>vrai;
    } while(vrai !=0);

    cout<<"tu recherche un livre ?"<<endl;
    do
    {
        for(int i=0;i<l.size();i+=1)
        {
        recherche(l[i]);
        }
        cout<<endl<<"tu as finis ? 1 pour oui , sinon 0"<<endl;
        cin>>finis;
    } while(finis !=1 );

    cout<<"voici tout nos livres en stocks !!!"<<endl;
    for(int i=0;i<l.size();i+=1)
    {
        affiche_livre(l[i]);
    }
    cout<<"Merci d'avoir utilisé bibliotheque"<<endl;
    return 0;
}