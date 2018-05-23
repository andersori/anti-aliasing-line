#include "linha.h"
#include <QtOpenGL>

using std::vector;

Linha::Linha(int dim_i, int dim_j) : dimencao_i(dim_i), dimencao_j(dim_j)
{
    this->cor = new float[3];

    vector<Posicao* >* p1 = new vector<Posicao*>();
    p1->push_back(new Posicao());
    this->posicoes.push_back(p1);

    vector<Posicao* >* p2 = new vector<Posicao*>();
    p2->push_back(new Posicao());
    this->posicoes.push_back(p2);
}

Linha::~Linha()
{
    Posicao* p;
    vector<Posicao* >* v;

    v = this->posicoes.at(0);
    p = v->at(0);//x
    delete p;
    p = v->at(1);//y
    delete p;
    delete v;

    v = this->posicoes.at(1);
    p = v->at(0);//x
    delete p;
    p = v->at(1);//y
    delete p;
    delete v;
}

void Linha::desenhar()
{
    Posicao* p1 = this->posicoes.at(0)->at(0);
    Posicao* p2 = this->posicoes.at(0)->at(1);

    glBegin(GL_LINES);
        glColor3fv(this->cor);
        glVertex2f(p1->x, p1->y);
        glVertex2f(p2->x, p2->y);
    glEnd();
}

void Linha::set_p1(int x, int y)
{
    vector<Posicao*>* v = this->posicoes.at(0);
    Posicao* p = v->at(0);
    p->x = x;
    p->y = y;
}

void Linha::set_p2(int x, int y)
{
    vector<Posicao*>* v = this->posicoes.at(1);
    Posicao* p = v->at(0);
    p->x = x;
    p->y = y;
}
