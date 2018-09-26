#ifndef CASA_H
#define CASA_H

#include "Imovel.h"
#include <string>
#include <sstream>

class Casa : public Imovel
{
    public:
        Casa();
        virtual ~Casa();

        void setPosicao(std::string posicao);
        void setNumDeQuartos(int numDeQuartos);
        void setNumDePavimentos(int numDePavimentos);
        void setAreaTerreno(double areaTerreno);
        void setAreaConstruida(double areaConstruida);
        void setDescricao();

        std::string getPosicao();
        int getNumDeQuartos();
        int getNumDePavimentos();
        double getAreaTerreno();
        double getAreaConstruida();
        std::string getDescricao();

    protected:

    private:
        std::string posicao;
        int numDeQuartos, numDePavimentos;
        double areaTerreno, areaConstruida;
};

#endif // CASA_H
