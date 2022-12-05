#include <stdio.h>
#define max 3

// fazer ainda verificações na hora do cadastro;
// fazer menu com 5 itens ( primeiro cadastro e o resto esta abaixo)
// 2) Ordenar o cadastro por nome em ordem alfabética. 
// 3) Ordenar o cadastro por CR, maiores primeiro. 
// 4) Ler o valor de um RA e imprimir os dados do aluno no cadastro com mesmo RA. 
// 5) Imprimir o cadastro na ordem atual. 

typedef struct{
char nome_da_rua[50];
char cidade[15];
char estado[15];
char cep[9]
}tipo_endereco;

typedef struct{
 int dia;
 int mes;
 int ano;
}data;

typedef struct {
char nome[30];
data datanascimento;
char RG[13];
char Sexo;
tipo_endereco endereco;
int RA; // RA = registro academico
float CR; // CR = coeficiente de rendimento , sendo maximo = 1;
}dados;

void cadastrar_alunos(dados alunos[max], int *contador){
	int i,j,n;
	if(*contador==99)
	printf("memoria esta cheia");
	else{
		printf("Digite o número de cadastros para serem feitos: ");
		scanf("%i", &n);
		i = *contador; // para deixar mais arrumado o codigo
		j = i+n;
		do{
		printf("Aluno[%i]\n", i);	
		fflush(stdin);
		printf("Nome do Aluno: ");
		gets(alunos[i].nome);
		printf("\nData de nascimento: ");
		scanf("%i", &alunos[i].datanascimento.dia);
		scanf("%i", &alunos[i].datanascimento.mes);
		scanf("%i", &alunos[i].datanascimento.ano);
		i++;
		fflush(stdin); // tirar sujeira causada pelo enter antes da troca de int para string;
		printf("Rg: ");
		gets(alunos[i].RG);
		printf("Sexo: ");
		scanf("%c", &alunos[i].Sexo); // // tirar sujeira causada pelo enter antes da troca de char para string;
		printf("Endereco \n");
		fflush(stdin); 
		printf("Rua: ");
		gets(alunos[i].endereco.nome_da_rua);
		printf("Cidade: ");
		gets(alunos[i].endereco.cidade);
		printf("Estado: ");
		gets(alunos[i].endereco.estado);
		printf("CEP: ");
		gets(alunos[i].endereco.cep);
		fflush(stdin); // tirar sujeira causada pelo enter  antes da troca de string para int;
		printf("RA: ");
		scanf("%i", &alunos[i].RA);
		printf("CR: ");
		scanf("%f", &alunos[i].CR);	
			}while(i<j-1);
		*contador = i;	
		}
	}

int main(){
	int contador;
	contador = 0;
	dados alunos[max];
	cadastrar_alunos(alunos, &contador);
	printf("\n\n%i", contador);
}