#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <exception>
#include "dominios.h"

//Codigos referentes ao conversor
char Conversor::converte_numero_letra(int numero){
    if(numero == 0) return '0';
    else if(numero == 1) return '1';
    else if(numero == 2) return '2';
    else if(numero == 3) return '3';
    else if(numero == 4) return '4';
    else if(numero == 5) return '5';
    else if(numero == 6) return '6';
    else if(numero == 7) return '7';
    else if(numero == 8) return '8';
    else if(numero == 9) return '9';
}

int Conversor::converte_letra_numero(char numero){
    if(numero == '0') return 0;
    else if(numero == '1') return 1;
    else if(numero == '2') return 2;
    else if(numero == '3') return 3;
    else if(numero == '4') return 4;
    else if(numero == '5') return 5;
    else if(numero == '6') return 6;
    else if(numero == '7') return 7;
    else if(numero == '8') return 8;
    else if(numero == '9') return 9;
}
//fim dos codigos do conversor
/**
 * @brief Essa funcao e responsavel por validar o codigo de evento do programa
 *
 */
void Codigo_de_evento::valida_Codigo(){
    int certo = 0;
    try{
        if(numero.length() == 3){
            for(int i = 0; i < numero.length(); i++){
                if(numero[i] == '0' || numero[i] == '1' || numero[i] == '2' || numero[i] == '3' ||
                numero[i] == '4' || numero[i] == '5' || numero[i] == '6' || numero[i] == '7' ||
                numero[i] == '8' || numero[i] == '9' )
                certo++;
            }
            if(certo == 3)
                cout << "Codigo de Evento corretamente apresentado" << endl;
        }
        else{
            throw erro_de_evento;
        }
    }
    catch(string erro_de_evento){
        cout << "O codigo informado nao corresponde ao padrao solicitado" << endl;
    }
}
/**
 * @brief essa funcao serve para setar o codigo de evento na string numero, atributo do objeto e chama a funcao validar
 *
 * @param numero parametro que sera enviado para o atributo de mesmo nome do objeto
 */
void Codigo_de_evento::setCodigo_de_evento(string numero){
    this->numero = numero;
    valida_Codigo();
}
/**
 * @brief Essa funcao e responsavel por validar o codigo de apresentacao do programa
 *
 */
void Codigo_de_apresentacao::valida_apresentacao(){
    int certo = 0;
    try{
        if(numero.length() == 4){
            for(int i = 0; i < numero.length(); i++){
                if(numero[i] == '0' || numero[i] == '1' || numero[i] == '2' || numero[i] == '3' ||
                numero[i] == '4' || numero[i] == '5' || numero[i] == '6' || numero[i] == '7' ||
                numero[i] == '8' || numero[i] == '9' )
                certo++;
            }
            if(certo == 4)
                cout << "Codigo de apresentacao corretamente apresentado" << endl;
        }
        else{
            throw erro_de_evento;
        }
    }
    catch(string erro_de_evento){
        cout << "O codigo informado nao corresponde ao padrao solicitado" << endl;
    }
}
/**
 * @brief essa funcao serve para setar o codigo de apresentacao na string numero, atributo do objeto e chama a funcao validar
 *
 * @param numero parametro que sera enviado para o atributo de mesmo nome do objeto
 */
void Codigo_de_apresentacao::setCodigo_de_apresentacao(string numero){
    this->numero = numero;
    valida_apresentacao();
}
/**
 * @brief Essa funcao e responsavel por validar o codigo de ingresso do programa
 *
 */
void Codigo_de_ingresso::valida_ingresso(){
    int certo = 0;
    try{
        if(numero.length() == 5){
            for(int i = 0; i < numero.length(); i++){
                if(numero[i] == '0' || numero[i] == '1' || numero[i] == '2' || numero[i] == '3' ||
                numero[i] == '4' || numero[i] == '5' || numero[i] == '6' || numero[i] == '7' ||
                numero[i] == '8' || numero[i] == '9' )
                certo++;
            }
            if(certo == 5)
                cout << "Codigo de ingresso corretamente apresentado" << endl;
        }
        else{
            throw erro_de_evento;
        }
    }
    catch(string erro_de_evento){
        cout << "O codigo informado nao corresponde ao padrao solicitado" << endl;
    }
}
/**
 * @brief essa funcao serve para setar o codigo de ingresso na string numero, atributo do objeto e chama a funcao validar
 *
 * @param numero parametro que sera enviado para o atributo de mesmo nome do objeto
 */
void Codigo_de_ingresso::setCodigo_de_ingresso(string numero){
    this->numero = numero;
    valida_ingresso();
}
/**
 * @brief Essa funcao serve para validar o evento segundo a especificacao
 *
 * @param nome recebe a variavel nome, um de seus atributos para analise
 */
void Nome_de_evento::valida_evento(string nome){
    int erro_espaco = 0;
    int erro_letra_M = 0;
    int erro_letra_m = 0;
    int e_digito = 0;
    bool padrao = false;
    try{
        if(nome.length() <= 20 && nome.length() > 0){
            for(int i = 0; i < nome.length(); i++){
                if(nome[i] == 'a' || nome[i] == 'b' || nome[i] == 'c' || nome[i] == 'd' || nome[i] == 'e' ||
                    nome[i] == 'f' || nome[i] == 'g' || nome[i] == 'h' || nome[i] == 'i' || nome[i] == 'j' ||
                    nome[i] == 'k' || nome[i] == 'l' || nome[i] == 'm' || nome[i] == 'n' || nome[i] == 'n' ||
                    nome[i] == 'o' || nome[i] == 'p' || nome[i] == 'q' || nome[i] == 'r' || nome[i] == 's' ||
                    nome[i] == 't' || nome[i] == 'y' || nome[i] == 'v' || nome[i] == 'w' || nome[i] == 'x' ||
                    nome[i] == 'y' || nome[i] == 'z')
                        erro_letra_m++;
                else if(nome[i] == 'A' || nome[i] == 'B' || nome[i] == 'C' || nome[i] == 'D' || nome[i] == 'E' ||
                    nome[i] == 'F' || nome[i] == 'G' || nome[i] == 'H' || nome[i] == 'I' || nome[i] == 'J' ||
                    nome[i] == 'K' || nome[i] == 'L' || nome[i] == 'M' || nome[i] == 'N' || nome[i] == 'N' ||
                    nome[i] == 'O' || nome[i] == 'P' || nome[i] == 'Q' || nome[i] == 'R' || nome[i] == 'S' ||
                    nome[i] == 'T' || nome[i] == 'Y' || nome[i] == 'V' || nome[i] == 'W' || nome[i] == 'X' ||
                    nome[i] == 'Y' || nome[i] == 'Z')
                        erro_letra_M++;
                else if(nome[i] == ' ' && nome[i+1] == ' ')
                    erro_espaco++;
            }

            if(erro_espaco == 0 && erro_letra_m != 0 && erro_letra_M != 0)
                cout << "Nome de evento fornecido corretamente" << endl;
            else
                throw erro_de_nome;
        }
        else
            throw erro_de_nome;
    }
    catch(string erro_de_nome){
        cout << "Nome informado esta incorreto" << endl;
    }
}
/**
 * @brief essa funcao serve para setar o nome de evento na string nome, atributo do objeto e chama a funcao validar
 *
 * @param nome parametro que sera enviado para o atributo de mesmo nome do objeto
 */
void Nome_de_evento::setNome_de_evento(string nome){
    this->nome = nome;
    valida_evento(nome);
}
/**
 * @brief Essa funcao serve para validar o evento segundo a especificacao
 *
 * @param data Utiliza a variavel para a validacao da data conforme a especificacao
 */
void Data::valida_data(string data){
    string temp;
    int i = 0;
    try{
        for(i = 0; i < data.length(); i++){
            if(data[i] == '/')
                erro_barra++;
        }
        if(erro_barra == 2){

            int dia = 0;
            int mes = 0;
            int ano = -1;

            temp.push_back(data[0]);
            temp.push_back(data[1]);
            stringstream dias(temp);
            dias >> dia;

            temp.pop_back();
            temp.pop_back();

            temp.push_back(data[3]);
            temp.push_back(data[4]);
            stringstream meses(temp);
            meses >> mes;

            temp.pop_back();
            temp.pop_back();

            temp.push_back(data[6]);
            temp.push_back(data[7]);
            stringstream anos(temp);
            anos >> ano;

            if(dia > 0 && dia <= 31 && mes > 0 && mes <= 12 && ano >= 0 && ano <= 99){
                if(mes == 2){
                    if(dia > 0 && dia < 29 || (dia > 0 && dia <= 29 && ano % 4 == 0))
                        cout << "Data corretamente informada" << endl;
                    else
                        throw erro_data;
                }
                else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
                    if(dia > 0 && dia <=30)
                        cout << "Data corretamente informada" << endl;
                    else
                        throw erro_data;
                }
                else if(mes == 1 || mes == 3 || mes == 5 || mes == 7
                || mes == 8 || mes == 10 || mes == 12){
                    if(dia > 0 && dia <=31)
                        cout << "Data corretamente informada" << endl;
                    else
                        throw erro_data;
                }
                else
                    throw erro_data;
            }
            else
                throw erro_data;
        }
        else
            throw erro_data;
    }
    catch(int erro_data){
        cout << "Data errada" << endl;
    }
}
/**
 * @brief essa funcao serve para setar a data na string data, atributo do objeto e chama a funcao validar
 *
 * @param data parametro que sera enviado para o atributo de mesmo nome do objeto
 */
void Data::setData(string data){
    this->data = data;
    valida_data(data);
}
/**
 * @brief Essa funcao serve para validar o evento segundo a especificacao
 *
 * @param horario Utiliza a variavel para a validacao do horario conforme a especificacao
 */
void Horario::valida_horario(string horario){
    string temp;
    int i = 0;
    try{
        if(horario[2] == ':')
            formato = 1;
        if(formato == 1){
            int hora = -1;
            int minuto = -1;

            temp.push_back(horario[0]);
            temp.push_back(horario[1]);
            stringstream horas(temp);
            horas >> hora;

            temp.pop_back();
            temp.pop_back();

            temp.push_back(horario[3]);
            temp.push_back(horario[4]);
            stringstream minutos(temp);
            minutos >> minuto;

            if(hora >= 7 && hora <= 22){
                if(minuto == 0 || minuto == 15 || minuto == 30 || minuto == 45){
                    cout << "Horario corretamente informado" << endl;
                }
                else
                    throw erro_horario;
            }
            else throw erro_horario;

        }
        else
            throw erro_horario;
    }
    catch(string erro_horario){
        cout << "Horario informado esta incorreta" << endl;
    }
}
/**
 * @brief essa funcao serve para setar o horario na string horario, atributo do objeto e chama a funcao validar
 *
 * @param horario
 */
void Horario::setHorario(string horario){
    this->horario = horario;
    valida_horario(horario);
}
/**
 * @brief Essa funcao serve para validar o evento segundo a especificacao
 *
 */
void Preco::valida_preco(){
    try{
        if(preco >= 0 && preco <=1000)
            cout << "Preco informado corretamente" << endl;
        else
            throw erro;
    }
    catch(int erro){
        cout << "Preco informado esta errado" << endl;
    }
}
/**
 * @brief essa funcao serve para setar o preco na string preco, atributo do objeto e chama a funcao validar
 *
 * @param preco Utiliza a variavel para a validacao do preco conforme a especificacao
 */
void Preco::setPreco(int preco){
    this->preco = preco;
    valida_preco();
}
/**
 * @brief Essa funcao serve para validar o evento segundo a especificacao
 *
 */
void Numero_de_sala::valida_sala(){
    try{
        if(sala > 0 && sala <= 10)
            cout << "Valor de sala informado corretamente" << endl;
        else
            throw erro;
    }
    catch(int erro){
        cout << "Valor de sala errado" << endl;
    }
}
/**
 * @brief essa funcao serve para validar a disponibilidade, atributo do objeto e chama a funcao validar
 *
 */
void Disponibilidade::valida_disponibilidade(){
    try{
        if(this->disponibilidade < 0 || this->disponibilidade > 250)
            throw erro;
        else{
            cout << "Disponibilidade Correta" << endl;
        }
    }
    catch(bool erro){
        cout << "Dispoibilidade informada esta incorreta" << endl;
    }
}
/**
 * @brief essa funcao serve para setar a disponibilidade na string disponibilidade, atributo do objeto e chama a funcao validar
 *
 * @param disponibilidade Utiliza a variavel para a validacao da disponibilidade conforme a especificacao
 */
void Disponibilidade::setDisponibilidade(int disponibilidade){
    this->disponibilidade = disponibilidade;
    valida_disponibilidade();
}
/**
 * @brief essa funcao serve para validar a classe de evento, atributo do objeto e chama a funcao validar
 *
 */
void Classe_de_evento::valida_classe_de_evento(){
    try{
        if(numero == 1){
            cout << "TEATRO escolhido" << endl;
            this->escolha = "TEATRO";
        }
        else if(numero == 2){
            cout << "ESPORTE escolhido" << endl;
            this->escolha = "ESPORTE";
        }
        else if(numero == 3){
            cout << "SHOW NACIONAL escolhido" << endl;
            this->escolha = "SHOW NACIONAL";
        }
        else if(numero == 4){
            cout << "SHOW INTERNACIONAL escolhido" << endl;
            this->escolha = "SHOW INTERNACIONAL";
        }
        else
            throw erro;
    }
    catch(bool erro){
        cout << "Classe de evento informada incorretamente" << endl;
    }
}
/**
 * @brief essa funcao serve para setar a classe de evento na string numero, atributo do objeto e chama a funcao validar
 *
 * @param numero Utiliza a variavel para a validacao da classe de evento conforme a especificacao
 */
void Classe_de_evento::setClasse_de_evento(int numero){
    this->numero = numero;
    valida_classe_de_evento();
}
/**
 * @brief essa funcao serve para validar a faixa etaria, atributo do objeto e chama a funcao validar
 *
 */
void Faixa_etaria::valida_faixa_etaria(){
    try{
        if(faixa == "L" || faixa == "10" || faixa == "12" || faixa == "14" || faixa == "16" || faixa == "18")
            cout << "Faixa etaria informada corretamente" << endl;
        else
            throw erro;

    }
    catch(bool erro){
        erro = true;
        cout << "Faixa etaria informada esta incorreta" << endl;
    }
}
/**
 * @brief essa funcao serve para setar a faixa etaria na string faixa, atributo do objeto e chama a funcao validar
 *
 * @param faixa parametro que sera enviado ao atributo do objeto
 */
void Faixa_etaria::setFaixa_etaria(string faixa){
    this->faixa = faixa;
    valida_faixa_etaria();
}
/**
 * @brief essa funcao serve para setar a numero de sala no int sala, atributo do objeto e chama a funcao validar
 *
 * @param sala Utiliza a variavel para a validacao da classe de evento conforme a especificacao
 */
void Numero_de_sala::setSala(int sala){
    this->sala = sala;
    valida_sala();
}
/**
 * @brief Responsavel por validar a cidade
 *
 */
void Cidade::valida_cidade(){
    int erro_espaco = 0;
    int erro_letra_M = 0;
    int erro_letra_m = 0;
    int e_digito = 0;
    int erro_ponto = 0;
    bool padrao = false;
    try{
        if(cidade.length() <= 15 && cidade.length() > 0){
            for(int i = 0; i < cidade.length(); i++){
                if(cidade[i] == 'a' || cidade[i] == 'b' || cidade[i] == 'c' || cidade[i] == 'd' || cidade[i] == 'e' ||
                    cidade[i] == 'f' || cidade[i] == 'g' || cidade[i] == 'h' || cidade[i] == 'i' || cidade[i] == 'j' ||
                    cidade[i] == 'k' || cidade[i] == 'l' || cidade[i] == 'm' || cidade[i] == 'n' || cidade[i] == 'n' ||
                    cidade[i] == 'o' || cidade[i] == 'p' || cidade[i] == 'q' || cidade[i] == 'r' || cidade[i] == 's' ||
                    cidade[i] == 't' || cidade[i] == 'y' || cidade[i] == 'v' || cidade[i] == 'w' || cidade[i] == 'x' ||
                    cidade[i] == 'y' || cidade[i] == 'z')
                        erro_letra_m++;
                else if(cidade[i] == 'A' || cidade[i] == 'B' || cidade[i] == 'C' || cidade[i] == 'D' || cidade[i] == 'E' ||
                    cidade[i] == 'F' || cidade[i] == 'G' || cidade[i] == 'H' || cidade[i] == 'I' || cidade[i] == 'J' ||
                    cidade[i] == 'K' || cidade[i] == 'L' || cidade[i] == 'M' || cidade[i] == 'N' || cidade[i] == 'N' ||
                    cidade[i] == 'O' || cidade[i] == 'P' || cidade[i] == 'Q' || cidade[i] == 'R' || cidade[i] == 'S' ||
                    cidade[i] == 'T' || cidade[i] == 'Y' || cidade[i] == 'V' || cidade[i] == 'W' || cidade[i] == 'X' ||
                    cidade[i] == 'Y' || cidade[i] == 'Z')
                        erro_letra_M++;
                else if(cidade[i] == ' ' && cidade[i+1] == ' ')
                    erro_espaco++;
                else if(cidade[i] == '.' && !(cidade[i-1] == 'A' || cidade[i-1] == 'B' || cidade[i-1] == 'C' || cidade[i-1] == 'D' || cidade[i-1] == 'E' ||
                    cidade[i-1] == 'F' || cidade[i-1] == 'G' || cidade[i-1] == 'H' || cidade[i-1] == 'I' || cidade[i-1] == 'J' ||
                    cidade[i-1] == 'K' || cidade[i-1] == 'L' || cidade[i-1] == 'M' || cidade[i-1] == 'N' || cidade[i-1] == 'N' ||
                    cidade[i-1] == 'O' || cidade[i-1] == 'P' || cidade[i-1] == 'Q' || cidade[i-1] == 'R' || cidade[i-1] == 'S' ||
                    cidade[i-1] == 'T' || cidade[i-1] == 'Y' || cidade[i-1] == 'V' || cidade[i-1] == 'W' || cidade[i-1] == 'X' ||
                    cidade[i-1] == 'Y' || cidade[i-1] == 'Z'))
                        erro_ponto++;
            }

            if(erro_espaco == 0 && erro_letra_m != 0 && erro_letra_M != 0 && erro_ponto == 0)
                cout << "Nome de evento fornecido corretamente" << endl;
            else
                throw erro;
        }
        else
            throw erro;
    }
    catch(string erro){
        cout << "Nome informado esta incorreto" << endl;
    }
}
/**
 * @brief Responsavel por setar a cidade e chamar a validacao
 *
 * @param cidade parametro que sera enviado ao atributo do objeto
 */
void Cidade::setCidade(string cidade){
    this->cidade = cidade;
    valida_cidade();
}
/**
 * @brief Responsavel por validar o estado
 *
 */
void Estado::valida_Estado(){
    try{
        if(estado ==  AC || estado == AL || estado == AP || estado == AM || estado == BA || estado == CE ||estado == DF ||
         estado == ES || estado == GO || estado == MA || estado == MT || estado == MS || estado == MG || estado == PA ||
         estado == PB || estado == PR || estado == PE || estado == PI || estado == RJ || estado == RN || estado == RS ||
         estado == RO || estado == RR || estado == SC || estado == SP || estado == SE || estado == TO)
            cout << "Estado corretamente informado" << endl;
        else
            throw erro;
    }
    catch(bool erro){
        cout << "Estado incorretamente informado" << endl;
    }
}
/**
 * @brief Responsavel por chamar a funcao validar e setar o estado
 *
 * @param estado parametro que sera enviado ao atributo do objeto
 */
void Estado::setEstado(string estado){
    this->estado = estado;
    valida_Estado();
}
/**
 * @brief Responsavel por validar o Cpf
 *
 */
void Cpf::valida_Cpf(){
    try{
        if(cpf_string.length() == 11){

            for(int i = 0; i < 9; i++){
                cpf[i] = converte_letra_numero(cpf_string[i]);

            }

            //codigo verificador do cpf
            //primeiro numero
            for(int i = 0; i < 9; i++){
                verifica[i] = (10-i) * cpf[i];
                soma += verifica[i];
            }

            if(soma % 11 < 2){
                verificador1 = 0;
            }
            else{
                verificador1 = 11 - (soma % 11);
            }
            // primeiro digito calculado
            cpf[9] = verificador1;

            //calcular segundo digito

            for(int i = 0; i < 10; i++){
                verifica2[i] = (11-i) * cpf[i];
                soma2 += verifica2[i];
            }
            if(soma2 % 11 < 2){
                verificador2 = 0;
            }
            else{
                verificador2 = 11 - (soma2 % 11);
            }
            cpf[10] = verificador2;
            int igual = 0;
            for(int i = 0; i < 11; i++)
                analisacpf[i] = converte_letra_numero(cpf_string[i]);
            for(int i = 0; i < 11; i++)
                if(analisacpf[i] == cpf[i])
                    igual++;

            if(igual == 11)
                cout << "CPF correto" << endl;
            else
                throw erro_tamanho;
        }
        else
            throw erro_tamanho;
    }
    catch(string erro_tamanho){
        cout << "CPF incorretamente informado" << endl;
    }
}
/**
 * @brief Responsavel por setar o cpf e chamar a funcao validar
 *
 * @param cpf_string parametro que sera enviado ao atributo do objeto
 */
void Cpf::setCpf(string cpf_string){
    this->cpf_string = cpf_string;
    valida_Cpf();
}
/**
 * @brief Responsavel por validar a senha
 *
 */
void Senha::valida_Senha(){
    int e_numero = 0;
    int e_letra_M = 0;
    int e_letra_m = 0;
    bool padrao = false;

    try{

        if(senha.length() > 6 || senha.length() <= 0)
            throw erro_senha;
        else{

            for(int i = 0; i < 6; i++){
                if(senha[i] == '0' || senha[i] == '1' || senha[i] == '2' || senha[i] == '3' || senha[i] == '4' ||
                    senha[i] == '5' || senha[i] == '6' || senha[i] == '7' || senha[i] == '8' || senha[i] == '9')
                        e_numero++;
                    else if(senha[i] == 'a' || senha[i] == 'b' || senha[i] == 'c' || senha[i] == 'd' || senha[i] == 'e' ||
                        senha[i] == 'f' || senha[i] == 'g' || senha[i] == 'h' || senha[i] == 'i' || senha[i] == 'j' ||
                        senha[i] == 'k' || senha[i] == 'l' || senha[i] == 'm' || senha[i] == 'n' || senha[i] == 'n' ||
                        senha[i] == 'o' || senha[i] == 'p' || senha[i] == 'q' || senha[i] == 'r' || senha[i] == 's' ||
                        senha[i] == 't' || senha[i] == 'y' || senha[i] == 'v' || senha[i] == 'w' || senha[i] == 'x' ||
                        senha[i] == 'y' || senha[i] == 'z')
                        e_letra_m++;
                    else if(senha[i] == 'A' || senha[i] == 'B' || senha[i] == 'C' || senha[i] == 'D' || senha[i] == 'E' ||
                        senha[i] == 'F' || senha[i] == 'G' || senha[i] == 'H' || senha[i] == 'I' || senha[i] == 'J' ||
                        senha[i] == 'K' || senha[i] == 'L' || senha[i] == 'M' || senha[i] == 'N' || senha[i] == 'N' ||
                        senha[i] == 'O' || senha[i] == 'P' || senha[i] == 'Q' || senha[i] == 'R' || senha[i] == 'S' ||
                        senha[i] == 'T' || senha[i] == 'Y' || senha[i] == 'V' || senha[i] == 'W' || senha[i] == 'X' ||
                        senha[i] == 'Y' || senha[i] == 'Z')
                        e_letra_M++;
                    if(e_numero > 0 && e_letra_M > 0 && e_letra_m > 0)
                        padrao = true;
            }
        }

        if(padrao)
            cout << "Senha correta" << endl;
        else
            throw erro_senha;
    }
    catch(string erro_senha){
        cout << "Senha incorretamente informada" << endl;
    }
}
/**
 * @brief seta a senha no atributo senha
 *
 * @param senha parametro que sera enviado ao atributo do objeto
 */
void Senha::setSenha(string senha){
    this->senha = senha;
    valida_Senha();
}
/**
 * @brief Responsavel por validar o cartao
 *
 */
void Numero_do_cartao_de_credito::valida_cartao(){
    int sum = 0, converte = 0;
    try{
        if(numero_cartao.length() != 16){
            throw erro_numero_do_cartao_de_credito;
        }
        else{
            for(int i = 0; i < 16; i++){
                converte = Conversor.converte_letra_numero(numero_cartao[i]);
                if(i%2 == 0){
                    converte *= 2;
                    if(converte>=10){
                        sum += (converte-9);
                    }
                    else{
                        sum += converte;
                    }
                }
                else{
                    sum += converte;
                }
            }
            if(sum%10 =! 0){
                throw erro_numero_do_cartao_de_credito;
            }
            else{
                cout << "Numero do cartao de credito valido" << endl;
            }
        }
    }
    catch(string erro_numero_do_cartao_de_credito){
        cout << "Numero do cartao de credito invalido" << endl;
    }
}
/**
 * @brief seta o numero de cartao no atributo numero_cartao
 *
 * @param senha parametro que sera enviado ao atributo do objeto
 */
void Numero_do_cartao_de_credito::set_Numero_do_cartao_de_credito(string numero_cartao){
    this->numero_cartao = numero_cartao;
    valida_cartao();
}

void Codigo_de_seguranca::valida_Codigo(){
    int certo = 0;
    try{
        if(numero.length() == 3){
            for(int i = 0; i < numero.length(); i++){
                if(numero[i] == '0' || numero[i] == '1' || numero[i] == '2' || numero[i] == '3' ||
                numero[i] == '4' || numero[i] == '5' || numero[i] == '6' || numero[i] == '7' ||
                numero[i] == '8' || numero[i] == '9' )
                certo++;
            }
            if(certo == 3)
                cout << "Codigo de seguranca corretamente apresentado" << endl;
        }
        else{
            throw erro_de_evento;
        }
    }
    catch(string erro_de_evento){
        cout << "O codigo informado nao corresponde ao padrao solicitado" << endl;
    }
}

void Codigo_de_seguranca::setCodigo_de_seguranca(string numero){
    this->numero = numero;
    valida_Codigo();
}

void Data_de_validade::setData_de_validade(string data_validade){
    this->data_validade = data_validade;
    valida_Data_de_validade();
}

void Data_de_validade::valida_Data_de_validade(){
    try{
        if(data_validade.length() != 5){
            throw erro_data_validade;
        }
        else{
            if(data_validade[2] != '/'){
                throw erro_data_validade;
            }
            else{
                if(data_validade[0] != '0' && data_validade[0] != '1'){
                    throw erro_data_validade;
                }
                else{
                    if(data_validade[0] == '0'){
                        if(data_validade[1] != '1' && data_validade[1] != '2' && data_validade[1] != '3' && data_validade[1] != '4' &&
                           data_validade[1] != '5' && data_validade[1] != '6' && data_validade[1] != '7' && data_validade[1] != '8' &&
                           data_validade[1] != '9'){
                            throw erro_data_validade;
                        }
                    }
                    else{
                        if(data_validade[1] != '1' && data_validade[1] != '2'){
                            throw erro_data_validade;
                        }
                    }
                }
                if(data_validade[3] != '1' && data_validade[3] != '2' && data_validade[3] != '3' && data_validade[3] != '4' &&
                   data_validade[3] != '5' && data_validade[3] != '6' && data_validade[3] != '7' && data_validade[3] != '8' &&
                   data_validade[3] != '9' && data_validade[3] != '0'){
                        throw erro_data_validade;
                }
                else{
                    if(data_validade[4] != '1' && data_validade[4] != '2' && data_validade[4] != '3' && data_validade[4] != '4' &&
                       data_validade[4] != '5' && data_validade[4] != '6' && data_validade[4] != '7' && data_validade[4] != '8' &&
                       data_validade[4] != '9' && data_validade[4] != '0'){
                        throw erro_data_validade;
                       }
                }
            }
        }
    }
    cout << "A data de validade informada e valida" << endl;
    catch(string erro_data_validade){
        cout << "A data de validade informada nao e valida" << endl;
    }
}
