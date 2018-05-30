#include "matriz.h"
#include <QDebug>
using std::vector;

Matriz::Matriz(int altura, int largura, int dimensao)
    : linha(dimensao), coluna(dimensao), aspecto(Janela(altura, largura))
{
    qDebug() << "Altura:" << altura << ", Dimensao: " << dimensao << " = " << (this->aspecto.altura + 0.0) / (dimensao+0.0) << ".";
    this->algoritmo = 1;

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

    if(algoritmo == 1)
    {
        bresenham(lin);
    }
    if(algoritmo == 2)
    {
        borramento();
    }


    for(int i = 0; i < this->linha; i++)
    {
        vector<Pixel*>* qq = pixeis.at(i);
        for(int j = 0; j < this->coluna; j++)
        {
            Pixel* pp = qq->at(j);

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
    if(valor != this->linha)
    {
        if(valor > this->linha)
        {
            //Almentar a dimenção da matriz
            for(int i = 0; i < valor; i++)
            {
                if(i >= this->linha && i < valor)
                {
                    vector<Pixel* >* nova_linha = new vector<Pixel*>();

                    for(int j = 0; j < valor; j++)
                    {
                        nova_linha->push_back(new Pixel(i,j,((this->aspecto.altura + 0.0) / (valor + 0.0)), -1, -1));
                    }
                    this->pixeis.push_back(nova_linha);

                }
                else
                {
                    vector<Pixel* >* linha_do_pixel = this->pixeis.at(i);

                    for(int j = 0; j < valor; j++)
                    {
                        if(j >= this->coluna && j < valor)
                        {
                            linha_do_pixel->push_back(new Pixel(i,j,((this->aspecto.altura + 0.0) / (valor + 0.0)), -1, -1));
                        }
                        else
                        {
                            Pixel* temp = linha_do_pixel->at(j);
                            temp->set_tamanho((this->aspecto.altura + 0.0) / (valor + 0.0));
                            temp->set_cor(1.0, 1.0, 1.0);
                        }
                    }
                }

            }

        }
        else
        {
            //Diminuir a dimensão da matriz
            for(int i = 0; i < this->linha; i++)
            {
                if(i >= (valor))
                {
                    this->pixeis.pop_back();
                }
                else
                {
                    vector<Pixel* >* linha_do_pixel = this->pixeis.at(i);

                    for(int j = 0; j < this->coluna; j++)
                    {
                        if(j >= (valor))
                        {
                            linha_do_pixel->pop_back();
                        }
                        else
                        {
                            Pixel* temp = linha_do_pixel->at(j);
                            temp->set_tamanho((this->aspecto.altura + 0.0) / (valor + 0.0));
                            temp->set_cor(1.0, 1.0, 1.0);
                        }

                    }

                }

            }
        }

        this->linha = valor;
        this->coluna = valor;

    }
}

void Matriz::borramento()
{
    if(get_dimensao()>1){
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

}

float Matriz::coeficiente(float pix, float piy, float pfx, float pfy)
{
    if (pfx == pix || pfy == piy){
        return 0.0;
    }
    else{
        if (pix < pfx){
            if (piy < pfy){
                return ((pfx - pix)/(pfy - piy));
            }
            else{
                return ((pfx - pix)/(piy - pfy));
            }
        }
        else {
            if ( piy < pfy) {
                return ((pix - pfx)/(pfy - piy));
            }
            else{
                return ((pix - pfx)/(piy - pfy));
            }
        }
    }
}

void Matriz::calBresenham(float **matrizTemp, float pix, float piy, float pfx, float pfy, float mx, float my)
{
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

        matrizTemp[aux2][aux] = 0.0;

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

        matrizTemp[aux][aux2] = 0.0;
    }
}

void Matriz::bresenham(Linha *lin)
{
    if(get_dimensao()>1){
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


        float** MatrizTemp = new float*[this->linha*3];

        for (int i = 0; i < (this->linha*3); i++){
            MatrizTemp[i] = new float[this->linha*3];
            for (int j = 0; j < (this->linha * 3); j++){
                MatrizTemp[i][j] = 1.0;
            }
        }

        float Mix[5] = {pix*3+2, pix*3+1, pix*3, pix*3, pix*3};
        float Miy[5] = {piy*3, piy*3, piy*3, piy*3+1, piy*3+2};
        float Mfx[5] = {pfx*3+2, pfx*3+2, pfx*3+2, pfx*3+1, pfx*3};
        float Mfy[5] = {pfy*3, pfy*3+1, pfy*3+2, pfy*3+2, pfy*3+2};

        float Coeficientes[5][2] = { { coeficiente(Mix[0],Miy[0],Mfx[0],Mfy[0]), coeficiente(Miy[0],Mix[0],Mfy[0],Mfx[0]) },
                                     { coeficiente(Mix[1],Miy[1],Mfx[1],Mfy[1]), coeficiente(Miy[1],Mix[1],Mfy[1],Mfx[1]) },
                                     { coeficiente(Mix[2],Miy[2],Mfx[2],Mfy[2]), coeficiente(Miy[2],Mix[2],Mfy[2],Mfx[2]) },
                                     { coeficiente(Mix[3],Miy[3],Mfx[3],Mfy[3]), coeficiente(Miy[3],Mix[3],Mfy[3],Mfx[3]) },
                                     { coeficiente(Mix[4],Miy[4],Mfx[4],Mfy[4]), coeficiente(Miy[4],Mix[4],Mfy[4],Mfx[4]) } };


        for (int i = 0; i < 5; i++)
        {

            calBresenham(MatrizTemp, Mix[i], Miy[i], Mfx[i], Mfy[i], Coeficientes[i][0], Coeficientes[i][1]);
        }

        for (int i = 0; i < this->linha; i ++ ){
            for (int j = 0; j < this->linha; j++) {
                float aux = (MatrizTemp[3*i][3*j] + MatrizTemp[3*i+1][3*j] + MatrizTemp[3*i+2][3*j] +
                        MatrizTemp[3*i][3*j+1] + MatrizTemp[3*i+1][3*j+1] + MatrizTemp[3*i+2][3*j+1] +
                        MatrizTemp[3*i][3*j+2] + MatrizTemp[3*i+1][3*j+2] + MatrizTemp[3*i+2][3*j+2])/9;

                vector<Pixel*>* temp = this->pixeis.at(i);
                Pixel* p = temp->at(j);

                //p->desenhar2();
                p->set_cor(aux,aux,aux);
                p->set_desenhar(true);
            }
        }

    }

}

void Matriz::set_algoritmo(int id)
{
    this->algoritmo = id;
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
