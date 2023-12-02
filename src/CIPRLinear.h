#ifndef MODELOIPRLINEAR_H
#define MODELOIPRLINEAR_H

#include "CIPR.h"

class CIPRLinear : public CIPR
{

public:
    CIPRLinear(){}; // Construtor padrao
    void CalcIPR(CFluido* fluido, CReservatorio& reservatorio, CPoco& poco) override;
    
};

#endif 	