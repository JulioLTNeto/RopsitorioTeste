#include "Casa.h"

Casa::Casa()
{
    posicao = "";
    numDeQuartos = numDePavimentos = 0;
    areaTerreno = areaConstruida = 0;
}

void Casa::setPosicao(std::string posicao){
    this->posicao = posicao;
}

void Casa::setNumDeQuartos(int numDeQuartos){
    this->numDeQuartos = numDeQuartos;
}

void Casa::setNumDePavimentos(int numDePavimentos){
    this->numDePavimentos = numDePavimentos;
}

void Casa::setAreaTerreno(double areaTerreno){
    this->areaTerreno = areaTerreno;
}

void Casa::setAreaConstruida(double areaConstruida){
    this->areaConstruida = areaConstruida;
}

void Casa::setDescricao(){
    std::stringstream sPavimentos, sQuartos;
    std::stringstream sConstruida, sTerreno;
    sPavimentos << numDePavimentos;
    sQuartos << numDeQuartos;
    sConstruida << areaConstruida;
    sTerreno << areaTerreno;
    descricao = posicao + "/" + sPavimentos.str() + "/" + sQuartos.str() + "/" + sConstruida.str() + "/" + sTerreno.str();
}

std::string Casa::getPosicao(){
    return posicao;
}

int Casa::getNumDeQuartos(){
    return numDeQuartos;
}

int Casa::getNumDePavimentos(){
    return numDePavimentos;
}

double Casa::getAreaTerreno(){
    return areaTerreno;
}

double Casa::getAreaConstruida(){
    return areaConstruida;
}

std::string Casa::getDescricao(){
    return descricao;
}

Casa::~Casa(){
}
