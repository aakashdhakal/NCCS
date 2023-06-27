//Not updated according to lab

#include <GL/glut.h>

// Square properties
float squareSize = 0.2f;
float squarePosX = 0.0f;
float squarePosY = 0.0f;
float squareSpeedX = 0.01f;
float squareSpeedY = 0.01f;

void drawSquare()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(squarePosX, squarePosY);
    glVertex2f(squarePosX + squareSize, squarePosY);
    glVertex2f(squarePosX + squareSize, squarePosY + squareSize);
    glVertex2f(squarePosX, squarePosY + squareSize);
    glEnd();
    glutSwapBuffers();
}

void update(int value)
{
    // Update the square position
    squarePosX += squareSpeedX;
    squarePosY += squareSpeedY;

    // Check boundaries and reverse direction if necessary
    if (squarePosX + squareSize > 1.0f || squarePosX < -1.0f)
    {
        squareSpeedX = -squareSpeedX;
    }
    if (squarePosY + squareSize > 1.0f || squarePosY < -1.0f)
    {
        squareSpeedY = -squareSpeedY;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS (1000ms/60 ≈ 16ms)
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bouncing Square");
    glutDisplayFunc(drawSquare);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
