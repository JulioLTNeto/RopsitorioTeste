#include "Endereco.h"

Endereco::Endereco()
{
    logradouro = "";
    numero = 0;
    bairro = "";
    cidade = "";
    cep = "";
}

void Endereco::setLogradouro(std::string logradouro){
    this->logradouro = logradouro;
}

void Endereco::setNumero(int numero){
    this->numero = numero;
}

void Endereco::setBairro(std::string bairro){
    this->bairro = bairro;
}

void Endereco::setCidade(std::string cidade){
    this->cidade = cidade;
}

void Endereco::setCep(std::string cep){
    this->cep = cep;
}

std::string Endereco::getLogradouro(){
    return logradouro;
}

int Endereco::getNumero(){
    return numero;
}

std::string Endereco::getBairro(){
    return bairro;
}

std::string Endereco::getCidade(){
    return cidade;
}

std::string Endereco::getCep(){
    return cep;
}

Endereco::~Endereco()
{
    //dtor
}
