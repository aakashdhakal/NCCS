#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

float x, y;
float width, height;
int win_width = 800;
int win_height = 600;

void drawRectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
}

void rotate()
{
    float theta = (30 * 3.14159265) / 180.0;
    float rotationMatrix[3][3] = {cos(theta), -sin(theta), 0, sin(theta), cos(theta), 0, 0, 0, 1};
    float originalVertex[3][4] = {x, y, 1, x + width, y, 1, x + width, y + height, 1, x, y + height, 1};
    float finalVertex[3][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                finalVertex[i][j] += rotationMatrix[i][k] * originalVertex[k][j];
            }
        }
    }
    float x1 = finalVertex[0][0];
    float y1 = finalVertex[1][0];

    // Rotated rectangle
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x1 + width, y1);
    glVertex2f(x1 + width, y1 + height);
    glVertex2f(x1, y1 + height);
    glEnd();
    glFlush();
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

    rotate();

    // Original rectangle
    glColor3f(1.0, 0.0, 0.0); // Red color
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
    glutInitWindowSize(win_width, win_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotate Rectangle Without Using Function - Aakash Dhakal");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-100, win_width, -100, win_height);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
