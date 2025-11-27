#pragma once
#define CLEAR system("cls")
#include <windows.h>
#include <vector>
#include <string>
#include <iostream>
#include "KeyManager.h"

class  Screen;

class GameInfo{
public:
    int FPS;
    double frameTime;
    long frameTimems;
    GameInfo(int FPS){
        this->frameTime = 1.0 / FPS;
        this->frameTimems = frameTime * 1000;
    }

};
void commonUpdate(GameInfo info){
    Sleep(info.frameTimems);
    CLEAR;
}
class Position{
public:
    int x;
    int y;
    Position(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Texture {
public:
    int width, height;
    std::string string;
    Texture(std::string strTexture) {
        string = strTexture;
    }


};

class GameObject {
public:
    int centre;
    int width;
    int height;
    Texture* texture;
    Position position = Position(0, 0);
    int pixelCount;
    Screen* screen;
    int screenWidth;
    int screenHeight;

    GameObject(){
        centre = -1;
        width = -1;
        height = -1;
        texture = new Texture(" ");
        pixelCount = -1;
    }


    GameObject(int width, int height, Texture* texture, Position position)
    : width(width),
      height(height),
      texture(texture),
      position(position)
    {
        pixelCount = width * height;
    }
    virtual void update() { }

};

 int position2index(Position pos , int width) {
    int x = pos.x;
    int y = pos.y;
    return x + width * y;
}

class Screen {
public:
    char voidBackGroundTexture;
    int width;
    int height;
    int pixelCount;
    char* mainScreen;
    std::vector<GameObject*> objects;
    std::vector<GameObject*> preJoinedObjects;

    Screen(char voidBackGroundTexture, int w, int h) {
        this->voidBackGroundTexture = voidBackGroundTexture;
        this->width = w;
        this->height = h;
        this->pixelCount = width * height;
        mainScreen = new char[width * height];

        for (int i = 0; i < (width * height); i++) {
            mainScreen[i] = voidBackGroundTexture;
        }

    }

    void writeObj(GameObject* obj) const {
        int count = 0;
        int count2 = 0;
        for (int i = position2index(obj->position , width); i < pixelCount; i++) {

            if(count2 == obj->pixelCount) break;
            count++ ;
            count2++ ;

            if(i > -1 && i < pixelCount){
                mainScreen[i] = obj->texture->string.at(count2 - 1);
            }

            if(count == obj->width) {
                count = 0;
                i -= obj->width;
                i += width;
            }
        }
    }

    void addObj(GameObject* obj, int order){
        this->preJoinedObjects.push_back(obj);
        obj->screen = this;
        obj->screenHeight = this->height;
        obj->screenWidth = this->width;
        obj->pixelCount = obj->width * obj->height;
    }

    void draw() const{
        std::string buffer;
        buffer.reserve(width * height + height);
        for(int y = 0; y < height; y++){
            buffer.append(mainScreen + y * width, width);
            buffer += '\n';
        }
        std::cout << buffer;
    }
    void update(){
        for (int i = 0; i < (width * height); i++) {
            mainScreen[i] = voidBackGroundTexture;
        }
        for(auto &obj : objects){
            obj->update();
            writeObj(obj);
        }
        for(GameObject* obj : preJoinedObjects){
            objects.push_back(obj);
        }
        preJoinedObjects.clear();
    }
};



