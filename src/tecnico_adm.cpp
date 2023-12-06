#include "tecnico_adm.hpp"
#include "funcionario.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "./excecoes/tecnicoExcecoes.hpp"
using namespace std;

// Construtor parametrizado
TecnicoADM::TecnicoADM(float _adicionalProdutividade, const std::string& _funcaoDesempenhada)
    : adicionalProdutividade(_adicionalProdutividade), funcaoDesempenhada(_funcaoDesempenhada) {
}

// Getters
float TecnicoADM::getAdicionalProdutividade() const {
    return adicionalProdutividade;
}

std::string TecnicoADM::getFuncaoDesempenhada() const {
    return funcaoDesempenhada;
}

// Setters
void TecnicoADM::setAdicionalProdutividade(float novoAdicionalProdutividade) {
    adicionalProdutividade = novoAdicionalProdutividade;
}

void TecnicoADM::setFuncaoDesempenhada(const std::string& novaFuncaoDesempenhada) {
    funcaoDesempenhada = novaFuncaoDesempenhada;
}

void TecnicoADM::imprimirSalarioDoFuncionarioByMatricula(int _matricula) {
    try {
        fstream arquivo("funcionarios.txt");
        vector<TecnicoADM> listaProfessores;

        if (!arquivo.is_open()) {
            throw runtime_error("Nao foi possivel abrir o arquivo.");
        } else {
            string linha;
            TecnicoADM encontrado;
            bool encontradoFlag = false;

            while (getline(arquivo, linha)) {
                if (linha.find("Matricula: T2-" + ::to_string(_matricula)) != ::string::npos) {
                    encontrado = TecnicoADM();
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
    } catch (const tecnicoExcecoes& erro) {
            cout << "================================================================================================================" << endl;
            cout << "| ERROR: " << erro.what() << endl;
            cout << "================================================================================================================" << endl;
    }
}