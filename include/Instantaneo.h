#ifndef INSTANTANEO_H
#define INSTANTANEO_H

#include "Tatica.h"
class Jogador;
class Unidade;

class Instantaneo : public Tatica{
    public:
        void fornece_efeito (Jogador jogador, Jogador inimigo);
        // Construtor padrão
        Instantaneo();
        Instantaneo(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID);
};

namespace InstanteneoPredefinidos{
    extern const Instantaneo SistemaRaioSolar;
    extern const Instantaneo OperacaoBritanica;
    extern const Instantaneo ReforcosDaFederacao;
    extern const Instantaneo NovaInvestida;
    extern const Instantaneo INEUZaku;
    extern const Instantaneo DesengajarCombate;
    extern const Instantaneo CINADSN;
    extern const Instantaneo ADCV;
}
#endif