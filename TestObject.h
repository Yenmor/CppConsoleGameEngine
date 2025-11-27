//我们需要新建一个类
//还是引入头文件
//建议都写上不重复定义
#pragma once
#include "MyGameEngine.h"
#include "Ballet.h"
//新建一个类继承自GameObject
class MyObj : public GameObject{
public:
    int count = 0;
            //在这里定义一下自设物品的材质， 材质是方形的，但是可以填空字符进去;
    std::string str =
            "  *  "
            "**=**"
            "*****"
            "== =="
            "== ==";
    //因为父类有texture，所以也可以构造方法里new(我c++这方面的规范并不熟，可能有误，但确实能跑起来)
    Texture texture1 = Texture(str);

    //构造方法初始化游戏物体, 可以直接调用父类构造方法
    //可以看到要传入长宽材质和初始位置
    //定义的是五列，材质不够 回头封装一下再试试
    MyObj() : GameObject(5,5,&texture1,Position(20,10)){

    }

    //那么该如何让游戏物体拥有行为呢？
    //可以重写GameObject 的 update()方法， 会在屏幕更新时调用
    void update() override{
        //比如我们让他按照按键去动
        //键盘控制也已经封装好了一部分
        if(getKeyState(KeyCode::RIGHT)) this->position.x += 1;
        if(getKeyState(KeyCode::LEFT)) this -> position.x -= 1;
        //注意， y增加是向下
        if(getKeyState(KeyCode::UP)) this-> position.y -= 1;
        if(getKeyState(KeyCode::DOWN)) this-> position.y += 1;

        //可以看到行为很不错
        //我们在任何GameObject里都可以对所属的屏幕进行操作，主要是添加子物体，比如子弹
        count++;
        if(count == 30){
            //update每次更新完就没了，所以要new （也应该是这样的吧我不清楚）
            auto b = new Ballet();
            //对子弹位置初始化为自身
            b->position.x = this->position.x + 2;
            b->position.y = this->position.y;
            //添加子弹
            //跑一下试试
            //忘记归零子弹时间计数了
            //我靠，爆炸了、
            //为什么呢
            //破案了 update是在遍历的时候运行，这时候给列表add就是遍历动列表了，要改成延迟添加
            //待我改改引擎
            //再试试
            //ok 接下来让子弹动起来
            //ee又zz啊，这样写控制台游戏的效率高多了
            //我这个只是刚写了一天的初级版本，回头再改一些api加一些功能，争取更规范
            //拜拜喵
            screen->addObj(b,1);

            count = 0;
        }

    }

};