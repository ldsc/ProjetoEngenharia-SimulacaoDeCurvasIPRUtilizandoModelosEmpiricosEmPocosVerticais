#ifndef CGeneralizada_H
#define CGeneralizada_H

#include "CFluido.h"
#include "CReservatorio.h"
#include "CPoco.h"

class CGeneralizada {
public:
    CGeneralizada(CFluido& fluido, CReservatorio& reservatorio, CPoco& poco);
    double CalcGeneralizada();

private:
    CFluido& parametrosFluido;
    CReservatorio& parametrosReservatorio;
    CPoco& parametrosPoco;
};

#endif // MODELOIPRGENERALIZADA_H
