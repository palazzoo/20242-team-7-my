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

    const Piloto AmuroRay = Piloto("Unidade que pilota recebe PV+25. "
                                "Caso a Unidade Pilotada tenha o nome \"GUNDAM\", "
                                "a unidade recebe Evasão.",
                                NULL, 
                                "Um heroi da guerra de um ano, pilotou o Mobile Suit RX-78-2 GUNDAM "
                                "no lado da Federação da Terra. Também conhecido como \"Diabo Branco\"",
                                "Piloto",
                                "Amuro Ray",
                                4,
                                1);


    const Piloto KayShiden = Piloto("Efeito",
                                     NULL,
                                     "Descricao",
                                     "Piloto",
                                     "Kay Shiden",
                                     3,
                                     2);

    const Piloto HayatoKobayashi = Piloto("Efeito",
                                           NULL,
                                           "Descricao",
                                           "Piloto",
                                           "Hayato Kobayashi",
                                           2,
                                           3);

    const Piloto PilotoFederacao = Piloto("Caso existam 2 ou mais cópias de \"Piloto da Federação\" "
                                      "no campo, cada unidade pilotada por \"Piloto da Federação\" "
                                      "recebe PV+15",
                                      nullptr,
                                      "Descricao",
                                      "Piloto",
                                      "Piloto da Federacao",
                                      1,
                                      4);


    const Piloto CharAznable = Piloto("Efeito",
                                      NULL,
                                      "Descricao",
                                      "Piloto",
                                      "Char Azanable",
                                      4,
                                      5);
    const Piloto DozleZabi = Piloto("Efeito",
                                     NULL,
                                     "Descricao",
                                     "Piloto",
                                     "Dozle Zabi",
                                     3,
                                     6);
     const Piloto RambaRal = Piloto("Efeito",
                                     NULL,
                                     "Descricao",
                                     "Piloto",
                                     "Ramba Ral",
                                     2,
                                     7);
    const Piloto PilotoZeon = Piloto("Caso existam 2 ou mais cópias de \"Piloto de Zeon\" "
                                 "no campo, cada unidade pilotada por \"Piloto de Zeon\" "
                                 "recebe ATK+15",
                                 nullptr,
                                 "Descricao",
                                 "Piloto",
                                 "Piloto de Zeon",
                                 1,
                                 8);

    






}

