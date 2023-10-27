#include "CFetkovich.h"
#include <cmath>

CFetkovich::CFetkovich(CFluido& fluido, CReservatorio& reservatorio, CPoco& poco)
    : parametrosFluido(fluido), parametrosReservatorio(reservatorio), parametrosPoco(poco) {
   
}

double CFetkovich::CalcFetkovich() {
	
	double pi = parametrosReservatorio.PInicial();
    double qmax = parametrosReservatorio.VazaoMaxima();
    double pwf = parametrosPoco.PressaoDeFundo();
    
	//Cálculo vazão Modelo Fetkovich
	double q = qmax * (1 - pow(pwf/pi, 2 ) );
    
    // Retorna a vazão
    return q;
}