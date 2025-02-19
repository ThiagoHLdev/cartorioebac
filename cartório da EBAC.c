#include <stdio.h> //bibioteca de comunicação do usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //bibloteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() //funcão responsável por criação de usuários no sistema
{
	// ínicio criação de varíavel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// fim da criação de varíavel/string
	
	printf("digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a stings
	
	strcpy(arquivo, cpf); // responsável por copiar os vlores das sting
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cia o arquuvo  e o "W" significa escrever
	fprintf(file,cpf); // salva o valor da variável
	fclose(file); // fecho o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
	
}


int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
       char cpf[40];
       char conteudo[400];
       
       printf("digite o CPF a ser consultado; ");
       scanf("%s", cpf);
       
       FILE *file;
       file = fopen(cpf,"r");
       
       if(file == NULL)
       {
       	  printf("Não foi possível abrir o arquivo, não localizado!.\n");
	   }
	   
	   while(fgets(conteudo, 200, file) !=NULL)
	   {
	   	  printf("\nEssas são as informações do usúario; ");
	   	  printf("%s", conteudo);
	   	  printf("\n\n");
	   }
	   
	   system("pause");
	   
       
       
}
int deletar()
{
   char cpf[40];
   
   printf("digite o CPF a ser deletado:");
   scanf("%s",cpf);
   
   
   remove(cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
   	printf("o usúario não se encontra no sistema!. \n");
   	system("pause");
   	
   }
   
} 



int main()
{
	int opcao=0; //definindo a varíaveis
	int laco=1;
	
	for (laco==1;laco==1;)
	{
	
	    system("cls"); //responsavel por limpar a tela
	    
    	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
 	
    	printf("### cartório da EBAC ###\n\n"); //inicio do menu 
    	printf("Escolha a opção desejada do menu\n\n");
    	printf("\t1 - Registrar nomes\n"); // chamada das funções 
    	printf("\t2 - consultar nomes\n");
    	printf("\t3 - deletar nomes\n\n");
    	printf("opção: ");//fim do menu
    	
    	scanf("%d" , &opcao); // armazenando a escolha do usuário
	
    	system("cls");
    	
    	
    	switch(opcao)//inicio da seleção
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
		
	       default:
		   printf("está opção não está disponível\n");
	       system("pause");
	       break;
		
			
    	} // fim da seleçao
        }
	
	    }
