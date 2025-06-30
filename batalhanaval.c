#include <stdio.h>
#include <stdlib.h>

int verificavitoria(int matriz[10][10])
{
    int i, j;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(matriz[i][j] == 1)
            {
                //se ainda tiver navio(1), retorna 0
                return 0; //0 == ainda não ganhou
            }
        }
    }
    //caso contrario, retorna 1
    return 1; //1 == vitoria
}
int main () 
{
    int i, j, linha, coluna;
    int tentativa = 0;
    int venceu = 0;

    int matrizinfo[10][10] = 
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        //17 navios
    };

    char matrizvisual[10][10] = 
    {
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    };

    printf("=== Batalha Naval ===\n");
    printf("Digite as coordenadas entre 0 e 9.\n");

    while(!venceu)
    {
        //printa o tabuleiro atual
        printf("          Tabuleiro\n");
        for(i = 0; i < 10; i++)
        {
            for(j = 0; j < 10; j++)
            {
                if(j == 0)
                {
                    printf("|");
                }
                printf(" %c ", matrizvisual[i][j]);
                if(j == 9)
                {
                    printf(" |\n");
                }
            }
        }
        printf("\n");

        //escolha da coordenada para atirar
        printf("=======================================\n\n");
        
        printf("Linha: ");
        scanf("%d", &linha);
        printf("\n");

        printf("Coluna: ");
        scanf("%d", &coluna);
        printf("\n");

        if(linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10)
        {
            //se acertar no barco(1), usando as corodenadas [linha][coluna] 
            //na matriz info, 
            //marca um 'X' nas mesmas coordenadas da matrizvisual[linha][coluna]
            if(matrizinfo[linha][coluna] == 1)
            {
                printf("Acertou um NAVIO!!\n");
                matrizvisual[linha][coluna] = 'X';//insere um "X" no tabuleiro
                matrizinfo[linha][coluna] = 0; //remove o navio
            }
            else if(matrizvisual[linha][coluna] == '~')
            {
                printf("Opa, caiu na AGUA...\n");
                matrizvisual[linha][coluna] = 'O';//insere um "O" no tabuleiro
            }
            else
            {
                printf("Voce ja atirou aqui, amigao.\n");
            }

            tentativa++;
            venceu = verificavitoria(matrizinfo);
        }
        else
        {
            printf("Coordenada invalida!\n");
        }
    }

    //final do jogo caso o venceu for == 1
    printf("  =-=-=-=-= PARABENS =-=-=-=-=\n");
    printf("Todos os navios foram afundados!\n\n");
    printf("Tentativas : %d\n\n", tentativa);

    printf("Tabuleiro Final : \n");
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(j == 0)
            {
                printf("|");
            }
            printf(" %c ", matrizvisual[i][j]);
            if(j == 9)
            {
                printf(" |\n");
            }
        }
    }
    return 0;
}