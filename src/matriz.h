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
    int get_dimensao();
    void set_dimensao(int valor);

private:
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
};

#endif // MATRIZ_H
