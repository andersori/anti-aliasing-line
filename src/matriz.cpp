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
    borramento();

    for(int i = 0; i < this->linha; i++)
    {
        for(int j = 0; j < this->coluna; j++)
        {
            vector<Pixel*>* qq = pixeis.at(i);
            Pixel* pp = qq->at(j);

            //qDebug() << pp->get_descricao();
            pp->desenhar2();

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

void Matriz::borramento()
{
    for(int i = 0; i < this->linha; i++)
    {
        //Linha do pixel que será pintado
        vector<Pixel* >* linha_do_pixel = this->pixeis.at(i);

        for(int j = 0; j < this->coluna; j++)
        {
            Pixel* pp = linha_do_pixel->at(j);

            float r=0.0;
            float g=0.0;
            float b=0.0;

            if(pp->get_i() == 0)
            {
                //Não tem ninguem abaixo
                vector<Pixel* >* linha_de_cima = this->pixeis.at(i+1);

            }
            else
            {
                if(pp->get_i() == (this->coluna - 1))
                {
                    //Ninguem acima
                    vector<Pixel* >* linha_de_baixo = this->pixeis.at(i-1);

                }
                else
                {
                    //Existe linha acima e abaixo

                }
            }

            if(pp->get_j() == 0)
            {
                //Ninguem na esquerda
                float* cor = pp->get_cor();
                r += cor[0];
                g += cor[1];
                b += cor[2];

                Pixel* temp = linha_do_pixel->at(j+1);
                cor = temp->get_cor();
                r += cor[0];
                g += cor[1];
                b += cor[2];

                pp->set_cor(r/2.0,g/2.0,b/2.0);
            }
            else
            {
                if(pp->get_j() == (this->coluna-1))
                {
                    //Ninguem na direita
                    Pixel* temp = linha_do_pixel->at(j-1);
                    float* cor = temp->get_cor();
                    r += cor[0];
                    g += cor[1];
                    b += cor[2];

                    cor = pp->get_cor();
                    r += cor[0];
                    g += cor[1];
                    b += cor[2];

                    pp->set_cor(r/2.0,g/2.0,b/2.0);
                }
                else
                {
                    //Existe pixel na direita e esquerda
                    Pixel* temp = linha_do_pixel->at(j-1);
                    float* cor = temp->get_cor();
                    r += cor[0];
                    g += cor[1];
                    b += cor[2];

                    temp = linha_do_pixel->at(j+1);
                    cor = temp->get_cor();
                    r += cor[0];
                    g += cor[1];
                    b += cor[2];

                    cor = pp->get_cor();
                    r += cor[0];
                    g += cor[1];
                    b += cor[2];

                    pp->set_cor(r/3.0,g/3.0,b/3.0);
                }
            }

        }
    }
}

void Matriz::pixeis_da_linha(Linha* lin)
{

    Linha::Posicao* p_inicial = lin->get_ponto_inicial();
    Linha::Posicao* p_final = lin->get_ponto_final();

    //p é ponto
    //utilizar "linha" pq ela é a DIMENSÃO da matriza

    //p_linha_na_matriz_inicial_x
    float pix = (p_inicial->x + 1) * this->linha/2.0;

    //p_linha_na_matriz_inicial_y
    float piy = (p_inicial->y + 1) * this->linha/2.0;

    //p_linha_na_matriz_final_x
    float pfx = (p_final->x + 1) * this->linha/2.0;

    //p_linha_na_matriz_final_y
    float pfy = (p_final->y + 1) * this->linha/2.0;

    float mx, my;
    if (pfx == pix || pfy == piy){
        mx = 0.0;
        my = 0.0;
    }
    else{
        if (pix < pfx){
            if (piy < pfy){
                mx = ((pfx - pix)/(pfy - piy));
                my = ((pfy - piy)/(pfx - pix));
            }
            else{
                mx = ((pfx - pix)/(piy - pfy));
                my = ((piy - pfy)/(pfx - pix));
            }
        }
        if( pix > pfx ) {
            if ( piy < pfy) {
                mx = ((pix - pfx)/(pfy - piy));
                my = ((pfy - piy)/(pix - pfx));
            }
            else{
                mx = ((pix - pfx)/(piy - pfy));
                my = ((piy - pfy)/(pix - pfx));
            }
        }
    }

    for(int i = 0; i <= abs(pfx - pix); i++)
    {
        int aux = piy + (i * my);
        if (piy > pfy){
            aux = piy - (i * my);
        }

        int aux2 = pix + i;
        if (pix > pfx){
            aux2 = pix - i;
        }

        vector<Pixel*>* temp = this->pixeis.at(aux2);
        Pixel* p = temp->at(aux);

        //p->desenhar2();
        p->set_cor(0.0,0.0,0.0);
        p->set_desenhar(true);
    }
    for(int i = 0; i <= abs(pfy - piy); i++)
    {
        int aux = pix + (i * mx);
        if (pix > pfx){
            aux = pix - (i * mx);
        }

        int aux2 = piy +i;
        if (piy > pfy){
            aux2 = piy - i;
        }

        vector<Pixel*>* temp = this->pixeis.at(aux);
        Pixel* p = temp->at(aux2);

        //p->desenhar2();
        p->set_cor(0.0,0.0,0.0);
        p->set_desenhar(true);
    }
}
