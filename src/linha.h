#ifndef LINHA_H
#define LINHA_H
#include <vector>
using std::vector;

class Linha
{
public:
    struct Posicao
    {
        float x;
        float y;
    };

    explicit Linha(int dimensao, int tamanho, float angulo);
    ~Linha();

    void desenhar();

    void set_ponto_inicial(float x, float y);
    void set_ponto_final(float x, float y);

    void set_dimensao(int dim);
    void set_angulo(float angulo);

    float get_angulo() const;
    Posicao* get_ponto_inicial() const;
    Posicao* get_ponto_final() const;

private:
    int dimensao;
    float angulo;
    int tamanho;

    float* cor;
    Posicao* p1;
    Posicao* p2;

    void rotacionar();
};

#endif // LINHA_H
