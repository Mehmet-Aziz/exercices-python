#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

/*
🧩 Fonctionnalités attendues :

    Ajouter une tâche

        Demander une description

        Demander une priorité (1 à 5)

        Enregistrer la date de création automatiquement (facultatif : demander à l’utilisateur)

    Afficher toutes les tâches

        Lister les tâches avec leur état (à faire / terminée), description et priorité.

    Marquer une tâche comme terminée

        Rechercher une tâche par son indice ou titre

        Modifier son état.

    Supprimer une tâche

        Par indice ou description.

    Filtrer ou trier les tâches

        Ex. : trier par priorité ou filtrer les tâches "à faire" uniquement.

    Quitter le programme
*/

struct tache
{
    string description;
    int priorite;
    bool etat;
    char date[10];
};

void ajoute_tache(tache &t)
{
    cout<<"quelle est la description ?"<<endl;
    cin>>t.description;
    cout<<"quelle est l'ordre de prorité classé de 1 à 5 inclus ?"<<endl;
    cin>>t.priorite;
    cout<<"quelle est l'etat ? 0 pour à faire sinon 1 pour terminer"<<endl;
    cin>>t.etat;
    cout<<"date ? sous format JJ/MM/AAAA"<<endl;
    for(int i=0;i<10;i++)
    {
        if((i==2)&&(i==5))
        {
            t.date[i]=='/';
        }
        else
        {
            cin>>t.date[i];
        }
    }
    cout<<endl;

}


void affiche_tache(tache t)
{
    cout<<"Voici la description :"<<endl;
    cout<<t.description<<endl;
    cout<<"Voici la priorite :"<<endl;
    cout<<t.priorite<<endl;
    cout<<"Voici l'etat :"<<endl;
    cout<<t.etat<<endl;
    cout<<"Voici la date crée :"<<endl;
    for(int i=0;i<strlen(t.date);i++)
    {
        cout<<t.date[i];
    }
    cout<<endl;
}

void terminer(bool etat)
{
    cout<<"tu as terminer ta tache , bravo"<<endl;
    etat=1;
}

void recherche(tache &t)
{
    bool oui;
    bool ouii;
    bool ouiii;
    string noom;
    cout<<"tu cherche par rapport a son indice , tape 0 non , sinon 1 oui?"<<endl;
    cin>>oui;
    if(oui==1)
    {
    cout<<"tape son indice"<<endl;
    cin>>t.priorite;
    }
    cout<<endl<<"tu cherche par description ? 0 pour non , 1 pour oui"<<endl;
    cin>>ouii;
    if(ouii==1)
    {
    cout<<"tape le nom"<<endl;
    cin>>noom;
    if(strcmp(t.description,noom)==1)
    {
        strcpy(t.description,noom);
    }
    }
    cout<<"modifiez son etat , choisis nouveau etat ? , 0 en cours , 1 finis"<<endl;
    cin>>ouiii;
    if(ouiii==1)
    {
        cin>>t.etat;
    }

}

//j'ai pas trop compris les fonctions sont groupés comment , je marrete a la;

int main()
{
    vector<tache> t;
    bool fin==0;
    do
    {
        tache temp;
        bool oui;
        ajoute_tache(temp);
        affiche_tache(temp);
        cout<<"tache terminer ? 0 pour non , 1 pour oui"<<endl;
        cin>>oui;
        if(oui==1)
        {
            terminer(temp.etat);
        }
        t.push_back(temp);
        cout<<endl<<"tu as finis ? 0 pour non , 1 pour oui"<<end;
        cin>>fin;
    } while (fin==0);
    recherche(t);
    return 0;
}