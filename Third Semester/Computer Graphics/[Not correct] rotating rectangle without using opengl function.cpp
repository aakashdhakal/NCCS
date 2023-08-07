#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

float x, y;
float width, height;
int win_width = 800;
int win_height = 600;

void rotate()
{
    float theta = (30 * 3.14159265) / 180.0;
    float rotationMatrix[3][3] = {cos(theta), -sin(theta), 0, sin(theta), cos(theta), 0, 0, 0, 1};
    float originalVertex[3][4] = {x, y, 1, x + width, y, 1, x + width, y + height, 1, x, y + height, 1};
    float finalVertex[3][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            glVertex2f(rotationMatrix[0][i],rotationMatrix[1][j]);
        }
    }
    glEnd();
    glFlush();

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
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    for (int i=0;i<3;i++){
        for(int j =0;j<3;j++){
            glVertex2f(finalVertex[0][i],finalVertex[j][1]);
        }
    }
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
