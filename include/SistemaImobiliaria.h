#ifndef SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_H

#include "Imovel.h"
#include <list>
#include "GerenciadorPersistencia.h"

class SistemaImobiliaria
{
    public:
        SistemaImobiliaria();
        virtual ~SistemaImobiliaria();
        void cadastrarImovel(Imovel *imovel);
        std::list<Imovel*> getImoveis();
        std::list<Imovel*> getImoveisPorMaiorValorECidade(double valor, std::string cidade);
        std::list<Imovel*> getImoveisPorMenorValorECidade(double valor, std::string cidade);
        std::list<Imovel*> getImoveisPorMenorValor(double valor);
        std::list<Imovel*> getImoveisPorMaiorValor(double valor);
        std::list<std::string> getDescricao();
        std::list<Imovel*> getImoveisPorTipo(int tipo);
        std::list<Imovel*> getImoveisParaAlugarPorBairro(std::string bairro);
        std::list<Imovel*> getImoveisParaVenderPorBairro(std::string bairro);
        std::list<Imovel*> getImoveisPorCidade(std::string cidade);
        GerenciadorPersistencia getGerenciadorPersistencia();
        char retirarCaracteres(char caracter);
        std::string maiuscula(std::string texto);
        bool pesquisar(std::string palavra1, std::string palavra2);

    protected:

    private:
        std::list<Imovel*> lista;
        GerenciadorPersistencia gerenciador;
};

#endif // SISTEMAIMOBILIARIA_H
