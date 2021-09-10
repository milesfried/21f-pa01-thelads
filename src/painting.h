//
// Created by Miles Friedman on 9/2/21.
//

#ifndef INC_21F_PA01_THELADS_MAIN_PAINTING_H
#define INC_21F_PA01_THELADS_MAIN_PAINTING_H
#include <iostream>
using namespace std;

class painting {
private:
    int x;
    int y ;
    int width;
    int height;
    int id;
    int value;
public:
    painting(int i, int v, int w, int h);
    int& getWidth();
    int& getHeight();
    void setWidth(int& w);
    void setHeight(int& h);
    void setX(int xIn);
    void setY(int yIn);
    int& getX(){return x;}
    int& getY(){return y;}
    int getSize(){return (getWidth() * getHeight());}
    void print();
    int getValue(){return value;}
    int getID(){return id;}
    bool operator>(painting rhs);
    bool operator<(painting rhs);
    painting& operator=(const painting& rhs){
        x = rhs.x;
        y = rhs.y;
        width = rhs.width;
        height = rhs.height;
        id = rhs.id;
        value = rhs.value;
        return *this;
    }
};


#endif //INC_21F_PA01_THELADS_MAIN_PAINTING_H
