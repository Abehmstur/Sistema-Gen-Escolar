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

//menuzinho
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
    cout << "9. Sair" << endl;
    cout << "====================================" << endl;
    cout << "Escolha uma opcao: \n\n";
}

int main()
{
    int escolha;
    BancoDao banco;

    do {
        try{
            mostrarMenu();
            cin >> escolha;
            cin.ignore();
            //Tratamento de erro com o Throw
            if(escolha > 9 || escolha < 1){
                throw mainExcecoes("O valor informado nao esta entre as opcoes disponiveis, por favor informe um valor entre 1 e 9.");
            }

            switch (escolha) {
                case 1:
                    banco.cadastrarProfessor(banco.professores);
                    break;
                case 2:
                    banco.listarProfessores();
                    break;
                case 3:
                    int matriculaParaDeletar;
                    cout << "Digite a matricula do professor para deletar: ";
                    cin >> matriculaParaDeletar;
                    banco.deletarProfessor(matriculaParaDeletar);
                    break;
                case 4:
                    int matriculaParaBuscar;
                    cout << "Digite a matricula do professor para buscar: ";
                    cin >> matriculaParaBuscar;
                    banco.buscarProfessor(matriculaParaBuscar);
                    break;
                case 5:
                    banco.cadastrarTecnicoADM(banco.tecnicosADM);
                    break;
                case 6:
                    banco.listarTecnicosADM();
                    break;
                case 7:
                    int matriculaParaDeletarTecnico;
                    cout << "Digite a matricula do tecnico ADM para deletar: ";
                    cin >> matriculaParaDeletarTecnico;
                    banco.deletarTecnicoADM(matriculaParaDeletarTecnico);
                    break;
                case 8:
                    int matriculaParaBuscarTecnico;
                    cout << "Digite a matricula do tccnico ADM para buscar: ";
                    cin >> matriculaParaBuscarTecnico;
                    banco.buscarTecnicoADM(matriculaParaBuscarTecnico);
                    break;
                case 9:
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
        
    } while (escolha != 9);


    return 0;
}