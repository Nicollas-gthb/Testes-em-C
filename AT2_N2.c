#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AULAS 32

struct Aluno
{
    char nome[50];
    char ra[6];
    float nota[3];
    int faltas;
    float media;
    float frequencia;
	char var[50];
};

float calcularMedia(float notas[]) 
{
    return (notas[0]*2 + notas[1]*3 + notas[2]*5) / 10.0;
}

float calcularFrequencia(int faltas)
{
    return ((AULAS - faltas) / (float)AULAS) * 100;
}

int main()
{

	float temp;
	
    int i,j,k;
    float soma[3];
    struct Aluno aluno[10] = 
	{
        {"Alice Lima", "00745", {5.50, 6.60, 4.00}, 8},
        {"Bruno Souza", "01267", {7.80, 8.00, 3.50}, 12},
        {"Carlos Viana", "00084", {9.00, 9.50, 8.75}, 24},
        {"Danilo Alvim", "00267", {6.50, 3.00, 2.55}, 6},
        {"Emerson Silva", "00107", {5.00, 4.35, 4.00}, 19},
        {"Fernanda Guedes", "00942", {7.50, 4.00, 2.50}, 0},
        {"Gustavo Amorim", "01103", {7.55, 7.00, 4.00}, 5},
        {"Hilda Freitas", "01006", {9.00, 9.00, 6.75}, 7},
        {"Ivo Carvalho", "00351", {5.00, 5.00, 5.00}, 6},
        {"Jorge Garcia", "00433", {4.00, 3.75, 4.85}, 0}
    };
    
    for( i = 0; i < 10; i++)
	{
        aluno[i].media = calcularMedia(aluno[i].nota);
        aluno[i].frequencia = calcularFrequencia(aluno[i].faltas);
    }

    printf("Seja bem-vindo ao site da universidade Catolica de Brasilia!\n");

    while(1)
	{
        printf("O que deseja acessar? \n");
        printf("0 - sair \n");
        printf("1- Alunos que farao a prova final \n"); 
        printf("2- Media da turma nas provas\n");
        printf("3- Media final de todos os alunos e situacao\n");

        scanf("%d", &k);

        if(k>= 0 && k <= 3)
		{
            switch(k)
			{
                case 0: 
                printf("Obrigado por acessar! \n"); 
                printf("Saindo...\n");
                return 0;

                case 1: 
                for(i = 0; i < 10; i++)
				{          
	                if(aluno[i].media < 5 && aluno[i].frequencia >= 65.0)
					{         
	                    printf("%s (RA: %s) - Media: %.2f - Frequencia: %.2f%% - VAI FAZER A PROVA FINAL\n",
	                    aluno[i].nome, aluno[i].ra, aluno[i].media, aluno[i].frequencia);
	                }
            	}
                printf("\n");
                break;

                case 2: 
				{   
	                soma[0] = soma[1] = soma[2] = 0;
	                
	                for( i = 0; i < 10; i++)
					{
	                    for( j= 0; j < 3; j++)
						{
	                        soma[j] += aluno[i].nota[j];
	                    }
	                }
	                printf("Media da turma nas provas... \n");
	                for( i = 0; i < 3; i++)
					{
	                    printf("Prova %d: %.2f \n", (i+1), (soma[i]/10));
	                }
	                break;
                }
            
                case 3: 
				
				for(j = 9;j>0;j--)
				{
					for(i = 0; i <j ; i++)
					{
						if(aluno[i].media < aluno[i+1].media)
						{
							temp = aluno[i].media;
							aluno[i].media = aluno[i+1].media;
							aluno[i+1].media = temp;
							strcpy(aluno[i].var,aluno[i].nome);
							strcpy(aluno[i].nome,aluno[i+1].nome);
							strcpy(aluno[i+1].nome,aluno[i].var);
						}
					}
				}
			
                for( i = 0; i < 10; i++)
				{
	                printf("%s - Media final: %.2f - Situacao: ", aluno[i].nome, aluno[i].media);
	                if(aluno[i].media >= 5)
					{
	                    printf("APROVADO\n");
	                } 
					else
					{
	                    printf("REPROVADO\n");
	                }
            	} 
	            printf("\n");
	            break;
	
	        }
        }
		else
		{
            printf("Entrada invalida\n");
		}
	}
}