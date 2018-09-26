#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Imovel.h"
#include <string>
#include <sstream>

class Apartamento : public Imovel
{
    public:
        Apartamento();
        virtual ~Apartamento();

        void setPosicao(std::string posicao);
        void setNumDeQuartos(int numDeQuartos);
        void setValorCondominio(double valorCondominio);
        void setVagasGaragem(int vagastGaragem);
        void setArea(double area);

        std::string getPosicao();
        void setDescricao();
        int getNumDeQuartos();
        double getValorCondominio();
        int getVagasGaragem();
        double getArea();
        std::string getDescricao();

    protected:

    private:
        std::string posicao;
        int numDeQuartos;
        double valorCondominio;
        int vagasGaragem;
        double area;

};
#endif // APARTAMENTO_H
