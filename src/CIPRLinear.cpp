#include "CIPRLinear.h"
#include <cmath>

CIPRLinear::CIPRLinear(CFluido& fluido, CReservatorio& reservatorio, CPoco& poco)
    : parametrosFluido(fluido), parametrosReservatorio(reservatorio), parametrosPoco(poco) {
   
}

double CIPRLinear::CalcLinear() {
	double j = parametrosReservatorio.IndiceProdutividade();
	double pi = parametrosReservatorio.PInicial();
	double pwf = parametrosPoco.PressaoDeFundo();
	//Cálculo vazão IPRLinear
	double q = j * (pi - pwf);
    
    // Retorna a vazão
    return q;
}
