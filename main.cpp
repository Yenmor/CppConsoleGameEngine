#include "MyGameEngine.h"
#include "FreeSquare.h"
int update() {
    return 0;
}
int main(){
    GameInfo info(60);
    Screen screen(' ', 60, 20);
    auto obj = new FreeSquare();
    screen.addObj(obj,1);
    while (true) {
        screen.update();
        screen.draw();
        commonUpdate(info);
    }
}



