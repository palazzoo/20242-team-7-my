#include "../include/Partida.h"
#include "../include/Carta.h"
#include "../include/Jogador.h"
#include "../include/Instantaneo.h"
#include "../include/Unidade.h"
#include "../include/Equipamento.h"
#include "../include/Piloto.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;



#include <iostream>
#include "../include/Partida.h"
#include "../include/Jogador.h"
#include "../include/Baralho.h"

int main() {
    // Cria um baralho para os jogadores
    Baralho baralho;

    // Recebe os nomes dos jogadores
    std::string j1, j2;
    std::cout << "Digite o nome do Jogador 1: ";
    std::cin >> j1;
    std::cout << "Digite o nome do Jogador 2: ";
    std::cin >> j2;

    // Cria dois jogadores com o baralho
    Jogador jogador1(100, j1, 20, baralho, true);  // Jogador 1 começa
    Jogador jogador2(100, j2, 20, baralho, false); // Jogador 2 começa

    // Histórico da partida
    std::string historico;

    // Cria a partida
    Partida partida(j1, j2, false, 0, 0, historico, 0); // Fim da partida ainda não ocorreu, turno começa com 0

    // Loop principal da partida
    while (!partida.encerra_partida()) {
        std::cout << "Rodada: " << partida.rodada << std::endl;
        std::cout << "Turno do " << (partida.getTurno() == 0 ? jogador1.getNome() : jogador2.getNome()) << std::endl;

        // Exibe a mão do jogador atual
        if (partida.getTurno() == 0) {
            std::cout << "Mão de " << jogador1.getNome() << ":\n";
            jogador1.verMao();
        } else {
            std::cout << "Mão de " << jogador2.getNome() << ":\n";
            jogador2.verMao();
        }

        // Menu de opções para o jogador
        std::cout << "Escolha uma opção:\n";
        std::cout << "1 - Jogar Carta\n2 - Atacar\n3 - Encerrar Turno\n4 - Encerrar Partida\n5 - Exibir Historico\n6 - Passar Turno\n7 - Sair\n";
        int opcao;
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                if (partida.getTurno() == 0) {
                    jogador1.joga_carta(0);  // Jogador 1 joga a primeira carta da mão
                } else {
                    jogador2.joga_carta(0);  // Jogador 2 joga a primeira carta da mão
                }
                break;

            case 2:
                std::cout << "Atacar\n";
                // Função de ataque a ser implementada, se necessário.
                break;

            case 3:
                std::cout << "Encerrar Turno\n";
                partida.passa_turno(); // Passa o turno
                break;

            case 4:
                partida.encerra_partida(true); // Encerra a partida
                break;

            case 5:
                partida.exibe_historico(); // Exibe o histórico da partida
                break;

            case 6:
                partida.passa_turno(); // Passa o turno para o outro jogador
                break;

            case 7:
                std::cout << "Saindo...\n";
                return 0; // Encerra o programa

            default:
                std::cout << "Opção inválida\n";
                break;
        }

        // Verifica se a partida acabou após o turno
        if (partida.encerra_partida()) {
            std::cout << "Fim de jogo!" << std::endl;
            break; // Encerra o loop quando a partida termina
        }

        // Jogador compra uma carta após jogar
        if (partida.getTurno() == 0) {
            jogador1.compra_carta(0); // Jogador 1 compra uma carta
        } else {
            jogador2.compra_carta(0); // Jogador 2 compra uma carta
        }

        // Jogador joga uma carta após comprar
        if (partida.getTurno() == 0) {
            jogador1.joga_carta(0); // Jogador 1 joga uma carta
        } else {
            jogador2.joga_carta(0); // Jogador 2 joga uma carta
        }

        // Passa o turno
        partida.passa_turno();
    }

    // Exibe o histórico da partida ao final
    partida.exibe_historico();
    return 0;
}





