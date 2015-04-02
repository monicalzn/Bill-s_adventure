
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif
#include "GameT.h"

int level = 1;
double y=1, x2=1, y2=1;
double z=-10;
float x=0;
double width, height;
GameT game;
char color;
#include <iostream>
using namespace std;

void init(void)
{
    glClearColor (0.0, 1.0, 1.0, 0.0);
    glShadeModel (GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


    glColor3ub(255,135,100);
    glPointSize(10.0f);
    glBegin(GL_POINTS);
        if(color == 'b'){
            glColor3ub(35, 100, 245);
        } else if(color == 'r'){
            glColor3ub(245, 100, 35);
        } else {
            glColor3ub(10, 200, 35);
        }
        glVertex3d(0,0,0);
        //left corner
        glVertex3d(-1, .5, 2);
        //right corner
        glColor3ub(255,0,0);
        glVertex3d(1, .5, 0);
        //left
        glColor3ub(0,255,0);
        glVertex3d(-1,-0.25, 0);
        //right
        glColor3ub(0,0,255);
        glVertex3d(1,-0.25, 0);
        //center
        glColor3ub(0,135,0);
        glVertex3d(0, 0.5, 0);
    glEnd();

    glPushMatrix();
    glScalef(24,24,24);
    glTranslated(0,-11,-5);
    glColor3ub(110,10,255);
    glutSolidSphere(5.0,16,16);
    glPopMatrix();

    glColor3ub(255,135,100);
    glPointSize(10.0f);
    game.draw();

    glutSwapBuffers();
}

void timer (int v)
{
    z += .5;
    glutPostRedisplay();
    glutTimerFunc(100, timer, 1);

}

void reshape (int w, int h)
{
    width = w;
    height = h;
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();


    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    //alejamos la camara
    /*Frustum top part is smaller to have the center higher */
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20);
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);


}

void clic(int button, int state, int x, int y)
{
}

void key_Stroke(unsigned char key, int xs, int ys)
{
    switch(key){
        case 'i':
            game = GameT();
            color = game.getColor();
            break;

        case 'l':
        case 's':
        case 'c':
        case 'o':
        case 'r':
            if(game.checkHit(key)){
                cout << "HIIIT" << endl;
            }
            break;

        case 'j':
        /* Only way the player can change color is by jumping */
            game.changeColor();
            color = game.getColor();
            break;

        case 'q':
        case 'Q':
        case 27:
            exit(0);
            break;
    }

}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_DOUBLE| GLUT_RGB| GLUT_DEPTH);
    glutInitWindowSize (600, 480);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(clic);
    glutTimerFunc(300, timer, 1);

    glutKeyboardFunc(key_Stroke);
    glutMainLoop();
    return 0;
}



