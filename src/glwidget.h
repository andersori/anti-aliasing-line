#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>
#include "matriz.h"

class GLWidget : public QGLWidget
{
public:
    explicit GLWidget(QWidget* parent=0);
    ~GLWidget();

    void initializeGL();
    void paintGL();

private:
    Matriz* mt;
};

#endif // GLWIDGET_H
