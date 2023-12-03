#include <iostream>
#include "../excecoes/bancoDaoExcecoes.hpp"

using namespace std;

double divide(double x, double y){
    if(y==0){
        throw "Erro de Divisao por ZERO!";
    }
    return x / y;
}

void lerNumero() {
    int numero;

    cout << "Digite um(a) numero inteiro: ";
    try {
        if (!(cin >> numero)) {
            cin.clear();
            cin.ignore();
            throw bancoDaoExcecoes("Entrada invalida! Digite um numero inteiro.");
        }
        
    } catch(const bancoDaoExcecoes& erro){
        cout << "================================================================================================================" << endl;
        cout << "| ERROR: " << erro.what() << endl;
        cout << "================================================================================================================" << endl;
    }
}

int main()
{
    lerNumero();
    
    return 0;
}
