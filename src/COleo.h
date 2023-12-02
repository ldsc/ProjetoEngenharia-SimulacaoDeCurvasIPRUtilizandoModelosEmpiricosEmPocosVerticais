#ifndef COleo_h
#define COleo_h

#include "CFluido.h"

#include <iostream>

//Declaração de COleo que herda de CFluido

class COleo : public CFluido {
	
		
	public:

		COleo(){}; // Construtor
		virtual ~COleo() = default; // Destrutor
		
};

#endif