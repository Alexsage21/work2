#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <math.h>

void Z1()
{
	printf("%20s\n", "��� �����");
	printf("%-20s\n", "��� �����");
	printf("%-20s\n", "\t��� �����");
	printf("%10.3f\n ", 12.234657);
	printf("%10.5f\n ", 12.234657);
	printf("������� �� ������� %d �� %d ����� %d\n ", 5, 2, 5 % 2);
	printf("������� �� ������� %d �� %d ����� %d\n ", 7, 5, 7 % 5);
	printf("��������� %d �� %d ����� %d\n ", 2000, 4, 2000 * 4);
	printf("%g ��������� %e ����� %f\n ", 5., 2., 5. / 2);
	printf("%d ��������� %d ����� %d\n ", 5., 2., 5. / 2); //��� ��� ����� ����� ����� ���� �����, ��������������� ��� ��� ��� float(�� �����), � �� ������� ������� ��� int, ��-�� ���� ��������� ��� �� �������� � ������� ����.
	printf("%f ��������� %f ����� %f\n ", 5., 2., 5. / 2); //��� ����� ��������� ��� ����� � ��������� �������.
	printf("%g ��������� %g ����� %g\n ", 5., 2., 5. / 2); //��������� ������� ����� ���, ��� ������� ������(����� - ������, ������� - ��������)
	printf("%e ��������� %e ����� %e\n\n", 5., 2., 5. / 2); //������� ���������� ����� � ���� x.xx e+xx
}

void Z2()
{
	int N, K;
	scanf("%d", &N);
	scanf("%d", &K);
	printf("\n������ %d ����� %d ����� 00 ������\n", N, K);
	printf("��� %d ������ �����\n", N * 60 + K + 1);
	printf("�� �������� �������� %d ����� � %d �����\n", 23 - N, 60 - K);
	printf("� 8.00 ������ %d ������\n", (N * 60 + K) * 60 - (8 * 3600));
	printf("������� ��� = %1.3f ����� � ������� ������ = %1.3f ����\n\n", (float)N / 24, (float)K / 60);
}

void Z3()
{
	int N, D, K, M;
	char* str;
	char* strc;
	scanf("%d", &N);
	scanf("%d", &D);
	scanf("%d", &K);
	scanf("%d", &M);
	float r = ((float)N / D);
	int rn = (N / D);
	int c = (N / D);
	int cc = c;
	int drch = (r - rn) * pow(10, M);
	int cdrch = drch;
	int n = 0;
	int n2 = 0;

	while (cdrch > 0)
	{
		cdrch /= 10;
		n++;
	}

	while (cc > 0)
	{
		cc /= 10;
		n2++;
	}

	str = (int*)malloc(M * sizeof(int));

	snprintf(str, sizeof str, "%d", drch);

	strc = (int*)malloc(K * sizeof(int));

	snprintf(strc, sizeof strc, "%d", c);

	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		str[i + (M - n)] = str[i];
	}

	for (int i = 0; i < (M - n); i++)
	{
		str[i] = '0';
	}

	for (int i = strlen(strc) - 1; i >= 0; i--)
	{
		strc[i + (K - n2)] = strc[i];
	}

	for (int i = 0; i < (K - n2); i++)
	{
		strc[i] = '0';
	}

	str[M] = 0;
	strc[K] = 0;

	printf("\n����:\n \t%d\n \t%d\n \t_______\n�����:\n \t%s.%s", N, D, strc, str);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	Z1();
	Z2();
	Z3();
	getchar();
}