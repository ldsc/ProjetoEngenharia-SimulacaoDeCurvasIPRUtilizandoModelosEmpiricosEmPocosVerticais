#ifndef CLinear_h
#define CLinear_h

#include <iostream>
#include <fstream>

#include "CGeometria.h"

class CLinear: public CGeometria {

	protected:

	double length; // Comprimento da rocha reservatório
	double width; // Largura da rocha reservatório
	
	public:
		
		CLinear(); // Construtor default
		~CLinear() {}; // Destrutor

		double Length() {return length;} // Método get para o comprimento do reservatório
		void Length (double _length) {length = _length;} // Método set para o comprimento do reservatório
		
		double Width() const {return width;} // Método get para a largura do reservatório
		void Width (double _width) {width = _width;} // Método set para a largura do reservatório
				
		virtual void Area() override;
	
};

#endif