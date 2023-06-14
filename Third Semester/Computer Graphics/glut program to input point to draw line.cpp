#include <GL/glut.h>
#include<GL/glu.h >
#include <iostream>
using namespace std;

void drawLine(){
	int x1,y1,x2,y2;
	cout<<"Enter the points (x1,y1): ";
	cin>>x1>>y1;
	cout<<"Enter the points (x2,y2): ";
	cin>>x2>>y2;
	
    glBegin(GL_LINES);
    glVertex2d(x1,y1);
    glVertex2d(x2,y2);
    glEnd();
    glFlush();
}

void myInit(){

    glutInitWindowSize(600, 600); // Increase window size
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Drawing Line");
    glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	gluOrtho(0,640,0,640);
	glMatrixMode(GL_MODELVIEW); 

}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
myInit();
        glutDisplayFunc(drawLine);
    glutMainLoop();
    return 0;
}
