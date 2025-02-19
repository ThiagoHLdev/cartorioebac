#include <stdio.h> //bibioteca de comunica��o do usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //bibloteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() //func�o respons�vel por cria��o de usu�rios no sistema
{
	// �nicio cria��o de var�avel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// fim da cria��o de var�avel/string
	
	printf("digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a stings
	
	strcpy(arquivo, cpf); // respons�vel por copiar os vlores das sting
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cia o arquuvo  e o "W" significa escrever
	fprintf(file,cpf); // salva o valor da vari�vel
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
       	  printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	   }
	   
	   while(fgets(conteudo, 200, file) !=NULL)
	   {
	   	  printf("\nEssas s�o as informa��es do us�ario; ");
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
   	printf("o us�ario n�o se encontra no sistema!. \n");
   	system("pause");
   	
   }
   
} 



int main()
{
	int opcao=0; //definindo a var�aveis
	int laco=1;
	
	for (laco==1;laco==1;)
	{
	
	    system("cls"); //responsavel por limpar a tela
	    
    	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
 	
    	printf("### cart�rio da EBAC ###\n\n"); //inicio do menu 
    	printf("Escolha a op��o desejada do menu\n\n");
    	printf("\t1 - Registrar nomes\n"); // chamada das fun��es 
    	printf("\t2 - consultar nomes\n");
    	printf("\t3 - deletar nomes\n\n");
    	printf("op��o: ");//fim do menu
    	
    	scanf("%d" , &opcao); // armazenando a escolha do usu�rio
	
    	system("cls");
    	
    	
    	switch(opcao)//inicio da sele��o
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
		   printf("est� op��o n�o est� dispon�vel\n");
	       system("pause");
	       break;
		
			
    	} // fim da sele�ao
        }
	
	    }
