#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>
#include "pessoa.hpp"

class Funcionario : public Pessoa {
private:
    std::string matricula;
    float salario;
    std::string departamento;
    int cargaHoraria;
    std::string dataIngresso;

public:
    //Construtor
    Funcionario();
    //Construtor parametrizado pessoa
    Funcionario(const std::string& _nome, const std::string& _cpf, const std::string& _dataNascimento, const Endereco& _endereco, const std::string& _matricula, float _salario, 
    const std::string& _departamento, int _cargaHoraria, const std::string& _dataIngresso) : Pessoa(_nome, _cpf, _dataNascimento, _endereco), matricula(_matricula), salario(_salario), departamento(_departamento), cargaHoraria(_cargaHoraria), dataIngresso(_dataIngresso){
    };

    //Getters
    std::string getMatricula() const;
    float getSalario() const;
    std::string getDepartamento() const;
    int getCargaHoraria() const;
    std::string getDataIngresso() const;

    //Setters
    void setMatricula(const std::string& novaMatricula);
    void setSalario(float novoSalario);
    void setDepartamento(const std::string& novoDepartamento);
    void setCargaHoraria(int novaCargaHoraria);
    void setDataIngresso(const std::string& novaDataIngresso);
};

#endif
