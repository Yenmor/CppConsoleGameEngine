#include "MyGameEngine.h"
#pragma once
//我这里准备了一个子弹类
class Ballet : public GameObject{
public:
    Ballet() : GameObject(){
        this->position.x = 10;
        this->position.y = 30;
        this->width = 2;
        this->height = 3;
        this->texture = new Texture ("##@@##");
    }
    void update() override{
        this->position.y -= 2;
    }





};
