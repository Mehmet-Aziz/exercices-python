#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;
using namespace sf;

struct Balle
{
    float r;
    float x , y;
    float vx , vy;
};

Balle ajoute_balle()
{
    Balle b;
    b.r=10;
    b.x=490;
    b.y=490;
    float a=1+rand()% 100;
    b.vx=a/10000 * (rand()%2 ==0 ? 1 : -1);
    float c=1+rand()% 100;
    b.vy= c / 10000 * (rand()%2 ==0 ? 1 : -1);
    return b;
}

int main()
{
    srand(time(NULL));
    Balle b=ajoute_balle();
    bool etat=false; //false = menu et true=sur le jeu

    RenderWindow window(VideoMode(1000,1000),"pong");


        Font font;
        if(!font.loadFromFile("DejaVuSans.ttf"))
        {
            cerr<<"erreur"<<endl;
            return 1;
        }


        float rect1X=0 , rect1Y=500;
        float rect1L=10 , rect1H=100;

        RectangleShape rect1 (Vector2f(rect1L,rect1H));
        rect1.setFillColor(Color::Red);


        float rect2X=990 , rect2Y=500;
        float rect2L=10 , rect2H=100;

        RectangleShape rect2 (Vector2f(rect2L,rect2H));
        rect2.setFillColor(Color::Red);
        

        CircleShape rond(b.r);
        rond.setFillColor(Color::Blue);


        float rectQuitterX=500 , rectQuitterY=500;
        float rectQuitterL=100 , rectQuitterH=100;
        RectangleShape rectQuitter(Vector2f(rectQuitterL,rectQuitterH));
        rectQuitter.setFillColor(Color::White);
        Text txtQuitter("QUITTER" , font ,20);
        txtQuitter.setFillColor(Color::Black);



        float rectJouerX=500 , rectJouerY=300;
        float rectJouerL=100 , rectJouerH=100;
        RectangleShape rectJouer(Vector2f(rectJouerL,rectJouerH));
        rectJouer.setFillColor(Color::White);
        Text txtJouer("JOUER" , font , 20);
        txtJouer.setFillColor(Color::Black);

        int score1 =0 , score2=0;

        Text txtscore1;
        txtscore1.setFont(font);
        txtscore1.setFillColor(Color::Red);
        txtscore1.setCharacterSize(15);

        Text txtscore2;
        txtscore2.setFont(font);
        txtscore2.setFillColor(Color::Red);
        txtscore2.setCharacterSize(15);







    while(window.isOpen())
    {
        window.clear();
        Event event;
        

        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }



            if(etat==false && event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                float sourisX=event.mouseButton.x , sourisY=event.mouseButton.y;
                if(sourisX>=rectQuitterX-rectQuitterL/2 && sourisX<=rectQuitterX+rectQuitterL/2 && sourisY>=rectQuitterY-rectQuitterH/2 && sourisY<=rectQuitterY+rectQuitterH/2)
                {
                    window.close();
                }
                if(sourisX>=rectJouerX-rectJouerL/2 && sourisX<=rectJouerX+rectJouerL/2 && sourisY>=rectJouerY-rectJouerH/2 && sourisY<=rectJouerY+rectJouerH/2)
                {
                    etat=true;
                }

            }


            


        if (etat==true && Keyboard::isKeyPressed(Keyboard::Up))
        {
            rect1Y-=10;
        }
        if (etat==true && Keyboard::isKeyPressed(Keyboard::Down))
        {
            rect1Y+=10;
        }
        if (etat==true && Keyboard::isKeyPressed(Keyboard::Z))
        {
            rect2Y-=10;
        }
        if (etat==true && Keyboard::isKeyPressed(Keyboard::S))
        {
            rect2Y+=10;
        }
        if(etat==true && b.x<0)
        {
            score2+=1;
            b=ajoute_balle();
        }

        if(etat==true && b.x>1000)
        {
            score1+=1;
            b=ajoute_balle();
        }






        }


        if(etat==false)
        {


            txtJouer.setPosition(rectJouerX-30,rectJouerY-10);
            txtQuitter.setPosition(rectQuitterX-40,rectQuitterY-10);
            rectQuitter.setPosition(rectQuitterX-rectQuitterL/2,rectQuitterY-rectQuitterH/2);
            rectJouer.setPosition(rectJouerX-rectJouerL/2,rectJouerY-rectJouerH/2);
            window.draw(rectQuitter);
            window.draw(txtQuitter);
            window.draw(rectJouer);
            window.draw(txtJouer);

        }
        


        if(etat==true)
        {

        b.x+=b.vx;
        b.y+=b.vy;

        if( b.x < rect1X + rect1L &&  b.x + 2*b.r > rect1X &&  b.y + 2*b.r > rect1Y && b.y < rect1Y + rect1H  )
        {
            b.vx=-b.vx*1.1076;
            b.vy=-b.vy*1.1076;
        }
        if( b.x < rect2X + rect2L &&  b.x + 2*b.r > rect2X &&  b.y + 2*b.r > rect2Y && b.y < rect2Y + rect2H  )
        {
            b.vx=-b.vx*1.1076; 
            b.vy=-b.vy*1.1076;
        }


        if(b.y-b.r<0 || b.y-b.r>1000)
        {
            b.vy=-b.vy;
        }


        if(rect1Y < 0)
        {
            rect1Y=0;
        }
        if(rect1Y >900)
        {
            rect1Y=900;
        }
        if(rect2Y < 0)
        {
            rect2Y=0;
        }
        if(rect2Y >900)
        {
            rect2Y=900;
        }



        txtscore1.setString("score : " + to_string(int(score1)));
        txtscore2.setString("score : " + to_string(int(score2)));
        txtscore1.setPosition(10 , 900);
        txtscore2.setPosition(900 , 900);
        rect1.setPosition(rect1X,rect1Y);
        rect2.setPosition(rect2X,rect2Y);
        rond.setPosition(b.x,b.y);
        window.draw(txtscore1);
        window.draw(txtscore2);
        window.draw(rect1);
        window.draw(rect2);
        window.draw(rond);
        }


        window.display();
    }



    return 0;
}