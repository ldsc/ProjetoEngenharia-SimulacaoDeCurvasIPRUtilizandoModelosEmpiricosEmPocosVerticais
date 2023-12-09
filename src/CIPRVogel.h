#ifndef CVogel_H
#define CVogel_H

#include "CFluido.h"
#include "CReservatorio.h"
#include "CPoco.h"
#include "CIPR.h"

class CIPRVogel : public CIPR {
public:
    CIPRVogel(){};
    virtual void CalcIPR(CFluido* fluido, CReservatorio& reservatorio, CPoco& poco, CPoco& parametrosSegundoPoco) override;

};

#endif 
