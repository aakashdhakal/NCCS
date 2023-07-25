
#include <GL/glut.h>

int x, y;
int width, height;
int win_width = 800;
int win_height = 600;

void drawRectangle()
{
    glClear(GL_COLOR_BUFFER_BIT);
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

    // Scaled Rectangle
    float x1, y1, x2, y2, x3, y3, x4, y4, sx = 2.0, sy = 2.0;
    x1 = x * sx;
    y1 = y * sy;
    x2 = (x + width) * sx;
    y2 = y * sy;
    x3 = (x + width) * sx;
    y3 = (y + height) * sy;
    x4 = x * sx;
    y4 = (y + height) * sy;

    glColor3f(0.0, 0.0, 1.0); // Blue color
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
    glutCreateWindow("Scale Rectangle - Aakash Dhakal");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-100, win_width, -100, win_height);
    glutDisplayFunc(drawRectangle);
    glutMainLoop();

    return 0;
}
