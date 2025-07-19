#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <time.h>
#include <vector>

using namespace std;
using namespace sf;

const int DIMW=1000;
const int MENU=0;
const int JEU=1;

/*
//on repars de 0 , sur un nouveau projet

//ouvrir une fenetre et faire apparaitre un cercle au milieu de la fenetre

on va faire des intereactions avec la souris , si clique alors cercle devient rouge

*/

struct Cercle
{
    float r;
    float x , y ;
    float vx , vy;
};

Cercle ajoute_cercle()
{
    Cercle c;
    c.x=rand()%900;
    c.y=rand()%900;
    c.r=30 + rand()% 50;  
    float a=rand()%100;
    float b =rand()%100;
    c.vx=a/10000;
    c.vy=b/10000;
    return c;  
}



int main()
{

    vector <Cercle> c;
    for(int i=0;i<5;i+=1)
    {
        c.push_back(ajoute_cercle());
    }

    srand(time(NULL));
    bool estRouge=false;
    int score=0;
    sf::Clock chrono;
    bool fin=false;
    int highscore=0;
    sf::Clock chronobravo;
    bool affichebravo = false;
    bool etat=true;



    RenderWindow window(VideoMode(DIMW,DIMW),"nouveau projet");

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"error"<<endl;
    }

    Text txtscore;
    txtscore.setFont(font);
    txtscore.setCharacterSize(20);
    txtscore.setFillColor(Color::Red);
    txtscore.setPosition(10,900);

    Text txttemps;
    txttemps.setFont(font);
    txttemps.setCharacterSize(20);
    txttemps.setFillColor(Color::Red);
    txttemps.setPosition(890,10);

    Text txtfin;
    txtfin.setFont(font);
    txtfin.setCharacterSize(20);
    txtfin.setFillColor(Color::Red);
    txtfin.setPosition(400,400);

    Text bravo;
    bravo.setFont(font);
    bravo.setCharacterSize(20);
    bravo.setFillColor(Color::Red);
    bravo.setPosition(400,400);

    float jouerX=500 , jouerY=600 , jouerl=100 , jouerh=100;
    RectangleShape boutonJouer(Vector2f(jouerl,jouerh));
    boutonJouer.setFillColor(Color(100,100,100));
    boutonJouer.setPosition(jouerX,jouerY);
    Text txtJouer("JOUER " , font , 20);
    txtJouer.setPosition(jouerX-jouerl/2,jouerY-jouerh/2);

    float quitterX=500 , quitterY=700 , quitterl=100 , quitterh=100;
    RectangleShape boutonQuitter(Vector2f(quitterl,quitterh));
    boutonQuitter.setFillColor(Color(200,200,200));
    boutonQuitter.setPosition(quitterX-quitterl/2,quitterY-quitterh/2);
    Text txtQuitter("Quitter " , font , 20);
    txtQuitter.setPosition(480,680);


    while(window.isOpen())
    {
        window.clear(Color(70,90,17));
        Event event;

        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }

            if(etat==true && event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left )
            {
                float sourisX=event.mouseButton.x , sourisY=event.mouseButton.y;
                if(sourisX>=jouerX && sourisX <=jouerX+jouerl && sourisY>=jouerY && sourisY<=jouerY + jouerh)
                {
                    etat=false;
                }

            }

            if(etat==true && event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left )
            {
                float sourisX=event.mouseButton.x , sourisY=event.mouseButton.y;
                if(sourisX>=quitterX && sourisX <=quitterX+quitterl && sourisY>=quitterY && sourisY<=quitterY + quitterh)
                {
                    window.close();
                }

            }
            if(event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                for(int i=0;i<c.size();i+=1)
                {
                float mx=event.mouseButton.x ;
                float my=event.mouseButton.y ;
                float dist = sqrt(pow(mx-c[i].x,2)+ pow(my-c[i].y,2));
                if(dist<=c[i].r)
                {
                    score+=1;
                    estRouge=true;
                    c[i].x=rand()%850;
                    c[i].y=rand()%850;
                    c[i].r=30 + rand()% 50;
                    float a=rand()%100;
                    float b =rand()%100;
                    c[i].vx=a/10000 * (rand()%2 == 0 ? 1 : -1);
                    c[i].vy=b/10000 * (rand()%2 == 0 ? 1 : -1);
                    affichebravo=true;
                    chronobravo.restart();
                }
                }

            }
            if(Keyboard::isKeyPressed(Keyboard::B))
            {
                for(int i=0;i<c.size();i++)
                {
                estRouge=false;
                c[i].x=500;
                c[i].y=500;
                }
            }



        }


        if(etat==true)
        {

            window.clear();
            window.draw(boutonJouer);
            window.draw(boutonQuitter);
            window.draw(txtJouer);
            window.draw(txtQuitter);  
            window.display(); 
        }














        if(etat==false)
        {
        float temps=chrono.getElapsedTime().asSeconds();
        float tempsbravo=chronobravo.getElapsedTime().asSeconds();

        if(fin==false && temps>30)
        {
            fin=true;
            if(score>highscore)
            {
                highscore=score;
            }
        }

        if(fin==false)
        {
            txttemps.setString("temps : " + to_string(int(30-temps)));
            txtscore.setString("score :" + to_string(int(score)));
            
            for(int i=0;i<c.size();i++)
            {
            CircleShape shape(c[i].r);
            shape.setRadius(c[i].r);
            shape.setFillColor(Color(0,0,255));
            if(estRouge==true)
            {
                shape.setFillColor(Color(255,0,0));
            }


            c[i].x+=c[i].vx;
            c[i].y+=c[i].vy;

            if(c[i].x-c[i].r <0 || c[i].x+c[i].r>1000 || c[i].y-c[i].r<0 || c[i].y+c[i].r >1000)
            {
                c[i].vx=-c[i].vx;
                c[i].vy=-c[i].vy;
            }

            shape.setPosition(c[i].x-c[i].r,c[i].y-c[i].r);
            window.draw(shape);
            }
        
            if(affichebravo==true)
            {
                bravo.setString("BRAVO");
                window.draw(bravo);
                if(tempsbravo>1)
                {
                    affichebravo=false;
                }
            }
            

            window.draw(txttemps);
            window.draw(txtscore);
        }

        

        if(fin==true)
        {
            window.clear();
            txtfin.setString("GAME OVER \n score : " + to_string(int(score)) + " \n highscore : " + to_string(int(highscore)) );
            window.draw(txtfin);
            if(Keyboard::isKeyPressed(Keyboard::R))
            {
                chrono.restart();
                score=0;
                fin=false;
                c.clear();
                for(int i=0;i<5;i++)
                {
                    c.push_back(ajoute_cercle());
                }
            }

        }
        
        window.display();
        }
    }
    return 0;
}