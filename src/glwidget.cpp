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

    glClear(GL_COLOR_BUFFER_BIT);
    this->update();
}

void GLWidget::set_algoritmo(int algoritmo)
{
    this->mt->set_algoritmo(algoritmo);
    this->update();
}

void GLWidget::set_angulo(int angulo)
{
    this->lin->set_angulo((float)angulo+0.0);
    this->update();
}
