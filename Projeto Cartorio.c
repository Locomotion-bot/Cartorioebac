#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por  cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
		//inicio criação de váriaveis/string	
		char arquivo[40];
		char cpf [40];
		char nome [40];
		char sobrenome [40];
		char cargo [40];
		//final da criação de variáveis/string
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
		scanf("%s", cpf); //%s refere-se a strings
		
		strcpy(arquivo, cpf); //Responsável por copiar os valores das string
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa write de escrita
		fprintf(file,cpf); // salvo o valor da variável
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
			printf("Não foi possivel abrir o arquivo, não localizado!.\n");	
		}	
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\n Essas são as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
			fclose(file);
		}
		
		system("pause");
}

int deletar()
{
		char cpf[40];
		
		printf("Digiite o CPF do usuário a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("O usuário não foi encontrado no sistema!.\n");
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
		
	
		setlocale(LC_ALL, "Portuguese"); //Serve para definir o local no qual o programa está rodando
	
		printf("### Cartório da EBAC ###\n\n"); //as # são puramente cosmeticas \n é para pular linha
		printf("Escolha a opção desejada do menu:\n\n"); // \t serve para dar o espaço 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: ");
		
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");//responsavel por limpar a tela
		
			switch(opcao)//inicio da seleção do menu
		{
			case 1:
			registro();//chama de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		}
	
	
	
}
}
