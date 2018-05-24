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
    void set_dimensao(int valor);

private:
    Matriz* mt;
    Linha* lin;
};

#endif // GLWIDGET_H
