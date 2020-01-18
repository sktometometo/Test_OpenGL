#include <cstdio>

#include <GL/gl.h>
#include <GL/glut.h>

int pointSize = 1;

void disp( void )
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(pointSize);
    glBegin(GL_POINTS);
    {
        glVertex2f(0 , -0.9);
        glVertex2f(-0.9 , 0.9);
        glVertex2f(0.9 , 0.9);
    }
    glEnd();

glFlush();
}

int main(int argc , char ** argv)
{
    if (argc >= 2)
        sscanf(argv[1] , "%d" , &pointSize);

    glutInit(&argc , argv);
    glutInitWindowPosition(100 , 50);
    glutInitWindowSize(400 , 300);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    glutCreateWindow("Kitty on your lap");
    glutDisplayFunc(disp);

    glutMainLoop();
    return 0;
}
