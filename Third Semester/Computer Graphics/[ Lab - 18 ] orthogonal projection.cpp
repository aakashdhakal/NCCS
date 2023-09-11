#include <GL/glut.h>
#include <iostream>
int windowWidth = 800;
int windowHeight = 600;
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Set the background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);
    // Set the square color to black
    glColor3f(0.0, 0.0, 0.0);
    // Draw a square
    glBegin(GL_QUADS);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    glEnd();
    glutSwapBuffers();
}
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Orthogonal Projection Example - Aakash Dhakal");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutMainLoop();
    return 0;
}
