#ifndef JOGADOR_H
#define JOGADOR_H

#include "Carta.h"
#include "Baralho.h"
#include "Unidade.h"

class Jogador{
public:
    int vida;
    std::string nome;
    std::vector<Carta*> mao;
    int qtdCalor;
    Baralho baralho;
    std::vector<Carta*> pilha_descarte;
    std::vector<Carta*> campo;
    bool vezDeJogar;
    Jogador();
    Jogador(int _vida, std::string _nome, int _qtdCalor, Baralho _baralho, bool _vezDeJogar);
    void compra_carta(int qtd);
    void joga_carta(int ID);
    void declara_efeito(Carta* c);
    void encerra_turno();
    void descarta(const Carta* carta);
    void verMao();

    void declara_ataque(Unidade atacante, Unidade defensora);
    int getcalor();
    void setcalor(int _calor);
    void setHP(int hp);
    int getVida();
    std::string getNome();
    const std::vector<Carta*>& getCampo() const;
    std::vector<Carta*>& getCampo();
    
     
    
};
#endif
