#ifndef CLinear_h
#define CLinear_h

#include <iostream>
#include <fstream>

#include "CGeometria.h"

class CLinear: public CGeometria {

	protected:

	double length; // Comprimento da rocha reservatorio
	double width; // Largura da rocha reservatorio
	
	public:
		
		CLinear(); // Construtor default
		~CLinear() {}; // Destrutor

		double Length() {return length;} // Metodo get para o comprimento do reservatorio
		void Length (double _length) {length = _length;} // Metodo set para o comprimento do reservatorio
		
		double Width() const {return width;} // Metodo get para a largura do reservatorio
		void Width (double _width) {width = _width;} // Metodo set para a largura do reservatorio
				
		virtual void Area() override;
	
};

#endif