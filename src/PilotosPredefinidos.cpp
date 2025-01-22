#include "Piloto.h"

namespace PilotosPredefinidos{


    /*Efeito do piloto, 
    Unidade tripulada,
    Descrição
    Tipo
    Nome
    Custo
    ID
    
    */

    const Piloto AmuroRay = Piloto("Ao ser despachado numa unidade afiliada a Federacao da Terra, 
                                    compre uma carta para cada unidade da Federacao da Terra em campo.
                                    Além , receba 1 de calor no início de cada turno, se esse piloto
                                    estiver tripulando uma unidade da Federacao da Terra.",
                                    NULL, 
                                    "Um heroi da guerra de um ano, pilotou o Mobile Suit RX-78-2 GUDAN
                                    no lado da Federacao da Terra. Também conhecido como 'Diabo Branco'",
                                    NULL,
                                    "Amuro Ray",
                                    3,
                                    1);

    const Piloto KayShiden = Piloto("Efeito",
                                     NULL,
                                     "Descricao",
                                     NULL,
                                     "Kay Shiden",
                                     3,
                                     2);

    const Piloto HayatoKobayashi = Piloto("Efeito",
                                           NULL,
                                           "Descricao",
                                           NULL,
                                           "Hayato Kobayashi",
                                           3,
                                           3);

    const Piloto GenericoFederacao = Piloto("Efeito",
                                             NULL,
                                            "Descricao",
                                            NULL,
                                            "Generico da Federacao",
                                            3,
                                            4);

    const Piloto CharAznable = Piloto("Efeito",
                                      NULL,
                                      "Descricao",
                                      NULL,
                                      "Char Azanable",
                                      3,
                                      5);
    const Piloto DozleZabi = Piloto("Efeito",
                                     NULL,
                                     "Descricao",
                                     NULL,
                                     "Dozle Zabi",
                                     3,
                                     6);
     const Piloto RambaRal = Piloto("Efeito",
                                     NULL,
                                     "Descricao",
                                     NULL,
                                     "Ramba Ral",
                                     3,
                                     7);
    const Piloto GenericoZeon = Piloto("Efeito",
                                        NULL,
                                        "Descricao",
                                        NULL,
                                        "Generico de Zeon",
                                        3,
                                        8);
    






}


std::string _efeito_piloto, Unidade _unidade_tripulada, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID