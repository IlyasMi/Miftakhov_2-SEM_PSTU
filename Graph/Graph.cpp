#include <iostream>
int SIZE = 6;
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int a[6][6] = { {0,0,11,26,0,12},{0,0,17,20,0,0},{11,17,0,0,15,0},{26, 20, 0,0,38,0},{0,0,15,38,0,23},{12,0,0,0,23,0} }; // матрица связей
	int min_d[6]; // минимальное расстояние
	int visit[6]; // посещенные вершины
	int temp, minindex, min;
	int begin_index = 5;
	cout << "Матрица связей: " << endl;
	// Вывод матрицы связей
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << " " << a[i][j] << " ";
		}
		cout << endl;
	}
	
	//Инициализация вершин и расстояний
	for (int i = 0; i < SIZE; i++)
	{
		min_d[i] = 10000;
		visit[i] = 1;
	}
	min_d[begin_index] = 0;
	// Шаг алгоритма
	do {
		minindex = 10000;
		min = 10000;
		for (int i = 0; i < SIZE; i++)
		{ // Если вершину ещё не обошли и вес меньше min
			if ((visit[i] == 1) && (min_d[i] < min))
			{ // Переприсваиваем значения
				min = min_d[i];
				minindex = i;
			}
		}
		// Добавляем найденный минимальный вес
		// к текущему весу вершины
		// и сравниваем с текущим минимальным весом вершины
		if (minindex != 10000)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (a[minindex][i] > 0)
				{
					temp = min + a[minindex][i];
					if (temp < min_d[i])
					{
						min_d[i] = temp;
					}
				}
			}
			visit[minindex] = 0;
		}
	} while (minindex < 10000);
	// Вывод кратчайших расстояний до вершин
	cout << endl << "Кратчайшие расстояния до вершин: " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << " " << min_d[i] << " ";
	
	return 0;
}