#ifndef ENDERECO_HPP
#define ENDERECO_HPP

#include <string>

/**
 * @file endereco.hpp
 * @brief Definição da classe Endereco.
 */

/**
 * @class Endereco
 * @brief Representa um endereço com rua, número, bairro, cidade e CEP.
 */
class Endereco {
private:
    std::string rua;    ///< Nome da rua.
    int numero;         ///< Número do endereço.
    std::string bairro; ///< Nome do bairro.
    std::string cidade; ///< Nome da cidade.
    std::string cep;    ///< CEP do endereço.

    public:

/**
     * @brief Construtor padrão.
     * @details Inicializa o número com 0.
     */       
        Endereco() {
            numero = 0;
        }

        // Getters

    /**
     * @brief Getter para obter o nome da rua.
     * @return O nome da rua.
     */
    std::string getRua() const;

    /**
     * @brief Getter para obter o número do endereço.
     * @return O número do endereço.
     */
    int getNumero() const;

    /**
     * @brief Getter para obter o nome do bairro.
     * @return O nome do bairro.
     */
    std::string getBairro() const;

    /**
     * @brief Getter para obter o nome da cidade.
     * @return O nome da cidade.
     */
    std::string getCidade() const;

    /**
     * @brief Getter para obter o CEP do endereço.
     * @return O CEP do endereço.
     */
    std::string getCEP() const;

    // Setters

    /**
     * @brief Setter para definir o nome da rua.
     * @param newRua Novo nome da rua a ser definido.
     */
    void setRua(const std::string& newRua);

    /**
     * @brief Setter para definir o número do endereço.
     * @param newNumero Novo número do endereço a ser definido.
     */
    void setNumero(int newNumero);

    /**
     * @brief Setter para definir o nome do bairro.
     * @param newBairro Novo nome do bairro a ser definido.
     */
    void setBairro(const std::string& newBairro);

    /**
     * @brief Setter para definir o nome da cidade.
     * @param newCidade Novo nome da cidade a ser definido.
     */
    void setCidade(const std::string& newCidade);

    /**
     * @brief Setter para definir o CEP do endereço.
     * @param newCEP Novo CEP a ser definido.
     */
    void setCEP(const std::string& newCEP);
};
#endif
