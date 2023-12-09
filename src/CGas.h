#ifndef CGas_h
#define CGas_h

#include "CFluido.h"

#include <iostream>

//Declaracao de CGas que herda de CFluido

class CGas : public CFluido {
	
	protected:
			
		double fatorZ; // Constante dos gases
		
	public:
		
		CGas(){}; // Construtor
		~CGas(){}; // Destrutor
				
		double FatorZ() const {return fatorZ;} // Metodo get para a constante dos gases
		void FatorZ (double _fatorZ) {fatorZ = _fatorZ;} // Metodo set para a constante dos gases
		
};

#endif