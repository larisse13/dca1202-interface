#include "colordisplay.h"

#include <QPainter>
#include <QPen>
#include <QBrush>

colorDisplay::colorDisplay(QWidget *parent) : QWidget(parent)
{

}

/*!
 * \brief O método paintEvent tem como objetivo preparar a matriz de voxels para ser pintada.
 * \param event - Recebe como parâmetro de entrada o clique do usuário.
 */
void colorDisplay::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QPen pen;
    QBrush brush;

    // preparando a caneta
    pen.setColor(QColor(150,150,150));
    pen.setWidth(4);
    p.setPen(pen);

    // preparando o pincel
    brush.setColor(QColor(this->r,this->g,this->b,this->a));
    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);

    p.drawRect(0,0,width(),height()); //painting the background rectangle

}


/*!
 * \brief A função tem como objetivo mudar a cor da caneta. Recebe como parâmetros de entrada os valores correspondentes ao código RGBA das cores.
 * \param r
 * \param g
 * \param b
 * \param a
 */
void colorDisplay::changeColor(int r, int g, int b, int a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
    repaint();
}
