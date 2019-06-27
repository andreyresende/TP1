#ifndef __INTERFACES_H__
#define __INTERFACES_H__
#include "dominios.h"
#include "entidades.h"
#include <list>

using namespace std;
/**
 * @brief Interface que realiza a comunicacao entre o banco de dados, armazenado em memoria RAM e o programa em si 
 * 
 */
class Container{
private:

public:
    list <Usuario> totalUsuarios;//Armazena todos os usuarios
    list <Evento*> totalEventos;//Armazena todos os eventos, e cada evento tambem armazena suas respectivas apresentacoes
    list <Apresentacao*> totalApresentacoes;//Armazena todas as apresentacoes
    int quantidade_apresentacoes;
    int quantidade_eventos;
    int eventos_apagados;
    int apresentacoes_apagadas;
    Usuario *logado;
    Container(){
        quantidade_eventos       = 0;
        quantidade_apresentacoes = 0;
        eventos_apagados         = 0;
        apresentacoes_apagadas   = 0;
    }
};
/**
 * @brief Interface de Autenticacao de Usuario
 * 
 */
class IUAutenticacao{
    virtual void autenticar(list <Usuario> &totalUsuarios, string cpf, string senha, string numeros_cartoes_de_credito, string codigos, string datas) = 0;
    virtual bool login(string cpf, string senha, Container &container) = 0;
};
/**
 * @brief Interface de Criacao de Eventos do sistema
 * 
 */
class ICRiacaoDeEvento{
    public:
        virtual void criarEvento(Container &container) = 0;
        virtual void editarEvento(Container &container) = 0;
        virtual void excluirEvento(Container &container) = 0;
        virtual void consultaEvento(Container &container) = 0;
};
/**
 * @brief Interface de Descadastro de Usuario do sistema
 * 
 */
class IDEscadastroUsuario{
    public:
        virtual void descadastrarUsuario(Container &container) = 0;
};
/**
 * @brief Interface de Funcoes Auxiliares para os controladores
 * 
 */
class IFAuxiliares{
    public:
    virtual int auxiliar_classe() = 0;
    virtual int auxiliar_preco() = 0;
    virtual int auxiliar_sala() = 0;
    virtual int auxiliar_disponibilidade() = 0;
};

#endif