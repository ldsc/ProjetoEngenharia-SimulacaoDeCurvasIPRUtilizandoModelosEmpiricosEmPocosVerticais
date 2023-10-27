#include "CVogel.h"
#include <cmath>

using namespace std; 
// Construtor da classe
CVogel::CVogel(CFluido& fluido, CReservatorio& reservatorio, CPoco& poco)
    : parametrosFluido(fluido), parametrosPoco(poco), parametrosReservatorio(reservatorio) {
}

// Método para calcular a taxa de produção de acordo com o modelo de Vogel
double CVogel::CalcVogel() {
    double pi = parametrosReservatorio.PInicial();
    double qmax = parametrosReservatorio.VazaoMaxima();
    double pwf = parametrosPoco.PressaoDeFundo();

    //Cálculo vazão modelo Vogel
    double q = qmax * ( 1 - 0.2 * (pwf/pi) - 0.8 * pow(pwf / pi, 2));
//Retorna a vazão
    return q;
}