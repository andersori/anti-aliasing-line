#ifndef LINHA_H
#define LINHA_H
#include <vector>
using std::vector;

class Linha
{
public:
    explicit Linha(int dim_i, int dim_j);
    ~Linha();

    void desenhar();
    void set_p1(int x, int y);
    void set_p2(int x, int y);

private:
    struct Posicao
    {
        int x;
        int y;
    };

    int dimencao_i;
    int dimencao_j;

    float* cor;
    vector<vector<Posicao *>* > posicoes;
};

#endif // LINHA_H
