#include <stdio.h>
#include <stdlib.h>

int verificaVitoria(int matriz[3][3]) 
{
	int i, j;
    // Verifica linhas
    for (i = 0; i < 3; i++) {
        if (matriz[i][0] != 0 &&
            matriz[i][0] == matriz[i][1] &&
            matriz[i][1] == matriz[i][2]) {
            return matriz[i][0];
        }
    }

    // Verifica colunas
    for (j = 0; j < 3; j++) {
        if (matriz[0][j] != 0 &&
            matriz[0][j] == matriz[1][j] &&
            matriz[1][j] == matriz[2][j]) {
            return matriz[0][j];
        }
    }

    // Diagonal principal
    if (matriz[0][0] != 0 &&
        matriz[0][0] == matriz[1][1] &&
        matriz[1][1] == matriz[2][2]) {
        return matriz[0][0];
    }

    // Diagonal secundária
    if (matriz[0][2] != 0 &&
        matriz[0][2] == matriz[1][1] &&
        matriz[1][1] == matriz[2][0]) {
        return matriz[0][2];
    }

    return 0; // ninguém venceu
}

int main () 
{
	int i, j, contador, posicao, px, po, resultado, achou;
	contador = 0;
	achou = 0;

	char matriz1[3][3] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	int matriz2[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	printf("  TIC TAC TOE\n");
	printf("-----------------\n");
	
	printf("Posicoes de jogo\n");
	printf(" 1 | 2 | 3 \n 4 | 5 | 6 \n 7 | 8 | 9 \n");
	
	while(contador != 10) 
	{
		//posicao do x
		printf("Insira a posicao para [x] : ");
		scanf("%d", &px);

		posicao = 1;
		for(i = 0; i < 3; i++)
		{
			if(achou == 1)
			{
				break;
			}
			for(j = 0; j < 3; j++)
			{
				if(posicao == px)
				{
					matriz1[i][j] = 'x';
					matriz2[i][j] = 1;
					achou = 1;
					break;
				}
				posicao++;
			}
		}

		contador++;
		posicao = 0;
		achou = 0;
		if(contador == 9)
		{
			break;
		}

		//printa a matriz dps do x
		for(i = 0; i < 3; i++)
		{
			for(j = 0; j < 3; j++)
			{
				if(j == 0)
				{
					printf("| ");
				}
				printf("%c ", matriz1[i][j]);
				if(j == 2)
				{
					printf("|\n");
				}
			}
		}

		//testa vitoria de x 
		resultado = verificaVitoria(matriz2);
		if(resultado == 1)
		{
			printf("\n");
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					if(j == 0)
					{
						printf("| ");
					}
					printf("%c ", matriz1[i][j]);
					if(j == 2)
					{
						printf("|\n");
					}
				}
			}
			printf("Jogador [x] venceu!!\n");
			contador = 10;
			break;
		}

		//posicao da bolinha
		printf("Insira a posicao para [o] : ");
		scanf("%d", &po);
	
		posicao = 1;
		for(i = 0; i < 3; i++)
		{
			if(achou == 1)
			{
				break;
			}
			for(j = 0; j < 3; j++)
			{
				if(posicao == po)
				{
					matriz1[i][j] = 'o';
					matriz2[i][j] = 2;
					achou = 1;
					break;
				}
				posicao++;
			}
		}

		//printa a matriz dps da bolinha
		for(i = 0; i < 3; i++)
		{
			for(j = 0; j < 3; j++)
			{
				if(j == 0)
				{
					printf("| ");
				}
				printf("%c ", matriz1[i][j]);
				if(j == 2)
				{
					printf("|\n");
				}
			}
		}
		contador++;
		achou = 0;

		//testa vitoria de o
		resultado = verificaVitoria(matriz2);
		if(resultado == 2)
		{
			printf("\n");
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					if(j == 0)
					{
						printf("| ");
					}
					printf("%c ", matriz1[i][j]);
					if(j == 2)
					{
						printf("|\n");
					}
				}
			}
			printf("Jogador [o] venceu!!\n");
			contador = 10;
			break;
		}
	}
	
	//Empate
	if(verificaVitoria(matriz2) == 0)
	{
		printf("\n");
		for(i = 0; i < 3; i++)
		{
			for(j = 0; j < 3; j++)
			{
				if(j == 0)
				{
					printf("| ");
				}
				printf("%c ", matriz1[i][j]);
				if(j == 2)
				{
					printf("|\n");
				}
			}
		}
		printf("Empate!!\n");
	}	
	
	return 0;
}