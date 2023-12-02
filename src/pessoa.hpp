#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include "endereco.hpp"

class Pessoa : public Endereco{
    private:
        std::string nome;
        std::string cpf;
        std::string dataNascimento;
        Endereco endereco;
    
    public:
        //Constructor
        Pessoa();
        
        // Construtor parametrizado
        Pessoa(const std::string& _nome, const std::string& _cpf, const std::string& _dataNascimento, const Endereco& _endereco);

        // Getters
        std::string getNome() const;
        std::string getCPF() const;
        std::string getDataNascimento() const;
        Endereco getEndereco() const;

        // Setters
        void setNome(const std::string& novoNome);
        void setCPF(const std::string& novoCPF);
        void setDataNascimento(const std::string& novaData);
        void setEndereco(const Endereco& novoEndereco);
};

#endif