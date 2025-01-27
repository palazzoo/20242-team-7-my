#include "../include/Baralho.h"

Carta* Baralho::seleciona_carta(int qtd) {
    if (qtd < cartas.size()) {
        return cartas[qtd];
    }
    return nullptr;
}

void Baralho::adiciona_carta(Carta* carta) {
    cartas.push_back(carta);
}

int Baralho::quantidade_cartas() {
    return cartas.size();
}

Baralho::~Baralho() {
    // Libera a memória das cartas
    for (Carta* carta : cartas) {
        delete carta;
    }
}