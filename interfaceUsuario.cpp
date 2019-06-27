#include "controladores.h"
#include "interfaces.h"
#include <cstdlib>
#include <list>

using namespace std;
/**
 * @brief Tela inicial do Sistema
 * 
 * @param container Interface do Banco de Dados
 */
void Interface_usuario::tela_inicial(Container &container){
    int escolha = -1;  // nem 0 nem 1
    bool continua = true;
    cout << "#########################" << endl;
    cout << "Seja Bem Vindo ao Sistema" << endl;
    cout << "#########################" << endl;
    cout << "###############################################" << endl;
    cout << "[1] Login" << endl;
    cout << "[2] Cadastro" << endl;
    cout << "[3] Sair" << endl;
    cout << "###############################################" << endl;
    cin >> escolha;
    while (continua) {
        if (escolha == 1) {
            cout << "Direcionando para Login" << endl;
            continua = false;
            tela_login(container);
        } 
        else if (escolha == 2) {
            cout << "Direcionando para Cadastro" << endl;
            continua = false;
            tela_cadastro(container);
        }
        else if(escolha == 3) { 
            cout << "Saindo..." << endl;
            exit(0);
        }
        else{
            cout << "Opcao escolhida errada, informe:" << endl;
            cout << "###############################################" << endl;
            cout << "[1] Login" << endl;
            cout << "[2] Cadastro" << endl;
            cout << "[3] Sair" << endl;
            cout << "###############################################" << endl;
            cin >> escolha;
        }
    }
}
/**
 * @brief Tela onde acontece o login e a autenticacao do usuario
 * 
 * @param container Interface do Banco de Dados
 */
void Interface_usuario::tela_login(Container &container) {
    cout << "################################################################" << endl;
    Usuario usuario;
    string cpf;
    string senha;
    bool achou_conta = false;
    bool continua = true;

    cout << "Informe seu Cpf" << endl;
    cin >> cpf;
    cout << "Informe sua Senha" << endl;
    cin >> senha;

    achou_conta = cadastro.login(cpf, senha, container);
    if(!achou_conta){
        while (continua) {
            cout << "Informe seu Cpf" << endl;
            cin >> cpf;
            cout << "Informe sua Senha" << endl;
            cin >> senha;
            achou_conta = cadastro.login(cpf, senha, container);
            if(achou_conta)
                continua = false;
        }
    }
        tela_principal(container);
}
/**
 * @brief Tela onde e possivel se realizar o cadastro no sistema
 * 
 * @param container Interface do Banco de Dados
 */
void Interface_usuario::tela_cadastro(Container &container) {
    cout << "################################################################" << endl;
    Cpf objeto_cpf;
    Senha objeto_senha;
    Numero_do_cartao_de_credito objeto_numero_do_cartao_de_credito;
    Codigo_de_seguranca objeto_codigo_de_seguranca;
    Data_de_validade objeto_data_de_validade;
    bool cpf_teste                         = false;
    bool senha_teste                       = false;
    bool numero_do_cartao_de_credito_teste = false;
    bool codigo_de_seguranca_teste         = false;
    bool data_de_validade_teste            = false;
    string cpf;
    string senha;
    string numero_do_cartao_de_credito;
    string codigo_de_seguranca;
    string data_de_validade;


    cout << "Informe seu Cpf" << endl;
    cin >> cpf;
    cpf_teste = objeto_cpf.setCpf(cpf);
    while(cpf_teste){
        cout << "Numero de cpf invalido, por favor, verifique e insira novamente" << endl;
        cin  >> cpf;
        cpf_teste = objeto_cpf.setCpf(cpf);
    }
    cout << "Cpf confirmado" << endl;



    cout << "Informe sua Senha, ela devera possuir um caracter maiusculo, um minusculo e um numero, com no maximo 6 "
            "digitos e todos eles devem ser diferentes" << endl;
    cin  >> senha;
    senha_teste = objeto_senha.setSenha(senha);
    while(senha_teste){
        cout << "Senha invalida, por favor, escolha uma senha valida" << endl;
        cin >> senha;
        senha_teste = objeto_senha.setSenha(senha);
    }
    cout << "Senha confirmada" << endl;



    cout << "Agora para finalizar seu cadastro, informe os seguintes dados:" << endl;
    cout << "Numero do Cartao de credito:" << endl;
    cin  >> numero_do_cartao_de_credito;
    numero_do_cartao_de_credito_teste = objeto_numero_do_cartao_de_credito.set_Numero_do_cartao_de_credito(numero_do_cartao_de_credito);
    while(numero_do_cartao_de_credito_teste){
        cout << "Numero do cartao de credito invalido, por favor, verifique e insira novamente" << endl;
        cin  >> numero_do_cartao_de_credito;
        numero_do_cartao_de_credito_teste = objeto_numero_do_cartao_de_credito.set_Numero_do_cartao_de_credito(numero_do_cartao_de_credito);
    }
    cout << "Numero do cartao de credito confirmado" << endl;



    cout << "Codigo de seguranca do cartao:" << endl;
    cin  >> codigo_de_seguranca;
    codigo_de_seguranca_teste = objeto_codigo_de_seguranca.setCodigo_de_seguranca(codigo_de_seguranca);
    while(codigo_de_seguranca_teste){
        cout << "Codigo de seguranca invalido, por favor, verifique e insira novamente" << endl;
        cin  >> codigo_de_seguranca;
        codigo_de_seguranca_teste = objeto_codigo_de_seguranca.setCodigo_de_seguranca(codigo_de_seguranca);
    }
    cout << "Codigo de seguranca confirmado" << endl;



    cout << "Data de Validade do cartao:" << endl;
    cin  >> data_de_validade;
    data_de_validade_teste = objeto_data_de_validade.setData_de_validade(data_de_validade);
    while(data_de_validade_teste){
        cout << "Data de validade invalida, por favor, verifique e insira novamente" << endl;
        cin  >> data_de_validade;
        data_de_validade_teste = objeto_data_de_validade.setData_de_validade(data_de_validade);
    }


    cadastro.autenticar(container.totalUsuarios, cpf, senha, numero_do_cartao_de_credito, codigo_de_seguranca,data_de_validade);
    cout << "Usuario cadastrado com sucesso" << endl;
    tela_inicial(container);
}
/**
 * @brief Tela Principal de utilizacao apos autenticacao 
 * 
 * @param container Interface do Banco de Dados
 */
void Interface_usuario::tela_principal(Container &container) {
    bool continua = true;
    int escolha = -1;  // nem 0 nem 1
    while (continua) {
        if (escolha == 1) {
            cout << "Direcionando para Compra de Ingresso" << endl;
            tela_adquirir_ingresso(container);
            escolha = -1;
        }
        else if (escolha == 2) {
            cout << "Direcionando para Informacoes de Venda dos Eventos" << endl;
            tela_relatorio_vendas(container);
            escolha = -1;
        }
        else if (escolha == 3) {
            cout << "Direcionando para Criacao de Evento" << endl;
            tela_cadastro_evento(container);
            escolha = -1;
        }
        else if (escolha == 4) {
            cout << "Direcionando para Descadastro de Evento" << endl;
            tela_descadastro_evento(container);
            escolha = -1;
        }
        else if (escolha == 5) {
            cout << "Direcionando para Alteracao de Evento" << endl;
            tela_alteracao_evento(container);
            escolha = -1;
        }
        else if (escolha == 6) {
            cout << "Direcionando para Descadastro do Sistema" << endl;
            tela_descadastro_usuario(container);
            escolha = -1;
        }
        else if (escolha == 7) {
            cout << "Direcionando para Consulta de Eventos" << endl;
            tela_consulta_evento(container);
            escolha = -1;
        }
        else if (escolha == 8) {
            cout << "Deslogando..." << endl;
            tela_inicial(container);
            continua = false;
        }
        else if(escolha == -1){
            cout << "################################################################" << endl;
            cout << "Escolha uma das seguintes opcoes para continuar" << endl;
            cout << "[1] Adquirir ingresso" << endl;
            cout << "[2] Informacoes de Venda dos Eventos" << endl;
            cout << "[3] Criar novo Evento" << endl;
            cout << "[4] Descadastrar Evento" << endl;
            cout << "[5] Alterar Evento" << endl;
            cout << "[6] Efetuar Descadastro do Sistema" << endl;
            cout << "[7] Consultar Eventos" << endl;
            cout << "[8] Deslogar" << endl;
            cin >> escolha;
            while(escolha < 1 || escolha > 8){
                cout << "Opcao invalida, por favor, escolha novamente" << endl;
                cin >> escolha;
            }
        }
    }
}
/**
 * @brief Tela de Adquirir Ingressos
 * 
 * @param container Interface do Banco de Dados
 */
void Interface_usuario::tela_adquirir_ingresso(Container &container) {
    cout << "################################################################" << endl;
    int escolha = 0;
    int quantidade = 0;
    string codigo_apresentacao;
    cout << "Deseja adquirir ingresso(s)?" << endl;
    cout << "[1] Sim" << endl;
    cout << "[2] Nao, desejo voltar para a tela principal" << endl;
    cin  >> escolha;
    while(escolha != 1 && escolha != 2){
        cout << "Opcao invalida, digite 1 para adquirir ingressos ou 2 para voltar ao menu principal" << endl;
        cin  >> escolha;
    }
    if(escolha == 2){
        return;
    }
    cout << "Informe o Codigo da Apresentacao: " << endl;
    cin  >> codigo_apresentacao;
    Apresentacao *apresentacao;
    while(escolha == 1){
        for(list <Apresentacao*>::iterator i = container.totalApresentacoes.begin(); i != container.totalApresentacoes.end(); i++){
            if((*i)->getCodigo_de_apresentacao() == codigo_apresentacao){
                cout << "Apresentacao encontrada" << endl;
                escolha = 3;
                apresentacao = (*i)->getApresentacao();
                break;
            }
        }
        if(escolha == 1){
            cout << "Apresentacao nao encontrada ou codigo invalido." << endl;
            cout << "Deseja tentar outro codigo?" << endl;
            cout << "[1] Sim" << endl;
            cout << "[2] Nao, desejo voltar para a tela principal" << endl;
            cin  >> escolha;
            while(escolha != 1 && escolha != 2){
                cout << "Opcao invalida, digite 1 para tentar inserir outro codigo ou 2 para voltar ao menu principal" << endl;
                cin  >> escolha;
            }
            if(escolha == 2){
                return;
            }
            else{
                cout << "Informe o Codigo da Apresentacao: " << endl;
                cin  >> codigo_apresentacao;
            }
        }
    }
    int disponivel = 0;
    disponivel = apresentacao->getDisponibilidade();
    if(disponivel > 0){
        cout << "Qual a quantidade de Ingressos voce deseja comprar?: " << endl;
        cin  >> quantidade;
        escolha = 0;    
        while(quantidade > disponivel || quantidade < 1){
            cout << "Temos apenas "<< disponivel << " ingressos disponiveis, deseja escolher uma quantidade menor?" << endl;
            cout << "[1] Sim" << endl;
            cout << "[2] Nao, voltar para o menu principal" << endl;
            cin  >> escolha;
            while(escolha != 1 && escolha != 2){
                cout << "Opcao invalida, digite 1 para adquirir ingressos ou 2 para voltar ao menu principal" << endl;
                cin  >> escolha;
            }
            if(escolha == 2){
                return;
            }
            cout << "Qual a quantidade de Ingressos voce deseja comprar?: " << endl;
            cin  >> quantidade;
        }
        apresentacao->vender(quantidade);
        apresentacao->adicionarCompradores(container.logado->getCpf());
        cout << "Ingressos adquiridos com sucesso" << endl;
        cout << "Apresentacao agora possui " << apresentacao->getDisponibilidade() << endl;
    }
    else{
        cout << "Desculpe, mas essa apresentacao ja esgotou todos os ingressos." << endl;
    }
}
/**
 * @brief Tela de cadastramento de evento
 * 
 * @param container Interface do Banco de Dados
 */
void Interface_usuario::tela_cadastro_evento(Container &container){
    CRUDEvento evento;
    evento.criarEvento(container);
}
/**
 * @brief Tela onde e possivel ver o relatorio de vendas dos Eventos em seu nome
 * 
 * @param container Interface do Banco de Dados
 */
void Interface_usuario::tela_relatorio_vendas(Container &container) {
    cout << "################################################################" << endl;
    if(container.logado->quantidade == 0){
        cout << "Voce nao possui eventos cadastrados para ver relatorios" << endl;
        return;
    }
    cout << "Deseja ver um relatorio das suas vendas?" << endl;
    cout << "[1] Sim" << endl;
    cout << "[2] Nao, voltar para o menu principal" << endl;
    int escolha;
    cin  >> escolha;
    while(escolha != 1 && escolha != 2){
        cout << "Opcao invalida, digite 1 para ver o relatorio ou 2 para voltar ao menu principal" << endl;
        cin  >> escolha;
    }
    if(escolha == 2)
        return;
    Usuario *usuario;
    usuario = container.logado;
    cout << "(Cod) (Nome) (Estado) (Cidade) (Classe) (Faixa etaria)" << endl;
    for(list <Evento>::iterator i = usuario->eventos.begin(); i!= usuario->eventos.end(); i++){
        if(!i->apagado){
            cout << " " << i->getCodigo_de_evento() << " | " << i->getNome_de_evento() << " | " << i->getEstado() << " | " << i->getCidade()
                 << " | ";
            switch(i->getClasse_de_evento()){
                case 1:
                    cout << "Teatro | ";
                    break;
                case 2:
                    cout << "Esporte | ";
                    break;
                case 3:
                    cout << "Show Nacional | ";
                    break;
                case 4:
                    cout << "Show Internacional | ";
                    break;
            }
            cout << i->getFaixa_etaria() << endl;
            cout << "Apresentacoes: " << i->quantidade << endl;
            cout << "(Cod) (Data) (Horario) (Preco) (Sala) (Disponibilidade)" << endl;
            i->listarApresentacoes();
            cout << "--------------------------------------------------------------------------" << endl << endl;
        }
    }
    escolha = 0;
    cout << "Deseja ver o cpf dos compradores de alguma apresentacao?" << endl;
    cout << "[1] Sim" << endl;
    cout << "[2] Nao, voltar para a tela principal" << endl;
    cin  >> escolha;
    while(escolha != 1 && escolha != 2){
        cout << "Opcao invalida, digite 1 ver o cpf dos compradores ou 2 para voltar ao menu principal" << endl;
        cin  >> escolha;
    }
    if(escolha == 2)
        return;
    for(list <Evento>::iterator i = container.logado->eventos.begin(); i != container.logado->eventos.end(); i++){
        if(i->apagado == false){
            cout << "CPF" << endl;
            for(list <Apresentacao>::iterator j = i->apresentacoes.begin(); j != i->apresentacoes.end(); j++){
                j->listarCpf();
            }
        }
    }
}
/**
 * @brief Tela para a consulta de eventos
 * 
 * @param container Interface do Banco de Dados
 */
void Interface_usuario::tela_consulta_evento(Container &container) {
    CRUDEvento evento;
    evento.consultaEvento(container);
}
/**
 * @brief Tela de descadastro de eventos do sistema
 * 
 * @param container Interface do Banco de Dados
 */
void Interface_usuario::tela_descadastro_evento(Container &container){
    CRUDEvento evento;
    evento.excluirEvento(container);
}
/**
 * @brief Tela de alteracao de evento do sistema
 * 
 * @param container Interface do Banco de Dados
 */
void Interface_usuario::tela_alteracao_evento(Container &container){ 
    CRUDEvento evento;
    evento.editarEvento(container);
}

/**
 * @brief Tela de descadastro do usuario do sistema
 * 
 * @param container Interface do Banco de Dados
 */
void Interface_usuario::tela_descadastro_usuario(Container &container){
    RemoveUsuario remover;
    remover.descadastrarUsuario(container);
}

bool Interface_usuario::tela_meus_eventos(Container &container) {
    Usuario *usuario;
    usuario = container.logado;
    cout << "###########################################################################" << endl;
    if (usuario->quantidade > 0) {
        cout << "(Cod) (Nome) (Estado) (Cidade) (Classe) (Faixa etaria)" << endl;
        for (list<Evento>::iterator i = usuario->eventos.begin(); i != usuario->eventos.end(); i++) {
            if (i->apagado == false) {
                cout << " " << i->getCodigo_de_evento() << " | " << i->getNome_de_evento() << " | " << i->getEstado()
                     << " | " << i->getCidade() << " | ";
                switch (i->getClasse_de_evento()) {
                    case 1:
                        cout << "Teatro | ";
                        break;
                    case 2:
                        cout << "Esporte | ";
                        break;
                    case 3:
                        cout << "Show Nacional | ";
                        break;
                    case 4:
                        cout << "Show Internacional | ";
                        break;
                }
                cout << i->getFaixa_etaria() << endl;
                cout << "Apresentacoes: " << i->quantidade << endl;
                cout << "(Cod) (Data) (Horario) (Preco) (Sala) (Disponibilidade)" << endl;
                i->listarApresentacoes();
                cout << "--------------------------------------------------------------------------" << endl << endl;
            }
        }
        return true;
    } else {
        cout << "Voce nao possui eventos registrados" << endl;
        return false;
    }
}