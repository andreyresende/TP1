#ifndef TRABALHO_TP1_CONTROLADORES_H
#define TRABALHO_TP1_CONTROLADORES_H

#include "interfaces.h"
#include "entidades.h"
#include "dominios.h"
#include <list>
/**
 * @brief Classe Responsavel por funcoes auxiliares usadas durante a implementacao dos controladores
 * 
 */
class Auxiliar : public IFAuxiliares{
public:
    string auxiliar_nome();
    string auxiliar_estado();
    string auxiliar_cidade();
    int auxiliar_classe();
    string auxiliar_faixa_etaria();
    string auxiliar_data();
    string auxiliar_horario();
    int auxiliar_preco();
    int auxiliar_sala();
    int auxiliar_disponibilidade();
};
/**
 * @brief Classe responsavel pelo login e cadastro efetivo no sistema
 * 
 */
class Cadastro : public IUAutenticacao{
private:
    string cpf;
    string senha;
    string numeros_cartoes_de_credito;
    string codigos;
    string datas;
public:
    void autenticar(list <Usuario> &totalUsuarios, string cpf, string senha, string numeros_cartoes_de_credito, string codigos, string datas);
    bool login(string cpf, string senha, Container &container);

};
/**
 * @brief Classe responsavel pela comunicacao entre Usuario e sistema
 * 
 */
class Interface_usuario: public Auxiliar{
private:
    Cadastro cadastro;

public:
    void tela_inicial(Container &container);
    void tela_cadastro(Container &container);
    void tela_login(Container &container);
    void tela_principal(Container &container);
    void tela_adquirir_ingresso(Container &container);
    void tela_cadastro_evento(Container &container);
    void tela_descadastro_evento(Container &container);
    void tela_alteracao_evento(Container &container);
    void tela_relatorio_vendas(Container &container);
    void tela_descadastro_usuario(Container &container);
    void tela_consulta_evento(Container &container);
    bool tela_meus_eventos(Container &container);
};
/**
 * @brief Classe responsavel pelo CRUD dos Eventos
 * 
 */
class CRUDEvento : public ICRiacaoDeEvento, public Interface_usuario{
public:
    void criarEvento(Container &container);
    void editarEvento(Container &container);
    void excluirEvento(Container &container);
    void consultaEvento(Container &container);
};
/**
 * @brief Classe responsavel por remover efetivamente um usuario do sistema
 * 
 */
class RemoveUsuario : IDEscadastroUsuario, public Interface_usuario{
    public:
        void descadastrarUsuario(Container &container);
};
#endif //TRABALHO_TP1_CONTROLADORES_H