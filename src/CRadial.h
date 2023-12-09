#ifndef CRadial_h
#define CRadial_h

#include <iostream>
#include <cmath>
#include <fstream>

#include "CGeometria.h"

class CRadial: public CGeometria {

	protected:

		double raioExterno; // Raio da rocha reservatorio
		
	public:
		
		CRadial() {}; // Construtor default
		~CRadial() {}; // Destrutor

		double RaioExterno() const {return raioExterno;} // Metodo get para o raio do reservatorio
		void RaioExterno (double _raioExterno) {raioExterno = _raioExterno;} // Metodo set para o raio do reservatorio
		
		virtual void Area() override;
				
};

#endif