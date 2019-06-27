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
bool Usuario::setUsuario(string cpf, string senha, string numero_do_cartao_de_credito, string codigo_de_seguranca, string data_de_validade){
    bool b_cpf, b_senha, b_cartao, b_seg, b_data;
    Cpf cpf_teste;
    Senha senha_teste;
    Numero_do_cartao_de_credito cartao_teste;
    Codigo_de_seguranca codigo_teste;
    Data_de_validade data_teste;
    b_cpf    = cpf_teste.setCpf(cpf);
    b_senha  = senha_teste.setSenha(senha);
    b_cartao = cartao_teste.set_Numero_do_cartao_de_credito(numero_do_cartao_de_credito);
    b_seg    = codigo_teste.setCodigo_de_seguranca(codigo_de_seguranca);
    b_data   = data_teste.setData_de_validade(data_de_validade);

    if(!b_cpf && !b_senha && !b_cartao && !b_seg && !b_data){
        this->cpf.setCpf(cpf);
        this->senha.setSenha(senha);
        this->numero_do_cartao_de_credito.set_Numero_do_cartao_de_credito(numero_do_cartao_de_credito);
        this->codigo_de_seguranca.setCodigo_de_seguranca(codigo_de_seguranca);
        this->data_de_validade.setData_de_validade(data_de_validade);
        return false;
    }
    else
        return true;
}

void Usuario::adicionarEvento(int &quantidade_eventos, list <Evento*> &totalEventos, string nome_de_evento, string estado, string cidade,
                              int classe_de_evento, string faixa_etaria){
    this->quantidade++;
    quantidade_eventos++;
    string aux, aux2, aux3;
    int aux4;
    aux  = "0";
    aux2 = "00"; 
    aux4 = quantidade_eventos;
    aux3 = std::to_string(aux4);
    Evento evento;
    if(quantidade_eventos      < 10)
        aux3 = aux2 + aux3;
    else if(quantidade_eventos < 100)
        aux3 = aux  + aux3;
    evento.setEvento(aux3, nome_de_evento, estado, cidade, classe_de_evento, faixa_etaria);
    this->eventos.push_front(evento);//Lista de eventos desse usuario
    totalEventos.push_front(&this->eventos.front());//Lista de eventos do sistema
}
/**
 * @brief Responsavel pela entidade de apresentacao do programa
 * 
 * @param string_numero Codigo de apresentacao
 * @param string_data Data da apresentacao
 * @param string_horario Horario da apresentacao
 * @param int_preco Preco do ingresso
 * @param int_sala Numero de sala
 * @param int_disponibilidade Disponibilidade no sistema
 */
void Apresentacao::setApresentacao(string codigo_de_apresentacao, string data, string horario, int preco, int sala, int disponibilidade){  
    this->codigo_de_apresentacao.setCodigo_de_apresentacao(codigo_de_apresentacao);
    this->data.setData(data);
    this->horario.setHorario(horario);
    this->preco.setPreco(preco);
    this->sala.setSala(sala);
    this->disponibilidade.setDisponibilidade(disponibilidade);
    this->quantidade_original = disponibilidade;
}

string Apresentacao::getCodigo_de_apresentacao(){
    return this->codigo_de_apresentacao.getCodigo();
}

string Apresentacao::getData(){
    return this->data.getData();
}

string Apresentacao::getHorario(){
    return this->horario.getHorario();
}

int Apresentacao::getPreco(){
    return this->preco.getPreco();
}

int Apresentacao::getSala(){
    return this->sala.getSala();
}

int Apresentacao::getDisponibilidade(){
    return this->disponibilidade.getDisponibilidade();
}

void Apresentacao::vender(int quantidade){
    int atual = 0;
    atual = this->disponibilidade.getDisponibilidade();
    atual -= quantidade;
    this->disponibilidade.setDisponibilidade(atual);
}

void Apresentacao::adicionarCompradores(string cpf){
    Cpf objeto_cpf;
    objeto_cpf.setCpf(cpf);
    this->compradores.push_front(objeto_cpf);
}

void Apresentacao::listarCpf(){
    for(list<Cpf>::iterator i = this->compradores.begin(); i != this->compradores.end(); i++){
        cout << i->getCpf() << endl;
    }
}

void Evento::setEvento(string codigo_de_evento, string nome_de_evento, string estado, string cidade, int classe_de_evento,
                       string faixa_etaria){
    this->codigo_de_evento.setCodigo_de_evento(codigo_de_evento);
    this->nome_de_evento.setNome_de_evento(nome_de_evento);
    this->estado.setEstado(estado);
    this->cidade.setCidade(cidade);
    this->classe_de_evento.setClasse_de_evento(classe_de_evento);
    this->faixa_etaria.setFaixa_etaria(faixa_etaria);
}

void Evento::adicionarApresentacao(int &quantidade_apresentacoes, list<Evento*> &totalEventos, list <Apresentacao*> &totalApresentacoes,
                                   string data, string horario, int preco, int sala, int disponibilidade){
    this->quantidade++;//Quantidade de apresentacoes desse evento
    quantidade_apresentacoes++;//Quantidade de apresentacoes do sistema
    Apresentacao apresentacao;
    string aux, aux2, aux3, aux4;
    int aux5;
    aux  = "000";
    aux2 = "00";
    aux3 = "0";
    aux5 = quantidade_apresentacoes;
    aux4 = std::to_string(aux5);
    if(quantidade_apresentacoes < 10)
        aux4 = aux+aux4;  //0001...0009
    else if(quantidade_apresentacoes < 100)
        aux4 = aux2+aux4; //0010...0099
    else if(quantidade_apresentacoes < 1000)
        aux4 = aux3+aux4; //0100...0999
    apresentacao.setApresentacao(aux4, data, horario, preco, sala, disponibilidade);
    this->apresentacoes.push_front(apresentacao);//Lista de apresentacoes desse evento desse usuario
    totalApresentacoes.push_front(&this->apresentacoes.front());//Lista de apresentacoes totais do sistema
}

void Evento::listarApresentacoes(){
    for(list <Apresentacao>::iterator i = this->apresentacoes.begin(); i != this->apresentacoes.end(); i++){
        cout << i->getCodigo_de_apresentacao() << " | " << i->getData() << " | " << i->getHorario() << " | " << i->getPreco() << " | "
             << i->getSala() << " | " << i->getDisponibilidade() << endl;
        cout << "Ingressos vendidos: " << i->quantidade_original - i->getDisponibilidade() << endl;
    }
}

string Evento::getCodigo_de_evento(){
    return this->codigo_de_evento.getCodigo();
}

string Evento::getNome_de_evento(){
    return this->nome_de_evento.getNome_de_evento();
}

string Evento::getCidade(){
    return this->cidade.getCidade();
}

string Evento::getEstado(){
    return this->estado.getEstado();
}

int Evento::getClasse_de_evento(){
    return this->classe_de_evento.getClasse_de_evento();
}

string Evento::getFaixa_etaria(){
    return this->faixa_etaria.getFaixa_etaria();
}
void Ingresso::setIngresso(string cod_ingressos){
    bool b_cod_ingressos;
    b_cod_ingressos = codigo_de_ingresso.setCodigo_de_ingresso(cod_ingressos);
    
    if(!b_cod_ingressos){
        this->cod_ingressos = cod_ingressos;
    }
}

string Usuario::getCpf(){
    return this->cpf.getCpf();
}
string Usuario::getSenha(){
    return this->senha.getSenha();
}
string Usuario::getNumero_do_cartao_de_credito(){
    return this->numero_do_cartao_de_credito.get_Numero_do_cartao_de_credito();
}
string Usuario::getCodigo_de_seguranca(){
    return this->codigo_de_seguranca.getCodigo();
}
string Usuario::getData_de_validade(){
    return this->data_de_validade.getData_de_validade();
}