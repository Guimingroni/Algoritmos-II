#include <stdio.h>
#define max 2
struct vetor{ 
float x; 
float y; 
float z; 
}; 

void cadastrardados(struct vetor a[max]){
	int i;
	for(i=0;i<max;i++){
	printf("Vetor [%i]\n", i);
	printf("variavel x: ");
	scanf("%f", &a[i].x);
	printf("variavel y: ");
	scanf("%f", &a[i].y);
	printf("variavel z: ");
	scanf("%f", &a[i].z);	
	}
}

void somardados(struct vetor a[max], struct vetor resultado){
	int i;
	resultado.x = 0;
	resultado.y = 0;
	resultado.z = 0;
	for(i=0;i<max;i++){
	resultado.x += a[i].x;
	resultado.y += a[i].y;	
	resultado.z += a[i].z;
	}
	printf("%f ", resultado.x);
	printf("%f ", resultado.y);
	printf("%f ", resultado.z);
	}

int main(){
struct vetor a[2], resultado;
cadastrardados(a);
somardados(a, resultado);
}