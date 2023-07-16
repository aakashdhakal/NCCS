
#include <iostream>
#include <GL/glut.h>
using namespace std;

int xi, yi, radius;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x + xi, y + yi);
    glEnd();
}

void drawCircle()
{
    int x = 0;
    int y = radius;
    float decision = 1 - radius;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);
    plot(x, y);

    while (x <= y)
    {
        x++;
        if (decision < 0)
        {
            decision += 2 * x + 1;
        }
        else
        {
            y--;
            decision += 2 * (x - y) + 1;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
    glFlush();
}

int main(int argc, char **argv)
{
    cout << "Enter the coordinates of the center (x,y): ";
    cin >> xi >> yi;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Line Drawing Alogrithms");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glutDisplayFunc(drawCircle);
    glutMainLoop();
}
