#include <GL/gl.h>
#include <GL/glut.h>

void disp( void ) {
	float width;
	glGetFloatv(GL_LINE_WIDTH , &width);

	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(++width);
	glBegin(GL_LINE_LOOP);
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

	glutMainLoop();
	return 0;
}
