#ifndef CGas_h
#define CGas_h

#include "CFluido.h"

#include <iostream>

//Declaração de CGas que herda de CFluido

class CGas : public CFluido {
	
	protected:
			
		double fatorZ; // Constante dos gases
		
	public:
		
		CGas(){}; // Construtor
		~CGas(){}; // Destrutor
				
		double FatorZ() const {return fatorZ;} // Método get para a constante dos gases
		void FatorZ (double _fatorZ) {fatorZ = _fatorZ;} // Método set para a constante dos gases
		
};

#endif