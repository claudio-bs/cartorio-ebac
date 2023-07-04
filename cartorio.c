#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas string

int registro()
{	//início das declarações de funções/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim das funções/string
	
	printf("Digite  CPF a ser cadastrado: "); //mensagem ao usuário
	scanf("%s", cpf); //armazena os dados inseridos pelo usuário na função "cpf"
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //comando para acessar biblioteca de arquivos 
	file = fopen(arquivo, "w"); //abre ou cria um arquivo de texto no modo "w" (write ou escrever)
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo no modo "a" (iclusão ou append)
	fprintf(file, " - CPF,\n"); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " - NOME,\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " - SOBRENOME,\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " - CARGO,\n");
	fclose(file);
	
	system("pause"); //pausa o programa e mostra ao usuário o que estiver dentro do último "printf"	
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo em modo "r" (leitura)
	
	
	if(file == NULL) //condição se o dado inserido pelo usuário for valor nulo no arquivo
	{
		printf("\nNão foi possível abrir o arquivo, não localizado!\n");
	}
	
	printf("\nEssas são as informações do usuário: ");
	
	while(fgets(conteudo, 200, file)!= NULL) //enquanto o dado inserido pelo usuário localizar informações vinculadas no arquivo até 200 caracateres serão mostrados em tela
	{
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //pausa o programa e mostra ao usuário o que estiver dentro do último "printf"
	fclose(file); //fecha o arquivo
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file); //fecha o arquivo
	
	remove(cpf); //comando que apaga o dado informado pelo usuário do arquivo
	
	printf("\nUsuário deletado com sucesso do sistema!\n\n");
	system("pause");
	
	if(file == NULL) //condição se o dado inserido pelo usuário for valor nulo no arquivo
	{
		printf("Usuário não se encontra no sistema!\n\n");
		system("pause");
		fclose(file); //fecha o arquivo
	}	

}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //Comando do sistema operacional para limpar as mensagens da tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("#*#*# Cartório da EBAC #*#*#\n\n"); //Início do menu
		printf("Escolha a opção desejada do Menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Comando do sistema operacional para limpar as mensagens da tela
	
		switch(opcao) //Início da seleção utilizando operadores de repetição (operações lógicas)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Agradecemos por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n\n"); //Fim da seleção (operações lógicas)
			system("pause");
			break;
		}
		printf("\n\n\nDesenvolvido por Cláudio Santana para o curso da EBAC.\n\n\n");	//Créditos de desenvolvimento
		system("pause");
	}
	
}
