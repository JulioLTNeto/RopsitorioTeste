#include "Apartamento.h"
#include <iostream>

Apartamento::Apartamento()
{
    posicao = "";
    numDeQuartos = 0;
    valorCondominio = 0;
    vagasGaragem = 0;
    area = 0;
}

void Apartamento::setPosicao(std::string posicao){
    this->posicao = posicao;
}

void Apartamento::setNumDeQuartos(int numDeQuartos){
    this->numDeQuartos = numDeQuartos;
}

void Apartamento::setValorCondominio(double valorCondominio){
    this->valorCondominio = valorCondominio;
}

void Apartamento::setVagasGaragem(int vagasGaragem){
    this->vagasGaragem = vagasGaragem;
}

void Apartamento::setArea(double area){
    this->area = area;
}

std::string Apartamento::getPosicao(){
    return posicao;
}

int Apartamento::getNumDeQuartos(){
    return numDeQuartos;
}

std::string Apartamento::getDescricao(){
    return descricao;
}

void Apartamento::setDescricao(){
    std::stringstream numD;
    std::stringstream valorC;
    std::stringstream vagasG;
    std::stringstream areaD;
    numD << numDeQuartos;
    valorC<<valorCondominio;
    vagasG<<vagasGaragem;
    areaD<<area;
    descricao = posicao + "/" + numD.str() + "/" + valorC.str() + "/" + vagasG.str() + "/" + areaD.str();
}

double Apartamento::getValorCondominio(){
    return valorCondominio;
}

int Apartamento::getVagasGaragem(){
    return vagasGaragem;
}

double Apartamento::getArea(){
    return area;
}

Apartamento::~Apartamento()
{
    //dtor
}
