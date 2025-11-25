//
// Created by 17551 on 2025/11/25.
//

#ifndef CPPGAMEENGINE_MYGAMEENGINE_H
#define CPPGAMEENGINE_MYGAMEENGINE_H

#endif //CPPGAMEENGINE_MYGAMEENGINE_H
class Position{
public:
    int x;
    int y;
    Position(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Shape {
public:
    int width, height;
    char* shapeData;
    Shape(std::string str) {

    }
};

class GameObject {
public:
    int centre;
    int width;
    int height;
    char texture;
    Position position;

    GameObject(int centre, int width, int height, char texture, Position position)
    : centre(centre),
      width(width),
      height(height),
      texture(texture),
      position(position)
    {}

};

class Screen {
public:
    char voidBackGroundTexture;
    int width;
    int height;
    char* mainScreen;

    Screen(char voidBackGroundTexture, int w, int h) {
        this->voidBackGroundTexture = voidBackGroundTexture;
        this->width = w;
        this->height = h;
        mainScreen = new char[width * height];

        for (int i = 0; i < (width * height); i++) {
            mainScreen[i] = voidBackGroundTexture;
        }

    }

    void writeObj(GameObject* obj) {
        for (int i = obj->centre ; i < width; i++) {

        }
    }


};


int position2index(Position pos , Screen s) {
    int x = pos.x;
    int y = pos.y;
    return x + s.width * y;

}