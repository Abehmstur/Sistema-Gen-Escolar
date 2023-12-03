#ifndef TECNICO_ADM_HPP
#define TECNICO_ADM_HPP

#include "funcionario.hpp"
#include <iostream>
#include <string>

class TecnicoADM : public Funcionario {
private:
    float adicionalProdutividade = 0.25;
    std::string funcaoDesempenhada;

public:
    TecnicoADM(){};
    // Construtor parametrizado
    TecnicoADM(float _adicionalProdutividade, const std::string& _funcaoDesempenhada);

    // Construtor parametrizado com as classes mães etc
    TecnicoADM(const std::string& _nome, const std::string& _cpf, const std::string& _dataNascimento, const Endereco& _endereco, const std::string& _matricula, float _salario, const std::string& _departamento, int _cargaHoraria, const std::string& _dataIngresso, float _adicionalProdutividade, const std::string& _funcaoDesempenhada) : Funcionario(_nome, _cpf, _dataNascimento, _endereco, _matricula, _salario, _departamento, _cargaHoraria, _dataIngresso), adicionalProdutividade(_adicionalProdutividade), funcaoDesempenhada(_funcaoDesempenhada) {};

    // Getters
    float getAdicionalProdutividade() const;
    std::string getFuncaoDesempenhada() const;

    // Setters
    void setAdicionalProdutividade(float novoAdicionalProdutividade);
    void setFuncaoDesempenhada(const std::string& novaFuncaoDesempenhada);
};

#endif
