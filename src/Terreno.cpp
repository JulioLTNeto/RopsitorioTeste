#include "Terreno.h"


Terreno::Terreno()
{
    area = 0;
}

void Terreno::setArea(double area){
    this->area = area;
}

void Terreno::setDescricao(){
    std::stringstream sArea;
    sArea << area;
    descricao = sArea.str();
}

double Terreno::getArea(){
    return area;
}

std::string Terreno::getDescricao(){
    return descricao;
}

Terreno::~Terreno(){
}
