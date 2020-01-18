#include <GL/gl.h>
#include <GL/glut.h>

void disp()
{
    glClear( GL_COLOR_BUFFER_BIT );

    glBegin( GL_POLYGON );
    {
        glEdgeFlag( GL_TRUE  ); glVertex2f( -0.9 , -0.5  );
        glEdgeFlag( GL_TRUE  ); glVertex2f( -0.85,  0.9  );
        glEdgeFlag( GL_FALSE ); glVertex2f(  0   ,  0.3  );
        
        glEdgeFlag( GL_TRUE  ); glVertex2f( -0.9 , -0.5  );
        glEdgeFlag( GL_FALSE ); glVertex2f(  0.9 , -0.5  );
        glEdgeFlag( GL_TRUE  ); glVertex2f(  0   ,  0.3  );

        glEdgeFlag( GL_TRUE  ); glVertex2f(  0.85,  0.9  );
        glEdgeFlag( GL_FALSE ); glVertex2f(  0.9 , -0.5  );
        glEdgeFlag( GL_FALSE ); glVertex2f(  0   ,  0.3  );
    }
    glEnd();

    glFlush();
}

int main(int argc , char ** argv)
{
    glutInit(&argc , argv);
    glutInitWindowPosition(100 , 50);
    glutInitWindowSize(400 , 300);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    
    glutCreateWindow("Kitty on your lap");
    glutDisplayFunc(disp);
    
    glutMainLoop();
    return 0;
}
