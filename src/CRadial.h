#ifndef CRadial_h
#define CRadial_h

#include <iostream>
#include <cmath>
#include <fstream>

#include "CGeometria.h"

class CRadial: public CGeometria {

	protected:

		double raioExterno; // Raio da rocha reservatório
		
	public:
		
		CRadial() {}; // Construtor default
		~CRadial() {}; // Destrutor

		double RaioExterno() const {return raioExterno;} // Método get para o raio do reservatório
		void RaioExterno (double _raioExterno) {raioExterno = _raioExterno;} // Método set para o raio do reservatório
		
		virtual void Area() override;
				
};

#endif