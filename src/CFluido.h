#ifndef CFluido_h
#define CFluido_h

#include <iostream>

class CFluido
{
	
	protected:

    	double densidade; // Densidade do fluido
    	double viscosidade; // Viscosidade do fluido
    	double fatorVolumeFormacao; //Fator Volume formacao do fluido
        double compressibilidade; // Compressibilidade do fluido

	public:
	
		CFluido(){}; // Construtor
		virtual ~CFluido(){}; // Destrutor
		
		double Densidade() const {return densidade;} // Metodo get para a densidade do fluido
		void Densidade (double _densidade) {densidade = _densidade;} // Metodo set para a densidade do fluido
		
		double Viscosidade() const {return viscosidade;} // Metodo get para a viscosidade do fluido
		void Viscosidade (double _viscosidade) {viscosidade = _viscosidade;} // Metodo set para a viscosidade do fluido
		
		double FatorVolumeFormacao() const {return fatorVolumeFormacao;} // Metodo get para o fator volume-formacao do oleo
		void FatorVolumeFormacao (double _fatorVolumeFormacao) {fatorVolumeFormacao = _fatorVolumeFormacao;} // Metodo set para o fator volume-formacao do oleo

        double getCompressibilidade() {return compressibilidade; } // Metodo get para a compressibilidade do oleo
        void setCompressibilidade(double _compressibilidade) { compressibilidade = _compressibilidade; } // Metodo set para a compressibilidade do oleo
		
};

#endif