#include "Turma.hpp"
#include <iostream>

// Construtor padrão
Turma::Turma() : capacidadeAlunos(0) {}

// Construtor parametrizado
Turma::Turma(const std::string& _nomeDaTurma, Professor& _professorDaTurma, int _capacidadeAlunos)
    : nomeDaTurma(_nomeDaTurma), professorDaTurma(_professorDaTurma), capacidadeAlunos(_capacidadeAlunos) {}

// Getters
std::string Turma::getNomeDaTurma() const {
    return nomeDaTurma;
}

int Turma::getCapacidadeAlunos() const {
    return capacidadeAlunos;
}

void Turma::getProfessorDaTurma() const {
    std::cout << "Professor da Turma: " << professorDaTurma.getNome() << std::endl;
}

// Setters
void Turma::setNomeDaTurma(const std::string& novaTurma) {
    nomeDaTurma = novaTurma;
}

void Turma::setProfessorDaTurma(Professor novoProfessor) {
    professorDaTurma = novoProfessor;
}

void Turma::setCapacidadeDaTurma(int capacidadeAlunos) {
    capacidadeAlunos = capacidadeAlunos;
}