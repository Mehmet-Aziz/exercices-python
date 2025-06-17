#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
🎯 Projet 5 – Gestionnaire de dépenses avancé
Sujet

Construis un programme console en C++ qui permet de gérer tes dépenses sur plusieurs mois (ou catégories)
, avec les fonctionnalités suivantes (plus costaudes que la to-do list) :
Fonctionnalités demandées

1. Ajouter une dépense

    Saisir :

        Description (ex : “Courses”)

        Montant (€)

        Catégorie (ex : “Alimentation”, “Loisirs”, “Transports”…)

        Date (JJ/MM/AAAA)

2. Afficher toutes les dépenses

    Afficher sous forme de liste : description, montant, catégorie, date.

3. Supprimer une dépense

    Par indice ou description

4. Modifier une dépense

    Changer un ou plusieurs champs

5. Total des dépenses

    Afficher la somme totale dépensée, et aussi le total par catégorie

6. Filtrer/afficher

    Afficher seulement les dépenses d’une catégorie ou d’une date précise

7. Trier

    Par montant croissant/décroissant

    Par date (si tu veux aller plus loin !)

8. Quitter le programme
*/

struct depense
{
    string nom;
    string description;
    float prix;
    string categorie;
    string date;
};

void ajouter(vector <depense> &d)
{
    depense temp;
    cout<<"quelle est le nom ?:"<<endl;
    getline(cin,temp.nom);
    cout<<"quelle est la description ?"<<endl;
    getline(cin,temp.description);
    cout<<"quelle est le prix"<<endl;
    cin>>temp.prix;
    cin.ignore();
    cout << "Quelle est la catégorie ?" << endl;
    getline(cin, temp.categorie);
    cout<<"quelle est la date ?"<<endl;
    getline(cin,temp.date);
    d.push_back(temp);

}

void affiche(vector <depense> &d)
{
     cout<<"voici toute les depenses"<<endl<<endl;
    for(int i=0;i<d.size();i++)
    {
        cout<<"nom :     "<<d[i].nom<<endl;
        cout<<"description :    "<<d[i].description<<endl;
        cout<<"prix :   "<<d[i].prix<<endl;
        cout<<"catgeorie :   "<<d[i].categorie<<endl;
        cout<<"date :   "<<d[i].date<<endl<<endl; 
    }
}

void supprimer(vector <depense> &d)
{
    int choix, indice;
    string nom;
    cout<<"supprimer une depense par 1. indice , 2. nom"<<endl;
    cin>>choix;
    if(choix==1)
    {
        cout<<"quelle est l'indice ?"<<endl;
        cin>>indice;
        d.erase(d.begin() + indice);
    }
    else if (choix==2)
    {
        cout<<"quelle est le nom ?"<<endl;
        getline(cin,nom);
        for(int i=0;i<d.size();i++)
        {
            if(nom==d[i].nom)
            {
                d.erase(d.begin()+i);
            }
        }
    }
}

void modifier(vector<depense> &d)
{
    bool fin=false;
    string nom, des , cate , date , dep;
    float prix;
    do
    {
    int choix;
    cout<<"qu'est ce que tu veux changer ?"<<endl;
    cout<<"0.rien ,1.nom , 2.description , 3.prix , 4.categorie , 5.date"<<endl;
    cin>>choix;
    cout<<"met le nom de la depense a changer"<<endl;
    cin>>dep;
    switch(choix)
    {
        case 0:
        fin=true;
        break;

        case 1 :
        for(int i=0;i<d.size();i+=1)
        {
            if(dep==d[i].nom)
            {
                cout<<"met son nouveau nom"<<endl;
                cin>>d[i].nom;
                break;
            }
        }
        break;


        case 2 :
        for(int i=0;i<d.size();i+=1)
        {
            if(dep==d[i].nom)
            {
                cout<<"met sa nouvelle des"<<endl;
                cin>>d[i].description;
                break;
            }
        }
        break;


        case 3 :
        for(int i=0;i<d.size();i+=1)
        {
            if(dep==d[i].nom)
            {
                cout<<"met son nouveau prix"<<endl;
                cin>>d[i].prix;
                break;
            }
        }
        break;

        case 4:
        for(int i=0;i<d.size();i+=1)
        {
            if(dep==d[i].nom)
            {
                cout<<"met sa nouvelle"<<endl;
                cin>>d[i].categorie;
                break;
            }
        }
        break;

        case 5 :
        for(int i=0;i<d.size();i+=1)
        {
            if(dep==d[i].nom)
            {
                cout<<"met sa nouvelle date"<<endl;
                cin>>d[i].date;
                break;
            }
        }
        break;

        default :
        cout<<"error"<<endl;
        fin=true;
        break;


    }
    } while (fin==false);
}

void total(vector <depense> &d)
{
    int somme=0;
    for(int i=0;i<d.size();i++)
    {
        somme+=d[i].prix;
    }

    cout<<endl<<"voici le total  "<<somme<<endl;
}

//pas pu faire par categorie donc pas de 6

int main()
{
    vector <depense> d;
    ajouter(d);
    affiche(d);
    supprimer(d);
    modifier(d);
    total(d);

    return 0;
}