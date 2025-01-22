#include "../include/Jogador.h"

Jogador::Jogador(int _vida, std::string _nome, int _qtdCalor, Baralho _baralho, bool _vezDeJogar) 
    : vida(_vida), nome(_nome), qtdCalor(_qtdCalor), baralho(_baralho), vezDeJogar(_vezDeJogar) {}

void Jogador::compra_carta(int qtd) {
    for (int i = 0; i < qtd; ++i) {
            Carta* carta = baralho.seleciona_carta(i);
            if (carta) {
                mao.push_back(carta);
            }
        }
}

void Jogador::declara_ataque(Unidade atacante, Unidade defensora){
    atacante.Atacar(defensora);
}

int Jogador::getcalor(){
    return qtdCalor;
}
void Jogador::setcalor(int _calor){
    qtdCalor = _calor;
}

int Jogador::getVida(){
    return vida;
}

std::string Jogador::getNome(){
    return nome;
}







