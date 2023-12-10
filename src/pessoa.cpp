#include <iostream>
#include "pessoa.hpp"

using namespace std;

/**
 * @file pessoa.cpp
 * @brief Implementação da classe Pessoa.
 */

/**
 * @brief Construtor padrão da classe Pessoa.
 */
Pessoa::Pessoa() {
}

/**
 * @brief Construtor parametrizado da classe Pessoa.
 * @param _nome Nome da pessoa.
 * @param _cpf CPF da pessoa.
 * @param _dataNascimento Data de nascimento da pessoa.
 * @param _endereco Objeto da classe Endereco representando o endereço da pessoa.
 */
Pessoa::Pessoa(const std::string& _nome, const std::string& _cpf, const std::string& _dataNascimento, const Endereco& _endereco) 
    : nome(_nome), cpf(_cpf), dataNascimento(_dataNascimento), endereco(_endereco) {
}

/**
 * @brief Getter para obter o nome da pessoa.
 * @return O nome da pessoa.
 */
std::string Pessoa::getNome() const {
    return nome;
}

/**
 * @brief Getter para obter o CPF da pessoa.
 * @return O CPF da pessoa.
 */
std::string Pessoa::getCPF() const {
    return cpf;
}

/**
 * @brief Getter para obter a data de nascimento da pessoa.
 * @return A data de nascimento da pessoa.
 */
std::string Pessoa::getDataNascimento() const {
    return dataNascimento;
}

/**
 * @brief Getter para obter o endereço da pessoa.
 * @return O endereço da pessoa como um objeto da classe Endereco.
 */
Endereco Pessoa::getEndereco() const {
    return endereco;
}

/**
 * @brief Setter para definir o nome da pessoa.
 * @param novoNome Novo nome a ser definido.
 */
void Pessoa::setNome(const std::string& novoNome) {
    nome = novoNome;
}

/**
 * @brief Setter para definir o CPF da pessoa.
 * @param novoCPF Novo CPF a ser definido.
 */
void Pessoa::setCPF(const std::string& novoCPF) {
    cpf = novoCPF;
}

/**
 * @brief Setter para definir a data de nascimento da pessoa.
 * @param novaData Nova data de nascimento a ser definida.
 */
void Pessoa::setDataNascimento(const std::string& novaData) {
    dataNascimento = novaData;
}

/**
 * @brief Setter para definir o endereço da pessoa.
 * @param novoEndereco Novo endereço a ser definido, representado por um objeto da classe Endereco.
 */
void Pessoa::setEndereco(const Endereco& novoEndereco) {
    endereco = novoEndereco;
}
