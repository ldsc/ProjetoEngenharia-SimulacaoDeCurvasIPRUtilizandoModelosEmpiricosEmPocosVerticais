#ifndef CReservatorio_h
#define CReservatorio_h

// Inclusão dos arquivos de cabeçalho

#include "CRocha.h"
#include "CGeometria.h"
#include "CLinear.h"
#include "CRadial.h"
#include "CTipoGeometria.h"
#include "CTipoFluido.h"
#include "CFluido.h"
#include "COleo.h"
#include "CGas.h"
#include "CPoco.h"

#include <iostream>

// Classe CReservatório que representa o reservatório 

class CReservatorio: public CRocha {
	
	protected:
		
		double espessura; // Espessura do reservatório
		double EulerCte = 1.781; // Constante de Euler
		double fatorPelicula; // Fator de película do reservatório
		double pressaoBolha; // Pressão de bolha do reservatório
		double pressaoInicial; // Pressão média inicial do reservatório
		double temperatura; // Temperatura
		double coeficienteDietz; // Coeficiente de Dietz
		double indiceProdutividade; // Indice de Produtividade do reservatório
		CTipoGeometria enumeracaoGeometria; // Enumeração para escolha do tipo de geometria
		CTipoFluido enumeracaoFluido; // Enumeração para escolha do tipo de fluido
		CPoco poco; // Objeto de CPoco associado a reservatório
		
	public:
		
		CReservatorio () {} // Construtor default
		
		~CReservatorio () {} // Destrutor
		
		double Espessura () const {return espessura;} // Método get para a espessura
		void Espessura (double _espessura) {espessura = _espessura;} // Método set para a espessura
		
		double FatorPelicula() const {return fatorPelicula;} // Método get para a fatorPelicula
		void FatorPelicula (double _fatorPelicula) {fatorPelicula = _fatorPelicula;} // Método set para a fatorPelicula
		
		double PressaoBolha() const {return pressaoBolha;} // Método get para a pressaoBolha
		void PressaoBolha (double _pressaoBolha) {pressaoBolha = _pressaoBolha;} // Método set para a pressaoBolha
		
		double PressaoInicial() const {return pressaoInicial;} // Método get para a pressaoInicial
		void PressaoInicial (double _pressaoInicial) {pressaoInicial = _pressaoInicial;} // Método set para a pressaoInicial
		
		double Temperatura() const {return temperatura;} // Método get para a temperatura
		void Temperatura (double _temperatura) {temperatura = _temperatura;} // Método set para a temperatura
		
		void setGeometria(CTipoGeometria _enumeracaoGeometria); // Método set para o tipo de geometria
		
		void setFluido(CTipoFluido _enumeracaoFluido); // Método set para o tipo de fluido
		
		void setFatorVolumeFormacao(double _fatorVolumeFormacao); // Método set para o fator volume-formação
		
		void CoeficienteDietz(CTipoGeometria _enumeracaoGeometria); // Método para cálculo do Coeficiente de Dietz a ser utilizado
        double getCoeficienteDietz() { return coeficienteDietz; }
		
		void IndiceProdutividade(CFluido* _fluido, CGeometria* _geometria, CPoco& _poco); // Método para cálculo do Índice de Produtividade
        double getIndiceProdutividade() {return indiceProdutividade; }
		
		double VazaoMaxima() {return ((indiceProdutividade * pressaoInicial)/1.8);} // Método para cálculo da máxima vazão obtida pelo reservatório (AOF)
		
};

#endif