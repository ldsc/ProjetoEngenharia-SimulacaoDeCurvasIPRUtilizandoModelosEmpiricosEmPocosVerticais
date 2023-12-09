#include "CIPRFetkovich.h"
#include <cmath>
#include <iostream>

using namespace std;

void CIPRFetkovich::CalcIPR(CFluido* fluido, CReservatorio& reservatorio, CPoco& poco, CPoco& pocoDois)
{

    double pi = reservatorio.PressaoInicial();
   	double pwf = pi; // Inicializa o valor de pwf como pi

    // Solicita os valores de teste do usuario
    double pwf1, pwf2, q1, q2;


    pwf1 = poco.getPressao();


    pwf2 = pocoDois.getPressao();


    q1 = poco.getVazaoProducao();

    q2 = pocoDois.getVazaoProducao();
    
	//Definicao das constantes empiricas n e C
    double n = ( log(q1/q2) ) / ( log ( ( pow (pi,2) - pow(pwf1,2) )/ ( pow(pi,2) - pow(pwf2,2) ) ) );
    double C = q1 / pow( (pow(pi,2) - pow(pwf1,2)), n);
    
	// Calculo de qmax com os valores de teste
    double qmax = C * pow(pi, 2*n);
    
    
    iprVariacaoPwf(pwf);

    // Loop para variar pwf
    for (double pwf : valoresPwf) {
        if (pwf == pi) {
            vazao.push_back(0); // Vazao zero quando pwf eh igual a pi
        } else if (pwf == 0) {
            vazao.push_back(qmax); // Vazao maxima quando pwf eh igual a zero
        } else {
            vazao.push_back(qmax * (1 - pow(pwf/pi, 2 ) ));
        }
        cout << "Pwf: " << pwf << ", Vazao: " << qmax * (1 - pow(pwf/pi, 2 ) ) << endl;
    }
}