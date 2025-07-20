//projet solo pour voir de quoi suis capable

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;
using namespace sf;

const int DIMW=1000;


struct Cercle
{
    float r ;
    float x , y ;
    float vx , vy ;
};

Cercle ajoute_cercle()
{
    Cercle c;
    c.r=30+ rand()% 50;
    c.x= c.r + rand()% DIMW - (2* c.r);
    c.y= c.r + rand()% DIMW-(2*c.r);
    float a=1 +rand()% 100;
    float b= 1+rand()%100;
    c.vx=a/10000 * (rand()%2 == 0 ? 1 : -1);
    c.vy=b/10000 * (rand()%2 == 0 ? 1 : -1);
    return c;
}


int main()
{
    srand(time(NULL));
    vector <Cercle> c;
    for(int i=0;i<5;i+=1)
    {
        c.push_back(ajoute_cercle());
    }

    bool etat=false; //false = je suis sur le menu , true = dans le jeu
    RenderWindow window(VideoMode(DIMW,DIMW),"TEST SOLO");
    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"erreur"<<endl;
        return 1;
    }



    float QuitterX=DIMW/2 , QuitterY=DIMW/2 , QuitterL=100 , QuitterH=100;
    RectangleShape BoutonQuitter(Vector2f(QuitterL,QuitterH));
    BoutonQuitter.setFillColor(Color::Red);
    BoutonQuitter.setPosition(QuitterX-QuitterL/2,QuitterY-QuitterH/2);
    Text txtQuitter("QUITTER" , font , 20);
    txtQuitter.setPosition(DIMW/2 -40 , DIMW/2 -20);


    float JouerX=DIMW/2 , JouerY=DIMW/2+100 , JouerL=100 , JouerH=100;
    RectangleShape BoutonJouer(Vector2f(JouerL,JouerH));
    BoutonJouer.setFillColor(Color::Red);
    BoutonJouer.setPosition(JouerX-JouerL/2,JouerY-JouerH/2+100);
    Text txtJouer("JOUER" , font , 20);
    txtJouer.setPosition(DIMW/2 -35 , DIMW/2 +200 -20);

    Text txtscore;
    txtscore.setFont(font);
    txtscore.setFillColor(Color::Red);
    txtscore.setPosition(10,900);
    
    Text txttemps;
    txttemps.setFont(font);
    txttemps.setFillColor(Color::Red);
    txttemps.setPosition(850 , 10);

    Text txtperdu;
    txtperdu.setFont(font);
    txtperdu.setFillColor(Color::Red);
    txtperdu.setPosition(400,400);

    int score =0 , highscore=0;
    bool fin=false;
    sf::Clock chrono;

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }

            if(etat== false && event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                float sourisX=event.mouseButton.x;
                float sourisY=event.mouseButton.y;
                if(sourisX>=QuitterX-QuitterL/2 && sourisX<=QuitterX+QuitterL && sourisY>=QuitterY-QuitterH/2 && sourisY<=QuitterY+QuitterH)
                {
                    window.close();
                }
            }

            if(etat ==false && event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                float sourisX=event.mouseButton.x;
                float sourisY=event.mouseButton.y;
                if(sourisX>=JouerX-JouerL/2 && sourisX<=JouerX+JouerL && sourisY>=JouerY-JouerH/2 && sourisY<=JouerY+JouerH+100)
                {
                    etat=true;
                }
            }

            if(etat ==true && event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                for(int i=0;i<c.size();i++)
                {

                
                float sourisX=event.mouseButton.x;
                float sourisY=event.mouseButton.y;
                float dist = sqrt(pow(sourisX-c[i].x,2)+pow(sourisY-c[i].y,2));
                if(dist<c[i].r)
                {
                    score+=1;
                    c[i]=ajoute_cercle();
                    break;
                }
                }
            }

            


        }

        if(etat==false)
        {
        window.clear();
        window.draw(BoutonQuitter);
        window.draw(txtQuitter);
        window.draw(BoutonJouer);
        window.draw(txtJouer);
        }

        if(etat==true)
        {
            window.clear();

            float temps=chrono.getElapsedTime().asSeconds();

            if(fin==false && temps>30)
            {
                if(score>=highscore)
                {
                    highscore=score;
                }
                fin=true;
            }



            if(fin==false)
            {
            for(int i=0;i<c.size();i+=1)
            {
                CircleShape shape(c[i].r);
                shape.setFillColor(Color::Blue);
                shape.setPosition(c[i].x-c[i].r,c[i].y-c[i].r);
                c[i].x+=c[i].vx;
                c[i].y+=c[i].vy;
                if(c[i].x-c[i].r<0 || c[i].x+c[i].r>1000 || c[i].y-c[i].r<0 || c[i].y+c[i].r>1000)
                {
                    c[i].vx=-c[i].vx;
                    c[i].vy=-c[i].vy;
                }



                txtscore.setString("score :" + to_string(int(score)));
                txttemps.setString("temps " + to_string(int(30-temps)));
                window.draw(txttemps);
                window.draw(shape);
                window.draw(txtscore);


            }
            }

            if(fin==true)
            {
                txtperdu.setString("GAME OVER \n score : " + to_string(int(score)) + " highscore : " + to_string(int(highscore)) );
                window.draw(txtperdu);

                if(Keyboard::isKeyPressed(Keyboard::R))
                {
                    chrono.restart();
                    fin=false;
                    c.clear();
                    score=0;
                    for(int i=0;i<5;i+=1)
                    {
                        c.push_back(ajoute_cercle());
                    }
                }
            }

        }


        window.display();
    }
    
}