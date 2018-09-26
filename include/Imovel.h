#ifndef IMOVEL_H
#define IMOVEL_H

#include "Endereco.h"
#include <string>

class Imovel
{
    public:
        Imovel();
        virtual ~Imovel();

        void setImovelTipo(int escolha);
        void setValor(double valor);
        void setTipoOferta(int tipoDeOferta);
        void setEndereco(Endereco endereco);

        int getImovelTipo();
        double getValor();
        int getTipoDeferta();
        Endereco getEndereco();
        void setDescricao(std::string descricao);
        void setTitulo(std::string titulo);
        std::string getTitulo();
        void setDescricao();
        std::string getDescricao();

    protected:
        int imovelTipo;
        double valor;
        int tipoDeOferta;
        std::string descricao;
        std::string titulo;
        Endereco endereco;

    private:
};

#endif // IMOVEL_H
