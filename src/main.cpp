#include "bancoDao.hpp"
#include <iostream>
#include <string>
#include "pessoa.hpp"
#include "endereco.hpp"
#include "professor.hpp"
#include "funcionario.hpp"
#include "tecnico_adm.hpp"
#include "./excecoes/mainExcecoes.hpp"

using namespace std;

/**
* @file: main.cpp
* @brief Programa principal para interação com o sistema de cadastro de professores e técnicos ADM.
* @authores: Matheus Barros Medeiros, William de Abreu Martins Oliveira, Flavio Germano Pinheiro.
* @Date Data de criação (10 de dezembro de 2023)
*/

/**
 * @brief Exibe o menu principal do programa.
 */
void mostrarMenu() {
    cout << "========== MENU PRINCIPAL ==========" << endl;
    cout << "1. Cadastrar Professor" << endl;
    cout << "2. Listar Professores" << endl;
    cout << "3. Deletar Professor" << endl;
    cout << "4. Buscar Professor" << endl;
    cout << "5. Cadastrar Tecnico ADM" << endl;
    cout << "6. Listar Tecnicos ADM" << endl;
    cout << "7. Deletar Tecnico ADM" << endl;
    cout << "8. Buscar Tecnico ADM" << endl;
    cout << "9. Imprimir Salario Professor" << endl;
    cout << "10. Imprimir Salario Tecnico" << endl;
    cout << "0. Sair" << endl;
    cout << "====================================" << endl;
    cout << "Escolha uma opcao: \n\n";
}

/**
 * @brief Função principal do programa.
 * @return 0 se o programa for concluído com sucesso.
 */
int main()
{
    int escolha;
    int matriculaParaBuscar;
    BancoDao banco;
    Professor prof;
    TecnicoADM tecn;

    do {
        try{
            mostrarMenu();
            cin >> escolha;
            cin.ignore();

            // Tratamento de erro com o Throw
            if(escolha > 10 || escolha < 0){
                throw mainExcecoes("O valor informado nao esta entre as opcoes disponiveis, por favor informe um valor entre 1 e 10.");
            }

            switch (escolha) {
                case 1:
                    banco.cadastrarProfessor(banco.professores);
                    break;
                case 2:
                    banco.listarProfessores();
                    break;
                case 3:
                    cout << "Digite a matricula do professor para deletar: ";
                    matriculaParaBuscar = banco.lerNumero();
                    banco.deletarProfessor(matriculaParaBuscar);
                    break;
                case 4:
                    cout << "Digite a matricula do professor para buscar: ";
                    matriculaParaBuscar = banco.lerNumero();
                    banco.buscarProfessor(matriculaParaBuscar);
                    break;
                case 5:
                    banco.cadastrarTecnicoADM(banco.tecnicosADM);
                    break;
                case 6:
                    banco.listarTecnicosADM();
                    break;
                case 7:
                    cout << "Digite a matricula do tecnico ADM para deletar: ";
                    matriculaParaBuscar = banco.lerNumero();
                    banco.deletarTecnicoADM(matriculaParaBuscar);
                    break;
                case 8:
                    cout << "Digite a matricula do tccnico ADM para buscar: ";
                    matriculaParaBuscar = banco.lerNumero();
                    banco.buscarTecnicoADM(matriculaParaBuscar);
                    break;
                case 9:
                    cout << "Digite a matricula do PROFESSOR para visualizar o Salario: ";
                    matriculaParaBuscar = banco.lerNumero();
                    prof.imprimirSalarioDoFuncionarioByMatricula(matriculaParaBuscar);
                    break;
                case 10:
                    cout << "Digite a matricula do tccnico ADM para visualizar o Salario: ";
                    matriculaParaBuscar = banco.lerNumero();
                    tecn.imprimirSalarioDoFuncionarioByMatricula(matriculaParaBuscar);
                    break;
                case 0:
                    cout << "Saindo do programa...\n\n" << endl;
                    break; 
                default:
                    break;
            }
        }
        catch(const mainExcecoes& erro){
            cout << "================================================================================================================" << endl;
            cout << "| ERROR: " << erro.what() << endl;
            cout << "================================================================================================================" << endl;
        }

    } while (escolha != 0);

    return 0;
}
