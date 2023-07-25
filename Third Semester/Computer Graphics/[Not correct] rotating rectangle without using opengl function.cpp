
#include <GL/glut.h>
#include <cmath>

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

    // Original rectangle
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
    glFlush();

    // Rotated Rectangle
    glColor3f(0.0, 0.0, 1.0); // Blue color
    float x1, y1, x2, y2, x3, y3, x4, y4;
    float theta = (30 * 3.14159265) / 180.0;
    x1 = x * cos(theta) - y * sin(theta);
    y1 = x * sin(theta) + y * cos(theta);
    x2 = (x + width) * cos(theta) - y * sin(theta);
    y2 = (x + width) * sin(theta) + y * cos(theta);
    x3 = (x + width) * cos(theta) - (y + height) * sin(theta);
    y3 = (x + width) * sin(theta) + (y + height) * cos(theta);
    x4 = x * cos(theta) - (y + height) * sin(theta);
    y4 = x * sin(theta) + (y + height) * cos(theta);

    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
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
    glutInitWindowSize(win_width, win_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotate Rectangle - Aakash Dhakal");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-100, win_width, -100, win_height);
    glutDisplayFunc(drawRectangle);
    glutMainLoop();

    return 0;
}
