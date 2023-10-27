#ifndef CGeneralizada_h
#define CGeneralizada_h

#include "CFluido.h"
#include "CPoco.h"
#include "CReservatorio.h"

class CGeneralizada {
public:
    CGeneralizada(CFluido& fluido, CPoco& poco, CReservatorio& reservatorio, bool abaixoDaPressaoDeBolha);

    double CalcGeneralizada();

private:
    CFluido& parametrosFluido;
    CPoco& parametrosPoco;
    CReservatorio& parametrosReservatorio;
    bool abaixoDaPressaoDeBolha;
};

#endif