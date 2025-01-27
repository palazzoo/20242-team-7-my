#include "../include/Jogador.h"

Jogador::Jogador(int _vida, std::string _nome, int _qtdCalor, Baralho _baralho, bool _vezDeJogar) 
    : vida(_vida), nome(_nome), qtdCalor(_qtdCalor), baralho(_baralho), vezDeJogar(_vezDeJogar) {}

void Jogador::compra_carta(int indice) {
    if (indice >= 0 && indice < baralho.quantidade_cartas()) {
        Carta* carta = baralho.seleciona_carta(indice);
        if (carta) {
            mao.push_back(carta);
        }
    }
}

void Jogador::joga_carta(int indice) {
    if (indice >= 0 && indice < mao.size()) {
        Carta* carta = mao[indice];
        campo.push_back(carta);
        mao.erase(mao.begin() + indice);
    }
}

void Jogador::verMao() {
    for (Carta* carta : mao) {
        std::cout << "Mao Jogador: " << getNome() << std::endl;
        std::cout << "\t" << carta->getNome() << " " << carta->getTipo() << carta->getID() << std::endl;
    }
}

void Jogador::descarta(const Carta* carta) {
    // seleciona uma carta da mão e descarta
    auto it = std::find(mao.begin(), mao.end(), carta);
    if (it != mao.end()) {
        pilha_descarte.push_back(*it);
        mao.erase(it);
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
