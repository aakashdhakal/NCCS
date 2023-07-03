#include <gl/glut.h>
#include <iostream>
using namespace std;

void line() {
 glColor3f(1.0, 0.0, 0.0);
 glPointSize(2.0);
 int x1, y1, x2, y2;
 cout << "Enter starting point (x, y): ";
 cin >> x1 >> y1;
 cout << "Enter end point (x, y): ";
 cin >> x2 >> y2;
 int steps, dx = x2 - x1, dy = y2 - y1;
 if (abs(dx) > abs(dy)) {
  steps = abs(dx);
 }
 else {
  steps = abs(dy);
 }
 float xInc = (float)dx / (float)steps;
 float yInc = (float)dy / (float)steps;
 float x = x1, y = y1;
 glBegin(GL_POINTS);
 for (int i = 0; i < steps; i++){
  glVertex2i(x, y);
  x += xInc;
  y += yInc;
 }
 glEnd();
 glFlush();
}
int main(int argc, char ** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Line Draw OpenGL");

 glClearColor(1.0, 1.0, 1.0, 1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 gluOrtho2D(0, 500, 0, 500);
 glMatrixMode(GL_PROJECTION);
 glViewport(0, 0, 500, 500);

 glutDisplayFunc(line);
 glutMainLoop();
 return 0;
}
