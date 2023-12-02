#include <iostream>
#include <string>
#include <map>
#include "./endereco.cpp"
#include "./pessoa.cpp"
#include "./bancoDao.cpp"
#include "./professor.cpp"
#include "./funcionario.cpp"
#include "./tecnico_adm.cpp"

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

    do {
        mostrarMenu();
        cin >> escolha;
        cin.ignore(); // Limpa o buffer de entrada

        switch (escolha) {
            case 1:
                cadastrarProfessor(professores);
                break;
            case 2:
                listarProfessores();
                break;
             case 3:
                int matriculaParaDeletar;
                cout << "Digite a matricula do professor para deletar: ";
                cin >> matriculaParaDeletar;
                deletarProfessor(matriculaParaDeletar);
                break;
            case 4:
                int matriculaParaBuscar;
                cout << "Digite a matricula do professor para buscar: ";
                cin >> matriculaParaBuscar;
                buscarProfessor(matriculaParaBuscar);
                break;
            case 5:
                cadastrarTecnicoADM(tecnicosADM);
                break;
            case 6:
                listarTecnicosADM();
                break;
            case 7:
                int matriculaParaDeletarTecnico;
                cout << "Digite a matricula do tecnico ADM para deletar: ";
                cin >> matriculaParaDeletarTecnico;
                deletarTecnicoADM(matriculaParaDeletarTecnico);
                break;
            case 8:
                int matriculaParaBuscarTecnico;
                cout << "Digite a matricula do tccnico ADM para buscar: ";
                cin >> matriculaParaBuscarTecnico;
                buscarTecnicoADM(matriculaParaBuscarTecnico);
                break;
            case 9:
                cout << "Saindo do programa...\n\n" << endl;
                break; 
            default:
                cout << "Opcao invalida! Por favor, escolha uma opcao valida." << endl;
                break;
        }
    } while (escolha != 9);


    return 0;
}