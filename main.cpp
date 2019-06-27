#include "testes.h"
#include <list>
#include "interfaces.h"
#include "controladores.h"

using namespace std;

void populate(Container &container){
    Cadastro cadastro;
    cadastro.autenticar(container.totalUsuarios, "06762463118", "1mM23", "5555666677778884", "143", "09/23");
    container.totalUsuarios.front().adicionarEvento(container.quantidade_eventos, container.totalEventos, "Show fulano", "DF", "Brasilia", 4, "L");
    container.totalUsuarios.front().eventos.front().adicionarApresentacao(container.quantidade_apresentacoes, container.totalEventos, container.totalApresentacoes, "18/06/19", "18:00", 150, 5, 250);
    container.totalUsuarios.front().eventos.front().adicionarApresentacao(container.quantidade_apresentacoes, container.totalEventos, container.totalApresentacoes, "21/05/19", "15:00", 100, 2, 205);
    cadastro.autenticar(container.totalUsuarios, "31914340116", "1mM23", "5555666677778884", "123", "11/27");
    container.totalUsuarios.front().adicionarEvento(container.quantidade_eventos, container.totalEventos, "Mamonas", "DF", "Brasilia", 3, "12");
    container.totalUsuarios.front().eventos.front().adicionarApresentacao(container.quantidade_apresentacoes, container.totalEventos, container.totalApresentacoes, "20/07/19", "18:00", 112, 3, 223);   
}


int main(){
    Container container;
    populate(container);

    Interface_usuario interface_usuario;
    interface_usuario.tela_inicial(container);

    return 0;
}