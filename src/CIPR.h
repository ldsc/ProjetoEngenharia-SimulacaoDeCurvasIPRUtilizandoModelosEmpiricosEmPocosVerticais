#ifndef CIPR_H
#define CIPR_H

#include "CFluido.h"
#include "CReservatorio.h"
#include "CPoco.h"
#include <vector>

class CIPR
{

public:

    CIPR();
    virtual void CalcIPR(CFluido* fluido, CReservatorio& reservatorio, CPoco& poco, CPoco& parametrosSegundoPoco);
    virtual void CalcIPR(CFluido* fluido, CReservatorio& reservatorio, CPoco& poco);
    std::vector<double> getPWF() {return valoresPwf;}
    void setPWF(std::vector<double> _valoresPwf) { valoresPwf = _valoresPwf; }
    std::vector<double> getVazao() {return vazao; }
    void iprVariacaoPwf(double _pwf);
    void setPartes(double _partes) { partes = _partes; }

protected:

    std::vector<double> valoresPwf;
    std::vector<double> vazao ;
    double partes;


};

#endif