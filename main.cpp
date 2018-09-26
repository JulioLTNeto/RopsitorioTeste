#include <iostream>
#include "Apartamento.h"
#include "Imovel.h"
#include "SistemaImobiliaria.h"
#include "Endereco.h"
#include <list>

using namespace std;

int main()
{
    Endereco ende = Endereco();
    ende.setBairro("Jardim CID Universitaria");
    ende.setCep("0099898");
    ende.setCidade("JP");
    ende.setLogradouro("Num sei");
    ende.setNumero(406);
    SistemaImobiliaria ut = SistemaImobiliaria();
    Apartamento a = Apartamento();
    Imovel *apt = new Imovel();
    Imovel *aux = apt;

    a.setEndereco(ende);
    a.setTitulo("Titulo");
    a.setImovelTipo(1);
    a.setTipoOferta(1);
    a.setValor(40);
    a.setValorCondominio(88);
    a.setArea(66);
    a.setVagasGaragem(6);
    a.setNumDeQuartos(6);
    a.setPosicao("SUL");
    a.setDescricao();

    *apt = a;
    delete(aux);

    cout << "Hello world!" << endl;
    list<Imovel*> l;
    cout<<ut.pesquisar("Papipapigrafo", "pigra")<<endl;
    cout << ut.maiuscula("Testé") << endl;
    l.push_back(apt);
    l.push_back(apt);
    ut.getGerenciadorPersistencia().salvarImovel(l);
    list<Imovel*> lista = ut.getImoveisPorMenorValorECidade(41, "j");
    for(Imovel* im:lista){
        cout << "Testandoo" << endl;
        cout<<im->getTitulo() << "\n" <<endl;
    }
    return 0;
}
