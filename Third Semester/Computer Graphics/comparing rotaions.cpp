
#include <GL/glut.h>

int x, y;
int width, height;
int win_width = 800;
int win_height = 600;

void drawRectangle()
{
    glColor3f(0.0, 0.0, 0.0); // Black color
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2i(-800, 0);
    glVertex2i(800, 0);
    glVertex2i(0, -600);
    glVertex2i(0, 600);
    glEnd();

    x = 100;
    y = 100;
    width = 100;
    height = 50;

    // Original rectangle
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    // Rotated Rectangle
    // glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
    // glColor3f(0.0, 1.0, 0.0); // Green color
    // glBegin(GL_POLYGON);
    // glVertex2f(x, y);
    // glVertex2f(x + width, y);
    // glVertex2f(x + width, y + height);
    // glVertex2f(x, y + height);
    // glEnd();

    // Rotated Rectangle
    glTranslatef(150.0f, 125.0f, 0.0f);
    glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
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

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(win_width, win_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotate Rectangle - Aakash Dhakal");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-100, win_width, -100, win_height);
    glutDisplayFunc(drawRectangle);
    glutMainLoop();

    return 0;
}
