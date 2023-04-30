#include "oglwidget.h"

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    parama = 0;
    paramb = 0;
    paramc = 0;
    paramd = 0;
    parame = 0;

}

OGLWidget::~OGLWidget()
{
}


void OGLWidget::setParamE(int newe)
{
    parama = newe; // Set new value
    update();      // Update the view
}

void OGLWidget::setParamA(int newa)
{
    paramb = newa;
    update();
}

void OGLWidget::setParamB(int newb)
{
    paramc = newb;
    update();
}

void OGLWidget::setParamC(int newc)
{
    paramd = newc;
    update();
}

void OGLWidget::setParamD(int newd)
{
    parame = newd;
    update();
}

void OGLWidget::square() // Erzeugt ein Einheitsquadrat
{
}

void OGLWidget::ziehharmonika()
{
    double aufklappen = parama*0.9;
    glPushMatrix();

    glTranslatef(0.5,0.5,0.0);
    glRotatef(aufklappen, 0.0f, 0.0f, -1.0f); // Rotate by t degrees around z axis
    glBegin(GL_QUADS);
        glColor3f(0.0, 0.7, 1.0);
        glVertex3f(0.0, 0.0, 0.5);
        glVertex3f(0.0, 0.0, -0.5);
        glVertex3f(-0.25, 0.0, -0.5);
        glVertex3f(-0.25, 0.0, 0.5);
    glEnd();

    glTranslatef(-0.25,0.0,0.0);
    glRotatef(2*aufklappen, 0.0f, 0.0f, 1.0f); // Rotate by t degrees around z axis
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.8, 0.9);
    glVertex3f(0.0, 0.0, 0.5);
    glVertex3f(0.0, 0.0, -0.5);
    glVertex3f(-.25, 0.0, -0.5);
    glVertex3f(-0.25, 0.0, 0.5);
    glEnd();

    glTranslatef(-0.25,0.0,0.0);
    glRotatef(-2*aufklappen, 0.0f, 0.0f, 1.0f); // Rotate by t degrees around z axis
    glBegin(GL_QUADS);
    glColor3f(-0.3, -0.9, 0.8);
    glVertex3f(0.0, 0.0, 0.5);
    glVertex3f(0.0, 0.0, -0.5);
    glVertex3f(-.25, 0.0, -0.5);
    glVertex3f(-0.25, 0.0, 0.5);
    glEnd();

    glTranslatef(-0.25,0.0,0.0);
    glRotatef(2*aufklappen, 0.0f, 0.0f, 1.0f); // Rotate by t degrees around z axis
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.7);
    glVertex3f(0.0, 0.0, 0.5);
    glVertex3f(0.0, 0.0, -0.5);
    glVertex3f(-.25, 0.0, -0.5);
    glVertex3f(-0.25, 0.0, 0.5);
    glEnd();
    glPopMatrix();
};

void OGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

 void OGLWidget::paintGL()
{
    double aufklappen = parame*0.9;
    double r = paramb*3.6;   // degree to rotate
    double a = paramc*3.6;
    double b = paramd*3.6;



    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(r, 0.0f, 0.0f, 1.0f); // Rotate by r degrees around z axis
    glRotatef(a, 0.0f, 1.0f, 0.0f);
    glRotatef(b, 1.0f, 0.0f, 0.0f);


    glPushMatrix();

    glPushMatrix();
    glTranslatef(-0.5, 0.5, 0);
    glRotatef(aufklappen, 0, 1, 0);
    glTranslatef(0.5, -0.5, 0);
    //
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f( 0.5, 0.5, 0.0);
    glVertex3f(0.5,-0.5, 0.0);
    glEnd(); //vorne + Deckel
    glPopMatrix();


    glTranslatef(0, 0, 1); //hinten
    //
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f( 0.5, 0.5, 0.0);
    glVertex3f(0.5,-0.5, 0.0);
    glEnd();

    glTranslatef(-0.5, 0, -0.5); //links
    glRotatef(180.0f, 1, 0, 1);
    //
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f( 0.5, 0.5, 0.0);
    glVertex3f(0.5,-0.5, 0.0);
    glEnd();

    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.5); //boden
    glRotatef(180.0f, 0, 1, 1);
    //
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f( 0.5, 0.5, 0.0);
    glVertex3f(0.5,-0.5, 0.0);
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.5); //rechts
    glRotatef(180.0f, 1, 0, 1);
    //
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f( 0.5, 0.5, 0.0);
    glVertex3f(0.5,-0.5, 0.0);
    glEnd();

    glTranslatef(0, -1, -0.5); //ziehharmonika
    glRotatef(90.0f, 0, 1, 0);
    ziehharmonika();
}



void OGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-1, 1, -1, 1, 1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glFrustum(-10, 10, -10, 10, 0, 200);
}

