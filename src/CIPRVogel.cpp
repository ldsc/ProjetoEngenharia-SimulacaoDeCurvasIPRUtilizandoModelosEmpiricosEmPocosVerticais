#include "CIPRVogel.h"
#include <cmath>
#include <iostream>

using namespace std;


void CIPRVogel::CalcIPR(CFluido* fluido, CReservatorio& reservatorio, CPoco& poco, CPoco& parametrosSegundoPoco) {
    double pi = reservatorio.PressaoInicial(); // Pressão inicial do reservatório
    double j = reservatorio.getIndiceProdutividade(); //Indice de Produtividade

    // Solicita os valores de teste do usuário
    double pwf1, pwf2, q1, q2;

    // Cálculo de qmax com os valores de teste
    double qmax = j*(pi)/1.8;

    // Inicializa a classe CIPRVariacaoPwf
    iprVariacaoPwf(pi);

    // Loop para variar pwf
    for (double pwf : valoresPwf) {
        double q;
        if (pwf == pi) {
            vazao.push_back(0); // Vazão zero quando pwf é igual a pi
        } else if (pwf == 0) {
            vazao.push_back(qmax); // Vazão máxima quando pwf é igual a zero
        } else {
            vazao.push_back(qmax * (1 - 0.2 * (pwf / pi) - 0.8 * pow(pwf / pi, 2)));
        }
    }

}
