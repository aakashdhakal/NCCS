//not cannon according to lab
#include <GL/glut.h>

int windowWidth = 800;
int windowHeight = 600;
int squareSize = 50;
int mouseX = 0;
int mouseY = 0;
bool mouseClicked = false;

void drawSquare(int x, int y)
{
    glColor3f(1.0f, 0.0f, 0.0f); // Red square
    glBegin(GL_POLYGON);
    glVertex2f(x - squareSize / 2, y - squareSize / 2);
    glVertex2f(x + squareSize / 2, y - squareSize / 2);
    glVertex2f(x + squareSize / 2, y + squareSize / 2);
    glVertex2f(x - squareSize / 2, y + squareSize / 2);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (mouseClicked)
    {
        drawSquare(mouseX, windowHeight - mouseY); // Flip Y coordinate to match OpenGL's coordinate system
    }
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseX = x;
        mouseY = y;
        mouseClicked = true;
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Draw Square on Mouse Click");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
