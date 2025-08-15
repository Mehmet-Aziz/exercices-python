#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>
using namespace std;


void afficher_bonjour()
{
    cout<<"Bonjour"<<endl;
}


void prenom_et_age()
{
    cout<<"Quelle est ton prenom ainsi que ton age ?"<<endl;
    string prenom;
    cin>>prenom;
    cout<<endl;
    float age;
    cin>>age;
    cout<<"Ton prenom est "<<prenom<<" et tu as "<<age<<" ans"<<endl;
}

void affiche_nombre()
{
    cout<<"quelle nombre veux tu choisir et affiché ?"<<endl;
    float nombre;
    cin>>nombre;
    cout<<"tu as choisis le nombre : "<<nombre<<endl;
}

void somme()
{
    float nb1 , nb2;
    cout<<"tu veux sommer quel nombre ?"<<endl<<"entre ton premier nombre"<<endl;
    cin>>nb1;
    cout<<"entre ton deuxieme nombre"<<endl;
    cin>>nb2;
    cout<<"La somme de "<<nb1<<" + "<<nb2<<" donne : "<<nb1+nb2<<endl;
}

void aire_d_un_rectangle()
{
    float longueur , largeur;
    cout<<"pour calculer l'aire d'un rectangle , donner la longueur "<<endl;
    cin>>longueur;
    cout<<"maintenant la largeur"<<endl;
    cin>>largeur;
    cout<<"voici l'air : "<<longueur*largeur<<endl;
}

void km_to_miles()
{
    float km , miles=0.621;
    cout<<"combien de km tu veux convertir en miles ?"<<endl;
    cin>>km;
    cout<<"tu as "<<km*miles<<" miles"<<endl;
}

void perimetre_cercle()
{
    float r;
    cout<<"quelle est le rayon du cercle et je te donne son perimetre en cm"<<endl;
    cin>>r;
    cout<<"le perimetre est "<<2*3.14*r<<" cm"<<endl;
}

void positif_negatif()
{
float nb;
cout<<"donne un nombre et je te dis si il est negatif ou positif"<<endl;
cin>>nb;
if(nb>=0)
{
    cout<<nb<<" est un nombre positif"<<endl;
}
else
{
    cout<<nb<<" est un nombre negatif"<<endl;
}
}

void pair_impair()
{
    int nb;
    cout<<"choisis un nombre et je te dis si il est pair ou impair"<<endl;
    cin>>nb;
    if(nb%2==0)
    {
        cout<<nb<<" est pair"<<endl;
    }
    else
    {
        cout<<nb<<" est impair"<<endl;
    }
}

void affiche_un_a_dix()
{
    for(int i=1 ; i<11;i+=1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}


void moyennes()
{
float a , b , c;
cout<<"on va faire la moyenne de 3 nombres donne le nombre 1 :"<<endl;
cin>>a;
cout<<"maintenant le nombre 2 :"<<endl;
cin>>b;
cout<<"et pour finir le nombre 3 :"<<endl;
cin>>c;
cout<<"la moyenne est : "<<(a+b+c)/3<<endl;
}

void multiplication()
{
    float nb;
    cout<<"quelle table veux tu afficher ?"<<endl;
    cin>>nb;
    for(int i=0;i<11;i++)
    {
        cout<<nb<<" * "<<i<<" = "<<nb*i<<endl;
    }
    cout<<endl;
}

void countdown()
{
    for(int i=10;i>=0;i--)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void factorielle()
{
    int n;
    int somme=1;
    cout<<"tu veux la factorielle de combien ?"<<endl;
    cin>>n;
    if(n==0)
    {
        cout<<"factorielle de 0 c'est 1"<<endl;
    }
    if(n>0)
    {
        for(int i=1;i<=n;i++)
        {
            somme*=i;
        }
        cout<<"factorielle de "<<n<<" est "<<somme<<endl;
    }
}

void divisible_par_trois_et_cinq()
{
    int nb;
    cout<<"verifions si ton nombre est divisible par 3 et par 5 "<<endl;
    cin>>nb;
    if(nb%3==0 && nb%5==0)
    {
        cout<<"bravo , c'est divisible par 3 et 5"<<endl;
    }
    else
    {
        cout<<"ça ne l'est pas"<<endl;
    }
}

void le_plus_grand()
{
    float a , b ,c;
    cout<<"saisis 3 nombres et je te dis lequel et le plus grand , nombre 1 ?"<<endl;
    cin>>a;
    cout<<"nombre 2?"<<endl;
    cin>>b;
    cout<<"nombre 3?"<<endl;
    cin>>c;
    if((a>b)&&(a>c))
    {
        if(b>c)
        {
            cout<<"Le plus grand est "<<a<<" suivi de "<<b<<" ainsi que "<<c<<endl;
        }
        else
        {
            cout<<"Le plus grand est "<<a<<" suivi de "<<c<<" ainsi que "<<b<<endl;
        }
    }
    if((b>a)&&(b>c))
    {
        if(a>c)
        {
            cout<<"Le plus grand est "<<b<<" suivi de "<<a<<" ainsi que "<<c<<endl;
        }
        else
        {
            cout<<"Le plus grand est "<<b<<" suivi de "<<c<<" ainsi que "<<a<<endl;
        }
    }
    if((c>b)&&(c>a))
    {
        if(a>b)
        {
            cout<<"Le plus grand est "<<c<<" suivi de "<<a<<" ainsi que "<<b<<endl;
        }
        else
        {
            cout<<"Le plus grand est "<<c<<" suivi de "<<b<<" ainsi que "<<a<<endl;
        }
    }
}

void affiche_cinq_fois()
{
    string mot;
    cout<<"quelle mot veux tu afficher 5 fois ?"<<endl;
    cin>>mot;
    for(int i=0;i<5;i+=1)
    {
        cout<<mot<<" ";
    }
    cout<<endl;
}

void espace()
{
    string mot;
    cout<<"quelle est ton mot ?"<<endl;
    cin>>mot;
    for(int i=0;i<mot.length();i+=1)
    {
        cout<<mot[i]<<" ";
    }
    cout<<endl;
}

void longueur_mot()
{
    string mot;
    cout<<"quelle est ton mot ?"<<endl;
    cin>>mot;
    int somme=0;
    for(int i=0;i<mot.length();i+=1)
    {
        somme+=1;
    }
    cout<<"voici la longueur du mot "<<somme<<"ou bien avec la fonction : "<<mot.length()<<endl;
}


void devine()
{
    int a=rand()%(10-1+1)+1;
    cout<<"quelle est le nombre ?"<<endl;
    int choix;
    do
    {
    cin>>choix;
    } while (choix!=a);
    cout<<"Bravo , tu as trouvé"<<endl;
}

void calculatrice()
{
    float a , b;
    char choix;
    bool fin=false;
    do
    {
        cout<<"pour quitter , choisis dans l'opperande '1'"<<endl;
        cout<<"choisis ta valeur"<<endl;
        cin>>a;
        cout<<"choisis l'opperande"<<endl;
        cin>>choix;
        cout<<"choisis ta deuxieme valeur"<<endl;
        cin>>b;
        switch (choix)
        {
            case '1' : fin=true; break;
            case '+' : cout<<a+b<<endl;break;
            case '*' : cout<<a*b<<endl;break;
            case '-' : cout<<a-b<<endl;break;
            case '/' :
            if(b!=0)
            {
                cout<<a/b<<endl;
            }
            else
            {
                cout<<"error"<<endl;
            }
        }

    }
    while(fin==false);
}

void imc()
{
    float poids , taille;
    cout<<"quelle est le poids ?"<<endl;
    cin>>poids;
    cout<<"quelle est la taille ?"<<endl;
    cin>>taille;
    cout<<"l'imc est "<<poids/(taille*taille)<<endl;
}

void multiple_de_sept()
{
    for(int i=7;i<=100;i+=1)
    {
        if(i%7==0)
        {
            cout<<i<<" est un multiple de 7"<<endl;
        }
    }
    cout<<endl;
}

void palindrome()
{
string mot , tom;
cout<<"quelle est ton mot ?"<<endl;
cin>>mot;
tom.resize(mot.length());
for(int i=0;i<mot.length();i+=1)
{
    tom[i]=mot[mot.length()-1-i];
}
if(mot==tom)
{
    cout<<mot<<" est un palindrome"<<endl;
}
else
{
    cout<<"ce n'est pas un palindrome"<<endl;
}
}

void plus_ou_moins()
{
    int essai=0;
    bool fin=false;
    int a=rand()% 100 +1;
    int nb;
    do
    {
    cin>>nb;
    essai+=1;
    if(nb==a)
    {
        fin=true;
    }
    if(nb<a)
    {
        cout<<"trop petit"<<endl;
    }
    else if (nb>a)
    {
        cout<<"trop grand"<<endl;
    }
    
    } while (fin==false && essai<10);
    if(essai<10)
    {
        cout<<"bravo , tu as reussi en moins de 10 essais"<<endl;
    }
    
}

void somme_des_n()
{
    float somme=0;
    float n;
    cout<<"tu veux jusqua quelle nombre ta somme ?"<<endl;
    cin>>n;
    for(int i=0;i<=n;i+=1)
    {
        somme+=i;
    }
    cout<<"voici la somme : "<<somme<<endl;
}

void fibonacci()
{
    int u0=1;
    int u1=1;
    int un;
    int n;
    cout<<"tu veux quelle terme de la suite de fibonacci ?"<<endl;
    cin>>n;
    if(n==0 || n==1)
    {
        cout<<"le terme demandé donne 1"<<endl;
    }

    for(int i=2;i<n;i+=1)
    {
        un=u0+u1;
        u0=u1;
        u1=un;
    }
    cout<<"le terme demandé donne "<<un<<endl;
}

void boucler()
{
    string mot;
    do
    {
        cout<<"tu dois ecrire    stop     pour que cela s'arrete "<<endl;
        cin>>mot;
    } while (mot!="stop");
    
}

void menu()
{
    int choix;
    bool fin=false;
    cout<<"bienvenu sur le menu , tu as la possibilite de faire plusieurs chose . Tape le nombre pour y avoir acces"<<endl;
    cout<<"0.quitter, 1.Bonjour, 2.prenom_age, 3.affiche_nombre, 4.somme, 5.aire_rectangle, 6.km_to_miles, 7.perimetre_cercle, 8.positif_negatif, 9.pair_impair, 10.1a10,"<<endl;
    cout<<"11.moyenne, 12.multiplication, 13.countdown, 14.factorielle, 15.divisible 3 et 5, 16.le plus grand, 17.affiche5fois, 18.espace, 19.longeurmot, 20.devine "<<endl;
    cout<<"21.calculatrice, 22.IMC, 23.multiple de 7, 24.palindrome, 25.plus ou moins, 26.somme des n, 27. fibonacci, 28. boucler "<<endl;
    cout<<"29. TOUT"<<endl;
    do
    {
    cin>>choix;
    switch (choix)
    {
        case 0: fin=true; break;
        case 1: afficher_bonjour(); break;
        case 2: prenom_et_age();break;
        case 3: affiche_nombre();break;
        case 4: somme();break;
        case 5: aire_d_un_rectangle();break;
        case 6:km_to_miles();break;
        case 7:perimetre_cercle();break;
        case 8:positif_negatif();break;
        case 9:pair_impair();break;
        case 10: affiche_un_a_dix();break;
        case 11: moyennes();break;
        case 12: multiplication();break;
        case 14:factorielle();break;
        case 13 :countdown();break;
        case 15: divisible_par_trois_et_cinq();break;
        case 16 : le_plus_grand();break;
        case 17:affiche_cinq_fois();break;
        case 18: espace();break;
        case 19:longueur_mot();break;
        case 20: devine();break;
        case 21: calculatrice();break;
        case 22 :imc();break;
        case 23:multiple_de_sept();break;
        case 24: palindrome();break;
        case 25: plus_ou_moins();break;
        case 26:somme_des_n();break;
        case 27:fibonacci();break;
        case 28:boucler();break;
 
        case 29:
        afficher_bonjour();
        prenom_et_age();
        affiche_nombre();
        somme();
        aire_d_un_rectangle();
        km_to_miles();
        perimetre_cercle();
        positif_negatif();
        pair_impair();
        affiche_un_a_dix();
        moyennes();
        multiplication();
        factorielle();
        countdown();
        divisible_par_trois_et_cinq();
        le_plus_grand();
        affiche_cinq_fois();
        espace();
        longueur_mot();
        devine();
        calculatrice();
        imc();
        multiple_de_sept();
        palindrome();
        plus_ou_moins();
        somme_des_n();
        fibonacci();
        boucler();

        default : cout<<"erreur"<<endl;fin=true;break;
    }
    } while (fin==false);
    
}

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}