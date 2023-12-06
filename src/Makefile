# Nome do seu programa
PROGRAMA = sge-program

# Compilador a ser utilizado
CC = g++

# Flags de compilação
CFLAGS = -std=c++11 -Wall

# Lista de todos os arquivos .cpp
SRCS = main.cpp bancoDao.cpp endereco.cpp funcionario.cpp pessoa.cpp professor.cpp tecnico_adm.cpp

# Comando para compilar o programa
$(PROGRAMA): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(PROGRAMA)

# Comando para limpar arquivos temporários
clean:
	rm -f $(PROGRAMA)
