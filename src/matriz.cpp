#include "matriz.h"
#include <QDebug>
using std::vector;

Matriz::Matriz(int altura, int largura, int dimensao)
    : linha(dimensao), coluna(dimensao), aspecto(Janela(altura, largura))
{
    qDebug() << "Altura:" << altura << ", Dimensao: " << dimensao << " = " << (this->aspecto.altura + 0.0) / (dimensao+0.0) << ".";
    for(int i = 0; i < this->linha; i++)
    {
        vector<Pixel* >* temp = new vector<Pixel*>();

        for(int j = 0; j < this->coluna; j++)
        {
            temp->push_back(new Pixel(i, j, ((this->aspecto.altura + 0.0) / (dimensao + 0.0)), -1, -1));
        }
        this->pixeis.push_back(temp);
    }

}

Matriz::~Matriz()
{
    for(int i = 0; i < this->linha; i++)
    {
        vector<Pixel* >* temp = this->pixeis[i];
        temp->clear();
    }
    this->pixeis.clear();
}

void Matriz::desenhar(Linha* lin)
{
    pixeis_da_linha(lin);
    for(int i = 0; i < this->linha; i++)
    {
        for(int j = 0; j < this->coluna; j++)
        {
            vector<Pixel*>* qq = pixeis.at(i);
            Pixel* pp = qq->at(j);

            //qDebug() << pp->get_descricao();
            pp->desenhar();

        }
    }
}

int Matriz::get_dimensao()
{
    return this->linha;
}

void Matriz::set_dimensao(int valor)
{
    this->linha = valor;
    this->coluna = valor;
}

void Matriz::pixeis_da_linha(Linha* lin)
{

    Linha::Posicao* p_inicial = lin->get_ponto_inicial();
    Linha::Posicao* p_final = lin->get_ponto_final();

    //p é ponto
    //utilizar "linha" pq ela é a DIMENSÃO da matriza

    //p_linha_na_matriz_inicial_x
    int pix = (p_inicial->x + 1) * this->linha/2.0;

    //p_linha_na_matriz_inicial_y
    int piy = (p_inicial->y + 1) * this->linha/2.0;

    //p_linha_na_matriz_final_x
    int pfx = (p_final->x + 1) * this->linha/2.0;

    //p_linha_na_matriz_final_y
    int pfy = (p_final->y + 1) * this->linha/2.0;


    float mx = ((pfx - pix)/(pfy - piy));
    float my = ((pfy - piy)/(pfx - pix));

    for(int i = 0; i < abs(pfx - pix); i++)
    {
        int aux = piy + (i * mx);
        qDebug()<<aux;
        vector<Pixel*>* temp = this->pixeis.at(pix + i);

        Pixel* p = temp->at(aux);
        p->desenhar2();
    }
    for(int i = 0; i < abs(pfy - piy); i++)
    {
        int aux = pix + (i * my);
        vector<Pixel*>* temp = this->pixeis.at(aux);

        Pixel* p = temp->at(piy + i);
        p->desenhar2();
    }
}
