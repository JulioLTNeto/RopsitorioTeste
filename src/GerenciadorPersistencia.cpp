#include "GerenciadorPersistencia.h"
#include <fstream>
#include "Endereco.h"
#include "Apartamento.h"
#include "Casa.h"
#include "Terreno.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

GerenciadorPersistencia::GerenciadorPersistencia()
{
    //ctor
}

void GerenciadorPersistencia::salvarImovel(list<Imovel*> lista){
    ofstream arq;
    arq.open("imovel.txt");
    int totalCadastrados = 0;
    for(Imovel *imovel:lista){
        arq<<imovel->getDescricao() << "\n";
        arq<<imovel->getTitulo() << "\n";
        arq<<imovel->getEndereco().getBairro() << "\n";
        arq<<imovel->getEndereco().getCep() << "\n";
        arq<<imovel->getEndereco().getCidade() << "\n";
        arq<<imovel->getEndereco().getLogradouro() << "\n";
        arq<<imovel->getEndereco().getNumero() << "\n";
        arq<<imovel->getImovelTipo() << "\n";
        arq<<imovel->getTipoDeferta() << "\n";
        arq<<imovel->getValor() << "\n";
        totalCadastrados++;
     }
    arq.close();
    ofstream conf;
    conf.open("imovel_Cfg.txt");
    conf<<totalCadastrados;
    conf.close();
}

list<Imovel*> GerenciadorPersistencia::recuperaListaImoveis(){
    ifstream arqCfg;
    arqCfg.open("imovel_Cfg.txt");

    int totalInt;
    string total;

    getline(arqCfg, total);
    stringstream totalStream(total);
    totalStream>>totalInt;

    list<Imovel*> imoveis;
    ifstream arquivo;
    arquivo.open("imovel.txt");

    int cont;

    for(cont = 0; cont < totalInt; cont++){

        Imovel *imovel = new Imovel();

        Endereco en = Endereco();
        string descricao;
        string tipoImovel;
        string valor;
        string tipoOferta;
        string bairro;
        string cidade;
        string logradouro;
        string cep;
        string numero;
        string titulo;

        getline(arquivo, descricao);
        getline(arquivo, titulo);
        getline(arquivo, bairro);
        getline(arquivo, cep);
        getline(arquivo, cidade);
        getline(arquivo, logradouro);
        getline(arquivo, numero);
        getline(arquivo, tipoImovel);
        getline(arquivo, tipoOferta);
        getline(arquivo, valor);

        if(tipoImovel == "1"){
            imovel = new Apartamento();
        }
        else if(tipoImovel == "2"){
            //imovel = new Casa();
        }
        else if(tipoImovel == "3"){
            //imovel = new Terreno();
        }else{
        }

        int n;
        int tI;
        int tO;
        double v;

        stringstream num(numero);
        num>>n;
        stringstream tipoI(tipoImovel);
        tipoI>>tI;
        stringstream tipoO(tipoOferta);
        tipoO>>tO;
        stringstream val(valor);
        val>>v;

        imovel->setDescricao(descricao);
        imovel->setTitulo(titulo);
        en.setBairro(bairro);
        en.setCep(cep);
        en.setCidade(cidade);
        en.setLogradouro(logradouro);
        en.setNumero(n);
        imovel->setEndereco(en);
        imovel->setImovelTipo(tI);
        imovel->setTipoOferta(tO);
        imovel->setValor(v);

        imoveis.push_back(imovel);

    }
    arquivo.close();
    return imoveis;
}

GerenciadorPersistencia::~GerenciadorPersistencia()
{
    //dtor
}
