#include "tecnico_adm.hpp"
#include "funcionario.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "./excecoes/tecnicoExcecoes.hpp"
using namespace std;

/**
 * @file tecnico_adm.cpp
 * @brief Implementação dos métodos da classe TecnicoADM.
 */

/**
 * @brief Construtor parametrizado da classe TecnicoADM.
 * @param _adicionalProdutividade Adicional de produtividade do técnico administrativo.
 * @param _funcaoDesempenhada Função desempenhada pelo técnico administrativo.
 */
TecnicoADM::TecnicoADM(float _adicionalProdutividade, const std::string& _funcaoDesempenhada)
    : adicionalProdutividade(_adicionalProdutividade), funcaoDesempenhada(_funcaoDesempenhada) {
}

/**
 * @brief Getter para obter o adicional de produtividade do técnico administrativo.
 * @return O adicional de produtividade.
 */
float TecnicoADM::getAdicionalProdutividade() const {
    return adicionalProdutividade;
}

/**
 * @brief Getter para obter a função desempenhada pelo técnico administrativo.
 * @return A função desempenhada.
 */
std::string TecnicoADM::getFuncaoDesempenhada() const {
    return funcaoDesempenhada;
}

/**
 * @brief Setter para definir o adicional de produtividade do técnico administrativo.
 * @param novoAdicionalProdutividade Novo adicional de produtividade a ser definido.
 */
void TecnicoADM::setAdicionalProdutividade(float novoAdicionalProdutividade) {
    adicionalProdutividade = novoAdicionalProdutividade;
}

/**
 * @brief Setter para definir a função desempenhada pelo técnico administrativo.
 * @param novaFuncaoDesempenhada Nova função desempenhada a ser definida.
 */
void TecnicoADM::setFuncaoDesempenhada(const std::string& novaFuncaoDesempenhada) {
    funcaoDesempenhada = novaFuncaoDesempenhada;
}

/**
 * @brief Método para imprimir o salário do funcionário com base na matrícula.
 * @param _matricula Matrícula do funcionário.
 * @details O método lê o arquivo "funcionarios.txt" em busca do funcionário com a matrícula informada e imprime seu salário.
 * @throws tecnicoExcecoes Lança exceções específicas para erros relacionados aos técnicos administrativos.
 */
void TecnicoADM::imprimirSalarioDoFuncionarioByMatricula(int _matricula) {
    try {
        std::fstream arquivo("funcionarios.txt");
        std::vector<TecnicoADM> listaTecnicosADM;

        if (!arquivo.is_open()) {
            throw std::runtime_error("Não foi possível abrir o arquivo.");
        } else {
            std::string linha;
            TecnicoADM encontrado;
            bool encontradoFlag = false;

            while (getline(arquivo, linha)) {
                if (linha.find("Matricula: T2-" + std::to_string(_matricula)) != std::string::npos) {
                    encontrado = TecnicoADM();
                    encontradoFlag = true;
                } else if (linha.find("Nome: ") == 0 && encontradoFlag) {
                    encontrado.setNome(linha.substr(6));
                } else if (linha.find("Salario: ") == 0 && encontradoFlag) {
                    float salario = std::stof(linha.substr(9));
                    encontrado.setSalario(salario);
                    break;
                }
            }

            arquivo.close();

            if (encontradoFlag) {
                std::cout << "Nome: " << encontrado.getNome() << " | Salario: " << encontrado.getSalario() << std::endl;
            } else {
                std::cout << "Professor com a matrícula " << _matricula << " não encontrado." << std::endl;
            }
        }
    } catch (const tecnicoExcecoes& erro) {
        std::cout << "================================================================================================================" << std::endl;
        std::cout << "| ERROR: " << erro.what() << std::endl;
        std::cout << "================================================================================================================" << std::endl;
    }
}
