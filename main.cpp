//
// Created by 17551 on 2025/11/25.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>

#include "MyGameEngine.h"
#define vector std::vector
#define CLEAR system("cls")

//vector<char> mainScreen(WIDTH * HEIGHT,L'=');



int update() {
    return 0;
}


int main(){
    boolean GameRunning = true;
    constexpr double FPS = 120;
    constexpr double frameTime = 1.0 / FPS;
    while (GameRunning) {
        CLEAR;
        update();
        for (int i = 0 ; i < PIXEL_COUNT ; i++ ){

            if (i % WIDTH == WIDTH - 1 && i != 0)  { std::cout << std::endl; }
        }



        Sleep(static_cast<long>(frameTime * 1000.0));
    }


}



