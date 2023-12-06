#include "professor.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "./excecoes/professorExcecoes.hpp"

using namespace std;

Professor::Professor(){
    
}

//Getters
Professor::Nivel Professor::getNivelProfessor() const {
    return nivelProfessor;
}

Professor::Formacao Professor::getFormacaoProfessor() const {
    return formacaoProfessor;
}

::string Professor::getDisciplina() const {
    return disciplina;
}

//Setters
void Professor::setNivelProfessor(Nivel novoNivel) {
    nivelProfessor = novoNivel;
}

void Professor::setFormacaoProfessor(Formacao novaFormacao) {
    formacaoProfessor = novaFormacao;
}

void Professor::setDisciplina(const string& novaDisciplina) {
    disciplina = novaDisciplina;
}

//classe abstrata paar imprimir salario servidor
void Professor::imprimirSalarioDoFuncionarioByMatricula(int _matricula) {
    try {
        fstream arquivo("funcionarios.txt");
        vector<Professor> listaProfessores;

        if (!arquivo.is_open()) {
            throw runtime_error("Nao foi possivel abrir o arquivo.");
        } else {
            string linha;
            Professor encontrado;
            bool encontradoFlag = false;

            while (getline(arquivo, linha)) {
                if (linha.find("Matricula: T1-" + ::to_string(_matricula)) != ::string::npos) {
                    encontrado = Professor();
                    encontradoFlag = true;
                } else if (linha.find("Nome: ") == 0 && encontradoFlag) {
                    encontrado.setNome(linha.substr(6));
                } else if (linha.find("Salario: ") == 0 && encontradoFlag) {
                    float salario = stof(linha.substr(9));
                    encontrado.setSalario(salario);
                    break;
                }
            }

            arquivo.close();

            if (encontradoFlag) {
                cout << "Nome: " << encontrado.getNome() << " | Salario: " << encontrado.getSalario() << endl;
            } else {
                ::cout << "Professor com a matricula " << _matricula << " nao encontrado." << endl;
            }
        }
    } catch (const professorExcecoes& erro) {
            cout << "================================================================================================================" << endl;
            cout << "| ERROR: " << erro.what() << endl;
            cout << "================================================================================================================" << endl;
    }
}