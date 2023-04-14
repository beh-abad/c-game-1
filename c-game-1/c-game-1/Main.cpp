#include "Animator.h"
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(1360, 720), "Simple game"); //ویندوز را باز می کند
    Animator anim;
    window.setFramerateLimit(30);// سرعت فریم ها برای رندرکردن انیمیشن
    anim.CreateAnimation(0, "dm.png", 1, 0, 0, 98, 98, 686);//تصاویر را از پیکربندی می کند
    anim.CreateAnimation(1, "dm_move_up.png", 1, 0, 0, 98, 98, 98);
    anim.CreateAnimation(2, "dm_move_right_up.png", 1, 0, 0, 98, 98, 98);
    anim.CreateAnimation(3, "dm_move_right.png", 1, 0, 0, 98, 98, 98);
    anim.CreateAnimation(4, "dm_move_right_down.png", 1, 0, 0, 98, 98, 98);
    anim.CreateAnimation(5, "dm_move_down.png", 1, 0, 0, 98, 98, 98);
    anim.CreateAnimation(6, "dm_move_left_down.png", 1, 0, 0, 98, 98, 98);
    anim.CreateAnimation(7, "dm_move_left.png", 1, 0, 0, 98, 98, 98);
    anim.CreateAnimation(8, "dm_move_left_up.png", 1, 0, 0, 98, 98, 98);
    int index = 0;
    Clock ob;
    Time timeHolder;
    int deltaTimeHolder;
    while (window.isOpen()) //تا زمانیکه پنجره باز هست
    {
        timeHolder = ob.restart();
        float deltaTime = timeHolder.asSeconds();
        deltaTimeHolder = 150 * deltaTime;   //تاثیر سرعت پردازنده های مختلف را از بین می برد
        Event event;
        while (window.pollEvent(event)) //تا زمانیکه ایونت وارد شود       
        {
            if (event.type == Event::EventType::Closed)
                window.close();
            if (event.type == Event::EventType::KeyReleased)
            {
                index = 0;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::D))
            {
                index = 3;
                anim.CallAnimation(index).move(deltaTimeHolder, 0);
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::A))
            {
                index = 7;
                anim.CallAnimation(index).move(-deltaTimeHolder, 0);
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::W))
            {
                index = 1;
                anim.CallAnimation(index).move(0, -deltaTimeHolder);
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::S))
            {
                index = 5;
                anim.CallAnimation(index).move(0, deltaTimeHolder);
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::D) && Keyboard::isKeyPressed(Keyboard::Key::S))
            {
                index = 4;
                anim.CallAnimation(index).move(deltaTimeHolder, deltaTimeHolder);
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::A) && Keyboard::isKeyPressed(Keyboard::Key::S))
            {
                index = 6;
                anim.CallAnimation(index).move(-deltaTimeHolder, deltaTimeHolder);
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::W) && Keyboard::isKeyPressed(Keyboard::Key::D))
            {
                index = 2;
                anim.CallAnimation(index).move(deltaTimeHolder, -deltaTimeHolder);
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::W) &&
                Keyboard::isKeyPressed(Keyboard::Key::A))
            {
                index = 8;
                anim.CallAnimation(index).move(-deltaTimeHolder,
                    -deltaTimeHolder);
            }
        }
        window.clear();//فریم قبلی را پاک می کند
        window.draw(anim.CallAnimation(index));//فریم را بر روی بافر بارگذاری می کند
        window.display();//فریم را نمایش می دهد
    }
    cin.ignore();
    return 0;
}
