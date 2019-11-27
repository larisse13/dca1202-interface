#include "cutsphere.h"

/*!
 * \brief Recebe como parâmetros as coordendas do centro e o raio, que como é uma esfera é o mesmo para toda a dimensão da figura.
 * \param _xcenter
 * \param _ycenter
 * \param _zcenter
 * \param _radius
 */
CutSphere::CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius )
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
}

CutSphere::~CutSphere()
{

}

/*!
 * \brief Função que apaga cada voxel da figura desejada.
 * \param t
 */
void CutSphere::draw(Sculptor &t){
    for (int i = xcenter-radius; i < xcenter+radius; i++) {
        for (int j = ycenter-radius; j < ycenter+radius; j++){
            for (int k = zcenter-radius; k < zcenter+radius; k++){
                if(((float)pow((i-xcenter),2))+((float)pow((j-ycenter),2))+((float)pow((k-zcenter),2))<=(pow(radius,2))){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}
