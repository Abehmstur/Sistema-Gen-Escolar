#ifndef MAINEXCECOES_HPP
#define MAINEXCECOES_HPP

#include <string>
#include <stdexcept>

class mainExcecoes : public std::runtime_error{

public:
    mainExcecoes(const std::string& msg) : std::runtime_error(msg) {}
};

#endif
