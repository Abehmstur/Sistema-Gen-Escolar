#ifndef PROFESSOREXCECOES_HPP
#define PROFESSOREXCECOES_HPP

#include <string>
#include <stdexcept>

class professorExcecoes : public std::runtime_error{

public:
    professorExcecoes(const std::string& msg) : std::runtime_error(msg) {}
};

#endif