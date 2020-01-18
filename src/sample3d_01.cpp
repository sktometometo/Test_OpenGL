// c++
#include <iostream>


// OpenGL
#include <GL/gl.h>
#include <GL/glut.h>

/* Reference
 *
 * - https://www.ntu.edu.sg/home/ehchua/programming/opengl/CG_examples.html
 *
 */


void reshape( GLsizei width, GLsizei height )
{
    if ( height == 0 ) {
        height = 1;
    }

    GLfloat aspect = (GLfloat) width / (GLfloat) height;

    glViewport( 0, 0, width, height );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 45.0f, aspect, 0.1f, 100.0f );
}

int main( int argc, char **argv )
{
    std::string windowname("sample");

    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutInitWindowPosition( 50, 50 );
    glutCreateWindow( windowname.c_str() );
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    init();

    glutMainLoop();

    return0;
}
