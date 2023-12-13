#include "CIPR.h"
#include <vector>

CIPR::CIPR()
{
}

// Declarando e definindo o metodo CalcIPR na classe CIPR	
void CIPR::CalcIPR(CFluido* fluido, CReservatorio& reservatorio, CPoco& poco, CPoco& parametrosSegundoPoco) {
    
}

void CIPR::CalcIPR(CFluido *fluido, CReservatorio &reservatorio, CPoco &poco)
{
}

void CIPR::iprVariacaoPwf(double _pwf) // Funcao responsavel pela variacao de Pwf
{

  double deltaP = _pwf/partes; // seta o Delta P que eh obtido pelo usuario. Divisao de Pwf e q sao obtidas pelo usuario

  while ( _pwf >= 0)
  {
      valoresPwf.push_back(_pwf); //Pwf armazenado eh decrementado em Delta P
      _pwf -= deltaP;

   if(_pwf < 0)
      valoresPwf.push_back(0.0);

  } 

}
