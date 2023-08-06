//not completed

#include <GL/glut.h>

int wx_max = 80, wy_max = 40, wx_min = 50, wy_min = 10;

int getCode(int x, int y)
{
    int code = 0000;

    if (x < wx_min)
        code |= 0001;
    else if (x > wx_max)
        code |= 0010;
    if (y < wy_min)
        code |= 0100;
    else if (y > wy_max)
        code |= 1000;

    return code;
}
void drawline(int x1, int y1, int x2, int y2)
{
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f); // black

    // Draw the window
    drawline(wx_min, wy_min, wx_max, wy_min);
    drawline(wx_min, wy_min, wx_min, wy_max);
    drawline(wx_max, wy_min, wx_max, wy_max);
    drawline(wx_min, wy_max, wx_max, wy_max);

    int x1 = 70, x2 = 100, y1 = 20, y2 = 10;
    int code1 = getCode(x1, y1);
    int code2 = getCode(x2, y2);
    glColor3f(0.0f, 1.0f, 0.0f); // green

    // Draw the original line
    drawline(x1, y1, x2, y2);

    // Check if the line is completely inside or outside the window
    if ((code1 & code2) == 0000)
    {
        glColor3f(1.0f, 0.0f, 0.0f); // red

        // Clipping variables
        int code;
        float m = (float)(y2 - y1) / (float)(x2 - x1);
        float c = y1 - m * x1;

        // Find the intersection points
        if (code1 != 0000)
            code = code1;
        else
            code = code2;

        if (code & 0001) // Left boundary
        {
            y1 = m * wx_min + c;
            x1 = wx_min;
        }
        else if (code & 0010) // Right boundary
        {
            y1 = m * wx_max + c;
            x1 = wx_max;
        }
        else if (code & 0100) // Bottom boundary
        {
            x1 = (wy_min - c) / m;
            y1 = wy_min;
        }
        else if (code & 1000) // Top boundary
        {
            x1 = (wy_max - c) / m;
            y1 = wy_max;
        }

        // Draw the clipped line (inside the window)
        glColor3f(1.0f, 0.0f, 0.0f); // red
        drawline(x1, y1, x2, y2);
    }

    glFlush();
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
