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
    cin>>choix;
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
    cin>>choix;
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
                t.erase(t.begin()+i);
            }
        }
    }
}

void trier (vector <tache> &t)
{
    int choix;
    cout<<"tu veux trier par ordre 1.croissant ou 2.decroissant ?"<<endl;
    cin>>choix;
    if(choix==1)
    {
        int temp;
        for (int i=0;i<t.size();i+=1)
        {
            for(int j=0;j<t.size()-1;j++)
            {
                if(t[j].priorite>=t[j+1].priorite)
                {
                    temp=t[j].priorite;
                    t[j].priorite=t[j+1].priorite;
                    t[j+1].priorite=temp;
                }
            }
        }
    }
    if(choix==2)
    {
        int temp;
        for (int i=0;i<t.size();i+=1)
        {
            for(int j=0;j<t.size()-1;j++)
            {
                if(t[j].priorite<=t[j+1].priorite)
                {
                    temp=t[j].priorite;
                    t[j].priorite=t[j+1].priorite;
                    t[j+1].priorite=temp;
                }
            }
        }
    }
}

void modifier(vector <tache> &t)
{
    int choix;
    bool fin = false;
    string nom , des , date;
    int prio;
    bool eta;
    cout<<"modifier : 0. rien , 1. nom , 2. description , 3. priorite , 4. etat , 5.date"<<endl;
    cin>>choix;
    do
    {
        switch(choix)
        {
            case 0 :
            fin=true;
            break;

            case 1 :
            cout<<"met le nom a changer"<<endl;
            cin>>nom;
            for(int i=0;i<t.size();i+=1)
            {
                if(nom==t[i].nom)
                {
                    cout<<"met son nouveau nom"<<endl;
                    cin>>t[i].nom;
                }
            }
            break;

            case 2 :
            cout<<"met la description a changer"<<endl;
            cin>>des;
            for(int i=0;i<t.size();i+=1)
            {
                if(des==t[i].description)
                {
                    cout<<"met nouvelle description"<<endl;
                    cin>>t[i].description;
                }
            }
            break;

            case 4 :
            cout<<"met l'etat a changer"<<endl;
            cin>>eta;
            for(int i=0;i<t.size();i+=1)
            {
                if(eta==t[i].etat)
                {
                    cout<<"met son nouveau etat"<<endl;
                    cin>>t[i].etat;
                }
            }
            break;

            case 3 :
            cout<<"met la priorite a changer"<<endl;
            cin>>prio;
            for(int i=0;i<t.size();i+=1)
            {
                if(prio==t[i].priorite)
                {
                    cout<<"met son nouveau priorite"<<endl;
                    cin>>t[i].priorite;
                }
            }
            break;

            case 5 :
            cout<<"met la date a changer"<<endl;
            cin>>date;
            for(int i=0;i<t.size();i+=1)
            {
                if(date==t[i].date)
                {
                    cout<<"met sa nouvelle date"<<endl;
                    cin>>t[i].date;
                }
            }
            break;

            default :
            cout<<"erreur bye"<<endl;
            fin=true;
            break;
            
        }   
    }while(fin==false);
}

void a_faire(vector <tache> &t)
{
    for(int i=0;i<t.size();i+=1)
    {
        if(t[i].etat==false)
        {
            cout<<endl<<"a faire :  "<<t[i].etat;
        }
    }
}

void menu(vector <tache> &t)
{
    bool fin=false;
    int choix;
    cout<<"bienvenu sur menu"<<endl;
    do
    {
        cout<<endl<<"0. QUITTER , 1. ajouter , 2. afficher , 3.terminer , 4.supprimer , 5.trier , 6.modifier , 7. a faire "<<endl;
        cin>>choix;

        switch(choix) 
        {
            case 0 :
            fin=true;
            break;

            case 1 :
            ajouter(t);
            afficher(t);
            break;

            case 2 :
            afficher(t);
            break;

            case 3 :
            terminer(t);
            afficher(t);
            break;

            case 4 :
            supprimer(t);
            afficher(t);
            break;

            case 5 :
            trier(t);
            afficher(t);
            break;

            case 6 :
            modifier(t);
            afficher(t);  
            break;

            case 7 :
            a_faire(t);
            break;

            default :
            cout<<"erreur bye !"<<endl;
            fin=true;
            break;
        }

    } while (fin==false);
    
}

int main()
{
    vector<tache> t;
    menu(t);
    return 0;
}