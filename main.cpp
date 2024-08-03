#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>

void display();
void reshape(int width, int height);
void timer(int);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Bouncing Baby Ball");
    glClearColor(0.1, 0.1, 0.1, 1.0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
}

void drawBall(float x, float y, float radius)
{
    int numPoints = 100;

    glBegin(GL_POLYGON);
    // make it red because of Owuraku
    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i < numPoints; i++)
    {
        double angle = 2 * M_PI * i / numPoints;
        double dx = radius * cos(angle);
        double dy = radius * sin(angle);
        glVertex2d(x + dx, y + dy);
    }
    glEnd();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

float ballX = 0;
float ballY = 0;
float ballRadius = 0.1;
float ballSpeed = 0.01;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

     // fall
    ballY -= ballSpeed;
    if(ballY - ballRadius <= -1.0){
        ballY = -1.0 + ballRadius;
        ballSpeed = -ballSpeed;
    }

    if ( ballSpeed < 0.05){
        ballSpeed += 0.002;
    }

    drawBall(ballX, ballY, ballRadius);

    glutSwapBuffers();
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}