#include <GL/glut.h>

void drawHut()
{
    // Draw the roof of the hut
    glColor3f(0.6f, 0.8f, 1.0f); // Light blue color
    glBegin(GL_TRIANGLES);

    glVertex2f(-170.0f, 50.0f); // Bottom-left vertex
    glVertex2f(170.0f, 50.0f);  // Bottom-right vertex
    glVertex2f(0.0f, 200.0f);   // Top vertex
    glEnd();

    // Draw the walls of the hut
    glColor3f(0.0f, 1.3f, 0.0f); // Red color
    glBegin(GL_POLYGON);
    glVertex2f(-170.0f, -250.0f); // Bottom-left vertex
    glVertex2f(-170.0f, 50.0f);   // Top-left vertex
    glVertex2f(170.0f, 50.0f);    // Top-right vertex
    glVertex2f(170.0f, -250.0f);  // Bottom-right vertex
    glEnd();

    // Draw the door of the hut
    glColor3f(0.6f, 0.8f, 1.0f); // Light blue color
    glBegin(GL_POLYGON);
    glVertex2f(-60.0f, -240.0f); // Bottom-left vertex
    glVertex2f(-60.0f, -100.0f); // Top-left vertex
    glVertex2f(60.0f, -100.0f);  // Top-right vertex
    glVertex2f(60.0f, -240.0f);  // Bottom-right vertex
    glEnd();

    // Draw the window of the hut
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glBegin(GL_POLYGON);
    glVertex2f(40.0f, -80.0f);  // Bottom-right vertex
    glVertex2f(40.0f, -10.0f);  // Top-right vertex
    glVertex2f(120.0f, -10.0f); // Top-left vertex
    glVertex2f(120.0f, -80.0f); // Bottom-left vertex
    glEnd();

    // Draw the window of the hut
    glBegin(GL_POLYGON);
    glVertex2f(-40.0f, -80.0f);  // Bottom-right vertex
    glVertex2f(-40.0f, -10.0f);  // Top-right vertex
    glVertex2f(-120.0f, -10.0f); // Top-left vertex
    glVertex2f(-120.0f, -80.0f); // Bottom-left vertex
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Translate the hut to the center of the window
    glTranslatef(400.0f, 300.0f, -1.0f);

    drawHut();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Hut");
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
