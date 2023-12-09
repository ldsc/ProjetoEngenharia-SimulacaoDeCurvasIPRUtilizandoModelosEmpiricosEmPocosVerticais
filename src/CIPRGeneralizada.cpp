#include "CIPRGeneralizada.h"
#include<iostream>
#include <cmath> 

void CIPRGeneralizada::CalcIPR(CFluido* fluido, CReservatorio& reservatorio, CPoco& poco) {
    double j = reservatorio.getIndiceProdutividade();
    double pi = reservatorio.PressaoInicial();
    double pb = reservatorio.PressaoBolha();

    // Inicializa a classe CIPRVariacaoPwf
    iprVariacaoPwf(pi);

    if (pi <= pb) {
        // Loop para calcular a vazao para cada valor de Pwf
        for (double pwf : valoresPwf) {
            vazao.push_back(j * (pi - pb) + ((j * pb) / 1.8) * (1.0 - 0.2 * (pwf / pb) - 0.8 * ((pwf / pb) * (pwf / pb))));

            std::cout << "Pwf: " << pwf << ", Vazao: " << j * (pi - pwf) << std::endl;
        }
    } else {
        // Mostrar mensagem de erro e encerrar o codigo
        for (double pwf : valoresPwf) {
            vazao.push_back(j * (pi - pwf));

            std::cout << "Pwf: " << pwf << ", Vazao: " << j * (pi - pwf) << std::endl;
        }
    }

}