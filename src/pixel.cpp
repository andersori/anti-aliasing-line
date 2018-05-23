#include "pixel.h"
#include <sstream>
#include <QtOpenGL>

using std::string;

Pixel::Pixel(int i, int j) : i(i), j(j)
{
    this->cor = new float[3];
}

Pixel::~Pixel()
{
    delete this->cor;
}

void Pixel::desenhar()
{
    if(this->desenhar_pix)
    {
        glBegin(GL_LINES);
            glColor3fv(this->cor);
            glVertex2f(this->pos.x_min, this->pos.y_max);
            glVertex2f(this->pos.x_max, this->pos.y_max);

            glVertex2f(this->pos.x_max, this->pos.y_max);
            glVertex2f(this->pos.x_max, this->pos.y_min);

            glVertex2f(this->pos.x_max, this->pos.y_min);
            glVertex2f(this->pos.x_min, this->pos.y_min);

            glVertex2f(this->pos.x_min, this->pos.y_min);
            glVertex2f(this->pos.x_min, this->pos.y_max);
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

