#include "../include/Partida.h"
#include "../include/Carta.h"
#include "../include/Jogador.h"
#include <iostream>

int main(){
    Partida P;
    while (true)
    {
        std::cout << "Rodada: " << P.rodada << std::endl;
        if(P.encerra_partida()){
            break;
        }

        std::cout << "1 - Jogar Carta\n2 - Atacar\n3 - Encerrar Turno\n4 - Encerrar Partida\n5 - Exibir Historico\n6 - Passar Turno\n7 - Sair\n";
        int opcao;
        std::cin >> opcao;
        switch (opcao)
        {
        case 1:
            std::cout << "Jogar Carta\n";
            break;
        case 2:
            std::cout << "Atacar\n";
            break;
        case 3:
            std::cout << "Encerrar Turno\n";
            break;
        case 4:
            P.encerra_partida(true);
            break;
        case 5:
            P.exibe_historico();
            break;
        case 6:
            P.passa_turno();
            break;
        case 7:
            std::cout << "Sair\n";
            break;
        default:
            std::cout << "Opcao invalida\n";
            break;
        }

        P.rodada++;
    }
    
}