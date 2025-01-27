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
    const Instantaneo SistemaRaioSolar;
    const Instantaneo ReforcosDaFederacao;
    const Instantaneo OperacaoBritanica;
    const Instantaneo NovaInvestida;
    const Instantaneo INEUZaku;
    const Instantaneo DesengajarCombate;
    const Instantaneo CINADSN;
    const Instantaneo ADCV;
}
#endif