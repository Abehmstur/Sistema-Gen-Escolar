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

//Lê o número informado pelo usuário e retorna uma exceção caso não seja um valor válido.
int BancoDao::lerNumero() {
    int numero;

    while (true) {
        try {
            if (!(cin >> numero)) {
                cin.clear();
                cin.ignore();
                throw bancoDaoExcecoes("Entrada invalida! Digite um numero inteiro.");
            }
            return numero; // Retorna o número se a entrada for válida
        } catch (const bancoDaoExcecoes& erro) {
            cout << "================================================================================================================" << endl;
            cout << "| ERROR: " << erro.what() << endl;
            cout << "================================================================================================================" << endl;
        }
    }
}

//excecoes temporarias
void BancoDao::operacaoSucesso(){
    cout << "Operacao realizada com sucesso!" << endl;
}

void BancoDao::operacaoFalha(){
    cout << "Não foi possivel completar a operacao!" << endl;
}
//funcoes professores
void BancoDao::cadastrarProfessor(vector<Professor>& professores){
    //dados Pessoa
    string nome;
    string cpf;
    string dataNascimento;
    
    //Novo endereço + atributos endereço
    Endereco novoEndereco;
    string rua;
    int numero;
    string bairro;
    string cidade;
    string cep;
    
    //dados Funcionario
    string matricula;
    float salario;
    string departamento;
    int cargaHoraria;
    string dataIngresso;

    //dados Professor
    string disciplina;
    int nivelProfessor;
    int formacaoProfessor;

    //solicitando entradas do usuário
    //entrada dados pessoa
    cout << "<< Informe os Dados Pessoais do professor a seguir >> " << endl;
    cout << "Informe o nome do professor: " << endl;
    getline(cin, nome);
    
    cout << "Informe o CPF do professor: " << endl;
    getline(cin, cpf);

    cout << "Informe a Data de Nascimento do professor: " << endl;
    getline(cin, dataNascimento);
    
    //entrada dados endereco
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

    // entrada dados funcionario
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
    
    //entrada dados professor
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
    
        //aqui converte os numeros recebidos pelo usuario nos seus devidos ENUM de nivel e formacao
        Professor::Nivel nivel = Professor::obterNivelPeloNumero(nivelProfessor);
        Professor::Formacao formacao = Professor::obterFormacaoPeloNumero(formacaoProfessor);

        //Constroi um novo professor com os dados fornecidos pelo usuario
        Professor novoProfessor(nome, cpf, dataNascimento, novoEndereco, matricula, salario, departamento, cargaHoraria, dataIngresso, nivel, formacao, disciplina);

        //comeca a salvar em arquivo aqui abrindo o arquivo.
        fstream arquivo("funcionarios.txt", ios::app);

        string nomeDoNivel = Professor::obterNomeDoNivel(novoProfessor.getNivelProfessor());
        string nomeDaFormacao = Professor::obterNomeDaFormacao(novoProfessor.getFormacaoProfessor());

        try
        {
            if(!arquivo.is_open()){
                throw bancoDaoExcecoes("Nao foi possivel abrir o arquivo.");
            }

            //Salvar informações do professor no arquivo txt.
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

        //Exibe um resumo dos dados do professor cadastrado
        cout << "========DADOS DO PROFESSOR CADASTRADO========" << endl;
        cout << "Nome: " << novoProfessor.getNome() << "\nCPF:" << novoProfessor.getCPF() << "\nData de Nascimento: " << novoProfessor.getDataNascimento() << endl;
        cout << "Rua: " << novoEndereco.getRua() << "\nBairro: " << novoEndereco.getBairro() << "\nCEP: " << novoEndereco.getCEP() << "\nCidade: " << novoEndereco.getCidade() << "\nNumero: " << novoEndereco.getNumero() << endl;
        cout << "Matricula: " << novoProfessor.getMatricula() << "\nSalario: " << novoProfessor.getSalario() << "\nDepartamento: " << novoProfessor.getDepartamento() << endl;
        cout << "Carga Horaria: " << novoProfessor.getCargaHoraria() << "\nData de Ingresso: " << novoProfessor.getDataIngresso() << endl;
        
        cout << "Nivel:" << nomeDoNivel << "\nFormacao: " << nomeDaFormacao << "\nDisciplina: " << novoProfessor.getDisciplina() << endl;
        cout << "========XXXXXXXXXXXXXXXXXXXXXXXXXXXXX========" << endl;
        
        operacaoSucesso();
};

//listar professor
void BancoDao::listarProfessores(){
    fstream arquivo("funcionarios.txt");
    vector<Professor> listaProfessores;

    //validacao caso o arquivo não abra.
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

        //lista professor no for
        for (const auto& professor : listaProfessores) {
            cout << "Nome: " << professor.getNome() << " | Disciplina: " << professor.getDisciplina() << endl;
        }
    }
}

//deletar professor
void BancoDao::deletarProfessor(int matricula) {
    ifstream arquivoOriginal("funcionarios.txt");
    ofstream arquivoTemporario("temp.txt");

    if (!arquivoOriginal.is_open() || !arquivoTemporario.is_open()) {
        cerr << "Nao foi possivel abrir o arquivo." << endl;
        return;
    }

    string linha;
    bool professorEncontrado = false;
    bool bloqueio = false; // Variável para controlar se deve bloquear a escrita

    while (getline(arquivoOriginal, linha)) {
        // Verifica se encontrou a matrícula do professor
        if (linha.find("Matricula: T1-" + to_string(matricula)) != string::npos) {
            professorEncontrado = true;
            bloqueio = true; // Bloqueia a escrita a partir deste ponto
        }

        // Se encontrou, pula todas as linhas referentes ao professor
        if (bloqueio && linha.empty()) {
            bloqueio = false; // Desbloqueia a escrita
        }

        // Escreve no arquivo temporário se não for uma linha do professor a ser deletado
        if (!bloqueio) {
            arquivoTemporario << linha << endl;
        }
    }

    arquivoOriginal.close();
    arquivoTemporario.close();

    // Remove o arquivo original e renomeia o temporário para o nome do original
    remove("funcionarios.txt");
    rename("temp.txt", "funcionarios.txt");

    if (professorEncontrado) {
        cout << "Professor com matricula " << matricula << " foi deletado com sucesso." << endl;
    } else {
        cout << "Professor com matricula " << matricula << " nao encontrado." << endl;
    }
}

void BancoDao::buscarProfessor(int matricula){
    fstream arquivo("funcionarios.txt");
    vector<Professor> listaProfessores;

    //validacao caso o arquivo não abra.
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
                break; // Não precisamos mais continuar após encontrar todos os dados
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
//funcoes para tecnicos adm
void BancoDao::cadastrarTecnicoADM(vector<TecnicoADM>& tecnicosADM){
    //dados Pessoa
    string nome;
    string cpf;
    string dataNascimento;
    
    //Novo endereço + atributos endereço
    Endereco novoEndereco;
    string rua;
    int numero;
    string bairro;
    string cidade;
    string cep;
    
    //dados Funcionario
    string matricula;
    float salario;
    string departamento;
    int cargaHoraria;
    string dataIngresso;

    //dados tecnico adm
    float adicionalProdutividade = 0.25;
    string funcaoDesempenhada;

    //solicitando entradas do usuário
    //entrada dados pessoa
    cout << "<< Informe os Dados Pessoais do Tecnico ADM a seguir >> " << endl;
    cout << "Informe o nome do tecnico adm: " << endl;
    getline(cin, nome);
    
    cout << "Informe o CPF do tecnico adm: " << endl;
    getline(cin, cpf);

    cout << "Informe a Data de Nascimento do tecnico adm: " << endl;
    getline(cin, dataNascimento);
    
    //entrada dados endereco
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

    // entrada dados funcionario
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

    // entrada de dados do tecnico adm a seguir
    cout << "<< Informe os Dados de Funcionario a seguir >> " << endl;
    cout << "Informe funcao desempenhada pelo tecnico adm a seguir: " << endl;
    getline(cin, funcaoDesempenhada);

    TecnicoADM novoTecnicoAdm(nome, cpf, dataNascimento, novoEndereco, matricula, salario, departamento, cargaHoraria, dataIngresso, adicionalProdutividade, funcaoDesempenhada);

    //comeca a salvar em arquivo aqui abrindo o arquivo.
    fstream arquivo("funcionarios.txt", ios::app);

    //tratamento de abertura de arquivo
    try
    {
        if(!arquivo.is_open()){
                throw bancoDaoExcecoes("Nao foi possivel abrir o arquivo.");
        }

        //Salvar informações do tecnico no arquivo txt.
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
    
    //Exibe um resumo dos dados do tecnico cadastrado
        cout << "========DADOS DO TECNICO CADASTRADO========" << endl;
        cout << "Nome: " << novoTecnicoAdm.getNome() << "\nCPF:" << novoTecnicoAdm.getCPF() << "\nData de Nascimento: " << novoTecnicoAdm.getDataNascimento() << endl;
        cout << "Rua: " << novoEndereco.getRua() << "\nBairro: " << novoEndereco.getBairro() << "\nCEP: " << novoEndereco.getCEP() << "\nCidade: " << novoEndereco.getCidade() << "\nNumero: " << novoEndereco.getNumero() << endl;
        cout << "Matricula: " << novoTecnicoAdm.getMatricula() << "\nSalario: " << novoTecnicoAdm.getSalario() << "\nDepartamento: " << novoTecnicoAdm.getDepartamento() << endl;
        cout << "Carga Horaria: " << novoTecnicoAdm.getCargaHoraria() << "\nData de Ingresso: " << novoTecnicoAdm.getDataIngresso() << endl;
        
        cout << "========XXXXXXXXXXXXXXXXXXXXXXXXXXXXX========" << endl;
        operacaoSucesso();

};

//listar Tecnicos ADM
void BancoDao::listarTecnicosADM(){
    fstream arquivo("funcionarios.txt");
    vector<TecnicoADM> listaTecnicos;

    //validacao caso o arquivo não abra.
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

        //lista tecnico adm no for
        for (const auto& tecnicos : listaTecnicos) {
            cout << "Nome: " << tecnicos.getNome() << " | Funcao Desempenhada: " << tecnicos.getFuncaoDesempenhada() << endl;
        }
    }
};

//replica do deletar professor
void BancoDao::deletarTecnicoADM(int matricula){
    ifstream arquivoOriginal("funcionarios.txt");
    ofstream arquivoTemporario("temp.txt");

    if (!arquivoOriginal.is_open() || !arquivoTemporario.is_open()) {
        cerr << "Nao foi possivel abrir o arquivo." << endl;
        return;
    }

    string linha;
    bool tecnicoEncontrado = false;
    bool bloqueio = false; // Variável para controlar se deve bloquear a escrita

    while (getline(arquivoOriginal, linha)) {
        // Verifica se encontrou a matrícula do professor
        if (linha.find("Matricula: T2-" + to_string(matricula)) != string::npos) {
            tecnicoEncontrado = true;
            bloqueio = true; // Bloqueia a escrita a partir deste ponto
        }

        // Se encontrou, pula todas as linhas referentes ao tecnico
        if (bloqueio && linha.empty()) {
            bloqueio = false; // Desbloqueia a escrita
        }

        // Escreve no arquivo temporário se não for uma linha do tecnico a ser deletado
        if (!bloqueio) {
            arquivoTemporario << linha << endl;
        }
    }

    arquivoOriginal.close();
    arquivoTemporario.close();

    // Remove o arquivo original e renomeia o temporário para o nome do original
    remove("funcionarios.txt");
    rename("temp.txt", "funcionarios.txt");

    if (tecnicoEncontrado) {
        cout << "Tecnico com matricula " << matricula << " foi deletado com sucesso." << endl;
    } else {
        cout << "Tecnico com matricula " << matricula << " nao encontrado." << endl;
    }
};

//busca tec
void BancoDao::buscarTecnicoADM(int matricula){
    fstream arquivo("funcionarios.txt");
    vector<TecnicoADM> listaTecnicos;

    //validacao caso o arquivo não abra.
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
                break; // Não precisamos mais continuar após encontrar todos os dados
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
