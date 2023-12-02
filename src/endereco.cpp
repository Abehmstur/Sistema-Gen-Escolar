#include <iostream>
#include "endereco.hpp"

using namespace std;

    // Getters
    string Endereco::getRua() const {
        return rua;
    }

    int Endereco::getNumero() const {
        return numero;
    }

    string Endereco::getBairro() const {
        return bairro;
    }

    string Endereco::getCidade() const {
        return cidade;
    }

    string Endereco::getCEP() const {
        return cep;
    }

    // Setters
    void Endereco::setRua(const std::string& novaRua) {
        rua = novaRua;
    }

    void Endereco::setNumero(int novaNumero) {
        numero = novaNumero;
    }

    void Endereco::setBairro(const std::string& novaBairro) {
        bairro = novaBairro;
    }

    void Endereco::setCidade(const std::string& novaCidade) {
        cidade = novaCidade;
    }

    void Endereco::setCEP(const std::string& novaCEP) {
        cep = novaCEP;
    }
