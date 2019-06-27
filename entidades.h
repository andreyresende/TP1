#ifndef __ENTIDADES_H__
#define __ENTIDADES_H__

#include "dominios.h"
#include <list>



/**
 * Acrescentar aqui a disponibilidade em apresentacao
 * 
 */
class Apresentacao{
    private:
        Codigo_de_apresentacao codigo_de_apresentacao;
        Data data;
        Horario horario;
        Preco preco;
        Numero_de_sala sala;
        Disponibilidade disponibilidade;
        list<Cpf> compradores;
    public:
        bool apagado;
        int quantidade_original;
        Evento(){
            apagado = false;
            quantidade_original = 0;
        }
        void setApresentacao(string codigo_de_apresentacao, string data, string horario, int preco, int sala, int disponibilidade);
        void adicionarCompradores(string cpf);
        string getCodigo_de_apresentacao();
        string getData();
        string getHorario();
        int getPreco();
        int getSala();
        int getDisponibilidade();
        Apresentacao* getApresentacao(){ return this;}
        void vender(int quantidade);
        void listarCpf();
};

class Evento{
    private:
        Codigo_de_evento codigo_de_evento;
        Nome_de_evento nome_de_evento;
        Cidade cidade;
        Estado estado;
        Classe_de_evento classe_de_evento;
        Faixa_etaria faixa_etaria;
    public:
        list <Apresentacao> apresentacoes;
        int quantidade;
        bool apagado;
        Evento(){
            quantidade = 0;
            apagado    = false;
        }
        void setEvento(string codigo_de_evento, string nome_de_evento, string estado, string cidade, int classe_de_evento, 
                       string faixa_etaria);
        void adicionarApresentacao(int &quantidade_apresentacoes, list<Evento*> &totalEventos, list <Apresentacao*> &totalApresentacoes, string data, string horario, int preco,
                                   int sala, int disponibilidade);
        void listarApresentacoes();
        string getCodigo_de_evento();
        string getNome_de_evento();
        string getCidade();
        string getEstado();
        int getClasse_de_evento();
        string getFaixa_etaria();
        Evento* getEvento(){ return this;}
};

class Ingresso{
    private:
        Codigo_de_ingresso codigo_de_ingresso;
        string cod_ingressos;
    public:
        Ingresso(){
            cod_ingressos = "" ;
        }
        void setIngresso(string cod_ingressos);
};

/**
 * @brief A classe Usuario serve para o cadastro e login de novo usuario no sistema, informando Cpf e senha
 * 
 */
class Usuario{
    private:
        Cpf cpf;
        Senha senha;
        Numero_do_cartao_de_credito numero_do_cartao_de_credito;
        Codigo_de_seguranca codigo_de_seguranca;
        Data_de_validade data_de_validade;
    public:
        list <Evento> eventos;
        int quantidade;
        bool apagado;
    Usuario(){
            quantidade = 0;
            apagado = false;
        }
        bool setUsuario(string cpf, string senha, string numero_do_cartao_de_credito, string codigo_de_seguranca, string data_de_validade);
        void adicionarEvento(int &quantidade_eventos, list <Evento*> &totalEventos, string nome_de_evento, string estado, string cidade,
                             int classe_de_evento, string faixa_etaria);
        string getCpf();
        string getSenha();
        string getNumero_do_cartao_de_credito();
        string getCodigo_de_seguranca();
        string getData_de_validade();
        Usuario* getUsuario(){ return this;}
};
#endif