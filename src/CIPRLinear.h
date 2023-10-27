#ifndef MODELOIPRLINEAR_H
#define MODELOIPRLINEAR_H

#include "CFluido.h"
#include "CPoco.h"
#include "CReservatorio.h"

class CIPRLinear {
public:
    CIPRLinear(CFluido& fluido, CReservatorio& reservatorio, CPoco& poco);
    double CalcLinear();

private:
    CFluido& parametrosFluido;
    CReservatorio& parametrosReservatorio;
    CPoco& parametrosPoco;
};

#endif 
