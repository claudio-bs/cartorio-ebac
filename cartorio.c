#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas string

int registro()
{	//in�cio das declara��es de fun��es/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim das fun��es/string
	
	printf("Digite  CPF a ser cadastrado: "); //mensagem ao usu�rio
	scanf("%s", cpf); //armazena os dados inseridos pelo usu�rio na fun��o "cpf"
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //comando para acessar biblioteca de arquivos 
	file = fopen(arquivo, "w"); //abre ou cria um arquivo de texto no modo "w" (write ou escrever)
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo no modo "a" (iclus�o ou append)
	fprintf(file, " - CPF,\n"); //salva o valor da vari�vel
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
	
	system("pause"); //pausa o programa e mostra ao usu�rio o que estiver dentro do �ltimo "printf"	
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
	
	
	if(file == NULL) //condi��o se o dado inserido pelo usu�rio for valor nulo no arquivo
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	printf("\nEssas s�o as informa��es do usu�rio: ");
	
	while(fgets(conteudo, 200, file)!= NULL) //enquanto o dado inserido pelo usu�rio localizar informa��es vinculadas no arquivo at� 200 caracateres ser�o mostrados em tela
	{
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //pausa o programa e mostra ao usu�rio o que estiver dentro do �ltimo "printf"
	fclose(file); //fecha o arquivo
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file); //fecha o arquivo
	
	remove(cpf); //comando que apaga o dado informado pelo usu�rio do arquivo
	
	printf("\nUsu�rio deletado com sucesso do sistema!\n\n");
	system("pause");
	
	if(file == NULL) //condi��o se o dado inserido pelo usu�rio for valor nulo no arquivo
	{
		printf("Usu�rio n�o se encontra no sistema!\n\n");
		system("pause");
		fclose(file); //fecha o arquivo
	}	

}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //Comando do sistema operacional para limpar as mensagens da tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("#*#*# Cart�rio da EBAC #*#*#\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do Menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Comando do sistema operacional para limpar as mensagens da tela
	
		switch(opcao) //In�cio da sele��o utilizando operadores de repeti��o (opera��es l�gicas)
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
			printf("Essa op��o n�o est� dispon�vel!\n\n"); //Fim da sele��o (opera��es l�gicas)
			system("pause");
			break;
		}
		printf("\n\n\nDesenvolvido por Cl�udio Santana para o curso da EBAC.\n\n\n");	//Cr�ditos de desenvolvimento
		system("pause");
	}
	
}
