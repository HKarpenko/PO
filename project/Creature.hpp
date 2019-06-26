#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <SFML/Graphics.hpp>

class Creature{
protected:
    int damage;
    int health;
    sf::Texture tx;
    sf::Sprite sp;
    double cord_x,cord_y;
    std::string status;
    double frame_number;
    std::string direction;
    double speedX, speedY;
    sf::IntRect rect;
    double ground, roof;
    virtual bool collisionX()=0;
    virtual void spot_lground() {}
public:
    friend class Camera;
    Creature(int damage_=0, int health_=1, std::string status_="stay", double frame_number_=0, std::string direction_="right", double cord_x_=32, double cord_y_=32, double speedX_=0, double speedY_=0, double ground_=380, double roof_=32)
    {
        damage=damage_;
        health=health_;
        cord_x=cord_x_;
        cord_y=cord_y_;
        status=status_;
        frame_number=frame_number_;
        direction=direction_;
        speedX=speedX_;
        speedY=speedY_;
        ground=ground_;
        roof=roof_;
    }
    virtual void set_status(std::string)=0;

    void set_direction(std::string dir="right"){
        if( dir=="right" || dir=="left")
            direction=dir;
    }
    virtual void update(double) {}
    virtual void update_pose(double)=0;
    virtual bool movingX(double)=0;
    virtual void movingY(double) {}
    void drawing(sf::RenderWindow& window){
        window.draw(sp);
    }
    int get_health() const{
        return health;
    }
    std::string get_dir() const{
        return direction;
    }
    const std::string get_status() const {
        return status;
    }
    void set_health(int delt){
        health+=delt;
    }
    const int get_damage() const{
        return damage;
    }
    void set_damage(int dam){
        damage=dam;
    }
    virtual void set_speedY(double) {}
	virtual double get_x() const { return cord_x; }
    virtual double get_y() const { return cord_y; }
	virtual sf::IntRect get_rect()const { return rect; }

	virtual double get_dam_tim() { return 0; }
    virtual double get_att_tim() { return 0; }
    virtual void restart_dam() {}
    virtual void restart_att() {}


};


#endif //CREATURE_HPP
