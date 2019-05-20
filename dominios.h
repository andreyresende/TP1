#ifndef __DOMINIOS_H__
#define __DOMINIOS_H__

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

class Conversor{
    public:
        char alfabeto_maiusculo[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        char alfabeto_minusculo[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        char espaco = ' ';
        char converte_numero_letra(int numero);
        int converte_letra_numero(char numero);
};

class Codigo_de_evento{
    private:
        string numero;
        string erro_de_evento;

        void valida_Codigo();

    public:
        Codigo_de_evento(){
            numero = "";
            erro_de_evento = "";
        }

        void getCodigo() {
            cout << numero << endl;
        }

        void setCodigo_de_evento(string numero);
};

class Codigo_de_apresentacao{
    private:
        string numero;
        string erro_de_evento;

        void valida_apresentacao();

    public:
        Codigo_de_apresentacao(){
            numero = "";
        }

        void getCodigo(){
            cout << numero << endl;
        }

        void setCodigo_de_apresentacao(string numero);
};

class Codigo_de_ingresso{
    private:
        string numero;
        string erro_de_evento;

        void valida_ingresso();

    public:
        Codigo_de_ingresso(){
            numero = "";
        }

        int getCodigo(){
            cout << numero << endl;
        }

        void setCodigo_de_ingresso(string numero);
};

class Nome_de_evento : private Conversor{
    private:
        //se for 0 vai ser numero, se for 1 vai ser letra minuscula, se for 2 letra maiuscula
        int numero;
        int rand_numero;
        string evento;
        string nome;

        string erro_de_nome;

        void valida_evento(string nome);

    public:
    //analisar retorno depois
        Nome_de_evento(){
            numero = -1;
            rand_numero = -1;
            evento = "";
            nome = "";
            erro_de_nome = "";
        }

        void getNome_de_evento(){
            cout << nome << endl;
        }

        void setNome_de_evento(string nome);
};

class Data : private Conversor{
    private:
        string data;
        string erro_de_data;
        int tamanho;
        int erro_barra;
        int erro_data;
        int data_correta;

        void valida_data(string data);

    public:
        Data(){
            data = "";
            erro_de_data = "";
            tamanho = 8;
            erro_barra = 0;
            erro_data = 0;
            data_correta = 0;
        }

        void getData(){
            cout << data << endl;
        }

        void setData(string data);
};

class Horario{
    private:
        string horario;
        string erro_horario;
        int formato;

        void valida_horario(string horario);
    public:
        Horario(){
            formato = -1;
        }

        void getHorario(){
            cout << horario << endl;
        }

        void setHorario(string horario);
};

class Preco{
    private:
        int preco;
        int erro;
        void valida_preco();

    public:
        Preco(){
            preco = 0;
            erro = 0;
        }

        void getPreco(){
            cout << preco << endl;
        }

        void setPreco(int preco);

};

class Numero_de_sala{
    private:
        int sala;
        int erro;
        void valida_sala();

    public:
        Numero_de_sala(){
            sala = 0;
            erro = 0;
        }

        void getSala(){
            cout << sala << endl;
        }

        void setSala(int sala);
};

class Cidade{
    private:
        string cidade;
        string erro;

        void valida_cidade();
    public:
        Cidade(){
            cidade = "";
            erro = "";
        }

        void getCidade(){
            cout << cidade << endl;
        }

        void setCidade(string cidade);
};

class Estado{
    private:
        string estado;
        string AC;
        string AL;
        string AP;
        string AM;
        string BA;
        string CE;
        string DF;
        string ES;
        string GO;
        string MA;
        string MT;
        string MS;
        string MG;
        string PA;
        string PB;
        string PR;
        string PE;
        string PI;
        string RJ;
        string RN;
        string RS;
        string RO;
        string RR;
        string SC;
        string SP;
        string SE;
        string TO;
        bool erro;

        void valida_Estado();

    public:
        Estado(){
            estado = "";
            AC = "AC";
            AL = "AL";
            AP = "AP";
            AM = "AM";
            BA = "BA";
            CE = "CE";
            DF = "DF";
            ES = "ES";
            GO = "GO";
            MA = "MA";
            MT = "MT";
            MS = "MS";
            MG = "MG";
            PA = "PA";
            PB = "PB";
            PR = "PR";
            PE = "PE";
            PI = "PI";
            RJ = "RJ";
            RN = "RN";
            RS = "RS";
            RO = "RO";
            RR = "RR";
            SC = "SC";
            SP = "SP";
            SE = "SE";
            TO = "TO";
        }

        void getEstado(){
            cout << estado << endl;
        }

        void setEstado(string estado);
};

class Disponibilidade{
    private:
        int disponibilidade;
        bool erro;

        void valida_disponibilidade();

    public:
        Disponibilidade(){
            disponibilidade = -1;
            erro = false;
        }

        void getDisponibilidade(){
            cout << disponibilidade << endl;
        }

        void setDisponibilidade(int disponibilidade);
};

class Classe_de_evento{
    private:
        int numero;
        string escolha;
        bool erro;

        void valida_classe_de_evento();

    public:
        Classe_de_evento(){
            numero = 0;
            erro = false;
        }

        void getClasse_de_evento(){
            cout << escolha << endl;
        }

        void setClasse_de_evento(int numero);
};

class Faixa_etaria{
    private:
        string faixa;
        bool erro;

        void valida_faixa_etaria();
    public:
        Faixa_etaria(){
            faixa = "";
            erro = false;
        }

        void getFaixa_etaria(){
            cout << faixa << endl;
        }

        void setFaixa_etaria(string faixa);

};

class Cpf : private Conversor{
    private:
        int soma;
        int soma2;
        int cpf[11];
        int analisacpf[11];
        int verifica[9];
        int verifica2[10];
        int verificador1;
        int verificador2;
        string cpf_string;
        string erro_tamanho;

        void valida_Cpf();

    public:

        Cpf(){
            soma = 0;
            soma2 = 0;
            erro_tamanho = "";
        }

        void getCpf(){
            int i = 0;
            while(i < 11){
                cout << cpf[i];
                i++;
            }
            cout << endl;
        }

        void setCpf(string cpf_string);
};

class Senha : private Conversor{
    private:
        //se for 0 vai ser numero, se for 1 vai ser letra minuscula, se for 2 letra maiuscula
        string senha;
        string erro_senha;

        void valida_Senha();

    public:
    //analisar retorno depois
        Senha(){
            erro_senha = "";
        }

        void getSenha(){
            int i = 0;
            while(i < senha.length()){
                cout << senha[i];
                i++;
            }
            cout << endl;
        }

        void setSenha(string senha);
};

class Numero_do_cartao_de_credito : private Conversor{
    private:
        string numero_cartao;

        bool erro;

        void valida_cartao();
    public:
        Numero_do_cartao_de_credito(){
            numero_cartao = "";
            erro = false;
        }

        void set_Numero_do_cartao_de_credito(string numero_cartao);
};

class Codigo_de_seguranca{
    private:
        string numero;
        string erro_de_evento;

        void valida_Codigo();

     public:
        Codigo_de_seguranca(){
            numero = "";
            erro_de_evento = "";
        }

        void getCodigo() {
            cout << numero << endl;
        }

        void setCodigo_de_seguranca(string numero);

};

class Data_de_validade{
     private:
        string data_validade;
        bool erro;

        void valida_Data_de_validade();

     public:
        Data_de_validade(){
                data_validade = "";
                erro = false;
        }
        void getData_de_validade() {
                cout<< data_validade << endl;
        }
        void setData_de_validade(string data_validade);
};

#endif
