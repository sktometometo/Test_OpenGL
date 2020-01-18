#include <iostream>

#include <GL/gl.h>
#include <GL/glut.h>

GLfloat fore[4] , back[4];

void disp( void ) {
	glClearColor(back[0] , back[1] , back[2] , back[3]);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3fv(fore);
	glBegin(GL_TRIANGLES);
		glVertex2f(0 , -0.9);
		glVertex2f(-0.9 , 0.9);
		glVertex2f(0.9 , 0.9);
	glEnd();

	glFlush();
}

int main(int argc , char ** argv) {
	glutInit(&argc , argv);
	glutInitWindowPosition(100 , 50);
	glutInitWindowSize(400 , 300);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutCreateWindow("Kitty on your lap");
	glutDisplayFunc(disp);

	glGetFloatv(GL_CURRENT_COLOR , back);
	glGetFloatv(GL_COLOR_CLEAR_VALUE , fore);

	glutMainLoop();
	return 0;
}
