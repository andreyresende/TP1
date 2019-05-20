#include "entidades.h"
#include "dominios.h"
#include <exception>
/**
 * @brief Responsavel por criar o Usuario do sistema, que possui cpf e senha
 * 
 * @param cpf_string cpf do usuario
 * @param senha senha do usuario
 * @return int possivel retorno de int para o futuro banco de dados, onde cada usuario tera uma primary key iterada
 */
int Usuario::setUsuario(string cpf_string, string senha){
    this->cpf_string = cpf_string;
    this->senha = senha;
    //criar usuario, primeiro o cpf e cadastrado para a classe e logo apos a senha e cadastrada
    //cout << "Por favor informe seu CPF para cadastrar no sistema" << endl;
    cpf_usuario.setCpf(cpf_string);

    //cadastro de senha da classe
    //cout << "Informe uma senha de 6 digitos que deve conter ao menos um numero, uma letra maiuscula, e uma letra minuscula" << endl;
    senha_usuario.setSenha(senha);
}
/**
 * @brief Responsavel pela entidade de apresentacao do programa
 * 
 * @param string_numero Codigo de apresentacao
 * @param string_data Data
 * @param string_horario Horario
 * @param int_preco Preco
 * @param int_sala Numero de sala
 * @param int_disponibilidade Disponibilidade no sistema
 */
void Apresentacao::setApresentacao(string string_numero, string string_data, string string_horario, int int_preco, int int_sala, int int_disponibilidade){
    this->string_numero = string_numero;
    this->string_data = string_data;
    this->string_horario = string_horario;
    this->int_preco = int_preco;
    this->int_sala = int_sala;
    this->int_disponibilidade = int_disponibilidade;
    
    apresentacao.setCodigo_de_apresentacao(string_numero);
    data.setData(string_data);
    horario.setHorario(string_horario);
    preco.setPreco(int_preco);
    sala.setSala(int_sala);
    disponibilidade.setDisponibilidade(int_disponibilidade);
}   

//ser implementado apenas na versao final do trabalho
/*void Usuario::loga_ou_cadastra(){
    int escolha = 0;

    cout << "Escolha " << endl << "[1] Para entrar" << endl << "[2] Para cadastro" << endl;
    while(escolha != 1 || escolha != 2 || getchar() != '\n'){
        escolha getchar();
        switch (escolha){
            case 1:
                //loga usuario
                break;
            case 2:
                cadastra_usuario();
                break;
            default:
                cout << "Escolha errada, por favor informe corretamente segundo o especificado" << endl;
                cout << "Escolha " << endl << "[1] Para entrar" << endl << "[2] Para cadastro" << endl;

                break;
        }

    }
}
*/