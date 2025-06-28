#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculoaprovacao(int conferematricula, int listamatriculas[], float listanotas[], int tamanho)
{
	int a, i, indice;
	indice = -1;
	
	for(i = 0; i < tamanho; i++)
	{
		if(conferematricula == listamatriculas[i])
		{
			indice = i;
			break;
		}
	}
	if(indice == -1)
	{
		a = -1;
	}
	if(listanotas[indice] >= 5.00)
	{
		a = 1;
	}
	else 
	{
		a = 0;
	}
	return a;
}
float calculomedia (float notas[], int tamanho) 
{
	int i;
	float m;
	float soma = 0;
	for(i = 0; i < tamanho; i++)
	{
		soma = soma + notas[i];
	}
	m = soma / 10;
	return m;
}
////////////////////////////////////////////////////////////////////////////////////
int main () 
{
	float media, tempnota; 
	int a, i, j, k, matricula, aprovacao, conferematricula, tempmat;
    int encontrado = 0;
    char tempnome[15];
    
    //////
    float notas2[10];
    float notas[10] = 
	{
		4.5, 8.7, 6.9, 5.0, 3.4, 
		4.9, 7.3, 7.8, 4.8, 5.8
	};
	int matriculas2[10];
    int matriculas[10] = 
	{
		74, 111, 12, 65, 67, 
		143, 3, 99, 44, 101
	};
	
	char alunos2[10][50];
	char alunos[10][50] = 
	{
        "Alice", "Bruno", "Carla", "Daniel", "Eduarda",
        "Fernando", "Gabriela", "Hugo", "Isabela", "Joao"
    };
    
    //copia vetor
	for(i = 0; i < 10; i++)
	{
		notas2[i] = notas[i];
		matriculas2[i] = matriculas[i];
		strcpy(alunos2[i], alunos[i]);
	}
    ///////
    
	int contador = 1;
	while (contador == 1) 
	{
		printf("Lista de alunos por matricula: \n");
		
		for(i = 0; i < 10; i++)
		{
			printf("ALUNO(A): %s || MATRICULA: %d\n", alunos[i], matriculas[i]);
		}
		printf("--------------------------------\n");
		
		printf("Digite qual acao deseja: \n");
		printf("[0] SAIR\n");
		printf("[1] MEDIA\n");
		printf("[2] NOTA FINAL DO ALUNO\n");
		printf("[3] ORDEM DECRESCENTE DE NOTAS\n");
		printf("[4] APROVACAO OU NAO DE ALUNO\n");
		printf("[5] MAIOR NOTA E QUEM TIROU\n");
		printf("[6] MENOR NOTA E QUEM TIROU\n");
		
		printf("Opcao: ");
		scanf("%d", &a);
		printf("\n");
		
		//2 - media
		media = calculomedia(notas, 10);
		
		
		
		switch(a)
		{
			case 0: {
				printf("Fim do programa!");
				return 0;
			}
			case 1: {
				printf("MEDIA : %.2f", media);
				break;
			}
			case 2: {
				printf("Digite a matricula do aluno: ");
				scanf("%d", &matricula);
				printf("\n");
				
				for(i = 0; i < 10; i++)
	            {
	                if(matriculas[i] == matricula)
	                {
	                    printf("Aluno(a): %s (%d)|| Nota: %.2f", alunos[i], matriculas[i], notas[i]);
	                    printf("\n");
	                    encontrado = 1;
	                }
	            }
	            if(encontrado == 0)
	            {
	                printf("Ops, Matricula nao encontrada!!\n");
	            }
	            encontrado = 0;
				break;
			}
			case 3: {
				printf("Notas em ordem decrescente:\n");
				for(j = 9; j > 0; j--)
				{
					for(i = 0; i < j; i++)
					{
						if(notas2[i] < notas2[i + 1])
						{
							//troca notas
							tempnota = notas2[i];
							notas2[i] = notas2[i + 1];
							notas2[i + 1] = tempnota;
							
							//troca nomes
							strcpy(tempnome, alunos2[i]);
							strcpy(alunos2[i], alunos2[i + 1]);
							strcpy(alunos2[i + 1], tempnome);
							
							//troca matriculas
							tempmat = matriculas2[i];
							matriculas2[i] = matriculas2[i + 1];
							matriculas2[i + 1] = tempmat;
						}
					}
				}
				for(i = 0; i < 10; i++)
				{
					printf("%s(%d) : %.2f\n", alunos2[i], matriculas2[i], notas2[i]);
				}
				break;
			}
			case 4: {
				printf("Insira a matricula: ");
				scanf("%d", &conferematricula);
				for(i = 0; i < 10; i++)
				{
					if(conferematricula == matriculas[i])
					{
						k = i;
					}
				}
				
				aprovacao = calculoaprovacao(conferematricula, matriculas, notas, 10);
				if(aprovacao == -1)
				{
					printf("Matricula NAO encontrada...\n");
				}
				else if(aprovacao == 1) 
				{
					printf("Aluno(a) %s (%d), ESTA aprovado", alunos[k], conferematricula);
				}
				else if(aprovacao == 0)
				{
					printf("Aluno(A) %s (%d), NAO esta aprovado", alunos[k], conferematricula);
				}
				break;
			}
			case 5: {
				for(j = 9; j > 0; j--)
				{
					for(i = 0; i < j; i++)
					{
						if(notas2[i] < notas2[i + 1])
						{
							tempnota = notas2[i];
							notas2[i] = notas2[i + 1];
							notas2[i + 1] = tempnota;
						}
					}
				}
				for(i = 0; i < 10; i++)
				{
					if(notas2[0] == notas[i])
					{
						printf("Maior nota: %.2f || Aluno: %s (%d)", notas2[0], alunos[i], matriculas[i]);
					}
				}
				break;
			}
			case 6: 
			{
				for(j = 9; j > 0; j--)
				{
					for(i = 0; i < j; i++)
					{
						if(notas2[i] < notas2[i + 1])
						{
							tempnota = notas2[i];
							notas2[i] = notas2[i + 1];
							notas2[i + 1] = tempnota;
						}
					}
				}
				for(i = 0; i < 10; i++)
				{
					if(notas2[9] == notas[i])
					{
						printf("Menor nota: %.2f || Aluno: %s (%d)", notas2[9], alunos[i], matriculas[i]);
					}
				}
				break;
			}
			default: {
				printf("Opcao invalida!!");
				return 0;
			}
		}
		
		printf("\n");
		printf("Deseja fazer outra operacao? [1] continuar / [0]sair : ");
		scanf("%d", &contador);
	}
	
	printf("\n");
	printf("Acabou.....Obrigado!");
	
	return 0;
}
