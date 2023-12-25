#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <windows.h>


void zast() {
	printf("\n\n\t\t\t\t---------------------------------------------------------- \n ");
	printf("\t\t\t\t| �������� ������ �������� ������ 22���1 ������� ������� | \n ");
	printf("\t\t\t\t---------------------------------------------------------- \n ");
	printf("\t\t\t\t|                     �������� ��������                  | \n ");
	printf("\t\t\t\t---------------------------------------------------------- \n ");
	Sleep(1000);
	system("cls");
}



void dejkctr(int** matr, int n) {

	int* v = (int*)malloc(sizeof(int) * n);
    int temp, minindex, min;
    int begin = 0;

    int* d = (int*)malloc(sizeof(int) * n);
	do {
		printf("������� ������� � ������� ������ ����: ");
		scanf("%d", &begin);
		if (begin < 1 || begin > n)
			printf("������ �������������� �������!\n");
	} while (begin < 1 || begin > n);
	begin -= 1;

	 
	  for (int i = 0; i < n; i++)
	  {
	      d[i] = INT_MAX;
	      v[i] = 1;
	  }
	  d[begin] = 0;
	 
	  do {
	      minindex = INT_MAX;
	      min = INT_MAX;
	      for (int i = 0; i < n; i++)
	      { 
	          if ((v[i] == 1) && (d[i] < min))
	          { 
	              min = d[i];
	              minindex = i;
	          }
	      }
	     
	      if (minindex != INT_MAX)
	      {
	          for (int i = 0; i < n; i++)
	          {
	              if (matr[minindex][i] > 0)
	              {
	                  temp = min + matr[minindex][i];
	                  if (temp < d[i])
	                  {
	                      d[i] = temp;
	                  }
	              }
	          }
	          v[minindex] = 0;
	      }
	  } while (minindex < INT_MAX);

	 
	  printf("\n���������� ���������� �� ������: \n");
	  for (int i = 0; i < n; i++) {
		  if (d[i] == INT_MAX)
			  printf("��� ���� � ������� %d\n", i + 1);
		  else
			  printf("���������� �� ������� %d = %d\n", i + 1, d[i]);
	  }

	  int vibor = 0;
	  
	  do {
		  printf("\n������ ���������� ���������� ���� �� ������? ���� ��, �� ������� 1, ���, �� ������� 0: ");
		  scanf("%d", &vibor);
		  if (vibor > 1 || vibor < 0)
			  printf("������! ������� ���� �� ������������ ���������!\n");
	  } while (vibor > 1 || vibor < 0);
	  if (vibor == 1) {
		  do {
			  int end = 0;
			  do {
				  printf("������� ����� �������, �� ������� ������ ����� ����: ");
				  scanf("%d", &end);
				  if (end > n || end < 1)
					  printf("������ �������������� �������!\n");
			  } while (end > n || end < 1);
			  
			  if (d[end - 1] == INT_MAX) {
				  printf("��� ����!");
			  }
			  else {
				  printf("\n����� ����������� ���� �� ������� %d:\n", end);
				  int* ver = (int*)malloc(sizeof(int) * n);
				  end -= 1;
				  ver[0] = end + 1; 
				  int k = 1; 
				  int weight = d[end]; 

				  while (end != begin) 
				  {
					  for (int i = 0; i < n; i++) 
						  if (matr[i][end] != 0)   
						  {
							  int temp = weight - matr[i][end];
							  if (temp == d[i]) 
							  {                 
								  weight = temp; 
								  end = i;       
								  ver[k] = i + 1; 
								  k++;
							  }
						  }
				  }
				  for (int i = k - 1; i >= 0; i--)
					  printf("->%3d ", ver[i]);
				  free(ver);
			  }
			  do{
			  printf("\n������ ���������� ������������� ����? ���� ���, �� ������� 0: ");
			  scanf("%d", &vibor);
			  if (vibor > 1 || vibor < 0)
				  printf("������! ������� ���� �� ������������ ���������!\n");
		  } while (vibor > 1 || vibor < 0);
		  } while (vibor);
	  }
	  free(v);
	  free(d);

}

int save_graph(int** matr, int n) {
	FILE* F;
	F = fopen("Matrica.txt", "w");
	if (F == NULL) {
		perror("������");
		return 0;
	}

	fprintf(F, "%d\n", n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			fprintf(F, "%d ", matr[i][j]);
		fprintf(F, "\n");
	}

	
	fclose(F);

	return 0;
}

int graph_1() {
	srand(time(NULL));
	int n = 0;
	printf("������� ���������� ������: ");
	scanf_s("%d", &n);
	int** matr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		matr[i] = (int*)malloc(sizeof(int) * n);

	int m = 0;
	printf("������� ������ ��� ��������� ����� �� 0 �� m: ");
	scanf_s("%d", &m);
	int orgr = 0;
	do {
		printf("������� ����� ���� ���� ������������� ���������������(1), �����������������(0): ");
		scanf("%d", &orgr);
		if (orgr > 1 || orgr < 0)
			printf("������! ������� ���� �� ������������ ���������!\n");
	} while (orgr > 1 || orgr < 0);
			if (orgr == 0) {
				for (int i = 0; i < n; i++) {
					for (int j = i; j < n; j++) {
						matr[i][j] = rand() % 2;
						matr[j][i] = matr[i][j];
						if (i == j)
							matr[i][j] = 0;
					}
				}
			}

			if (orgr == 1) {
				for (int i = 0; i < n; i++) {
					for (int j = i; j < n; j++) {
						matr[i][j] = rand() % 2;
						matr[j][i] = matr[i][j];
						if (i == j)
							matr[i][j] = 0;
					}

				}
			}

			if (orgr == 0) {
				for (int i = 0; i < n; i++) {
					for (int j = i; j < n; j++) {
						if (matr[i][j] == 1) {
							matr[i][j] = rand() % m;
							matr[j][i] = matr[i][j];
						}
					}
				}
			}
			int ori = 0;

			if (orgr == 1) {
				for (int i = 0; i < n; i++) {
					for (int j = i; j < n; j++) {

						if (matr[i][j] == 1) {
							matr[i][j] = rand() % m;
							ori = rand() % 3;
							if (ori == 1)
								matr[j][i] = matr[i][j];
							if (ori == 0)
								matr[j][i] = 0;
							if (ori == 2) {
								matr[j][i] = matr[i][j];
								matr[i][j] = 0;
							}
						}
					}
				}
			}
		
	
	printf("\n       �������:\n�  ");
	for (int i = 0; i < n; i++) {
		printf(" %3d", i + 1);
	}
	printf("\n__|");
	for (int i = 0; i < n; i++) {
		printf("____");
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		{
			printf("%d | ", i + 1);
			for (int j = 0; j < n; ++j)
				printf("%3d ", matr[i][j]);
			printf("\n");
		}
	}
	int opr = 0;
	while (1) {
		printf("\n������� ����� ��������:\n1)������� � ����� ������� ���� ����� ���������� ���� \n2)����� �� ������ � ������ ������\n");
		printf("�����: ");
		scanf_s("%d", &opr);
		switch (opr) {
		case 1:
			dejkctr(matr, n);
			break;
		case 2:
			do {
				printf("����� �� ��������� ��������������� �������? ���� �� ������� 1, ���� �� ����, �� 0: ");
				scanf("%d", &opr);
				if (opr > 1 || opr < 0)
					printf("������! ������� ���� �� ������������ ���������!\n");
			} while (opr > 1 || opr < 0);
			if (opr == 1)
				save_graph(matr, n);
			for (int i = 0; i < n; i++) {
				free(matr[i]);
			}
			free(matr);
			system("cls");
			return 0;
		default:
			printf("������! �� ������������ ����� ��������!��������� �������\n");
		}
	}

}

int graph_2() {
	int n = 0;
	printf("������� ���������� ������: ");
	scanf_s("%d", &n);
	int** matr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		matr[i] = (int*)malloc(sizeof(int) * n);

	int rebra = 0, orientier = 0;
	do {
		printf("\n���� ���������������? ������� 1 ���� ��, ����� 0: ");
		scanf("%d", &orientier);
		if (orientier > 1 || orientier < 0)
			printf("������! ������� ���� �� ������������ ���������!\n");
	} while (orientier > 1 || orientier < 0);
	if (orientier == 0) {
		for (int i = 0; i < n; i++)
		{
			matr[i][i] = 0;
			for (int j = i + 1; j < n; j++) {
				do {
					printf("������� ���������� %d - %d (���� 0 �� ����� ��������� ��� �������� ����): ", i + 1, j + 1);
					scanf("%d", &rebra);
					if (rebra < 0)
						printf("������! ���������� ������ ���� ������������� ���������!\n");
				} while (rebra < 0);
				matr[i][j] = rebra;
				matr[j][i] = rebra;
			}
		}
	}
	else {
		for (int i = 0; i < n; i++)
		{
			matr[i][i] = 0;
			for (int j = i + 1; j < n; j++) {
				do {
					printf("������� ���������� %d - %d (���� 0 �� ����� ��������� ��� �������� ����): ", i + 1, j + 1);
					scanf("%d", &rebra);
					if (rebra < 0)
						printf("������! ���������� ������ ���� ������������� ���������!\n");
				} while (rebra < 0);

				if (rebra != 0) {
					do {
						printf("\n� ����� ������� �������� ����?\n������� (1) ���� ������ �� %d - %d, (2) ���� ������ �� %d - %d, (3) ���� � ��� �������: \n", i + 1, j + 1, j + 1, i + 1);
						scanf("%d", &orientier);
						if (orientier > 3 || orientier < 1)
							printf("������! ������� ���� �� ������������ ���������!\n");
					} while (orientier > 3 || orientier < 1);
					if (orientier == 1) {
						matr[i][j] = rebra;
						matr[j][i] = 0;
					}
					if (orientier == 2) {
						matr[i][j] = 0;
						matr[j][i] = rebra;
					}
					if (orientier == 3) {
						matr[i][j] = rebra;
						matr[j][i] = rebra;
					}
				}
				else {
					matr[i][j] = rebra;
					matr[j][i] = rebra;
				}
			}
		}
	}
	

	printf("\n       �������:\n�  ");
	for (int i = 0; i < n; i++) {
		printf(" %3d", i + 1);
	}
	printf("\n__|");
	for (int i = 0; i < n; i++) {
		printf("____");
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		{
			printf("%d | ", i + 1);
			for (int j = 0; j < n; ++j)
				printf("%3d ", matr[i][j]);
			printf("\n");
		}
	}
	int opr = 0;
	while (1) {
		printf("\n������� ����� ��������:\n1)������� � ����� ������� ���� ����� ���������� ���� \n2)����� �� ������ � ������ ������\n");
		printf("�����: ");
		scanf_s("%d", &opr);
		switch (opr) {
		case 1:
			dejkctr(matr, n);
			_getch();
			break;
		case 2:
			do{
			printf("����� �� ��������� ��������������� �������? ���� �� ������� 1, ���� �� ����, �� 0: ");
			scanf("%d", &opr);
			if (opr > 1 || opr < 0)
				printf("������! ������� ���� �� ������������ ���������!\n");
		} while (opr > 1 || opr < 0);
			if (opr == 1)
				save_graph(matr, n);
			for (int i = 0; i < n; i++) {
				free(matr[i]);
			}
			free(matr);
			system("cls");
			return 0;
		default:
			printf("������! �� ������������ ����� ��������!��������� �������\n");
		}
	}
}

int graph_3() {
	FILE* F, *S;
	int n = 0;
	int vibor = 0;
	F = fopen("Matrica.txt", "r");
	if (F == NULL) {
		perror("������ ��� �������� �����");
		while (1) {
			printf("������ ������� ����? ������� 1 ���� ��, ���� ���, �� 0:");
			scanf("%d", &vibor);
			switch (vibor) {
			case 1: {
					S = fopen("Matrica.txt", "w");
					printf("���� ������, ������ ������� ��������� �������, ������� ������� ���������� ������, � ����� � ���� �������.");
					_getch();
					fclose(S);
					return 0;
				}
			case 0:
				return 0;
			default:
				printf("������! �� ������������ ����� ��������!��������� �������.\n");
			}
		}
	}

	fscanf(F, "%d", &n);
	if (n == 0) {
		printf("��������� �������! ��� ����� �  ����� 'Matrica.txt' ������� ������� ���������� ������, � ����� � ���� �������.");
		_getch();
		return 0;
	}
	int** matr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		matr[i] = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			matr[i][j] = 0;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(F, "%d", &matr[i][j]);
			if (matr[i][j] < 0) {
				printf("������! ������ �������� �������� ������ � ������� �������������� ����!\n�������� �������� �� �������������!");
				_getch();
				return 0;
			}
		}
	}

	fclose(F);

	

	printf("\n       �������:\n�  ");
	for (int i = 0; i < n; i++) {
		printf(" %3d", i + 1);
	}
	printf("\n__|");
	for (int i = 0; i < n; i++) {
		printf("____");
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		{
			printf("%d | ", i + 1);
			for (int j = 0; j < n; ++j)
				printf("%3d ", matr[i][j]);
			printf("\n");
		}
	}
	int opr = 0;
	while (1) {
		printf("\n������� ����� ��������:\n1)������� � ����� ������� ���� ����� ���������� ���� \n2)����� �� ������ � ������ ������\n");
		printf("�����: ");
		scanf_s("%d", &opr);
		switch (opr) {
		case 1:
			dejkctr(matr, n);
			break;
		case 2:
			for (int i = 0; i < n; i++) {
				free(matr[i]);
			}
			free(matr);
			system("cls");
			return 0;
		default:
			printf("������! �� ������������ ����� ��������!��������� �������\n");
		}
	}

}


int main()
{
setlocale(LC_ALL, "Rus");
zast();
int opr = 0;

while (1) {
	printf("����� ������� ������ � ������ �������?\n");
	printf("������� ����� ��������:\n1)�������� ������������� ����\n2)������� ���� �������\n3)��������� ���� �� �����\n4)��������� ������\n");
	printf("�����: ");
	scanf_s("%d", &opr);
	switch (opr) {
	case 1:
		system("cls");
		graph_1();
		break;
	case 2:
		system("cls");
		graph_2();
		break;
	case 3:
		system("cls");
		graph_3();
		break;
	case 4:
		return 0;
	default:
		printf("������! �� ������������ ����� ��������!��������� �������\n");
	
	}
}
}