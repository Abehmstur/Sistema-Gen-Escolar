#ifndef TECNICOEXCECOES_HPP
#define TECNICOEXCECOES_HPP

#include <string>
#include <stdexcept>

/**
 * @file tecnicoExcecoes.hpp
 * @brief Definição da classe tecnicoExcecoes.
 */

/**
 * @class tecnicoExcecoes
 * @brief Representa uma exceção relacionada à classe TecnicoADM.
 */
class tecnicoExcecoes : public std::runtime_error {
public:
    /**
     * @brief Construtor parametrizado.
     * @param msg Mensagem de erro associada à exceção.
     */
    tecnicoExcecoes(const std::string& msg);

    /**
     * @brief Getter para obter a mensagem de erro.
     * @return A mensagem de erro associada à exceção.
     */
    const char* what() const noexcept override;
};

#endif
