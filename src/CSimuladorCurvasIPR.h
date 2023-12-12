#ifndef CSimuladorCurvasIPR_h
#define CSimuladorCurvasIPR_h

#include <iostream>
#include <string>
#include <vector>

#include "CPoco.h"
#include "CFluido.h"
#include "COleo.h"
#include "CGas.h"
#include "CGeometria.h"
#include "CLinear.h"
#include "CRadial.h"
#include "CReservatorio.h"
#include "CRocha.h"
#include "CIPRLinear.h"
#include "CIPRFetkovich.h"
#include "CIPRVogel.h"
#include "CIPRGeneralizada.h"
#include "CIPR.h"
#include "CGnuplot.h"
#include "CMetodo.h"
#include "CTipoGeometria.h"

class CSimuladorCurvasIPR {
	
	private:
		
        CReservatorio reservatorio; // Criando objeto reservatorio
        CPoco poco; // Criando objeto poco
        CPoco pocoDois; // Criando segundo objeto poco para IPR do tipo Fetkovich
        CIPR* IPR; // Ponteiro para apontar para o tipo de metodo
        CGeometria* forma; // Ponteiro para apontar a geometria do reservatorio
        CTipoGeometria* geometria; // Ponteiro para apontar a geometria do reservatorio
        CFluido* fluido; // Ponteiro para apontar o tipo de fluido: gas ou oleo
        Gnuplot plot; // Criando objeto plot
        CMetodo metodo; // Criando objeto para enumeracao do metodo

        std::vector<double> vazoes; // Criando vetor de vazoes
        std::vector<double> pressoes; // Criando vetor de pressoes de fundo
		
	public:
		
		CSimuladorCurvasIPR(){}; // Construtor
		~CSimuladorCurvasIPR(); // Destrutor
		
		void EntradaDados(); // Metodo para entrada de dados do usuario

        void Calculos(); // Metodo para calculos da simulacao
		
		void Plotar(); // Metodo para plotar as curvas
		
		void SalvarGrafico(); // Metodo para salvar o grafico
		
		void Executar(); // Metodo para execucao do programa
		
};

#endif