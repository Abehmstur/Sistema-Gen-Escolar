#ifndef BANCODAOEXCECOES_HPP
#define BANCODAOEXCECOES_HPP

#include <string>
#include <stdexcept>

class bancoDaoExcecoes : public std::runtime_error{

public:
    bancoDaoExcecoes(const std::string& msg) : std::runtime_error(msg) {}
};

#endif
