#include "../include/Instantaneo.h"
#include "../include/Jogador.h"
#include "../include/Unidade.h"
#include <algorithm>

Instantaneo::Instantaneo(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID) : Carta(_Desc, _Tipo, _Nome, _Custo, _ID),
Tatica(_Desc, _Tipo, _Nome, _Custo, _ID) {}

void Instantaneo::fornece_efeito(Jogador jogador, Jogador inimigo) {
    switch (ID) {
    case 21:
        for (auto carta : jogador.campo) {
            if (auto unidadeCampo = dynamic_cast<Unidade*>(carta)) {
                unidadeCampo->receberDano(20);
            }
        }
        for (auto carta : inimigo.campo) {
            if (auto unidadeCampo = dynamic_cast<Unidade*>(carta)) {
                unidadeCampo->receberDano(20);
            }
        }
        break;

    case 22:
        for (auto carta : jogador.mao) {
            carta->setCusto(carta->getCusto() - 2);
            if (carta->getCusto() < 1)
                carta->setCusto(1);
        }
        break;

    case 23:
        for (auto it = jogador.campo.begin(); it != jogador.campo.end();) {
            if (auto unidadeCampo = dynamic_cast<Unidade*>(*it)) {
                unidadeCampo->receberDano(unidadeCampo->getHp());
                if (unidadeCampo->getHp() == 0) {
                    it = jogador.campo.erase(it);
                } else {
                    ++it;
                }
            } else {
                ++it;
            }
        }

        for (auto it = inimigo.campo.begin(); it != inimigo.campo.end();) {
            if (auto unidadeCampo = dynamic_cast<Unidade*>(*it)) {
                unidadeCampo->receberDano(unidadeCampo->getHp());
                if (unidadeCampo->getHp() == 0) {
                    it = inimigo.campo.erase(it);
                } else {
                    ++it;
                }
            } else {
                ++it;
            }
        }
        break;

    case 24: {
        int unidadesDespachadas = 0;
        std::vector<Unidade*> unidadesCustoBaixo;

        for (auto carta : jogador.mao) {
            if (auto unidade = dynamic_cast<Unidade*>(carta)) {
                if (unidade->getCusto() <= 2) {
                    unidadesCustoBaixo.push_back(unidade);
                }
            }
        }

        if (unidadesCustoBaixo.empty()) {
            std::cout << "Nenhuma unidade de custo 2 ou menor na mão!" << std::endl;
            return;
        }

        for (int i = 0; i < 2 && unidadesDespachadas < 2; ++i) {
            std::cout << "Escolha uma unidade para mover para o campo (Digite o número):" << std::endl;

            for (int j = 0; j < unidadesCustoBaixo.size(); ++j) {
                std::cout << j + 1 << ". " << unidadesCustoBaixo[j]->getNome() << " (Custo " << unidadesCustoBaixo[j]->getCusto() << ")" << std::endl;
            }

            int escolha;
            std::cin >> escolha;

            if (escolha >= 1 && escolha <= unidadesCustoBaixo.size()) {
                Carta* carta = unidadesCustoBaixo[escolha - 1];
                jogador.campo.push_back(carta);

                for (size_t i = 0; i < jogador.mao.size(); i++) {
                    if (jogador.mao[i] == carta) {
                        jogador.mao.erase(jogador.mao.begin() + i);
                        break;
                    }
                }

                unidadesDespachadas++;
                std::cout << unidadesCustoBaixo[escolha - 1]->getNome() << " foi movida para o campo!" << std::endl;
            } else {
                std::cout << "Escolha inválida, tente novamente." << std::endl;
            }
        }
        break;
    }

    case 25: {
        std::vector<Carta*> unidades;
        std::cout << "Escolha quais Unidades deseja recolher";
        int un1, un2;
        std::cin >> un1 >> un2;

        for (Carta* carta : jogador.campo) {
            if (dynamic_cast<Unidade*>(carta)) {
                unidades.push_back(carta);
            }
        }

        if (unidades.size() >= 2) {
            jogador.mao.push_back(unidades[0]);
            jogador.mao.push_back(unidades[1]);

            auto& campo = jogador.campo;
            campo.erase(std::remove(campo.begin(), campo.end(), unidades[un1]), campo.end());
            campo.erase(std::remove(campo.begin(), campo.end(), unidades[un2]), campo.end());
        }
        break;
    }

    case 26: {
            // Coleta as unidades do jogador
            std::vector<Unidade*> unidadesJogador;
            for (Carta* carta : jogador.campo) {
                if (auto unidade = dynamic_cast<Unidade*>(carta)) {
                    unidadesJogador.push_back(unidade);
                }
            }

            // Coleta as unidades do inimigo
            std::vector<Unidade*> unidadesInimigo;
            for (Carta* carta : inimigo.campo) {
                if (auto unidade = dynamic_cast<Unidade*>(carta)) {
                    unidadesInimigo.push_back(unidade);
                }
            }

            if (unidadesJogador.empty() || unidadesInimigo.empty()) {
                std::cout << "Não há unidades suficientes para executar o efeito." << std::endl;
                return;
            }

            // Selecionar uma unidade do jogador
            std::cout << "Escolha uma unidade do seu campo para destruir:" << std::endl;
            for (size_t i = 0; i < unidadesJogador.size(); ++i) {
                std::cout << i + 1 << ". " << unidadesJogador[i]->getNome() 
                          << " (HP: " << unidadesJogador[i]->getHp() << ")" << std::endl;
            }

            int escolhaJogador;
            std::cin >> escolhaJogador;

            if (escolhaJogador < 1 || escolhaJogador > unidadesJogador.size()) {
                std::cout << "Escolha inválida." << std::endl;
                return;
            }

            Unidade* unidadeSelecionada = unidadesJogador[escolhaJogador - 1];
            int hpUnidadeJogador = unidadeSelecionada->getHp();

            // Filtrar unidades inimigas elegíveis
            std::vector<Unidade*> unidadesElegiveis;
            for (Unidade* unidade : unidadesInimigo) {
                if (unidade->getHp() <= hpUnidadeJogador + 20) {
                    unidadesElegiveis.push_back(unidade);
                }
            }

            if (unidadesElegiveis.empty()) {
                std::cout << "Não há unidades inimigas elegíveis para destruir." << std::endl;
                return;
            }

            // Selecionar uma unidade inimiga
            std::cout << "Escolha uma unidade inimiga para destruir:" << std::endl;
            for (size_t i = 0; i < unidadesElegiveis.size(); ++i) {
                std::cout << i + 1 << ". " << unidadesElegiveis[i]->getNome() 
                          << " (HP: " << unidadesElegiveis[i]->getHp() << ")" << std::endl;
            }

            int escolhaInimigo;
            std::cin >> escolhaInimigo;

            if (escolhaInimigo < 1 || escolhaInimigo > unidadesElegiveis.size()) {
                std::cout << "Escolha inválida." << std::endl;
                return;
            }

            Unidade* unidadeInimigaSelecionada = unidadesElegiveis[escolhaInimigo - 1];

            // Remover as unidades do campo
            jogador.campo.erase(std::remove(jogador.campo.begin(), jogador.campo.end(), unidadeSelecionada), jogador.campo.end());
            inimigo.campo.erase(std::remove(inimigo.campo.begin(), inimigo.campo.end(), unidadeInimigaSelecionada), inimigo.campo.end());

            std::cout << unidadeSelecionada->getNome() << " foi destruída." << std::endl;
            std::cout << unidadeInimigaSelecionada->getNome() << " foi destruída." << std::endl;

            break;
        }

    case 27: {
            std::vector<Unidade*> unidadesInimigas;

            for (auto carta : inimigo.campo) {
                if (auto unidade = dynamic_cast<Unidade*>(carta)) {
                    unidadesInimigas.push_back(unidade);
                }
            }

            if (unidadesInimigas.empty()) {
                std::cout << "Não há unidades inimigas no campo!" << std::endl;
                return;
            }

            std::cout << "Escolha uma unidade inimiga para aplicar 30 de dano:" << std::endl;

            for (int i = 0; i < unidadesInimigas.size(); ++i) {
                std::cout << i + 1 << ". " << unidadesInimigas[i]->getNome() << " (HP: " << unidadesInimigas[i]->getHp() << ")" << std::endl;
            }

            int escolha;
            std::cin >> escolha;

            if (escolha >= 1 && escolha <= unidadesInimigas.size()) {
                Unidade* unidadeEscolhida = unidadesInimigas[escolha - 1];
                unidadeEscolhida->receberDano(30);

                if (unidadeEscolhida->getHp() <= 0) {
                    auto& campo = inimigo.campo;
                    campo.erase(std::remove(campo.begin(), campo.end(), unidadeEscolhida), campo.end());
                    std::cout << unidadeEscolhida->getNome() << " foi destruída!" << std::endl;
                } else {
                    std::cout << unidadeEscolhida->getNome() << " agora tem " << unidadeEscolhida->getHp() << " de HP!" << std::endl;
                }
            } else {
                std::cout << "Escolha inválida." << std::endl;
            }
            break;
        }

    default:
        std::cout << "Efeito não definido para este ID." << std::endl;
        break;
    }
}
