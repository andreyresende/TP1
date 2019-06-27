#ifndef _DOMINIOS_H_
#define _DOMINIOS_H_

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
    bool erro_de_evento;

        bool valida_Codigo(string numero);

public:
    Codigo_de_evento(){
        numero = "";
        erro_de_evento = false;
    }

    string getCodigo() {
        return numero;
    }

    bool setCodigo_de_evento(string numero);
};

class Codigo_de_apresentacao{
private:
    string numero;
    bool erro;

    bool valida_apresentacao(string numero);

public:
    Codigo_de_apresentacao(){
        numero = "";
        erro = false;
    }

    string getCodigo(){
        return numero;
    }

    bool setCodigo_de_apresentacao(string numero);
};

class Codigo_de_ingresso{
private:
    string numero;
    bool erro;

    bool valida_ingresso(string numero);

public:
    Codigo_de_ingresso(){
        numero = "";
        erro = false;
    }

    string getCodigo(){
        return numero;
    }

    bool setCodigo_de_ingresso(string numero);
};

class Nome_de_evento : private Conversor{
    private:
        //se for 0 vai ser numero, se for 1 vai ser letra minuscula, se for 2 letra maiuscula
        int numero;
        int rand_numero;
        string evento;
        string nome;

        bool erro_de_nome;

        bool valida_evento(string nome);

    public:
        Nome_de_evento(){
            numero = -1;
            rand_numero = -1;
            evento = "";
            nome = "";
            erro_de_nome = false;
        }

        string getNome_de_evento(){
            return nome;
        }
        bool setNome_de_evento(string nome);
};

class Data : private Conversor{
    private:
        string data;
        string erro_de_data;
        int tamanho;
        int erro_barra;
        bool erro_data;
        int data_correta;

        bool valida_data(string data);
        
    public:
        Data(){
            data = "";
            erro_de_data = "";
            tamanho = 8;
            erro_barra = 0;
            erro_data = false;
            data_correta = 0;
        }

        string getData(){
            return data;
        }

        bool setData(string data);        
};

class Horario{
    private:
        string horario;
        bool erro_horario;
        int formato;

        bool valida_horario(string horario);
    public:
        Horario(){
            formato = -1;
            erro_horario = false;
        }

        string getHorario(){
            return horario;
        }

        bool setHorario(string horario);
};

class Preco{
    private:
        int preco;
        bool erro;
        bool valida_preco(int preco);

public:
    Preco(){
        preco = 0;
        erro = false;
    }

    int getPreco(){
        return preco;
    }

        bool setPreco(int preco);
};

class Numero_de_sala{
    private:
        int sala;
        bool erro;
        bool valida_sala(int sala);

    public:
        Numero_de_sala(){
            sala = 0;
            erro = false;
        }

        int getSala(){
            return sala;
        }

        bool setSala(int sala);
};

class Cidade{
    private:
        string cidade;
        bool erro;

        bool valida_cidade(string cidade);
    public:
        Cidade(){
            cidade = "";
            erro = false;
        }

        string getCidade(){
            return cidade;
        }

        bool setCidade(string cidade);
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

        bool valida_Estado(string estado);

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
            erro = false;
        }

        string getEstado(){
            return estado;
        }

        bool setEstado(string estado);
};

class Disponibilidade{
private:
    int disponibilidade;
    bool erro;

        bool valida_disponibilidade(int disponibilidade);

public:
    Disponibilidade(){
        disponibilidade = -1;
        erro = false;
    }

    int getDisponibilidade(){
        return disponibilidade;
    }


        bool setDisponibilidade(int disponibilidade);
};

class Classe_de_evento{
private:
    int numero;
    string escolha;
    bool erro;

        bool valida_classe_de_evento(int numero);

public:
    Classe_de_evento(){
        numero = 0;
        erro = false;
    }

    int getClasse_de_evento(){
        return numero;
    }

        bool setClasse_de_evento(int numero);
};

class Faixa_etaria{
private:
    string faixa;
    bool erro;

        bool valida_faixa_etaria(string faixa);
    public:
        Faixa_etaria(){
            faixa = "";
            erro = false;
        }

    string getFaixa_etaria(){
        return faixa;
    }

        bool setFaixa_etaria(string faixa);
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
        bool erro_tamanho;

        bool valida_Cpf(string cpf_string);
        
    public:

        Cpf(){
            soma = 0;
            soma2 = 0;
            erro_tamanho = false;
        }

        string getCpf(){
            return cpf_string;
        }

        bool setCpf(string cpf_string);
};

class Senha : private Conversor{
    private:
        //se for 0 vai ser numero, se for 1 vai ser letra minuscula, se for 2 letra maiuscula
        string senha;
        bool erro_senha;

        bool valida_Senha(string senha);
        
    public:
        Senha(){
            erro_senha = false;
        }

        string getSenha(){
            return senha;
        }

        bool setSenha(string senha);
};

class Numero_do_cartao_de_credito : private Conversor{
    private:
        string numero_cartao;
        bool erro;

        bool valida_cartao(string numero_cartao);
    public:
        Numero_do_cartao_de_credito(){
            numero_cartao = "";
            erro = false;
        }

        string get_Numero_do_cartao_de_credito(){
            return numero_cartao;
        }

        bool set_Numero_do_cartao_de_credito(string numero_cartao);
};

class Codigo_de_seguranca{
private:
    string numero;
    bool erro_de_evento;

    bool valida_Codigo(string numero);

public:
    Codigo_de_seguranca(){
        numero = "";
        erro_de_evento = false;
    }

    string getCodigo() {
        return numero;
    }

        bool setCodigo_de_seguranca(string numero);
};

class Data_de_validade{
     private:
        string data_validade;
        bool erro;

        bool valida_Data_de_validade(string data_validade);

     public:
        Data_de_validade(){
                data_validade = "";
                erro = false;
        }
        string getData_de_validade() {
                return data_validade;
        }
        bool setData_de_validade(string data_validade);
};

#endif