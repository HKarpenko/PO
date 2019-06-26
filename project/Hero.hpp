#ifndef HERO_HPP
#define HERO_HPP

#include "Creature.hpp"
#include "Mapp.hpp"
#include "Camera.hpp"
#include "Enemy.hpp"
#include <SFML/Graphics.hpp>


class Hero : public Creature{
private:
    bool end_g=false;
    bool attack_poss;
    const int run_frames=11;
    const int jump_frames=6;
    const int sword_frames=8;
    const int jump_cord[6][4] { {175,71,24,37}, {207,67,17,41}, {234,62,19,46}, {260,67,23,41}, {290,66,27,42}, {326,70,24,38} };
    const int run_cord[11][4] { {61,118,30,34},{96,118,20,34},{120,117,23,35},{146,118,32,34},{182,119,34,33},{221,119,26,33},{253,118,22,34},{280,117,25,35},{310,118,30,34},{343,119,34,33},{381,119,29,33}};
    const int stay_cord[4] {73,307,32,37};
    const int death_cord[4] {325,695,32,48};
    const int sword_cord[8][4] { {81,535,31,33},{115,530,39,38},{156,533,38,35},{198,513,42,55},{244,515,63,53},{313,535,47,33},{362,536,46,32},{412,536,32,32}};
    const int real_sw_cord[8][4] { {81,535,31,33},{123,535,31,33},{164,533,30,35},{205,535,35,33},{244,535,35,33},{313,535,31,33},{362,536,32,32},{412,536,32,32}};
    bool collisionX(){
        int fr_width;
        int fr_height;
        int frame=std::floor(frame_number);
        if(status=="stay"){
            fr_width=stay_cord[2];
            fr_height=stay_cord[3];
        }
        else if(status=="run"){
            fr_width=run_cord[frame][2];
            fr_height=run_cord[frame][3];
        }
        else if(status=="jump"){
            fr_width=jump_cord[frame][2];
            fr_height=jump_cord[frame][3];
        }
        else if(status=="attack"){
            fr_width=real_sw_cord[frame][2];
            fr_height=real_sw_cord[frame][3];
        }
        if(cord_y+fr_height>=ground+4 && status!="stay"){
            cord_y=ground-fr_height;
            sp.setPosition(cord_x,cord_y);
            set_status("stay");
            speedY=0;
        }
        for (int i = cord_y/32; i <= std::floor((cord_y+fr_height)/32); i++)
            for (int j = cord_x/32; j <= std::floor((cord_x+fr_width+10)/32); j++)
                if (std::string("0tafds").find(MAPP::TileMap[i][j])!=-1 && status!="stay"){
                    if(direction=="right"){
                        if(cord_x+10>=(j+1)*32)
                            return false;
                        cord_x=j*32-fr_width-6;
                        sp.setPosition(cord_x,cord_y);
                    }
                    else{
                        if(cord_x+fr_width-10<j*32)
                            return false;
                        cord_x=j*32+38;
                        sp.setPosition(cord_x,cord_y);
                    }
                    return true;
                }
                else if (MAPP::TileMap[i][j] == 'k'){
                    MAPP::TileMap[i][j]=' ';
                    MAPP::TileMap[11][79]='O';
                    MAPP::TileMap[10][79]='1';
                }
                else if (MAPP::TileMap[i][j] == 'l' && cord_y+25>i*32){
                    health=0;
                }
                else if (MAPP::TileMap[i][j] == 'O'){
                    end_g=true;
                }
        return false;
    }
    void spot_lground(){
        int fr_width;
        int fr_height;
        int frame=std::floor(frame_number);
        if(status=="stay"){
            fr_width=stay_cord[2];
            fr_height=stay_cord[3];
        }
        else if(status=="run"){
            fr_width=run_cord[frame][2];
            fr_height=run_cord[frame][3];
        }
        else if(status=="jump"){
            fr_width=jump_cord[frame][2];
            fr_height=jump_cord[frame][3];
        }
        else if(status=="attack"){
            fr_width=real_sw_cord[frame][2];
            fr_height=real_sw_cord[frame][3];
        }
        bool brr=false;
        for (int i = cord_y/32; i < MAPP::height; i++){
            for (int j = cord_x/32; j <= std::floor((cord_x+fr_width-8)/32); j++)
                if (std::string("0tafds").find(MAPP::TileMap[i][j])!=-1){
                    ground=i*32-4;
                    brr=true;
                    break;
                }
            if(brr)
                break;
        }
        brr=false;
        for (int i = cord_y/32+1; i >= 0; i--){
            for (int j = cord_x/32; j <= std::floor((cord_x+fr_width-8)/32); j++)
                if (std::string("0tafds").find(MAPP::TileMap[i][j])!=-1){
                    roof=(i+1)*32;
                    brr=true;
                    break;
                }
            if(brr)
                break;
        }
    }
public:
    Hero() : Creature(20, 100, "stay", 0, "right", 32.0, 348.0, 0, 0, 380.0 , 32.0), attack_poss(true){
        tx.loadFromFile("hero.png");
        sp.setTexture(tx);
        rect = sf::IntRect(stay_cord[0],stay_cord[1],stay_cord[2],stay_cord[3]);
        sp.setTextureRect(rect);
        sp.setPosition(cord_x,cord_y);
    }
    void set_status(std::string state="stay"){
        if( state=="stay" || state=="run" || state=="jump" || state=="death" || state=="attack"){
            status=state;
            frame_number=0;
        }
    }
    void update_hero(double time_del,bool jump_move=false){
        update_pose(time_del);
        if(health<=0)
            set_status("death");
        if(status=="stay"){
            if(cord_y+stay_cord[3]-5<ground){
                set_status("jump");
                return;
            }
            attack_poss=true;
            speedX=0.05;
            speedY=0;
            sp.setTextureRect(rect);
            movingX(0);
        }
        else if(status=="death"){
            health=0;
            sp.setTextureRect(rect);
            if(cord_y>-80){
                sp.move(0,-0.1*time_del);
                cord_y+=-0.1*time_del;
            }
            else
                end_g=true;
            return;
        }
        else if(status=="run"){
            if(cord_y+stay_cord[3]-5<ground){
                set_status("jump");
                return;
            }
            attack_poss=true;
            if(speedX<0.1)
                speedX+=0.00005*time_del;
            sp.setTextureRect(rect);
            if(direction=="right")
                movingX(speedX*time_del);
            else
                movingX(-speedX*time_del);
        }
        else if(status=="jump"){
            if(cord_y+stay_cord[3]-5==ground&&speedY==0){
                speedY=-0.29;
                speedX=0.1;
                cord_y=ground-stay_cord[3]-7;
                sp.setPosition(cord_x,cord_y);
            }
            speedY+=0.0005*time_del;
            sp.setTextureRect(rect);
                if(direction=="right"){
                    movingX(speedX*time_del*jump_move);
                    movingY(speedY*time_del);
                }
                else{
                    movingX(-speedX*time_del*jump_move);
                    movingY(speedY*time_del);
                }
            if(abs(cord_y+stay_cord[3]-ground)<0.5 && speedY>0){
                sp.setPosition(cord_x,ground-stay_cord[3]+5);
                cord_y=ground-stay_cord[3]+5;
                set_status("stay");
                speedY=0;
            }
        }
        else if(status=="attack"){
            if(cord_y+stay_cord[3]-5<ground && !attack_poss){
                set_status("jump");
                return;
            }
            if(speedX==0.05)
                speedX+=0.01*time_del;
            else if(speedX>0.3){
                speedX=0.05;
            }
            sp.setTextureRect(rect);
            if(direction=="right")
                movingX(speedX*time_del);
            else
                movingX(-speedX*time_del);
        }
        spot_lground();
    }
    void update_pose(double time_del){
        if(status=="stay"){
            if(direction=="right")
                rect=sf::IntRect(stay_cord[0],stay_cord[1],stay_cord[2],stay_cord[3]);
            else
                rect=sf::IntRect(stay_cord[0]+stay_cord[2],stay_cord[1],-stay_cord[2],stay_cord[3]);
        }
        else if(status=="run"){
            frame_number+=0.01*time_del;
            if(frame_number>run_frames)
                frame_number=0.0;
            int frame=std::floor(frame_number);
            if(direction=="left")
                rect=sf::IntRect(run_cord[frame][0]+run_cord[frame][2],run_cord[frame][1],-run_cord[frame][2],run_cord[frame][3]);
            else
                rect=sf::IntRect(run_cord[frame][0],run_cord[frame][1],run_cord[frame][2],run_cord[frame][3]);
        }
        else if(status=="jump"){
            frame_number+=0.005*time_del;
            if(frame_number>jump_frames)
                frame_number=0.0;
            int frame=std::floor(frame_number);
            if(direction=="left")
                rect=sf::IntRect(jump_cord[frame][0]+jump_cord[frame][2],jump_cord[frame][1],-jump_cord[frame][2],jump_cord[frame][3]);
            else
                rect=sf::IntRect(jump_cord[frame][0],jump_cord[frame][1],jump_cord[frame][2],jump_cord[frame][3]);
        }
        else if(status=="attack"){
            frame_number+=0.01*time_del;
            if(frame_number>sword_frames){
                set_status("stay");
                attack_poss=false;
            }
            int frame=std::floor(frame_number);
            if(direction=="right")
                rect=sf::IntRect(sword_cord[frame][0],sword_cord[frame][1],sword_cord[frame][2],sword_cord[frame][3]);
            else
                rect=sf::IntRect(sword_cord[frame][0]+sword_cord[frame][2],sword_cord[frame][1],-sword_cord[frame][2],sword_cord[frame][3]);
        }
        else if(status=="death"){
            rect=sf::IntRect(death_cord[0],death_cord[1],death_cord[2],death_cord[3]);
        }
    }
    bool movingX(double c_x=0){
        cord_x+=c_x;
        bool coll=collisionX();
        sp.move(c_x,0);
        return true;
    }
    void movingY(double c_y=0){
        int fr_height;
        int frame=std::floor(frame_number);
        if(status=="stay")
            fr_height=stay_cord[3];
        else if(status=="death")
            fr_height=death_cord[3];
        else if(status=="run")
            fr_height=run_cord[frame][3];
        else if(status=="jump")
            fr_height=jump_cord[frame][3];
        else if(status=="run")
            fr_height=real_sw_cord[frame][3];
        double border1=roof;
        double border2=ground;
        if(cord_y+c_y<border1)
            speedY=0.0;
        else{
            cord_y+=c_y;
            sp.move(0,c_y);
        }
    }
    bool contact(const Creature* en){
        int h_rght, e_rght;
        int h_bot=cord_y+rect.height, e_bot=en->get_y()+en->get_rect().height;
        if(direction=="right")
            h_rght=cord_x+rect.width;
        else
            h_rght=cord_x-rect.width;
        if(en->get_dir()=="right")
            e_rght=en->get_x()+en->get_rect().width;
        else
            e_rght=en->get_x()-en->get_rect().width;
        if((cord_x>=en->get_x() && cord_x<=e_rght) || (h_rght>=en->get_x() && h_rght<=e_rght))
            if((cord_y>=en->get_y() && cord_y<=e_bot) || (h_bot>=en->get_y() && h_bot<=e_bot))
                return true;
        return false;
    }
    bool get_att_pos() const{
        return attack_poss;
    }
    bool get_end() const{
        return end_g;
    }
    void set_speedY(double sp){
        speedY=sp;
    }
};

#endif // HERO_HPP
