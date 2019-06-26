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
    Mush(double m_x, double m_y, std::string dir) : Creature(10, 40, "run", 0, dir, m_x, m_y, 0.03){
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
        update_pose(time_del);
        if(health<=0 || cord_y>=500)
            set_status("death");
        if(status=="death"){
            sp.setTextureRect(rect);
            return;
        }
        else if(status=="run"){
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

#endif //ENEMY_HPP
