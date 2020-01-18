/* Standard c++ headers */
#include <iostream>
#include <string>

/* OpenGL headers */
#include <GL/gl.h>
#include <GL/glut.h>

/* Boost headers */
#include <boost/program_options.hpp>

/* Eigen headers */
#include <Eigen/Dense>

/* stl_reader */
#include <stl_reader.h>

std::string filename_stl("hoge.stl");
std::string title("stl load example");
Eigen::Vector3f posSTL;
Eigen::Vector3f posCam;
float radiusPosCam;
stl_reader::StlMesh<float, unsigned int> stl_model;
GLfloat lightPos[] = { 0, 0, 0, 0 };
GLfloat lightCol[] = { 1, 1, 1, 1 };
GLfloat angle = 0.0f;     // Rotational angle for cube [NEW]

int duration_refresh_millisec = 50; // for Animation

bool parse_args( int argc,
                 char** argv,
                 std::string& filename )
{
    try
    {
        boost::program_options::options_description desc("Program Usage", 1024, 512);
        desc.add_options()
          ("help,h", "produce help message")
          ("file,f",   boost::program_options::value<std::string>(&filename), "stl file")
        ;

        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);

        if (vm.count("help") or not vm.count("file"))
        {
            std::cout << desc << "\n";
            return false;
        }
    }
    catch(std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return false;
    }
    catch(...)
    {
        std::cerr << "Unknown error!" << "\n";
        return false;
    }

    return true;
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );

    glLoadIdentity();
    glTranslatef( posSTL(0), posSTL(1), posSTL(2) );
    glRotatef( angle, 1.0f, 1.0f, 1.0f);

    glBegin( GL_TRIANGLES );
    {
        for ( size_t itri = 0; itri < stl_model.num_tris(); ++itri ) {
            const float *n = stl_model.tri_normal(itri);
            glNormal3f( n[0], n[1], n[2] );
            for ( size_t icorner = 0; icorner < 3; ++icorner ) {
                const float *c = stl_model.tri_corner_coords( itri, icorner );
                glVertex3f( c[0], c[1], c[2] );
            }
        }
    }
    glEnd();

    glutSwapBuffers();

    angle += 0.1f;
}

void timer(int value)
{
    std::cout << "refreshed." << std::endl;
    glutPostRedisplay();
    glutTimerFunc( duration_refresh_millisec, timer, 0);
}

void reshape( GLsizei width, GLsizei height )
{
    if ( height == 0 ) {
        height = 1;
    }
    GLfloat aspect = (GLfloat) width / (GLfloat) height;

    /* Configuring viewport
     * this section configuring where to display in the window
     */
    glViewport( 0, 0, width, height );

    /* Configuring projection matrix
     * 
     * This section configuring how large FOV is and How far display region is.
     */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 80.0f, aspect, 0.1f, 3 * radiusPosCam );

    // Configuring point of view
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt( posCam(0), posCam(1), posCam(2), // 視点位置
               posSTL(0), posSTL(1), posSTL(2), // 注視点
                       0,         0,         1
              );
}

bool loadSTLMode( std::string filename,
                  stl_reader::StlMesh<float, unsigned int> &mesh )
{
    try {
        mesh = stl_reader::StlMesh<float, unsigned int>( filename.c_str() );
        return true;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

float getBoundingRadius( stl_reader::StlMesh<float, unsigned int> &mesh )
{
    float ret = 0.0f;
    float dist;
    for ( size_t itri = 0; itri < mesh.num_tris(); ++itri ) {
        for ( size_t icorner = 0; icorner < 3; ++icorner ) {
            const float *c = mesh.tri_corner_coords( itri, icorner );
            dist = c[0] * c[0] + c[1] * c[1] + c[2] * c[2];
            if ( dist > ret ) {
                ret = dist;
            }
        }
    }
    return ret;
}

int main( int argc, char **argv )
{
    if ( not parse_args( argc, argv, filename_stl ) ) {
        std::cerr << "Aborting..." << std::endl;
        return 1;
    }

    if ( not loadSTLMode( filename_stl, stl_model ) ) {
        std::cerr << "Cannot load stl model " << filename_stl << std::endl;
        return 1;
    }

    radiusPosCam = 100 * getBoundingRadius( stl_model );

    lightPos[2] = 5 * radiusPosCam;

    posSTL << 0, 0, 0;
    posCam << radiusPosCam, 0, 0;

    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title.c_str());          // Create window with the given title

    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event

    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glClearDepth( 1.0f );

    glLightfv( GL_LIGHT0, GL_POSITION, lightPos );
    glLightfv( GL_LIGHT0, GL_DIFFUSE,  lightCol );
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );

    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glShadeModel( GL_SMOOTH );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

    glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]

    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
