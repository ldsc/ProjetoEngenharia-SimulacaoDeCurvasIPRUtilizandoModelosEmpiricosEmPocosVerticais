#include "CSimuladorCurvasIPR.h"

#include <iostream>

using namespace std;

// Sobrecarga de operador >> para o metodos

istream &operator>>(istream &is, CMetodo &metodo) {
   
   unsigned int a;
   is >> a;
   metodo = static_cast<CMetodo>(a);

   return is;

}

// Sobrecarga de operador >> para o tipo de fluido

istream &operator>>(istream &is, CTipoFluido &fluido) {
	
   unsigned int a;
   is >> a;
   fluido = static_cast<CTipoFluido>(a);

   return is;
   
}

// Sobrecarga de operador >> para geometria do reservatorio
istream &operator>>(istream &is, CTipoGeometria &geometria) {
	
   unsigned int a;
   is >> a;
   geometria = static_cast<CTipoGeometria>(a);

   return is;

}

CSimuladorCurvasIPR::~CSimuladorCurvasIPR() {

    delete forma;
    forma = nullptr;

}

void CSimuladorCurvasIPR::EntradaDados() {

    cout << endl;
    cout << "--------------- SIMULADOR DE CURVAS IPR PARA POCOS VERTICAIS ---------------" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "------------ Atila Junior, Giovanna Massardi e Marcelo Bernardo ------------" << endl;
    cout << "-------------------------------- UENF/LENEP --------------------------------" << endl;
    cout << endl;

    cout << "Aperte Enter para prosseguir..." << endl;

    cin.get();


    cout << "Qual o metodo sera utilizado?" << endl;
    cout << "1 - IPR Linear" << endl;
    cout << "2 - IPR Generalizada" << endl;
    cout << "3 - IPR de Fetkovich (Ideal para reservatorios de gas)" << endl;
    cout << "4 - IPR de Vogel" << endl;
    cout << "----------------------------------------------------------------------------" << endl;

    cin >> metodo; // Recebe o tipo de metodo que o usuario entrar
    
    cout << "Qual a geometria do reservatorio?" << std::endl;
	cout << "1 - Linear" << endl;
	cout << "2 - Radial" << endl;
	cout << "----------------------------------------------------------------------------" << endl;


	CTipoGeometria geometria;

    cin >> geometria;
    cin.get();
    
	// Switch para o tipo de metodo de calculo
    switch (metodo) {
    	
        case CMetodo::IPR_LINEAR:
        
		{
        	
		    switch (geometria) {
		    	
				case CTipoGeometria::linear:
				
				{

            	cin.get();

            	forma = new CLinear;
            	CLinear* cast = dynamic_cast<CLinear*>(forma);

            	reservatorio.CoeficienteDietz(geometria);

            	cout << "Entre com o comprimento do reservatorio (FT)" << endl;

            	double esp;

            	cin >> esp;

            	cout << "Entre com a largura do reservatorio (FT)" << endl;

            	double lar;

            	cin >> lar;

            	cast-> Length(esp);
	            cast-> Width(lar);
	            cast-> Area();

	            cout << "Entre com o raio do poco (FT):" << endl;
	
	            double raio;
	
	            cin >> raio;
	
	            poco.setRaioPoco(raio);
	
	            cout << "Entre com a pressao inicial do reservatorio (PSIA): " << endl;
	
	            double pi;
	
	            cin >> pi;
	
	            reservatorio.PressaoInicial(pi);
	
	            cout << "Entre com a pressao de bolha do reservatorio (PSIA): " << endl;
	
	            double pb;
	
	            cin >> pb;
	
	            reservatorio.PressaoBolha(pb);
	
	            poco.CalcArea();
	
	            cout << "Qual tipo de fluido presente no reservatorio?" << std::endl;
	            cout << "1 - Oleo" << endl;
	            cout << "2 - Gas" << endl;
	            cout << "----------------------------------------------------------------------------" << endl;
	
	            CTipoFluido tipoFluido;
	
	            cin >> tipoFluido;
	            cin.get();
	
	            bool chs = true;
	
	            while(chs) 
	            
				{
	                
					switch (tipoFluido) // Switch para definicao do tipo de fluido
	                
					{
	                    
						case CTipoFluido::oleo: // Caso oleo, cria um novo objeto da classe COleo
	                        
							{
	
	                        fluido = new COleo;
	                        cout << "Entre com fator volume de formacao do oleo: " << endl;
	                        double Bo;
	                        cin >> Bo;
	                        fluido->FatorVolumeFormacao(Bo);
	                        cout << "Entre com a viscosidade do fluido (CP):" << endl;
	                        double viscosidade;
	                        cin >> viscosidade;
	                        fluido->Viscosidade(viscosidade);
	
	                        chs = false;
	                        break;
	                        
							}
	                    
						case CTipoFluido::gas: // Caso gas, cria um novo objeto da classe CGas
	                        
							{
	
	                        fluido = new CGas;
	                        cout << "Entre com fator volume de formacao do gas:" << endl;
	                        double Bg;
	                        cin >> Bg;
	                        fluido->FatorVolumeFormacao(Bg);
	                        cout << "Entre com a viscosidade do fluido (CP):" << endl;
	                        double viscosidade;
	                        cin >> viscosidade;
	                        fluido->Viscosidade(viscosidade);
	
	                        chs = false;
	                        break;
	                        
							}
	                    
						default:
	                        cout << "Entrada invalida!" << endl;
	                        cout << "Qual tipo de fluido presente no reservatorio? " << endl;
	                        cin >> tipoFluido;
	                        cin.get();
	                
					}
	
	            }
	            
	            cout << "Entre com a espessura do reservatorio (FT):" << endl;
	
	            double espreservatorio;
	
	            cin >> espreservatorio;
	
	            reservatorio.Espessura(espreservatorio);
	
	            cout << "Entre com a permeabilidade da rocha reservatorio (MD):" << endl;
	
	            double perm;
	
	            cin >> perm;
	
	            reservatorio.Permeabilidade(perm);
	
	            cout << "Entre com fator de pelicula do reservatorio:" << endl;
	
	            double s;
	
	            cin >> s;
	
	            reservatorio.FatorPelicula(s);
	
	            reservatorio.IndiceProdutividade(fluido, forma, poco);
	
	            cout << "IP = " << reservatorio.getIndiceProdutividade() << endl << endl;
	            
	            IPR = new CIPRLinear();
	
	            break;
        
				}
			
				case CTipoGeometria::radial:
					
					{
					
		            cin.get();
		
		           	forma = new CRadial;
		           	CRadial* cast = dynamic_cast<CRadial*>(forma);
		
		           	reservatorio.CoeficienteDietz(geometria);
		
		           	cout << "Entre com o raio externo do reservatorio (FT)" << endl;
		           	
			        double Re;
			
			        cin >> Re;
			
		            cast->RaioExterno(Re);
			        cast->Area();
		
			        cout << "Entre com o raio do poco (FT):" << endl;
			
			        double raio;
			
			        cin >> raio;
			
			        poco.setRaioPoco(raio);
			
			        cout << "Entre com a pressao inicial do reservatorio (PSIA): " << endl;
			
			        double pi;
			
			        cin >> pi;
			
			        reservatorio.PressaoInicial(pi);
			
			        cout << "Entre com a pressao de bolha do reservatorio (PSIA): " << endl;
			
			        double pb;
			
			        cin >> pb;
			
			        reservatorio.PressaoBolha(pb);
			
			        poco.CalcArea();
			
			        cout << "Qual tipo de fluido presente no reservatorio?" << std::endl;
			        cout << "1 - Oleo" << endl;
			        cout << "2 - Gas" << endl;
			        cout << "----------------------------------------------------------------------------" << endl;
			
			        CTipoFluido tipoFluido;
			
			        cin >> tipoFluido;
			        cin.get();
			
			        bool chs = true;
			
			        while(chs) 
			            
					{
			                
						switch (tipoFluido) // Switch para definicao do tipo de fluido
			                
						{
			                    
							case CTipoFluido::oleo: // Caso oleo, cria um novo objeto da classe COleo
			                        
								{
			
			                    fluido = new COleo;
			                    cout << "Entre com fator volume de formacao do oleo: " << endl;
			                    double Bo;
			                    cin >> Bo;
			                    fluido->FatorVolumeFormacao(Bo);
			                    cout << "Entre com a viscosidade do fluido (CP):" << endl;
			                    double viscosidade;
			                    cin >> viscosidade;
			                    fluido->Viscosidade(viscosidade);
			
			                    chs = false;
			                    break;
			                        
									}
			                    
								case CTipoFluido::gas: // Caso gas, cria um novo objeto da classe CGas
			                        
									{
			
			                        fluido = new CGas;
			                        cout << "Entre com fator volume de formacao do gas:" << endl;
			                        double Bg;
			                        cin >> Bg;
			                        fluido->FatorVolumeFormacao(Bg);
			                        cout << "Entre com a viscosidade do fluido (CP):" << endl;
			                        double viscosidade;
			                        cin >> viscosidade;
			                        fluido->Viscosidade(viscosidade);
			
			                        chs = false;
			                        break;
			                        
									}
			                    
								default:
			                        cout << "Entrada invalida!" << endl;
			                        cout << "Qual tipo de fluido presente no reservatorio? " << endl;
			                        cin >> tipoFluido;
			                        cin.get();
			                
							}
			
			            }
			            
			    }
		            
		            cout << "Entre com a espessura do reservatorio (FT):" << endl;
		
		            double espreservatorio;
		
		            cin >> espreservatorio;
		
		            reservatorio.Espessura(espreservatorio);
		
		            cout << "Entre com a permeabilidade da rocha reservatorio (MD):" << endl;
		
		            double perm;
		
		            cin >> perm;
		
		            reservatorio.Permeabilidade(perm);
		
		            cout << "Entre com fator de pelicula do reservatorio:" << endl;
		
		            double s;
		
		            cin >> s;
		
		            reservatorio.FatorPelicula(s);
		
		            reservatorio.IndiceProdutividade(fluido, forma, poco);
		
		            cout << "IP = " << reservatorio.getIndiceProdutividade() << endl << endl;
		            
		            IPR = new CIPRLinear();
		
		            break;
	        
				}
		
		}
        
		case CMetodo::IPR_GENERALIZADA:
        
		{
			
			switch (geometria) 
			
			{
				
				case CTipoGeometria::linear: // Caso geometria linear cria objeto do tipo CLinear
	            
				{
				
					cin.get();
		
		            forma = new CLinear;
		            CLinear* cast = dynamic_cast<CLinear*>(forma);
		
		            reservatorio.CoeficienteDietz(geometria);
		
		            cout << "Entre com o comprimento do reservatorio (FT)" << endl;
	
	            	double esp;
	
	            	cin >> esp;
	
	            	cout << "Entre com a largura do reservatorio (FT)" << endl;
	
	            	double lar;
	
	            	cin >> lar;
	
	            	cast-> Length(esp);
		            cast-> Width(lar);
		            cast-> Area();
		
		            cout << "Entre com a raio do poco (FT)" << endl;
		
		            double raio;
		
		            cin >> raio;
		
		            poco.setRaioPoco(raio);
		
		            cout << "Entre com a pressao inicial (PSIA):" << endl;
		
		            double pi;
		
		            cin >> pi;
		
		            reservatorio.PressaoInicial(pi);
		
		            cout << "Entre com a pressao de bolha (PSIA): " << endl;
		
		            double pb;
		
		            cin >> pb;
		
		            reservatorio.PressaoBolha(pb);
		
		            poco.CalcArea();
		
		            cout << "Qual tipo de fluido presente no reservatorio?" << endl;
		            cout << "1 - Oleo" << endl;
		            cout << "2 - Gas" << endl;
		            cout << "----------------------------------------------------------------------------" << endl;
		
		            CTipoFluido tipoFluido;
		
		            cin >> tipoFluido;
		            cin.get();
		
		            bool chs = true;
		
		            while(chs)
		            
					{
		                
						switch (tipoFluido)
		                
						{
		                    
							case CTipoFluido::oleo:
		                        
								{
		
		                        fluido = new COleo;
		                        cout << "Entre com fator volume de formacao do oleo:" << endl;
		                        double Bo;
		                        cin >> Bo;
		                        fluido->FatorVolumeFormacao(Bo);
		                        cout << "Entre com a viscosidade do fluido (CP):" << endl;
		                        double viscosidade;
		                        cin >> viscosidade;
		                        fluido->Viscosidade(viscosidade);
		
		                        chs = false;
		                        break;
		                        
								}
		                    
							case CTipoFluido::gas:
		                        
								{
		
		                        fluido = new CGas;
		                        cout << "Entre com fator volume de formacao do gas:" << endl;
		                        double Bg;
		                        cin >> Bg;
		                        fluido->FatorVolumeFormacao(Bg);
		                        cout << "Entre com a viscosidade do fluido (CP):" << endl;
		                        double viscosidade;
		                        cin >> viscosidade;
		                        fluido->Viscosidade(viscosidade);
		
		                        chs = false;
		                        break;
		                        
								}
		                    
							default:
		                        cout << "Entrada invalida!" << endl;
		                        cout << "Qual tipo de fluido presente no reservatorio?" << endl;
		                        cin >> tipoFluido;
		                        cin.get();
		                
						}
		
		            }
		            
		            cout << "Entre com a espessura do reservatorio (FT):" << endl;
		
		            double espreservatorio;
		
		            cin >> espreservatorio;
		
		            reservatorio.Espessura(espreservatorio);
		
		            cout << "Entre com a permeabilidade da rocha (MD):" << endl;
		
		            double perm;
		
		            cin >> perm;
		
		            reservatorio.Permeabilidade(perm);
		
		            cout << "Entre com fator de pelicula do reservatorio:" << endl;
		
		            double s;
		
		            cin >> s;
		
		            reservatorio.FatorPelicula(s);
		
		            reservatorio.IndiceProdutividade(fluido, forma, poco);
		            
		            IPR = new CIPRGeneralizada();  
		            
		            break;
				
				}
            
				case CTipoGeometria::radial: // Caso geometria radial cria objeto do tipo CRadial
				
				{
					
					cin.get();
		
		            forma = new CRadial;
		            CRadial* cast = dynamic_cast<CRadial*>(forma);
		
		            reservatorio.CoeficienteDietz(geometria);
		
		            cout << "Entre com o raio externo do reservatorio (FT)" << endl;
		
		            double Re;
		
		            cin >> Re;
		
		            cast->RaioExterno(Re);
		            cast->Area();
		
		            cout << "Entre com a raio do poco (FT)" << endl;
		
		            double raio;
		
		            cin >> raio;
		
		            poco.setRaioPoco(raio);
		
		            cout << "Entre com a pressao inicial (PSIA):" << endl;
		
		            double pi;
		
		            cin >> pi;
		
		            reservatorio.PressaoInicial(pi);
		
		            cout << "Entre com a pressao de bolha (PSIA): " << endl;
		
		            double pb;
		
		            cin >> pb;
		
		            reservatorio.PressaoBolha(pb);
		
		            poco.CalcArea();
		
		            cout << "Qual tipo de fluido presente no reservatorio?" << endl;
		            cout << "1 - Oleo" << endl;
		            cout << "2 - Gas" << endl;
		            cout << "----------------------------------------------------------------------------" << endl;
		
		            CTipoFluido tipoFluido;
		
		            cin >> tipoFluido;
		            cin.get();
		
		            bool chs = true;
		
		            while(chs)
		            
					{
		                
						switch (tipoFluido)
		                
						{
		                    
							case CTipoFluido::oleo:
		                        
								{
		
		                        fluido = new COleo;
		                        cout << "Entre com fator volume de formacao do oleo:" << endl;
		                        double Bo;
		                        cin >> Bo;
		                        fluido->FatorVolumeFormacao(Bo);
		                        cout << "Entre com a viscosidade do fluido (CP):" << endl;
		                        double viscosidade;
		                        cin >> viscosidade;
		                        fluido->Viscosidade(viscosidade);
		
		                        chs = false;
		                        break;
		                        
								}
		                    
							case CTipoFluido::gas:
		                        
								{
		
		                        fluido = new CGas;
		                        cout << "Entre com fator volume de formacao do gas:" << endl;
		                        double Bg;
		                        cin >> Bg;
		                        fluido->FatorVolumeFormacao(Bg);
		                        cout << "Entre com a viscosidade do fluido (CP):" << endl;
		                        double viscosidade;
		                        cin >> viscosidade;
		                        fluido->Viscosidade(viscosidade);
		
		                        chs = false;
		                        break;
		                        
								}
		                    
							default:
		                        cout << "Entrada invalida!" << endl;
		                        cout << "Qual tipo de fluido presente no reservatorio?" << endl;
		                        cin >> tipoFluido;
		                        cin.get();
		                
						}
	
	            	}
	            
		            cout << "Entre com a espessura do reservatorio (FT):" << endl;
		
		            double espreservatorio;
		
		            cin >> espreservatorio;
		
		            reservatorio.Espessura(espreservatorio);
		
		            cout << "Entre com a permeabilidade da rocha (MD):" << endl;
		
		            double perm;
		
		            cin >> perm;
		
		            reservatorio.Permeabilidade(perm);
		
		            cout << "Entre com fator de pelicula do reservatorio:" << endl;
		
		            double s;
		
		            cin >> s;
		
		            reservatorio.FatorPelicula(s);
		
		            reservatorio.IndiceProdutividade(fluido, forma, poco);
		            
		            IPR = new CIPRGeneralizada();  
		            
		            break;
	        
					}
					
		}
		
	}
        
		case CMetodo::IPR_FETKOVICH:
        
		{
		    
			switch(geometria)
			
			{
            	
            	case CTipoGeometria::linear:
            		
            	{	
            		
			        cin.get();
			
			        forma = new CLinear;
			        CLinear* cast = dynamic_cast<CLinear*>(forma);
			
			        reservatorio.CoeficienteDietz(geometria);
			
			        cout << "Entre com o comprimento do reservatorio (FT)" << endl;
	
		            double esp;
		
		            cin >> esp;
		
		            cout << "Entre com a largura do reservatorio (FT)" << endl;
		
		            double lar;
		
		            cin >> lar;
		
		            cast-> Length(esp);
			        cast-> Width(lar);
			        cast-> Area();
			
			        cout << "Entre com a raio do poco ." << endl;
			
			        double raio;
			
			        cin >> raio;
			
			        poco.setRaioPoco(raio);
			
			        cout << "Entre com a pressao media do reservatorio (PSIA): " << endl;
			
			        double pi;
			
			        cin >> pi;
			
			        reservatorio.PressaoInicial(pi);
			
			        cout << "Entre com a pressao de bolha (PSIA): " << endl;
			
			        double pb;
			
			        cin >> pb;
			
			        reservatorio.PressaoBolha(pb);
			
			
			        cout << "Entre com a pressao de fundo no poco A (PSIA):" << endl;
			
			        double pwf1;
			
			        cin >> pwf1;
			
			        poco.setPressao(pwf1);
			
			        cout << "Entre com a vazao no poco A (STB/d):" << endl;
			
			        double q1;
			
			        cin >> q1;
			
			        poco.setVazaoProducao(q1);
			
			        cout << "Entre com a pressao de fundo no poco B (PSIA):" << endl;
			
			        double pwf2;
			
			        cin >> pwf2;
			
			        pocoDois.setPressao(pwf2);
			
			        cout << "Entre com a vazao no poco B (STB/d):" << endl;
			
			        double q2;
			
			        cin >> q2;
			
			        pocoDois.setVazaoProducao(q2);
			
			        poco.CalcArea();
			
			        cout << "Qual tipo de fluido presente no reservatorio?" << endl;
			        cout << "1 - Oleo" << endl;
			        cout << "2 - Gas" << endl;
			        cout << "----------------------------------------------------------------------------" << endl;
			
			        CTipoFluido tipoFluido;
			
			        cin >> tipoFluido;
			        cin.get();
			
			        bool chs = true;
			
			        while(chs)
			            
					{
			                
						switch (tipoFluido)
			                
						{
			                case CTipoFluido::oleo:
			                        
								{
			
			                    fluido = new COleo;
			                    cout << "Entre com fator volume de formacao do oleo:" << endl;
			                    double Bo;
			                    cin >> Bo;
			                    fluido->FatorVolumeFormacao(Bo);
			                    cout << "Entre com a viscosidade do fluido (CP):" << endl;
			                    double viscosidade;
			                    cin >> viscosidade;
			                    fluido->Viscosidade(viscosidade);
	
		                        chs = false;
		                        break;
			                        
								}
			                    
							case CTipoFluido::gas:
			                        
								{
			
		                        fluido = new CGas;
		                        cout << "Entre com fator volume de formacao do gas:" << endl;
			                    double Bg;
			                    cin >> Bg;
			                    fluido->FatorVolumeFormacao(Bg);
		                        cout << "Entre com a viscosidade do fluido (CP):" << endl;
		                        double viscosidade;
		                        cin >> viscosidade;
		                        fluido->Viscosidade(viscosidade);
			
		                        chs = false;
		                        break;
			                        
								}
			                    
							default:
			                    cout << "Entrada invalida!" << endl;
			                    cout << "Qual tipo de fluido presente no reservatorio?" << endl;
			                    cin >> tipoFluido;
			                    cin.get();
		                
			            }
			
			            double espreservatorio;
			
			            cin >> espreservatorio;
			
			            reservatorio.Espessura(espreservatorio);
			
			            cout << "Entre com a permeabilidade da rocha reservatorio (MD):" << endl;
			
			            double perm;
			
			            cin >> perm;
			
			            reservatorio.Permeabilidade(perm);
			
			            cout << "Entre com fator de pelicula do reservatorio:" << endl;
			
			            double s;
			
			            cin >> s;
			
			            reservatorio.FatorPelicula(s);
			
			            reservatorio.IndiceProdutividade(fluido, forma, poco);
			            
			            IPR = new CIPRFetkovich();  
			            
			            break;
			            
			    	}
			}
	           	
				case CTipoGeometria::radial:
					
				{
					
			        cin.get();
			
			        forma = new CRadial;
			        CRadial* cast = dynamic_cast<CRadial*>(forma);
			
			        reservatorio.CoeficienteDietz(geometria);
			
			        cout << "Entre com o raio externo do reservatorio (FT)" << endl;
			
			        double Re;
			
			        cin >> Re;
			
			        cast->RaioExterno(Re);
			        cast->Area();
			
			        cout << "Entre com a raio do poco ." << endl;
			
			        double raio;
			
			        cin >> raio;
			
			        poco.setRaioPoco(raio);
			
			        cout << "Entre com a pressao media do reservatorio (PSIA): " << endl;
			
			        double pi;
			
			        cin >> pi;
			
			        reservatorio.PressaoInicial(pi);
			
			        cout << "Entre com a pressao de bolha (PSIA): " << endl;
			
			        double pb;
			
			        cin >> pb;
			
			        reservatorio.PressaoBolha(pb);
			
			
			        cout << "Entre com a pressao de fundo no poco A (PSIA):" << endl;
			
			        double pwf1;
			
			        cin >> pwf1;
			
			        poco.setPressao(pwf1);
			
			        cout << "Entre com a vazao no poco A (STB/d):" << endl;
			
			        double q1;
			
			        cin >> q1;
			
			        poco.setVazaoProducao(q1);
			
			        cout << "Entre com a pressao de fundo no poco B (PSIA):" << endl;
			
			        double pwf2;
			
			        cin >> pwf2;
			
			        pocoDois.setPressao(pwf2);
			
			        cout << "Entre com a vazao no poco B (STB/d):" << endl;
			
			        double q2;
		
		            cin >> q2;
			
		            pocoDois.setVazaoProducao(q2);
			
		            poco.CalcArea();
			
		            cout << "Qual tipo de fluido presente no reservatorio?" << endl;
		            cout << "1 - Oleo" << endl;
		            cout << "2 - Gas" << endl;
		            cout << "----------------------------------------------------------------------------" << endl;
			
		            CTipoFluido tipoFluido;
			
		            cin >> tipoFluido;
		            cin.get();
			
		            bool chs = true;
			
		            while(chs)
			            
					{
			                
						switch (tipoFluido)
			                
						{
			                case CTipoFluido::oleo:
			                        
								{
			
			                    fluido = new COleo;
			                    cout << "Entre com fator volume de formacao do oleo:" << endl;
			                    double Bo;
			                    cin >> Bo;
			                    fluido->FatorVolumeFormacao(Bo);
			                    cout << "Entre com a viscosidade do fluido (CP):" << endl;
			                    double viscosidade;
			                    cin >> viscosidade;
			                    fluido->Viscosidade(viscosidade);
			
			                    chs = false;
			                    break;
			                        
								}
			                    
							case CTipoFluido::gas:
			                        
								{
			
			                    fluido = new CGas;
			                    cout << "Entre com fator volume de formacao do gas:" << endl;
			                    double Bg;
			                    cin >> Bg;
			                    fluido->FatorVolumeFormacao(Bg);
			                    cout << "Entre com a viscosidade do fluido (CP):" << endl;
			                    double viscosidade;
			                    cin >> viscosidade;
			                    fluido->Viscosidade(viscosidade);
			
			                    chs = false;
			                    break;
			                        
								}
			                    
							default:
			                    cout << "Entrada invalida!" << endl;
			                    cout << "Qual tipo de fluido presente no reservatorio?" << endl;
			                    cin >> tipoFluido;
			                    cin.get();
		                
			            }
			
			            double espreservatorio;
			
			            cin >> espreservatorio;
			
			            reservatorio.Espessura(espreservatorio);
			
			            cout << "Entre com a permeabilidade da rocha reservatorio (MD):" << endl;
			
			            double perm;
			
			            cin >> perm;
			
			            reservatorio.Permeabilidade(perm);
			
			            cout << "Entre com fator de pelicula do reservatorio:" << endl;
			
			            double s;
			
			            cin >> s;
			
			            reservatorio.FatorPelicula(s);
			
			            reservatorio.IndiceProdutividade(fluido, forma, poco);
			            
			            IPR = new CIPRFetkovich();  
			            
			            break;
			            
			    	}
			    
				}
	        
			}
        
		case CMetodo::IPR_VOGEL: {
            
			switch (geometria) 
			
			{
            
				case CTipoGeometria::linear:
				
				{
				
		            cin.get();
		
		            forma = new CLinear;
		            CLinear* cast = dynamic_cast<CLinear*>(forma);
		
		            reservatorio.CoeficienteDietz(geometria);
		
		            cout << "Entre com o comprimento do reservatorio (FT)" << endl;
		
			        double esp;
			
			        cin >> esp;
			
			        cout << "Entre com a largura do reservatorio (FT)" << endl;
			
		            double lar;
			
			        cin >> lar;
			
			        cast-> Length(esp);
				    cast-> Width(lar);
			        cast-> Area();
		
			        cout << "Entre com a raio do poco (FT):" << endl;
		
		   	        double raio;
		
		            cin >> raio;
		
		            poco.setRaioPoco(raio);
		
		            cout << "Entre com a pressao inicial do reservatorio (PSIA):" << endl;
		
		            double pi;
		
		            cin >> pi;
		
		            reservatorio.PressaoInicial(pi);
		
		            cout << "Entre com a pressao de bolha (PSIA): " << endl;
		
		            double pb;
		
		            cin >> pb;
		
		            reservatorio.PressaoBolha(pb);
		
		            poco.CalcArea();
		
		            cout << "Qual tipo de fluido presente no reservatorio?" << endl;
		            cout << "1 - Oleo" << endl;
		            cout << "2 - Gas" << endl;
		            cout << "----------------------------------------------------------------------------" << endl;
		
		            CTipoFluido tipoFluido;
		
		            cin >> tipoFluido;
		            cin.get();
		
		            bool chs = true;
		
		            while(chs)
		            
					{
		                
						switch (tipoFluido)
		                
						{
		                    
							case CTipoFluido::oleo:
		                        
								{
		
		                        fluido = new COleo;
		                        cout << "Entre com fator volume de formacao do oleo:" << endl;
		                        double Bo;
		                        cin >> Bo;
		                        fluido->FatorVolumeFormacao(Bo);
		                        cout << "Entre com a viscosidade do fluido (CP):" << endl;
		                        double viscosidade;
		                        cin >> viscosidade;
		                        fluido->Viscosidade(viscosidade);
		
		                        chs = false;
		                        break;
		                        
								}
		                    
							case CTipoFluido::gas:
		                        
								{
		
		                        fluido = new CGas;
		                        cout << "Entre com fator volume de formacao do gas:" << endl;
		                        double Bg;
		                        cin >> Bg;
		                        fluido->FatorVolumeFormacao(Bg);
		                        cout << "Entre com a viscosidade do fluido (CP):" << endl;
		                        double viscosidade;
		                        cin >> viscosidade;
		                        fluido->Viscosidade(viscosidade);
		
		                        chs = false;
		                        break;
		                        
								}
		                    
								default:
		                        cout << "Entrada invalida!" << endl;
		                        cout << "Qual tipo de fluido presente no reservatorio? " << endl;
		                        cin >> tipoFluido;
		                        cin.get();
		                
						}
		
		            }
		            
		            cout << "Entre com a espessura do reservatorio (FT):" << endl;
		
		            double espreservatorio;
		
		            cin >> espreservatorio;
		
		            reservatorio.Espessura(espreservatorio);
		
		            cout << "Entre com a permeabilidade da rocha (MD):" << endl;
		
		            double perm;
		
		            cin >> perm;
		
		            reservatorio.Permeabilidade(perm);
		
		            cout << "Entre com fator de pelicula do reservatorio:" << endl;
		
		            double s;
		
		            cin >> s;
		
		            reservatorio.FatorPelicula(s);
		
		            reservatorio.IndiceProdutividade(fluido, forma, poco);
		            
		            IPR = new CIPRVogel();  
		            
		            break;
		        
				}
			
				case CTipoGeometria::radial:
					
				{
					
		            cin.get();
		
		            forma = new CRadial;
		            CRadial* cast = dynamic_cast<CRadial*>(forma);
		
		            reservatorio.CoeficienteDietz(geometria);
		
		            cout << "Entre com o raio externo do reservatorio (FT)" << endl;
		
		            double Re;
		
		            cin >> Re;
		
		            cast->RaioExterno(Re);
		            cast->Area();
		
		            cout << "Entre com a raio do poco (FT):" << endl;
		
		            double raio;
		
		            cin >> raio;
		
		            poco.setRaioPoco(raio);
		
		            cout << "Entre com a pressao inicial do reservatorio (PSIA):" << endl;
		
		            double pi;
		
		            cin >> pi;
		
		            reservatorio.PressaoInicial(pi);
		
		            cout << "Entre com a pressao de bolha (PSIA): " << endl;
		
		            double pb;
		
		            cin >> pb;
		
		            reservatorio.PressaoBolha(pb);
		
		            poco.CalcArea();
		
		            cout << "Qual tipo de fluido presente no reservatorio?" << endl;
		            cout << "1 - Oleo" << endl;
		            cout << "2 - Gas" << endl;
		            cout << "----------------------------------------------------------------------------" << endl;
		
		            CTipoFluido tipoFluido;
		
		            cin >> tipoFluido;
		            cin.get();
		
		            bool chs = true;
		
		            while(chs)
		            
					{
		                
						switch (tipoFluido)
		                
						{
		                    
							case CTipoFluido::oleo:
		                        
								{
		
		                        fluido = new COleo;
		                        cout << "Entre com fator volume de formacao do oleo:" << endl;
		                        double Bo;
		                        cin >> Bo;
		                        fluido->FatorVolumeFormacao(Bo);
		                        cout << "Entre com a viscosidade do fluido (CP):" << endl;
		                        double viscosidade;
		                        cin >> viscosidade;
		                        fluido->Viscosidade(viscosidade);
		
		                        chs = false;
		                        break;
		                        
								}
		                    
							case CTipoFluido::gas:
		                        
								{
		
		                        fluido = new CGas;
		                        cout << "Entre com fator volume de formacao do gas:" << endl;
		                        double Bg;
		                        cin >> Bg;
		                        fluido->FatorVolumeFormacao(Bg);
		                        cout << "Entre com a viscosidade do fluido (CP):" << endl;
		                        double viscosidade;
		                        cin >> viscosidade;
		                        fluido->Viscosidade(viscosidade);
		
		                        chs = false;
		                        break;
		                        
								}
		                    
							default:
		                        cout << "Entrada invalida!" << endl;
		                        cout << "Qual tipo de fluido presente no reservatorio? " << endl;
		                        cin >> tipoFluido;
		                        cin.get();
		                
						}
		
		            }
		            
		            cout << "Entre com a espessura do reservatorio (FT):" << endl;
		
		            double espreservatorio;
		
		            cin >> espreservatorio;
		
		            reservatorio.Espessura(espreservatorio);
		
		            cout << "Entre com a permeabilidade da rocha (MD):" << endl;
		
		            double perm;
		
		            cin >> perm;
		
		            reservatorio.Permeabilidade(perm);
		
		            cout << "Entre com fator de pelicula do reservatorio:" << endl;
		
		            double s;
		
		            cin >> s;
		
		            reservatorio.FatorPelicula(s);
		
		            reservatorio.IndiceProdutividade(fluido, forma, poco);
		            
		            IPR = new CIPRVogel();  
		            
		            break;
		        
				}
	        
			default:
	            break;
	            
	        	}
	    	}
		}
    
    	}

	}

void CSimuladorCurvasIPR::Calculos() {

    cout << endl << endl;
    cout << "Calculando IPR..." << endl;
    cout << endl << endl;

    cout << "Deseja realizar o calculo de pressoes em quantas partes?"  << endl; // Realizara os calculos com base na quantidade de pontos solicitados ate que atinja a pressao igual a zero
    cout << "Digite um numero inteiro."  << endl;

    int partes; // Variavel que recebe a entrada do usuario

    cin >> partes;

    IPR->setPartes(partes);

    if(metodo == CMetodo::IPR_FETKOVICH)
        IPR->CalcIPR(fluido, reservatorio, poco, pocoDois); // Para Fetkovich eh necessario dois pocos para calculo das constantes
    else
        IPR->CalcIPR(fluido, reservatorio, poco);

    vazoes = IPR->getVazao();
    pressoes = IPR->getPWF();

}

// Metodo para plotar o grafico

void CSimuladorCurvasIPR::Plotar() {

    cout << "Deseja plotar o grafico?" << std::endl;
    cout << " 1 - Sim" << endl;
    cout << " 2 - Nao " << endl;
    cout << "----------------------------------------------------------------------------" << endl;

    char ans; // Variavel para receber resposta do usuario

    cin >> ans;
    cin.get();

    bool boleano = true;

    while(boleano)
    
	{

        switch(ans)
        
		{
            
			case '1':
            
			{

                plot.XLabel("Vazao (STB/d)");
                plot.YLabel("Pressao de Fundo (PSIA)");
                plot.Title("Curva IPR");
                plot.Style("lines");
                plot.plot_xy(vazoes, pressoes);
                cin.get();
                boleano = false;
                break;
            
			}
            
			case '2':
                boleano = false;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        
		}

    }

}

// Metodo para salvar o grafico
void CSimuladorCurvasIPR::SalvarGrafico() {

    plot.savetops("GraficoIPR");

}

// Metodo para executar o software
void CSimuladorCurvasIPR::Executar() {

    bool run = true;

    cout << endl;
    cout << "--------------- SIMULADOR DE CURVAS IPR PARA POCOS VERTICAIS ---------------" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "------------ Atila Junior, Giovanna Massardi e Marcelo Bernardo ------------" << endl;
    cout << "-------------------------------- UENF/LENEP --------------------------------" << endl;
    cout << endl;


    cout << " Deseja executar o programa ?" << endl;
    cout << " 1 - Sim" << endl;
    cout << " 2 - Nao " << endl;
    cout << "----------------------------------------------------------------------------" << endl;

    char ans; // Variavel para receber a resposta do usuario

    cin >> ans;
    cin.get();

// Caso usuario entre com uma opcao diferente das apresentadas retorna mensagem de erro

while (run)

{
    
	while ( ans!= '1' && ans != '2')
    
	{
        
		cout << "Opcao invalida" << endl;
        cout << " Deseja executar o programa ?" << endl;
    	cout << " 1 - Sim" << endl;
    	cout << " 2 - Nao " << endl;
    	cout << "----------------------------------------------------------------------------" << endl;

        cin >> ans;
        cin.get();

    }

    switch(ans)
    
	{
        
		case '1': // Caso resposta positiva do usuario, executa o programa
        
		{
            
			EntradaDados();
            Calculos();
            Plotar();

            cout << "Deseja salvar o grafico?" << endl;
            cout << " 1 - Sim" << endl;
    		cout << " 2 - Nao " << endl;
    		cout << "----------------------------------------------------------------------------" << endl;

            bool test = true;

            char chse; // Variavel para receber a resposta do usuario

            cin >> chse;
            cin.get();

            while(test)
            
			{
                
				switch(chse)
                
				{
                    
					case '1':
                    
					{
                        
						SalvarGrafico();
                        test = false;
                        break;
                    
					}
                    
					case '2':
                    
					{
                        
						test = false;
                        break;
                    
					}
                    
                    // Caso usuario entre com uma opcao diferente das apresentadas retorna mensagem de erro
                    
                    default:
                    
					{
                        
						cout << "Opcao Invalida!" << endl;
                        cout << "Deseja salvar o grafico?" << endl;
            			cout << " 1 - Sim" << endl;
    					cout << " 2 - Nao " << endl;
    					cout << "----------------------------------------------------------------------------" << endl;
                        cin >> chse;
                        break;
                    
					}
                
				}

            }

            cout << " Deseja executar o programa?" << endl;
            cout << " 1 - Sim" << endl;
    		cout << " 2 - Nao " << endl;
    		cout << "----------------------------------------------------------------------------" << endl;
            cin >> ans;
            cin.get();

            while ( ans!= '1' && ans != '2')
            
			{
                
				cout << "Opcao invalida" << endl;
                cout << " Deseja executar o programa ?" << endl;
                cout << " 1 - Sim" << endl;
    			cout << " 2 - Nao " << endl;
    			cout << "----------------------------------------------------------------------------" << endl;

                cin >> ans;
                cin.get();

            }
            
			break;
        
		}
        
		case '2':
            run = false;
            cout << "Obrigado por utilizar o software!" << endl;
            break;
        default:
            break;
            
        }

    }

}