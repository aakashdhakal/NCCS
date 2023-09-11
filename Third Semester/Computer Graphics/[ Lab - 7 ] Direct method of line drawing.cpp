#include <GL/glut.h>

#include <iostream>

#include <cmath>

using namespace std;
float xi, yi, xf, yf;
void plotPixel() {
	float x, y, dx, dy, m, c, xend;
	dx = xf - xi;
	dy = yf - yi;
	m = dy / dx;
	c = yi - m * xi;
	if(xi > xf) {
		x = xf;
		y = yf;
		xend = xi;
	} else {
		x = xi;
		y = yi;
		xend = xf;
	}
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	while(x <= xend) {
		glVertex2f(round(x), round(y));
		x += 1;
		y = m * x + c;
	}
	glEnd();
	glFlush();
}
int main(int argc, char * argv[]) {
	cout << "Enter the initial points: ";
	cin >> xi >> yi;
	cout << "Enter the final points: ";
	cin >> xf >> yf;
	glutInit( & argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Drawing Shapes");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	glutDisplayFunc(plotPixel);
	glutMainLoop();
	return 0;
}
