#ifndef INSTANTANEO_H
#define INSTANTANEO_H

#include "Tatica.h"
class Jogador;
class Unidade;

class Instantaneo : public Tatica{
    public:
         void fornece_efeito (Jogador jogador, Jogador inimigo);
         Instantaneo(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID);
};

namespace InstanteneoPredefinidos{
    extern const Instantaneo Carta1;
    extern const Instantaneo Carta2;
    extern const Instantaneo Carta3;
    extern const Instantaneo Carta4;
    extern const Instantaneo Carta5;
    extern const Instantaneo Carta6;
    extern const Instantaneo Carta7;
}
#endif