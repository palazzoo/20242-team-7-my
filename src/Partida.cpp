#define VIDA_INICIAL 100
#define CALOR_INICIAL 20

#include "../include/Partida.h"

Baralho baralho1;
Baralho baralho2;
Partida::Partida() : j1(VIDA_INICIAL, "Jogador 1", CALOR_INICIAL, Baralho(), true), j2(VIDA_INICIAL, "Jogador 2", CALOR_INICIAL, Baralho(), false) {
    tempo = 0;
    rodada = 0;
    historico = "";
    turno = 0;
}
Partida::Partida(std::string nome_j1, std::string nome_j2, bool fim, int tempo, int rodada, std::string historico, int turno) {
    // Inicialize os membros da classe com os parâmetros fornecidos
    this->nome_j1 = nome_j1;
    this->nome_j2 = nome_j2;
    this->fim = fim;
    this->tempo = tempo;
    this->rodada = rodada;
    this->historico = historico;
    this->turno = turno;

    // Inicializando os objetos Jogador com os parâmetros fornecidos
    this->j1 = Jogador( 100, nome_j2, 0, baralho1, true);  // Inicializa o Jogador 1 com os valores apropriados
    this->j2 = Jogador(100, nome_j2, 0, baralho2, false); // Inicializa o Jogador 2 com os valores apropriados
}
//int _vida, std::string _nome, int _qtdCalor, Baralho _baralho, bool _vezDeJogar

bool Partida::encerra_partida(bool _fim) {
    // Se a partida já deve ser encerrada
    if (_fim) {
        std::cout << "Partida encerrada!" << std::endl;
        fim = true;
        return true;  // Encerra imediatamente
    }

    // Condições de vitória ou empate baseadas na vida dos jogadores
    if (j1.getVida() <= 0) {
        std::cout << "Jogador " << j2.getNome() << " venceu a partida!" << std::endl;
        fim = true;  // Marca a partida como encerrada
        return true;
    } else if (j2.getVida() <= 0) {
        std::cout << "Jogador " << j1.getNome() << " venceu a partida!" << std::endl;
        fim = true;  // Marca a partida como encerrada
        return true;
    } else if (j1.getVida() == j2.getVida() && j1.getVida() == 0 && j2.getVida() == 0) {
        std::cout << "Empate!!!" << std::endl;
        fim = true;  // Marca a partida como encerrada
        return true;
    }

    return false;  // Caso a partida ainda continue
}



void Partida::exibe_historico() {
    std::cout << "Histórico da partida: " << historico << std::endl;
}

void Partida::passa_turno() {
    // Troca o turno
    // 0 -> Jogador 1
    // 1 -> Jogador 2
    turno = (turno + 1) % 2;
    std::cout << "Proximo turno." << std::endl;
}

 Jogador& Partida::getJ1() {
    return j1;
 }
 Jogador& Partida::getJ2(){
    return j2;
 }

 int Partida::getTurno(){
    return turno;
 }

