#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 20

typedef struct{
char nome[30];
char tipo_musica[15];
int numero_integrantes;
int posicao_top5; // sendo 0 fora do ranking;	
}dados_bandas;

void inicio_arquivo(dados_bandas bandas[max], dados_bandas top5[5]){
	int i;
	for(i=0;i<max;i++){
		bandas[i].posicao_top5 = -1 ; // valor fora do top 5
	}
	for(i=0;i<5;i++)
	top5[5].posicao_top5 = -1;
}

void cadastro_bandas(dados_bandas bandas[max], dados_bandas top5[5], int *contador){
	int i, n, postop5, j;
	if(*contador>=20)
	printf("Memoria está cheia\n");
	else{
	printf("digite o numero de bandas a ser inserido: ");
	scanf("%i", &n);
	if (n+*contador >= 20){
	printf("nao e possivel cadastrar esse numero de bandas\n");
	return 0;	
	}
	else
	i = *contador;
	fflush(stdin); // tirar o lixo causado pelo enter apos inserir o valor de n;
	j = i+n;
	for(i>=0;i<j;i++){
	printf("Banda [%i]:\n", i);
	fflush(stdin);	
	printf("Nome da banda: ");	
	gets(bandas[i].nome);
	printf("Tipo de musica: ");	
	gets(bandas[i].tipo_musica); // colocar em minusculo pra nao dar erro
	do{
	printf("Numero de integrantes: ");	
	scanf("%i", &bandas[i].numero_integrantes);	
	}while(bandas[i].numero_integrantes<=0);
	do{
	printf("Posicao top 5 : ");	
	scanf("%i", &bandas[i].posicao_top5);
	postop5 = bandas[i].posicao_top5;
	}while(bandas[i].posicao_top5 > 5 || bandas[i].posicao_top5<0);
	if(bandas[i].numero_integrantes>0 && bandas[i].numero_integrantes<=5){
	postop5--;
	top5[postop5] = bandas[i]; // se tiver outra banda naquela posicao ela sera removida da lista
			}	
	*contador = j;		
		}
	}
}

void mostrar_banda(dados_bandas banda){
 	printf("Nome da banda: %s\n", banda.nome);
	printf("Posicao: %i\n", banda.posicao_top5);
 	printf("Tipo de musica: %s\n", banda.tipo_musica);
 	printf("Numero de integrantes: %i\n", banda.numero_integrantes);
}

void procurar_por_ranking(dados_bandas top5[5]){
// por nao fazer sentido procurar bandas fora do top 5, usarei o top5 como referencia;
int posicao;
printf("Digite a posicao da banda que quer pesquisar (posicao - 1 por conta do vetor começar em 0): "); // exemplo 4 lugar top 5 vc digita 3
scanf("%i", &posicao);
mostrar_banda(top5[posicao]);
}

void procurar_por_tipo(dados_bandas top5[5]){
int posicao, result;
char tipo_musical[15];
printf("Digite o tipo musical que queira pesquisar: ");
fflush(stdin);
gets(tipo_musical);
for(posicao=0;posicao<5;posicao++){
	result = strcmp(tipo_musical, top5[posicao].tipo_musica); // compara as duas strings se for 0 sao iguais; se result > 0 o primeiro nome é maior que o segundo (seguindo a tabela asc II)
	if(result == 0)
	mostrar_banda(top5[posicao]);
	}		
}

void verificar_nome(dados_bandas top5[5]){
int posicao, verificar;
char nome_banda[30];
printf("Digite o nome da banda para verificarmos nos favoritos: ");
gets(nome_banda);
for(posicao=0;posicao<5;posicao++){
	verificar = strcmp(nome_banda,top5[posicao].nome); // compara os nomes das duas onde verificar == 0 mostra que sao iguais;
	if(verificar == 0){
	printf("esta no top5");
	break;
			}
		}
	if(verificar != 0)
	printf("nao esta no top5");		
}

int main(){
int contador, opcao; // ver se cabe ainda novas bandas
contador = 0;
char resposta;	
dados_bandas bandas[max], top5[5];
do{
cadastro_bandas(bandas, top5, &contador);
fflush(stdin);
printf("deseja inserir mais bandas? (S ou N)\n");	
scanf("%c", &resposta);
}while(resposta!= 'n' || resposta!= 'N');
do{
printf("Selecione uma das opcoes: 1-procurar por ranking, 2-procurar por tipo de musica, 3 - procurar por nome, 4- cadastrar bandas novas, 5 - sair\n");	
scanf("%i", &opcao);
}while(opcao<1 || opcao>5);
do{
fflush(stdin);	
if(opcao == 1)
procurar_por_ranking(top5);
else if(opcao == 2)
procurar_por_tipo(top5);
else if(opcao == 3)
verificar_nome(top5);
else if(opcao == 4)
cadastro_bandas(bandas, top5, &contador);
if(opcao !=5){
do{
fflush(stdin);	
printf("deseja utilizar mais alguma funcao? (S ou N)");
scanf("%c", &resposta);
system("cls");
	}while(resposta!='n' && resposta!='N' && resposta!= 's' && resposta != 'S');
		}
	}while(opcao!=5 && (resposta!= 'n' || resposta!= 'N'));
}
