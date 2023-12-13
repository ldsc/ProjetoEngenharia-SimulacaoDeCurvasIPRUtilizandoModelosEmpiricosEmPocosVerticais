#ifndef CIPRGeneralizada_H
#define CIPRGeneralizada_H

#include "CIPR.h"

class CIPRGeneralizada : public CIPR {
public:
    CIPRGeneralizada(){};
    virtual void CalcIPR(CFluido* fluido, CReservatorio& reservatorio, CPoco& poco);

};

#endif // MODELOIPRGENERALIZADA_H
