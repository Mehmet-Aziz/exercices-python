#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

/*
    🧩 Objectif général

Créer une To-Do List en C++ qui permet de gérer des tâches avec :

    Une description

    Une priorité (1 à 5)

    Une date

    Un état ("à faire" ou "terminée")
*/

struct tache
{
    string nom;
    string description;
    int priorite;
    bool etat;
    char date[10];
};

void remplir (tache &t)
{
    cout<<"quelle est son nom ?"<<endl;
    cin>>t.nom;
    cout<<"quelle est sa description ?"<<endl;
    cin>>t.description;
    cout<<"quelle est son ordre de priorite ?"<<endl;
    cin>>t.priorite;
    cout<<"quelle est son etat ?"<<endl;
    cin>>t.etat;
    cout<<"quelle est sa date limite  ?"<<endl;
    for(int i=0;i<10;i++)
    {
        if((i==2)||(i==5))
        {
            t.date[i]= /;
        }
        else
        {
            cin>>t.date[i];
        }
    }
}

void affiche(vector<tache> t)
{
    cout<<"NOM :"<<endl<<t.nom<<endl;
    cout<<"DESCRIPTION :"<<endl<<t.description<<endl;
    cout<<"PRIORITE :"<<endl<<t.priorite<<endl;
    cout<<"ETAT :"<<endl<<t.etat<<endl;
    cout<<"DATE :"<<endl<<t.date<<endl;
}

tache terminer()
{
    int choix;
    int index;
    string titre;


    cout<<"cherchez vous l'indice ou le nom ?"<<endl<<"pour l'indice taper 1 , pour le nom taper 2"<<;
    cin>>choix;
    if(choix==1)
    {
        cout<<"tu as chercher l'indice du tableau, tape son indice ";
        cin>>index;
        if(index>=0 && index<t.size())
        {
        t[index].etat=true;
        }
    }
    bool trouve=false;
    if(choix==2)
    {
        cout<<"tu as choisis le nom "<<endl<<"tape le titre ";
        cin>>titre;
        cin.ignore();
        for (auto &ta : t)
        {
            if (ta.description == titre)
            {
                ta.etat = true;
                cout << "Tâche marquée comme terminée ✅" << endl;
                trouve = true;
                break;
            }
        }
    }
}

//fait avec chatgpt car trop debutant pour les vectors
void supprimer_tache(vector<tache> &liste, int index)
{
    if (index < 0 || index >= liste.size())
    {
        cout << "❌ Index invalide. Aucun élément supprimé." << endl;
        return;
    }

    liste.erase(liste.begin() + index);
    cout << "✅ Tâche supprimée avec succès !" << endl;
}

filtrer_a_faire(vector<tache> &t)
{
    for (auto &ta :t)
    {
        if ta.etat==false;
        cout<<ta.nom<<" a faire "<<endl;
    }
}

int main()
{
    cout<<"bienvenu dans le programme to do list"<<endl<<"vous pouvez "<<endl;
    cout<<"1. Crée une tache , 2. Afficher une tache , 3. Terminer une tache , 4. Montrer ceux qui reste , 5. QUITTER"<<endl;
    int choix;
    vector <tache> t;
    tache temp;
    bool fin=false;
    do
    {
        cout<<"Veuillez choisir"<<endl;
        cin>>choix;
        switch(choix)
        {
            case 1 :
            remplir(temp);
            t.push_back(temp);
            break;

             case 2 :
            affiche(temp);
            break;

             case 3 :
            terminer(temp);
            break;

            case 4 :
            filtrer_a_faire(t);
            break;

            case 5 :
            fin=true;
            break;
        }
    } while (fin==false);

    return 0;
}