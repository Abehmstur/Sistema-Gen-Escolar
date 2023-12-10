/**
 * @file bancoDao.cpp
 * @brief Implementação da classe BancoDao para gerenciamento de professores e pessoal técnico em uma universidade.
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bancoDao.hpp"
#include "./excecoes/bancoDaoExcecoes.hpp"

using namespace std;

/**
 * @brief Função que lê um número inteiro inserido pelo usuário e trata entradas inválidas.
 * @return Um número inteiro inserido pelo usuário.
 * @throws bancoDaoExcecoes se a entrada não for um número inteiro válido.
 */
int BancoDao::lerNumero() {
    int numero;

    while (true) {
        try {
            if (!(cin >> numero)) {
                cin.clear();
                cin.ignore();
                throw bancoDaoExcecoes("Entrada invalida! Digite um numero inteiro.");
            }
            return numero;
        } catch (const bancoDaoExcecoes& erro) {
            cout << "================================================================================================================" << endl;
            cout << "| ERROR: " << erro.what() << endl;
            cout << "================================================================================================================" << endl;
        }
    }
}

/**
 * @brief Exibe uma mensagem de sucesso para operações.
 */
void BancoDao::operacaoSucesso(){
    cout << "Operacao realizada com sucesso!" << endl;
}

/**
 * @brief Exibe uma mensagem de falha para operações.
 */
void BancoDao::operacaoFalha(){
    cout << "Não foi possivel completar a operacao!" << endl;
}

/**
 * @brief Solicita ao usuário informações para um novo professor e salva essas informações em um arquivo.
 * @param professores Vetor de objetos da classe Professor para armazenar o novo professor.
 */
void BancoDao::cadastrarProfessor(vector<Professor>& professores){
    
    string nome;
    string cpf;
    string dataNascimento;

    
    Endereco novoEndereco;
    string rua;
    int numero;
    string bairro;
    string cidade;
    string cep;

    
    string matricula;
    float salario;
    string departamento;
    int cargaHoraria;
    string dataIngresso;

    
    string disciplina;
    int nivelProfessor;
    int formacaoProfessor;

    
    cout << "<< Informe os Dados Pessoais do professor a seguir >> " << endl;
    cout << "Informe o nome do professor: " << endl;
    getline(cin, nome);

    cout << "Informe o CPF do professor: " << endl;
    getline(cin, cpf);

    cout << "Informe a Data de Nascimento do professor: " << endl;
    getline(cin, dataNascimento);

    
    cout << "<< Informe o Endereco do professor a seguir >> " << endl;
    cout << "Rua: " << endl;
    getline(cin, rua);
    novoEndereco.setRua(rua);

    cout << "Numero da Casa: " << endl;
    numero = lerNumero();
    cin.ignore();
    novoEndereco.setNumero(numero);

    cout << "Bairro: " << endl;
    getline(cin, bairro);
    novoEndereco.setBairro(bairro);

    cout << "Cidade: " << endl;
    getline(cin, cidade);
    novoEndereco.setCidade(cidade);

    cout << "CEP: " << endl;
    cin >> cep;
    cin.ignore();
    novoEndereco.setCEP(cep);

    
    cout << "<< Informe os Dados de Funcionario a seguir >> " << endl;
    cout << "Informe a Matricula do professor a seguir: " << endl;
    int matriTemp = lerNumero();
    matricula = to_string(matriTemp);

    cout << "Informe o Salario do professor a seguir: " << endl;
    cin >> salario;
    cin.ignore();

    cout << "Informe o Departamento do professor a seguir: " << endl;
    getline(cin, departamento);

    cout << "Informe a Carga Horaria do professor a seguir: " << endl;
    cargaHoraria = lerNumero();
    cin.ignore();

    cout << "Informe a Data de Ingresso do professor a seguir: " << endl;
    getline(cin, dataIngresso);

   
    cout << "Informe a Disciplina do professor a seguir: " << endl;
    getline(cin, disciplina);

    do
    {
        cout << "Informe a Nivel do professor a seguir {0 a 6 = I a VIII}: " << endl;
        nivelProfessor = lerNumero();

        if(!(nivelProfessor >= 0 && nivelProfessor <= 6)){
            cout << "INCORRETO: Informe um valor entre 0 e 6. " << endl;
        }

    } while (!(nivelProfessor >= 0 && nivelProfessor <= 6));

    do
    {
        cout << "Informe a Formacao do professor a seguir {0 = ESPECIALIZACAO, 1 = MESTRADO, 2 = DOUTORADO}: " << endl;
        formacaoProfessor = lerNumero();

        if(!(formacaoProfessor >= 0 && formacaoProfessor <= 2)){
            cout << "INCORRETO: Informe um valor entre 0 e 2. " << endl;
        }

    } while (!(formacaoProfessor >= 0 && formacaoProfessor <= 2));

       
        Professor::Nivel nivel = Professor::obterNivelPeloNumero(nivelProfessor);
        Professor::Formacao formacao = Professor::obterFormacaoPeloNumero(formacaoProfessor);

        
        Professor novoProfessor(nome, cpf, dataNascimento, novoEndereco, matricula, salario, departamento, cargaHoraria, dataIngresso, nivel, formacao, disciplina);

       
        fstream arquivo("funcionarios.txt", ios::app);

        string nomeDoNivel = Professor::obterNomeDoNivel(novoProfessor.getNivelProfessor());
        string nomeDaFormacao = Professor::obterNomeDaFormacao(novoProfessor.getFormacaoProfessor());

        try
        {
            if(!arquivo.is_open()){
                throw bancoDaoExcecoes("Nao foi possivel abrir o arquivo.");
            }

            
            if (arquivo.is_open()) {
                arquivo << "Matricula: " << "T1-" << novoProfessor.getMatricula() << "\n";
                arquivo << "Nome: " << novoProfessor.getNome() << "\n";
                arquivo << "CPF: " << novoProfessor.getCPF() << "\n";
                arquivo << "Data de Nascimento: " << novoProfessor.getDataNascimento() << "\n";
                arquivo << "Endereco:\n";
                arquivo << "Rua: " << novoProfessor.getEndereco().getRua() << "\n";
                arquivo << "Numero: " << novoProfessor.getEndereco().getNumero() << "\n";
                arquivo << "Bairro: " << novoProfessor.getEndereco().getBairro() << "\n";
                arquivo << "Cidade: " << novoProfessor.getEndereco().getCidade() << "\n";
                arquivo << "CEP: " << novoProfessor.getEndereco().getCEP() << "\n";
                arquivo << "Salario: " << novoProfessor.getSalario() << "\n";
                arquivo << "Departamento: " << novoProfessor.getDepartamento() << "\n";
                arquivo << "Carga Horaria: " << novoProfessor.getCargaHoraria() << "\n";
                arquivo << "Data de Ingresso: " << novoProfessor.getDataIngresso() << "\n";
                arquivo << "Disciplina: " << novoProfessor.getDisciplina() << "\n";
                arquivo << "Nivel: " << nomeDoNivel << "\n";
                arquivo << "Formacao: " << nomeDaFormacao << "\n\n";
            }

            arquivo.close();

        }catch (const bancoDaoExcecoes& erro) {
            cout << "================================================================================================================" << endl;
            cout << "| ERROR: " << erro.what() << endl;
            cout << "================================================================================================================" << endl;
        }

        cout << "========DADOS DO PROFESSOR CADASTRADO========" << endl;
        cout << "Nome: " << novoProfessor.getNome() << "\nCPF:" << novoProfessor.getCPF() << "\nData de Nascimento: " << novoProfessor.getDataNascimento() << endl;
        cout << "Rua: " << novoEndereco.getRua() << "\nBairro: " << novoEndereco.getBairro() << "\nCEP: " << novoEndereco.getCEP() << "\nCidade: " << novoEndereco.getCidade() << "\nNumero: " << novoEndereco.getNumero() << endl;
        cout << "Matricula: " << novoProfessor.getMatricula() << "\nSalario: " << novoProfessor.getSalario() << "\nDepartamento: " << novoProfessor.getDepartamento() << endl;
        cout << "Carga Horaria: " << novoProfessor.getCargaHoraria() << "\nData de Ingresso: " << novoProfessor.getDataIngresso() << endl;

        cout << "Nivel:" << nomeDoNivel << "\nFormacao: " << nomeDaFormacao << "\nDisciplina: " << novoProfessor.getDisciplina() << endl;
        cout << "========XXXXXXXXXXXXXXXXXXXXXXXXXXXXX========" << endl;

        operacaoSucesso();
};

/**
 * @brief Lista todos os professores armazenados no arquivo.
 */
void BancoDao::listarProfessores(){
    fstream arquivo("funcionarios.txt");
    vector<Professor> listaProfessores;

    
    if (!arquivo.is_open()) {
        cerr << "Nao foi possivel abrir o arquivo." << endl;
    } else {

        string linha;
        Professor novoProfessor;


        while(getline(arquivo, linha)){
            if (linha.find("Matricula: T1-") != string::npos) {
                novoProfessor = Professor(); 
            } else if (linha.find("Nome: ") == 0) {
                novoProfessor.setNome(linha.substr(6));
            } else if (linha.find("Disciplina: ") == 0) {
                novoProfessor.setDisciplina(linha.substr(12));
                listaProfessores.push_back(novoProfessor); 
            }
        }
        arquivo.close();

        cout << "PROFESSORES: \n";

              for (const auto& professor : listaProfessores) {
            cout << "Nome: " << professor.getNome() << " | Disciplina: " << professor.getDisciplina() << endl;
        }
    }
}

/**
 * @brief Exclui um professor com uma determinada matrícula do arquivo.
 * @param matricula Matrícula do professor a ser excluído.
 */
void BancoDao::deletarProfessor(int matricula) {
    ifstream arquivoOriginal("funcionarios.txt");
    ofstream arquivoTemporario("temp.txt");

    if (!arquivoOriginal.is_open() || !arquivoTemporario.is_open()) {
        cerr << "Nao foi possivel abrir o arquivo." << endl;
        return;
    }

    string linha;
    bool professorEncontrado = false;
    bool bloqueio = false; 

    while (getline(arquivoOriginal, linha)) {
        
        if (linha.find("Matricula: T1-" + to_string(matricula)) != string::npos) {
            professorEncontrado = true;
            bloqueio = true; 
        }

       
        if (bloqueio && linha.empty()) {
            bloqueio = false; 
        }

       
        if (!bloqueio) {
            arquivoTemporario << linha << endl;
        }
    }

    arquivoOriginal.close();
    arquivoTemporario.close();

    
    remove("funcionarios.txt");
    rename("temp.txt", "funcionarios.txt");

    if (professorEncontrado) {
        cout << "Professor com matricula " << matricula << " foi deletado com sucesso." << endl;
    } else {
        cout << "Professor com matricula " << matricula << " nao encontrado." << endl;
    }
}

/**
 * @brief Procura por um professor com uma determinada matrícula e exibe suas informações.
 * @param matricula Matrícula do professor a ser pesquisado.
 */

void BancoDao::buscarProfessor(int matricula){
    fstream arquivo("funcionarios.txt");
    vector<Professor> listaProfessores;

    
    if (!arquivo.is_open()) {
        cerr << "Nao foi possivel abrir o arquivo." << endl;
    } else {

        string linha;
        Professor encontrado;
        bool encontradoFlag = false;

        while (getline(arquivo, linha)) {
            if (linha.find("Matricula: T1-" + to_string(matricula)) != string::npos) {
                encontrado = Professor();
                encontradoFlag = true;
            } else if (linha.find("Nome: ") == 0 && encontradoFlag) {
                encontrado.setNome(linha.substr(6));
            } else if (linha.find("Disciplina: ") == 0 && encontradoFlag) {
                encontrado.setDisciplina(linha.substr(12));
                break; 
            }
        }
            arquivo.close();

            if (encontradoFlag) {
                cout << "Nome: " << encontrado.getNome() << " | Disciplina: " << encontrado.getDisciplina() << endl;
            } else {
                cout << "Professor com a matricula " << matricula << " nao encontrado." << endl;
            }
    }
}

/**
 * @brief Cadastra um novo técnico ADM no sistema.
 * @param tecnicosADM Vetor de técnicos ADM onde o novo técnico ADM será armazenado.
 */
void BancoDao::cadastrarTecnicoADM(vector<TecnicoADM>& tecnicosADM){
    
    string nome;
    string cpf;
    string dataNascimento;

    
    Endereco novoEndereco;
    string rua;
    int numero;
    string bairro;
    string cidade;
    string cep;

    
    string matricula;
    float salario;
    string departamento;
    int cargaHoraria;
    string dataIngresso;

    
    float adicionalProdutividade = 0.25;
    string funcaoDesempenhada;
    
    cout << "<< Informe os Dados Pessoais do Tecnico ADM a seguir >> " << endl;
    cout << "Informe o nome do tecnico adm: " << endl;
    getline(cin, nome);

    cout << "Informe o CPF do tecnico adm: " << endl;
    getline(cin, cpf);

    cout << "Informe a Data de Nascimento do tecnico adm: " << endl;
    getline(cin, dataNascimento);
    
    cout << "<< Informe o Endereco do tecnico adm a seguir: >>" << endl;
    cout << "Rua: " << endl;
    getline(cin, rua);
    novoEndereco.setRua(rua);

    cout << "Numero: " << endl;
    numero = lerNumero();
    novoEndereco.setNumero(numero);

    cout << "Bairro: " << endl;
    getline(cin, bairro);
    novoEndereco.setBairro(bairro);

    cout << "Cidade: " << endl;
    getline(cin, cidade);
    novoEndereco.setCidade(cidade);

    cout << "CEP: " << endl;
    cin >> cep;
    cin.ignore();
    novoEndereco.setCEP(cep);
    
    cout << "<< Informe os Dados de Funcionario a seguir >> " << endl;
    cout << "Informe a Matricula do tecnico adm a seguir: " << endl;
    int matriTemp = lerNumero();
    matricula = to_string(matriTemp);

    cout << "Informe o Salario do tecnico adm a seguir: " << endl;
    cin >> salario;
    cin.ignore();

    cout << "Informe o Departamento do tecnico adm a seguir: " << endl;
    getline(cin, departamento);

    cout << "Informe a Carga Horaria do tecnico adm a seguir: " << endl;
    cargaHoraria = lerNumero();

    cout << "Informe a Data de Ingresso do tecnico adm a seguir: " << endl;
    getline(cin, dataIngresso);
    
    cout << "<< Informe os Dados de Funcionario a seguir >> " << endl;
    cout << "Informe funcao desempenhada pelo tecnico adm a seguir: " << endl;
    getline(cin, funcaoDesempenhada);

    TecnicoADM novoTecnicoAdm(nome, cpf, dataNascimento, novoEndereco, matricula, salario, departamento, cargaHoraria, dataIngresso, adicionalProdutividade, funcaoDesempenhada);

    
    fstream arquivo("funcionarios.txt", ios::app);

   
    try
    {
        if(!arquivo.is_open()){
                throw bancoDaoExcecoes("Nao foi possivel abrir o arquivo.");
        }

        
        if (arquivo.is_open()) { 
                arquivo << "Matricula: " << "T2-" << novoTecnicoAdm.getMatricula() << "\n";
                arquivo << "Nome: " << novoTecnicoAdm.getNome() << "\n";
                arquivo << "CPF: " << novoTecnicoAdm.getCPF() << "\n";
                arquivo << "Data de Nascimento: " << novoTecnicoAdm.getDataNascimento() << "\n";
                arquivo << "Endereco:\n";
                arquivo << "Rua: " << novoTecnicoAdm.getEndereco().getRua() << "\n";
                arquivo << "Numero: " << novoTecnicoAdm.getEndereco().getNumero() << "\n";
                arquivo << "Bairro: " << novoTecnicoAdm.getEndereco().getBairro() << "\n";
                arquivo << "Cidade: " << novoTecnicoAdm.getEndereco().getCidade() << "\n";
                arquivo << "CEP: " << novoTecnicoAdm.getEndereco().getCEP() << "\n";
                arquivo << "Salario: " << novoTecnicoAdm.getSalario() << "\n";
                arquivo << "Departamento: " << novoTecnicoAdm.getDepartamento() << "\n";
                arquivo << "Carga Horaria: " << novoTecnicoAdm.getCargaHoraria() << "\n";
                arquivo << "Data de Ingresso: " << novoTecnicoAdm.getDataIngresso() << "\n";
                arquivo << "Adicional de Produtividade: " << novoTecnicoAdm.getAdicionalProdutividade() << "\n";
                arquivo << "Funcao Desempenhada: " << novoTecnicoAdm.getFuncaoDesempenhada() << "\n\n";
        }
        arquivo.close();
    }catch (const bancoDaoExcecoes& erro) {
        cout << "================================================================================================================" << endl;
        cout << "| ERROR: " << erro.what() << endl;
        cout << "================================================================================================================" << endl;
    }

    
        cout << "========DADOS DO TECNICO CADASTRADO========" << endl;
        cout << "Nome: " << novoTecnicoAdm.getNome() << "\nCPF:" << novoTecnicoAdm.getCPF() << "\nData de Nascimento: " << novoTecnicoAdm.getDataNascimento() << endl;
        cout << "Rua: " << novoEndereco.getRua() << "\nBairro: " << novoEndereco.getBairro() << "\nCEP: " << novoEndereco.getCEP() << "\nCidade: " << novoEndereco.getCidade() << "\nNumero: " << novoEndereco.getNumero() << endl;
        cout << "Matricula: " << novoTecnicoAdm.getMatricula() << "\nSalario: " << novoTecnicoAdm.getSalario() << "\nDepartamento: " << novoTecnicoAdm.getDepartamento() << endl;
        cout << "Carga Horaria: " << novoTecnicoAdm.getCargaHoraria() << "\nData de Ingresso: " << novoTecnicoAdm.getDataIngresso() << endl;

        cout << "========XXXXXXXXXXXXXXXXXXXXXXXXXXXXX========" << endl;
        operacaoSucesso();

};

/**
 * @brief Lista todos os técnicos ADM cadastrados no sistema.
 */
void BancoDao::listarTecnicosADM(){
    fstream arquivo("funcionarios.txt");
    vector<TecnicoADM> listaTecnicos;

    
    if (!arquivo.is_open()) {
        cerr << "Nao foi possivel abrir o arquivo." << endl;
    } else {

        string linha;
        TecnicoADM novoTecnico;


        while(getline(arquivo, linha)){
            if (linha.find("Matricula: T2-") != string::npos) {
                novoTecnico = TecnicoADM(); 
            } else if (linha.find("Nome: ") == 0) {
                novoTecnico.setNome(linha.substr(6));
            } else if (linha.find("Funcao Desempenhada: ") == 0) {
                novoTecnico.setFuncaoDesempenhada(linha.substr(21));
                listaTecnicos.push_back(novoTecnico); 
            }
        }

        arquivo.close();

        cout << "TECNICOS: \n";

        
        for (const auto& tecnicos : listaTecnicos) {
            cout << "Nome: " << tecnicos.getNome() << " | Funcao Desempenhada: " << tecnicos.getFuncaoDesempenhada() << endl;
        }
    }
};

/**
 * @brief Deleta um técnico ADM do sistema com base na matrícula.
 * @param matricula Matrícula do técnico ADM a ser deletado.
 */
void BancoDao::deletarTecnicoADM(int matricula){
    ifstream arquivoOriginal("funcionarios.txt");
    ofstream arquivoTemporario("temp.txt");

    if (!arquivoOriginal.is_open() || !arquivoTemporario.is_open()) {
        cerr << "Nao foi possivel abrir o arquivo." << endl;
        return;
    }

    string linha;
    bool tecnicoEncontrado = false;
    bool bloqueio = false; 

    while (getline(arquivoOriginal, linha)) {
        
        if (linha.find("Matricula: T2-" + to_string(matricula)) != string::npos) {
            tecnicoEncontrado = true;
            bloqueio = true; 
        }

        
        if (bloqueio && linha.empty()) {
            bloqueio = false; 
        }

        
        if (!bloqueio) {
            arquivoTemporario << linha << endl;
        }
    }

    arquivoOriginal.close();
    arquivoTemporario.close();

    
    remove("funcionarios.txt");
    rename("temp.txt", "funcionarios.txt");

    if (tecnicoEncontrado) {
        cout << "Tecnico com matricula " << matricula << " foi deletado com sucesso." << endl;
    } else {
        cout << "Tecnico com matricula " << matricula << " nao encontrado." << endl;
    }
};

/**
 * @brief Busca e exibe os dados de um técnico ADM com base na matrícula.
 * @param matricula Matrícula do técnico ADM a ser buscado.
 */
void BancoDao::buscarTecnicoADM(int matricula){
    fstream arquivo("funcionarios.txt");
    vector<TecnicoADM> listaTecnicos;

    
    if (!arquivo.is_open()) {
        cerr << "Nao foi possivel abrir o arquivo." << endl;
    } else {

        string linha;
        TecnicoADM encontrado;
        bool encontradoFlag = false;

        while (getline(arquivo, linha)) {
            if (linha.find("Matricula: T2-" + to_string(matricula)) != string::npos) {
                encontrado = TecnicoADM();
                encontradoFlag = true;
            } else if (linha.find("Nome: ") == 0 && encontradoFlag) {
                encontrado.setNome(linha.substr(6));
            } else if (linha.find("Funcao Desempenhada: ") == 0 && encontradoFlag) {
                encontrado.setFuncaoDesempenhada(linha.substr(21));
                break; 
            }
        }
            arquivo.close();

            if (encontradoFlag) {
                cout << "Nome: " << encontrado.getNome() << " | Funcao Desempenhda: " << encontrado.getFuncaoDesempenhada() << endl;
            } else {
                cout << "Tecnico com a matricula " << matricula << " nao encontrado." << endl;
            }
    }
}; 
