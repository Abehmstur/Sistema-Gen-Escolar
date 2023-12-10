#include "funcionario.hpp"
#include "pessoa.hpp"

/**
 * @file funcionario.hpp
 * @brief Implementação da classe Funcionario.
 */

// Construtor
Funcionario::Funcionario() {
}

// Getters

/**
 * @brief Obtém a matrícula do funcionário.
 * @return A matrícula do funcionário.
 */
std::string Funcionario::getMatricula() const {
    return matricula;
}

/**
 * @brief Obtém o salário do funcionário.
 * @return O salário do funcionário.
 */
float Funcionario::getSalario() const {
    return salario;
}

/**
 * @brief Obtém o departamento do funcionário.
 * @return O departamento do funcionário.
 */
std::string Funcionario::getDepartamento() const {
    return departamento;
}

/**
 * @brief Obtém a carga horária do funcionário.
 * @return A carga horária do funcionário.
 */
int Funcionario::getCargaHoraria() const {
    return cargaHoraria;
}

/**
 * @brief Obtém a data de ingresso do funcionário.
 * @return A data de ingresso do funcionário.
 */
std::string Funcionario::getDataIngresso() const {
    return dataIngresso;
}

// Setters

/**
 * @brief Define a matrícula do funcionário.
 * @param novaMatricula Nova matrícula do funcionário.
 */
void Funcionario::setMatricula(const std::string& novaMatricula) {
    matricula = novaMatricula;
}

/**
 * @brief Define o salário do funcionário.
 * @param novoSalario Novo salário do funcionário.
 */
void Funcionario::setSalario(float novoSalario) {
    salario = novoSalario;
}

/**
 * @brief Define o departamento do funcionário.
 * @param novoDepartamento Novo departamento do funcionário.
 */
void Funcionario::setDepartamento(const std::string& novoDepartamento) {
    departamento = novoDepartamento;
}

/**
 * @brief Define a carga horária do funcionário.
 * @param novaCargaHoraria Nova carga horária do funcionário.
 */
void Funcionario::setCargaHoraria(int novaCargaHoraria) {
    cargaHoraria = novaCargaHoraria;
}

/**
 * @brief Define a data de ingresso do funcionário.
 * @param novaDataIngresso Nova data de ingresso do funcionário.
 */
void Funcionario::setDataIngresso(const std::string& novaDataIngresso) {
    dataIngresso = novaDataIngresso;
}
