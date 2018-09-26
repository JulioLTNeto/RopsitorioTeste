#ifndef GERENCIADORPERSISTENCIA_H
#define GERENCIADORPERSISTENCIA_H

#include "Imovel.h"
#include <string>
#include <list>

class GerenciadorPersistencia
{
    public:
        GerenciadorPersistencia();
        virtual ~GerenciadorPersistencia();
        void salvarImovel(std::list<Imovel*> lista);
        std::list<Imovel*> recuperaListaImoveis();

    protected:

    private:
};

#endif // GERENCIADORPERSISTENCIA_H
