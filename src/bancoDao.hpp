#ifndef BANCODAO_HPP
#define BANCODAO_HPP

#include <string>
#include "professor.hpp"
#include "tecnico_adm.hpp"
#include <iostream>
#include <vector>

class BancoDao : public Professor, TecnicoADM{
    private:

    public:
        // Vetores de prof e tec adm
        std::vector<Professor> professores;
        std::vector<TecnicoADM> tecnicosADM;

        // Funções Professor
        void cadastrarProfessor(std::vector<Professor>& professores);
        void listarProfessores();
        void deletarProfessor(int matricula);
        void buscarProfessor(int matricula);

        // Funções TecnicoADM
        void cadastrarTecnicoADM(std::vector<TecnicoADM>& tecnicosADM);
        void listarTecnicosADM();
        void deletarTecnicoADM(int matricula);
        void buscarTecnicoADM(int matricula);

        // Exceptions temporarias
        void operacaoSucesso();
        void operacaoFalha();

};
#endif