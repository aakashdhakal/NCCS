#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

int xc, yc, rx, ry;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glEnd();
}

void drawEllipse()
{
    int x = 0;
    int y = ry;
    float decision = pow(ry, 2) - pow(rx, 2) * ry;

    int dx = 2 * pow(ry, 2) * x;
    int dy = 2 * pow(rx, 2) * y;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    plot(x, y);
    while (dx < dy)
    {

        if (decision < 0)
        {
            x++;
            dx += 2 * pow(ry, 2);
            decision += dx + pow(ry, 2);
        }
        else
        {
            x++;
            y--;
            dx += 2 * pow(ry, 2);
            dy -= 2 * pow(rx, 2);
            decision += dx - dy + pow(ry, 2);
        }
        plot(x, y);
    }

    decision = pow(ry, 2) * pow(x, 2) + pow(rx, 2) * pow(y - 1, 2) - pow(rx, 2) * pow(ry, 2);
    while (y >= 0)
    {

        if (decision > 0)
        {
            y--;
            dy -= 2 * pow(rx, 2);
            decision += pow(rx, 2) - dy;
        }
        else
        {
            x++;
            y--;
            dx += 2 * pow(ry, 2);
            dy -= 2 * pow(rx, 2);
            decision += dx - dy + pow(rx, 2);
        }
        plot(x, y);
    }

    glFlush();
}

int main(int argc, char *argv[])
{
    cout << "Enter the center coordinates (xc, yc): ";
    cin >> xc >> yc;
    cout << "Enter the x-radius (rx): ";
    cin >> rx;
    cout << "Enter the y-radius (ry): ";
    cin >> ry;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Mid-point Ellipse Drawing Algorithm - Aakash Dhakal");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glutDisplayFunc(drawEllipse);
    glutMainLoop();

    return 0;
}
