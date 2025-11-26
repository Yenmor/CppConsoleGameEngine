#include "MyGameEngine.h"
class Ballet : public GameObject{
public:
    Ballet() : GameObject(){
        this->position.x = 10;
        this->position.y = 30;
        this->width = 2;
        this->height = 3;
        this->texture = new std::string ("##@@##");
    }
    void update() override{
        this->position.y -= 2;
    }





};
