#include <stdio.h>
#include <stdlib.h>

void maiusculo(char *a);

int main(void){
	// variáveis
	char texto[50];
	
	// entrada
	printf("Digite um texto: ");
	fgets(texto, 50, stdin);
	
	maiusculo(texto);
	
	printf("texto e : %s\n",texto);
	
	return 0;
}

void maiusculo(char *a){
	int i=0;
	while(a[i]!='\0'){
		if(a[i]>='a' && a[i]<='z'){
			a[i]-=32; // a[i]=a[i]-32;
		}
		i++;
	}
}