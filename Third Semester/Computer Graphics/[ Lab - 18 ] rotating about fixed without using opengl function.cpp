#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

float x, y;
float width, height;
int win_width = 800;
int win_height = 600;

void drawRectangle(float **rectangle){
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 4; i++)
    {
        glVertex2f(rectangle[0][i], rectangle[1][i]);
    }
    glEnd();
    glFlush();
}

void **multiplyMatrix(float **matrix1,float **matrix2,float **answer,int row1, int row2,int col1,int col2){

    for(int i = 0; i < row1; ++i){
        for(int j = 0; j < col2; ++j){
            for(int k = 0; k < col1; ++k)
            {
                answer[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

}

void rotate()
{
    float tx = 150, ty = 125;
    float theta = (30 * 3.14159265) / 180.0;
    float rotationMatrix[3][3] = {cos(theta), -sin(theta), 0, sin(theta), cos(theta), 0, 0, 0, 1};
    float originalVertex[3][4] = {{x, x + width, x + width, x}, {y, y, y + height, y + height}, {1, 1, 1, 1}};
    float translateMatrix[3][3] = {1,0,tx,0,1,ty,0,0,1};
    float translateBackMatrix[3][3] = {1,0,-tx,0,1,-ty,0,0,1};
    float **transformMatrix = new float*[3];
    for(int i=0;i<3;i++){
        transformMatrix[i] = new float[3];
    }

    float **original = new float*[3];
    for(int i=0;i<3;i++){
        original[i] = new float[3];
    }

    float **rotation= new float*[3];
    for(int i=0;i<3;i++){
        rotation[i] = new float[3];
    }

    float **translate = new float*[3];
    for(int i=0;i<3;i++){
        translate[i] = new float[3];
    }

    float **final = new float*[3];
    for(int i=0;i<3;i++){
        final[i] = new float[4];
    }
    float **temp = new float*[3];
    for(int i=0;i<3;i++){
        temp[i] = new float[3];
    }

    float **translateBack = new float*[3];
    for(int i=0;i<3;i++){
        translateBack[i] = new float[3];
    }


    for(int i = 0; i<3;i++){
        for(int j = 0; j<3; j++){
            rotation[i][j] = rotationMatrix[i][j];
            translate[i][j] = translateMatrix[i][j];
            translateBack[i][j] = translateBackMatrix[i][j];
        }
    }
     for(int i = 0; i<3;i++){
        for(int j = 0; j<4; j++){
            original[i][j] = originalVertex[i][j];
        }
    }

    glColor3f(0.0f, 0.0f, 0.0f);
    drawRectangle(original);

    multiplyMatrix(translate,rotation,temp,3,3,3,3);
    multiplyMatrix(temp,translateBack,transformMatrix,3,3,3,3);
    multiplyMatrix(transformMatrix,original,final,3,3,3,4);


    glColor3f(0.5, 0.5, 0.5);
    drawRectangle(final);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Black color
    glBegin(GL_LINES);
    glVertex2i(-800, 0);
    glVertex2i(800, 0);
    glVertex2i(0, -600);
    glVertex2i(0, 600);
    glEnd();
    glFlush();
    rotate();
}

int main(int argc, char *argv[])
{
    x = 100;
    y = 100;
    width = 100;
    height = 50;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(win_width, win_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotate Rectangle Without Using Function - Aakash Dhakal");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-100, win_width, -100, win_height);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
