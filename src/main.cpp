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


void inicializaBaralho(Baralho& baralho) {
    // Adiciona unidades ao baralho
    baralho.adiciona_carta(new Unidade(RX782Gundam));
    baralho.adiciona_carta(new Unidade(RX75Guntank));
    baralho.adiciona_carta(new Unidade(Guncannon));
    baralho.adiciona_carta(new Unidade(Ball));
    baralho.adiciona_carta(new Unidade(GM));
    baralho.adiciona_carta(new Unidade(Zeong));
    baralho.adiciona_carta(new Unidade(BigZam));
    baralho.adiciona_carta(new Unidade(Gelgoog));
    baralho.adiciona_carta(new Unidade(ZGok));
    baralho.adiciona_carta(new Unidade(Gouf));
    baralho.adiciona_carta(new Unidade(Zaku));

    // Adiciona equipamentos ao baralho
    baralho.adiciona_carta(new Equipamento(GundamHammer));
    baralho.adiciona_carta(new Equipamento(ArmaduraChobam));
    baralho.adiciona_carta(new Equipamento(UpgradeGundam));
    baralho.adiciona_carta(new Equipamento(ReatorPartículasMinovsky));

    // Adiciona pilotos ao baralho
    baralho.adiciona_carta(new Piloto(AmuroRay));
    baralho.adiciona_carta(new Piloto(KayShiden));
    baralho.adiciona_carta(new Piloto(HayatoKobayashi));
    baralho.adiciona_carta(new Piloto(PilotoFederacao));
    baralho.adiciona_carta(new Piloto(CharAznable));
    baralho.adiciona_carta(new Piloto(DozleZabi));
    baralho.adiciona_carta(new Piloto(RambaRal));
    baralho.adiciona_carta(new Piloto(PilotoZeon));

    // Adiciona instantâneos ao baralho
    baralho.adiciona_carta(new Instantaneo(SistemaRaioSolar));
    baralho.adiciona_carta(new Instantaneo(ReforcosDaFederacao));
    baralho.adiciona_carta(new Instantaneo(OperacaoBritanica));
    baralho.adiciona_carta(new Instantaneo(NovaInvestida));
    baralho.adiciona_carta(new Instantaneo(INEUZaku));
    baralho.adiciona_carta(new Instantaneo(DesengajarCombate));
    baralho.adiciona_carta(new Instantaneo(CINADSN));
    baralho.adiciona_carta(new Instantaneo(ADCV));
}

int main() {
    // Cria um baralho com algumas cartas
    Baralho baralho;
    baralho.quantidade = 10;
    inicializaBaralho(baralho); // tenta adicionar as cartas ao baralho
    std::cout << baralho.quantidade << std::endl;
    


    for(int j=0 ; j<31 ; j++)  {  // testa se foram adicionadas 
        std::cout<<baralho.cartas[j]->getNome();
        std::cout<<std::endl;
    }
    
    // Cria dois jogadores com o baralho    
    std::string j1, j2;
    std::cout << "Digite o nome do Jogador 1: ";
    std::cin >> j1;
    std::cout << "Digite o nome do Jogador 2: ";
    std::cin >> j2;
    Jogador jogador1(100, j1, 20, baralho, true);  //Jogador::Jogador(int _vida, std::string _nome, int _qtdCalor, Baralho _baralho, bool _vezDeJogar) 
    Jogador jogador2(100, j2, 20, baralho, false);

    int indice=0;

        
    for (int i = 0; i < 10 ; i++) {
        jogador1.compra_carta(i);
        std::cout<<jogador1.mao[i]<<std::endl;
    }
    for (int j = 10; j < 20; j++) {
        jogador2.compra_carta(j);
    }

    // Cria uma partida com os dois jogadores
    Partida partida(jogador1.getNome(), jogador2.getNome());

    // Simula a partida
    while (!partida.encerra_partida(false)) {

        std::cout << "Rodada: " << partida.rodada << std::endl;
        
        std::cout << "Turno do " << (partida.getTurno() == 0 ? "Jogador 1" : "Jogador 2") << std::endl;
        if (partida.getTurno() == 0) {
            std::cout << "Mao Jogador: " << jogador1.getNome() << std::endl;
            jogador1.verMao();

            std::cout << "1 - Jogar Carta\n2 - Atacar\n3 - \n4 - Encerrar Partida\n5 - Exibir Historico\n6 - Passar Turno\n7 - Sair\n";
            int opcao;
            std::cin >> opcao;

            switch (opcao)
            {
            case 1:
                std::cout << "Digite o numero da carta: ";
                std::cin >> indice;

                jogador1.joga_carta(indice-1);
                break;
            case 2:
                std::cout << "Atacar\n";
                break;
            case 3:
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
                std::cout << "Saindo\n";
                partida.encerra_partida(true);
                break;
            default:
                std::cout << "Opcao invalida\n";
                break;
            }
        } else if (partida.getTurno() == 1) {
            std::cout << "Mao Jogador: " << jogador2.getNome() << std::endl;
            jogador2.verMao();
        
            std::cout << "1 - Jogar Carta\n2 - Atacar\n3 - \n4 - Encerrar Partida\n5 - Exibir Historico\n6 - Passar Turno\n7 - Sair\n";
            int opcao;
            std::cin >> opcao;

            switch (opcao)
            {
            case 1:
                std::cout << "Digite o numero da carta: ";
                std::cin >> indice;
                jogador1.joga_carta(indice-1);
                jogador2.joga_carta(0);
                break;
            case 2:
                std::cout << "Atacar\n";
                break;
            case 3:
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
                std::cout << "Saindo\n";
                partida.encerra_partida(true);
                break;
            default:
                std::cout << "Opcao invalida\n";
                break;
            }
        }

        // Passa o turno
        partida.passa_turno();
    }

    // Exibe o histórico da partida
    partida.exibe_historico();

    return 0;
}