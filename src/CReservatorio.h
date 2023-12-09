#ifndef CReservatorio_h
#define CReservatorio_h

// Inclusao dos arquivos de cabecalho

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

// Classe CReservatorio que representa o reservatorio 

class CReservatorio: public CRocha {
	
	protected:
		
		double espessura; // Espessura do reservatorio
		double EulerCte = 1.781; // Constante de Euler
		double fatorPelicula; // Fator de pelicula do reservatorio
		double pressaoBolha; // Pressao de bolha do reservatorio
		double pressaoInicial; // Pressao media inicial do reservatorio
		double temperatura; // Temperatura
		double coeficienteDietz; // Coeficiente de Dietz
		double indiceProdutividade; // Indice de Produtividade do reservatorio
		CTipoGeometria enumeracaoGeometria; // Enumeracao para escolha do tipo de geometria
		CTipoFluido enumeracaoFluido; // Enumeracao para escolha do tipo de fluido
		CPoco poco; // Objeto de CPoco associado a reservatorio
		
	public:
		
		CReservatorio () {} // Construtor default
		
		~CReservatorio () {} // Destrutor
		
		double Espessura () const {return espessura;} // Metodo get para a espessura
		void Espessura (double _espessura) {espessura = _espessura;} // Metodo set para a espessura
		
		double FatorPelicula() const {return fatorPelicula;} // Metodo get para a fatorPelicula
		void FatorPelicula (double _fatorPelicula) {fatorPelicula = _fatorPelicula;} // Metodo set para a fatorPelicula
		
		double PressaoBolha() const {return pressaoBolha;} // Metodo get para a pressaoBolha
		void PressaoBolha (double _pressaoBolha) {pressaoBolha = _pressaoBolha;} // Metodo set para a pressaoBolha
		
		double PressaoInicial() const {return pressaoInicial;} // Metodo get para a pressaoInicial
		void PressaoInicial (double _pressaoInicial) {pressaoInicial = _pressaoInicial;} // Metodo set para a pressaoInicial
		
		double Temperatura() const {return temperatura;} // Metodo get para a temperatura
		void Temperatura (double _temperatura) {temperatura = _temperatura;} // Metodo set para a temperatura
		
		void setGeometria(CTipoGeometria _enumeracaoGeometria); // Metodo set para o tipo de geometria
		
		void setFluido(CTipoFluido _enumeracaoFluido); // Metodo set para o tipo de fluido
		
		void setFatorVolumeFormacao(double _fatorVolumeFormacao); // Metodo set para o fator volume-formacao
		
		void CoeficienteDietz(CTipoGeometria _enumeracaoGeometria); // Metodo para calculo do Coeficiente de Dietz a ser utilizado
        double getCoeficienteDietz() { return coeficienteDietz; }
		
		void IndiceProdutividade(CFluido* _fluido, CGeometria* _geometria, CPoco& _poco); // Metodo para calculo do Indice de Produtividade
        double getIndiceProdutividade() {return indiceProdutividade; }
		
		double VazaoMaxima() {return ((indiceProdutividade * pressaoInicial)/1.8);} // Metodo para calculo da maxima vazao obtida pelo reservatorio (AOF)
		
};

#endif