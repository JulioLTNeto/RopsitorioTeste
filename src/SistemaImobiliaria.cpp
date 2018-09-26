#include "SistemaImobiliaria.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

SistemaImobiliaria::SistemaImobiliaria()
{
    gerenciador = GerenciadorPersistencia();
    lista = gerenciador.recuperaListaImoveis();
}

GerenciadorPersistencia SistemaImobiliaria::getGerenciadorPersistencia(){
    return gerenciador;
}

void SistemaImobiliaria::cadastrarImovel(Imovel *imovel){
    lista.push_back(imovel);
}

std::list<std::string> SistemaImobiliaria::getDescricao(){
    std::list<std::string> lis;
    int cont = 0;
    for(Imovel *im:lista){
        std::string desc = "Este(a) ";
        if(im->getImovelTipo() == 1){
            desc = desc + " apartamento";
        }
        if(im->getImovelTipo() == 2){
            desc = desc + " casa";
        }
        if(im->getImovelTipo() == 3){
            desc = desc + " terreno";
        }
        desc = desc + " está locarizado no bairro:" + im->getEndereco().getBairro() + "\nNa cidade:" + im->getEndereco().getCidade() + "\nEle esta disponivel para ";
        if(im->getTipoDeferta() == 1){
            desc = desc + " alugar";
        }
        else{
            desc = desc + " vender";
        }
        if(im->getImovelTipo()==1){

            int intervalo = 0;

            int tamanhoDescricao = im->getDescricao().length();
            int cont;
            desc = desc + "\nPosicionado ao ";

            string numeroDeQuartos;
            string valorCondominio;
            string vagasGaragem;
            string area;

            for(cont = 0; cont < tamanhoDescricao; cont++){
                if(im->getDescricao()[cont] == '/'){
                    intervalo++;
                    continue;
                }
                if(intervalo == 0){
                    desc = desc + im->getDescricao()[cont];
                }
                if(intervalo == 1){
                    numeroDeQuartos = numeroDeQuartos+im->getDescricao()[cont];
                }
                if(intervalo == 2){
                    valorCondominio = valorCondominio+im->getDescricao()[cont];
                }
                if(intervalo == 3){
                    vagasGaragem = vagasGaragem+im->getDescricao()[cont];
                }
                if(intervalo == 4){
                    area = area+im->getDescricao()[cont];
                }
            }
            desc = desc + "\ncom " + numeroDeQuartos + " quarto(s), \ncustando o condominio R$" + valorCondominio + " mensais\nO apartamento tem " + vagasGaragem + " vaga(s) na garagem, e tendo uma area total de " + area + " metros quadrados";
        }
        lis.push_back(desc);
    }
    return lis;
}

std::list<Imovel*> SistemaImobiliaria::getImoveisPorTipo(int tipo){
    list<Imovel*> imoveis;
    for(Imovel *im:lista){
        if(tipo==im->getImovelTipo()){
            imoveis.push_back(im);
        }
    }
}

std::list<Imovel*> SistemaImobiliaria::getImoveisParaAlugarPorBairro(string bairro){
    list<Imovel*> l;
    for(Imovel *imovel:lista){
        if(pesquisar(imovel->getEndereco().getBairro(), bairro) == true && imovel->getTipoDeferta() == 1){
            l.push_back(imovel);
        }
    }
    return l;
}

std::list<Imovel*> SistemaImobiliaria::getImoveisPorCidade(string cidade){
    list<Imovel*> l;
    for(Imovel *imovel:lista){
        if(pesquisar(imovel->getEndereco().getCidade(), cidade) == true){
            l.push_back(imovel);
        }
    }
    return l;
}

std::list<Imovel*> SistemaImobiliaria::getImoveisParaVenderPorBairro(string bairro){
    list<Imovel*> l;
    for(Imovel *imovel:lista){
        if(pesquisar(imovel->getEndereco().getBairro(), bairro) == true && imovel->getTipoDeferta() == 2){
            l.push_back(imovel);
        }
    }
    return l;
}


std::list<Imovel*> SistemaImobiliaria::getImoveis(){
    return lista;
}

std::list<Imovel*> SistemaImobiliaria::getImoveisPorMenorValorECidade(double valor, string cidade){
    list<Imovel*> lis;

    for(Imovel* imovel:lista){
        if(imovel->getValor()<=valor && pesquisar(imovel->getEndereco().getCidade(), cidade)){
            lis.push_back(imovel);
        }
    }

    return lis;
}

std::list<Imovel*> SistemaImobiliaria::getImoveisPorMenorValor(double valor){
    list<Imovel*> lis;

    for(Imovel* imovel:lista){
        if(imovel->getValor()<=valor){
            lis.push_back(imovel);
        }
    }

    return lis;
}

std::list<Imovel*> SistemaImobiliaria::getImoveisPorMaiorValor(double valor){
    list<Imovel*> lis;

    for(Imovel* imovel:lista){
        if(imovel->getValor()>=valor){
            lis.push_back(imovel);
        }
    }

    return lis;
}

std::list<Imovel*> SistemaImobiliaria::getImoveisPorMaiorValorECidade(double valor, string cidade){
    list<Imovel*> lis;

    for(Imovel* imovel:lista){
        if(imovel->getValor()>=valor && pesquisar(imovel->getEndereco().getCidade(), cidade)){
            lis.push_back(imovel);
        }
    }

    return lis;
}

bool SistemaImobiliaria::pesquisar(string palavra1, string palavra2){
    int tamanho1 = palavra1.length();
    int tamanho2 = palavra2.length();
    int cont;
    palavra1 = maiuscula(palavra1);
    palavra2 = maiuscula(palavra2);
    if(tamanho2>tamanho1){
        return false;
    }
    bool achou = true;
    int cc;
    for(cc=0; cc<tamanho1; cc++){
        if((tamanho1-tamanho2)>=cc){
            achou = true;
            for(cont = 0; cont < tamanho2; cont++){
                if(palavra2[cont] != palavra1[cc+cont]){
                    achou = false;
                }
            }
            if(achou){
                break;
            }
        }
    }
    return achou;
}

std::string SistemaImobiliaria::maiuscula(string texto){
    int tamanho = texto.length();
    int cont;
    for(cont = 0; cont < tamanho; cont++){
        texto[cont] = retirarCaracteres(texto[cont]);
        texto[cont] = toupper(texto[cont]);
    }
    return texto;
}

char SistemaImobiliaria::retirarCaracteres(char caracter){

    if(caracter == 'é' || caracter == 'è' || caracter == 'ê' || caracter == 'ẽ' || caracter == 'É' || caracter == 'È' || caracter == 'Ê' || caracter == 'Ẽ'){
            caracter = 'E';
    }
    if(caracter == 'í' || caracter == 'ì' || caracter == 'î' || caracter == 'ĩ' || caracter == 'Í' || caracter == 'Ì' || caracter == 'Î' || caracter == 'Ĩ'){
            caracter = 'I';
    }
    if(caracter == 'ó' || caracter == 'ò' || caracter == 'ô' || caracter == 'õ' || caracter == 'Ó' || caracter == 'Ò' || caracter == 'Ô' || caracter == 'Õ'){
            caracter = 'O';
    }
    if(caracter == 'ú' || caracter == 'ù' || caracter == 'û' || caracter == 'ũ' || caracter == 'Ú' || caracter == 'Ù' || caracter == 'Û' || caracter == 'Ũ'){
            caracter = 'U';
    }
    if(caracter == 'ń' || caracter == 'ǹ' || caracter == 'ñ' || caracter == 'Ń' || caracter == 'Ǹ' || caracter == 'Ñ'){
            caracter = 'N';
    }
     return caracter;
}

SistemaImobiliaria::~SistemaImobiliaria()
{
    //dtor
}
