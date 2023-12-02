#include "funcionario.hpp"
#include "pessoa.hpp"

//Construtor 
Funcionario::Funcionario(){
}

//Getters
std::string Funcionario::getMatricula() const {
    return matricula;
}

float Funcionario::getSalario() const {
    return salario;
}

std::string Funcionario::getDepartamento() const {
    return departamento;
}

int Funcionario::getCargaHoraria() const {
    return cargaHoraria;
}

std::string Funcionario::getDataIngresso() const {
    return dataIngresso;
}

//Setters
void Funcionario::setMatricula(const std::string& novaMatricula) {
    matricula = novaMatricula;
}

void Funcionario::setSalario(float novoSalario) {
    salario = novoSalario;
}

void Funcionario::setDepartamento(const std::string& novoDepartamento) {
    departamento = novoDepartamento;
}

void Funcionario::setCargaHoraria(int novaCargaHoraria) {
    cargaHoraria = novaCargaHoraria;
}

void Funcionario::setDataIngresso(const std::string& novaDataIngresso) {
    dataIngresso = novaDataIngresso;
}
