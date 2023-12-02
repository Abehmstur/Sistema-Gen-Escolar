#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <string>
#include "funcionario.hpp"

class Professor : public Funcionario {
public:
    //Enumerações
    enum Nivel { I, II, III, IV, V, VI, VII, VIII };
    enum Formacao { ESPECIALIZACAO, MESTRADO, DOUTORADO };

private:
    Nivel nivelProfessor;
    Formacao formacaoProfessor;
    std::string disciplina;

public:
    //Construtor padrao
    Professor();

    //Construtor parametrizado
    Professor(Nivel _nivel, Formacao _formacao, const std::string& _disciplina);

    //Construtor parametrizado com as classes mães etc
    Professor(const std::string& _nome, const std::string& _cpf, const std::string& _dataNascimento, const Endereco& _endereco, const std::string& _matricula, float _salario, const std::string& _departamento, int _cargaHoraria, const std::string& _dataIngresso, const Nivel& _nivel, const Formacao& _formacao, const std::string& _disciplina) : Funcionario(_nome, _cpf, _dataNascimento, _endereco, _matricula, _salario, _departamento, _cargaHoraria, _dataIngresso), nivelProfessor(_nivel), formacaoProfessor(_formacao), disciplina(_disciplina) {};

    //Getters
    Nivel getNivelProfessor() const;
    Formacao getFormacaoProfessor() const;
    std::string getDisciplina() const;

    //Setters
    void setNivelProfessor(Nivel novoNivel);
    void setFormacaoProfessor(Formacao novaFormacao);
    void setDisciplina(const std::string& novaDisciplina);

    // Método estático para converter inteiro para enum Nivel
    static Nivel obterNivelPeloNumero(int numero) {
        return static_cast<Nivel>(numero);
    }

    // Método estático para converter inteiro para enum Formacao
    static Formacao obterFormacaoPeloNumero(int numero) {
        return static_cast<Formacao>(numero);
    }

    // Método para obter o nome do enum Nivel
    static std::string obterNomeDoNivel(Nivel nivel) {
        const char* nomes[] = { "I", "II", "III", "IV", "V", "VI", "VIII" };
        return nomes[nivel];
    }

    // Método para obter o nome do enum Formacao
    static std::string obterNomeDaFormacao(Formacao formacao) {
        const char* nomes[] = { "ESPECIALIZACAO", "MESTRADO", "DOUTORADO" };
        return nomes[formacao];
    }
};

#endif
