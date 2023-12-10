#ifndef BANCODAO_HPP
#define BANCODAO_HPP

#include <string>
#include "professor.hpp"
#include "tecnico_adm.hpp"
#include <iostream>
#include <vector>

/**
 * @file bancoDao.hpp
 * @brief Declaração da classe BancoDao e suas funcionalidades.
 */

/**
 * @class BancoDao
 * @brief Classe responsável por realizar operações de cadastro, listagem e remoção de Professores e Técnicos ADM.
 */

class BancoDao {
private:
    // Não há membros privados na classe.

public:
    /**
     * @brief Vetor que armazena objetos da classe Professor.
     */
    std::vector<Professor> professores;

    /**
     * @brief Vetor que armazena objetos da classe TecnicoADM.
     */
    std::vector<TecnicoADM> tecnicosADM;

    // Funções relacionadas a Professores

    /**
     * @brief Cadastra um novo Professor no sistema.
     * @param professores Vetor de professores onde o novo Professor será armazenado.
     */
    void cadastrarProfessor(std::vector<Professor>& professores);

    /**
     * @brief Lista todos os Professores cadastrados no sistema.
     */
    void listarProfessores();

    /**
     * @brief Deleta um Professor do sistema com base na matrícula.
     * @param matricula Matrícula do Professor a ser deletado.
     */
    void deletarProfessor(int matricula);

    /**
     * @brief Busca e exibe os dados de um Professor com base na matrícula.
     * @param matricula Matrícula do Professor a ser buscado.
     */
    void buscarProfessor(int matricula);

    // Funções relacionadas a Técnicos ADM

    /**
     * @brief Cadastra um novo Técnico ADM no sistema.
     * @param tecnicosADM Vetor de técnicos ADM onde o novo Técnico ADM será armazenado.
     */
    void cadastrarTecnicoADM(std::vector<TecnicoADM>& tecnicosADM);

    /**
     * @brief Lista todos os Técnicos ADM cadastrados no sistema.
     */
    void listarTecnicosADM();

    /**
     * @brief Deleta um Técnico ADM do sistema com base na matrícula.
     * @param matricula Matrícula do Técnico ADM a ser deletado.
     */
    void deletarTecnicoADM(int matricula);

    /**
     * @brief Busca e exibe os dados de um Técnico ADM com base na matrícula.
     * @param matricula Matrícula do Técnico ADM a ser buscado.
     */
    void buscarTecnicoADM(int matricula);

    // Funções para manipulação de exceções temporárias

    /**
     * @brief Exibe mensagem de sucesso após uma operação.
     */
    void operacaoSucesso();

    /**
     * @brief Exibe mensagem de falha após uma operação.
     */
    void operacaoFalha();

    /**
     * @brief Lê o número informado pelo usuário e retorna uma exceção caso não seja um valor válido.
     * @return Número inteiro informado pelo usuário.
     */
    int lerNumero();

};
#endif
