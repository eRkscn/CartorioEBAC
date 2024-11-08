#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //fun�ao responsavel por cadastrar os usuarios no sistema
{
	//inicio cria�ao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria�ao de variaveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informa�ao do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa modo de escrita
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abrir o arquivo e o "a" para acrescentar informa�ao no arquivo
	fprintf(file,","); //separar as strings por virgula
	fclose(file);//fecha o arquivo

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //abrir o arquivo e o "a" para acrescentar informa�ao no arquivo
	fprintf(file,nome); 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abrir o arquivo e o "a" para acrescentar informa�ao no arquivo
	fprintf(file,","); //separar as strings por virgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //abrir o arquivo e o "a" para acrescentar informa�ao no arquivo
	fprintf(file,sobrenome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abrir o arquivo e o "a" para acrescentar informa�ao no arquivo
	fprintf(file,","); //separar as strings por virgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //abrir o arquivo e o "a" para acrescentar informa�ao no arquivo
	fprintf(file,cargo);
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausar o sistema para o usuario ler as infos
	getchar(); //aguarda o usu�rio pressionar uma tecla
}

int consulta() //fun�ao responsavel por consultar os usuarios no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio cria�ao de variaveis/string
	char cpf[40];
	char conteudo[200];
	char *token; 
	//final cria�ao de variaveis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //%s refere-se a string
	
	FILE*file;//cria o arquivo
	file = fopen(cpf,"r"); //abrir o arquivo para leitura
	
	if(file == NULL)
	{
		system("cls"); //responsavel por limpar a tela
		printf("Nao foi possivel abrir o arquivo, n�o localizado!.\n\n");
		system("pause"); //pausar o sistema para o usuario ler as infos
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas sao as informa�oes do usuario:\n");
		
		token = strtok(conteudo, ","); //dividir uma string em tokens
		printf("CPF: %s\n", token);
		
		token = strtok(NULL, ","); //dividir uma string em tokens
		printf("Nome: %s\n", token);
		
		token = strtok(NULL, ","); //dividir uma string em tokens
		printf("Sobrenome: %s\n", token);
		
		token = strtok(NULL, ","); //dividir uma string em tokens
		printf("Cargo: %s\n", token);
		
		system ("pause"); //pausar o sistema para o usuario ler as infos
		
	}
	
	getchar(); //aguarda o usu�rio pressionar uma tecla
	
	fclose(file); //fecha o arquivo
	
}

int deletar() //fun�ao responsavel por deletar os usuarios no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio cria�ao de variaveis/string
	char cpf[40];
	//final cria�ao de variaveis/string
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r"); //abrir o arquivo para leitura
	
	if (file == NULL) 

	{
		system("cls"); //responsavel por limpar a tela
    	printf("Este usu�rio n�o foi encontrado!\n\n");
		system("pause"); //pausar o sistema para o usuario ler as infos

  	} 
  
  	else
	
	{
  		fclose(file); //fecha o arquivo
		remove(cpf); // deleta o arquivo
  		
		system("cls"); //responsavel por limpar a tela
		printf("Usu�rio deletado!\n\n");
  		system("pause"); //pausar o sistema para o usuario ler as infos
		
	}
  	
  	getchar(); //aguarda o usu�rio pressionar uma tecla
  	
}

int sair()
{
	printf("Saindo...\n");
    exit(0); //fechar o programa
}

int main()
{
	int opcao=0; //Definindo as variaveis
	char input[10];
	
	setlocale(LC_ALL,"portuguese"); //Definindo a linguagem
	
	while (1) //Definindo repeti�ao
	{
		
		system("cls"); //responsavel por limpar a tela
		
		printf("### Cartorio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op�ao desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t0 - Sair\n\n");
		printf("Op�ao:"); //Fim do menu
	
		fgets(input, sizeof(input), stdin); // L� a entrada como string
        if (sscanf(input, "%d", &opcao) != 1) 
		{
        system("pause"); //pausar o sistema para o usuario ler as infos
        continue;// volta ao in�cio do loop se a entrada for inv�lida
		}
		
		system("cls"); //responsavel por limpar a tela
	
		switch(opcao) //Inicio da sele�ao
		{
		case 1:
		registro();// chamada de fun�oes
		break;
		
		case 2:
		consulta();
		break;
	
		case 3:
		deletar();
		break;
		
		case 0:
        sair();
        break;
		    
		default:
		printf("Essa op�ao nao esta disponivel!\n");
		system("pause"); //pausar o sistema para o usuario ler as infos
		break;
		
		} //Fim da sele�ao

	}
}

