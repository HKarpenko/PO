#ifndef MAPP_H
#define MAPP_H

#include <SFML\Graphics.hpp>

namespace MAPP{
    const int height = 20;
    const int width = 80;
    sf::String TileMap[height] = {
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000",
    "0                                                                              0",
    "0                                                                              0",
    "0                                  fMMkMMf  f                                  0",
    "0                                  sttttts     f                               0",
    "0                                             f                                0",
    "0                afffd                  f                                      0",
    "0       affffd                               f               f                 0",
    "0                          f               f              f  s                 0",
    "0fffffd                    s          f         f      f  s  s                 0",
    "0         f                s             f     f    f  s  s  s          f      0",
    "0         s M  G  M f      s        f       f       sM s MsM s    fM    sMM f  o",
    "tttttttttttttttttttttttt  ttttttttt       f        tttttttttttt   ttttttttttttt0",
    "000000000000000000000000  000000000llllllllllllllll000000000000lll00000000000000",
    "000000000000000000000000  000000000000000000000000000000000000000000000000000000",
    "000000000000000000000000  000000000000000000000000000000000000000000000000000000",
    "000000000000000000000000ll000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000",
    };
    class Map{
        sf::Texture map_tx[2];
        sf::Sprite map_sp[2];
    public:
        Map(){
            map_tx[0].loadFromFile("world.png");
            map_sp[0].setTexture(map_tx[0]);
            map_tx[1].loadFromFile("sky.png");
            map_sp[1].setTexture(map_tx[1]);
        }
        void drawing_back(sf::RenderWindow& window){
            for (int i = 0; i < height; i++)
                for (int j = 0; j < width-1; j++){
                    if (TileMap[i][j] != '0'){
                        map_sp[1].setTextureRect(sf::IntRect(0, 0, 32, 32));
                        map_sp[1].setPosition(j * 32, i * 32);
                        window.draw(map_sp[1]);
                }
            }
        }
        void drawing(sf::RenderWindow& window){
            sf::Sprite* exact;
            for (int i = 0; i < height; i++)
                for (int j = 0; j < width; j++){
                    if (TileMap[i][j] == 'k'){  map_sp[0].setTextureRect(sf::IntRect(1728, 1440, 32, 32)); exact=&map_sp[0];}
                    else if (TileMap[i][j] == 't'){  map_sp[0].setTextureRect(sf::IntRect(0, 480, 32, 32)); exact=&map_sp[0];}
                    else if (TileMap[i][j] == '0'){  map_sp[0].setTextureRect(sf::IntRect(0, 448, 32, 32)); exact=&map_sp[0];}
                    else if (TileMap[i][j] == '1'){  map_sp[0].setTextureRect(sf::IntRect(0, 448, 32, 32)); exact=&map_sp[0];}
                    else if (TileMap[i][j] == 'l'){  map_sp[0].setTextureRect(sf::IntRect(960, 0, 32, 32)); exact=&map_sp[0];}
                    else if (TileMap[i][j] == 'a'){  map_sp[0].setTextureRect(sf::IntRect(320, 480, 32, 32)); exact=&map_sp[0];}
                    else if (TileMap[i][j] == 'f'){  map_sp[0].setTextureRect(sf::IntRect(256, 480, 32, 32)); exact=&map_sp[0];}
                    else if (TileMap[i][j] == 'd'){  map_sp[0].setTextureRect(sf::IntRect(288, 480, 32, 32)); exact=&map_sp[0];}
                    else if (TileMap[i][j] == 's'){  map_sp[0].setTextureRect(sf::IntRect(224, 480, 32, 32)); exact=&map_sp[0];}
                    else if (TileMap[i][j] == 'o'){  map_sp[0].setTextureRect(sf::IntRect(736, 352, 32, 32)); exact=&map_sp[0];}
                    else if (TileMap[i][j] == 'O'){map_sp[0].setTextureRect(sf::IntRect(864, 352, 32, 32)); exact=&map_sp[0];}
                    else continue;
                    (*exact).setPosition(j * 32, i * 32);
                    window.draw((*exact));
                }
        }
    };
}
#endif // MAPP_H
