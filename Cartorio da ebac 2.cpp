#include <stdio.h> //biblioteca de comunica��o com o us�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informa��es do usuario
	scanf("%s",cpf); //%s se refere as string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //criar arquivo
	file = fopen(arquivo, "w"); //criar o arquivo // e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file= fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file= fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL,"portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf [40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o us�rio n�o encontrado no sistema! .\n");
		system("pause");
		
	}
}


int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
	setlocale(LC_ALL,"portuguese"); //definindo linguagem
	printf("### cart�rio da EBAC ###\n\n");
	printf( "Escolha a op��o desejada do menu:\n\n"); //inicio do menu
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - consultar nomes\n");
	printf("\t3 - deletar nomes\n\n"); //fim do menu
	
	
	scanf("%d",&opcao); //armazenamento a escolha do usuario
	
	system("cls"); // responsavel por limpar historico de escritas do usuarios
	
	switch(opcao)
	
	{

	case 1:
    registro();
	break;
		
	case 2:
    consultar();
	break;
	
	case 3:
	deletar();
	break;
		
	default:
	printf("essa op��o n�o est� disponivel\n");
	system("pause");
	break;	


	 }	
	
 
   }
}


