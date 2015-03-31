
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif
#include "GameT.h"

int opcion = 2;
double y=1, x2=1, y2=1;
double z=-10;
float x=0;
float angulo=0;
double width, height;
GameT game;
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
        glVertex3d(0,0,0);
        //left corner
        glVertex3d(-600, height/2, 0);
        //right corner
        glColor3ub(255,0,0);
        glVertex3d(600, height/2, 0);
        //left
        glColor3ub(0,255,0);
        glVertex3d(-600,-height/4, 0);
        //right
        glColor3ub(0,0,255);
        glVertex3d(600,-height/4, 0);
        //center
        glColor3ub(0,135,0);
        glVertex3d(0,height/2, 0);
    glEnd();

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
    glFrustum(-w, w, -h, h/2,4,70);
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);


}

void clic(int button, int state, int x, int y)
{
}

void key_Stroke(unsigned char key, int xs, int ys)
{
    switch(key){
        case 'l':
        case 's':
        case 'c':
        case 'o':
        case 'r':
            if(game.checkHit(key)){
                cout << "HIIIT" << endl;
            }
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



