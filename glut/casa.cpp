#include<Windows.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <stdlib.h>

void inicia()
{

glClearColor(0.0f,0.8f,1.0f,1.0f);

}

void desenha()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.150f, 0.10f, 0.0f);
    glColor4ub(255,255,255,255);
//parede da casa
    glBegin(GL_QUADS);
    glVertex3f(-0.3f, 0.3f, 0.0f);                          // Top Left
    glVertex3f( 0.3f, 0.3f, 0.0f);                          // Top Right
    glVertex3f( 0.3f,-0.3f, 0.0f);                          // Bottom Right
    glVertex3f(-0.3f,-0.3f, 0.0f);
    glEnd();
    //porta
    glPopMatrix();
    glFlush();
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.150f, 0.10f, 0.0f);
    glColor4ub(255,150,220,255);
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, 0.1f, 0.0f);                          // Top Left
    glVertex3f( 0.1f, 0.1f, 0.0f);                          // Top Right
    glVertex3f( 0.1f,-0.3f, 0.0f);                          // Bottom Right
    glVertex3f(-0.1f,-0.3f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
//chao
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.150f, -0.50f, 0.0f);
    glColor4ub(0,255,0,255);
    glBegin(GL_QUADS);
    glVertex3f(-1.9f, 0.3f, 0.0f);                          // Top Left
    glVertex3f( 1.9f, 0.3f, 0.0f);                          // Top Right
    glVertex3f( 1.9f,-0.6f, 0.0f);                          // Bottom Right
    glVertex3f(-1.9f,-0.6f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();

//telhado

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.150f, 0.50f, 0.0f);
    glRotatef(300.0,160.0,1.0,0.0);
    glScalef(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);

    glColor3f(1.00,0.00,0.00);
    glVertex2f(-0.5,-0.5);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(0.5,-0.5);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(0.0,0.5);
    glPopMatrix();
    glEnd();
    glFlush();

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Casa");
    inicia();
    glutDisplayFunc(desenha);
    glutMainLoop();
    return 0;

}
