#include <GL/glut.h>

int x, y;
int width, height;

void drawRectangle()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Original rectangle
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + width, y);
    glVertex2i(x + width, y + height);
    glVertex2i(x, y + height);
    glEnd();

    // Translated rectangle
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glTranslatef(20, 20, 0);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + width, y);
    glVertex2i(x + width, y + height);
    glVertex2i(x, y + height);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    x = 100;
    y = 100;
    width = 200;
    height = 150;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Translate Rectangle - Aakash Dhakal");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 800, 0, 600);
    glutDisplayFunc(drawRectangle);
    glutMainLoop();

    return 0;
}
