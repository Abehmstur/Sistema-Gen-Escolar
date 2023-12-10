#ifndef BANCODAOEXCECOES_HPP
#define BANCODAOEXCECOES_HPP

#include <string>
#include <stdexcept>

/**
 * @file bancoDaoExcecoes.hpp
 * @brief Definição da classe bancoDaoExcecoes.
 */

/**
 * @class bancoDaoExcecoes
 * @brief Representa uma exceção relacionada ao BancoDao.
 */
class bancoDaoExcecoes : public std::runtime_error {
public:
    /**
     * @brief Construtor parametrizado.
     * @param msg Mensagem de erro associada à exceção.
     */
    bancoDaoExcecoes(const std::string& msg);

    /**
     * @brief Getter para obter a mensagem de erro.
     * @return A mensagem de erro associada à exceção.
     */
    const char* what() const noexcept override;
};
#endif
