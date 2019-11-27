#include "cutbox.h"

/*!
 * \brief Tendo como entrada a posição do cubo nos três eixos, a função objetiva apagar uma figura previamente desenhada.
 * \param _x0
 * \param _x1
 * \param _y0
 * \param _y1
 * \param _z0
 * \param _z1
 */
CutBox::CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1)
{
    x0 = _x0;x1 = _x1;y0 = _y0;y1 = _y1;z0 = _z0;z1 = _z1;
}

CutBox::~CutBox()
{

}


/*!
 * \brief A função draw será responsável por redesenhar a matriz retirando cada voxel do cubo.
 * \param t
 */
void CutBox::draw(Sculptor &t)
{
    for(int i = x0; i<=x1; i++){
        for(int j = y0; j<=y1; j++){
            for(int k = z0; k<=z1; k++){
                t.cutVoxel(i, j, k);
            }
        }
    }
}
