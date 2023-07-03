//Code is not completed so it is not working
#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

void plotPixel()
{
    float xi, yi, xf, yf, x, y, xinc, yinc,dx,dy;
    int steps,i;
    cout << "Enter the initial points: ";
    cin >> xi >> yi;
    cout << "Enter the final points: ";
    cin >> xf >> yf;
    x = xi;
    y = yi;
    dx = xf - xi;
    dy = yf - yi;
    if(abs(dx) > abs(dy)){
    	steps = abs(dx);
	}
	else{
		steps = abs(dy);
	}
    xinc = dx/(float)steps;
    yinc = dy/(float)steps;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
	i = 0;
    while (i <= steps) {
        glVertex2f(round(x), round(y));
        x += xinc;
        y += yinc;
        i++;
    }

    glEnd();
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Drawing Shapes");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glutDisplayFunc(plotPixel);
    glutMainLoop();
    
    return 0;
}
