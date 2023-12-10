#include "professor.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "./excecoes/professorExcecoes.hpp"

using namespace std;

/**
 * @file professor.hpp
 * @brief Implementação da classe Professor.
 */

/**
 * @class Professor
 * @brief Classe que representa um professor.
 * @details Herda da classe Funcionario e implementa funcionalidades específicas para professores.
 */
Professor::Professor() {

}

/**
 * @brief Getter para obter o nível do professor.
 * @return O nível do professor.
 */
Professor::Nivel Professor::getNivelProfessor() const {
    return nivelProfessor;
}

/**
 * @brief Getter para obter a formação do professor.
 * @return A formação do professor.
 */
Professor::Formacao Professor::getFormacaoProfessor() const {
    return formacaoProfessor;
}

/**
 * @brief Getter para obter a disciplina do professor.
 * @return A disciplina do professor.
 */
string Professor::getDisciplina() const {
    return disciplina;
}

/**
 * @brief Setter para definir o nível do professor.
 * @param novoNivel Novo nível a ser definido.
 */
void Professor::setNivelProfessor(Nivel novoNivel) {
    nivelProfessor = novoNivel;
}

/**
 * @brief Setter para definir a formação do professor.
 * @param novaFormacao Nova formação a ser definida.
 */
void Professor::setFormacaoProfessor(Formacao novaFormacao) {
    formacaoProfessor = novaFormacao;
}

/**
 * @brief Setter para definir a disciplina do professor.
 * @param novaDisciplina Nova disciplina a ser definida.
 */
void Professor::setDisciplina(const string& novaDisciplina) {
    disciplina = novaDisciplina;
}

/**
 * @brief Método abstrato para imprimir o salário do professor com base na matrícula.
 * @param _matricula Matrícula do professor.
 * @details Abstração para implementação em classes derivadas.
 */
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
                if (linha.find("Matricula: T1-" + to_string(_matricula)) != string::npos) {
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
                cout << "Professor com a matricula " << _matricula << " nao encontrado." << endl;
            }
        }
    } catch (const professorExcecoes& erro) {
            cout << "================================================================================================================" << endl;
            cout << "| ERROR: " << erro.what() << endl;
            cout << "================================================================================================================" << endl;
    }
}
