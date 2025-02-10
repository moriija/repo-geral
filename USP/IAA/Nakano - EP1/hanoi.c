#include <stdio.h>
#include <stdlib.h>

int callOrder = 0;

void indent(int n) {
  for (int i=0;i<n;i++) {
    putchar('\t');
  }
}

void hanoi(char ori, char dst, char aux, int nro, int nivel, int nroAntes) {

	// Entrando em F(nro)
	callOrder++;
	indent(nivel);
	printf("%d - ", callOrder);
	printf("Entrou no cálculo de F(%d).\n", nro);

	if(nro == 1) {
		indent(nivel);
		printf("=== Move de %c", ori);
		printf(" para %c ===\n", dst);
	}
	else {
		hanoi(ori, aux, dst, nro-1, nivel+1, nro);
		hanoi(ori, dst, aux, 1, nivel+1, nro);
		hanoi(aux, dst, ori, nro-1, nivel+1, nro);
	}

	// Retornando de F(nro)
	callOrder++;
	if( nro != 4 ){
		indent(nivel-1);
		printf("%d - ", callOrder);
		printf("Retornou ao cálculo de F(%d).\n", nroAntes);
	}
}

void main (void) {
	int nivel = 0;
	hanoi('A', 'B', 'C', 4, nivel, -1);
}
