
#include <GL/glut.h>

int x, y;
int width, height;

void drawRectangle()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Original rectangle
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    //Rotated Rectangle
    glScalef(2.0f,2.0f,0.0f);
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    x = 100;
    y = 100;
    width = 100;
    height = 50;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotate Rectangle - Aakash Dhakal");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 800, 0, 600);
    glutDisplayFunc(drawRectangle);
    glutMainLoop();

    return 0;
}
