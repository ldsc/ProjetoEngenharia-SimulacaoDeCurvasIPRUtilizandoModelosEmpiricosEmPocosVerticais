#ifndef CMETODO_H
#define CMETODO_H

// Classe para enumerar os metodos de calculo de IPR

enum class CMetodo {

    none = 0, IPR_LINEAR, IPR_GENERALIZADA,
    IPR_FETKOVICH, IPR_VOGEL
    
    // O usuario fica aberto a adicionar mais metodos

};

#endif