#ifndef __ENTIDADES_H__
#define __ENTIDADES_H__

#include "dominios.h"
/**
 * @brief A classe Usuario serve para o cadastro e login de novo usuario no sistema, informando Cpf e senha
 * 
 */
class Usuario{
    private:
        Cpf cpf_usuario;
        Senha senha_usuario;
        string cpf_string;
        string senha;
    public:
        Usuario(){
            cpf_string = "";
            senha = "";
        }
        //a ser implementado na versao final do trabalho
        //void loga_ou_cadastra();

        int setUsuario(string cpf_string, string senha);

        //int loga_usuario();
};

class Evento{
    private:
        Codigo_de_evento codigo_de_evento;
        Nome_de_evento nome_de_evento;
        Cidade cidade;
        Estado estado;
        Classe_de_evento classe_de_evento;
        Faixa_etaria faixa_etaria;
        string cod_eventos;
        string nome_eventos;
        string cidades;
        string estados;
        int classe_eventos;
        string faixas;

    public:
        Evento(){
            cod_eventos = "";
            nome_eventos = "";
            cidades = "";
            estados = "";
            classe_eventos = 0;
            faixas = "";
        }

        void setEvento(string cod_eventos, string nome_eventos, string cidades, string estados, int classe_eventos, string faixas){
            this->cod_eventos = cod_eventos;
            this->nome_eventos = nome_eventos;
            this->cidades = cidades;
            this->estados = estados;
            this->classe_eventos = classe_eventos;
            this->faixas = faixas;
            
            codigo_de_evento.setCodigo_de_evento(cod_eventos);
            nome_de_evento.setNome_de_evento(nome_eventos);
            cidade.setCidade(cidades);
            estado.setEstado(estados);
            classe_de_evento.setClasse_de_evento(classe_eventos);
            faixa_etaria.setFaixa_etaria(faixas);
        }

};
/**
 * Acrescentar aqui a disponibilidade em apresentacao
 * 
 */
class Apresentacao{
    private:
        Codigo_de_apresentacao apresentacao;
        Data data;
        Horario horario;
        Preco preco;
        Numero_de_sala sala;
        Disponibilidade disponibilidade;
        string string_numero;
        string string_data;
        string string_horario;
        int int_preco;
        int int_sala;
        int int_disponibilidade;

    public:
        Apresentacao(){
            string_numero = "";
            string_data = "";
            string_horario = "";
            int_preco = -1;
            int_sala = -1;
            int_disponibilidade = -1;
        }

        void setApresentacao(string string_numero, string string_data, string string_horario, int int_preco, int int_sala, int int_disponibilidade);
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

class Cartao_de_credito{
    private:
        Numero_do_cartao_de_credito numero_do_cartao_de_credito;
        Codigo_de_seguranca codigo_de_seguranca;
        Data_de_validade data_de_validade;
        string numeros_cartoes_de_credito;
        string codigos;
        string datas;
    public:
        Cartao_de_credito(){
            numeros_cartoes_de_credito = "";
            codigos = "";
            datas = "";
        }
        void setCartao_de_credito(string numeros_cartoes_de_credito, string codigos, string datas);
};

#endif