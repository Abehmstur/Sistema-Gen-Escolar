#ifndef TECNICOEXCECOES_HPP
#define TECNICOEXCECOES_HPP

#include <string>
#include <stdexcept>

class tecnicoExcecoes : public std::runtime_error{

public:
    tecnicoExcecoes(const std::string& msg) : std::runtime_error(msg) {}
};

#endif