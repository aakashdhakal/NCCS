#include <GL/glut.h>

void drawHut()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the roof of the hut
    glColor3f(0.3490f, 0.5098f, 0.6902f); // Light blue color
    glBegin(GL_TRIANGLES);
    glVertex2f(230.0f, 350.0f); // Bottom-left vertex
    glVertex2f(570.0f, 350.0f); // Bottom-right vertex
    glVertex2f(400.0f, 500.0f); // Top vertex
    glEnd();

    // Draw the walls of the hut
    glColor3f(0.5019f, 0.8314f, 0.1059f); // Red color
    glBegin(GL_QUADS);
    glVertex2f(230.0f, 50.0f);  // Bottom-left vertex
    glVertex2f(230.0f, 350.0f); // Top-left vertex
    glVertex2f(570.0f, 350.0f); // Top-right vertex
    glVertex2f(570.0f, 50.0f);  // Bottom-right vertex
    glEnd();

    // Draw the door of the hut
    glColor3f(0.3490f, 0.5098f, 0.6902f); // Light blue color
    glBegin(GL_QUADS);
    glVertex2f(350.0f, 60.0f);  // Bottom-left vertex
    glVertex2f(350.0f, 185.0f); // Top-left vertex
    glVertex2f(450.0f, 185.0f); // Top-right vertex
    glVertex2f(450.0f, 60.0f);  // Bottom-right vertex
    glEnd();

    // Draw the first window of the hut
    glColor3f(0.9412f, 0.0471f, 0.0471f); // Red color
    glBegin(GL_QUADS);
    glVertex2f(430.0f, 200.0f); // Bottom-right vertex
    glVertex2f(430.0f, 280.0f); // Top-right vertex
    glVertex2f(510.0f, 280.0f); // Top-left vertex
    glVertex2f(510.0f, 200.0f); // Bottom-left vertex
    glEnd();

    // Draw the second window of the hut
    glBegin(GL_QUADS);
    glVertex2f(290.0f, 200.0f); // Bottom-right vertex
    glVertex2f(290.0f, 280.0f); // Top-right vertex
    glVertex2f(370.0f, 280.0f); // Top-left vertex
    glVertex2f(370.0f, 200.0f); // Bottom-left vertex
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Hut - Aakash Dhakal");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(drawHut);
    glutMainLoop();
    return 0;
}
