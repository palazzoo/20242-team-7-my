#include "../include/Carta.h"
#include "../include/Piloto.h"
#include "../include/Unidade.h"
#include "../include/Tatica.h"
#include "../include/Instantaneo.h"
#include "../include/Equipamento.h"
#include "../include/Partida.h"
#include "../include/Baralho.h"
#include "../include/Jogador.h"
#include <iostream>

using namespace UnidadesPredefinidas;
using namespace EquipamentosPredefinidos;
using namespace PilotosPredefinidos;
using namespace InstanteneoPredefinidos;




int main() {
    // Cria um baralho com algumas cartas
    Baralho baralho;

    // Cria dois jogadores com o baralho
    std::string j1, j2;
    std::cout << "Digite o nome do Jogador 1: ";
    std::cin >> j1;
    std::cout << "Digite o nome do Jogador 2: ";
    std::cin >> j2;
    Jogador jogador1(100, j1, 20, baralho, true);
    Jogador jogador2(100, j2, 20, baralho, false);

    // Cria uma partida com os dois jogadores
    Partida partida(jogador1.getNome(), jogador2.getNome());

    // Simula a partida
    while (!partida.encerra_partida(false)) {

        std::cout << "Rodada: " << partida.rodada << std::endl;
        
        std::cout << "Turno do " << (partida.getTurno() == 0 ? "Jogador 1" : "Jogador 2") << std::endl;
        if (partida.getTurno() == 0) {
            std::cout << "Mao Jogador: " << jogador1.getNome() << std::endl;
            jogador1.verMao();

            std::cout << "1 - Jogar Carta\n2 - Atacar\n3 - Encerrar Turno\n4 - Encerrar Partida\n5 - Exibir Historico\n6 - Passar Turno\n7 - Sair\n";
            int opcao;
            std::cin >> opcao;

            switch (opcao)
            {
            case 1:
                jogador1.joga_carta(0);
                break;
            case 2:
                std::cout << "Atacar\n";
                break;
            case 3:
                std::cout << "Encerrar Turno\n";
                break;
            case 4:
                partida.encerra_partida(true);
                break;
            case 5:
                partida.exibe_historico();
                break;
            case 6:
                partida.passa_turno();
                break;
            case 7:
                std::cout << "Sair\n";
                break;
            default:
                std::cout << "Opcao invalida\n";
                break;
            }
        } else {
            std::cout << "Mao Jogador: " << jogador2.getNome() << std::endl;
            jogador2.verMao();
        
            std::cout << "1 - Jogar Carta\n2 - Atacar\n3 - Encerrar Turno\n4 - Encerrar Partida\n5 - Exibir Historico\n6 - Passar Turno\n7 - Sair\n";
            int opcao;
            std::cin >> opcao;

            switch (opcao)
            {
            case 1:
                jogador2.joga_carta(0);
                break;
            case 2:
                std::cout << "Atacar\n";
                break;
            case 3:
                std::cout << "Encerrar Turno\n";
                break;
            case 4:
                partida.encerra_partida(true);
                break;
            case 5:
                partida.exibe_historico();
                break;
            case 6:
                partida.passa_turno();
                break;
            case 7:
                std::cout << "Sair\n";
                break;
            default:
                std::cout << "Opcao invalida\n";
                break;
            }
        }


        // Jogador compra uma carta
        if (partida.getTurno() == 0) {
            jogador1.compra_carta(0); // Jogador 1 compra a primeira carta do baralho
            jogador1.verMao();
        } else {
            jogador2.compra_carta(0); // Jogador 2 compra a primeira carta do baralho
            jogador2.verMao();
        }

        // Jogador joga uma carta
        if (partida.getTurno() == 0) {
            jogador1.joga_carta(0); // Jogador 1 joga a primeira carta da mão
        } else {
            jogador2.joga_carta(0); // Jogador 2 joga a primeira carta da mão
        }

        // Passa o turno
        partida.passa_turno();
    }

    // Exibe o histórico da partida
    partida.exibe_historico();

    return 0;
}