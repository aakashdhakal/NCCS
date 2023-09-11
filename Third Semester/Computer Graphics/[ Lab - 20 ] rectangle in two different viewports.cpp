#include <GL/glut.h>

int win_width = 800;
int win_height = 600;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Set up viewport for the left rectangle
    glViewport(0, 0, win_width / 2, win_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw the left rectangle
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.2f, -0.8f);
    glVertex2f(-0.2f, 0.8f);
    glVertex2f(-0.8f, 0.8f);
    glEnd();

    // Set up viewport for the right rectangle
    glViewport(win_width / 2, 0, win_width / 2, win_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw the right rectangle
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(0.2f, -0.8f);
    glVertex2f(0.8f, -0.8f);
    glVertex2f(0.8f, 0.8f);
    glVertex2f(0.2f, 0.8f);
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
    glutCreateWindow("Two Viewports with Rectangles - Aakash Dhakal");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
