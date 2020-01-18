#include <iostream>
#include <string>

#include <GL/gl.h>
#include <GL/glut.h>

void disp( void ) {
	glClearColor(1 , 1 , 1 , 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0 , 0 , 1);
	glRectf(-0.8 , 0.8 , 0.8 , -0.8);

        glFlush();
}

int main(int argc , char ** argv) {
	glutInit(&argc , argv);
	glutInitWindowPosition(100 , 50);
	glutInitWindowSize(400 , 300);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutCreateWindow("Kitty on your lap");
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}
