#ifndef __TESTES_H__
#define __TESTES_H__

#include "dominios.h"
#include "entidades.h"

class Testes{
    private:
        Codigo_de_evento codigo_evento;
        Codigo_de_apresentacao codigo_apresentacao;
        Codigo_de_ingresso codigo_igresso;
        Nome_de_evento teste_nome_evento;
        Data testa_Data1;
        Data testa_Data2;
        Horario testa_horario1;
        Horario testa_horario2;
        Preco testa_preco1;
        Preco testa_preco2;
        Numero_de_sala testa_sala1;
        Numero_de_sala testa_sala2;
        Disponibilidade testa_disponibilidade;
        Classe_de_evento testa_evento;
        Faixa_etaria testa_faixa;
        Cidade testa_cidade;
        Estado testa_estado;
        Cpf teste_cpf;
        Senha teste_senha;
        Codigo_de_seguranca testa_codigo_seguranca;
        Usuario teste_usuario;
        Evento teste_evento;
        Apresentacao teste_apresentacao;


        void teste_Codigo_de_evento(){
            cout << "####################################" << endl;
            cout << "Começando testes de Codigo de evento" << endl;
            cout << "####################################" << endl << endl;
            codigo_evento.setCodigo_de_evento("250");
            cout << "Codigo Testado: 250" << endl;
            codigo_evento.setCodigo_de_evento("10");
            cout << "Codigo Testado: 10" << endl;
            codigo_evento.setCodigo_de_evento("1200");
            cout << "Codigo Testado: 1200" << endl;
            cout << endl <<"######################################" << endl;
            cout << "Termino dos testes de Codigo de evento" << endl;
            cout << "######################################" << endl << endl;
        }

        void teste_Codigo_de_apresentacao(){
            cout << "##########################################" << endl;
            cout << "Começando testes de Codigo de apresentacao" << endl;
            cout << "##########################################" << endl << endl;
            codigo_apresentacao.setCodigo_de_apresentacao("2000");
            cout << "Codigo Testado: 2000" << endl;
            codigo_apresentacao.setCodigo_de_apresentacao("200");
            cout << "Codigo Testado: 200" << endl;
            codigo_apresentacao.setCodigo_de_apresentacao("20000");
            cout << "Codigo Testado: 20000" << endl;
            cout << endl << "############################################" << endl;
            cout << "Termino dos testes de Codigo de apresentacao" << endl;
            cout << "############################################" << endl << endl;
        }

        void teste_Codigo_de_ingresso(){
            cout << "######################################" << endl;
            cout << "Começando testes de Codigo de ingresso" << endl;
            cout << "######################################" << endl << endl;
            codigo_igresso.setCodigo_de_ingresso("2000");
            cout << "Codigo Testado: 2000" << endl;
            codigo_igresso.setCodigo_de_ingresso("200");
            cout << "Codigo Testado: 200" << endl;
            codigo_igresso.setCodigo_de_ingresso("20000");
            cout << "Codigo Testado: 20000" << endl;
            cout << endl << "########################################" << endl;
            cout << "Termino dos testes de Codigo de ingresso" << endl;
            cout << "########################################" << endl << endl;
        }

        void teste_Nome_de_evento(){
            cout << "##################################" << endl;
            cout << "Começando testes de Nome de evento" << endl;
            cout << "##################################" << endl << endl;
            cout << "Codigo Testado: Lollapaloza" << endl;
            teste_nome_evento.setNome_de_evento("Lollapaloza");
            cout << "Codigo Testado: a   a" << endl;
            teste_nome_evento.setNome_de_evento("a   a");
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de Nome de evento" << endl;
            cout << "####################################" << endl << endl;

        }

        void teste_Data(){
            cout << "##################################" << endl;
            cout << "Começando testes de Data" << endl;
            cout << "##################################" << endl << endl;
            cout << "Codigo Testado: 12/08/97" << endl;
            testa_Data1.setData("12/08/97");
            cout << "Codigo Testado: 30/02/13" << endl;
            testa_Data2.setData("30/02/13");
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de Data" << endl;
            cout << "####################################" << endl << endl;
        }

        void teste_Horario(){
            cout << "##################################" << endl;
            cout << "Começando testes de Horario" << endl;
            cout << "##################################" << endl << endl;
            cout << "Codigo Testado: 18:00" << endl;
            testa_horario1.setHorario("18:00");
            cout << "Codigo Testado: 5:00" << endl;
            testa_horario1.setHorario("5:00");
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de Horario" << endl;
            cout << "####################################" << endl << endl;
        }

        void teste_Preco(){
            cout << "##################################" << endl;
            cout << "Começando testes de Preco" << endl;
            cout << "##################################" << endl << endl;
            cout << "Codigo Testado: 500" << endl;
            testa_preco1.setPreco(500);
            cout << "Codigo Testado: 2000" << endl;
            testa_preco1.setPreco(2000);
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de Preco" << endl;
            cout << "####################################" << endl << endl;
        }

        void teste_Numero_de_sala(){
            cout << "##################################" << endl;
            cout << "Começando testes de Sala" << endl;
            cout << "##################################" << endl << endl;
            cout << "Codigo Testado: 4" << endl;
            testa_sala1.setSala(4);
            cout << "Codigo Testado: 11" << endl;
            testa_sala2.setSala(11);
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de Sala" << endl;
            cout << "####################################" << endl << endl;
        }

        void teste_Disponibilidade(){
            cout << "##################################" << endl;
            cout << "Começando testes de Disponibilidade" << endl;
            cout << "##################################" << endl << endl;
            cout << "Codigo Testado: 4" << endl;
            testa_disponibilidade.setDisponibilidade(4);
            cout << "Codigo Testado: 8000" << endl;
            testa_disponibilidade.setDisponibilidade(8000);            
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de Disponibilidade" << endl;
            cout << "####################################" << endl << endl;
        }

        void teste_Classe_de_evento(){
            cout << "##################################" << endl;
            cout << "Começando testes de Classe de evento" << endl;
            cout << "##################################" << endl << endl;
            cout << "Codigo Testado: 1" << endl;
            testa_evento.setClasse_de_evento(1);
            cout << "Codigo Testado: 8" << endl;
            testa_evento.setClasse_de_evento(8);
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de Classe de evento" << endl;
            cout << "####################################" << endl << endl;
        }

        void teste_Faixa_etaria(){
            cout << "##################################" << endl;
            cout << "Começando testes de Faixa etaria" << endl;
            cout << "##################################" << endl << endl;
            cout << "Codigo Testado: L" << endl;
            testa_faixa.setFaixa_etaria("L");
            cout << "Codigo Testado: 21" << endl;
            testa_faixa.setFaixa_etaria("21");
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de Faixa etaria" << endl;
            cout << "####################################" << endl << endl;
        }

        void teste_Cidade(){
            cout << "##################################" << endl;
            cout << "Começando testes de Cidade" << endl;
            cout << "##################################" << endl << endl;
            cout << "Codigo Testado: Cidade1" << endl;
            testa_cidade.setCidade("Cidade1");
            cout << "Codigo Testado: Cidade2.c" << endl;
            testa_cidade.setCidade("Cidade1.c");            
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de Cidade" << endl;
            cout << "####################################" << endl << endl;
        }

        void teste_Estado(){
            cout << "##################################" << endl;
            cout << "Começando testes de Estado" << endl;
            cout << "##################################" << endl << endl;
            cout << "Codigo Testado: DF" << endl;
            testa_estado.setEstado("DF");
            cout << "Codigo Testado: Sul" << endl;
            testa_estado.setEstado("Sul");
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de Estado" << endl;
            cout << "####################################" << endl << endl;

        }

        void teste_Cpf(){
            cout << "##################################" << endl;
            cout << "Começando testes de CPF" << endl;
            cout << "##################################" << endl << endl;
            cout << "Codigo Testado: 06762463118" << endl;
            teste_cpf.setCpf("06762463118");
            cout << "Codigo Testado: 06766463118" << endl;
            teste_cpf.setCpf("06766463118");
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de CPF" << endl;
            cout << "####################################" << endl << endl;
        }

        void teste_Senha(){
            cout << "##################################" << endl;
            cout << "Começando testes de Senha" << endl;
            cout << "##################################" << endl << endl;
            cout << "Codigo Testado: senha1" << endl;
            teste_senha.setSenha("senha1");
            cout << "Codigo Testado: Senha1" << endl;
            teste_senha.setSenha("Senha1");
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de Senha" << endl;
            cout << "####################################" << endl << endl;
        }

        void teste_Codigo_seguranca(){
            cout << "##################################" << endl;
            cout << "Começando testes de Codigo de Seguranca" << endl;
            cout << "##################################" << endl << endl;
            cout << "Codigo Testado: 123" << endl;
            testa_codigo_seguranca.setCodigo_de_seguranca("123");
            cout << "Codigo Testado: 1234" << endl;
            testa_codigo_seguranca.setCodigo_de_seguranca("1234");
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de Codigo de Seguranca" << endl;
            cout << "####################################" << endl << endl;
        }

        /*void teste_Usuario(){
            cout << "############################" << endl;
            cout << "Iniciando testes de usuario" << endl;
            cout << "############################" << endl << endl << endl;
            cout << "Usuario testado: 06762463118, Senha1" << endl;
            teste_usuario.setUsuario("06762463118", "Senha1", "5555666677778884", "123", "10/21");
            cout << "Usuario testado: 09762463118, senha2" << endl;
            teste_usuario.setUsuario("09762463118", "senha2", "4012001037141112", "456", "12/25");
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de usuario" << endl;
            cout << "####################################" << endl << endl;
        }
        */
        void teste_Evento(){
            cout << "############################" << endl;
            cout << "Iniciando testes de evento" << endl;
            cout << "############################" << endl << endl << endl;
            cout << "Evento Testado: 100, Evento1, Brasilia, DF, 1, L" << endl;
            teste_evento.setEvento("100", "Evento1", "Brasilia", "DF", 1, "L");
            cout << "Evento Testado: 1000, Evento1, Brasilia, DF, 1, L" << endl;
            teste_evento.setEvento("1000", "Evento", "Brasiliaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "US", 23, "52");
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de evento" << endl;
            cout << "####################################" << endl << endl;
        }

        void teste_Apresentacao(){
            cout << "############################" << endl;
            cout << "Iniciando testes de apresentacao" << endl;
            cout << "############################" << endl << endl << endl;
            cout << "Codigo de apresentacao: 2000,  Data: 28/04/19, Horario: 15:00, Preco: 150, Valor de sala: 4, Disponibilidade: 45" << endl;
            teste_apresentacao.setApresentacao("2000", "28/04/19", "15:00", 150, 4, 45);
            cout << "Codigo de apresentacao: 200,  Data: 42/24/22, Horario: 15:34, Preco: 150, Valor de sala: 4, Disponibilidade: 45" << endl;
            teste_apresentacao.setApresentacao("200", "42/24/22", "15:34", 150, 4, 45);
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de apresentacao" << endl;
            cout << "####################################" << endl << endl;
        }

    public:
    
        void testesDominios(){
            cout << "############################" << endl;
            cout << "Iniciando testes de dominios" << endl;
            cout << "############################" << endl << endl << endl;
            teste_Codigo_de_evento();
            teste_Codigo_de_apresentacao();
            teste_Codigo_de_ingresso();
            teste_Nome_de_evento();
            teste_Data();
            teste_Horario();
            teste_Preco();
            teste_Numero_de_sala();
            teste_Disponibilidade();
            teste_Classe_de_evento();
            teste_Faixa_etaria();
            teste_Cidade();
            teste_Estado();
            teste_Cpf();
            teste_Senha();
            teste_Codigo_seguranca();
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de dominios" << endl;
            cout << "####################################" << endl << endl;
        }

        void testesEntidades(){
            cout << "############################" << endl;
            cout << "Iniciando testes de entidades" << endl;
            cout << "############################" << endl << endl << endl;
            //teste_Usuario();
            teste_Evento();
            teste_Apresentacao();
            cout << endl <<"####################################" << endl;
            cout << "Termino dos testes de entidades" << endl;
            cout << "####################################" << endl << endl;
        }

};

#endif