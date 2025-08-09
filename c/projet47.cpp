#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

void positif()
{
    float nombre;
    cout<<"donne un nombre :"<<endl;
    cin>>nombre;
    if(nombre==0)
    {
        cout<<"ton nombre est nul"<<endl;
    }
    else if(nombre>0)
    {
        cout<<"ton nombre est positif"<<endl;
    }
    else
    {
        cout<<"ton nombre est negatif"<<endl;
    }
}

void age()
{
    float age;
    cout<<"quelle est ton age"<<endl;
    cin>>age;
    if(age<18)
    {
        cout<<"tu es mineur"<<endl;
    }
    if(age>=18 && age<65)
    {
        cout<<"tu es majeur"<<endl;
    }
    if(age>=65)
    {
        cout<<"tu es retraite"<<endl;
    }
}

void le_plus_grand()
{
float a , b;
cout<<"donne deux nombes et je te dirais le plus grand"<<endl;
cin>>a>>b;
if(a>b)
{
cout<<a <<" est le plus grand"<<endl;
}
else if(b==a)
{
    cout<<"ils sont egaux"<<endl;
}
else
{
    cout<<b<<" est le plus grand"<<endl;
}

}

void pair_impair()
{
    int nombre;
    cout<<"Donne ton nombre : "<<endl;
    cin>>nombre;
    if(nombre %2==0)
    {
        cout<<"votre nombre est pair"<<endl;
    }
    else
    {
        cout<<"votre nombre est impair"<<endl;
    }

}

void affiche_for()
{
    for(int i=1;i<=10;i+=1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void affiche_while_pair()
{
    int i=0;
    while(i<=20)
    {
        cout<<i<<" ";
        i+=2;
    }
}

void for_cinq()
{
    string mot;
    cout<<endl<<"quelle est le mot que tu veux afficher 5 fois ?"<<endl;
    cin>>mot;
    for(int i=0;i<5;i+=1)
    {
        cout<<mot<<endl;
    }

}

void compte_a_rebours()
{
    for(int i=10;i>0;i-=1)
    {
        cout<<i<<"";
    }
    cout<<endl;
}

void mot_espace()
{
    string mot;
    cout<<"quelle est le mot ?"<<endl;
    cin>>mot;
    for(int i=0;i<mot.size();i+=1)
    {
        cout<<mot[i]<<" ";
    }
    cout<<endl;
}

void multiplication()
{
    int nombre;
    cout<<"tu veux la table de quelle nombre ?"<<endl;
    cin>>nombre;
    for(int i=0;i<20;i++)
    {
        cout<<i*nombre << " ";
    }
    cout<<endl;
}

void entre_un_et_dix()
{
    float nbr;

    do
    {
        cout<<"entre 1 et 10 inclus"<<endl;
        cin>>nbr;
    } while (nbr<1 || nbr>10);
    cout<<"ta choisis le nombe "<<nbr<<endl;
    
}

void devine()
{
    float a=rand()% (100-1+1)+1;
    float chance=10;
    float nombre;
    do
    {
        cout<<"quelle est le nombre ? il te reste "<<chance<<"chance/s"<<endl;
        cin>>nombre;
        if(nombre>a)
        {
            cout<<"trop garnd"<<endl;
        }
        if(nombre<a)
        {
            cout<<"trop petit"<<endl;
        }
        chance-=1;
    }
    while(nombre!=a && chance!=0);
    if(chance==0)
    {
        cout<<"tu as perdu , le nombre etait "<<a<<endl;
    }
    if(a==nombre)
    {
        cout<<"felicitation c'etait bien le nombre "<<a<<endl;
    }  

}


void multiple_de_trois()
{
    for(int i=0;i<=50;i++)
    {
        if(i%3==0)
        {
            cout<<i<<" est multiple de 3  ";
        }
    }
    cout<<endl;
}

void somme_des_entiers_n()
{
    int n;
    int sommes=0;
    cout<<"tu veux faire la somme jusqu'a quel nombre ? "<<endl;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        sommes+=i;
        cout<<i<<"eme etapes , le nombre est : "<<sommes<<endl;
    }
    cout<<endl;
}

void impair_trente()
{
    for(int i=0;i<=30;i++)
    {
        if(i%2==1)
        {
            cout<<i<<" est impair   ";
        }
    }
    cout<<endl;
}

void mot_de_passe()
{
    string mot1;
    string mot2;

    cout<<"met un mot de passe"<<endl;
    cin>>mot1;
    do
    {
        cout<<"verifie le mot de passe"<<endl;
        cin>>mot2;
    }while(mot1!=mot2);

}

void factorielle()
{
    float n;
    float prod=1;
    cout<<"donne un nombre et je te donne sa factorielle "<<endl;
    cin>>n;
    if(n!=0)
    {
    for(int i=1;i<=n;i++)
    {
        prod=prod*i;
    }
    cout<<endl;
    }
    if(n==0)
    {
        cout<<"factorielle de 0 est 1"<<endl;
    }

}

void fibonacci()
{
    float u0=1;
    float u1=1;
    float u2=2;
    float tamp;
    for(int i=0;i<10;i+=1)
    {
        cout<<"au rang"<<i<<" "<<u0<<" "<<u1<<" "<<u2;
        tamp=u2;
        u2=u1+u0;
        u0=u1;
        u1=tamp;
    }
}

void menu()
{
    cout<<"Bonjour"<<endl;
    bool finis=true;
    do
    {
        int choix;
        cout<<"choisissez la fonction que vous voulez"<<endl;
        cout<<"1.positif , 2.age, 3.le plu grand , 4.pair ou imapair , 5.afiche les 10 premiers nombres , 6.pair de 1 a 20"<<endl;
        cout<<"7.afficher un mot 5 fois , 8.compte a rebours , 9. espace entre mots , 10. multiplication d'un nombre , 11. entre 1 et 10"<<endl;
        cout<<"12.Devine , 13. multiple de 3 , 14. somme de nombre n , 15. impair jusqu'a 30 , 16.mot de passe "<<endl;
        cout<<"17.factorielle , 18.fibonacci , 19. TOUTE LES FONCTIONS , 20. QUITTER"<<endl;
        cin>>choix;
        switch (choix)
        {
            case 1 : positif();
            break;

            case 2 : age();
            break;

            case 3: le_plus_grand();
            break;

            case 4: pair_impair();
            break;

            case 5 : affiche_for();
            break;

            case 6: affiche_while_pair();
            break;

            case 7: for_cinq();
            break;

            case 8 : compte_a_rebours();
            break;

            case 9 : mot_espace();
            break;

            case 10: multiplication();
            break;

            case 11 : entre_un_et_dix();
            break;

            case 12 : devine();
            break;

            case 13: multiple_de_trois();
            break;

            case 14 : somme_des_entiers_n();
            break;

            case 15: impair_trente();
            break;

            case 16 : mot_de_passe();
            break;

            case 17 : factorielle();
            break;

            case 18 : fibonacci();
            break;

            case 19: 
            positif();
            age();
            le_plus_grand();
            pair_impair();
            affiche_for();
            affiche_while_pair();
            for_cinq();
            compte_a_rebours();
            mot_espace();
            multiplication();
            entre_un_et_dix();
            devine();
            multiple_de_trois();
            somme_des_entiers_n();
            impair_trente();
            mot_de_passe();
            factorielle();
            fibonacci();
            break;

            case 20:
            finis=false;
            break;


        
        default:
        cout<<"error"<<endl;
            break;
        }
    }
    while(finis==true);

}

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}