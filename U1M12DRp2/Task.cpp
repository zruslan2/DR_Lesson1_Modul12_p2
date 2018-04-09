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
		printf("Введите номер задания, 0 - для выхода "); scanf("%d", &nz);
		if (nz == 0)
		{
			break;
			system("exit");
		}
		else if (nz == 1)
		{
			/*9. В существующем типизированном файле, элементами которого являются 
			отдельные слова, изменить на заданное слово
				a.s - е слово
				b.последнее слово*/
			system("cls");
			char arr[80];
			char sim;
			if ((file = fopen("text.txt", "r")) == NULL)perror("Ошибка открытия файла: ");
			else
			{
				while (!feof(file))
				{			
					fscanf(file, "%s", arr);
					printf("%s", arr);
					sim = fgetc(file);	
					if(sim!='я')
					printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");			
			
			char wordR[20];			
			green();
			printf("a.\n");
			int s,sch=0;
			printf("Введите номер слова которое надо заменить "); scanf("%d", &s);
			printf("Введите слово на которое надо заменить "); scanf("%s", &wordR);
			white();
			if ((file = fopen("text.txt", "r")) == NULL)perror("Ошибка открытия файла: ");
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
					if (sim != 'я')
					printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");
			green();
			printf("b.\n");
			s=27, sch = 0;			
			printf("Введите слово на которое надо заменить последнее слово "); scanf("%s", &wordR);
			white();
			if ((file = fopen("text.txt", "r")) == NULL)perror("Ошибка открытия файла: ");
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
					if (sim != 'я')
					printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");
		}
		else if (nz == 2)
		{
			/*10.	Элементами типизированного файла являются отдельные слова.Изменить все его 
			элементы на другие слова(их значения вводятся с клавиатуры).*/
			system("cls");
			char arr[80];
			char sim;
			if ((file = fopen("text.txt", "r")) == NULL)perror("Ошибка открытия файла: ");
			else
			{
				while (!feof(file))
				{
					fscanf(file, "%s", arr);
					printf("%s", arr);
					sim = fgetc(file);
					if (sim != 'я')
						printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");
			char word[20];
			char wordR[20];			
			int ln;
			green();
			printf("Введите слово которое надо заменить "); scanf("%s", &word);
			printf("Введите слово на которое надо заменить "); scanf("%s", &wordR);
			white();
			if ((file = fopen("text.txt", "r")) == NULL)perror("Ошибка открытия файла: ");
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
					if (sim != 'я')
						printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");
		}
		else if (nz == 3)
		{
			/*11.	Имеется типизированный файл, элементами которого являются отдельные буквы, 
			составляющие последовательность орпцессор. Получить новый файл, в котором буквы слова 
			процессор будут расположены правильно*/
			char *simb;
			int i = 1;
			simb = (char*)malloc(i * sizeof(char));
			simb[0] = '\0';
			if ((file = fopen("1.txt", "r")) == NULL)perror("Ошибка открытия файла: ");
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
			if ((file = fopen("2.txt", "w")) == NULL)perror("Ошибка открытия файла: ");
			else
			{
				fprintf(file, "%s", simb);
			}
			fclose(file);
		}
		else
		{
			red();
			printf("Такого задания не существует \n");
			white();
		}
	}
}