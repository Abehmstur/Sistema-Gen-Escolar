#include "tecnico_adm.hpp"
#include "funcionario.hpp"

// Construtor parametrizado
TecnicoADM::TecnicoADM(float _adicionalProdutividade, const std::string& _funcaoDesempenhada)
    : adicionalProdutividade(_adicionalProdutividade), funcaoDesempenhada(_funcaoDesempenhada) {
}

// Getters
float TecnicoADM::getAdicionalProdutividade() const {
    return adicionalProdutividade;
}

std::string TecnicoADM::getFuncaoDesempenhada() const {
    return funcaoDesempenhada;
}

// Setters
void TecnicoADM::setAdicionalProdutividade(float novoAdicionalProdutividade) {
    adicionalProdutividade = novoAdicionalProdutividade;
}

void TecnicoADM::setFuncaoDesempenhada(const std::string& novaFuncaoDesempenhada) {
    funcaoDesempenhada = novaFuncaoDesempenhada;
}
