#ifndef TECNICO_ADM_HPP
#define TECNICO_ADM_HPP

#include "funcionario.hpp"
#include <iostream>
#include <string>

/**
 * @file tecnico_adm.hpp
 * @brief Implementação da classe TecnicoADM.
 */

/**
 * @class TecnicoADM
 * @brief Classe que representa um técnico administrativo.
 * @details Herda da classe Funcionario e implementa funcionalidades específicas para técnicos administrativos.
 */
class TecnicoADM : public Funcionario {
private:
    float adicionalProdutividade; ///< Adicional de produtividade do técnico administrativo.
    std::string funcaoDesempenhada; ///< Função desempenhada pelo técnico administrativo.

public:
    /**
     * @brief Construtor parametrizado da classe TecnicoADM.
     * @param _adicionalProdutividade Adicional de produtividade do técnico administrativo.
     * @param _funcaoDesempenhada Função desempenhada pelo técnico administrativo.
     */
    TecnicoADM(float _adicionalProdutividade, const std::string& _funcaoDesempenhada);

    /**
     * @brief Getter para obter o adicional de produtividade do técnico administrativo.
     * @return O adicional de produtividade.
     */
    float getAdicionalProdutividade() const;

    /**
     * @brief Getter para obter a função desempenhada pelo técnico administrativo.
     * @return A função desempenhada.
     */
    std::string getFuncaoDesempenhada() const;

    /**
     * @brief Setter para definir o adicional de produtividade do técnico administrativo.
     * @param novoAdicionalProdutividade Novo adicional de produtividade a ser definido.
     */
    void setAdicionalProdutividade(float novoAdicionalProdutividade);

    /**
     * @brief Setter para definir a função desempenhada pelo técnico administrativo.
     * @param novaFuncaoDesempenhada Nova função desempenhada a ser definida.
     */
    void setFuncaoDesempenhada(const std::string& novaFuncaoDesempenhada);

    /**
     * @brief Método para imprimir o salário do funcionário com base na matrícula.
     * @param _matricula Matrícula do funcionário.
     * @details O método lê o arquivo "funcionarios.txt" em busca do funcionário com a matrícula informada e imprime seu salário.
     */
    void imprimirSalarioDoFuncionarioByMatricula(int _matricula);
};
#endif
