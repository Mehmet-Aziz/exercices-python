#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;
using namespace sf;


struct Oiseau
{
    float r;
    float x;
    float y;
    float vy;
};


void init_Oiseau(Oiseau &o)
{
    o.r=10;
    o.x=10;
    o.y=500;
    o.vy=0.005;
}

struct Tuyeau1
{
    float x , y , l , h , vx;
};

struct Tuyeau2
{
    float x , y , l , h , vx;
};

struct Piece
{
    float x , y , r , vx;
};



void init_Tuyeau1 (Tuyeau1 &t)
{
    t.x= 500;
    t.y=0;
    t.l=50;
    t.h=10+rand()%600;
    t.vx=-0.005; 
}

void init_Tuyeau2(Tuyeau2 &t2 , Tuyeau1 t1)
{
    t2.x=t1.x;
    t2.y=200+t1.h;
    t2.l=50;
    t2.h=1000-t2.y;
    t2.vx=-0.005; 

}

void init_Piece(Piece &p)
{
    p.r=10;
    p.x=500;
    p.y=rand()% 1000;
    p.vx=-0.005;
}

int main()
{
    srand(time(NULL));
    
    Oiseau o;
    init_Oiseau(o);
    vector<Tuyeau1> t1;
    vector<Tuyeau2> t2;
    vector<Piece> p;

    bool menu=0; //0 = on est sur le menu , 1 = sur le jeu 
    bool jeu=1; // 1 = en jeu sinon ° = perdu
    int score=0;
    int higsore=0;


    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cout<<"erreur"<<endl;
        return 1;
    }


    
    for(int i=0;i<9;i+=1)
    {
    Tuyeau1 t11;
    Tuyeau2 t22;
    Piece pp;
    init_Tuyeau1(t11);
    t11.x = 500 + i * 250;
    init_Tuyeau2(t22,t11);
    t1.push_back(t11);
    t2.push_back(t22);
    init_Piece(pp);
    pp.x=500+i*250;
    p.push_back(pp);
    }

    RenderWindow window(VideoMode(1000,1000),"flappy");






    CircleShape flappy(o.r);
    flappy.setFillColor(Color::Red);


            float bjouerx=500 , bjouery=300 , bjouerl=100 , bjouerh=100;
            RectangleShape bjouer(Vector2f(bjouerl,bjouerh));
            bjouer.setFillColor(Color::Red);
            

            float bquitterx=500 , bquittery=600 , bquitterl=100 , bquitterh=100;
            RectangleShape bquitter(Vector2f(bquitterl,bquitterh));
            bquitter.setFillColor(Color::Red);




    while(window.isOpen())
    {
        window.clear();
        Event event;

        while (window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }


            if(menu==0 && event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                float sourisX=event.mouseButton.x;
                float sourisY=event.mouseButton.y;
                if(sourisX>=bjouerx-bjouerl/2 && sourisX<=bjouerx+bjouerl && sourisY>=bjouery-bjouerh/2 && sourisY<=bjouery+bjouerh)
                {
                    menu=1;
                }
                if(sourisX>=bquitterx-bquitterl/2 && sourisX<=bquitterx+bquitterl && sourisY>=bquittery-bquitterh/2 && sourisY<=bquittery+bquitterh)
                {
                    window.close();
                }
            }

            


            if (menu == 1 && event.type == Event::KeyPressed && event.key.code == Keyboard::Up) 
            {
                o.vy = -0.0075;
            }
         

        }


        if(menu==0)
        {

            bquitter.setPosition(bquitterx-bquitterl/2,bquittery-bquitterh/2);
            bjouer.setPosition(bjouerx-bjouerl/2,bjouery-bjouerh/2);
            window.draw(bquitter);
            window.draw(bjouer);

        }



















       



        if(menu==1)
        {
            if(jeu==0)
            {
                window.clear();

            }


        if(jeu==1)
        {    
        o.vy+=0.0000005;
        o.y+=o.vy;
       
        if(o.y +o.r<=0)
        {
            jeu=0;

        }
         if(o.y -o.r>=1000)
        {
            jeu=0;
        }

        for(int i=0;i<t1.size();i+=1)
        {
        t1[i].x+=t1[i].vx;
        t2[i].x+=t2[i].vx;
        p[i].x+=p[i].vx;
        RectangleShape tuyeau1(Vector2f(t1[i].l,t1[i].h));
        tuyeau1.setFillColor(Color::Green);
        RectangleShape tuyeau2(Vector2f(t2[i].l,t2[i].h));
        tuyeau2.setFillColor(Color::Green);
        CircleShape piece(p[i].r);
        piece.setFillColor(Color::Yellow);




           if(t1[i].x +t1[i].l<0)
           {
                float max_x=0;
                for(int j=0;j<t1.size();j+=1)
                {
                    if(t1[j].x>max_x)
                    {
                        max_x=t1[j].x;
                    }

                    t1[i].x=max_x+150;

                    t1[i].h=10+rand()% 600;

                    t2[i].x=t1[i].x;
                    t2[i].y=200+t1[i].h;
                    t2[i].h=1000-t2[i].y;
                }
           }


        

        float gauche_oiseau   = o.x;
        float droite_oiseau   = o.x + 2 * o.r;
        float haut_oiseau     = o.y;
        float bas_oiseau      = o.y + 2 * o.r;

        float gauche_tuyau    = t1[i].x;
        float droite_tuyau    = t1[i].x + t1[i].l;
        float haut_tuyau      = t1[i].y;
        float bas_tuyau       = t1[i].y + t1[i].h;
        float gauche_tuyau2    = t2[i].x;
        float droite_tuyau2    = t2[i].x + t2[i].l;
        float haut_tuyau2      = t2[i].y;
        float bas_tuyau2       = t2[i].y + t2[i].h;

        if (!(droite_oiseau < gauche_tuyau ||
        gauche_oiseau > droite_tuyau ||
        bas_oiseau    < haut_tuyau ||
        haut_oiseau   > bas_tuyau))
        {
        jeu = 0; // Collision !
        }
        if (!(droite_oiseau < gauche_tuyau2 ||
        gauche_oiseau > droite_tuyau2 ||
        bas_oiseau    < haut_tuyau2 ||
        haut_oiseau   > bas_tuyau2))
        {
        jeu = 0; // Collision !
        }

        float dx=o.x-p[i].x;
        float dy=o.y-p[i].y;
        float dist2=dx*dx+dy*dy;
        float somme_des_r=o.r+p[i].r;
        if(dist2<somme_des_r*somme_des_r)
        {
            score+=1;
            float max_xx=0;
                for(int j=0;j<p.size();j+=1)
                {
                    if(p[j].x>max_xx)
                    {
                        max_xx=p[j].x;
                    }

                    p[i].x=max_xx+150;

                    

                    p[i].x=p[i].x;
                    p[i].y=200;
                    
                }

                if(p[i].x -p[i].r<0)
           {
                float max_x=0;
                for(int j=0;j<p.size();j+=1)
                {
                    if(p[j].x>max_x)
                    {
                        max_x=p[j].x;
                    }

                    p[i].x=max_x+150;

                    

                    p[i].x=p[i].x;
                    p[i].y=200;
                    
                }
           }
        }


        piece.setPosition(p[i].x-p[i].r,p[i].y-p[i].r);
        window.draw(piece);
        tuyeau1.setPosition(t1[i].x,t1[i].y);
        window.draw(tuyeau1);
        tuyeau2.setPosition(t2[i].x,t2[i].y);
        window.draw(tuyeau2);
        }
        flappy.setPosition(o.x-o.r,o.y-o.r);
        window.draw(flappy);
        }
        }






        window.display();
        
    }



    return 0;
}