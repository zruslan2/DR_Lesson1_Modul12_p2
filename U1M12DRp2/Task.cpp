#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "MyFuncr.h"

int nz;

void main()
{
	FILE *file;
	setlocale(LC_ALL, "Ru");
	system("chcp 1251");
	srand(time(NULL));
	while (true)
	{
		printf("������� ����� �������, 0 - ��� ������ "); scanf("%d", &nz);
		if (nz == 0)
		{
			break;
			system("exit");
		}
		else if (nz == 1)
		{
			/*9. � ������������ �������������� �����, ���������� �������� �������� 
			��������� �����, �������� �� �������� �����
				a.s - � �����
				b.��������� �����*/
			system("cls");
			char arr[80];
			char sim;
			if ((file = fopen("text.txt", "r")) == NULL)perror("������ �������� �����: ");
			else
			{
				while (!feof(file))
				{			
					fscanf(file, "%s", arr);
					printf("%s", arr);
					sim = fgetc(file);	
					if(sim!='�')
					printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");			
			
			char wordR[20];			
			green();
			printf("a.\n");
			int s,sch=0;
			printf("������� ����� ����� ������� ���� �������� "); scanf("%d", &s);
			printf("������� ����� �� ������� ���� �������� "); scanf("%s", &wordR);
			white();
			if ((file = fopen("text.txt", "r")) == NULL)perror("������ �������� �����: ");
			else
			{
				while (!feof(file))
				{
					fscanf(file, "%s", arr);
					sch++;
					if (sch == s)					
						printf("%s", wordR);					
					else
				    	printf("%s", arr);
					sim = fgetc(file);		
					if (sim != '�')
					printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");
			green();
			printf("b.\n");
			s=27, sch = 0;			
			printf("������� ����� �� ������� ���� �������� ��������� ����� "); scanf("%s", &wordR);
			white();
			if ((file = fopen("text.txt", "r")) == NULL)perror("������ �������� �����: ");
			else
			{
				while (!feof(file))
				{
					fscanf(file, "%s", arr);
					sch++;
					if (sch == s)
						printf("%s", wordR);
					else
						printf("%s", arr);
					sim = fgetc(file);
					if (sim != '�')
					printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");
		}
		else if (nz == 2)
		{
			/*10.	���������� ��������������� ����� �������� ��������� �����.�������� ��� ��� 
			�������� �� ������ �����(�� �������� �������� � ����������).*/
			system("cls");
			char arr[80];
			char sim;
			if ((file = fopen("text.txt", "r")) == NULL)perror("������ �������� �����: ");
			else
			{
				while (!feof(file))
				{
					fscanf(file, "%s", arr);
					printf("%s", arr);
					sim = fgetc(file);
					if (sim != '�')
						printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");
			char word[20];
			char wordR[20];			
			int ln;
			green();
			printf("������� ����� ������� ���� �������� "); scanf("%s", &word);
			printf("������� ����� �� ������� ���� �������� "); scanf("%s", &wordR);
			white();
			if ((file = fopen("text.txt", "r")) == NULL)perror("������ �������� �����: ");
			else
			{
				while (!feof(file))
				{
					fscanf(file, "%s", arr);
					ln = strlen(arr);
					
					if (strcmp(arr, word) == 0)					
						printf("%s", wordR);					
					else
						printf("%s", arr);			
						
					sim = fgetc(file);
					if (sim != '�')
						printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");
		}
		else if (nz == 3)
		{
			/*11.	������� �������������� ����, ���������� �������� �������� ��������� �����, 
			������������ ������������������ ���������. �������� ����� ����, � ������� ����� ����� 
			��������� ����� ����������� ���������*/
			char *simb;
			int i = 1;
			simb = (char*)malloc(i * sizeof(char));
			simb[0] = '\0';
			if ((file = fopen("1.txt", "r")) == NULL)perror("������ �������� �����: ");
			else
			{
				while (!feof(file))
				{
					simb[i - 1] = fgetc(file);
					i++;
					simb = (char*)realloc(simb, i * sizeof(char));
				}
			}
			fclose(file);
			simb[i - 2] = '\0';
			char t;
			t = simb[0];
			simb[0] = simb[2];
			simb[2] = t;			
			printf("\n%s\n", simb);			
			if ((file = fopen("2.txt", "w")) == NULL)perror("������ �������� �����: ");
			else
			{
				fprintf(file, "%s", simb);
			}
			fclose(file);
		}
		else
		{
			red();
			printf("������ ������� �� ���������� \n");
			white();
		}
	}
}