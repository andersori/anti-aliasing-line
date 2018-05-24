#include "linha.h"
#include <QtOpenGL>

using std::vector;

Linha::Linha(int dimensao, int tamanho, float angulo) : dimensao(dimensao), tamanho(tamanho), angulo(angulo)
{
    this->cor = new float[3];
    this->cor[0] = 0.0;
    this->cor[1] = 0.0;
    this->cor[2] = 0.0;

    this->p1 = new Posicao();
    this->p2 = new Posicao();

    /*
    this->p1->x = ;
    this->p1->y = ;

    this->p2->x = ;
    this->p2->y = ;
    */
}

Linha::~Linha()
{
    delete this->cor;
    delete this->p1;
    delete this->p2;
}

void Linha::desenhar()
{
    glBegin(GL_LINES);
        glColor3fv(this->cor);
        glVertex2f(p1->x, p1->y);
        glVertex2f(p2->x, p2->y);
    glEnd();
}

void Linha::set_ponto_inicial(float x, float y)
{
    p1->x = x;
    p1->y = y;
}

void Linha::set_ponto_final(float x, float y)
{
    p2->x = x;
    p2->y = y;
}

void Linha::set_dimensao(int dim)
{
    this->dimensao = dim;
}

float Linha::get_angulo() const
{
    return angulo;
}

void Linha::set_angulo(float angulo)
{
    this->angulo = angulo;
}

Linha::Posicao *Linha::get_ponto_inicial() const
{
    return this->p1;
}

Linha::Posicao *Linha::get_ponto_final() const
{
    return this->p2;
}
