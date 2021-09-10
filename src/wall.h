//
// Created by Miles Friedman on 9/2/21.
//

#ifndef INC_21F_PA01_THELADS_MAIN_WALL_H
#define INC_21F_PA01_THELADS_MAIN_WALL_H
#include "painting.h"
#include <vector>
#include <iostream>
using namespace std;

class wall {
private:
    int width;
    int height;
    vector<painting> wallList;
    int max_X = 0;
    int max_Y = 0;
    int totalValue = 0;

public:
    wall();
    wall(int w, int h);
    vector<painting> getList(){return wallList;}
    void addPainting(painting& newPainting);
    bool collides(painting& paint1, painting& paint2);
    void wallPrint();
    int getWidth(){return width;}
    int getHeight(){return height;}
    void updateValue();
    void clear();
    int getValue();
    wall& operator=(const wall& rhs){
        width = rhs.width;
        height = rhs.height;
        wallList = rhs.wallList;
        max_X = rhs.max_X;
        max_Y = rhs.max_Y;
        totalValue = rhs.totalValue;
        return *this;

    }


};


#endif //INC_21F_PA01_THELADS_MAIN_WALL_H
