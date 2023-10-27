#ifndef CFetkovich_h
#define CFetkovich_h

#include "CFluido.h"
#include "CReservatorio.h"
#include "CPoco.h"

class CFetkovich {
public:
    CFetkovich(CFluido& fluido, CReservatorio& reservatorio, CPoco& poco);
    double CalcFetkovich();

private:
    CFluido& parametrosFluido;
    CReservatorio& parametrosReservatorio;
    CPoco& parametrosPoco;
};

#endif 
