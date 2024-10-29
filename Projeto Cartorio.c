#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por  cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
		//inicio cria��o de v�riaveis/string	
		char arquivo[40];
		char cpf [40];
		char nome [40];
		char sobrenome [40];
		char cargo [40];
		//final da cria��o de vari�veis/string
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
		scanf("%s", cpf); //%s refere-se a strings
		
		strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa write de escrita
		fprintf(file,cpf); // salvo o valor da vari�vel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s" ,sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
		
}

int consulta()
{
		setlocale(LC_ALL, "Portuguese"); 
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s",cpf);
		
		FILE *file;
		file =  fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");	
		}	
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\n Essas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
			fclose(file);
		}
		
		system("pause");
}

int deletar()
{
		char cpf[40];
		
		printf("Digiite o CPF do usu�rio a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("O usu�rio n�o foi encontrado no sistema!.\n");
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
		
	
		setlocale(LC_ALL, "Portuguese"); //Serve para definir o local no qual o programa est� rodando
	
		printf("### Cart�rio da EBAC ###\n\n"); //as # s�o puramente cosmeticas \n � para pular linha
		printf("Escolha a op��o desejada do menu:\n\n"); // \t serve para dar o espa�o 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");//responsavel por limpar a tela
		
			switch(opcao)//inicio da sele��o do menu
		{
			case 1:
			registro();//chama de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		}
	
	
	
}
}
