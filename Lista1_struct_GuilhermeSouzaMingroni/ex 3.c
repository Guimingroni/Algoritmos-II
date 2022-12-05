#include <stdio.h>
#define max 2
typedef struct{
	float real; // parte real
	float imaginario; // parte imaginaria
}num_complexo;

void lernumeros(num_complexo valores[max]){
	int i;
	for(i=0;i<max;i++){
		printf("\nParte real do valor[%i]\n", i);
		scanf("%f", &valores[i].real);
		printf("\nParte imaginaria do valor[%i]\n", i);
		scanf("%f", &valores[i].imaginario);
	}
}

void soma(num_complexo valores[max]){
int i;
for(i=1;i<max;i++){
	valores[0].real += valores[i].real;
	valores[0].imaginario += valores[i].imaginario;
}
if(valores[0].imaginario>=0)
printf("soma -> %.3f + %.3fi\n", valores[0].real, valores[0].imaginario);
else if(valores[0].imaginario<0)
printf("soma -> %.3f  %.3fi\n", valores[0].real, valores[0].imaginario);
}

void subtrai(num_complexo valores[max]){
int i=0;
for(i=1;i<max;i++){
	valores[i].real = valores[0].real - valores[i].real;
	valores[i].imaginario = valores[0].imaginario - valores[i].imaginario;
}
if(valores[0].imaginario>=0)
printf("subtraçao -> %.3f + %.3fi\n", valores[1].real, valores[1].imaginario);
if(valores[0].imaginario<0)
printf("subtraçao -> %.3f  %.3fi\n", valores[1].real, valores[1].imaginario);
}

void multiplicacao(num_complexo valores[max]){
	float a,b,c,d, total_real, total_imaginario;
	a = valores[0].real;
	b = valores[0].imaginario;
	c = valores[1].real;
	d = valores[1].imaginario;
	total_real = a*c + (-1*b*d);
	total_imaginario = b*c + a*d;
	if(total_imaginario >=0)
	printf("multiplicacao -> %.3f + %.3fi\n", total_real, total_imaginario);
	else if(total_imaginario <0)
	printf("multiplicacao -> %.3f  %.3fi\n", total_real, total_imaginario);
}

int main(){
	int escolha;
	num_complexo valores[max];
	lernumeros(valores);
	printf("escolha uma opçao: 1-soma, 2-subtracao, 3-multiplicacao, 4-sair\n");
	do{
	scanf("%i", &escolha);	
	}while(escolha<1 || escolha>4);
	if(escolha==1)
	soma(valores);
	else if(escolha==2)
	subtrai(valores);
	else if(escolha==3)
	multiplicacao(valores);
	else if(escolha==4)
	return 0;
}