#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
🎯 Sujet Revu : Projet 4 — To-Do List évoluée
Fonctionnalités à coder

    Ajouter une tâche

        Saisir description, priorité (1 à 5), état (“à faire” ou “terminée”), date limite (format JJ/MM/AAAA)

    Afficher toutes les tâches (avec tous les détails)

    Marquer une tâche comme terminée (par indice ou par description)

    Supprimer une tâche (par indice ou par description)

    Trier les tâches (par priorité croissante/décroissante)

    Modifier une tâche (description, priorité, état, date)

    Afficher seulement les tâches “à faire”

    Quitter le programme
*/

struct tache
{
    string nom;
    string description;
    int priorite;
    bool etat;
    string date;
};

void ajouter(vector<tache> &ta)
{
    tache t;
    cout<<"nom : "<<endl;
    getline(cin , t.nom);
    cout<<"description : "<<endl;
    getline(cin ,t.description);
    cout<<"priorite : "<<endl;
    cin>>t.priorite;
    cout<<"etat ;"<<endl;
    cin>>t.etat;
    cin.ignore();
    cout<<"date limite ;"<<endl;
    getline(cin , t.date);
    ta.push_back(t);
}

void afficher(vector<tache> &t)
{
    for(int i=0;i<t.size();i+=1)
    {
    cout<<"nom : "<<endl;
    cout<<t[i].nom<<endl;
    cout<<"description : "<<endl;
    cout<<t[i].description<<endl;
    cout<<"priorite : "<<endl;
    cout<<t[i].priorite<<endl;
    cout<<"etat ;"<<endl;
    cout<<t[i].etat<<endl;
    cout<<"date limite ;"<<endl;
    cout<<t[i].date<<endl;
    }
}

void terminer(vector <tache> &t)
{
    int choix, indice;
    string nom;
    cout<<"tu veux changer l'etat via l'indice 1. ou son nom 2. ?"<<endl;
    if(choix==1)
    {
        cout<<"choisis l'indice"<<endl;
        cin>>indice;
        t[indice].etat=1;
    }
    else if(choix==2)
    {
        cout<<"tape le nom"<<endl;
        cin>>nom;
        for(int i=0;i<t.size();i++)
        {
            if(nom==t[i].nom)
            {
                t[i].etat=1;
            }
        }
    }
}

void supprimer(vector <tache> &t)
{
    int choix, indice;
    string nom;
    cout<<"tu veux supprimer la tache via l'indice 1. ou son nom 2. ?"<<endl;
    if(choix==1)
    {
        cout<<"choisis l'indice"<<endl;
        cin>>indice;
        t.erase(t.begin()+indice);
    }
    else if(choix==2)
    {
        cout<<"tape le nom"<<endl;
        cin>>nom;
        for(int i=0;i<t.size();i++)
        {
            if(nom==t[i].nom)
            {
                t[i].erase();
            }
        }
    }
}

int main()
{
    vector<tache> t;
    ajouter(t);
    afficher(t);
    terminer(t);
    supprimer(t);
    return 0;
}