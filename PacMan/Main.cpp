#include <SFML/Graphics.hpp>
//******************
constexpr auto WIDTH_MAP =  20;
constexpr auto HEIGHT_MAP = 15;
//*********************
char Map[WIDTH_MAP][HEIGHT_MAP] =
{ 'R','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','0','0','B','I','0','0'



};


void createMap();

//***********************
sf::Sprite Pacman;
sf::Sprite Lblock;
sf::Sprite Iblock;
sf::Sprite Xblock;
sf::Sprite block;
sf::Image image;
sf::Texture texture;

int main()
{
    
   
    
    image.loadFromFile("TileSet.png");
    texture.loadFromImage(image);

    Lblock.setTexture(texture);
    Lblock.setTextureRect(sf::IntRect(16,0,16,16));

    Iblock.setTexture(texture);
    Iblock.setTextureRect(sf::IntRect(0, 0, 16, 16));
    
    Xblock.setTexture(texture);
    Xblock.setTextureRect(sf::IntRect(32, 0, 16, 16));
   
    Lblock.setOrigin(8, 8);
    Xblock.setOrigin(8, 8);
    Iblock.setOrigin(8, 8);
    //Iblock.set
    sf::RenderWindow window(sf::VideoMode(320, 240), "SFML works!");
   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //**********************

        for (int i = 0; i <= 20; i++)
            for (int j = 0; j <= 15; j++)
            {
                if (Map[j][i] == 'L') 
                {
                    Lblock.setPosition(i * 16+8, j * 16+8);
                    
                    Lblock.setRotation(0);
                    
                    window.draw(Lblock);
                    
                    
                }
                if (Map[j][i] == 'R')
                {
                    Lblock.setPosition(i * 16+8, j * 16+8);
                    
                    Lblock.setRotation(90);
                    
                    window.draw(Lblock);
                    
                    
                }
                if (Map[j][i] == 'B')
                {
                    Lblock.setPosition(i * 16+8, j * 16+8);
                    
                    Lblock.setRotation(180);
                    window.draw(Lblock);
                   
                    
                }
                if (Map[j][i] == 'T')
                {
                    Lblock.setPosition(i * 16 + 8, j * 16 + 8);

                    Lblock.setRotation(270);

                    window.draw(Lblock);


                }
                if (Map[j][i] == '+')
                {
                    Xblock.setPosition(i * 16 + 8, j * 16 + 8);

                    Xblock.setRotation(0);

                    window.draw(Xblock);


                }
                if (Map[j][i] == 'I')
                {
                    Iblock.setPosition(i * 16 + 8, j * 16 + 8);

                    Iblock.setRotation(90);

                    window.draw(Iblock);


                }
                if (Map[j][i] == '-')
                {
                    Iblock.setPosition(i * 16 + 8, j * 16 + 8);

                    Iblock.setRotation(0);

                    window.draw(Iblock);


                }
            }
        
        
        //*************
        
        
        
        //************
        window.display();
    }

    return 0;
}

void createMap()
{
    
    
   

    
}
