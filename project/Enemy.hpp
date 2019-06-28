#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "Mapp.hpp"
#include "Creature.hpp"

class Mush : public Creature{
private:
    sf::Clock damage_timer;
    sf::Clock attack_timer;
    sf::Clock disapp_timer;
    const int run_frames=3;
    const int run_cord[3][4] { {7,108,19,19},{39,109,19,18},{71,107,19,20}};
    const int death_cord[4] {360,257,20,12};

    bool collisionX(){
        int frame=std::floor(frame_number);
        int fr_height=run_cord[frame][3];
        int fr_width=run_cord[frame][2];
        for (int i = cord_y/32; i <= std::floor((cord_y+fr_height)/32); i++)
            for (int j = cord_x/32; j <= std::floor((cord_x+fr_width)/32); j++)
                if (std::string("0afds").find(MAPP::TileMap[i][j])!=-1){
                    speedX=0.03;
                    if(direction=="right"){
                        set_direction("left");
                        cord_x=j*32-20;
                        sp.setPosition(cord_x,cord_y);
                    }
                    else{
                        set_direction("right");
                        cord_x=j*32+32;
                        sp.setPosition(cord_x,cord_y);
                    }
                    return true;
                }
        return false;
    }
public:
    Mush(double m_x, double m_y, std::string dir, Creature* hero_) : Creature(10, 40, "run", 0, dir, m_x, m_y, 0.03){
        tx.loadFromFile("enemy.png");
        sp.setTexture(tx);
        rect = sf::IntRect(run_cord[0][0],run_cord[0][1],run_cord[0][2],run_cord[0][3]);
        sp.setTextureRect(rect);
        sp.setPosition(cord_x,cord_y);
    }
    void set_status(std::string state="run"){
        if(state=="run" || state=="death")
            status=state;
    }
    void update(double time_del){
        if(status=="death"){
            if(disapp_timer.getElapsedTime().asSeconds()>3){
                cord_y+=500;
                sp.setPosition(cord_x,cord_y);
            }
        }
        else if(health<=0 || cord_y>=500){
            set_status("death");
            update_pose(time_del);
            sp.setTextureRect(rect);
            disapp_timer.restart();
        }
        else if(status=="run"){
            update_pose(time_del);
            sp.setTextureRect(rect);
            if(direction=="right")
                movingX(speedX*time_del);
            else
                movingX(-speedX*time_del);
        }
    }
    void update_pose(double time_del){
        if(status=="run"){
            frame_number+=0.005*time_del;
            if(frame_number>run_frames)
                frame_number=0.0;
            int frame=std::floor(frame_number);
            if(direction=="left")
                rect=sf::IntRect(run_cord[frame][0]+run_cord[frame][2],run_cord[frame][1],-run_cord[frame][2],run_cord[frame][3]);
            else
                rect=sf::IntRect(run_cord[frame][0],run_cord[frame][1],run_cord[frame][2],run_cord[frame][3]);
        }
        else if(status=="death"){
            frame_number=0.0;
            rect=sf::IntRect(death_cord[0],death_cord[1],death_cord[2],death_cord[3]);
        }
    }
    bool movingX(double c_x=0){
        cord_x+=c_x;
        bool collis = collisionX();
        sp.setPosition(cord_x,cord_y);
        return collis;
    }
    double get_x() const{
        return cord_x;
    }
    double get_y() const{
        return cord_y;
    }
    sf::IntRect get_rect()const{
        return rect;
    }
    double get_dam_tim(){
        return damage_timer.getElapsedTime().asSeconds();
    }
    double get_att_tim(){
        return attack_timer.getElapsedTime().asSeconds();
    }
    void restart_dam(){
        damage_timer.restart();
    }
    void restart_att(){
        attack_timer.restart();
    }
};

class Golem : public Creature{
private:
    sf::Clock damage_timer;
    sf::Clock attack_timer;
    sf::Clock disapp_timer;
    Creature* hero;
    const int run_frames=3;
    const int run_cord[3][4] { {196,224,21,31},{229,224,21,31},{259,224,21,31}};
    const int death_cord[4] {320,353,32,31};

    bool collisionX(){
        int frame=std::floor(frame_number);
        int fr_height=run_cord[frame][3];
        int fr_width=run_cord[frame][2];
        for (int i = cord_y/32; i <= std::floor((cord_y+fr_height)/32); i++)
            for (int j = cord_x/32; j <= std::floor((cord_x+fr_width)/32); j++)
                if (std::string("0afds").find(MAPP::TileMap[i][j])!=-1){
                    speedX=0.03;
                    if(direction=="right"){
                        set_direction("left");
                        cord_x=j*32-24;
                        sp.setPosition(cord_x,cord_y);
                    }
                    else{
                        set_direction("right");
                        cord_x=j*32+33;
                        sp.setPosition(cord_x,cord_y);
                    }
                    return true;
                }
        return false;
    }
public:
    Golem(double m_x, double m_y, std::string dir, Creature* hero_) : Creature(10, 160, "run", 0, dir, m_x, m_y, 0.02), hero(hero_){
        tx.loadFromFile("enemy.png");
        sp.setTexture(tx);
        rect = sf::IntRect(run_cord[0][0],run_cord[0][1],run_cord[0][2],run_cord[0][3]);
        sp.setTextureRect(rect);
        sp.setPosition(cord_x,cord_y);
    }
    void set_status(std::string state="run"){
        if(state=="run"  || state=="smell" || state=="death" )
            status=state;
    }
    void update(double time_del){
        if(status=="death"){
            if(disapp_timer.getElapsedTime().asSeconds()>3){
                cord_y+=500;
                sp.setPosition(cord_x,cord_y);
            }
            return;
        }
        else if(health<=0 || cord_y>=500){
            set_status("death");
            update_pose(time_del);
            sp.setTextureRect(rect);
            disapp_timer.restart();
            cord_y+=32;
            sp.setPosition(cord_x,cord_y);
            return;
        }
        else if(status=="run"){
            update_pose(time_del);
            sp.setTextureRect(rect);
            speedX=0.02;
            if(direction=="right")
                movingX(speedX*time_del);
            else
                movingX(-speedX*time_del);
        }
        else if(status=="smell"){
            update_pose(time_del);
            sp.setTextureRect(rect);
            speedX=0.025;
            if(hero->get_x()-cord_x<0)
                direction="left";
            else
                direction="right";
            if(direction=="right")
                movingX(speedX*time_del);
            else
                movingX(-speedX*time_del);
        }

        if(abs(hero->get_x()-cord_x)<100 && abs(hero->get_y()-cord_y)<100 && hero->get_status()!="death")
            set_status("smell");
        else
            set_status("run");
    }
    void update_pose(double time_del){
        if(status=="run" || status=="smell"){
            frame_number+=0.005*time_del;
            if(frame_number>run_frames)
                frame_number=0.0;
            int frame=std::floor(frame_number);
            if(direction=="left")
                rect=sf::IntRect(run_cord[frame][0]+run_cord[frame][2],run_cord[frame][1],-run_cord[frame][2],run_cord[frame][3]);
            else
                rect=sf::IntRect(run_cord[frame][0],run_cord[frame][1],run_cord[frame][2],run_cord[frame][3]);
        }
        else if(status=="death"){
            frame_number=0.0;
            rect=sf::IntRect(death_cord[0],death_cord[1],death_cord[2],death_cord[3]);
        }
    }
    bool movingX(double c_x=0){
        cord_x+=c_x;
        bool collis = collisionX();
        sp.setPosition(cord_x,cord_y);
        return collis;
    }
    double get_x() const{
        return cord_x;
    }
    double get_y() const{
        return cord_y;
    }
    sf::IntRect get_rect()const{
        return rect;
    }
    double get_dam_tim(){
        return damage_timer.getElapsedTime().asSeconds();
    }
    double get_att_tim(){
        return attack_timer.getElapsedTime().asSeconds();
    }
    void restart_dam(){
        damage_timer.restart();
    }
    void restart_att(){
        attack_timer.restart();
    }
};

#endif //ENEMY_HPP
