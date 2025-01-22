   #include "Piloto.h"
   #include "Carta.h
   
   
   
   Piloto :: Piloto(std::string _efeito_piloto, Unidade _unidade_tripulada, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID)
    :Carta(_Desc, _Tipo, _Nome, _Custo, _ID),//Chama o construtor da superclasse
    unidade_tripulada(_unidade_tripulada),//Unidade do piloto
    efeito_piloto(_efeito_piloto){ //Efeito do piloto
    }

    ~Piloto(){
        //Nada no destrutor, sem alocação dinâmica
    }

    void fornece_efeito() override{

    }