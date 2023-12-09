#ifndef CPoco_h
#define CPoco_h

#include <iostream>

class CPoco{
	
	protected:
		
		double raioPoco; // Raio do poco
		double pwf; // Pressao de fundo
        double area; // Area do poco
        double vazaoProducao; // Vazao de producao
		
	public:
	
		CPoco(){}; // Construtor
		~CPoco(){}; // Destrutor
	
		void CalcArea(); // Metodo de calculo da area
        double getArea() {return area; }

		double getRaioPoco() const {return raioPoco;} // Metodo get para o raio do poco
		void setRaioPoco (double _raioPoco) {raioPoco = _raioPoco;} // Metodo set para o raio do poco
		
		double getPressao() const {return pwf;} // Metodo get para a pressao de fundo
		void setPressao (double _pwf) {pwf = _pwf;} // Metodo set para a pressao de fundo

        double getVazaoProducao() {return vazaoProducao;} // Metodo get para a vazao de producao
        void setVazaoProducao(double _vazaoProducao) { vazaoProducao = _vazaoProducao;} // Metodo set para a vazao de producao

};
#endif