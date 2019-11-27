#include "putellipsoid.h"


/*!
 * \brief Responsável por receber as dimensões e cores - em RGBA - do elipsoide para desenhar na matriz.
 * \param _xcenter
 * \param _ycenter
 * \param _zcenter
 * \param _rx
 * \param _ry
 * \param _rz
 * \param _r
 * \param _g
 * \param _b
 * \param _a
 */
PutEllipsoid::PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a)
{
    xcenter = _xcenter;ycenter = _ycenter;zcenter = _zcenter;
    rx = _rx;ry = _ry;rz = _rz;
    r = _r;g = _g; b = _b;a = _a;
}
PutEllipsoid::~PutEllipsoid()
{

}


/*!
 * \brief Desenha voxel a voxel o elipsoide na matriz.
 * \param t
 */
void PutEllipsoid::draw(Sculptor &t){
    for (int i = xcenter-rx; i < xcenter+rx; i++) {
        for (int j = ycenter-ry; j < ycenter+ry; j++){
            for (int k = zcenter-rz; k < zcenter+ rz; k++){
                if(((float)pow((i-xcenter),2)/(pow(rx,2)))+((float)pow((j-ycenter),2)/(pow(ry,2)))+((float)pow((k-zcenter),2)/(pow(rz,2)))<1.0){
                    t.putVoxel(i,j,k);
                }
            }
        }
    }
}
