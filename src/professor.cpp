#include "professor.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"

Professor::Professor(){
    
}

//Getters
Professor::Nivel Professor::getNivelProfessor() const {
    return nivelProfessor;
}

Professor::Formacao Professor::getFormacaoProfessor() const {
    return formacaoProfessor;
}

std::string Professor::getDisciplina() const {
    return disciplina;
}

//Setters
void Professor::setNivelProfessor(Nivel novoNivel) {
    nivelProfessor = novoNivel;
}

void Professor::setFormacaoProfessor(Formacao novaFormacao) {
    formacaoProfessor = novaFormacao;
}

void Professor::setDisciplina(const std::string& novaDisciplina) {
    disciplina = novaDisciplina;
}
