#include <iostream>
#include <fstream>
#include "wall.h"
#include <vector>
#include <algorithm>
//Heap's Algorithm Reference Used: https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/

using namespace std;
void bruteForceAlgo(vector<painting>& paintings, wall canvas, string fileName);
void expenseAlgo(vector<painting>& paintings, wall canvas, string fileName);
void customAlgo(vector<painting>& paintings, wall canvas, string fileName);
void writeOut(ofstream& fileOut, wall& canvas);
void paintingsAdd(vector<painting> paintings, wall& canvas);
void heapPermutation(vector<painting>& paintings, int size, int n, wall canvas);

wall bruteMax;
int main(int argC, char* argV[]) {
    vector<painting> paintings;
    int numPaintings;
    wall canvas;

    if (argC == 2) {
        ifstream file;
        file.open(argV[1]);
        if (!file.is_open()) {
            cout << "Could not open file" << endl;
        } else {
            int w;
            int h;
            file >> w;
            file >> h;
            wall canvas(w, h);

            file >> numPaintings;
            int id;
            int value;
            for (int i = 0; i < numPaintings; i++) {
                file >> id;
                file >> value;
                file >> w;
                file >> h;
                painting temp(id, value, w, h);
                paintings.push_back(temp);
            }
            bruteForceAlgo(paintings, canvas, argV[1]);
            expenseAlgo(paintings, canvas, argV[1]);
            customAlgo(paintings, canvas, argV[1]);

        }
    } else {
        cout << "Improper Command Line Arguments Only Input 1 File Name. Example:"
             << endl <<
             "/Users/yeet/Downloads/21f-pa01-thelads-main/cmake-build-debug/21f_pa01_thelads_main input.txt"
             << endl;
    }
//wall ohboy(1000, 1000);
//
//painting ayo7(1, 100, 100, 100);
//ohboy.addPainting(ayo7);
//ohboy.addPainting(ayo7);
//ohboy.addPainting(ayo7);
//ohboy.addPainting(ayo7);
//ohboy.addPainting(ayo7);
//ohboy.addPainting(ayo7);
//ohboy.addPainting(ayo7);
//ohboy.addPainting(ayo7);
//    ohboy.addPainting(ayo7);
//    ohboy.addPainting(ayo7);
//    for(int i = 0; i < ohboy.getList().size(); i++){
//    cout << "Painting " << i + 1 << " X: " << ohboy.getList()[i].getX() << endl;
//    cout << "Painting " << i + 1 << " Y: " << ohboy.getList()[i].getY() << endl;
//}





}
//this algorithm tests all permutations of a data set and determines the maximum value
void bruteForceAlgo(vector<painting>& paintings, wall canvas, string fileName){
    size_t found = fileName.find_last_of('.');
    string bruteName = fileName.insert(found, "-bruteforce");
    ofstream fileOut(bruteName.c_str());

    if (paintings.size() <= 10){
        heapPermutation(paintings, paintings.size(), paintings.size(),canvas);
        writeOut(fileOut, bruteMax);
        fileOut.close();

    }
    else{
        fileOut << "data set exceeds maximum";
    }


}
//this algorithm sorts the paintings by their monetary value and then adds them starting from the highest first
void expenseAlgo(vector<painting>& paintings, wall canvas, string fileName){
    size_t found = fileName.find_last_of('.');
    string expenseName = fileName.insert(found, "-highvalue");
    ofstream fileOut(expenseName.c_str());

    for(int i = 0; i < paintings.size() - 1; ++i){
        int indexBiggest = i;
        for (int j = i + 1; j < paintings.size(); ++j){
            if(paintings.at(j) > paintings.at(indexBiggest)){
                indexBiggest = j;
            }
        }
        painting temp = paintings.at(i);
        paintings.at(i) = paintings.at(indexBiggest);
        paintings.at(indexBiggest) = temp;
    }
    for(auto & painting : paintings){
        canvas.addPainting(painting);
    }
    writeOut(fileOut, canvas);
    fileOut.close();

}
//this function sorts the paintings by size and then adds the smallest paintings first
void customAlgo(vector<painting>& paintings, wall canvas, string fileName){
    size_t found = fileName.find_last_of('.');
    string customName = fileName.insert(found, "-custom");
    ofstream fileOut(customName.c_str());
    for(int i = 0; i < paintings.size() - 1; ++i){
        int indexSmallest = i;
        for (int j = i + 1; j < paintings.size(); ++j){
            if(paintings.at(j) < paintings.at(indexSmallest)){
                indexSmallest = j;
            }
        }
        painting temp = paintings.at(i);
        paintings.at(i) = paintings.at(indexSmallest);
        paintings.at(indexSmallest) = temp;
    }
    for(auto & painting : paintings){
       // cout << painting.getID() << endl;
        canvas.addPainting(painting);
    }

    writeOut(fileOut, canvas);
    fileOut.close();

}
//this function provides all possible permutations for a vector of paintings
void heapPermutation(vector<painting>& paintings, int size, int n, wall canvas){
    if (size == 1){
        paintingsAdd(paintings, canvas);
        if(canvas.getValue() >= bruteMax.getValue()){
            bruteMax = canvas;
        }
    }

    for (int i = 0; i < size; i++){
        heapPermutation(paintings, size - 1, n, canvas);
        if (size % 2 == 1){
            painting temp = paintings[0];
            paintings[0] = paintings[size -1];
            paintings[size - 1] = temp;
        }
        else{
            painting temp = paintings[i];
            paintings[i] = paintings[size -1];
            paintings[size - 1] = temp;
        }
    }

}
//this function adds a vector of  paintings to a wall
void paintingsAdd(vector<painting> paintings, wall& canvas){
    canvas.clear();
    for (int i = 0; i < paintings.size(); i++){
        canvas.addPainting(paintings[i]);
    }
}
//this function takes a file and wall, and writes information about the wall to the file
void writeOut(ofstream& fileOut, wall& canvas){
    //fileOut << "ID " << "Value " << "Width " << "Height " << "X " << "Y " << endl;
    for(int i = 0; i < canvas.getList().size(); i++){
        fileOut << canvas.getList().at(i).getID() << " ";
        fileOut << canvas.getList().at(i).getValue() << " ";
        fileOut << canvas.getList().at(i).getWidth() << " ";
        fileOut << canvas.getList().at(i).getHeight() << " ";
        fileOut << canvas.getList().at(i).getX()<< " ";
        fileOut << canvas.getList().at(i).getY() << endl;

    }
    fileOut << "Total Value: " << canvas.getValue() << endl;
}

