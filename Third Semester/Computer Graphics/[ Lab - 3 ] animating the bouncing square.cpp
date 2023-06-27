#include <GL/glut.h>

// Square properties
float squareWidth = 100.0f, squarePosX = 0.0f, squarePosY = 0.0f ,squareSpeedX = 5.0f, squareSpeedY = 5.0f ,x_max = 800.0f,y_max = 600.0f;

void drawSquare()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(squarePosX, squarePosY);
    glVertex2f(squarePosX + squareWidth, squarePosY);
    glVertex2f(squarePosX + squareWidth, squarePosY + squareWidth);
    glVertex2f(squarePosX, squarePosY + squareWidth);
    glEnd();
    glutSwapBuffers();
}

void update(int value)
{
    // Update the square position
    squarePosX += squareSpeedX;
    squarePosY += squareSpeedY;

    // Check boundaries and reverse direction if necessary
    if (squarePosX + squareWidth > x_max || squarePosX < 0.0f)
    {
        squareSpeedX = -squareSpeedX;
    }
    if (squarePosY + squareWidth > y_max || squarePosY < 0.0f)
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
    glutInitWindowSize(x_max, y_max);
    glutCreateWindow("Bouncing Square");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,0,600);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(drawSquare);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
