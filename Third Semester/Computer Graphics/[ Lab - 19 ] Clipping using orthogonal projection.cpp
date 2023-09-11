#include <GL/glut.h>
int win_width = 800;
int win_height = 600;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Set up the clipping region using glOrtho
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0.4, 0.4, -0.4, 0.4, -1.0, 1.0);
    // Draw the original non-filled triangle
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5f, -0.4f);
    glVertex2f(0.7f, -0.2f);
    glVertex2f(0.2f, 0.7f);
    glEnd();
    glutSwapBuffers();
}
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(win_width, win_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Clipping Using Orthogonal Projection - Aakash Dhakal");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
