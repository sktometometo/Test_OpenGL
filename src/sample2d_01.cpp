
#include <GL/gl.h>
#include <GL/glut.h>

int pointSize = 1;

void display()
{
    // Clear the buffer
    glClear( GL_COLOR_BUFFER_BIT );

    // Display a polygon
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

    // Plot points
    glPointSize(pointSize);
    glBegin(GL_POINTS);
    {
        glVertex2f(0 , -0.9);
        glVertex2f(-0.9 , 0.9);
        glVertex2f(0.9 , 0.9);
    }
    glEnd();

    // Draw lines
    float width;
    glGetFloatv(GL_LINE_WIDTH , &width);
    glLineWidth(++width);
    glBegin(GL_LINE_LOOP);
    {
        glVertex2f(0 , -0.9);
        glVertex2f(-0.9 , 0.9);
        glVertex2f(0.9 , 0.9);
    }
    glEnd();

    // Draw triangles
    glBegin( GL_TRIANGLES );
    {
        glVertex2f(   0,   0 );
        glVertex2f(  -1, 0.9 );
        glVertex2f(   1, 0.9 );

        glVertex2f(   0,   0 );
        glVertex2f(  -1,-0.9 );
        glVertex2f(   1,-0.9 );
    }
    glEnd();

    // Draw color triangles
    glBegin(GL_TRIANGLES);
    {
        glColor3ub(0xFF , 0 , 0);
        glVertex2f(0 , 0);
        glColor3f(0 , 0 , 1);
        glVertex2f(-1 , 0.9);
        glVertex2f(1 , 0.9);

        glColor3i(2147483647 , 0 , 0);
        glVertex2f(0 , 0);
        glColor3b(0 , 127 , 0);
        glVertex2f(-1 , -0.9);
        glVertex2f(1 , -0.9);
    }
    glEnd();

    // Draw a rectangle with simple functions
     glColor3f(0 , 0 , 1);
     glRectf(-0.8 , 0.8 , 0.8 , -0.8);

    //
    glFlush();
}

int main(int argc , char ** argv)
{
    glutInit(&argc , argv);
    glutInitWindowPosition(100 , 50);
    glutInitWindowSize(400 , 300);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    
    glutCreateWindow("Kitty on your lap");
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}
