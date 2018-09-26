#include "Imovel.h"
#include "Apartamento.h"

Imovel::Imovel()
{
   tipoDeOferta = 0;
   imovelTipo = 0;
   valor = 0;

}

void Imovel::setImovelTipo(int escolha){
    this->imovelTipo = escolha;
}

void Imovel::setValor(double valor){
    this->valor = valor;
}

void Imovel::setTipoOferta(int tipoDeOferta){
    this->tipoDeOferta = tipoDeOferta;
}

void Imovel::setEndereco(Endereco endereco){
    this->endereco = endereco;
}

int Imovel::getImovelTipo(){
    return imovelTipo;
}

double Imovel::getValor(){
    return valor;
}

int Imovel::getTipoDeferta(){
    return tipoDeOferta;
}

std::string Imovel::getDescricao(){
    return descricao;
}

void Imovel::setDescricao(std::string descricao){
    this->descricao = descricao;
}

void Imovel::setTitulo(std::string titulo){
    this->titulo = titulo;
}

std::string Imovel::getTitulo(){
    return titulo;
}

Endereco Imovel::getEndereco(){
    return endereco;
}

Imovel::~Imovel()
{
    //dtor
}
