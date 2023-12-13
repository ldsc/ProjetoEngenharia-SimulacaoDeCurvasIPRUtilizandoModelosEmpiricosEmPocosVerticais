#ifndef CFetkovich_h
#define CFetkovich_h

#include "CIPR.h"

class CIPRFetkovich : public CIPR{
public:
    CIPRFetkovich(){};
    virtual void CalcIPR(CFluido* fluido, CReservatorio& reservatorio, CPoco& poco, CPoco& pocoDois) override;
    
};

#endif 
