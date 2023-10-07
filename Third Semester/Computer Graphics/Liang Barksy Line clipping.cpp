#include <iostream>
#include <GL/glut.h>
using namespace std;

int wx_max, wy_max, wx_min, wy_min;
float x_1, x_2, y_1, y_2;

float max(float a, float b, float c)
{
    if (a > b && a > c)
    {
        return a;
    }
    else if (b > a && b > c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

float min(float a, float b, float c)
{
    if (a < b && a < c)
    {
        return a;
    }
    else if (b < a && b < c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

void liang_barksy()
{
    float t1 = 0, t2 = 1, p[4], q[4], dx = x_2 - x_1, dy = y_2 - y_1;

    p[1] = -dx;
    p[2] = dx;
    p[3] = -dy;
    p[4] = dy;

    q[1] = x_1 - wx_min;
    q[2] = wx_max - x_1;
    q[3] = y_1 - wy_min;
    q[4] = wy_max - y_1;

    for (int i = 1; i <= 4; i++)
    {
        if (p[i] < 0)
        {
            t1 = max(0, t1, q[i] / p[i]);
        }
        else if (p[i] > 0)
        {
            t2 = min(1, t2, q[i] / p[i]);
        }
    }
    float x = x_1, y = y_1;

    x_1 = x + t1 * dx;
    x_2 = x + t2 * dx;
    y_1 = y + t1 * dy;
    y_2 = y + t2 * dy;
}
void drawline(int x1, int y1, int x2, int y2)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f); // black
    glLineWidth(2.0);
    // Draw the window
    glBegin(GL_LINE_LOOP);
    glVertex2i(wx_min, wy_min);
    glVertex2i(wx_max, wy_min);
    glVertex2i(wx_max, wy_max);
    glVertex2i(wx_min, wy_max);
    glEnd();

    // Draw the line
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
    glFlush();
}
void display()
{

    drawline(x_1, y_1, x_2, y_2);
    Sleep(2000);
    liang_barksy();
    cout << "After clipping: " << endl;
    cout << "x1 = " << x_1 << " y1 = " << y_1 << endl;
    cout << "x2 = " << x_2 << " y2 = " << y_2 << endl;
    drawline(x_1, y_1, x_2, y_2);
}

int main(int argc, char **argv)
{
    cout << "Enter the window coordinates (wx_min,wy_min,wx_max,wy_max): ";
    cin >> wx_min >> wy_min >> wx_max >> wy_max;
    cout << "Enter the line coordinates (x1,y1,x2,y2): ";
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Liang-Barksy - Aakash Dhakal");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 200, -20, 200);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
