#ifndef TEXT_FIELD_HPP
#define TEXT_FIELD_HPP

#pragma warning(disable : 4996)

#include "Camera.hpp"
#include "Hero.hpp"
#include <sstream>
#include <SFML/Graphics.hpp>

class Text_field{
    std::ostringstream data;
    sf::Font main_font;
    sf::Text text;
public:
    Text_field(std::string file_name, int font_size=32){
        main_font.loadFromFile(file_name);
        text.setCharacterSize(font_size);
        text.setFont(main_font);
        data.str("");
    }

    void assign_hp(Hero& hero,Camera& camera){
        text.setColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold);
        data << hero.get_health();
        text.setString(data.str()+" HP");
        text.setPosition(camera.get_cam().getCenter().x-300, camera.get_cam().getCenter().y-240);
                data.str("");
    }

    void update_hp(Hero& hero,Camera& camera){
        data << hero.get_health();
        text.setString(data.str()+" HP");
        text.setPosition(camera.get_cam().getCenter().x-300, camera.get_cam().getCenter().y-240);
        data.str("");
    }

    void drawing(sf::RenderWindow& window){
        window.draw(text);
    }


};

#endif //TEXT_FIELD_HPP
