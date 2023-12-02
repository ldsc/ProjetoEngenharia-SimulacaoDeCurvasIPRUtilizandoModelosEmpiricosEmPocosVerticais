#ifndef CGeometria_h
#define CGeometria_h

#include <iostream>

//Classe CGeometria que representa a geometria da rocha reservatório 

class CGeometria{
	
	protected:
		
		double area;
	
	public:
		
		CGeometria(){};
		virtual ~CGeometria() = default; //Destrutor
		
		virtual void Area() {}
		
		double getArea () {return area;} // Puxar área da geometria em questão
	
};

#endif