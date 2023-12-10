#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include "endereco.hpp"

/**
 * @file pessoa.hpp
 * @brief Definição da classe Pessoa.
 */

/**
 * @class Pessoa
 * @brief Classe que representa uma pessoa com nome, CPF, data de nascimento e endereço.
 * @details Herda da classe Endereco para incluir informações de endereço.
 */
class Pessoa : public Endereco {
private:
    std::string nome; /**< Nome da pessoa. */
    std::string cpf; /**< CPF da pessoa. */
    std::string dataNascimento; /**< Data de nascimento da pessoa. */
    Endereco endereco; /**< Endereço da pessoa. */

public:
    /**
     * @brief Construtor padrão da classe Pessoa.
     */
    Pessoa();

    /**
     * @brief Construtor parametrizado da classe Pessoa.
     * @param _nome Nome da pessoa.
     * @param _cpf CPF da pessoa.
     * @param _dataNascimento Data de nascimento da pessoa.
     * @param _endereco Objeto da classe Endereco representando o endereço da pessoa.
     */
    Pessoa(const std::string& _nome, const std::string& _cpf, const std::string& _dataNascimento, const Endereco& _endereco);

    /**
     * @brief Getter para obter o nome da pessoa.
     * @return O nome da pessoa.
     */
    std::string getNome() const;

    /**
     * @brief Getter para obter o CPF da pessoa.
     * @return O CPF da pessoa.
     */
    std::string getCPF() const;

    /**
     * @brief Getter para obter a data de nascimento da pessoa.
     * @return A data de nascimento da pessoa.
     */
    std::string getDataNascimento() const;

    /**
     * @brief Getter para obter o endereço da pessoa.
     * @return O endereço da pessoa como um objeto da classe Endereco.
     */
    Endereco getEndereco() const;

    /**
     * @brief Setter para definir o nome da pessoa.
     * @param novoNome Novo nome a ser definido.
     */
    void setNome(const std::string& novoNome);

    /**
     * @brief Setter para definir o CPF da pessoa.
     * @param novoCPF Novo CPF a ser definido.
     */
    void setCPF(const std::string& novoCPF);

    /**
     * @brief Setter para definir a data de nascimento da pessoa.
     * @param novaData Nova data de nascimento a ser definida.
     */
    void setDataNascimento(const std::string& novaData);

    /**
     * @brief Setter para definir o endereço da pessoa.
     * @param novoEndereco Novo endereço a ser definido, representado por um objeto da classe Endereco.
     */
    void setEndereco(const Endereco& novoEndereco);
};
#endif
