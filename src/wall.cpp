//
// Created by Miles Friedman on 9/2/21.
//

#include "wall.h"

wall::wall(int w, int h) {
    width = w;
    height = h;


}

void wall::addPainting(painting &newPainting) {
    if (newPainting.getWidth() > width || newPainting.getHeight() > height) {
    }
    else if (wallList.size() == 0) {
        newPainting.setX(0);
        newPainting.setY(0);
       // cout << "Adding " << newPainting.getID() << endl;
        wallList.push_back(newPainting);

    } else {
        if (max_X + newPainting.getWidth() < width) {

            newPainting.setX(max_X+ newPainting.getWidth() + 1);
        } else {
            newPainting.setX(0);
            max_X = 0;
            if (max_Y + newPainting.getHeight() < height) {
                newPainting.setY(max_Y + newPainting.getHeight() + 1);
            } else {
                newPainting.setY(0);
            }
        }


//            newPainting.setX(0);
//            newPainting.setY(0);
//            for (int i = 0; i < wallList.size(); i++) {
//
//                while (collides(newPainting, wallList[i])) {
//                    if (newPainting.getX() + newPainting.getWidth() > width) {
//                        newPainting.setX(0);
//                        newPainting.setY(wallList[i].getY() + wallList[i].getHeight() + 1);
//
//                    } else {
//                        newPainting.setY(0);
//                        newPainting.setX(wallList[i].getX() + wallList[i].getWidth() + 1);
//                    }
//                }




        int l = 0;

        for (int i = 0; i < wallList.size(); i++) {
            if (!collides(newPainting, wallList[i])) {
                l++;
            }
        }
        if ((newPainting.getX() + newPainting.getWidth()) > width) {
            l = 0;
        }
        if ((newPainting.getY() + newPainting.getHeight()) > height){
            l = 0;
        }
        if (l >= wallList.size()) {
            if (newPainting.getX() + newPainting.getWidth() > max_X) {
                max_X = newPainting.getX() + newPainting.getWidth();

            }
            if (newPainting.getY() + newPainting.getHeight() > max_Y) {
                max_Y = newPainting.getY() + newPainting.getHeight();

            }
            //cout << "Adding " << newPainting.getID() << endl;
            wallList.push_back(newPainting);
        }
    }
    updateValue();
}


bool wall::collides(painting &paint1, painting &paint2) {
    if(paint1.getX() > paint2.getX() + paint2.getWidth()
       || paint2.getX() > paint1.getX() + paint2.getWidth()){
        return false;
    }
    if (paint1.getY() > paint2.getY() + paint2.getHeight() ||
        paint2.getY() > paint1.getY() + paint1.getHeight()){
        return false;
    }
    return true;
}

void wall::wallPrint() {
    for(int i = 0; i < getList().size(); i++){
        cout << "Painting " << i + 1 << " X: " << getList()[i].getX() << endl;
        cout << "Painting " << i + 1 << " Y: " << getList()[i].getY() << endl;

    }

}

wall::wall() {
    width = 0;
    height = 0;
}

int wall::getValue() {
    return totalValue;
}

void wall::clear() {
    wallList.clear();
}

void wall::updateValue() {
    totalValue = 0;
    for(auto & i : wallList){
        totalValue += i.getValue();
    }
}

