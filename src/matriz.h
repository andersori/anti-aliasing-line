#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>
#include "linha.h"
#include "pixel.h"
using std::vector;

class Matriz
{

public:
    Matriz(int altura = 2, int largura = 2, int dimensao = 20);
    ~Matriz();

    void desenhar(Linha *lin);

    //Dimensão
    int get_dimensao();
    void set_dimensao(int valor);

    //1ª algoritmo para resolver o aliasing
    void borramento();

    //2ª algoritmo para resolver o aliasing
    float coeficiente(float pix,float piy, float pfx, float pfy);
    void calBresenham(float **matrizTemp, float pix, float piy, float pfx, float pfy, float mx, float my);
    void bresenham(Linha* lin);

    //Qual algoritmo usar
    void set_algoritmo(int id);

private:
    //Produz o aliasing
    void pixeis_da_linha(Linha* lin);

    struct Janela{
        Janela(int altura, int largura)
        {
            this->altura = altura;
            this->largura = largura;
        }

        int altura;
        int largura;
    };

    int linha;
    int coluna;

    Janela aspecto;

    vector<vector<Pixel*>* > pixeis;

    int algoritmo;
};

#endif // MATRIZ_H
