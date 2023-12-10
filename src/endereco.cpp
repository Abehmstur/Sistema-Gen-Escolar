#include <iostream>
#include "endereco.hpp"

/**
 * @file endereco.cpp
 * @brief Implementação dos métodos da classe Endereco.
 */

/**
 * @brief Getter para obter o nome da rua.
 * @return O nome da rua.
 */
string Endereco::getRua() const {
    return rua;
}

/**
 * @brief Getter para obter o número do endereço.
 * @return O número do endereço.
 */
int Endereco::getNumero() const {
    return numero;
}

/**
 * @brief Getter para obter o nome do bairro.
 * @return O nome do bairro.
 */
string Endereco::getBairro() const {
    return bairro;
}

/**
 * @brief Getter para obter o nome da cidade.
 * @return O nome da cidade.
 */
string Endereco::getCidade() const {
    return cidade;
}

/**
 * @brief Getter para obter o CEP do endereço.
 * @return O CEP do endereço.
 */
string Endereco::getCEP() const {
    return cep;
}

/**
 * @brief Setter para definir o nome da rua.
 * @param novaRua Novo nome da rua a ser definido.
 */
void Endereco::setRua(const std::string& novaRua) {
    rua = novaRua;
}

/**
 * @brief Setter para definir o número do endereço.
 * @param novaNumero Novo número do endereço a ser definido.
 */
void Endereco::setNumero(int novaNumero) {
    numero = novaNumero;
}

/**
 * @brief Setter para definir o nome do bairro.
 * @param novoBairro Novo nome do bairro a ser definido.
 */
void Endereco::setBairro(const std::string& novoBairro) {
    bairro = novoBairro;
}

/**
 * @brief Setter para definir o nome da cidade.
 * @param novaCidade Novo nome da cidade a ser definido.
 */
void Endereco::setCidade(const std::string& novaCidade) {
    cidade = novaCidade;
}

/**
 * @brief Setter para definir o CEP do endereço.
 * @param novoCEP Novo CEP a ser definido.
 */
void Endereco::setCEP(const std::string& novaCEP) {
    cep = novaCEP;
}
