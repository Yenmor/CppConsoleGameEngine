# 快速开始

- 最小实现<br/>
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

```cpp
#pragma once
#include "MyGameObject.h"

//must extend GameObject
//必须继承自GameObject
class Square : public GameObject{

//creat the texure. allow void character
//创建游戏精灵的材质
  str::string s =
    "***"
    "***"
    "***";
Texture tt = Texture("s");

//init by super()
//从父类构造方法初始化
Square() : GameObject(3, 3, &tt){
    
  }

//will be execute on every single frame
//每帧都会运行update中的内容
void update() override{

  }
}

```

- 添加游戏物体进屏幕
```cpp
//使用 Screen 中的 addObj() 方法
#include "MyGameEngine.h"
#include "Square.h"
int main(){

  GameInfo info = GameInfo(30);
  Screen screen = Screen(' ', 30, 20);

  Square sq = Square();
  screen.addObj(sq);

  while(true){

    screen.update();
    screen.draw();

    commonUpdate();
}
```

