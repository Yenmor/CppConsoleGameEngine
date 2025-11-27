# 快速开始

- 最小实现
    此程序可以实现一个空的游戏场景
```cpp
#include "MyGameEngine.h"

int main(){

  GameInfo info = GameInfo(30);
  Screen screen = Screen(' ', 30, 20);

  while(true){

    screen.update();
    screen.draw();

    commonUpdate();
}
```
- 自定义游戏物体

```
#pragma once
#include "MyGameObject.h"

//must extend GameObject
class Square : public GameObject{

//creat the texure. allow void character
  str::string s =
    "***"
    "***"
    "***";
Texture tt = Texture("s");

//init by super()
Square() : GameObject(3, 3, &tt){
    
  }

//will be execute on every single frame
void update() override{

  }

}

```
