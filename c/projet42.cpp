#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;
using namespace sf;


const int NB_CASES_X=20;
const int NB_CASES_Y=20;
const int TAILLE_CASE=25;


struct Pomme
{
    float r , x , y;
};

Pomme ajoute_pomme()
{
    Pomme p;
    p.r=8;
    p.x= p.r + rand()% 500-2*p.r;
    p.y= p.r + rand()% 500-2*p.r;
    return p;
}



int main()
{

    srand(time(NULL));

    Pomme p=ajoute_pomme();
    
    bool etat=false; //false = menu , true =jeu 
    bool fin = false; //fin =false  c'est quand on est dans le jeu sinon on est mort donc fin=true

    RenderWindow window(VideoMode(NB_CASES_X*TAILLE_CASE,NB_CASES_Y*TAILLE_CASE),"snake");

    Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        cerr<<"erreur"<<endl;
        return 1;
    }

    CircleShape pomme(p.r);
    pomme.setFillColor(Color::Red);
    
    float snakeX=0 , snakeY=0 , snakeL=25 , snakeH=25 , snakeVX=25 , snakeVY=25;
    RectangleShape snake(Vector2f(snakeL,snakeH));
    snake.setFillColor(Color::Green);
    


    sf::Clock chrono;
    int score=0, highscore=0;

    Text txtscore;
    txtscore.setFont(font);
    txtscore.setFillColor(Color::Red);
    txtscore.setCharacterSize(15);
    txtscore.setPosition(25,450);







    float rectjouerX=250 , rectjouerY=150 , rectjouerL=100 , rectjouerH=100;
    RectangleShape rectjouer(Vector2f(rectjouerL,rectjouerH));
    rectjouer.setFillColor(Color::Blue);
    Text txtjouer("JOUER" , font , 10);

    float rectquitterX=250 , rectquitterY=350 , rectquitterL=100 , rectquitterH=100;
    RectangleShape rectquitter(Vector2f(rectquitterL,rectquitterH));
    rectquitter.setFillColor(Color::Blue);
    Text txtquitter("QUITTER" , font , 10);

    Text txtfin;
    txtfin.setFillColor(Color :: Red);
    txtfin.setFont(font);
    txtfin.setCharacterSize(20);


    while(window.isOpen())
    {
        window.clear();
        Event event;
        float temps=chrono.getElapsedTime().asMilliseconds();

        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }



            if(etat==false && event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left)
            {
                float sourisX=event.mouseButton.x;
                float sourisY=event.mouseButton.y;
                if(sourisX>=rectjouerX-rectjouerL/2 && sourisX<=rectjouerX+rectjouerL/2 && sourisY>=rectjouerY-rectjouerH/2 && sourisY<=rectjouerY+rectjouerH/2 )
                {
                    etat=true;
                }
                if(sourisX>=rectquitterX-rectquitterL/2 && sourisX<=rectquitterX+rectquitterL/2 && sourisY>=rectquitterY-rectquitterH/2 && sourisY<=rectquitterY+rectquitterH/2 )
                {
                    window.close();
                }

            }

            if (etat==true && event.type == Event::KeyPressed) 
            {
            if (event.key.code == Keyboard::Up)    { snakeVX = 0;   snakeVY = -TAILLE_CASE; }
            if (event.key.code == Keyboard::Down)  { snakeVX = 0;   snakeVY =  TAILLE_CASE; } //extrait de chatgpt
            if (event.key.code == Keyboard::Left)  { snakeVX = -TAILLE_CASE; snakeVY = 0; }
            if (event.key.code == Keyboard::Right) { snakeVX =  TAILLE_CASE; snakeVY = 0; }
            }
            

        }











        if(etat==false)
        {



            rectjouer.setPosition(rectjouerX-rectjouerL/2,rectjouerY-rectjouerH/2);
            txtjouer.setPosition(rectjouerX-rectjouerL/2 +30,rectjouerY-rectjouerH/2+50);
            rectquitter.setPosition(rectquitterX-rectquitterL/2,rectquitterY-rectquitterH/2);
            txtquitter.setPosition(rectquitterX-rectquitterL/2 +30,rectquitterY-rectquitterH/2+50);
            

            window.draw(rectquitter);
            window.draw(txtquitter);
            window.draw(rectjouer);
            window.draw(txtjouer);

        }














        if(etat==true)
        {

            if(fin==true)
            {
                if(score>highscore)
                {
                    highscore=score;
                }
                txtfin.setString("GAME OVER \n  score : " + to_string(int(score)) + "\n highscore : " + to_string(int(highscore)));
                window.draw(txtfin);
                if(Keyboard::isKeyPressed(Keyboard::R))
                {
                    fin=false;
                    score=0;
                    p=ajoute_pomme();
                    snakeX = 0;    // ou la position de départ de ton choix
                    snakeY = 0;
                    snakeVX = TAILLE_CASE; // pour aller à droite au démarrage
                    snakeVY = 0;
                    chrono.restart();
                    
                }
            }





        if(fin==false)
        {    
        for(int i=0;i<NB_CASES_X;i+=1)
        {
            RectangleShape ligneX(Vector2f(1,NB_CASES_Y*TAILLE_CASE));
            ligneX.setPosition(i*TAILLE_CASE,0);
            ligneX.setFillColor(Color(100,100,100));
            window.draw(ligneX);
        }
        for(int i=0;i<NB_CASES_Y;i+=1)
        {
            RectangleShape ligneY(Vector2f(NB_CASES_X*TAILLE_CASE,1));
            ligneY.setPosition(0,i*TAILLE_CASE);
            ligneY.setFillColor(Color(100,100,100));
            window.draw(ligneY);
        }

        if(temps>200)
        {
            snakeX+=snakeVX;
            snakeY+=snakeVY;

            chrono.restart();
        }

        if(snakeX-snakeL/2 <0)
        {
            snakeX=0;
            fin=true;
        }
        if(snakeX+snakeL/2 >475)
        {
            snakeX=475;
            fin=true;
        }
        if(snakeY-snakeH/2 <0)
        {
            snakeY=0;
            fin=true;

        }
        if(snakeY+snakeH/2 >475)
        {
            snakeY=475;
            fin=true;
        }

        if(p.x<snakeX+snakeL && p.x+2*p.r>snakeX && p.y<snakeY+snakeH && p.y+2*p.r>snakeY)
        {
            score++;
            p=ajoute_pomme();
            
        }

        
        txtscore.setString("score : " + to_string(int(score)));   
        pomme.setPosition(p.x-p.r,p.y-p.r);
        snake.setPosition(snakeX,snakeY);
        window.draw(txtscore);
        window.draw(pomme);
        window.draw(snake);
        }
        }


        window.display();
    }



    return 0;
}