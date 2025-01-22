#include "../include/Baralho.h"

Carta* Baralho::seleciona_carta(int qtd) {
    if (qtd < lista.size()) {
        return lista[qtd];
    }
    return nullptr;
}

void Baralho::adiciona_carta(Carta* carta) {
    lista.push_back(carta);
}