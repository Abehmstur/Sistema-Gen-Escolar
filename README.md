# SIGEscolar
 Sistema de gerenciamento de funcionarios professor e tecnicos com turma. 

# Para Compilar o Projeto SEM o MAKE FILE
No terminal, na pasta SRC do projeto, escreva: 
g++ main.cpp bancoDao.cpp endereco.cpp funcionario.cpp pessoa.cpp professor.cpp tecnico_adm.cpp turma.cpp -o sge-program

Após isso, ainda na pasta SRC do projeto, no terminal, escreva: .\sge-program.exe

# Para Compilar o Projeto COM o MAKE FILE no WINDOWS
com o mingw instalado no seu computador, caso não tenha o makefile instalado, execute o seguinte comando no seu Windows PowerShell:
mingw-get install mingw32-make

Após isso ele estara instalado, agora, para executar o makefile e compilar o seu projeto.
Para compilar o seu projeto com o MakeFile, acesse a pasta SRC do projeto o terminal e execute o seguinte comando:
mingw32-make.exe sge-program

Agora para executar, acesse a pasta SRC do projeto o terminal e execute o seguinte comando:
.\sge-program.exe
