#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/////                 funcao 1 parte 1
int calculo1 (int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int n11) 
{
	int s, resto1, d1;
	s = 0;
	s = s + (n1 * 10);
	s = s + (n2 * 9);
	s = s + (n3 * 8);
	s = s + (n4 * 7);
	s = s + (n5 * 6);
	s = s + (n6 * 5);
	s = s + (n7 * 4);
	s = s + (n8 * 3);
	s = s + (n9 * 2);
	
	resto1 = s % 11;
	if (resto1 < 2) 
	{
		d1 = 0;
	} 
	else 
	{
		d1 = (11 - resto1);
	}
	return d1;
}
/////                funcao 2 parte 1
int calculo2 (int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int n11) 
{
	int t, resto2, d2;
	t = 0;
	t = t + (n1 * 11);
	t = t + (n2 * 10);
	t = t + (n3 * 9);
	t = t + (n4 * 8);
	t = t + (n5 * 7);
	t = t + (n6 * 6);
	t = t + (n7 * 5);
	t = t + (n8 * 4);
	t = t + (n9 * 3);
	t = t + (n10 * 2);
	
	resto2 = t % 11;
	if (resto2 < 2) 
	{
		d2 = 0;
	} 
	else 
	{
		d2 = (11 - resto2);
	}
	return d2;
}
//////                 funcao 1 parte 2
int gerador1 (int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9) 
{
	int s, resto1, d1;
	s = 0;
	s = s + (n1 * 10);
	s = s + (n2 * 9);
	s = s + (n3 * 8);
	s = s + (n4 * 7);
	s = s + (n5 * 6);
	s = s + (n6 * 5);
	s = s + (n7 * 4);
	s = s + (n8 * 3);
	s = s + (n9 * 2);
	
	resto1 = s % 11;
	if (resto1 < 2) 
	{
		d1 = 0;
	} 
	else 
	{
		d1 = (11 - resto1);
	}
	return d1;
}
///////               funcao 2 parte 2
int gerador2 (int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int g1) 
{
	int t, resto2, d2;
	t = 0;
	t = t + (n1 * 11);
	t = t + (n2 * 10);
	t = t + (n3 * 9);
	t = t + (n4 * 8);
	t = t + (n5 * 7);
	t = t + (n6 * 6);
	t = t + (n7 * 5);
	t = t + (n8 * 4);
	t = t + (n9 * 3);
	t = t + (g1 * 2);
	
	resto2 = t % 11;
	if (resto2 < 2) 
	{
		d2 = 0;
	} 
	else 
	{
		d2 = (11 - resto2);
	}
	return d2;
}
//////////    INT MAIN     /////////
int main () 
{
	int e, i, n, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;
	int verificador1, verificador2, g1, g2;
	printf("TESTANDO");
	printf("Digite [1] para Verificar CPF \n");
	printf("Digite [2] para Gerar CPF \n");
	scanf("%d", &e);
	
	if(e == 1) 
	{
		///////////////////     parte 1
		printf("=========================================\n");
		printf("           Verificador de CPF \n");
		printf("=========================================\n");
		printf("       Digite cada digito do CPF: \n");
		printf("-----------------------------------------\n");
		for (i = 1; i <= 11; i++) 
		{
			printf("%do:", i);
			scanf("%d", &n);
			
			switch(i) 
			{
				case 1: n1 = n; break;
				case 2: n2 = n; break;
				case 3: n3 = n; break;
				case 4: n4 = n; break;
				case 5: n5 = n; break;
				case 6: n6 = n; break;
				case 7: n7 = n; break;
				case 8: n8 = n; break;
				case 9: n9 = n; break;
				case 10: n10 = n; break;
				case 11: n11 = n; break;
			}
		}
		printf("-----------------------------------------\n");
		verificador1 = calculo1(n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
		verificador2 = calculo2(n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
		if ((verificador1 != n10) || (verificador2 != n11)) 
		{
			printf("  !! CPF [%d%d%d.%d%d%d.%d%d%d-%d%d] INVALIDO !! \n", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
		} 
		else 
		{
		printf("  ! CPF [%d%d%d.%d%d%d.%d%d%d-%d%d] VALIDADO ! \n", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
		}
		printf("-----------------------------------------\n");
	} 
	else if (e == 2) 
	{
		//////////////    parte 2
		printf("=========================================\n");
		printf("           Gerador de CPF \n");
		printf("=========================================\n");
		printf("       Digite cada digito do CPF: \n");
		printf("-----------------------------------------\n");
		for (i = 1; i <= 9; i++) 
		{
			printf("%do:", i);
			scanf("%d", &n);
			
			switch(i) 
			{
				case 1: n1 = n;
				case 2: n2 = n;
				case 3: n3 = n;
				case 4: n4 = n;
				case 5: n5 = n;
				case 6: n6 = n;
				case 7: n7 = n;
				case 8: n8 = n;
				case 9: n9 = n;
			}
		}
		printf("-----------------------------------------\n");
		g1 = gerador1(n1, n2, n3, n4, n5, n6, n7, n8, n9);
		g2 = gerador2(n1, n2, n3, n4, n5, n6, n7, n8, n9, g1);
		printf("  ! CPF gerado [%d%d%d.%d%d%d.%d%d%d-%d%d] ! \n", n1, n2, n3, n4, n5, n6, n7, n8, n9, g1, g2);
		printf("-----------------------------------------\n");
	}
	return 0;
}
