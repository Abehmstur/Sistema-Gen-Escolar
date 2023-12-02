#include <iostream>
#include "pessoa.hpp"

using namespace std;

// Construtor
Pessoa::Pessoa() {
}

// Construtor parametrizado
Pessoa::Pessoa(const std::string& _nome, const std::string& _cpf, const std::string& _dataNascimento, const Endereco& _endereco) 
    : nome(_nome), cpf(_cpf), dataNascimento(_dataNascimento), endereco(_endereco) {
}

// Getters
std::string Pessoa::getNome() const {
    return nome;
}

std::string Pessoa::getCPF() const {
    return cpf;
}

std::string Pessoa::getDataNascimento() const {
    return dataNascimento;
}

Endereco Pessoa::getEndereco() const {
    return endereco;
}

// Setters
void Pessoa::setNome(const std::string& novoNome) {
    nome = novoNome;
}

void Pessoa::setCPF(const std::string& novoCPF) {
    cpf = novoCPF;
}

void Pessoa::setDataNascimento(const std::string& novaData) {
    dataNascimento = novaData;
}

void Pessoa::setEndereco(const Endereco& novoEndereco) {
    endereco = novoEndereco;
}