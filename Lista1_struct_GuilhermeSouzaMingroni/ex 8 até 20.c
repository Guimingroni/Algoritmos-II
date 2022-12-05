#include <stdio.h>
#define max 100

// falta menu ;
// caso queira ver apenas uma funcao colocar // na frente das outras;

typedef struct{
	int dia;
	int mes;
	int ano;
}tipo_data; 


typedef struct{
char nome[30];
char rg[13]; // "54.238.069-9"+"/0"
float salario;
int idade;
char sexo;
tipo_data Data_nascimento;	
}TipoReg;

typedef struct{
TipoReg funcionarios[max];
int quantidade;	
}TipoCadastro;

void IniciaCadastro(TipoCadastro *X){
	(*X).quantidade = 0; // colocar um parenteses para passar por parametro;
}

void LeFuncionarios(TipoCadastro *X){
	int n, j, quant;
	if((*X).quantidade>=99){
		printf("memoria esta cheia\n");
	}
	else{
	printf("Digite o numero de funcionarios a serem lidos: ");
	scanf("%i", &n);
	quant = (*X).quantidade;
	j = quant + n;
	fflush(stdin); // tirar a sujeira causada pelo enter;
		if(j >99)
	printf("o numero de funcionarios passa da quantidade maxima que pode ser lida");
		else{
		for(quant>=0;quant<j;quant++){
		fflush(stdin);
		printf("Funcionario [%i]\n", quant);
		printf("Nome: "); //usar todos minusculos ou maiusculos para nao ter fazer uma funcao toupper ou tolower;
		gets((*X).funcionarios[quant].nome);
		printf("Rg: ");
		gets((*X).funcionarios[quant].rg);
		printf("Salario: ");
		scanf("%f", &(*X).funcionarios[quant].salario);
		printf("Idade: ");
		scanf("%i", &(*X).funcionarios[quant].idade);
		fflush(stdin); // tirar a sujeira causada pelo enter;
		printf("Sexo (M ou F): ");
		scanf("%c", &(*X).funcionarios[quant].sexo);
		printf("Data de nascimento: ");
		fflush(stdin);
		scanf("%i", &(*X).funcionarios[quant].Data_nascimento.dia);
		scanf("%i", &(*X).funcionarios[quant].Data_nascimento.mes);
		scanf("%i", &(*X).funcionarios[quant].Data_nascimento.ano);
			}
		(*X).quantidade = quant;		
		}	
	}
}

void ListaFuncionarios(TipoCadastro *X){
	int i, quant;
	quant = (*X).quantidade;
	for(i=0;i<quant;i++){
	printf("Funcionario [%i]\n",i);
	printf("Nome: %s\n", (*X).funcionarios[i].nome);
	printf("RG: %s\n", (*X).funcionarios[i].rg);
	printf("Salario: %.2f\n", (*X).funcionarios[i].salario);
	printf("Idade: %i\n", (*X).funcionarios[i].idade);
	printf("Sexo: %c", (*X).funcionarios[i].sexo);
	printf("Data de nascimento: %i/%i/%i \n", (*X).funcionarios[i].Data_nascimento.dia, (*X).funcionarios[i].Data_nascimento.mes, (*X).funcionarios[i].Data_nascimento.ano);
	}
}

void Ordenanome(TipoCadastro *X){
	int i, j, quant, result;
	TipoCadastro Aux;
	quant = (*X).quantidade;
	for(i=0;i<quant-1;i++){
	for(j=1;j<quant;j++){
	result = strcmp((*X).funcionarios[i].nome, (*X).funcionarios[j].nome);
	if(result > 0){
	Aux.funcionarios[i]=(*X).funcionarios[i];
	(*X).funcionarios[i] = (*X).funcionarios[j];
	(*X).funcionarios[j] = Aux.funcionarios[i];
			}	
		}
	}
}

void OrdenaSalario(TipoCadastro *X){ // ordem crescente
	int i, j, quant;
	TipoCadastro Aux;
	quant = (*X).quantidade;
	for(i=0;i<quant-1;i++){
	for(j=1;j<quant;j++){
	if((*X).funcionarios[i].salario > (*X).funcionarios[j].salario){
	Aux.funcionarios[i]=(*X).funcionarios[i];
	(*X).funcionarios[i] = (*X).funcionarios[j];
	(*X).funcionarios[j] = Aux.funcionarios[i]; 
			}
		}	
	}
}

void SalarioIntervalo(TipoCadastro *X,int v1,int v2){
int aux;
if(v1>v2){
aux = v1;
v1 = v2;
v2 = aux	
}
int i, quant, funcionarios_intervalo;
funcionarios_intervalo=0;
float media;
media = 0;
quant = (*X).quantidade;
for(i=0;i<quant;i++){
	if((*X).funcionarios[i].salario >= v1 && (*X).funcionarios[j].salario <= v2){
	printf("Funcionario [%i]\n",i);
	printf("Nome: %s\n", (*X).funcionarios[i].nome);
	printf("RG: %s\n", (*X).funcionarios[i].rg);
	printf("Salario: %.2f\n", (*X).funcionarios[i].salario);
	printf("Idade: %i\n", (*X).funcionarios[i].idade);
	printf("Sexo: %c", (*X).funcionarios[i].sexo);
	printf("Data de nascimento: %i/%i/%i \n", (*X).funcionarios[i].Data_nascimento.dia, (*X).funcionarios[i].Data_nascimento.mes, (*X).funcionarios[i].Data_nascimento.ano);
	funcionarios_intervalo ++ ;
	media += (*X).funcionarios[i].salario;
		}	
	}
	media = media/quant;
	printf("Media de salario : %f", media);
}

void ImpostoFuncionario(Tipo Cadastro X, numero_funcionario){
	float imposto;
	printf("%s", X.funcionarios[numero_funcionario].nome);
	if(X.funcionarios[numero_funcionario].salario <=1000)
	printf("Isento de imposto\n");
	else if(X.funcionarios[numero_funcionario].salario >1000 && X.funcionarios[numero_funcionario].salario <=2000)
	imposto = X.funcionarios[numero_funcionario].salario * 0.1;
	printf("Imposto do funcionario [%i:] %f\n", numero_funcionario, imposto);
	else if(X.funcionarios[numero_funcionario].salario >2000 && X.funcionarios[numero_funcionario].salario <=3500)
	imposto = X.funcionarios[numero_funcionario].salario * 0.15;
	printf("Imposto do funcionario [%i]: %f\n", numero_funcionario, imposto);
	else if(X.funcionarios[numero_funcionario].salario >3500)
	imposto = X.funcionarios[numero_funcionario].salario * 0.25;
	printf("Imposto do funcionario [%i]: %f\n", numero_funcionario, imposto);
} 

int main(){
	int v1, v2, numero_funcionario, opcao;
	TipoCadastro X;
	IniciaCadastro(&X); // funcao ex 9
	
	LeFuncionarios(&X); // funcao ex 10
	// funcao ex 11: 
	ListaFUncionarios(&X);
	// funcoes ex 12:
	Ordenanome(&X);
	OrdenaSalario(&X);
	// funcao ex 13:
	printf("Digite os valores de v1 e v2 (valor minimo e máximo de salário): ")
	scanf("%i", &v1);
	scanf("%i", &v2);
	SalarioIntervalo(&X, v1, v2);
	// funcao ex 14:
	printf("Digite o funcionario que voce quer ver o imposto: ");
	scanf("%i", &numero_funcionario); // 1 funcionario -> numero 0;
	ImpostoFuncionario(X, numero_funcionario);
}
