#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include <cmath>

#include "Mapp.hpp"
#include "Camera.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"
#include "TextField.hpp"

using namespace sf;
class Game{
    bool menu_on=true;
    Clock Esc_timer;
    void inter_with_enemies(Hero& hero, std::vector<Creature*> mus, double tim) {
        for ( Creature* Mu : mus ) {
            if(hero.contact(Mu) && Mu->get_status()!="death"){
                if(hero.get_status()!="attack"){
                    if(Mu->get_att_tim()>0.8){
                        hero.set_health(-Mu->get_damage());
                        hero.set_status("jump");
                        Mu->restart_att();
                    }
                }
                else if(Mu->get_dam_tim()>0.8){
                    Mu->set_health(-hero.get_damage());
                    Mu->restart_dam();
                    if(hero.get_dir()=="right"){
                        Mu->set_direction("right");
                        for(int i=0;i<1000;i++)
                            if(Mu->movingX(0.01*tim))
                                break;
                    }
                    else{
                        Mu->set_direction("left");
                        for(int i=0;i<1000;i++)
                            if(Mu->movingX(-0.01*tim))
                                break;
                    }
                }
            }
        }
    }
     void main_menu(bool& keep_on) {
        sf::Event event;
        RenderWindow window(VideoMode(640, 480), "SFML game");
        Texture menuTexture1, menuTexture2, panel_tx, menuBackground;
        menuTexture1.loadFromFile("but1.png");
        menuTexture2.loadFromFile("but2.png");
        panel_tx.loadFromFile("panel.png");
        menuBackground.loadFromFile("retro_back.png");
        Sprite menu1(menuTexture1), menu2(menuTexture2), panel(panel_tx), menuBg(menuBackground);
        bool isMenu = 1;
        int menuNum = 0;
        panel.setPosition(150, 90);
        menu1.setPosition(250, 160);
        menu2.setPosition(250, 240);
        menuBg.setPosition(0, 0);
        while (isMenu)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed){
                    window.close();
                    keep_on=false;
                }
            }
            menu1.setColor(Color::White);
            menu2.setColor(Color::White);
            menuNum = 0;
            window.clear(Color(129, 181, 221));

            if (IntRect(250, 160, 154, 25).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
            if (IntRect(250, 240, 58, 25).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (menuNum == 1)  { isMenu = false; keep_on=true; }
                if (menuNum == 2)  { isMenu = false; keep_on=false; }

            }

            window.draw(menuBg);
            window.draw(panel);
            window.draw(menu1);
            window.draw(menu2);

            window.display();
        }
        window.close();
    }
    void game_menu(RenderWindow& window, bool& keep_on) {
        sf::Event event;
        Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4, panel_tx, menuBackground;
        menuTexture1.loadFromFile("but4.png");
        menuTexture2.loadFromFile("but3.png");
        menuTexture3.loadFromFile("but2.png");
        menuTexture4.loadFromFile("but5.png");
        panel_tx.loadFromFile("panel.png");
        menuBackground.loadFromFile("retro_back.png");
        Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4), panel(panel_tx), menuBg(menuBackground);
        bool isMenu = 1;
        int menuNum = 0;
        panel.setPosition(150, 218);
        menu4.setPosition(250, 268);
        menu1.setPosition(250, 318);
        menu2.setPosition(250, 368);
        menu3.setPosition(250, 418);
        menuBg.setPosition(0, 108);
        while (isMenu)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed){
                    window.close();
                    keep_on=false;
                }
            }
            menu1.setColor(Color::White);
            menu2.setColor(Color::White);
            menu3.setColor(Color::White);
            menu4.setColor(Color::White);
            menuNum = 0;
            window.clear(Color(129, 181, 221));

            if (IntRect(250, 160, 113, 25).contains(Mouse::getPosition(window))) { menu4.setColor(Color::Blue); menuNum = 4; }
            if (IntRect(250, 210, 104, 25).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
            if (IntRect(250, 260, 164, 25).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
            if (IntRect(250, 310, 58, 25).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }


            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (menuNum == 1)  { isMenu = false; keep_on=true;   window.close(); menu_on=false; }
                if (menuNum == 2)  { isMenu = false; keep_on=true; window.close(); }
                if (menuNum == 3)  { isMenu = false; keep_on=false; window.close(); }
                if (menuNum == 4)  { isMenu = false; keep_on=true; }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && Esc_timer.getElapsedTime().asSeconds()>0.2){
                Esc_timer.restart();
                break;
            }

            window.draw(menuBg);
            window.draw(panel);
            window.draw(menu1);
            window.draw(menu2);
            window.draw(menu3);
            window.draw(menu4);

            window.display();
        }
    }
    void game_on(bool& keep_on){
        menu_on=true;
        RenderWindow window(VideoMode(640, 480), "SFML game");
        Clock timing;
        double tim;

        MAPP::Map map_v1;

        Hero Jack;

        std::vector<Creature*> Mus;
        for (int i = 0; i < MAPP::height; i++)
            for (int j = 0; j < MAPP::width; j++)
                if(MAPP::TileMap[i][j]=='e')
                    Mus.push_back(new Mush(j*32,i*32+13,"left"));
        Camera cam(Jack);
        cam.get_cam().reset(sf::FloatRect(0, 0, 640, 480));

        Text_field hero_hp("font.ttf",32);
        hero_hp.assign_hp(Jack, cam);

        while (window.isOpen())
        {
            tim=timing.getElapsedTime().asMicroseconds();
            timing.restart();
            tim/=800;
            sf::Event event;
            for ( Creature* Mu : Mus ) {
                Mu->update(tim);
            }
            if (Jack.get_end())
                window.close();
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed){
                    window.close();
                    keep_on=false;
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && Esc_timer.getElapsedTime().asSeconds()>0.2){
                Esc_timer.restart();
                game_menu(window, keep_on);
            }
            else if(Keyboard::isKeyPressed(sf::Keyboard::K)){
                Jack.set_status("death");
                Jack.update_hero(tim);
            }
            else if(Keyboard::isKeyPressed(sf::Keyboard::Q)){
                if(Jack.get_att_pos() && Jack.get_status()!="attack" )
                    Jack.set_status("attack");
                Jack.update_hero(tim);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)||Keyboard::isKeyPressed(sf::Keyboard::W)){
                if(Jack.get_status()!="jump" && Jack.get_status()!="death" && Jack.get_status()!="attack")
                    Jack.set_status("jump");
                Jack.update_hero(tim);
            }
            else if(Keyboard::isKeyPressed(sf::Keyboard::Left)||Keyboard::isKeyPressed(sf::Keyboard::A)){
                if(Jack.get_status()!="jump" && Jack.get_status()!="death" && Jack.get_status()!="attack" && Jack.get_status()!="run")
                    Jack.set_status("run");
                if(Jack.get_status()!="attack")
                    Jack.set_direction("left");
                Jack.update_hero(tim,true);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||Keyboard::isKeyPressed(sf::Keyboard::D)){
                if(Jack.get_status()!="jump" && Jack.get_status()!="death" && Jack.get_status()!="attack" && Jack.get_status()!="run")
                    Jack.set_status("run");
                if(Jack.get_status()!="attack")
                    Jack.set_direction("right");
                Jack.update_hero(tim,true);
            }
            else{
                if(Jack.get_status()!="jump"&&Jack.get_status()!="death"&&Jack.get_status()!="attack")
                    Jack.set_status("stay");
                Jack.update_hero(tim);
            }
            inter_with_enemies(Jack, Mus, tim);
            window.clear();
            map_v1.drawing_back(window);
            Jack.drawing(window);
            for ( Creature* Mu : Mus ) {
                Mu->drawing(window);
            }
            cam.update();
            map_v1.drawing(window);
            hero_hp.update_hp(Jack, cam);
            hero_hp.drawing(window);
            window.setView(cam.get_cam());
            window.display();
        }

    }
public:
    void start(){
        bool keep_on=true;
        while(keep_on){
            if(menu_on)
                main_menu(keep_on);
            if(keep_on)
                game_on(keep_on);
        }
    }
};

#endif // GAME_HPP
