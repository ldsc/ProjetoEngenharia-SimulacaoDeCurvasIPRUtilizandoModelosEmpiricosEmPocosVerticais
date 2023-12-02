#include "CIPRLinear.h"
#include <iostream>
#include <cmath>

void CIPRLinear::CalcIPR(CFluido* fluido, CReservatorio& reservatorio, CPoco& poco) {
    
    double j = reservatorio.getIndiceProdutividade();
    double pi = reservatorio.PressaoInicial();
    double pb = reservatorio.PressaoBolha();
    
    iprVariacaoPwf(pi);  // Inicializa a classe CIPRVariacaoPwf com parâmetro pi
    
	// Uma estrutura condicional verifica se a pressão inicial é maior que a pressão de bolha
    if (pi > pb) {
        // Loop para calcular a vazão para cada valor de Pwf
        for (double pwf : valoresPwf) {
            vazao.push_back(j * (pi - pwf));

            std::cout << "Pwf: " << pwf << ", Vazao: " << j * (pi - pwf) << std::endl;
        }
    } else {
        // Mostrar mensagem de erro e encerrar o código
        std::cout << "A pressão do reservatório (pi) é menor ou igual à pressão de bolha (pb). Selecione um valor acima de pb." << std::endl;
        exit(1); // Encerra o programa com um código de erro
    }

}
