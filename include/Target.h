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
        Target(int w, int h, int l);
        void drawTarget();
        void reset();
        void moveT();
        void checkPos();
        bool hit(char po, char playerColor);
        void setPosition();
        void setColor();
        void setWindow(int w, int h);
        void setLevel(int l);

    private:
        char position;
        int width;
        int height;
        int wdh;
        int hgt;
        double zI;
        double z;
        char color;
        int level;
        char colors[4] = {'b', 'r', 'g'};

};

Target:: Target(){
/*when you create a new target it randomly decides
* its position and color. According to the position they are in the width and the height values
* will be adapted and stored in wdh and hgt (they become the draw's x and y, respectively. The position is chosen by a random
* number between 1 and 5. Using a random the value for the color is defined. The default values for the width and height
* are the default values for the window. The starting value for z is a random number between -30 and -50. Once the
* position is defined and the values for wdh, hgt and z, we must call the draw method. */
    level = 1;
    setColor();
    //color
    width = wdh = 480;
    height = hgt = 600;
    setPosition();
    drawTarget();
}

Target:: Target(int w, int h, int l){
/*when you create a new target it randomly decides
* its position and color. According to the position they are in the width and the height values
* will be adapted and stored in wdh and hgt (they become the draw's x and y, respectively. The position is chosen by a random
* number between 1 and 5. Using a random the value for the color is defined. The default values for the width and height
* are the default values for the window. The starting value for z is a random number. Once the
* position is defined and the values for wdh, hgt and z, we must call the draw method. */
     level = l;
    setColor();
    //color
    width = wdh = w;
    height = hgt =h;
    setPosition();
    drawTarget();
}

void Target::drawTarget(){
/* function that draws the target, right now it only draws a point in representation. */
    glBegin(GL_POINTS);
        if(color == 'b'){
            glColor3ub(35, 100, 245);
        } else if(color == 'r'){
            glColor3ub(245, 100, 35);
        } else {
            glColor3ub(10, 200, 35);
        }
        glVertex3d(wdh,hgt,zI);
    glEnd();
}

void Target::reset(){
/* This function reset the position of the target to a new one. According to the values of width
* and height, it makes the proper adjustments. It also gives it a new color depending on the current level. */
    wdh = width;
    //color
    hgt = height;
    setColor();
    setPosition();
}

void Target::checkPos(){
/* Checks the position of the target, if its past the camera it's values must be reseted. */
    if(z > 20){
        reset();
    }
}

void Target::moveT(){
/* Moves the object forward, draws it and then checks if it needs to be reseted.*/
    z+=1;

     cout << z << " " ;
    glPushMatrix();
    glTranslated(0,0,z);
    drawTarget();
    checkPos();
    glPopMatrix();

}

bool Target::hit(char po, char playerColor){
/* Checks if the user hit the target, it does if they are in the same position and if the target is at least
* on a positive z. Check if they are the same color is still missing.*/
    if(po == position && playerColor == color){
        if(z >= 5 ){
            return true;
        }
    }
    return false;
}

 void Target::setPosition(){
     zI = (rand() % 20) * -1;
     z = zI;
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
 }

void Target::setColor(){
/* According to the current level, it assigns a color. */
    int rndC;
    if(level == 1){
         rndC = rand() % 2 ;
         color = colors[rndC];
    } else {
        rndC = rand() % 3;
         color = colors[rndC];
    }
}

void Target::setWindow(int w, int h){
/* When the user reshapes the window. */
    width = w;
    height = h;
}

void Target::setLevel(int l){
/* Changes the current level. */
    level = l;
}
#endif // TARGET_H
