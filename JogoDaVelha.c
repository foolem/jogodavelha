#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char tabuleiro[3][3];
int primeira=0;
void main();
void jogo_computador(int nivel);
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
	int simbjog1 = 0;
	while (simbjog1 == 0) {
		printf("\nEscolha o simbolo do jogador 1: ");
		scanf("%*c%c", &jogador1);
		if ( (jogador1 == 'x') || ( jogador1 == 'o' )) {
			simbjog1 = 1;
		}
		else {
			simbjog1 = 0;
		}
	}

	*jog1 = jogador1;
	if (jogador1 == 'x') {
		jogador2 = 'o';
	}
	else {
		jogador2 = 'x';
	}
	*jog2 = jogador2;
}

void inicializa_velha() {
	int i, j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			tabuleiro[i][j] = ' ';
		}
	}

	printf("\n       1  2  3\n");
	printf("\n     1  |   |  ");
	printf("\n      --|---|--");
	printf("\n     2  |   |  ");
	printf("\n      --|---|--");
	printf("\n     3  |   |  \n\n\n");
}

void mostra_velha(){
    printf("\n       1  2  3\n");
    printf("\n     1 %c| %c |%c ",tabuleiro[0][0],tabuleiro[0][1],tabuleiro[0][2]);
    printf("\n      --|---|--");
    printf("\n     2 %c| %c |%c ",tabuleiro[1][0],tabuleiro[1][1],tabuleiro[1][2]);
    printf("\n      --|---|--");
    printf("\n     3 %c| %c |%c\n\n\n",tabuleiro[2][0],tabuleiro[2][1],tabuleiro[2][2]);
}

int jogada_usuario(int lin, int col, char jog) {
	if (tabuleiro[lin][col] == ' ' ){
		return 0;
	}
	if ((lin < 0) || (lin > 3) || (col < 0) || (col > 3)){
		return 1;
	}
	if (tabuleiro[lin][col] != ' ' ){
		return 2;
	}
}

void jogada_basica(char jogador) {
	int linha, coluna, erro = 1;
	do {
		srand(time(NULL));

		linha = rand()%3;
		coluna = rand()%3;
		if (tabuleiro[linha][coluna] == ' '){
			erro = 0;
			tabuleiro[linha][coluna] = jogador;
		} else {
			erro = 1;
		}
	} while (erro != 0);

}

void jogada_intermediaria(char jogador) {
	int linha, coluna, erro = 1, i, j, h = 0, jog=0;
	char humano;
	
	if (jogador == 'o') {
		humano = 'x';
	} else {
		humano = 'o';
	}
	
		
		if (primeira == 0 && jog==0) {
			primeira++;
			do {
				srand(time(NULL));

				linha = rand()%3;
				coluna = rand()%3;
				if (tabuleiro[linha][coluna] == ' '){
					erro = 0;
					tabuleiro[linha][coluna] = jogador;
					jog=1;
				} else {
					erro = 1;
				}
			} while (erro != 0);

		}
				
		//linha 0
		if (tabuleiro[0][0] == humano && tabuleiro[0][1] == ' ' && tabuleiro[0][2] == ' ' && jog==0) 
		{
			tabuleiro[0][2] = jogador;
			jog=1;
		}
		if (tabuleiro[0][1] == humano && tabuleiro[0][0] == ' ' && tabuleiro[0][2] == ' ' && jog==0) 
		{
			tabuleiro[0][0] = jogador;
			jog=1;
		}
		else
			{
				if (tabuleiro[0][2] == humano && tabuleiro[0][1] == ' ' && tabuleiro[0][0] == ' ') {
			tabuleiro[0][1] = jogador;	
			} 
		}

		else
			{
				if (tabuleiro[1][0] == humano && tabuleiro[1][1] == ' ' && tabuleiro[1][2] == ' ') {
			tabuleiro[1][2] = jogador;
			} 
		}
		else
			{
				if (tabuleiro[1][1] == humano && tabuleiro[1][0] == ' ' && tabuleiro[1][2] == ' ') {
			tabuleiro[1][0] = jogador;
			} 
		}
		else
			{
				if (tabuleiro[1][2] == humano && tabuleiro[1][1] == ' ' && tabuleiro[1][0] == ' ') {
			tabuleiro[1][1] = jogador;
			} 
		}

		else
			{
				if (tabuleiro[2][0] == humano && tabuleiro[2][1] == ' ' && tabuleiro[2][2] == ' ') {
			tabuleiro[2][2] = jogador;
			} 
		}
		else
			{
				if (tabuleiro[2][1] == humano && tabuleiro[2][0] == ' ' && tabuleiro[2][2] == ' ') {
			tabuleiro[2][0] = jogador;
			} 
		}
		else
			{

			} if (tabuleiro[2][2] == humano && tabuleiro[2][1] == ' ' && tabuleiro[2][0] == ' ') {
			tabuleiro[2][1] = jogador;
		}



		else
			{

			} if (tabuleiro[0][0] == humano && tabuleiro[0][1] == humano){
			tabuleiro[0][2] = jogador;
		}
		else
			{

			} if (tabuleiro[0][1] == humano && tabuleiro[0][2] == humano){
			tabuleiro[0][0] = jogador;
		}
		else
			{

			} if (tabuleiro[0][0] == humano && tabuleiro[0][2] == humano){
			tabuleiro[0][1] = jogador;
		}
		
		//linha 1
		else
			{

			} if (tabuleiro[1][0] == humano && tabuleiro[1][1] == humano){
			tabuleiro[1][2] = jogador;
		}
		else
			{

			} if (tabuleiro[1][1] == humano && tabuleiro[1][2] == humano){
			tabuleiro[1][0] = jogador;
		}
		else
			{

			} if (tabuleiro[1][0] == humano && tabuleiro[1][2] == humano){
			tabuleiro[1][1] = jogador;
		}
		
		//linha 2
		else
			{

			} if (tabuleiro[2][0] == humano && tabuleiro[2][1] == humano){
			tabuleiro[2][2] = jogador;
		}
		else
			{

			} if (tabuleiro[2][1] == humano && tabuleiro[2][2] == humano){
			tabuleiro[2][0] = jogador;
		}
		else
			{

			} if (tabuleiro[2][0] == humano && tabuleiro[2][2] == humano){
			tabuleiro[2][1] = jogador;
		}		
		}

	
	
				
		
		
}

void jogada_computador(char jog, int nivel) {
	if(nivel == 1) {
		jogada_basica(jog);
	}
	if(nivel == 2) {
		jogada_intermediaria(jog);
	}
}

int verifica_ganhador(char jog) {
	  if((tabuleiro[0][0]=='o' && tabuleiro[0][1]=='o' && tabuleiro[0][2]=='o')||
        (tabuleiro[1][0]=='o' && tabuleiro[1][1]=='o' && tabuleiro[1][2]=='o')||
        (tabuleiro[2][0]=='o' && tabuleiro[2][1]=='o' && tabuleiro[2][2]=='o')||
        (tabuleiro[0][0]=='o' && tabuleiro[1][0]=='o' && tabuleiro[2][0]=='o')||
        (tabuleiro[0][1]=='o' && tabuleiro[1][1]=='o' && tabuleiro[2][1]=='o')||
        (tabuleiro[0][2]=='o' && tabuleiro[1][2]=='o' && tabuleiro[2][2]=='o')||
        (tabuleiro[0][0]=='o' && tabuleiro[1][1]=='o' && tabuleiro[2][2]=='o')||
        (tabuleiro[0][2]=='o' && tabuleiro[1][1]=='o' && tabuleiro[2][0]=='o')) {
        	return 1;
        }
        if((tabuleiro[0][0]=='x' && tabuleiro[0][1]=='x' && tabuleiro[0][2]=='x')||
          (tabuleiro[1][0]=='x' && tabuleiro[1][1]=='x' && tabuleiro[1][2]=='x')||
          (tabuleiro[2][0]=='x' && tabuleiro[2][1]=='x' && tabuleiro[2][2]=='x')||
          (tabuleiro[0][0]=='x' && tabuleiro[1][0]=='x' && tabuleiro[2][0]=='x')||
          (tabuleiro[0][1]=='x' && tabuleiro[1][1]=='x' && tabuleiro[2][1]=='x')||
          (tabuleiro[0][2]=='x' && tabuleiro[1][2]=='x' && tabuleiro[2][2]=='x')||
          (tabuleiro[0][0]=='x' && tabuleiro[1][1]=='x' && tabuleiro[2][2]=='x')||
          (tabuleiro[0][2]=='x' && tabuleiro[1][1]=='x' && tabuleiro[2][0]=='x')) {
          	return 1;
        }
}
void jogo_ganho(char jog) {
	int continua;
	printf("\n\a\t\tJogador %c, VOCE VENCEU!!!", jog);
	printf("\nDeseja jogar mais uma?");
			printf("\n0 - Nao");
			printf("\n1 - Sim:\n");
			scanf("%d", &continua);
			if (continua == 1) {
				primeira--;
				main();
			} else {
				exit(0);
			}
}
void jogo_computador(nivel) {
	char jogador1, jogador2;
	int jogada, linha, coluna, valida, erro = 1, continua, verifica;
	
	system("cls");
	escolha_simb(&jogador1, &jogador2);
	system("cls");
	inicializa_velha();

	for(jogada=0;jogada<9;jogada++) {

		if(jogada % 2) {
			do {
				jogada_computador(jogador2, nivel);
				system("cls");
				mostra_velha();
				verifica = verifica_ganhador(jogador2);
				if (verifica == 1) {
					jogo_ganho(jogador2);
				}
				erro = 0;
				
			} while (erro != 0);
		}
	
		else {
				do {
				printf("\nJogador %c: Digite a linha: ", jogador1);
				scanf("%d", &linha);
				linha = linha -1;
				printf("\nJogador %c: Digite a coluna: ", jogador1);
				scanf("%d", &coluna);
				coluna = coluna -1;

				valida = jogada_usuario(linha, coluna, jogador1);
				if(valida == 0) {
					tabuleiro[linha][coluna] = jogador1;
					system("cls");
					mostra_velha();
					verifica = verifica_ganhador(jogador1);
					if (verifica == 1) {
						jogo_ganho(jogador1);

					}
					erro = 0;
				}
				if(valida == 1) {
					printf("\nOpcao invalida");
					erro = 1;
				}
				if(valida == 2) {
					printf("\nPosicao ja escolhida");
					erro = 1;
				}
			} while (erro != 0);
		}
		if(jogada == 8) {
			printf("\nDeu velha");
			printf("\nDeseja jogar mais uma?");
			printf("\n0 - Nao");
			printf("\n1 - Sim:");
			scanf("\n%d\n", &continua);
			if (continua == 1) {
				main();
			} else {
				exit(0);
			}
		}
	}

}
void main() {
	int escolha, nivel = 0, jogada, linha, coluna, valida, erro = 1, continua, verifica;
	char jogador1;
	char jogador2;

	system("cls");
	escolha = menu();
	system("cls");
	if (escolha == 1) {
		while ((nivel > 3) || (nivel < 1)) {
			printf("Escolha o nivel\n");
			printf("1 - Basico\n");
			printf("2 - Intermediario\n");
			printf("3 - Avancado\n");
			scanf("%d", &nivel);
		}
		jogo_computador(nivel);
	}
	system("cls");

	escolha_simb(&jogador1, &jogador2);
	system("cls");
	inicializa_velha();

	for(jogada=0;jogada<9;jogada++) {

		if(jogada % 2) {
			do {
				printf("\nJogador %c: Digite a linha: ", jogador2);
				scanf("%d", &linha);
				linha = linha - 1;
				printf("\nJogador %c: Digite a coluna: ", jogador2);
				scanf("%d", &coluna);
				coluna = coluna - 1;
				valida = jogada_usuario(linha, coluna, jogador2);

				if(valida == 0) {
					tabuleiro[linha][coluna] = jogador2;
					system("cls");
					mostra_velha();
					verifica = verifica_ganhador(jogador2);
					if (verifica == 1) {

						jogo_ganho(jogador2);
					}
					erro = 0;
				}
				if(valida == 1) {
					printf("\nOpcao invalida");
					erro = 1;
				}
				if(valida == 2) {
					printf("\nPosicao ja escolhida");
					erro = 1;
				}
			} while (erro != 0);

		}
		else {
				do {
				printf("\nJogador %c: Digite a linha: ", jogador1);
				scanf("%d", &linha);
				linha = linha -1;
				printf("\nJogador %c: Digite a coluna: ", jogador1);
				scanf("%d", &coluna);
				coluna = coluna -1;

				valida = jogada_usuario(linha, coluna, jogador1);
				if(valida == 0) {
					tabuleiro[linha][coluna] = jogador1;
					system("cls");
					mostra_velha();
					verifica = verifica_ganhador(jogador1);
					if (verifica == 1) {
						jogo_ganho(jogador1);

					}
					erro = 0;
				}
				if(valida == 1) {
					printf("\nOpcao invalida");
					erro = 1;
				}
				if(valida == 2) {
					printf("\nPosicao ja escolhida");
					erro = 1;
				}
			} while (erro != 0);
		}
		if(jogada == 8) {
			printf("\nDeu velha");
			printf("\nDeseja jogar mais uma?");
			printf("\n0 - Nao");
			printf("\n1 - Sim");
			scanf("\n%d", &continua);
			if (continua == 1) {
				main();
			} else {
				exit(0);
			}
		}
	}
}
