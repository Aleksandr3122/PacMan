#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cobject.h"
//******************
constexpr auto WIDTH_MAP =  20;
constexpr auto HEIGHT_MAP = 20;
//*********************
char Map[HEIGHT_MAP][WIDTH_MAP] =
{ 'B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B',
  'B','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','B',
  'B','F','B','B','F','B','B','B','B','B','B','B','B','B','B','B','F','B','F','B',
  'B','F','F','B','F','F','F','F','F','B','0','B','F','B','-','-','F','F','F','B',
  'B','F','B','B','B','B','F','B','F','B','0','B','F','F','F','-','F','B','F','B',
  'B','F','F','F','F','F','F','F','F','B','B','B','F','B','F','B','F','B','F','B',
  'B','F','B','F','B','B','B','B','F','F','B','F','F','B','F','B','F','B','F','B',
  'B','F','B','F','B','F','F','F','B','F','B','0','F','B','F','B','F','B','F','B',
  'B','F','B','F','B','B','B','F','B','F','0','0','F','B','F','B','F','B','F','B',
  'B','F','F','F','F','F','F','F','F','F','B','B','F','B','F','B','F','B','F','B',
  'B','F','B','F','B','B','B','B','F','B','I','B','F','B','F','F','F','B','F','B',
  'B','F','B','F','B','F','F','F','F','B','B','B','-','B','F','0','B','B','F','B',
  'B','F','B','F','B','F','B','B','B','I','0','B','-','F','B','0','B','B','F','B',
  'B','F','B','F','B','F','B','F','B','0','0','0','0','F','F','F','B','0','F','B',
  'B','F','B','F','B','F','B','F','F','F','F','F','B','F','B','B','F','B','F','B',
  'B','F','B','F','F','F','B','F','B','B','B','B','B','F','B','F','F','B','F','B',
  'B','F','F','F','B','F','B','F','F','F','F','F','F','F','B','B','F','B','F','B',
  'B','F','B','B','B','F','B','F','B','F','B','B','B','B','B','B','F','B','F','B',
  'B','F','F','F','F','F','F','F','B','F','F','F','F','F','F','F','F','F','F','B',
  'B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B'
};

void collision(int i,int j);
void keyInput();
//***********************
sf::Sprite Pacman;
sf::Sprite fruit;
sf::Sprite block;
sf::Sprite pacbud;
sf::Sprite pacbud1, pacbud2, pacbud3;
sf::Image image;
sf::Texture texture,pactextur,frutextur,budtexture;
sf::Font font;
sf::Text scoreText, lifeText;
/*********/
int dirX = 0;
int dirY = 0;
float timeInput = 16;
int animCount = 0;

int score = 0;

int bdirx = 1;
int bdiry = 0;


static void pacAnim()
{
  int  x = animCount * 14;

  Pacman.setTextureRect(sf::IntRect(x, 0, 14, 14));
  animCount++;
  if (animCount >= 4) animCount = 0;
}


static void budMove(sf::Sprite &bud)
{
    srand(time(NULL));
    int x = bud.getPosition().x;
    int y = bud.getPosition().y;
    int k = 1;
    int i,j;

    if ((bdiry == 1) or (bdiry == -1)) /// DOWN or UP
    {
        if (bdiry == 1)
        {
            k = -1;
            j = (y + 8) / 16;
        }
        if (bdiry == -1)
        {
            k = 1;
        j = (y - 8) / 16;
        }
            int i = x / 16;
            
        if (Map[j][i] == 'B')
          {
            int a = rand() % 30;
            std::cout << a<<" ";
            if (Map[j + k][i - 1] != 'B')
            {
                if (a <= 10)
                {
                    bdirx = -1;
                    bdiry = 0;

                }
            }
            if (Map[j + k][i + 1] != 'B')
            {
                if ((a >= 10) && (a <= 20))
                {
                    bdirx = 1;
                    bdiry = 0;
                }
            }
                  bdiry = -bdiry;
       }       
    }

    if ((bdirx == -1) or (bdirx == 1)) // LEFT or RIGHT
    {

        if (bdirx == 1)
        {
            i = (x + 8) / 16;
            k = -1;
        }
        if (bdirx == -1)
        {
            i = (x - 8) / 16;
            k = 1;
        }
        int j = y / 16;
        int a = rand() % 30;
        if (Map[j][i] == 'B')
        {
            std::cout << a << " ";

            if (Map[j - 1][i+k] != 'B')
            {               
                if (a <= 10)
                {
                    bdirx = 0;
                    bdiry = -1;

                }
            }
            if (Map[j + 1][i+k] != 'B')
            {
                if ((a >= 10) and(a<=20))
                {
                    bdirx = 0;
                    bdiry = 1;
                }
            }
            bdirx = -bdirx;
        }
    }

    bud.setPosition(x + bdirx, y + bdiry);
}

int main()
{   
    font.loadFromFile("Pixel.ttf");
    scoreText.setFont(font);
    scoreText.setString( "Score:");

    lifeText.setFont(font);
    lifeText.setString("0");
    lifeText.setPosition(420, 0);

    image.loadFromFile("block.png");
    texture.loadFromImage(image);
    block.setTexture(texture);
    image.loadFromFile("PacTile.png");
    pactextur.loadFromImage(image);
    image.loadFromFile("fruit.png");
    frutextur.loadFromImage(image);
    fruit.setTexture(frutextur);
    block.setColor(sf::Color::Cyan);
    Pacman.setTexture(pactextur);
    Pacman.setPosition(112, 81);
    
    sf::RenderWindow window(sf::VideoMode(480, 320), "PACMAN!");
    
    window.setSize(sf::Vector2u(960, 640));
    window.setFramerateLimit(60);
    
    scoreText.setPosition(340, 0);
    image.loadFromFile("budpac.png");
    
    budtexture.loadFromImage(image);
    pacbud.setTexture(budtexture);
    pacbud.setPosition(24, 24);
    pacbud.setOrigin(7, 7);
   /* pacbud1 = pacbud;
    pacbud1.setPosition(24, 296);
    pacbud1.setColor(sf::Color::Green);*/
    sf::Clock clock;
    while (window.isOpen())
    {
     float time = clock.getElapsedTime().asMilliseconds(); 
        if (time >= timeInput)
        {
            keyInput();
            budMove(pacbud);
           /* budMove(pacbud1);*/
        }
        if (time >= 80)
        {
            clock.restart();
            timeInput = 0;
            pacAnim();
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //**********************
        for (int i = 0; i <= 19; i++)
            for (int j = 0; j <= 19; j++)
            {  
                if (Map[i][j] == 'B') 
                {
                    block.setPosition(j * 16, i * 16);
                    window.draw(block);                                                         
                } 
                if (Map[i][j] == 'F')
                {
                    fruit.setPosition(j * 16, i * 16);
                    window.draw(fruit);
                }
            }     
        std::string s =std::to_string( score);
        lifeText.setString(s);
        window.draw(Pacman);
        window.draw(scoreText);
        window.draw(lifeText);
        window.draw(pacbud);
       /* window.draw(pacbud1);*/
        window.display();
    }
    return 0;
}
void collision(int i, int j)
{
   
}
void keyInput()
{
    timeInput = timeInput + 16;
    int x = Pacman.getPosition().x;
    int y = Pacman.getPosition().y;
    int width = x + 14;
    int height = y + 14;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {  
        Pacman.setOrigin(0, 14);
        Pacman.setRotation(90);
        dirY = 1;
        int i = x / 16;
        int j = (y+15 ) / 16;
        
        if (Map[j][i] == 'B')
        {
            dirY = 0;
        }
        i = (x + 14) / 16;
        if (Map[j][i] == 'B')
        {
            dirY = 0;
        }
        Pacman.setPosition(x, y + dirY);
        j = (y + 5) / 16;
        if (Map[j][i] == 'F')
        {
            Map[j][i] = '0';
            score = score++;
        }
        dirY = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Pacman.setOrigin(14, 0);
        Pacman.setRotation(-90);
        dirY = -1;  
        int i = x / 16;
        int j = (y-2) / 16;
        
        if (Map[j][i] == 'B')
        {
            dirY = 0;
        }
       
        i = (x + 14) / 16;
        if (Map[j][i] == 'B')
        {
            dirY = 0;
        }
        Pacman.setPosition(x, y + dirY);
        j = (y +10) / 16;
        if (Map[j][i] == 'F')
        {
            score = score++;
            Map[j][i] = '0';
        }
        dirY = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        Pacman.setOrigin(14, 14);
        Pacman.setRotation(180);
        
        dirX = -1;
        int i = (x - 2) / 16;
        int j = (y+1) / 16;
              
        if (Map[j][i] == 'B')
        {
            dirX = 0;
        }
        j = (y + 14) / 16;
        if (Map[j][i] == 'B')
        {
            dirX = 0;
        }
          
        Pacman.setPosition(x + dirX, y);
        i = (x + 14) / 16;
        if (Map[j][i] == 'F')
        {
            Map[j][i] = '0';
            score = score++;
        }
        dirX = 0;

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {       
        Pacman.setOrigin(0, 0);
        Pacman.setRotation(0);
        dirX = 1;
        int i = (x +15) / 16;
        int j = (y+1) / 16;
        if (Map[j][i] == 'B')
        {
            dirX = 0;
        }            
        j = (y + 14) / 16;
        if (Map[j][i] == 'B')
        {
            dirX = 0;
        }
        Pacman.setPosition(x + dirX, y);
        i = (x - 1) / 16;
        if (Map[j][i] == 'F')
        {
            score = score ++;
            Map[j][i] = '0'; 
        }
        
        dirX = 0;
    }
}
