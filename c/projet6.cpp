#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <ctime>

using namespace std;

/*
🏆 Projet 6 : Gestionnaire de Carnet d’Adresses Évolué

Fonctionnalités à coder :

    Ajouter un contact

        Demander prénom, nom, téléphone, email, adresse postale, (optionnel : date d’anniversaire)

    Afficher tous les contacts (bien présentés, numérotés)

    Rechercher un contact

        Par nom OU par numéro de téléphone

        Afficher tous les résultats correspondants

    Modifier un contact

        Rechercher un contact (par nom ou numéro)

        Proposer de modifier chaque champ

    Supprimer un contact

        Par nom ou par index (si plusieurs du même nom, demander confirmation)

    Trier les contacts

        Par nom croissant/décroissant

        Par prénom ou par date d’anniversaire (si renseignée)

    Afficher les anniversaires du mois courant

    Exporter les contacts dans un fichier texte (bonus mais formateur)

    Menu console clair, bouclé, propre, avec gestion des erreurs
*/

struct contact
{
    string prenom;
    string nom;
    double telephone;
    string email;
    double postale;
    string anniversaire;
};

void ajouter(vector <contact> &c)
{
    contact con;
    cout<<endl<<"prenom ? "<<endl;
    cin>>con.prenom;
    cout<<"nom ?"<<endl;
    cin>>con.nom;
    cout<<"telephone ? "<<endl;
    cin>>con.telephone;
    cout<<"email ? "<<endl;
    cin>>con.email;
    cout<<"code postale ?"<<endl;
    cin>>con.postale;
    cout<<"anniversaire ?"<<endl;
    cin>>con.anniversaire;
    c.push_back(con);
}

void afficher(vector <contact> &c)
{
    for(int i=0 ;i<c.size() ; i+=1)
    {
    cout<<endl<<"prenom :"<<endl<<c[i].prenom<<endl<<"nom :"<<endl<<c[i].nom<<endl<<"tel :"<<endl<<c[i].telephone<<endl<<"email :"<<endl;
    cout<<c[i].email<<endl<<"code postale :"<<endl<<c[i].postale<<endl<<"anniversaire :"<<endl<<c[i].anniversaire<<endl;
    }
}

void rechercher(vector <contact> &c)
{
    int choix;
    string nom;
    double num;
    cout<<endl<<"tu recherche par   1.Nom ou 2.Numero"<<endl;
    cin>>choix;
    if (choix==1)
    {
        cout<<"tape le nom"<<endl;
        cin>>nom;
        for(int i=0;i<c.size();i++)
        {
            if(c[i].nom==nom)
            {
            cout<<endl<<"prenom :"<<endl<<c[i].prenom<<endl<<"nom :"<<endl<<c[i].nom<<endl<<"tel :"<<endl<<c[i].telephone<<endl;
            cout<<"email :"<<endl;
            cout<<c[i].email<<endl<<"code postale :"<<endl<<c[i].postale<<endl<<"anniversaire :"<<endl<<c[i].anniversaire<<endl;
            }
        }
    }
    
     if (choix==2)
    {
        cout<<"tape le numero"<<endl;
        cin>>num;
        for(int i=0;i<c.size();i++)
        {
            if(c[i].telephone==num)
            {
            cout<<endl<<"prenom :"<<endl<<c[i].prenom<<endl<<"nom :"<<endl<<c[i].nom<<endl<<"tel :"<<endl<<c[i].telephone<<endl;
            cout<<"email :"<<endl;
            cout<<c[i].email<<endl<<"code postale :"<<endl<<c[i].postale<<endl<<"anniversaire :"<<endl<<c[i].anniversaire<<endl;
            }
        }
    }

}

void modifier(vector <contact> &c)
{
    int choix ,choix1;
    string nom;
    double num;
    bool fin=false;
    cout<<endl<<"tu modifie par   1.Nom ou 2.Numero"<<endl;
    cin>>choix;
    if (choix==1)
    {
        cout<<"tape le nom"<<endl;
        cin>>nom;
        for(int i=0;i<c.size();i++)
        {
            if(c[i].nom==nom)
            {
            do
            {
                cout<<endl<<"0.QUITTER , 1.prenom , 2.nom , 3.tel , 4.email , 5.code postale , 6.anniversaire"<<endl;
                cout<<"quelle champs tu veux modifier ?"<<endl;
                cin>>choix1;
                switch (choix1)
                {
                case 0 :
                fin=true;
                break;
                
                case 1 :
                cin>>c[i].prenom;
                break;
                
                case 2 :
                cin>>c[i].nom;
                break;

                case 3 :
                cin>>c[i].telephone;
                break;

                case 4 :
                cin>>c[i].email;
                break;

                case 5 :
                cin>>c[i].postale;
                break;
                
                case 6 :
                cin>>c[i].anniversaire;

                default:
                fin=true;
                break;
                }
            } while (fin==false);
            
            }
        }
    }
    
     if (choix==2)
    {
        cout<<"tape le numero"<<endl;
        cin>>num;
        for(int i=0;i<c.size();i++)
        {
            do
            {
                cout<<endl<<"0.QUITTER , 1.prenom , 2.nom , 3.tel , 4.email , 5.code postale , 6.anniversaire"<<endl;
                cout<<"quelle champs tu veux modifier ?"<<endl;
                cin>>choix1;
                switch (choix1)
                {
                case 0 :
                fin=true;
                break;
                
                case 1 :
                cin>>c[i].prenom;
                break;
                
                case 2 :
                cin>>c[i].nom;
                break;

                case 3 :
                cin>>c[i].telephone;
                break;

                case 4 :
                cin>>c[i].email;
                break;

                case 5 :
                cin>>c[i].postale;
                break;
                
                case 6 :
                cin>>c[i].anniversaire;

                default:
                fin=true;
                break;
                }
            } while (fin==false);
            
            
            
        }
    }
}

void supprimer(vector <contact> &c)
{
    int choix , in;
    string nom;
    cout<<"tu veux supprimer un contact par     1.nom ou 2.indice ?"<<endl;
    cin>>choix;
    if(choix==1)
    {
        cin>>nom;
        for(int i=0;i<c.size();i+=1)
        {
            if(c[i].nom==nom)
            {
                c.erase(c.begin()+i);
            }
        }
    }
    
    if(choix==2)
    {
        cin>>in;
        c.erase(c.begin()+in);
    }
}

void trier(vector<contact> &c)
{
    cout<<endl<<"par ordre   1.croissant ou 2.decroissant ?"<<endl;
    int choix;
    cin>>choix;
    if(choix==1)
    {
        sort(c.begin(),c.end() ,[](contact &a , contact &b)
        {
            return a.nom<b.nom;
        });

    }

    if(choix==2)
    {
        sort(c.begin(),c.end() ,[](contact &a , contact &b)
        {
            return a.nom>b.nom;
        });

    }

    cout<<endl<<"tu veux trier par    1.prenom ou 2.anniversaire"<<endl;
    cin>>choix;
    if(choix==1)
    {
        sort(c.begin(),c.end(),[](contact &a , contact &b)
    {
        return a.prenom<b.prenom;
    });
    }

     if(choix==2)
    {
        sort(c.begin(),c.end(),[](contact &a , contact &b)
    {
        return a.anniversaire<b.anniversaire;
    });
    }

}

void afficher_anniv(vector <contact> &c)
{
    cout<<endl<<"quelle est le mois actuellement ?"<<endl;
    string mois;
    cin>>mois;
    for(int i=0;i<c.size();i+=1)
    {
    if(mois[0]==c[i].anniversaire[3] && mois[1]==c[i].anniversaire[4])
    {
        cout<<c[i].prenom<<endl<<c[i].nom;
    }
    }
}

void menu(vector <contact> &c)
{
    cout<<"choisis le nombre d'ajout"<<endl;
    int nombre;
    cin>>nombre;
    for(int i=0;i<nombre;i+=1)
    {
        ajouter(c);
    }
    afficher(c);
    rechercher(c);
    modifier(c);
    supprimer(c);
    afficher_anniv(c);
}

int main()
{
    vector <contact> c;
   menu(c);
    return 0;
}