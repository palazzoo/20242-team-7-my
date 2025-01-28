#ifndef PILOTO_H
#define PILOTO_H
#include "../include/Carta.h"
#include "../include/Unidade.h"
#include <cstring>
  
class Piloto : public Carta {
private:
    Unidade* unidade_tripulada;
    std::string efeito_piloto;

public:
    Piloto(std::string _efeito_piloto, Unidade* _unidade_tripulada,
           std::string _Desc, std::string _Tipo,
           std::string _Nome, int _Custo, int _ID);
    
    virtual ~Piloto();
    
    Unidade* getUnidadeTripulada();
    virtual void fornece_efeito(Jogador& jogador);
};

namespace PilotosPredefinidos{
    extern const Piloto AmuroRay;
    extern const Piloto KayShiden;
    extern const Piloto HayatoKobayashi;
    extern const Piloto PilotoFederacao;
    extern const Piloto CharAznable;
    extern const Piloto DozleZabi;
    extern const Piloto RambaRal;
    extern const Piloto PilotoZeon;
}


#endif