#ifndef TERRENO_H
#define TERRENO_H

#include "Imovel.h"
#include <string>
#include <sstream>

class Terreno : public Imovel
{
    public:
        Terreno();
        virtual ~Terreno();

        void setArea(double area);
        void setDescricao();

        double getArea();
        std::string getDescricao();

    protected:

    private:
        double area;
};

#endif // TERRENO_H
