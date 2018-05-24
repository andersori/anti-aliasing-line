#ifndef PIXEL_H
#define PIXEL_H

#include <vector>
#include <string>

using std::string;
using std::vector;

class Pixel
{

public:
    explicit Pixel(int i, int j, float tamanho, float x_mundo, float y_mundo);
    ~Pixel();

    void desenhar();
    void desenhar2();

    const char *get_descricao();
    void set_desenhar(bool);

    void set_min_XY(float, float);
    void set_max_XY(float, float);

private:
    struct Posicao{
        //x e y da posição inferior esquerda do pixel
        float y_min;
        float x_min;

        //x e y da posição superior direita do pixel
        float y_max;
        float x_max;
    };

    bool desenhar_pix;

    //Posicao na matriz
    int i;
    int j;

    //Cor do pixel
    float* cor;

    //Posicão do Pixel
    Posicao pos;

    float* pos_mundo;
    /*
    //Definirá a quantidade de quadradinhos que irão compor o pixel
    int dimencao;
    //Definirá a intensidade da cor do pixel de acordo com a quantidade de quadradinhos que
    //o desenho passa por cima
    float intencidade_da_cor;
    //Atualizacão para o futuro
    vector<vector<Posicao> > quadradinhos;
    */
};

#endif // PIXEL_H
