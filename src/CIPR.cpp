#include "CIPR.h"
#include <vector>

CIPR::CIPR()
{
}

// Declarando e definindo o método CalcIPR na classe CIPR	
void CIPR::CalcIPR(CFluido* fluido, CReservatorio& reservatorio, CPoco& poco, CPoco& parametrosSegundoPoco) {
    
}

void CIPR::CalcIPR(CFluido *fluido, CReservatorio &reservatorio, CPoco &poco)
{
}

void CIPR::iprVariacaoPwf(double _pwf) // Função responsável pela variação de Pwf
{

  double deltaP = _pwf/partes; // seta o Delta P que é obtido pelo usuário. Divisão de Pwf e q são obtidas pelo usuário

  while ( _pwf >= 0)
  {
      valoresPwf.push_back(_pwf); //Pwf armazenado é decrementado em Delta P
      _pwf -= deltaP;

   if(_pwf < 0)
      valoresPwf.push_back(0.0);

  } 

}
