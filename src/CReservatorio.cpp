#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "CReservatorio.h"

using namespace std;

// Implementação do método CoeficienteDietz da classe CReservatorio
void CReservatorio::CoeficienteDietz(CTipoGeometria _enumeracaoGeometria) {

// Switch para atribuir o coeficiente de Dietz baseado no tipo de geometria
	switch (_enumeracaoGeometria) {
		
		case CTipoGeometria::linear:
			coeficienteDietz = 30.8828;
			break;
		
		case CTipoGeometria::radial:
			coeficienteDietz = 31.62;
			break;
		
		default:			
			cout << "Geometria nao encontrada";
			break;
		
	}

}

// Implementação do método IndiceProdutividade da classe CReservatorio
void CReservatorio::IndiceProdutividade(CFluido* _fluido, CGeometria* _geometria, CPoco& _poco) {

	// Cálculo do Índice de Produtividade usando os parâmetros do reservatório
	indiceProdutividade = ((permeabilidade * espessura) / (141.2 * _fluido->FatorVolumeFormacao() * _fluido->Viscosidade() * (0.5 * log((4 * _geometria->getArea()) / (EulerCte * coeficienteDietz * _poco.getRaioPoco() * _poco.getRaioPoco())) + fatorPelicula)));

}