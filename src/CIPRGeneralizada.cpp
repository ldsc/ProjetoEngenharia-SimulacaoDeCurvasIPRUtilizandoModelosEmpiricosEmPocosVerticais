#include "CGeneralizada.h"
#include <cmath> 

CGeneralizada::CGeneralizada(CFluido& fluido, CPoco& poco, CReservatorio& reservatorio, bool abaixoDaPressaoDeBolha)
    : parametrosFluido(fluido), parametrosPoco(poco), parametrosReservatorio(reservatorio), abaixoDaPressaoDeBolha(abaixoDaPressaoDeBolha) {
}

double CGeneralizada::CalcGeneralizada() {
    double pwf = parametrosPoco.PressaoDeFundo();
    double pb = parametrosReservatorio.PBolha();
    double q = parametrosPoco.GetQ();
    double pi = parametrosReservatorio.PInicial();
    double j = parametrosReservatorio.IndiceProdutividade();

    if (abaixoDaPressaoDeBolha) {
        // Use a fórmula correta para abaixo da pressão de bolha
        q = j * (pi - pb) + ((j * pb) / 1.8) * (1 - 0.2 * (pwf / pb) - 0.8 * ((pwf / pb) * (pwf / pb)));
    } else {
        // Use a fórmula correta para acima da pressão de bolha
        q = j * (pi - pb);
    }

    return q;
}