#include<iostream>
#include<stdio.h>
using namespace std;
void create(int*&arr, int size)
{
	arr = new int[size]();//Динамический массив, заполненный нулями
	int j = 9;//начало отсчета для массива
	for (int i = 0; i < size ; ++i)
	{
		arr[i] = j;
		cout << arr[i] << " ";
		j--;
	}//заполнили массив числами до 9 до 0
	cout << endl;
}
void Print1(int*&arr, int size, int k)
{
	if (k <= size and k>=0)//чтоб не вылезти за память
	{
		for (int i = k; i <= k + 1; i++)//условия для выполнения цикла 2 раза
		{
			if (i - 1 == size) { i = 0; }//если предыдущий перед К И равен длине массива, то обнуляем И
			cout << arr[i] << " ";//выводим нужное
		}
		cout << endl;
	}
}
void AddFront(int*&arr, int &size, int element)
{
	int*arr1 = new int[size + 1];//динамический массив с кол-вом символов больше на 1
	arr1[0] = element;//нулевому элементу массива присвоить значение нашего элемента
	for (int i = 0; i < size+1; ++i)
	{
		arr1[i+1] = arr[i];//переписываем массив со сдвигом вправо, так как добавили элемент в начало
		cout << arr1[i] << " ";
	
	}

	delete[]arr;
	arr = arr1;
	++size;
	cout << endl;
}
void AddBack(int*&arr, int &size, int element)
{
	int*arr2 = new int[size + 1];//аналогично прошлой функции
	
	for (int i = 0; i <size+1; ++i)
	{
		arr2[i] = arr[i];//переобозначили элементы старого массива в динамический
		arr2[size] = element;//последнему свободному элементу присвоили значение элемента
		cout << arr2[i] << " ";
	}
	delete[]arr;
	arr = arr2;
	++size;
	cout << endl;
}
void Delete(int*&arr, int &size, int k)
{
	int *arr3 = new int[size];//динамический массив
	int NewArr3[12];//макс кол-во элементов нового массива, так как размер 12, вдруг все числа будут четные
	int NewSize=0;//размер нового массива
	int length = 0;//переменная для нового массива
	for (int i = 0; i < size; i++)
	{
		arr3[i] = arr[i];//переобозначение старого массива в динамический
		cout << arr3[i] << " ";
		if (arr3[i] % 2 == 0)//если число четное,
		{
			NewArr3[length] = arr3[i];//то помещаем его в новый массив
			length++;
		}
		
	}
	cout << endl;
	for (int i = 0; i < length; i++)
	{
		cout << NewArr3[i] << " ";//смотрим новый массив
	}
	delete[]arr;
	arr = NewArr3;
	cout << endl;
	for (int i = 0; i < length; i++)
	{
		NewSize++;//считаем новый размер массива
	}
	cout << NewSize << endl;
	size = NewSize;//меняем значение размера
	if (k <= size and k >= 0)//вывод к и к+1 элемента осуществляем аналогично функции Print1
	{
		for (int i = k; i <= k + 1; i++)
		{
			if (i - 1 == size) { i = 0; }
			cout << arr[i] << " ";
		}
		cout << endl;
	}

}
int main()
{
	setlocale(LC_ALL, "russian");
	int *arr = NULL;
	int k = 1;
	int element = 793;
	int size = 10;
	create(arr, size);
	Print1(arr, size, k);
	AddFront(arr, size, element);
	AddBack(arr, size, element);
	Delete(arr, size, k);
	return 0;
}