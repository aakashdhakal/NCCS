#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;
float xf, yf, xi, yi;
void drawLine()
{
    float steps, dx = xf - xi, dy = yf - yi;
    if (abs(dx) < abs(dy))
    {
        steps = abs(dy);
    }
    else
    {
        steps = abs(dx);
    }
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;
    float x = xi;
    float y = yi;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(round(x), round(y));

    for (int i = 0; i <= steps; i++)
    {
        x += xIncrement;
        y += yIncrement;
        glVertex2f(round(x), round(y));
    }

    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    cout << "Enter the initial point (x1, y1): ";
    cin >> xi >> yi;
    cout << "Enter the final point (x2, y2): ";
    cin >> xf >> yf;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("DDA Algorithm - Aakash Dhakal");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glutDisplayFunc(drawLine);
    glutMainLoop();
    return 0;
}
