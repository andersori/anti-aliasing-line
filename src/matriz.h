#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>
#include "pixel.h"
using std::vector;

class Matriz
{

public:
    explicit Matriz(int dimencao_x = 20, int dimencao_y = 20);
    ~Matriz();

    void desenhar();

private:
    int dimencao_x;
    int dimencao_y;

    void lin_pixel();
    vector<vector<Pixel*>* > pixeis;
};

#endif // MATRIZ_H
