#include<iostream>
#include<cmath>
#include <cstring>
using namespace std;
int min_element(int n, int a[ ])
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}

size_t min_element(string str)//size_t= UNSIGNED INT
{
	size_t min = str.length();//определение длины строки! мин равен всей строке 
	int k = 0;//счетчик
	for (size_t i = 0; i < str.length(); i++)//пока И меньше длины строки будем идти
	{
		k++;//итерируем счетчик на единицу
		if (str[i + 1] == ' ' || str[i + 1] == '\0') // тут можете добавить свои разделители ЕСЛИ следующий элемент строки пробел или конец строки, то..
		{
			if (min > k)
			{
				min = k;//если минимум больше счетчика, тогда минимум равен счетчику 
			}
			k = -1;//обнуление счетчика до -1, восстановление до 0 в следущем шаге
		}
	}
	return min;
}


int main()
{
	//int a[] = { 123,452432,125,34534,10 };
	//cout << min_element(5, a ) << endl;
	cout << min_element("Hello little man") << endl;
}