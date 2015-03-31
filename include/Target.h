#ifndef TARGET_H
#define TARGET_H

#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;
/*
* A target can only be in one of the 5 positions
* 1 = l = left
* 2 = s = left corner
* 3 = c = center
* 4 = o = right corner
* 5 = r = right
*/

class Target
{
    public:
        Target();
        Target(int w, int h);
        void drawTarget();
        void reset();
        void moveT();
        void checkPos();
        bool hit(char po);

    private:
        char position;
        int width;
        int height;
        int wdh;
        int hgt;
        int z;

};

Target:: Target(){
/*when you create a new target it randomly decides
* its position and color */
    z = 0;
    width = wdh = 480;
    height = hgt = 600;
    int po;
    po = rand() % 5 + 1;
    if(po == 1){
        position = 'l';
        wdh *= -1;
        hgt = (hgt/4) * -1;
    } else if(po == 2){
        position = 's';
        wdh *= -1;
        hgt /= 2;
    } else if(po == 3){
        position = 'c';
        wdh = 0;
        hgt /= 2;
    } else if(po == 4){
        position = 'o';
        hgt /= 2;
    } else {
        position = 'r';
        hgt = (hgt/4) * -1;
    }
    drawTarget();
}

Target:: Target(int w, int h){
/*when you create a new target it randomly decides
* its position and color */
    z = 0;
    width = wdh = w;
    height = hgt =h;
    int po;
    po = rand() % 5 + 1;
    if(po == 1){
        position = 'l';
        wdh *= -1;
        hgt = (hgt/4) * -1;
    } else if(po == 2){
        position = 's';
        wdh *= -1;
        hgt /= 2;
    } else if(po == 3){
        position = 'c';
        wdh = 0;
        hgt /= 2;
    } else if(po == 4){
        position = 'o';
        hgt /= 2;
    } else {
        position = 'r';
        hgt = (hgt/4) * -1;
    }
    drawTarget();
}

void Target::drawTarget(){

    glBegin(GL_POINTS);
        glVertex3d(wdh,hgt,-30+z);

    glEnd();
}

void Target::reset(){
    wdh = width;
    hgt = height;
    int po;
    po = rand() % 5 + 1;
    if(po == 1){
        position = 'l';
        wdh *= -1;
        hgt = (hgt/4) * -1;
    } else if(po == 2){
        position = 's';
        wdh *= -1;
        hgt /= 2;
    } else if(po == 3){
        position = 'c';
        wdh = 0;
        hgt /= 2;
    } else if(po == 4){
        position = 'o';
        hgt /= 2;
    } else {
        position = 'r';
        hgt = (hgt/4) * -1;
    }
    drawTarget();
}

void Target::checkPos(){
    if(-30+z > 5){
        reset();
        z = 0;
    }
}

void Target::moveT(){
    z+=1;
    drawTarget();
    checkPos();
}

bool Target::hit(char po){
    if(po == position){
        if(-30+z >= 0 ){
            return true;
        }
    }
    return false;
}
#endif // TARGET_H
