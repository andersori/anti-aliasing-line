#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>
#include "matriz.h"
#include "linha.h"

class GLWidget : public QGLWidget
{
public:
    explicit GLWidget(QWidget* parent=0);
    ~GLWidget();

    void initializeGL();
    void paintGL();

    int get_dimensao();

public slots:
    void set_dimensao(int valor);
    void set_algoritmo(int algoritmo);
    void set_angulo(int angulo);

private:
    Matriz* mt;
    Linha* lin;
};

#endif // GLWIDGET_H
