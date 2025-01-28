#include "../include/Piloto.h"
#include "../include/Carta.h"
#include "../include/Jogador.h"

Piloto::Piloto(std::string _efeito_piloto, Unidade* _unidade_tripulada, 
               std::string _Desc, std::string _Tipo, 
               std::string _Nome, int _Custo, int _ID)
    : Carta(_Desc, _Tipo, _Nome, _Custo, _ID),
      unidade_tripulada(_unidade_tripulada),
      efeito_piloto(_efeito_piloto) {
    
}

Unidade* Piloto::getUnidadeTripulada() {
    return unidade_tripulada;
}

void Piloto::fornece_efeito(Jogador& jogador) {
    if (!unidade_tripulada) {
        return;
    }

    switch (getID()) {
        case 1: // Amuro Ray
        {
            unidade_tripulada->setHp(unidade_tripulada->getHp() + 15);
            if (unidade_tripulada->getNome() == "RX78-2 GUNDAM") {
                // evasion 
            }
            break;
        }

        case 2: // Kay Shiden
            //  Kay Shiden effect
            break;

        case 3: // Hayato
            // Hayato effect
            break;

        case 4: // Piloto Genérico da Federação
        {
            std::vector<size_t> indicesF;
            size_t nPF = 0;

            for (size_t i = 0; i < jogador.getCampo().size(); ++i) {
                Carta* carta = jogador.getCampo()[i];
                if (carta && carta->getNome() == "Piloto da Federacao") {
                    nPF++;
                    indicesF.push_back(i);
                }
            }

            if (nPF >= 2) {
                for (size_t idx : indicesF) {
                    Piloto* piloto = dynamic_cast<Piloto*>(jogador.getCampo()[idx]);
                    if (piloto) {
                        Unidade* unidade = piloto->getUnidadeTripulada();
                        if (unidade) {
                            unidade->setHp(unidade->getHp() + 15);
                        }
                    }
                }
            }
            break;
        }

        case 5: // Char Aznable
            //  Char effect
            break;

        case 6: // Dozle Zabi
            //  Dozle effect
            break;

        case 7: // Ramba Ral
            //  Ramba Ral effect
            break;

        case 8: // Piloto Genérico de Zeon
        {
            std::vector<size_t> indicesZ;
            size_t nPZ = 0;

            for (size_t i = 0; i < jogador.getCampo().size(); ++i) {
                Carta* carta = jogador.getCampo()[i];
                if (carta && carta->getNome() == "Piloto de Zeon") {
                    nPZ++;
                    indicesZ.push_back(i);
                }
            }

            if (nPZ >= 2) {
                for (size_t idx : indicesZ) {
                    Piloto* piloto = dynamic_cast<Piloto*>(jogador.getCampo()[idx]);
                    if (piloto) {
                        Unidade* unidade = piloto->getUnidadeTripulada();
                        if (unidade) {
                            unidade->setAtk(unidade->getAtk() + 15);
                        }
                    }
                }
            }
            break;
        }

        default:
            std::cout << "Efeito não definido para este ID: " << getID() << std::endl;
            break;
    }
}

Piloto::~Piloto() {
}