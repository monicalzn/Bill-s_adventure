
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

int opcion = 2;
double y=1, x2=1, y2=1;
double z=-10;
float x=0;
float angulo=0;

#include <stdlib.h>

void init(void)
{
    glClearColor (0.0, 1.0, 1.0, 0.0);
    glShadeModel (GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


    glColor3ub(255,135,100);
    glPointSize(10.0f);
    glBegin(GL_POINTS);
        glVertex3d(1,1,-20);
        glVertex3d(500, 500, 2+z);
        glVertex3d(-500, 500, -1+z);
        glVertex3d(500, -500, 12+z);
        glVertex3d(-500, -500, -12+z);
    glEnd();

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
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();


    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    //alejamos la camara
    glFrustum(-w, w, -h, h,1,20);

    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);


}

void clic(int button, int state, int x, int y)
{
    if (button==GLUT_LEFT_BUTTON&& state==GLUT_DOWN)
    {
        opcion= 1;
        reshape(500,500);
    }

    else
        if (button==GLUT_RIGHT_BUTTON&& state==GLUT_DOWN)
        {
            opcion= 2;
            reshape(500,500);
        }
}

void key_Stroke(unsigned char key, int xs, int ys)
{
    if (key == 'i' || key =='I')
    {
        y=1, x2=1, y2=1;
        x=0;
        angulo=0;

    }
    else
        if (key == 'q' || key =='Q')
        {
            exit(0);  //#include <stdlib.h>
        }

}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_DOUBLE| GLUT_RGB| GLUT_DEPTH);
    glutInitWindowSize (500, 500);
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



