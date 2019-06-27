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
bool Codigo_de_evento::valida_Codigo(string numero){
    try{
        if(numero.length() == 3){
            for(int i = 0; i < 3; i++){
                if(numero[i] != '0' && numero[i] != '1' && numero[i] != '2' && numero[i] != '3' &&
                   numero[i] != '4' && numero[i] != '5' && numero[i] != '6' && numero[i] != '7' &&
                   numero[i] != '8' && numero[i] != '9' )
                    throw erro_de_evento;
            }
        }
        else{
            throw erro_de_evento;
        }
    }
    catch(bool erro_de_evento){
        return true;
        cout << "O codigo informado nao corresponde ao padrao solicitado" << endl;
    }
}
/**
 * @brief essa funcao serve para setar o codigo de evento na string numero, atributo do objeto e chama a funcao validar
 *
 * @param numero parametro que sera enviado para o atributo de mesmo nome do objeto
 */
bool Codigo_de_evento::setCodigo_de_evento(string numero){
    this->erro_de_evento = valida_Codigo(numero);
    if(!this->erro_de_evento){
        this->numero = numero;
        return false;
    }
    else
        return true;
}
/**
 * @brief Essa funcao e responsavel por validar o codigo de apresentacao do programa
 *
 */
bool Codigo_de_apresentacao::valida_apresentacao(string numero){
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
                return false;
        }
        else{
            throw erro;
        }
    }
    catch(bool erro){
        this->erro = true;
        cout << "O codigo informado nao corresponde ao padrao solicitado" << endl;
    }
}
/**
 * @brief essa funcao serve para setar o codigo de apresentacao na string numero, atributo do objeto e chama a funcao validar
 *
 * @param numero parametro que sera enviado para o atributo de mesmo nome do objeto
 */
bool Codigo_de_apresentacao::setCodigo_de_apresentacao(string numero){
    this->erro = valida_apresentacao(numero);
    if(!this->erro){
        this->numero = numero;
        return false;
    }
    else
        return true;
}
/**
 * @brief Essa funcao e responsavel por validar o codigo de ingresso do programa
 *
 */
bool Codigo_de_ingresso::valida_ingresso(string numero){
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
            throw erro;
        }
    }
    catch(bool erro){
        this->erro = true;
        cout << "O codigo informado nao corresponde ao padrao solicitado" << endl;
    }
}
/**
 * @brief essa funcao serve para setar o codigo de ingresso na string numero, atributo do objeto e chama a funcao validar
 *
 * @param numero parametro que sera enviado para o atributo de mesmo nome do objeto
 */
bool Codigo_de_ingresso::setCodigo_de_ingresso(string numero){
    valida_ingresso(numero);
    if(!this->erro)
        this->numero = numero;
    else
        return true;
}
/**
 * @brief Essa funcao serve para validar o evento segundo a especificacao
 *
 * @param nome recebe a variavel nome, um de seus atributos para analise
 */
bool Nome_de_evento::valida_evento(string nome){
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
                   nome[i] == 'y' || nome[i] == 'z'){
                    erro_letra_m++;
                }
                else if(nome[i] == 'A' || nome[i] == 'B' || nome[i] == 'C' || nome[i] == 'D' || nome[i] == 'E' ||
                        nome[i] == 'F' || nome[i] == 'G' || nome[i] == 'H' || nome[i] == 'I' || nome[i] == 'J' ||
                        nome[i] == 'K' || nome[i] == 'L' || nome[i] == 'M' || nome[i] == 'N' || nome[i] == 'N' ||
                        nome[i] == 'O' || nome[i] == 'P' || nome[i] == 'Q' || nome[i] == 'R' || nome[i] == 'S' ||
                        nome[i] == 'T' || nome[i] == 'Y' || nome[i] == 'V' || nome[i] == 'W' || nome[i] == 'X' ||
                        nome[i] == 'Y' || nome[i] == 'Z'){
                    erro_letra_M++;
            }
                else if(nome[i] == ' ' && nome[i+1] == ' '){
                    erro_espaco++;
                }
            }

            if(erro_espaco != 0 || (erro_letra_m == 0 && erro_letra_M == 0))
                throw erro_de_nome;
            else{
                return false;
            }
        }
        else
            throw erro_de_nome;
    }
    catch(bool erro_de_nome){
        return true;
    }
}
/**
 * @brief essa funcao serve para setar o nome de evento na string nome, atributo do objeto e chama a funcao validar
 *
 * @param nome parametro que sera enviado para o atributo de mesmo nome do objeto
 */
bool Nome_de_evento::setNome_de_evento(string nome){
    this->erro_de_nome = valida_evento(nome);
    if(!this->erro_de_nome){
        this->nome = nome;
        return false;
    }
    else
        return true;
}
/**
 * @brief Essa funcao serve para validar o evento segundo a especificacao
 *
 * @param data Utiliza a variavel para a validacao da data conforme a especificacao
 */
bool Data::valida_data(string data){
    int aux = 0;
    string temp;
    try{
        for(int i = 0; i < data.length(); i++){
            if(data[i] == '/'){
                aux++;
            }
        }
        if(aux == 2){
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
                    if((dia > 0 && dia < 29) || (dia == 29 && ano % 4 == 0))
                        return false;
                    else
                        throw erro_data;
                }
                else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
                    if(dia > 0 && dia <=30)
                        return false;
                    else
                        throw erro_data;
                }
                else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                    if(dia > 0 && dia <=31)
                        return false;
                    else
                        throw erro_data;
                }
                else{
                    throw erro_data;
                }
            }
            else{
                throw erro_data;
            }
        }
        else{
            throw erro_data;
        }
    }
    catch(bool erro_data){
        return true;
    }
}
/**
 * @brief essa funcao serve para setar a data na string data, atributo do objeto e chama a funcao validar
 *
 * @param data parametro que sera enviado para o atributo de mesmo nome do objeto
 */
bool Data::setData(string data){
    this->erro_data = valida_data(data);
    if(!this->erro_data){
        this->data = data;
        return false;
    }
    else
        return true;
}
/**
 * @brief Essa funcao serve para validar o evento segundo a especificacao
 *
 * @param horario Utiliza a variavel para a validacao do horario conforme a especificacao
 */
bool Horario::valida_horario(string horario){
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
                    return false;
                }
                else
                    throw erro_horario;
            }
            else
                throw erro_horario;

        }
        else
            throw erro_horario;
    }
    catch(bool erro_horario){
        return true;
    }
}
/**
 * @brief essa funcao serve para setar o horario na string horario, atributo do objeto e chama a funcao validar
 *
 * @param horario
 */
bool Horario::setHorario(string horario){
    this->erro_horario = valida_horario(horario);
    if(!this->erro_horario){
        this->horario = horario;
        return false;
    }
    else
        return true;
}
/**
 * @brief Essa funcao serve para validar o evento segundo a especificacao
 *
 */
bool Preco::valida_preco(int preco){
    try{
        if(preco >= 0 && preco <=1000)
            return false;
        else
            throw erro;
    }
    catch(bool erro){
        return true;
    }
}
/**
 * @brief essa funcao serve para setar o preco na string preco, atributo do objeto e chama a funcao validar
 *
 * @param preco Utiliza a variavel para a validacao do preco conforme a especificacao
 */
bool Preco::setPreco(int preco){
    this->erro = valida_preco(preco);
    if(!this->erro){
        this->preco = preco;
        return false;
    }
    else
        return true;
}
/**
 * @brief Essa funcao serve para validar o evento segundo a especificacao
 *
 */
bool Numero_de_sala::valida_sala(int sala){
    try{
        if(sala > 0 && sala <= 10)
            return false;
        else
            throw erro;
    }
    catch(bool erro){
        return true;
    }
}
/**
 * @brief essa funcao serve para setar a numero de sala no int sala, atributo do objeto e chama a funcao validar
 *
 * @param sala Utiliza a variavel para a validacao da classe de evento conforme a especificacao
 */
bool Numero_de_sala::setSala(int sala){
    this->erro = valida_sala(sala);
    if(!this->erro){
        this->sala = sala;
        return false;
    }
    else
        return true;
}
/**
 * @brief essa funcao serve para validar a disponibilidade, atributo do objeto e chama a funcao validar
 *
 */
bool Disponibilidade::valida_disponibilidade(int disponibilidade){
    try{
        if(disponibilidade < 0 || disponibilidade > 250)
            throw erro;
        else{
            return false;
        }
    }
    catch(bool erro){
        return true;
    }
}
/**
 * @brief essa funcao serve para setar a disponibilidade na string disponibilidade, atributo do objeto e chama a funcao validar
 *
 * @param disponibilidade Utiliza a variavel para a validacao da disponibilidade conforme a especificacao
 */
bool Disponibilidade::setDisponibilidade(int disponibilidade){
    this->erro = valida_disponibilidade(disponibilidade);
    if(!this->erro){
        this->disponibilidade = disponibilidade;
        return false;
    }
    else
        return true;
}
/**
 * @brief essa funcao serve para validar a classe de evento, atributo do objeto e chama a funcao validar
 *
 */
bool Classe_de_evento::valida_classe_de_evento(int numero){
    try{
        if(numero == 1){
            this->escolha = "TEATRO";
            return false;
        }
        else if(numero == 2){
            this->escolha = "ESPORTE";
            return false;
        }
        else if(numero == 3){
            this->escolha = "SHOW NACIONAL";
            return false;
        }
        else if(numero == 4){
            this->escolha = "SHOW INTERNACIONAL";
            return false;
        }
        else
            throw erro;
    }
    catch(bool erro){
        return true;
    }
}
/**
 * @brief essa funcao serve para setar a classe de evento na string numero, atributo do objeto e chama a funcao validar
 *
 * @param numero Utiliza a variavel para a validacao da classe de evento conforme a especificacao
 */
bool Classe_de_evento::setClasse_de_evento(int numero){
    this->erro = valida_classe_de_evento(numero);
    if(!this->erro){
        this->numero = numero;
        return false;
    }
    else
        return true;
}
/**
 * @brief essa funcao serve para validar a faixa etaria, atributo do objeto e chama a funcao validar
 *
 */
bool Faixa_etaria::valida_faixa_etaria(string faixa){
    try{
        if(faixa == "L" || faixa == "10" || faixa == "12" || faixa == "14" || faixa == "16" || faixa == "18")
            return false;
        else
            throw erro;

    }
    catch(bool erro){
        return true;
    }
}
/**
 * @brief essa funcao serve para setar a faixa etaria na string faixa, atributo do objeto e chama a funcao validar
 *
 * @param faixa parametro que sera enviado ao atributo do objeto
 */
bool Faixa_etaria::setFaixa_etaria(string faixa){
    this->erro = valida_faixa_etaria(faixa);
    if(!this->erro){
        this->faixa = faixa;
        return false;
    }
    else
        return true;
}
/**
 * @brief Responsavel por validar a cidade
 *
 */
bool Cidade::valida_cidade(string cidade){
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
                                              cidade[i-1] == 'Y' || cidade[i-1] == 'Z' || cidade[i-1] == 'a' || cidade[i-1] == 'b' || cidade[i-1] == 'c' ||
                                              cidade[i-1] == 'd' || cidade[i-1] == 'e' || cidade[i-1] == 'f' || cidade[i-1] == 'g' || cidade[i-1] == 'h' ||
                                              cidade[i-1] == 'i' || cidade[i-1] == 'j' || cidade[i-1] == 'k' || cidade[i-1] == 'l' || cidade[i-1] == 'm' ||
                                              cidade[i-1] == 'n' || cidade[i-1] == 'n' || cidade[i-1] == 'o' || cidade[i-1] == 'p' || cidade[i-1] == 'q' ||
                                              cidade[i-1] == 'r' || cidade[i-1] == 's' || cidade[i-1] == 't' || cidade[i-1] == 'y' || cidade[i-1] == 'v' ||
                                              cidade[i-1] == 'w' || cidade[i-1] == 'x' || cidade[i-1] == 'y' || cidade[i-1] == 'z'))
                    erro_ponto++;
            }
            if(erro_espaco == 0 && (erro_letra_m != 0 || erro_letra_M != 0) && erro_ponto == 0)
                return false;
            else
                throw erro;
        }
        else
            throw erro;
    }
    catch(bool erro){
        return true;
    }
}
/**
 * @brief Responsavel por setar a cidade e chamar a validacao
 *
 * @param cidade parametro que sera enviado ao atributo do objeto
 */
bool Cidade::setCidade(string cidade){
    this->erro = valida_cidade(cidade);
    if(!this->erro){
        this->cidade = cidade;
        return false;
    }
    else
        return true;
}
/**
 * @brief Responsavel por validar o estado
 *
 */
bool Estado::valida_Estado(string estado){
    try{
        if(estado ==  AC || estado == AL || estado == AP || estado == AM || estado == BA || estado == CE ||estado == DF ||
           estado == ES || estado == GO || estado == MA || estado == MT || estado == MS || estado == MG || estado == PA ||
           estado == PB || estado == PR || estado == PE || estado == PI || estado == RJ || estado == RN || estado == RS ||
           estado == RO || estado == RR || estado == SC || estado == SP || estado == SE || estado == TO)
            return false;
        else
            throw erro;
    }
    catch(bool erro){
        return true;
    }
}
/**
 * @brief Responsavel por chamar a funcao validar e setar o estado
 *
 * @param estado parametro que sera enviado ao atributo do objeto
 */
bool Estado::setEstado(string estado){
    this->erro = valida_Estado(estado);
    if(!this->erro){
        this->estado = estado;
        return false;
    }
    else
        return true;
}
/**
 * @brief Responsavel por validar o Cpf
 *
 */
bool Cpf::valida_Cpf(string cpf_string){
    int somando  = 0;
    int somando2 = 0;
    int cpf_aux[11];
    try{
        if(cpf_string.length() == 11){
            for(int i = 0; i < 9; i++){
                cpf_aux[i] = converte_letra_numero(cpf_string[i]);
            }
            //codigo verificador do cpf
            //primeiro numero
            for(int i = 0; i < 9; i++){
                verifica[i] = (10-i) * cpf_aux[i];
                somando += verifica[i];
            }

            if(somando % 11 < 2){
                verificador1 = 0;
            }
            else{
                verificador1 = 11 - (somando % 11);
            }
            // primeiro digito calculado
            cpf_aux[9] = verificador1;

            //calcular segundo digito

            for(int i = 0; i < 10; i++){
                verifica2[i] = (11-i) * cpf_aux[i];
                somando2 += verifica2[i];
            }
            if(somando2 % 11 < 2){
                verificador2 = 0;
            }
            else{
                verificador2 = 11 - (somando2 % 11);
            }
            cpf_aux[10] = verificador2;
            int igual = 0;
            for(int i = 0; i < 11; i++)
                analisacpf[i] = converte_letra_numero(cpf_string[i]);
            for(int i = 0; i < 11; i++){
                if(analisacpf[i] == cpf_aux[i]){
                    igual++;
                }
            }
            if(igual != 11){
                throw erro_tamanho;
            }
            return false;
        }
        else
            throw erro_tamanho;
    }
    catch(bool erro_tamanho){
        return true;
    }
}
/**
 * @brief Responsavel por setar o cpf e chamar a funcao validar
 *
 * @param cpf_string parametro que sera enviado ao atributo do objeto
 */
bool Cpf::setCpf(string cpf_string){
    this->erro_tamanho = valida_Cpf(cpf_string);
    if(!this->erro_tamanho){
        this->cpf_string = cpf_string;
        return false;
    }
    else
        return true;
}
/**
 * @brief Responsavel por validar a senha
 *
 */
bool Senha::valida_Senha(string senha){
    int e_numero = 0;
    int e_letra_M = 0;
    int e_letra_m = 0;
    bool padrao = false;

    try{

        if(senha.length() > 6 || senha.length() <= 2)
            throw erro_senha;
        else{
            if(senha.length() == 3){
                if(senha[0] == senha[1] || senha[0] == senha[2] || senha[1] == senha[2])
                    throw erro_senha;
            }
            else if(senha.length() == 4){
                if(senha[0] == senha[1] || senha[0] == senha[2] || senha[0] == senha[3] || senha[1] == senha[2] || senha[1] == senha[3] ||
                   senha[2] == senha[3])
                    throw erro_senha;
            }
            else if(senha.length() == 5){
                if(senha[0] == senha[1] || senha[0] == senha[2] || senha[0] == senha[3] || senha[0] == senha[4] || senha[1] == senha[2] ||
                   senha[1] == senha[3] || senha[1] == senha[4] || senha[2] == senha[3] || senha[2] == senha[4] || senha[3] == senha[4])
                    throw erro_senha;
            }
            else if(senha.length() == 6){
                if(senha[0] == senha[1] || senha[0] == senha[2] || senha[0] == senha[3] || senha[0] == senha[4] || senha[0] == senha[5] ||
                   senha[1] == senha[2] || senha[1] == senha[3] || senha[1] == senha[4] || senha[1] == senha[5] || senha[2] == senha[3] ||
                   senha[2] == senha[4] || senha[2] == senha[5] || senha[3] == senha[4] || senha[3] == senha[5] || senha[4] == senha[5])
                    throw erro_senha;
            }
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

        if(!padrao)
            throw erro_senha;
    }
    catch(bool erro_senha){
        return true;
    }
}
/**
 * @brief seta a senha no atributo senha
 *
 * @param senha parametro que sera enviado ao atributo do objeto
 */
bool Senha::setSenha(string senha){
    this->erro_senha = valida_Senha(senha);
    if(!this->erro_senha){
        this->senha = senha;
        return false;
    }
    else
        return true;
}
/**
 * @brief Responsavel por validar o cartao
 *
 */
bool Numero_do_cartao_de_credito::valida_cartao(string numero_cartao){
    int sum = 0, converte = 0;
    string erro_numero_do_cartao_de_credito;
    try{
        if(numero_cartao.length() != 16){
            throw erro_numero_do_cartao_de_credito;
        }
        else{
            for(int i = 0; i < 16; i++){
                converte = converte_letra_numero(numero_cartao[i]);
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
            if(sum%10 != 0){
                throw erro_numero_do_cartao_de_credito;
            }
        }
    }
    catch(string erro_numero_do_cartao_de_credito){
        return true;
    }
    return false;
}
/**
 * @brief seta o numero de cartao no atributo numero_cartao
 *
 * @param senha parametro que sera enviado ao atributo do objeto
 */
bool Numero_do_cartao_de_credito::set_Numero_do_cartao_de_credito(string numero_cartao){
    this->erro = valida_cartao(numero_cartao);
    if(!this->erro){
        this->numero_cartao = numero_cartao;
        return false;
    }
    else
        return true;
}

bool Codigo_de_seguranca::valida_Codigo(string numero){
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
                return false;
        }
        else{
            throw erro_de_evento;
        }
    }
    catch(bool erro_de_evento){
        return true;
    }
}

bool Codigo_de_seguranca::setCodigo_de_seguranca(string numero){
    this->erro_de_evento = valida_Codigo(numero);
    if(!this->erro_de_evento){
        this->numero = numero;
        return false;
    }
    else
        return true;
}
bool Data_de_validade::setData_de_validade(string data_validade){
    this->erro = valida_Data_de_validade(data_validade);
    if(!this->erro){
        this->data_validade = data_validade;
        return false;
    }
    else
        return true;
}

bool Data_de_validade::valida_Data_de_validade(string data_validade){
    string erro_data_validade;
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
                        if(data_validade[1] != '0' && data_validade[1] != '1' && data_validade[1] != '2'){
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
        return false;
    }
    catch(string erro_data_validade){
        return true;
    }
}
