#include <GL/glut.h>

void drawShapes()
{
    glLineWidth(3);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a rectangle
    glColor3f(1.0, 0.0, 0.0); // Red
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.1); // Bottom-left vertex
    glVertex2f(-0.2, -0.1); // Bottom-right vertex
    glVertex2f(-0.2, 0.5);  // Top-right vertex
    glVertex2f(-0.7, 0.5);  // Top-left vertex
    glEnd();

    // Draw a triangle
    glColor3f(0.0, 0.0, 1.0); // Blue
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, -0.4); // Bottom-Left-Vertex
    glVertex2f(-0.2, 0.2);  // Top-Vertex
    glVertex2f(0.1, -0.4);  // Bottom-Right-Vertex
    glEnd();

    // Draw a hexagon
    glColor3f(0.0, 1.0, 0.0); // Green
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, -0.4); // Left vertex
    glVertex2f(-0.1, -0.7);  // Bottom-Left vertex
    glVertex2f(0.1, -0.7);   // Bottom-right vertex
    glVertex2f(0.25, -0.4);  // Right vertex
    glVertex2f(0.1, -0.1);   // Top-Right vertex
    glVertex2f(-0.1, -0.1);  // Top-left vertex
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
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
