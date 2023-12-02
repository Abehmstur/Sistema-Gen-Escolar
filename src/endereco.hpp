#ifndef ENDERECO_HPP
#define ENDERECO_HPP

#include <string>

class Endereco {
    private:
        std::string rua;
        int numero;
        std::string bairro;
        std::string cidade;
        std::string cep;

    public:
        // Construtor
        Endereco() {
            numero = 0;
        }

        // Getters
        std::string getRua() const;
        int getNumero() const;
        std::string getBairro() const;
        std::string getCidade() const;
        std::string getCEP() const;

        // Setters
        void setRua(const std::string& newRua);
        void setNumero(int newNumero);
        void setBairro(const std::string& newBairro);
        void setCidade(const std::string& newCidade);
        void setCEP(const std::string& newCEP);
};
#endif