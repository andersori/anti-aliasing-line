#include "glwidget.h"
#include <GL/glu.h>
#include "pixel.h"

GLWidget::GLWidget(QWidget* parent) : QGLWidget(parent)
{
    this->setFocus();
    this->mt = new Matriz();
}

GLWidget::~GLWidget()
{
    delete this->mt;
}

void GLWidget::initializeGL()
{
    glViewport(0, 0, this->width(), this->height());
    glClearColor(0.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-this->width()/2.0, this->width()/2.0,
            -this->height()/2.0, this->height()/2.0,
            10, 10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //mt->desenhar();
    Pixel* p = new Pixel(10,10);
    p->set_max_XY(0.5, 0.5);
    p->set_min_XY(-0.5, -0.5);
    p->set_desenhar(true);
    p->desenhar();
}
