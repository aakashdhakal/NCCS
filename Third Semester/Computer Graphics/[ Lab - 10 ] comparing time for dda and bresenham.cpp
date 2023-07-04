//Code is not completed so it is not working
#include <GL/glut.h>
#include <iostream>
#include<ctime>
#include <cmath>

using namespace std;
float xi, yi, xf, yf;
void bresenham() {
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
void dda() {
	int steps;
	int dx = xf - xi;
	int dy = yf - yi;
	if(abs(dx) < abs(dy)) {
		steps = abs(dy);
	} else {
		steps = abs(dx);
	}
	float xIncrement = (float) dx / (float) steps;
	float yIncrement = (float) dy / (float) steps;
	float x = xi;
	float y = yi;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for(int i = 0; i <= steps; i++) {
		glVertex2i(x, y);
		x += xIncrement;
		y += yIncrement;
	}
	glEnd();
	glFlush();
}
void plotPixel() {
    time_t dda_start = time(&dda_start);
	dda();
	time_t dda_end = time(&dda_end);
	time_t bresenham_start = time(&bresenham_start);
	bresenham();
	time_t bresenham_end = time(&bresenham_end);

	cout<<"The time taken by DDA is "<<dda_start - dda_end<<" seconds"<<endl;
	cout<<"The time taken by Bresenham is "<<bresenham_start - bresenham_end<<" seconds"<<endl;

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
