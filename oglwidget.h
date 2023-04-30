#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OGLWidget : public QOpenGLWidget,
                  protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OGLWidget(QWidget *parent = 0);
    ~OGLWidget();

public slots:
    void setParamE( int newa );
    void setParamA( int newb );
    void setParamB( int newc );
    void setParamC( int newd );
    void setParamD( int newd );

protected:
    void initializeGL(); //Вызывается при создании окна
    void resizeGL(int w, int h); //Вызывается при изменении размеров окна
    void paintGL(); // Тут происходит отрисовка,вызывается при любом событии (Пример: Изменили размер окна, после этого срабатывает paintGL())
    void square();
    void ziehharmonika();

protected:
    int parama;
    int paramb;
    int paramc;
    int paramd;
    int parame;
};


#endif // OGLWIDGET_H
