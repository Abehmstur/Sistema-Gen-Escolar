#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <string>
#include "funcionario.hpp"

/**
 * @file professor.hpp
 * @brief Implementação da classe Professor.
 */

/**
 * @class Professor
 * @brief Classe que representa um professor.
 * @details Herda da classe Funcionario e implementa funcionalidades específicas para professores.
 */
class Professor : public Funcionario {
public:
    //Enumerações

    /**
     * @enum Nivel
     * @brief Enumeração para representar o nível do professor.
     */
    enum Nivel { I, II, III, IV, V, VI, VII, VIII };

    /**
     * @enum Formacao
     * @brief Enumeração para representar a formação do professor.
     */
    enum Formacao { ESPECIALIZACAO, MESTRADO, DOUTORADO };

private:
    Nivel nivelProfessor; ///< Nível do professor.
    Formacao formacaoProfessor; ///< Formação do professor.
    std::string disciplina; ///< Disciplina do professor.

public:
    //Construtor padrao

    /**
     * @brief Construtor padrão da classe Professor.
     */
    Professor();

    /**
     * @brief Construtor parametrizado da classe Professor.
     * @param _nivel Nível do professor.
     * @param _formacao Formação do professor.
     * @param _disciplina Disciplina do professor.
     */
    Professor(Nivel _nivel, Formacao _formacao, const std::string& _disciplina);

    /**
     * @brief Construtor parametrizado da classe Professor.
     * @param _nome Nome do professor.
     * @param _cpf CPF do professor.
     * @param _dataNascimento Data de nascimento do professor.
     * @param _endereco Endereço do professor.
     * @param _matricula Matrícula do professor.
     * @param _salario Salário do professor.
     * @param _departamento Departamento do professor.
     * @param _cargaHoraria Carga horária do professor.
     * @param _dataIngresso Data de ingresso do professor.
     * @param _nivel Nível do professor.
     * @param _formacao Formação do professor.
     * @param _disciplina Disciplina do professor.
     */
    Professor(const std::string& _nome, const std::string& _cpf, const std::string& _dataNascimento, const Endereco& _endereco, const std::string& _matricula, float _salario, const std::string& _departamento, int _cargaHoraria, const std::string& _dataIngresso, const Nivel& _nivel, const Formacao& _formacao, const std::string& _disciplina);

    /**
     * @brief Método abstrato para imprimir o salário do professor com base na matrícula.
     * @param _matricula Matrícula do professor.
     * @details Abstração para implementação em classes derivadas.
     */
    void imprimirSalarioDoFuncionarioByMatricula(int _matricula);

    /**
     * @brief Getter para obter o nível do professor.
     * @return O nível do professor.
     */
    Nivel getNivelProfessor() const;

    /**
     * @brief Getter para obter a formação do professor.
     * @return A formação do professor.
     */
    Formacao getFormacaoProfessor() const;

    /**
     * @brief Getter para obter a disciplina do professor.
     * @return A disciplina do professor.
     */
    std::string getDisciplina() const;

    /**
     * @brief Setter para definir o nível do professor.
     * @param novoNivel Novo nível a ser definido.
     */
    void setNivelProfessor(Nivel novoNivel);

    /**
     * @brief Setter para definir a formação do professor.
     * @param novaFormacao Nova formação a ser definida.
     */
    void setFormacaoProfessor(Formacao novaFormacao);

    /**
     * @brief Setter para definir a disciplina do professor.
     * @param novaDisciplina Nova disciplina a ser definida.
     */
    void setDisciplina(const std::string& novaDisciplina);

    /**
     * @brief Método estático para converter inteiro para enum Nivel.
     * @param numero Número a ser convertido.
     * @return Enum Nivel correspondente ao número.
     */
    static Nivel obterNivelPeloNumero(int numero);

    /**
     * @brief Método estático para converter inteiro para enum Formacao.
     * @param numero Número a ser convertido.
     * @return Enum Formacao correspondente ao número.
     */
    static Formacao obterFormacaoPeloNumero(int numero);

    /**
     * @brief Método para obter o nome do enum Nivel.
     * @param nivel Nível a ser convertido em nome.
     * @return Nome correspondente ao enum Nivel.
     */
    static std::string obterNomeDoNivel(Nivel nivel);

    /**
     * @brief Método para obter o nome do enum Formacao.
     * @param formacao Formacao a ser convertido em nome.
     * @return Nome correspondente ao enum Formacao.
     */
    static std::string obterNomeDaFormacao(Formacao formacao);
};
#endif
