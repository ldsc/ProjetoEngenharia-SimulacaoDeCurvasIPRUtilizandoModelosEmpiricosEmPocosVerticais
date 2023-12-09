#ifndef CRocha_h
#define CRocha_h

#include <iostream>

// Classe CRocha que representa as propriedades de rocha

class CRocha {
	
	protected:
		
		double compRocha; // Compressibilidade da rocha
		double porosidade; // Porosidade da rocha
		double permeabilidade; // Permeabilidade da rocha
		
		
	public:
	
		CRocha(){}; // Construtor
		~CRocha(){}; // Destrutor
	
		double CompRocha() const {return compRocha;} // Metodo get para a compressibilidade da rocha
		void CompRocha (double _compRocha) {compRocha = _compRocha;} // Metodo set para a compressibilidade da rocha
		
		double Porosidade() const {return porosidade;} // Metodo get para a porosidade da rocha
		void Porosidade (double _porosidade) {porosidade = _porosidade;} // Metodo set para a porosidade da rocha
		
		double Permeabilidade() const {return permeabilidade;} // Metodo get para a permeabilidade da rocha
		void Permeabilidade (double _permeabilidade) {permeabilidade = _permeabilidade;} // Metodo set para a permeabilidade da rocha
		
};

#endif