#pragma once
#include "Animator.h"

Animator::Animator()
{
}
void Animator::CreateAnimation(int animIndex, string path, float duration, int posDrawX, int posDrawY, int sizeFrameX, int sizeFrameY, int sizeSpriteX)        //این تابع وضعیت کاراکتر را مقداردهی می کند
{
    index = 0;
    anim_duration = duration;
    pos_draw_x = posDrawX;
    pos_draw_y = posDrawY;
    size_frame_x = sizeFrameX;
    size_frame_y = sizeFrameY;
    size_sprite_x = sizeSpriteX;
    isFirstTimeIniti = true;
    sprite_texture.loadFromFile(path); //تصاویر را از هارد بارگذاری می کند
    container.insert(pair<int, Texture>(animIndex, sprite_texture));//تصویر را به کانتینر
}
Sprite& Animator::CallAnimation(int animIndex)
{
    //if (isFirstTimeIniti)
    //{
    isFirstTimeIniti = false;
    sprite.setTexture(container[animIndex]);//تصویر را به صورت بافت بر روی اسپرایت می گذارد 
//}
    Time deltaTime = clk.restart();//زمان کل را رستارت می کند
    timepassed += deltaTime;
    //
    if (timepassed.asSeconds() >= anim_duration || isFirstTime)
    {
        timepassed = timepassed.Zero;
        sprite.setTextureRect(IntRect(index + pos_draw_x, pos_draw_y,
            size_frame_x, size_frame_y));
        index = index + size_frame_x;
        if (index >= size_sprite_x)
        {
            index = 0;
        }
    }
    return sprite;
}
