#include "matriz.h"
#include <QDebug>
using std::vector;

Matriz::Matriz(int dimencao_x, int dimencao_y) : dimencao_x(dimencao_x), dimencao_y(dimencao_y)
{

    for(int i = 0; i < this->dimencao_y; i++)//Qtd Linhas
    {
        vector<Pixel* >* temp = new vector<Pixel*>();

        for(int j = 0; j < this->dimencao_x; j++)//Qtd Colunas
        {
            temp->push_back(new Pixel(i, j));
        }
        this->pixeis.push_back(temp);
    }

}

Matriz::~Matriz()
{
    for(int i = 0; i < this->dimencao_y; i++)//Qtd Linhas
    {
        vector<Pixel* >* temp = this->pixeis[i];
        temp->clear();
    }
    this->pixeis.clear();
}

void Matriz::desenhar()
{
    for(int i = 0; i < this->dimencao_y; i++)
    {
        for(int j = 0; j < this->dimencao_x; j++)
        {
            vector<Pixel*>* qq = pixeis.at(i);

            if(qq == nullptr){
                qDebug() << "qq null";
            }
            else{
                //qDebug() << "aqui antes";
                Pixel* pp = qq->at(j);
                //qDebug() << "aqui depois";
                if(pp == nullptr){
                    qDebug() << "pp null";
                }
                else{
                    qDebug() << pp->get_descricao();
                }

            }
            //Pixel* pp = qq->at(j);
            //qDebug() << pp->get_descricao();
        }
    }
}
