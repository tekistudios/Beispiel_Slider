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


void OGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

 void OGLWidget::paintGL()
{

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

