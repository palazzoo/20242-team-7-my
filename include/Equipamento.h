#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include "Tatica.h"


class Equipamento : public Tatica{
    private:
        int atkextra;
        int hpextra;
        bool guarda;
        int calor_extra = 0; //calor extra gerado pelo equipamento, por padrão é 0
    public:
        void fornece_efeito(Unidade unidade, Jogador jogador) override;
        //construtores da classe Equipamento
        Equipamento(int atkextra, int hpextra, bool guarda, int _calor_extra, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID);
        Equipamento(int atkextra, int hpextra, bool guarda, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID);
};

namespace EquipamentosPredefinidos{
    extern const Equipamento GundamHammer;
    extern const Equipamento ArmaduraChobam;
    extern const Equipamento UpgradeGundam;
    extern const Equipamento ReatorPartículasMinovsky;
}
#endif

