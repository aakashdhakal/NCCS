#include <GL/glut.h>

void drawShapes()
{
    glLineWidth(3);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw line
    glColor3f(1.0, 0.0, 0.0); // Red
    glBegin(GL_LINES);
    glVertex2f(-0.8, 0.8);
    glVertex2f(0.8, -0.8);
    glEnd();

    // Draw a rectangle
    glColor3f(0.0, 1.0, 0.0); // Green
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.7, -0.5); // Bottom-left vertex
    glVertex2f(-0.1, -0.5); // Bottom-right vertex
    glVertex2f(-0.1, 0.5);  // Top-right vertex
    glVertex2f(-0.7, 0.5);  // Top-left vertex
    glEnd();

    // Draw a triangle
    glColor3f(0.0, 0.0, 1.0); // Blue
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.3, -0.5);
    glVertex2f(0.0, 0.5);
    glVertex2f(0.3, -0.5);
    glEnd();

    // Draw a hexagon
    glColor3f(1.0, 1.0, 0.0); // Yellow
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.0);   // Bottom-left vertex
    glVertex2f(0.35, 0.5);  // Top-left vertex
    glVertex2f(0.65, 0.5);  // Top vertex
    glVertex2f(0.9, 0.0);   // Top-right vertex
    glVertex2f(0.65, -0.5); // Bottom-right vertex
    glVertex2f(0.35, -0.5); // Bottom vertex
    glEnd();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(800, 600); // Increase window size
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Drawing Shapes");
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set clear color to black
    glutDisplayFunc(drawShapes);
    glutMainLoop();
    return 0;
}
