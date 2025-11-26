#include "MyGameEngine.h"
#include "Ballet.h"
class FreeSquare : public GameObject{
public:
    std::string texture =
            "  **  "
            " **** "
            "******"
            "******";

    FreeSquare() : GameObject(6 ,4 ,&texture,Position(4,4)){
    }
    void update() override{
        if(getKeyState(KeyCode::RIGHT)){
            this->position.x += 1;
        }
        if(getKeyState(KeyCode::UP)){
            this->position.y -= 1;
        }
        if(getKeyState(KeyCode::LEFT)){
            this->position.x -= 1;
        }
        if(getKeyState(KeyCode::DOWN)){
            this->position.y += 1;
        }
        if(getKeyState(KeyCode::PAGEUP)){


        }

    }
};