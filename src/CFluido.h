#ifndef CFluido_h
#define CFluido_h

#include <iostream>

class CFluido
{
	
	protected:

    	double densidade; // Densidade do fluido
    	double viscosidade; // Viscosidade do fluido
    	double fatorVolumeFormacao; //Fator Volume-formação do fluido
        double compressibilidade; // Compressibilidade do fluido

	public:
	
		CFluido(){}; // Construtor
		virtual ~CFluido(){}; // Destrutor
		
		double Densidade() const {return densidade;} // Método get para a densidade do fluido
		void Densidade (double _densidade) {densidade = _densidade;} // Método set para a densidade do fluido
		
		double Viscosidade() const {return viscosidade;} // Método get para a viscosidade do fluido
		void Viscosidade (double _viscosidade) {viscosidade = _viscosidade;} // Método set para a viscosidade do fluido
		
		double FatorVolumeFormacao() const {return fatorVolumeFormacao;} // Método get para o fator volume-formação do óleo
		void FatorVolumeFormacao (double _fatorVolumeFormacao) {fatorVolumeFormacao = _fatorVolumeFormacao;} // Método set para o fator volume-formação do óleo

        double getCompressibilidade() {return compressibilidade; } // Método get para a compressibilidade do óleo
        void setCompressibilidade(double _compressibilidade) { compressibilidade = _compressibilidade; } // Método set para a compressibilidade do óleo
		
};

#endif