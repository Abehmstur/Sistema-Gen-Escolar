#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>
#include "pessoa.hpp"

/**
 * @file funcionario.hpp
 * @brief Definição da classe Funcionario.
 */

/**
 * @class Funcionario
 * @brief Representa um funcionário que é uma pessoa e possui atributos específicos.
 * @details A classe possui membros como matrícula, salário, departamento, carga horária
 * e data de ingresso. Além disso, herda atributos e métodos da classe Pessoa.
 */
class Funcionario : public Pessoa {
private:
    std::string matricula;      ///< Matrícula do funcionário.
    float salario;              ///< Salário do funcionário.
    std::string departamento;   ///< Departamento do funcionário.
    int cargaHoraria;           ///< Carga horária do funcionário.
    std::string dataIngresso;   ///< Data de ingresso do funcionário.

public:
    // Construtores

    /**
     * @brief Construtor padrão da classe Funcionario.
     */
    Funcionario();

    /**
     * @brief Construtor parametrizado da classe Funcionario.
     * @param _nome Nome do funcionário.
     * @param _cpf CPF do funcionário.
     * @param _dataNascimento Data de nascimento do funcionário.
     * @param _endereco Endereço do funcionário.
     * @param _matricula Matrícula do funcionário.
     * @param _salario Salário do funcionário.
     * @param _departamento Departamento do funcionário.
     * @param _cargaHoraria Carga horária do funcionário.
     * @param _dataIngresso Data de ingresso do funcionário.
     */
    Funcionario(const std::string& _nome, const std::string& _cpf, const std::string& _dataNascimento,
                const Endereco& _endereco, const std::string& _matricula, float _salario,
                const std::string& _departamento, int _cargaHoraria, const std::string& _dataIngresso);

    // Funções virtuais puras para abstração

    /**
     * @brief Função pura virtual para imprimir o salário do funcionário por matrícula.
     * @param _matricula Matrícula do funcionário.
     */
    virtual void imprimirSalarioDoFuncionarioByMatricula(int _matricula) = 0;

    // Getters

    /**
     * @brief Obtém a matrícula do funcionário.
     * @return A matrícula do funcionário.
     */
    std::string getMatricula() const;

    /**
     * @brief Obtém o salário do funcionário.
     * @return O salário do funcionário.
     */
    float getSalario() const;

    /**
     * @brief Obtém o departamento do funcionário.
     * @return O departamento do funcionário.
     */
    std::string getDepartamento() const;

    /**
     * @brief Obtém a carga horária do funcionário.
     * @return A carga horária do funcionário.
     */
    int getCargaHoraria() const;

    /**
     * @brief Obtém a data de ingresso do funcionário.
     * @return A data de ingresso do funcionário.
     */
    std::string getDataIngresso() const;

    // Setters

    /**
     * @brief Define a matrícula do funcionário.
     * @param novaMatricula Nova matrícula do funcionário.
     */
    void setMatricula(const std::string& novaMatricula);

    /**
     * @brief Define o salário do funcionário.
     * @param novoSalario Novo salário do funcionário.
     */
    void setSalario(float novoSalario);

    /**
     * @brief Define o departamento do funcionário.
     * @param novoDepartamento Novo departamento do funcionário.
     */
    void setDepartamento(const std::string& novoDepartamento);

    /**
     * @brief Define a carga horária do funcionário.
     * @param novaCargaHoraria Nova carga horária do funcionário.
     */
    void setCargaHoraria(int novaCargaHoraria);

    /**
     * @brief Define a data de ingresso do funcionário.
     * @param novaDataIngresso Nova data de ingresso do funcionário.
     */
    void setDataIngresso(const std::string& novaDataIngresso);
};
#endif
