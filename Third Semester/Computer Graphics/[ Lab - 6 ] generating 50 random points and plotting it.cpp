#include <GL/glut.h>

int windowWidth = 800;
int windowHeight = 600;
void plotPoint()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f); // Black points
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < 50; i++)
    {
        glVertex2f(rand() % windowWidth, rand() % windowHeight);
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Draw 50 Random Points - Aakash Dhakal");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(plotPoint);
    glutMainLoop();
    return 0;
}
