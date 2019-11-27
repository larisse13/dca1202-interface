#include "cutvoxel.h"



/*!
 * \brief A classe CutVoxel tem como objetivo apagar um voxel já criado na matriz. Ela possui 3 parâmetros de entrada que são respectivamente:
 * \param _x - Posição do voxel em x
 * \param _y - Posição do voxel em y
 * \param _z - Posição do voxel em z
 */

CutVoxel::CutVoxel(int _x, int _y, int _z){
    x = _x;y = _y;z = _z;
}


CutVoxel::~CutVoxel(){

}

/*!
 * \brief Função que faz o recorte das três coordenadas do voxel.
 * \param t
 */
void CutVoxel::draw(Sculptor &t){
    t.cutVoxel(x, y, z);
}
