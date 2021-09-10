//
// Created by Miles Friedman on 9/2/21.
//

#include "painting.h"

painting::painting(int i, int v, int w, int h) {
    id = i;
    value = v;
    width = w;
    height = h;
    x = 0;
    y = 0;
}

void painting::setHeight(int& h) {height = h;}

void painting::setWidth(int& w) { width = w;}

int& painting::getHeight() {return height;}

int& painting::getWidth() {return width;}

 void painting::setY(int yIn) {y = yIn;}

 void painting::setX(int xIn) { x = xIn;}

void painting::print() {
    cout << "ID: " << id << endl << "Value: " << value << endl << "Width: " <<  width << endl << "Height: " <<  height << endl;
}

bool painting::operator<(painting rhs) {
    if (this->getSize() > rhs.getSize()){
        return false;
    }
    return true;
}

bool painting::operator>(painting rhs) {
    if (this->getValue() > rhs.getValue()){
        return true;
    }
    return false;
}
