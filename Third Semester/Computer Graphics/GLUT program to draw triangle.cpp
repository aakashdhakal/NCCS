#include <GL/gl.h>
#include <GL/glut.h>

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();
	glFlush();
}

int main(int argc, char *argv[]){
	 glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);    
    glutInitWindowSize(500,500);       
    glutInitWindowPosition(100,100);    
    glutCreateWindow("Hello World"); 
    glutDisplayFunc(draw);           
    
    glutMainLoop(); // Run the event loop!  This function does not return.
                    // Program ends when user closes the window.
    return 0;
}
