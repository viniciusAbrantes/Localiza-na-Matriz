#Arquivo Makefile contendo as instruções para a criação do executável e suas dependências
 #Para criar o executável, basta digitar o comando 'make' no terminal dentro da pasta que contém os arquivos
 #Para apagar os arquivos objeto e executável, basta digitar o comando 'make clean'

procuraValor: main.o funções.o
	gcc main.o funções.o -o procuraValor.exe -lpthread

main.o: main.c
	gcc -c main.c

funções.o: funções.c funções.h
	gcc -c funções.c

clean:
	rm *.o procuraValor.exe


#Criado pelos alunos:
 #Alfredo Albélis Batista
 #Cléofas Peres Santos
 #Vinícius Abrantes Pereira
