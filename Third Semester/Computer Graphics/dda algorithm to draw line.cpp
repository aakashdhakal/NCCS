#include<GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<stdio.h>
#define ROUND(x) ((int)(x+0.5))
int xa,xb,ya,yb;
void init(void){
glClearColor (0.0, 0.0, 0.0, 1.0);
glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}
void display (void){
//DDA Algorithm starts here
int dx = xb-xa,dy = yb-ya,steps,k;
float xIncrement,yIncrement, x = xa, y = ya;
if(abs(dx)>abs(dy))
steps = abs(dx);
else steps = abs(dy);
xIncrement = dx/(float)steps;
yIncrement = dy/(float)steps;

glClear (GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_POINTS);
glVertex2s(ROUND(x),ROUND(y));
for(k=0;k<steps;k++){
x = x+xIncrement;
y = y+yIncrement;

glVertex2s(ROUND(x),ROUND(y));
}
glEnd();
glutSwapBuffers();
}

int main(int argc, char** argv){

printf("Enter the points\n");
scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Simple DDA ");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
