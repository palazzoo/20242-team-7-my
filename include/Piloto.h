#ifndef PILOTO_H
#define PILOTO_H
#include "Carta.h"
#include <cstring>

class Piloto: public: Carta{
    private:
    std:: string efeito_piloto;
    Unidade unidade_tripulada;
    public:
    void fornece_efeito() override;
    

};


#endif