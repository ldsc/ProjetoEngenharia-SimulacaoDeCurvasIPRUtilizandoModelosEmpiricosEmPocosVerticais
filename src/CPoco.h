#ifndef CPoco_h
#define CPoco_h

#include <iostream>

class CPoco{
	
	protected:
		
		double raioPoco; // Raio do poço
		double pwf; // Pressão de fundo
        double area; // Área do poço
        double vazaoProducao; // Vazão de produção
		
	public:
	
		CPoco(){}; // Construtor
		~CPoco(){}; // Destrutor
	
		void CalcArea(); // Método de cálculo da área
        double getArea() {return area; }

		double getRaioPoco() const {return raioPoco;} // Método get para o raio do poço
		void setRaioPoco (double _raioPoco) {raioPoco = _raioPoco;} // Método set para o raio do poço
		
		double getPressao() const {return pwf;} // Método get para a pressão de fundo
		void setPressao (double _pwf) {pwf = _pwf;} // Método set para a pressão de fundo

        double getVazaoProducao() {return vazaoProducao;} // Método get para a vazão de produção
        void setVazaoProducao(double _vazaoProducao) { vazaoProducao = _vazaoProducao;} // Método set para a vazão de produção

};
#endif