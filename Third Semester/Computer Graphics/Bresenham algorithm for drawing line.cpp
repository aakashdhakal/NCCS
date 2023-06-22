#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;
 float xi, yi, xf, yf, x, y, xinc, yinc,dx,dy,p,xend;
void plotPixel()
{
   
    int steps,i;
    cout << "Enter the initial points: ";
    cin >> xi >> yi;
    cout << "Enter the final points: ";
    cin >> xf >> yf;
    dx = xf - xi;
    dy = yf - yi;   
    p = 2*dy - dx;
    
    if(xi > xf){
    	x = xf;
    	y = yf;
    	xend = xi;
	}
	else{
		x = xi;
		y = yi;
		xend = xf;
	}
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
	while(x <= xend){
		if(p < 0 ){
			p += 2*dy;
			x += 1;
			y = y; 
		}
		else{
			p += 2*dy - 2*dx;
			x += 1;
			y -= 1;   
		}
		 glVertex2f(x, y);
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
