#include "putbox.h"


/*!
 * \brief Responsável por receber as dimensões e cores - em RGBA - do cubo para desenhar na matriz.
 * \param _x0
 * \param _x1
 * \param _y0
 * \param _y1
 * \param _z0
 * \param _z1
 * \param _r
 * \param _g
 * \param _b
 * \param _a
 */
PutBox::PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a)
{
    x0 = _x0;x1 = _x1;y0 = _y0;y1 = _y1;z0 = _z0;z1 = _z1;
    r = _r;g = _g;b = _b;a = _a;
}

PutBox::~PutBox()
{

}


/*!
 * \brief Desenha a forma geométrica voxel por voxel até terminar de preencher as dimensões especificadas.
 * \param t
 */
void PutBox::draw(Sculptor &t){
    for (int i = x0; i<=x1; i++){
        for (int j = y0; j<=y1; j++){
            for (int k = z0; k<=z1; k++){
                t.putVoxel(i,j,k);
            }
        }
    }
}
