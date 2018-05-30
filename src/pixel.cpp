#include "pixel.h"
#include <sstream>
#include <QtOpenGL>
#include <QDebug>

using std::string;

Pixel::Pixel(int i, int j, float tamanho, float x_mundo, float y_mundo) : i(i), j(j)
{
    this->cor = new float[3];
    this->cor[0] = 1.0;
    this->cor[1] = 1.0;
    this->cor[2] = 1.0;

    //qDebug() << (tamanho * i) + (tamanho) << (tamanho * j) + (tamanho);
    //qDebug() << tamanho * i << tamanho * j;

    set_max_XY((tamanho * i) + (tamanho), (tamanho * j) + (tamanho));
    set_min_XY(tamanho * i, tamanho * j);

    /*
    this->pos.x_min = tamanho * i;
    this->pos.x_max = (tamanho * i) + (tamanho);

    this->pos.y_min = tamanho * j;
    this->pos.y_max = (tamanho * j) + (tamanho);
    */

    this->pos_mundo = new float[2];
    this->pos_mundo[0] = x_mundo;
    this->pos_mundo[1] = y_mundo;

    this->desenhar_pix = true;
}

Pixel::~Pixel()
{
    delete this->cor;
    delete this->pos_mundo;
}

void Pixel::desenhar()
{
    if(this->desenhar_pix)
    {
        glBegin(GL_LINES);
            glColor3fv(this->cor);
            glVertex2f(this->pos.x_min + pos_mundo[0], this->pos.y_min + pos_mundo[1]);
            glVertex2f(this->pos.x_min + pos_mundo[0], this->pos.y_max + pos_mundo[1]);

            glVertex2f(this->pos.x_min + pos_mundo[0], this->pos.y_max + pos_mundo[1]);
            glVertex2f(this->pos.x_max + pos_mundo[0], this->pos.y_max + pos_mundo[1]);

            glVertex2f(this->pos.x_max + pos_mundo[0], this->pos.y_max + pos_mundo[1]);
            glVertex2f(this->pos.x_max + pos_mundo[0], this->pos.y_min + pos_mundo[1]);

            glVertex2f(this->pos.x_max + pos_mundo[0], this->pos.y_min + pos_mundo[1]);
            glVertex2f(this->pos.x_min + pos_mundo[0], this->pos.y_min + pos_mundo[1]);
        glEnd();
    }
}

void Pixel::desenhar2()
{
    if(this->desenhar_pix)
    {
        glBegin(GL_QUADS);
            glColor3fv(this->cor);

            glVertex2f(this->pos.x_min + pos_mundo[0], this->pos.y_min + pos_mundo[1]);
            glVertex2f(this->pos.x_min + pos_mundo[0], this->pos.y_max + pos_mundo[1]);

            glVertex2f(this->pos.x_max + pos_mundo[0], this->pos.y_max + pos_mundo[1]);
            glVertex2f(this->pos.x_max + pos_mundo[0], this->pos.y_min + pos_mundo[1]);
        glEnd();
    }
}

const char* Pixel::get_descricao()
{

    std::string posicao;

    std::stringstream i_string;
    i_string << this->i;

    std::stringstream j_string;
    j_string << this->j;

    posicao = "Pos i: " + i_string.str() + " " + "Pos j: " + j_string.str() + ".";
    return posicao.c_str();
}

void Pixel::set_desenhar(bool valor)
{
    this->desenhar_pix = valor;
}

void Pixel::set_min_XY(float x, float y)
{
    this->pos.x_min = x;
    this->pos.y_min = y;
}

void Pixel::set_max_XY(float x, float y)
{
    this->pos.x_max = x;
    this->pos.y_max = y;
}

void Pixel::set_cor(float r, float g, float b)
{
    this->cor[0] = r;
    this->cor[1] = g;
    this->cor[2] = b;
}

float *Pixel::get_cor()
{
    return this->cor;
}

int Pixel::get_i() const
{
    return this->i;
}

int Pixel::get_j() const
{
    return this->j;
}

void Pixel::set_tamanho(float tamanho)
{
    set_max_XY((tamanho * i) + (tamanho), (tamanho * j) + (tamanho));
    set_min_XY(tamanho * i, tamanho * j);
}

