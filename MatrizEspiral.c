#include <stdio.h>
#include <stdlib.h>

int main () 
{
	int n;
	
	printf("Insira o tamanho (n) para a matriz: ");
	scanf("%d", &n);
	
	int i, j, k, l;
    int number = 1;
	int length = n * n;
	
    int matrix[n][n];

    i = 0;
    j = 0; 
    k = 0;
    l = 0;
	
	//preencher a espiral
    while(number <= length)
    {
        while(j < n - k)//j == 0 -> n - 1; 
        {
            matrix[i][j] = number;
            number++;
            j++;
        }
        j--;//j == 4;
        i++;//i == 2;
        while(i < n - k)//i == 1 -> n - 1;
        {
            matrix[i][j] = number;
            number++;
            i++;
        }
        i--;//i == 4;
        j--;//j == 3;
        while(j > l - 1)
        {
            matrix[i][j] = number;
            number++;
            j--;
        }
        j++;//j == 0;
        i--;//i == 3;
        l++;
        while(i > l - 1)
        {
            matrix[i][j] = number;
            number++;
            i--;
        }
        i++;//i == 1;
        j++;//j == 1;
        k++;
        
    };
    
    //printf
    for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(j == 0)
			{
				printf("| ");
			}
			
			printf("%d ", matrix[i][j]);
			
			if(j == n - 1)
			{
				printf("|\n");
			}
		}
	}
	
	return 0;
}