#include "../include/Carta.h"
#include "../include/Jogador.h"


int Carta::getID() {
    return ID;
}

int Carta::getCusto() {
    return Custo;
}

std::string Carta::getTipo() {
    return Tipo;
}

std::string Carta::getNome(){
    return Nome;
}

Carta::Carta(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID)
    : Descricao(_Desc), Tipo(_Tipo), Nome(_Nome), Custo(_Custo), ID(_ID) {}

Carta::~Carta() {} 

void Carta::gasta_calor(int custo, Jogador& jogador){
    jogador.setcalor(jogador.getcalor() - custo);
}
void Carta::gera_calor(int qtd, Jogador& jogador){
    jogador.setcalor(jogador.getcalor() + qtd);
}

 void Carta::fornece_efeito(){}

void Carta::setCusto(int custo){
    Custo = custo;
}

bool Carta::operator==(const Carta& other) const {
        // Implementação da comparação
        return this->ID == other.ID; // Exemplo de comparação
    }

