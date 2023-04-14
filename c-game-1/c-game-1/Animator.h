#pragma once
#include "SFML/Graphics.hpp"  //باید نصب شود
#include <map>

using namespace sf;
using namespace std;

class Animator   //این کلاس انیمیشن ها را می سازد
{

private:

    string texture_path;
    Texture sprite_texture;
    Sprite sprite;   //به بافت نیاز دارد
    Clock clk;
    Time timepassed;
    map <int, Texture> container;
    bool isFirstTime = true, isFirstTimeIniti;
    int index, pos_draw_x, pos_draw_y, size_frame_x, size_frame_y, size_sprite_x;
    float anim_duration;

public:

    Animator();
    void CreateAnimation(int, string, float, int, int, int, int, int);
    Sprite& CallAnimation(int);

};
