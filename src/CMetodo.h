#ifndef CMETODO_H
#define CMETODO_H

// Classe para enumerar os metodos de cálculo de IPR

enum class CMetodo {

    none = 0, IPR_LINEAR, IPR_GENERALIZADA,
    IPR_FETKOVICH, IPR_VOGEL
    
    // O usuário fica aberto a adicionar mais métodos

};

#endif