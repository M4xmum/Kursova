#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <windows.h>


void zast() {
	printf("\n\n\t\t\t\t---------------------------------------------------------- \n ");
	printf("\t\t\t\t| Курсовая работа студента группы 22ВВС1 Костина Максима | \n ");
	printf("\t\t\t\t---------------------------------------------------------- \n ");
	printf("\t\t\t\t|                     Алгоритм Дейкстры                  | \n ");
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
		printf("Введите вершину с которой начать путь: ");
		scanf("%d", &begin);
		if (begin < 1 || begin > n)
			printf("Ошибка несуществующая вершина!\n");
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

	 
	  printf("\nКратчайшие расстояния до вершин: \n");
	  for (int i = 0; i < n; i++) {
		  if (d[i] == INT_MAX)
			  printf("Нет пути в вершину %d\n", i + 1);
		  else
			  printf("Расстояние до вершины %d = %d\n", i + 1, d[i]);
	  }

	  int vibor = 0;
	  
	  do {
		  printf("\nХотите посмотреть кратчайшие пути до вершин? Если да, то введите 1, нет, то введите 0: ");
		  scanf("%d", &vibor);
		  if (vibor > 1 || vibor < 0)
			  printf("Ошибка! Введите один из предложенных вариантов!\n");
	  } while (vibor > 1 || vibor < 0);
	  if (vibor == 1) {
		  do {
			  int end = 0;
			  do {
				  printf("Введите номер вершины, до которой хотите найти путь: ");
				  scanf("%d", &end);
				  if (end > n || end < 1)
					  printf("Ошибка несуществующая вершина!\n");
			  } while (end > n || end < 1);
			  
			  if (d[end - 1] == INT_MAX) {
				  printf("Нет пути!");
			  }
			  else {
				  printf("\nВывод кратчайшего пути до вершины %d:\n", end);
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
			  printf("\nХотите продолжить просматривать пути? Если нет, то введите 0: ");
			  scanf("%d", &vibor);
			  if (vibor > 1 || vibor < 0)
				  printf("Ошибка! Введите один из предложенных вариантов!\n");
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
		perror("Ошибка");
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
	printf("Введите количество вершин: ");
	scanf_s("%d", &n);
	int** matr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		matr[i] = (int*)malloc(sizeof(int) * n);

	int m = 0;
	printf("Введите предел для генерации числа от 0 до m: ");
	scanf_s("%d", &m);
	int orgr = 0;
	do {
		printf("Введите какой граф надо сгенерировать ориентированный(1), неориентированный(0): ");
		scanf("%d", &orgr);
		if (orgr > 1 || orgr < 0)
			printf("Ошибка! Введите один из предложенных вариантов!\n");
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
		
	
	printf("\n       Матрица:\n№  ");
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
		printf("\nВведите номер операции:\n1)Выбрать с какой вершины надо найти кратчайшие пути \n2)Выйти из работы с данным графом\n");
		printf("Выбор: ");
		scanf_s("%d", &opr);
		switch (opr) {
		case 1:
			dejkctr(matr, n);
			break;
		case 2:
			do {
				printf("Нужно ли сохранять сгенерированную матрицу? Если да введите 1, если не надо, то 0: ");
				scanf("%d", &opr);
				if (opr > 1 || opr < 0)
					printf("Ошибка! Введите один из предложенных вариантов!\n");
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
			printf("Ошибка! Не существующий номер операции!Повторите попытку\n");
		}
	}

}

int graph_2() {
	int n = 0;
	printf("Введите количество вершин: ");
	scanf_s("%d", &n);
	int** matr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		matr[i] = (int*)malloc(sizeof(int) * n);

	int rebra = 0, orientier = 0;
	do {
		printf("\nГраф ориентированный? Введите 1 если да, иначе 0: ");
		scanf("%d", &orientier);
		if (orientier > 1 || orientier < 0)
			printf("Ошибка! Введите один из предложенных вариантов!\n");
	} while (orientier > 1 || orientier < 0);
	if (orientier == 0) {
		for (int i = 0; i < n; i++)
		{
			matr[i][i] = 0;
			for (int j = i + 1; j < n; j++) {
				do {
					printf("Введите расстояние %d - %d (если 0 то между вершинами нет никакого пути): ", i + 1, j + 1);
					scanf("%d", &rebra);
					if (rebra < 0)
						printf("Ошибка! Расстояние должно быть положительным значением!\n");
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
					printf("Введите расстояние %d - %d (если 0 то между вершинами нет никакого пути): ", i + 1, j + 1);
					scanf("%d", &rebra);
					if (rebra < 0)
						printf("Ошибка! Расстояние должно быть положительным значением!\n");
				} while (rebra < 0);

				if (rebra != 0) {
					do {
						printf("\nВ какую сторону провести путь?\nВведите (1) если только из %d - %d, (2) если только из %d - %d, (3) если в обе стороны: \n", i + 1, j + 1, j + 1, i + 1);
						scanf("%d", &orientier);
						if (orientier > 3 || orientier < 1)
							printf("Ошибка! Введите один из предложенных вариантов!\n");
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
	

	printf("\n       Матрица:\n№  ");
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
		printf("\nВведите номер операции:\n1)Выбрать с какой вершины надо найти кратчайшие пути \n2)Выйти из работы с данным графом\n");
		printf("Выбор: ");
		scanf_s("%d", &opr);
		switch (opr) {
		case 1:
			dejkctr(matr, n);
			_getch();
			break;
		case 2:
			do{
			printf("Нужно ли сохранять сгенерированную матрицу? Если да введите 1, если не надо, то 0: ");
			scanf("%d", &opr);
			if (opr > 1 || opr < 0)
				printf("Ошибка! Введите один из предложенных вариантов!\n");
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
			printf("Ошибка! Не существующий номер операции!Повторите попытку\n");
		}
	}
}

int graph_3() {
	FILE* F, *S;
	int n = 0;
	int vibor = 0;
	F = fopen("Matrica.txt", "r");
	if (F == NULL) {
		perror("Ошибка при открытии файла");
		while (1) {
			printf("Хотите создать файл? Введите 1 если да, если нет, то 0:");
			scanf("%d", &vibor);
			switch (vibor) {
			case 1: {
					S = fopen("Matrica.txt", "w");
					printf("Файл создан, теперь вручную заполните матрицу, сначала укажите количество вершин, а потом и саму матрицу.");
					_getch();
					fclose(S);
					return 0;
				}
			case 0:
				return 0;
			default:
				printf("Ошибка! Не существующий номер операции!Повторите попытку.\n");
			}
		}
	}

	fscanf(F, "%d", &n);
	if (n == 0) {
		printf("Заполните матрицу! Для этого в  файле 'Matrica.txt' введите сначала количество вершин, а потом и саму матрицу.");
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
				printf("Ошибка! Данный алгоритм работает только с ребрами положительного веса!\nИзмените значения на положительные!");
				_getch();
				return 0;
			}
		}
	}

	fclose(F);

	

	printf("\n       Матрица:\n№  ");
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
		printf("\nВведите номер операции:\n1)Выбрать с какой вершины надо найти кратчайшие пути \n2)Выйти из работы с данным графом\n");
		printf("Выбор: ");
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
			printf("Ошибка! Не существующий номер операции!Повторите попытку\n");
		}
	}

}


int main()
{
setlocale(LC_ALL, "Rus");
zast();
int opr = 0;

while (1) {
	printf("Какой вариант работы с графом выбрать?\n");
	printf("Введите номер операции:\n1)Случайно сгенерировать граф\n2)Создать граф вручную\n3)Загрузить граф из файла\n4)Завершить работу\n");
	printf("Выбор: ");
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
		printf("Ошибка! Не существующий номер операции!Повторите попытку\n");
	
	}
}
}