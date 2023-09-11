#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

float x, y;
float width, height;
int win_width = 800;
int win_height = 600;

void drawRectangle(float rectangleMatrix[][4])
{
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 4; i++)
    {
        glVertex2f(rectangleMatrix[0][i], rectangleMatrix[1][i]);
    }
    glEnd();
    glFlush();
}

void scale()
{
    float originalVertex[3][4] = {{x, x + width, x + width, x}, {y, y, y + height, y + height}, {1, 1, 1, 1}};

    glColor3f(0.0f, 0.0f, 0.0f);
    drawRectangle(originalVertex);

    glScalef(sx, sy, 1.0);

    glColor3f(0.5f, 0.5f, 0.5f);
    drawRectangle(originalVertex);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Black color
    glBegin(GL_LINES);
    glVertex2i(-800, 0);
    glVertex2i(800, 0);
    glVertex2i(0, -600);
    glVertex2i(0, 600);
    glEnd();
    glFlush();
    scale();
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
    glutCreateWindow("Rotate Rectangle Without Using Function - Aakash Dhakal");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-100, win_width, -100, win_height);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
