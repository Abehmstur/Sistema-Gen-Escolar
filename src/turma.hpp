#ifndef TURMA_HPP
#define TURMA_HPP

#include "professor.hpp"
#include <string>

class Turma : public Professor {
public:
private:
    std::string nomeDaTurma;
    Professor professorDaTurma;
    int capacidadeAlunos;

public:
    //Construtor padrao
    Turma();

    //Construtor parametrizado
    Turma(const std::string& _nomeDaTurma, Professor& _professorDaTurma, int _capacidadeAlunos);

    //Getters
    std::string getNomeDaTurma() const;
    int getCapacidadeAlunos() const;
    Professor getProfessorDaTurma() const;

    //Setters
    void setNomeDaTurma(const std::string& novaTurma);
    void setProfessorDaTurma(Professor novoProfessor);
    void setCapacidadeDaTurma(int capacidadeAlunos);
};

#endif
