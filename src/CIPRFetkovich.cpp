#include "CIPRFetkovich.h"
#include <cmath>
#include <iostream>

using namespace std;

void CIPRFetkovich::CalcIPR(CFluido* fluido, CReservatorio& reservatorio, CPoco& poco, CPoco& pocoDois)
{

    double pi = reservatorio.PressaoInicial();
   	double pwf = pi; // Inicializa o valor de pwf como pi

    // Solicita os valores de teste do usuário
    double pwf1, pwf2, q1, q2;


    pwf1 = poco.getPressao();


    pwf2 = pocoDois.getPressao();


    q1 = poco.getVazaoProducao();

    q2 = pocoDois.getVazaoProducao();
    
	//Definição das constantes empíricas n e C
    double n = ( log(q1/q2) ) / ( log ( ( pow (pi,2) - pow(pwf1,2) )/ ( pow(pi,2) - pow(pwf2,2) ) ) );
    double C = q1 / pow( (pow(pi,2) - pow(pwf1,2)), n);
    
	// Cálculo de qmax com os valores de teste
    double qmax = C * pow(pi, 2*n);
    
    
    iprVariacaoPwf(pwf);

    // Calcula os valores de pwf e armazena em um vetor
    //vector<double> valoresPwf = iprVariacaoPwf.CalcIPR();

    // Loop para variar pwf
    for (double pwf : valoresPwf) {
        if (pwf == pi) {
            vazao.push_back(0); // Vazão zero quando pwf é igual a pi
        } else if (pwf == 0) {
            vazao.push_back(qmax); // Vazão máxima quando pwf é igual a zero
        } else {
            vazao.push_back(qmax * (1 - pow(pwf/pi, 2 ) ));
        }
        cout << "Pwf: " << pwf << ", Vazao: " << qmax * (1 - pow(pwf/pi, 2 ) ) << endl;
    }
}