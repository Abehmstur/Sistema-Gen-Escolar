#ifndef MAINEXCECOES_HPP
#define MAINEXCECOES_HPP

#include <string>
#include <stdexcept>

/**
 * @file mainExcecoes.hpp
 * @brief Definição da classe mainExcecoes.
 */

/**
 * @class mainExcecoes
 * @brief Representa uma exceção relacionada ao código principal (main).
 */
class mainExcecoes : public std::runtime_error {
public:
    /**
     * @brief Construtor parametrizado.
     * @param msg Mensagem de erro associada à exceção.
     */
    mainExcecoes(const std::string& msg);

    /**
     * @brief Getter para obter a mensagem de erro.
     * @return A mensagem de erro associada à exceção.
     */
    const char* what() const noexcept override;
};
#endif
