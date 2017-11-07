#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int menu() {
	int escolha;
	
	printf("Escolha uma opcao do menu\n");
	while ((escolha > 2) || (escolha < 1)) {
		printf("1 - Jogar contra computador\n");
		printf("2 - Jogar contra humano\n");
		scanf("%d", &escolha);		
	}
	
	return escolha;
	
}

void escolha_simb(char *jog1, char *jog2) {
	char jogador1;
	char jogador2;
	printf("\nEscolha o simbolo do jogador 1: ");
	scanf("%c", &jogador1);
	jog1 = &jogador1;
	if (jogador1 == 'x') {
		jogador2 = 'o';
	}
	else {
		jogador2 = 'x';
	}
	jog2 = &jogador2;
}

void inicializa_velha() {
	
}

int verifica_ganhador(char jog) {
	
}
void main() {
	int escolha = 0;
	int nivel = 0;
	char *jogador1;
	char *jogador2;
	char letra = 'q';
	escolha = menu();

	if (escolha == 1) {
		while ((nivel > 3) || (nivel < 1)) {
			printf("Escolha o nivel\n");
			printf("1 - Basico\n");
			printf("2 - Intermediario\n");
			printf("3 - Avancado\n");
			scanf("%d", &nivel);	
		}
	}
	printf("\nopcao escolhida: %d", escolha);
	printf("\nnivel escolhido: %d", nivel);
	
	escolha_simb(jogador1, jogador2);
	printf("\njog1 %c", *jogador1);
	system("pause");
}


