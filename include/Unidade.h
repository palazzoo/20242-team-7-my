#ifndef UNIDADE_H
#define UNIDADE_H

#include "Carta.h"
#include <string>

class Unidade : public Carta {
    private:
        int Atk, Def, Hp; 
        bool Equip;         // Pilotado
        bool Guarda;
        int calor_produzido = 0; // Calor produzido pela unidade, por padrão é 0
    public:
        int getHp(); 
        void setHp(int _hp);
        int getAtk();
        void setAtk(int _atk);
        int getDef();
        Unidade(int Atk, int Def, int Hp, int Custo, std::string Desc, std::string Tipo, std::string Nome, bool Equip, int ID, bool Guarda);
        Unidade(int Atk, int Def, int Hp, int Custo, std::string Desc, std::string Tipo, std::string Nome, bool Equip, int ID, bool Guarda, int calor_produzido);
        void Atacar(Unidade &Outra);
        void receberDano(int dano);
        bool isEquiped();
        void recebe_efeito();
        void le()const;
        void ativa_guarda();
        std::string getnome();
    };

namespace UnidadesPredefinidas {
    extern const Unidade RX782Gundam;
    extern const Unidade RX75Guntank;
    extern const Unidade Guncannon;
    extern const Unidade Ball;
    extern const Unidade GM;
    extern const Unidade Zeong;
    extern const Unidade BigZam;
    extern const Unidade Gelgoog;
    extern const Unidade ZGok;
    extern const Unidade Gouf;
    extern const Unidade Zaku;
}
#endif