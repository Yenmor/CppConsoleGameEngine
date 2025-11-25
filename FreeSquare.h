#include "MyGameEngine.h"
class FreeSquare : public GameObject{
public:
    FreeSquare() : GameObject(-1,4,4,'*',Position(1,1)){
    }
    void update() override{
        this->position.x += 1;
    }
};