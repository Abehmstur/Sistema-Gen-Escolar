#ifndef PROFESSOREXCECOES_HPP
#define PROFESSOREXCECOES_HPP

#include <string>
#include <stdexcept>

/**
 * @file professorExcecoes.hpp
 * @brief Definição da classe professorExcecoes.
 */

/**
 * @class professorExcecoes
 * @brief Representa uma exceção relacionada à classe Professor.
 */
class professorExcecoes : public std::runtime_error {
public:
    /**
     * @brief Construtor parametrizado.
     * @param msg Mensagem de erro associada à exceção.
     */
    professorExcecoes(const std::string& msg);

    /**
     * @brief Getter para obter a mensagem de erro.
     * @return A mensagem de erro associada à exceção.
     */
    const char* what() const noexcept override;
};

#endif
