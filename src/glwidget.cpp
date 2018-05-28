#include "glwidget.h"
#include <GL/glu.h>
#include "pixel.h"

GLWidget::GLWidget(QWidget* parent) : QGLWidget(parent)
{
    this->setFocus();

    this->mt = new Matriz();
    this->lin = new Linha(mt->get_dimensao(),10,30);
    this->lin->set_ponto_inicial(-0.14, -0.64);
    this->lin->set_ponto_final(0.23, 0.93);

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

    /*
    Pixel* p = new Pixel(0,0,0.5,-1,-1);

    p->set_max_XY(0.5, 0.5);
    p->set_min_XY(0.0, 0.0);

    p->desenhar();
    */

    mt->desenhar(lin);
    //lin->desenhar();
}

int GLWidget::get_dimensao()
{
    return this->mt->get_dimensao();
}

void GLWidget::set_dimensao(int valor)
{
    this->mt->set_dimensao(valor);
    this->lin->set_dimensao(valor);
}
