#ifndef CVogel_H
#define CVogel_H

#include "CFluido.h"
#include "CReservatorio.h"
#include "CPoco.h"

class CVogel {
public:
    CVogel(CFluido& fluido, CReservatorio& reservatorio, CPoco& poco);
    double CalcVogel();

private:
    CFluido& parametrosFluido;
    CReservatorio& parametrosReservatorio;
    CPoco& parametrosPoco;
};

#endif 
