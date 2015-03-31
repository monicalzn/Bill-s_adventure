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
        char color;
        int level;

};

Target:: Target(){
/*when you create a new target it randomly decides
* its position and color. According to the position they are in the width and the height values
* will be adapted and stored in wdh and hgt (they become the draw's x and y, respectively. The position is chosen by a random
* number between 1 and 5. Using a random the value for the color is defined. The default values for the width and height
* are the default values for the window. The starting value for z is a random number between -30 and -50. Once the
* position is defined and the values for wdh, hgt and z, we must call the draw method. */
    z = (rand() % 50 + 30) * -1;
    //color
    width = wdh = 480;
    height = hgt = 600;
    int po;
    po = rand() % 5 + 1;
    if(po == 1){
        // left
        position = 'l';
        wdh *= -1;
        hgt = (hgt/4) * -1;
    } else if(po == 2){
        //left corner
        position = 's';
        wdh *= -1;
        hgt /= 2;
    } else if(po == 3){
        //center
        position = 'c';
        wdh = 0;
        hgt /= 2;
    } else if(po == 4){
        // right corner
        position = 'o';
        hgt /= 2;
    } else {
        // right
        position = 'r';
        hgt = (hgt/4) * -1;
    }
    drawTarget();
}

Target:: Target(int w, int h){
/*when you create a new target it randomly decides
* its position and color. According to the position they are in the width and the height values
* will be adapted and stored in wdh and hgt (they become the draw's x and y, respectively. The position is chosen by a random
* number between 1 and 5. Using a random the value for the color is defined. The default values for the width and height
* are the default values for the window. The starting value for z is a random number. Once the
* position is defined and the values for wdh, hgt and z, we must call the draw method. */
    z = (rand() % 50 + 30) * -1;
    //color
    width = wdh = w;
    height = hgt =h;
    int po;
    po = rand() % 5 + 1;
    if(po == 1){
        //left
        position = 'l';
        wdh *= -1;
        hgt = (hgt/4) * -1;
    } else if(po == 2){
        //left corner
        position = 's';
        wdh *= -1;
        hgt /= 2;
    } else if(po == 3){
        //center
        position = 'c';
        wdh = 0;
        hgt /= 2;
    } else if(po == 4){
        //right corner
        position = 'o';
        hgt /= 2;
    } else {
        //right
        position = 'r';
        hgt = (hgt/4) * -1;
    }
    drawTarget();
}

void Target::drawTarget(){
/* function that draws the target, right now it only draws a point in representation. */
    glBegin(GL_POINTS);
        glVertex3d(wdh,hgt,z);

    glEnd();
}

void Target::reset(){
/* This function reset the position of the target to a new one. According to the values of width
* and height, it makes the proper adjustments. It also gives it a new color depending on the current level. */
    z = (rand() % 50 + 30) * -1;
    wdh = width;
    //color
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
/* Checks the position of the target, if its past the camera it's values must be reseted. */
    if(z > 5){
        reset();
    }
}

void Target::moveT(){
/* Moves the object forward, draws it and then checks if it needs to be reseted.*/
    z+=1;
    drawTarget();
    checkPos();
}

bool Target::hit(char po){
/* Checks if the user hit the target, it does if they are in the same position and if the target is at least
* on a positive z. Check if they are the same color is still missing.*/
    if(po == position){
        if(z >= 0 ){
            return true;
        }
    }
    return false;
}


#endif // TARGET_H
