#include <GL/glut.h>

#include <iostream>

#include <cmath>

using namespace std;
float xi, yi, xf, yf;
void plotPixel() {
	float x, y, dx, dy, p, xend;
	dx = xf - xi;
	dy = yf - yi;
	if(dx < 0) {
		dx = abs(dx);
	}
	if(dy < 0) {
		dy = abs(dy);
	}
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
	if(dx < dy) {
		p = 2 * dy - dx;
		while(x <= xend) {
			glVertex2f(x, y);
			if(p < 0) {
				p += 2 * dy;
				x += 1;
				y = y;
			} else {
				p += 2 * dy - 2 * dx;
				x += 1;
				y += 1;
			}
		}
	} else {
		p = 2 * dx - dy;
		while(x <= xend) {
			glVertex2f(x, y);
			if(p < 0) {
				p += 2 * dx;
				x += 1;
				y = y;
			} else {
				p += 2 * dx - 2 * dy;
				x += 1;
				y += 1;
			}
		}
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
	glutCreateWindow("Bresnham Algorithm - Aakash Dhakal");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	glutDisplayFunc(plotPixel);
	glutMainLoop();
	return 0;
}
