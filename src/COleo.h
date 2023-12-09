#ifndef COleo_h
#define COleo_h

#include "CFluido.h"

#include <iostream>

//Declaracao de COleo que herda de CFluido

class COleo : public CFluido {
	
		
	public:

		COleo(){}; // Construtor
		virtual ~COleo() = default; // Destrutor
		
};

#endif