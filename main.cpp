//首先引入头文件
#include "MyGameEngine.h"
//引入自己定义的游戏物品
#include "TestObject.h"
int main() {
    //创建一个游戏信息
    GameInfo info = GameInfo(120);

    //创建一个游戏场景
    //三个参数, 长度宽度和默认背景字符
    Screen screen = Screen(' ', 40, 20);

    //那么如何往游戏里添加物品呢？
    //向 screen 里添加物品
    auto obj = MyObj();
    screen.addObj(&obj, 1); //order 其实没用，按照添加顺序就是order了，后面添加的就渲染在上面


    //游戏主循环
    while (true) {
        //你可以直接在main里对游戏物体的属性进行操控， 不过不推荐这么搞

        //可以看到自建的游戏物体已经可以渲染出来了
        //更新Screen 和绘制 Screen
        screen.update();
        screen.draw();

        //这个要放在最后, 输入GameInfo
        commonUpdate(info);

    }
}



