#include "../include/Jogador.h"
#include <algorithm>

Jogador::Jogador(int _vida, std::string _nome, int _qtdCalor, Baralho _baralho, bool _vezDeJogar) 
    : vida(_vida), nome(_nome), qtdCalor(_qtdCalor), baralho(_baralho), vezDeJogar(_vezDeJogar) {
        std::cout<<"Jogador "<<_nome<< " inicializado"<<std::endl;
    }

void Jogador::compra_carta(int indice) {   
    if (indice >= 0 && indice < baralho.quantidade_cartas()) {   //Verifica se o índice fornecido é válido para acessar uma carta no baralho
        Carta* carta = baralho.seleciona_carta(indice); //Obtém a carta correspondente usando o método baralho.seleciona_carta(indice)
        if (carta) {                //Verifica se a carta obtida é válida (não nula)
            mao.push_back(carta);   //Se for válida, adiciona a carta ao vetor mao (mão do jogador).
        }
        else{
            std::cout<<"Falha ao comprar carta!"<<std::endl; //se nao for valida, imprime erro
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
    for (int i = 0; i < mao.size(); ++i) {
        Carta* carta = mao[i];
        std::cout << "\t[" << i+1 << "] " << carta->getNome() << " " << carta->getTipo() <<  std::endl;
    }
}

void Jogador::descarta(const Carta* carta) {
    // seleciona uma carta da mão e descarta
    auto it = std::find_if(mao.begin(), mao.end(), [&](const Carta* c) { return *c == *carta; });
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
