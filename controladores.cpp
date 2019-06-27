#include "controladores.h"
/**
 * @brief Funcao responsavel por fazer o login no sistema
 * 
 * @param cpf CPF informado pelo usuario
 * @param senha Senha informada pelo usuario
 * @param container Interface do Banco de dados 
 * @return true caso conta seja valida
 * @return false  caso conta nao seja valida
 */
bool Cadastro::login(string cpf, string senha, Container &container) {
    string cpfr;
    string senhar;
    bool achou = false;

    for(list<Usuario>::iterator i = container.totalUsuarios.begin(); i!= container.totalUsuarios.end(); i++){
        cpfr = i->getCpf();
        senhar = i->getSenha();
        if (cpfr == cpf && senhar == senha){
            if(i->apagado == false){
                cout << "Usuario encontrado, direcionando para sua pagina" << endl;
                container.logado = i->getUsuario();//Ponteiro 'logado' recebe o endereco do respectivo usuario da lista que esta logando
                achou = true;
            }
            else 
                cout << "Nao foi possivel logar pois a conta foi deletada" << endl;
        }
    }
    if(achou)
        return true;
    else
        return false;
}
/**
 * @brief Funcao responsavel pelo cadastro no banco de dados do sistema
 * 
 * @param totalUsuarios Lista com o total de usuarios do sistema
 * @param cpf CPF informado pelo usuario
 * @param senha Senha informada pelo usuario
 * @param numeros_cartoes_de_credito Numero informado pelo usuario
 * @param codigos Codigo de seguranca do cartao de credito
 * @param datas data de validade do cartao de credito
 */
void Cadastro::autenticar(list <Usuario> &totalUsuarios, string cpf, string senha, string numeros_cartoes_de_credito, string codigos,
                                     string datas){
    Usuario usuario;
    usuario.setUsuario(cpf, senha, numeros_cartoes_de_credito, codigos, datas);
    totalUsuarios.push_front(usuario);
}
/**
 * @brief Cria um novo evento atrelado ao usuario logado
 * 
 * @param container Interface do Banco de dados
 */
void CRUDEvento::criarEvento(Container &container){
    Usuario *usuario;
    usuario = container.logado;
    if(usuario->quantidade<5){
        cout << "Voce possui no momento " << usuario->quantidade  << " evento(s)" << endl;
    }
    if(usuario->quantidade == 5){
        cout << "Voce ja possui o maximo de eventos que um mesmo usuario pode cadastrar" << endl;
    }
    else{
        int quantidade = 0;
        usuario->adicionarEvento(container.quantidade_eventos, container.totalEventos, auxiliar_nome(), auxiliar_estado(), auxiliar_cidade(),
                                 auxiliar_classe(), auxiliar_faixa_etaria());

        string data;
        string horario;
        int preco;
        int sala;
        int disponibilidade;

        cout << "################################################################" << endl;
        cout << "Para fazer o cadastro do Evento, informe:" << endl;
        cout << "Quantas apresentacoes tera esse evento?" << endl;
        cin  >> quantidade;
        while(quantidade < 1 || quantidade > 10){
            cout << "Quantidade informada invalida, por favor, insira um valor entre 1 e 10" << endl;
            cin  >> quantidade;
        }
        for(int i = 1; i <= quantidade; i++){
            cout << "Apresentacao numero " << i << endl;
            data            = auxiliar_data();
            horario         = auxiliar_horario();
            preco           = auxiliar_preco();
            sala            = auxiliar_sala();
            disponibilidade = auxiliar_disponibilidade();
            usuario->eventos.front().adicionarApresentacao(container.quantidade_apresentacoes, container.totalEventos,
                                                           container.totalApresentacoes, data, horario, preco, sala, disponibilidade);
        }
    }
}
/**
 * @brief Edita um Evento ja criado, se nao foram vendidos ingressos ainda no sistema
 * 
 * @param container Interface do Banco de dados
 */
void CRUDEvento::editarEvento(Container &container){
    Usuario *usuario;
    usuario = container.logado;
    Evento *evento;
    int escolha;
    int escolha_apresentacao;
    bool achou = false;
    string escolha_cod_evento;
    string escolha_cod_apresentacao;
    cout << "Esses sao os seus eventos:" << endl;
    bool tem_evento = tela_meus_eventos(container);

    string nome_de_evento;
    string estado;
    string cidade;
    int classe_de_evento;
    string faixa_etaria;

    string data_apresentacao;
    string horario_apresentacao;
    int preco_apresentacao;
    int sala_apresentacao;
    int disponibilidade_apresentacao;


    if(tem_evento){
        cout << "Deseja alterar algum deles?" << endl;
        cout << "[1] Sim" << endl;
        cout << "[2] Nao, quero voltar a tela principal" << endl;
        cin  >> escolha;
        while(escolha != 1 && escolha != 2){
            cout << "Opcao invalida, por favor escolha 1 para alterar algum evento, ou 2 para voltar ao menu principal" << endl;
            cin  >> escolha;
        }
        if(escolha == 2){
            cout << "Voltando para pagina inicial" << endl;
            return;
        }
        cout << "Escolha o codigo do Evento" << endl;
        cin >> escolha_cod_evento;
        int vendeu = 0;
        while(!achou){
            for(list <Evento>::iterator i = usuario->eventos.begin(); i!= usuario->eventos.end(); i++){
                if(i->getCodigo_de_evento() == escolha_cod_evento){
                    evento = i->getEvento();
                    for(list <Apresentacao>::iterator j = evento->apresentacoes.begin(); j != evento->apresentacoes.end(); j++){
                        if(j->getDisponibilidade() != j->quantidade_original){
                            vendeu = 1;
                        }
                    }
                    if(!vendeu){
                        cout << "Codigo informado valido, indo para alteracao do evento escolhido" << endl;
                        achou = true;
                        cout << "Seu evento atualmente esta assim:" << endl;
                        cout << i->getCodigo_de_evento() << " || ";
                        cout << i->getNome_de_evento() << " || ";
                        cout << i->getEstado() << " || ";
                        cout << i->getCidade() << " || ";
                        switch( i->getClasse_de_evento()){
                            case 1:
                                cout << "Teatro || ";
                                break;
                            case 2:
                                cout << "Esporte || ";
                                break;
                            case 3:
                                cout << "Show Nacional || ";
                                break;
                            case 4:
                                cout << "Show Internacional || ";
                                break;
                        }
                        cout << i->getFaixa_etaria() << endl;

                        cout << "Faca suas alteracoes agora:" << endl;
                        cout << "Informe o novo Nome de Evento: " << endl;
                        getline(cin,nome_de_evento);
                        getline(cin,nome_de_evento);
                        cout << "Informe o novo Estado: " << endl;
                        cin >> estado;
                        cout << "Informe a nova Cidade: " << endl;
                        cin >> cidade;
                        cout << "Informe a nova Classe de evento: " << endl;
                        cin >> classe_de_evento;
                        cout << "Informe a nova Faixa etaria: " << endl;
                        cin >> faixa_etaria;

                        i->setEvento(i->getCodigo_de_evento(), nome_de_evento, estado, cidade, classe_de_evento, faixa_etaria);

                        cout << "Seu evento agora esta assim:" << endl;
                        cout << i->getCodigo_de_evento() << " || ";
                        cout << i->getNome_de_evento() << " || ";
                        cout << i->getEstado() << " || ";
                        cout << i->getCidade() << " || ";
                        switch( i->getClasse_de_evento()){
                            case 1:
                                cout << "Teatro || ";
                                break;
                            case 2:
                                cout << "Esporte || ";
                                break;
                            case 3:
                                cout << "Show Nacional || ";
                                break;
                            case 4:
                                cout << "Show Internacional || ";
                                break;
                        }
                        cout << i->getFaixa_etaria() << endl;

                        cout << "Deseja fazer edicao nas apresentacoes?" << endl;
                        cout << "[1] Sim" << endl;
                        cout << "[2] Nao, quero voltar a tela principal" << endl;
                        cin >> escolha_apresentacao;

                        while(escolha_apresentacao != 1 && escolha_apresentacao != 2){
                            cout << "Opcao invalida, por favor escolha 1 para alterar alguma apresentacao, ou 2 para voltar ao menu principal"
                                 << endl;
                            cin  >> escolha_apresentacao;
                        }
                        if(escolha_apresentacao == 2)
                            return;
                        cout << "Escolha qual apresentacao voce deseja modificar" << endl;
                        i->listarApresentacoes();
                        cout << "Escolha o codigo da Apresentacao" << endl;
                        cin >> escolha_cod_apresentacao;
                        int encontrou = 0;
                        for(list <Apresentacao>::iterator j = evento->apresentacoes.begin(); j != evento->apresentacoes.end(); j++){
                            if(j->getCodigo_de_apresentacao() == escolha_cod_apresentacao){
                                encontrou = 1;
                                cout << "Codigo informado valido, indo para alteracao de apresentacao escolhida" << endl;
                                cout << "Sua Apresentacao atualmente esta assim:" << endl;
                                cout << j->getCodigo_de_apresentacao() << " || ";
                                cout << j->getData() << " || ";
                                cout << j->getHorario() << " || ";
                                cout << j->getPreco() << " || ";
                                cout << j->getSala() << " || ";
                                cout << j->getDisponibilidade() << endl;

                                cout << "Faca suas alteracoes agora:" << endl;
                                cout << "Informe a nova Data: " << endl;
                                cin >> data_apresentacao;
                                cout << "Informe o novo Horario: " << endl;
                                cin >> horario_apresentacao;
                                cout << "Informe o novo Preco: " << endl;
                                cin >> preco_apresentacao;
                                cout << "Informe a nova Sala: " << endl;
                                cin >> sala_apresentacao;
                                cout << "Informe a nova Disponibilidade: " << endl;
                                cin >> disponibilidade_apresentacao;

                                j->setApresentacao(j->getCodigo_de_apresentacao(), data_apresentacao, horario_apresentacao,
                                                   preco_apresentacao, sala_apresentacao, disponibilidade_apresentacao);

                                cout << "Sua apresentacao agora esta assim:" << endl;
                                cout << j->getCodigo_de_apresentacao() << " || ";
                                cout << j->getData() << " || ";
                                cout << j->getHorario() << " || ";
                                cout << j->getPreco() << " || ";
                                cout << j->getSala() << " || ";
                                cout << j->getDisponibilidade() << endl;
                                break;
                            }
                        }
                        if(!encontrou){
                            cout << "O codigo informado nao corresponde a nenhuma de suas apresentacoes" << endl;
                        }
                    }
                    else{
                        cout << "Nao e possivel alterar esse evento pois ingressos ja foram vendidos" << endl;
                        cout << "Voltando para pagina inicial" << endl;
                        return;
                    }
                }
                else{
                    cout << "Codigo nao valido" << endl;
                    cin >> escolha_cod_evento;
                }
            }
        }
    }
}
/**
 * @brief Exclui um evento do sistema
 * 
 * @param container Interface do Banco de dados
 */
void CRUDEvento::excluirEvento(Container &container){
    if(container.logado->quantidade > 0){
        int erro = 0;
        int escolha = 0;
        tela_meus_eventos(container);
        cout << "Deseja descadastrar algum evento?" << endl;
        cout << "[1] Sim" << endl << "[2] Nao, voltar para tela principal" << endl;
        cin  >> escolha;
        while(escolha != 1 && escolha != 2){
            cout << "Opcao invalida, por favor, insira uma opcao valida" << endl;
            cin  >> escolha;
        }
        if(escolha == 2)
            return;
        else{
            Codigo_de_evento codigo;
            string codigo_teste;
            bool codigo_invalido;
            cout << "Digite o codigo do evento que deseja descadastrar" << endl;
            cin  >> codigo_teste;
            codigo_invalido = codigo.setCodigo_de_evento(codigo_teste);
            while(codigo_invalido){
                cout << "Codigo invalido, por favor, escolha um codigo valido(deve possuir 3 digitos)" << endl;
                cin  >> codigo_teste;
                codigo_invalido = codigo.setCodigo_de_evento(codigo_teste);
            }
            Evento *evento;
            /* Procura nos eventos do usuario se o codigo pertence a ele, se sim apaga todas as apresentacoes e o proprio evento
            tanto da lista do usuario quanto das listas do sistema */
            for(list <Evento>::iterator i = container.logado->eventos.begin(); i != container.logado->eventos.end(); i++){
                if(i->getCodigo_de_evento() == codigo_teste){
                    evento = i->getEvento();
                    Apresentacao *apresentacao;
                    string k;
                    int vendeu = 0;
                    for(list <Apresentacao>::iterator j = evento->apresentacoes.begin(); j != evento->apresentacoes.end(); j++){
                        if(j->getDisponibilidade() != j->quantidade_original){
                            vendeu = 1;
                        }
                    }
                    if(!vendeu){
                        for(list <Apresentacao>::iterator j = evento->apresentacoes.begin(); j != evento->apresentacoes.end(); j++){
                            k = j->getCodigo_de_apresentacao();
                            apresentacao = j->getApresentacao();
                            apresentacao->apagado = true;
                            cout << "Apresentacao " << k <<" apagada da lista do Evento do Usuario" << endl;
                        }
                        k = evento->getCodigo_de_evento();
                        evento->apagado = true;
                        evento->quantidade = 0;
                        container.logado->quantidade--;
                        cout << "Evento " << k << " apagado da lista do usuario" << endl;
                        break;
                    }
                    else{
                        cout << "Esse evento ja possui ingressos vendidos, portanto nao pode ser descadastrado" << endl;
                        erro = 1;
                    }
                }
                if(erro == 0){
                    cout << "Esse codigo nao corresponde a nenhum dos seus eventos" << endl;
                }
            }
        }
    }
    else{
        string voltar;
        cout << "Voce nao possui eventos cadastrados" << endl;
        cout << "Insira qualquer valor para retornar ao menu principal" << endl;
        cin  >> voltar;
        return;
    }
}
/**
 * @brief Realiza uma consulta com base na localizacao do evento
 * 
 * @param container Interface do Banco de dados
 */
void CRUDEvento::consultaEvento(Container &container){
    string aux_data_inicio, aux_data_termino;
    string temp;

    int dia_inicio = 0;
    int mes_inicio = 0;
    int ano_inicio = -1;

    int dia_termino = 0;
    int mes_termino = 0;
    int ano_termino = -1;

    string aux_cidade, aux_estado;
    bool inicio_teste, termino_teste, cidade_teste, estado_teste;
    Data inicio, termino;
    Cidade cidade;
    Estado estado;
    cout << "Qual a cidade do evento?" << endl;
    cin >> aux_cidade;
    cout << "Por favor, informe a sigla do Estado em que ocorrera o evento" << endl;
    cin >> aux_estado;

    for (list <Evento*>::iterator i = container.totalEventos.begin(); i != container.totalEventos.end(); i++){
        if(aux_cidade == (*i)->getCidade() && aux_estado == (*i)->getEstado()){
            cout << (*i)->getCodigo_de_evento() << " || ";
            cout << (*i)->getNome_de_evento() << " || ";
            cout << (*i)->getEstado() << " || ";
            cout << (*i)->getCidade() << " || ";
            cout << (*i)->getClasse_de_evento() << " || ";
            cout << (*i)->getFaixa_etaria() << endl;
            (*i)->listarApresentacoes();
        }
    }
}
/**
 * @brief Realiza o descadastro do Usuario do sistema
 * 
 * @param container Interface do Banco de dados
 */
void RemoveUsuario::descadastrarUsuario(Container &container){
    int escolha = 0;
    cout << "Deseja descadastrar o usuario?" << endl;
    cout << "Digite 1 para Sim, e 2 para Nao" << endl;
    cin  >> escolha;
    while(escolha != 1 && escolha != 2){
        cout << "Valor invalido, digite 1 caso queira descadastrar o usuario, e 2 caso nao queira" << endl;
        cin >> escolha;
    }
    if(escolha == 1){
        //testa se pode descadastrar(se o usuario tem algum evento aberto em seu nome)
        for(list <Usuario>::iterator i = container.totalUsuarios.begin(); i!= container.totalUsuarios.end(); i++){
            if(container.logado->getCpf() == i->getCpf()){
                cout << "Usuario encontrado no Banco de Dados, verificando se e possivel apagar a conta" << endl;
                if(container.logado->quantidade > 0){
                    cout << "Nao foi possivel realizar o descadastramento pois voce ainda possui eventos abertos em seu nome" << endl;//se nao puder
                }
                else{
                    container.logado->apagado = true;
                    cout << "Usuario descadastrado com sucesso" << endl;//se puder
                    cout << "Voltando para pagina inicial" << endl;
                    tela_inicial(container);
                }
            }
        }
    }//se o cara desistir(escolher 2), nao precisa fazer nada, so deixa a funcao acabar
    else if(escolha == 2){
        cout << "Voltando para pagina principal" << endl;
    }
}
/**
 * @brief Funcao auxiliar 
 * 
 * @return string 
 */
string Auxiliar::auxiliar_nome(){
    string nome_do_evento;
    bool nome_de_evento_teste;
    Nome_de_evento objeto_nome_de_evento;

    cout << "Nome do Evento:" << endl;
    getline(cin,nome_do_evento);
    getline(cin,nome_do_evento);
    nome_de_evento_teste = objeto_nome_de_evento.setNome_de_evento(nome_do_evento);
    while(nome_de_evento_teste){
        cout << "Nome de evento invalido, por favor, escolha outro nome" << endl;
        getline(cin,nome_do_evento);
        nome_de_evento_teste = objeto_nome_de_evento.setNome_de_evento(nome_do_evento);
    }
    cout << "Nome do evento confirmado" << endl;
    return nome_do_evento;
}
/**
 * @brief Funcao auxiliar 
 * 
 * @return string 
 */
string Auxiliar::auxiliar_estado(){
    string estado;
    bool estado_teste = false;
    Estado objeto_estado;

    cout << "Estado do evento:" << endl;
    cin  >> estado;
    estado_teste = objeto_estado.setEstado(estado);
    while(estado_teste){
        cout << "Estado invalido, por favor, insira um estado valido" << endl;
        cin  >> estado;
        estado_teste = objeto_estado.setEstado(estado);
    }
    cout << "Estado escolhido com sucesso" << endl;
    return estado;
}
/**
 * @brief Funcao auxiliar 
 * 
 * @return string 
 */
string Auxiliar::auxiliar_cidade(){
    string cidade;
    bool cidade_teste = false;
    Cidade objeto_cidade;

    cout << "Cidade do evento:" << endl;
    getline(cin,cidade);
    getline(cin,cidade);
    cidade_teste = objeto_cidade.setCidade(cidade);
    while(cidade_teste){
        cout << "Cidade invalida, por favor, selecione uma cidade valida" << endl;
        getline(cin,cidade);
        cidade_teste = objeto_cidade.setCidade(cidade);
    }
    cout << "Cidade escolhida com sucesso" << endl;
    return cidade;
}
/**
 * @brief Funcao auxiliar 
 * 
 * @return int 
 */
int Auxiliar::auxiliar_classe(){
    int classe;
    bool classe_teste = false;
    Classe_de_evento objeto_classe;

    cout << "Classe do evento:" << endl;
    cin  >> classe;
    classe_teste = objeto_classe.setClasse_de_evento(classe);
    while(classe_teste){
        cout << "Classe invalida, por favor, insira uma classe valida" << endl;
        cin  >> classe;
        classe_teste = objeto_classe.setClasse_de_evento(classe);
    }
    switch(classe){
        case 1:
            cout << "Teatro escolhido" << endl;
            break;
        case 2:
            cout << "Esporte escolhido" << endl;
            break;
        case 3:
            cout << "Show Nacional escolhido" << endl;
            break;
        case 4:
            cout << "Show Internacional escolhido" << endl;
            break;
    }
    return classe;
}
/**
 * @brief Funcao auxiliar 
 * 
 * @return string 
 */
string Auxiliar::auxiliar_faixa_etaria(){
    string faixa;
    bool faixa_teste = false;
    Faixa_etaria objeto_faixa_etaria;

    cout << "Faixa etaria do evento:" << endl;
    cin  >> faixa;
    faixa_teste = objeto_faixa_etaria.setFaixa_etaria(faixa);
    while(faixa_teste){
        cout << "Faixa etaria invalida, por favor, insira uma faixa etaria valida" << endl;
        cin  >> faixa;
        faixa_teste = objeto_faixa_etaria.setFaixa_etaria(faixa);
    }
    cout << "Faixa etaria selecionada com sucesso" << endl;
    return faixa;
}
/**
 * @brief Funcao auxiliar 
 * 
 * @return string 
 */
string Auxiliar::auxiliar_data(){
    string data;
    bool data_teste = false;
    Data objeto_data;

    cout << "Data da apresentacao:" << endl;
    cin  >> data;
    data_teste = objeto_data.setData(data);
    while(data_teste){
        cout << "Data invalida, por favor, escolha uma data valida" << endl;
        cin  >> data;
        data_teste = objeto_data.setData(data);
    }
    cout << "Data da apresentacao escolhida com sucesso" << endl;
    return data;
}
/**
 * @brief Funcao auxiliar 
 * 
 * @return string 
 */
string Auxiliar::auxiliar_horario(){
    string horario;
    bool horario_teste = false;
    Horario objeto_horario;

    cout << "Horario da apresentacao:" << endl;
    cin  >> horario;
    horario_teste = objeto_horario.setHorario(horario);
    while(horario_teste){
        cout << "Horario invalido, por favor, escolha um horario valido" << endl;
        cin  >> horario;
        horario_teste = objeto_horario.setHorario(horario);
    }
    cout << "Horario escolhido com sucesso" << endl;
    return horario;
}
/**
 * @brief Funcao auxiliar 
 * 
 * @return int 
 */
int Auxiliar::auxiliar_preco(){
    int preco;
    bool preco_teste = false;
    Preco objeto_preco;

    cout << "Preco do ingresso:" << endl;
    cin  >> preco;
    preco_teste = objeto_preco.setPreco(preco);
    while(preco_teste){
        cout << "Preco invalido, por favor, escolha um preco valido" << endl;
        cin  >> preco;
        preco_teste = objeto_preco.setPreco(preco);
    }
    cout << "Preco do ingresso dessa apresentacao escolhido com sucesso" << endl;
    return preco;
}
/**
 * @brief Funcao auxiliar 
 * 
 * @return int 
 */
int Auxiliar::auxiliar_sala(){
    int sala;
    bool sala_teste = false;
    Numero_de_sala objeto_sala;

    cout << "Sala da apresentacao:" << endl;
    cin  >> sala;
    sala_teste = objeto_sala.setSala(sala);
    while(sala_teste){
        cout << "Sala invalida, por favor, selecione uma sala valida" << endl;
        cin  >> sala;
        sala_teste = objeto_sala.setSala(sala);
    }
    cout << "Sala escolhida com sucesso" << endl;
    return sala;
}
/**
 * @brief Funcao auxiliar 
 * 
 * @return int 
 */
int Auxiliar::auxiliar_disponibilidade(){
    int disponibilidade;
    bool disponibilidade_teste = false;
    Disponibilidade objeto_disponibilidade;

    cout << "Numero de ingressos disponiveis" << endl;
    cin  >> disponibilidade;
    disponibilidade_teste = objeto_disponibilidade.setDisponibilidade(disponibilidade);
    while(disponibilidade_teste){
        cout << "Quantidade invalida, por favor, escolha uma quantidade valida" << endl;
        cin  >> disponibilidade;
        disponibilidade_teste = objeto_disponibilidade.setDisponibilidade(disponibilidade);
    }
    cout << "Quantidade de ingressos selecionada com sucesso" << endl;
    cout << "Apresentacao marcada com sucesso" << endl;
    cout << "################################################################" << endl;
    return disponibilidade;
}