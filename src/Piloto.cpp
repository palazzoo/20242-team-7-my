   #include "../include/Piloto.h"
   #include "../include/Carta.h"
   #include "../include/Jogador.h"
   
   
   
   Piloto :: Piloto(std::string _efeito_piloto, Unidade _unidade_tripulada, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID)
    :Carta(_Desc, _Tipo, _Nome, _Custo, _ID),//Chama o construtor da superclasse
    unidade_tripulada(_unidade_tripulada),//Unidade do piloto
    efeito_piloto(_efeito_piloto){ //Efeito do piloto
    }

    ~Piloto(){
        //Nada no destrutor, sem alocação dinâmica
    }

    void fornece_efeito() override{
        switch (_ID)
        {
        case 1: //Amuro Ray
            _unidade_tripulada.Hp +=15;
            if(_unidade_tripulada.Nome=="RX78-2 GUDAM"){
                //Evasão
            }
            break;

        case 2:// Kay Shiden
            //Efeito do Kai Shiden
            break;

        case 3: //Hayato
            //Efeito do Hayato
            break;

        case 4: //Genérico federação
            int nPF=0; //Contagem de pilotoos da federação em campo
            std::vector<int> indicesF[campo.size()]; //Lista que vai guardar os indices de cartas em campo
                                                    //que são pilotos genéricos da federação
            int j=0; //Variáver usada para percorres o vetor indices
            for(int i=0;i< campo.size();i++){ ///Percorre Campo
                if(campo[i].nome=="Piloto da Federacao"){ //Verifica se é um gerérico da federação
                    nPF++; //Se sim, contabilizaa em npf
                    indicesF[j]=i; //Guarda o indice
                    j++; //Aumenta j.
                }
            }

            if(nPF>=2){ //Se nPF é maior ou igual a 2
                for(int i=0;i<indicesF.size();i++){ //Percorre indices
                    campo[indicesF[i]]._unidade_tripulada.Hp+=15; 
                    //As cartas em campo, que são tripuladas por pilotos genericos
                    //da federação recebem +15 de vida.
                }


            }
        case 5: //Char Aznable
        //Efeito do Char 
            break;

        case 6:// Dozle Zabi
        //Efeito de Dozle 
            break;

        case 7: //Ramba Ral
            //Efeito do Ramba
            break;

        case 8: //Genérico Zeon
            int nPZ=0; //Contagem de pilotos da federação em campo
            std::vector<int> indicesZ[campo.size()]; //Lista que vai guardar os indices de cartas em campo
                                                    //que são pilotos genéricos da federação
            int k=0; //Variáver usada para percorres o vetor indices
            for(int i=0;i< campo.size();i++){ ///Percorre Campo
                if(campo[i].nome=="Piloto de Zeon"){ //Verifica se é um gerérico da federação
                    nPZ++; //Se sim, contabilizaa em npz
                    indicesZ[k]=i; //Guarda o indice
                    k++; //Aumenta k.
                }
            }

            if(nPZ>=2){ //Se nPF é maior ou igual a 2
                for(int i=0;i<indices.size();i++){ //Percorre indices
                    campo[indices[i]]._unidade_tripulada.Atk+=15; 
                    //As cartas em campo, que são tripuladas por pilotos genericos
                    //de Zeon recebem +15 de ataque.
                }
            }
            break;

        default:
            break;
        }


    }