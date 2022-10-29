#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

void Kvad(float a, float b, float c)
{
	float discr, x1, x2;
	HANDLE Rez = CreateFile(L"./Rezultat.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD d;
	LPCSTR rezult = malloc(100);
	if ((a != 0) && (b != 0) && (c != 0))
	{
		discr = b * b - 4 * a * c;
		if (discr < 0)
		{
			sprintf(rezult, "дискриминант = %f Корней нет\n ", &discr);
			WriteFile(Rez, rezult, strlen(rezult), &d, NULL);
			CloseHandle(Rez);

		}
		else if (discr == 0)
		{
			x1 = -b / (2 * a);
			sprintf(rezult, "дискриминант = %f \n кол-во корней:1 \n x1: %f", &discr, &x1);
			WriteFile(Rez, rezult, strlen(rezult), &d, NULL);
			CloseHandle(Rez);
		}
		else if (discr > 0)
		{
			x1 = (-b + sqrt(discr)) / (2 * a);
			x2 = (-b - sqrt(discr)) / (2 * a);
			sprintf(rezult, "дискриминант = %f \n кол-во корней:2 \n x1: %f x2: %f", discr, x1, x2);
			WriteFile(Rez, rezult, strlen(rezult), &d, NULL);
			CloseHandle(Rez);
		}
	}
	else if ((c == 0) && (b == 0))
	{
		x1 = 0;
		sprintf(rezult, "Корень равен = %f", &x1);
		WriteFile(Rez, rezult, strlen(rezult), &d, NULL);
		CloseHandle(Rez);
	}
	else if (b == 0)
	{

		if (-c / a < 0)
		{
			sprintf(rezult, "Корней нет");
			WriteFile(Rez, rezult, strlen(rezult), &d, NULL);
			CloseHandle(Rez);
		}
		else
		{
			x1 = sqrt((-c / a));
			sprintf(rezult, "Корени равены = %f и -%f", &x1, &x1);
			WriteFile(Rez, rezult, strlen(rezult), &d, NULL);
			CloseHandle(Rez);
		}
	}
	else if (c == 0)
	{
		x1 = -b / a;
		x2 = 0;
		sprintf(rezult, "Корени равены = %f и %f", &x1, &x2);
		WriteFile(Rez, rezult, strlen(rezult), &d, NULL);
		CloseHandle(Rez);
	}
	else if (a == 0)
	{
		x1 = -c / b;
		sprintf(rezult, "Корень равен = %f", &x1);
		WriteFile(Rez, rezult, strlen(rezult), &d, NULL);
		CloseHandle(Rez);
		
	}

}

int main()
{
	system("chcp 1251>nul");
	DWORD d;
	HANDLE Start = CreateFile(L"./Start.txt", GENERIC_READ , 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	HANDLE Rez = CreateFile(L"./Rezultat.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	LPCSTR rezult = "";
	if (Start == INVALID_HANDLE_VALUE)   
	{
		rezult = "Ошибка КЛИЕНТА! - неудалось открыть файл";
		WriteFile(Rez, rezult, strlen(rezult), &d, NULL);
		CloseHandle(Start);
		return;
	}

	
	LPCSTR str = calloc(100, 1);
	
ReadFile(Start, str, 100, &d, NULL);
	double koeff[3];
	int i = 0;
	char* istr;
	istr = strtok(str, " ");
	if (ReadFile(Start, str, 100, &d, NULL) == NULL)
	{
		rezult = "Не удалось считать данные с файла";
		WriteFile(Rez, rezult, strlen(rezult), &d, NULL);
		CloseHandle(Rez);
	}
	else
	{
		while (istr!=NULL)
		{
			
			koeff[i] = atof(istr);
			istr = strtok(NULL, " ");
			i++;
			
			
		}
		if (i ==3)
		{
			if (koeff[0] == -92559631349317830736831783200707727132248687965119994463780864.000000 || koeff[1] == -92559631349317830736831783200707727132248687965119994463780864.000000 || koeff[2] == -92559631349317830736831783200707727132248687965119994463780864.000000)
			{
				rezult = "Не корректно введены данные";
				WriteFile(Rez, rezult, strlen(rezult), &d, NULL);
				CloseHandle(Rez);
			}
			if (koeff[0] == 0 || koeff[1] == 0 || koeff[2] == 0)
			{
				rezult = "Все введенные данные равны 0";
				WriteFile(Rez, rezult, strlen(rezult), &d, NULL);
				CloseHandle(Rez);
			}
			Kvad(koeff[0], koeff[1], koeff[2]);
		}
		else
		{
			rezult = "Количество введенных данных не равно 3";
			WriteFile(Rez, rezult, strlen(rezult), &d, NULL);
			CloseHandle(Rez);
		}
	}
}