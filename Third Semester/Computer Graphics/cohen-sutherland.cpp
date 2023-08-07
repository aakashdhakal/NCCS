#include <GL/glut.h>

int wx_max = 100, wy_max = 100, wx_min = 50, wy_min = 50;
int x_1 = 40, x_2 = 100, y_1 = 50, y_2 = 150;

int getCode(int x, int y)
{
    int code = 0000;

    if (x < wx_min)
        code |= 1;
    else if (x > wx_max)
        code |= 2;
    if (y < wy_min)
        code |= 4;
    else if (y > wy_max)
        code |= 8;

    return code;
}
void drawline(int x_1, int y_1, int x_2, int y2)
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
    glVertex2i(x_1, y_1);
    glVertex2i(x_2, y2);
    glEnd();
    glFlush();
}
void cohen_sutherland()
{

    int code1 = getCode(x_1, y_1);
    int code2 = getCode(x_2, y_2);
    bool accept = false;

    do
    {
        // Check if the line is completely inside or outside the window
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            glColor3f(1.0f, 0.0f, 0.0f); // red

            // Clipping variables
            int code;
            float m = (float)(y_2 - y_1) / (float)(x_2 - x_1);
            float c = y_1 - m * x_1;
            float x, y;

            // Find the intersection points
            if (code1 != 0)
                code = code1;
            else
                code = code2;

            if (code & 1) // Left boundary
            {
                y = m * wx_min + c;
                x = wx_min;
            }
            else if (code & 2) // Right boundary
            {
                y = m * wx_max + c;
                x = wx_max;
            }
            else if (code & 4) // Bottom boundary
            {
                x = (wy_min - c) / m;
                y = wy_min;
            }
            else if (code & 8) // Top boundary
            {
                x = (wy_max - c) / m;
                y = wy_max;
            }

            if (code == code1)
            {
                x_1 = x;
                y_1 = y;
                code1 = getCode(x_1, y_1);
            }
            else
            {
                x_2 = x;
                y_2 = y;
                code2 = getCode(x_2, y_2);
            }
        }
    } while (accept == false);
}
void display()
{

    drawline(x_1, y_1, x_2, y_2);
    Sleep(1000);
    cohen_sutherland();
    drawline(x_1, y_1, x_2, y_2);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Line Clipping - Cohen-Sutherland");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 200, -20, 200);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
