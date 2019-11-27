#include "putvoxel.h"

/*!
 * \brief Responsável por receber as dimensões e cores - em RGBA - do voxel para desenhar na matriz.
 * \param _x
 * \param _y
 * \param _z
 * \param _r
 * \param _g
 * \param _b
 * \param _a
 */
PutVoxel::PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a)
{
    x = _x;y = _y;z = _z;
    r = _r;g = _g;b = _b;a = _a;
}

PutVoxel::~PutVoxel()
{

}


/*!
 * \brief Desenha o voxel na matriz e atualiza as cores.
 * \param t
 */
void PutVoxel::draw(Sculptor &t)
{
    t.setColor(r, g, b, a);
    t.putVoxel(x, y, z);
}
