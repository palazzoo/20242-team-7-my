#ifndef BARALHO_H
#define BARALHO_H

#include "Carta.h"

class Baralho {
public:
    int quantidade;
    std::vector<Carta*> lista;
    std::string nome;
    int IDBaralho;

    Carta* seleciona_carta(int qtd);

    void adiciona_carta(Carta* carta);
};

#endif