#include<Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#define M_PI       3.14159265358979323846




void circulo()
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.70f, 0.50f, 0.0f);
    glScalef(0.30, 0.60f, 0.0f);
    double ang1 = 2*  M_PI/100 ;
    glPolygonMode( GL_FRONT, GL_FILL );
    glColor3f(0.2, 0.5, 0.5 );
    glBegin(GL_POLYGON);
        double ang2=0.0;
        glVertex2d( cos(0.0) , sin(0.0));
        int i;
        for ( i=0 ; i< 100 ;i++)
        {

            glVertex2d( cos(ang2),sin(ang2));
            ang2 += ang1 ;
        }

    glEnd();
    glPopMatrix();
    //glFlush();
}
void parede()
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.150f, 0.10f, 0.0f);
    glColor4ub(255,255,255,255);
    glBegin(GL_QUADS);
        glVertex3f(-0.3f, 0.3f, 0.0f);                          // Top Left
        glVertex3f( 0.3f, 0.3f, 0.0f);                          // Top Right
        glVertex3f( 0.3f,-0.3f, 0.0f);                          // Bottom Right
        glVertex3f(-0.3f,-0.3f, 0.0f);
    glEnd();
    glPopMatrix();
   // glFlush();

}
void porta()
{
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
   // glFlush();

}
void tronco()
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.650f, 0.10f, 0.0f);
    glColor4ub(150,28,0,255);
    glBegin(GL_QUADS);
         glVertex3f(0.0f, 0.1f, 0.0f);                          // Top Left
         glVertex3f( 0.1f, 0.1f, 0.0f);                          // Top Right
         glVertex3f( 0.1f,-0.3f, 0.0f);                          // Bottom Right
          glVertex3f(0.0f,-0.3f, 0.0f);
    glEnd();
    glPopMatrix();
  //  glFlush();


}
void chao()
{
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
  //  glFlush();
}

void telhado()
{
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

    glEnd();
    glPopMatrix();
   // glFlush();
}

void macaneta()
{
	 glLoadIdentity();
     glTranslatef(-0.320f, -0.05f, 0.0f);
     glLineWidth(20);
     glColor3f(0.0,0.0,0.0);
     glBegin(GL_LINES);
          glVertex2f(0.1,0.0);  // primeiro vértice
          glVertex2f(0.1,0.1); // segundo vértice
     glEnd();
    // glFlush();
}
void pontos()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(10);
	 GLfloat pt[2] = {0.930, 0.740};
            glBegin(GL_POINTS);
            glVertex2f(0.810,0.820);  
           glVertex2f(0.820,0.530);    
            glVertex2fv(pt);         
    glEnd();

}

void inicia()
{

glClearColor(0.0f,0.8f,1.0f,1.0f);


}

void desenha()
{
    glClear(GL_COLOR_BUFFER_BIT);

 //parede da casa
    parede();
//porta
    porta();

//tronco
    tronco();

//copa da arvore

    circulo();

//chao
    chao();

//telhado
    telhado();
    //ceu
//macaneta da porta
    macaneta();
//frutas das arvores
    pontos();

glFlush();

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowPosition(5,5);
    glutInitWindowSize(450,450);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("casa");
    glutDisplayFunc(desenha);
    inicia();
    glutMainLoop();
    return 0;

}
