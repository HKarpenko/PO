#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Hero.hpp"
#include <SFML/Graphics.hpp>

class Camera{
    sf::View camera;
    Creature* v_obj;
public:
    Camera(Creature& obj) : v_obj(&obj) {}
    void update(){
        float x = v_obj->cord_x;
        float y = v_obj->cord_y;
        if(x<320) x=320;
        if(y<240) y=240;
        if(y>554) y=554;
        if(x>2240) x=2240;
        camera.setCenter(x, y);
    }
    sf::View& get_cam(){
        return camera;
    }
};

#endif // CAMERA_HPP
