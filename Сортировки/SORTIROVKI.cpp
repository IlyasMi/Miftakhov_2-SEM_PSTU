#include <iostream>
#include <ctime>
using namespace std;
void print_arr(int* arr, const int n)
{
	for (int counter = 0; counter < n; counter++)
	{
		cout << arr[counter] << ' ';
	}
	cout << endl;
}

void shell(int x[], int n)
{
	int i, j, k, inc, temp;
	int swp = 0, comp = 0; inc = n / 2;
	while (inc > 0)
	{
		for (i = 0; i < inc; i++)
		{
			for (j = 0; j < n; j += inc)
			{
				temp = x[j];
				for (k = j - inc; k >= 0 && temp < x[k]; k -= inc)
				{
					comp++;
					swp++;
					x[k + inc] = x[k];
				}
				x[k + inc] = temp;
				swp++;
			}
		}
		comp++;
		if (inc / 2 != 0)
			inc = inc / 2;
		else if (inc == 1)
			inc = 0;
		else
			inc = 1;
	}
}

void hoar(int* a, int n)
{
	int i = 0;
	int j = n - 1;
	int mid = a[n / 2];
	do
	{
		while (a[i] < mid)
		{
			i++;
		}
		while (a[j] > mid)
		{
			j--;
		}
		if (i <= j)
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
	{
		hoar(a, j + 1);
	}
	if (i < n)
	{
		hoar(&a[i], n - i);
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int n, k;
	cout << "Введите количество элементов массива: ";
	cin >> n;
	int* arr = new int[n];
	for (int counter = 0; counter < n; counter++)
	{
		arr[counter] = rand() % 100 - 50;
	}
	print_arr(arr, n);
	cout << "Выберете метод сортировки:" << endl << "1. Сортировка Шелла " << '\n' << "2. Сортировка Хоара " << endl;
	cin >> k;
	switch (k)
	{
	case(1):
		shell(arr, n);
		print_arr(arr, n);
		break;
	case(2):
		hoar(arr, n);
		print_arr(arr, n);
		break;
	}
	return 0;

}