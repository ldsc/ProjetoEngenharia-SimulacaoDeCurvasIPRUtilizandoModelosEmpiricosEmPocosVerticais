#ifndef CGeometria_h
#define CGeometria_h

#include <iostream>

//Classe CGeometria que representa a geometria da rocha reservatorio 

class CGeometria{
	
	protected:
		
		double area;
	
	public:
		
		CGeometria(){};
		virtual ~CGeometria() = default; //Destrutor
		
		virtual void Area() {}
		
		double getArea () {return area;} // Puxar area da geometria em questão
	
};

#endif