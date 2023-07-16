#include <GL/glut.h>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

float xi, yi, xf, yf;

void bresenham()
{
    float x, y, dx, dy, p, xend;
    dx = xf - xi;
    dy = yf - yi;
    if (dx < 0)
    {
        dx = -dx;
    }
    if (dy < 0)
    {
        dy = -dy;
    }
    if (xi > xf)
    {
        x = xf;
        y = yf;
        xend = xi;
    }
    else
    {
        x = xi;
        y = yi;
        xend = xf;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    if (dx < dy)
    {
        p = 2 * dx - dy;
        while (x <= xend)
        {

            if (p < 0)
            {
                p += 2 * dx;
            }
            else
            {
                p += 2 * (dx - dy);
                y += (yf > yi) ? 1 : -1;
            }
            x += 1;
            glVertex2f(x, y);
        }
    }
    else
    {
        p = 2 * dy - dx;
        while (x <= xend)
        {

            if (p < 0)
            {
                p += 2 * dy;
            }
            else
            {
                p += 2 * (dy - dx);
                x += (xf > xi) ? 1 : -1;
            }
            y += 1;
            glVertex2f(x, y);
        }
    }
    glEnd();
    glFlush();
}

void dda()
{
    int steps;
    int dx = xf - xi;
    int dy = yf - yi;
    if (abs(dx) >= abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }
    float xIncrement = (float)dx / (float)steps;
    float yIncrement = (float)dy / (float)steps;
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

void direct()
{
    float x, y, dx, dy, m, c, xend;
    dx = xf - xi;
    dy = yf - yi;
    m = dy / dx;
    c = yi - m * xi;
    if (xi > xf)
    {
        x = xf;
        y = yf;
        xend = xi;
    }
    else
    {
        x = xi;
        y = yi;
        xend = xf;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(round(x), round(y));
    while (x <= xend)
    {

        x += 1;
        y = m * x + c;
        glVertex2f(round(x), round(y));
    }
    glEnd();
    glFlush();
}

void plotPixel()
{
    clock_t dda_start, dda_end, bresenham_start, bresenham_end, direct_start, direct_end;

    dda_start = clock();
    dda();
    dda_end = clock();
    bresenham_start = clock();
    bresenham();
    bresenham_end = clock();
    direct_start = clock();
    direct();
    direct_end = clock();

    cout << endl;
    cout << "The time taken by DDA is " << (float)(dda_end - dda_start) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "The time taken by Bresenham is " << (float)(bresenham_end - bresenham_start) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "The time taken by Direct is " << (float)(direct_end - direct_start) / CLOCKS_PER_SEC << " seconds" << endl;
}

int main(int argc, char *argv[])
{
    cout << "Enter the initial points: ";
    cin >> xi >> yi;
    cout << "Enter the final points: ";
    cin >> xf >> yf;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Algorithm - Aakash Dhakal");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glutDisplayFunc(plotPixel);
    glutMainLoop();

    return 0;
}
