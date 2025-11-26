#include "MyGameEngine.h"
#include "FreeSquare.h"
int main(){
    GameInfo info(50);
    Screen screen(' ', 50, 14);
    std::string backGround =
            "##################################################"
            "#                                                #"
            "#                                                #"
            "#                                                #"
            "#                                                #"
            "#                                                #"
            "#                                                #"
            "#                                                #"
            "#                                                #"
            "#                                                #"
            "#                                                #"
            "#                                                #"
            "#                                                #"
            "##################################################";
    auto bg = new GameObject(50,14,&backGround,Position(0,0));
    auto obj = new FreeSquare();
    screen.addObj(bg,1);
    screen.addObj(obj,1);
    int c1 = 0;
    while (true) {
        c1++;
        if(c1 == 6){
            auto b = new Ballet();
            b->position = Position(obj->position.x + 2, obj->position.y);
            screen.addObj(b,1);
            c1 = 0;
        }

        screen.draw();
        screen.update();
        commonUpdate(info);
    }
}



