#ifndef PARTIDA_H
#define PARTIDA_H

#include "Jogador.h"
#include "Baralho.h"

class Partida {
private:
    Jogador j1;
    Jogador j2;
    bool fim = false;
    std::string nome_j1;
    std::string nome_j2;
   

public:
    int tempo;
    int rodada;
    std::string historico;
    int turno;
    
    Partida();
    Partida(std::string nome_j1, std::string nome_j2, bool fim, int tempo, int rodada, std::string historico, int turno);
    ~Partida() = default;

    bool encerra_partida(bool _fim = false);

    void exibe_historico();

    void passa_turno();
    int getTurno();

    Jogador& getJ1(); 
    Jogador& getJ2();
};

#endif