#include<iostream>
#include<stdarg.h>
#include <cstdarg>
using namespace std;
int belong(int num, ...)
{
	int count = 0;//счетчик
	int sun = 0;//сумма - выбранное указателем число
	int squads = 0;
	int rad = num * num;//взяли радиус из числа количества элементов 
	va_list param;//задали указатель
	va_start(param, num);//указываем на количество элементов
		for (int i = 0; i < num; i++)
		{
			sun = va_arg(param, int);//выбранное указателем число после количества элементов
			cout <<"Число - "<< sun << endl;
			sun = sun * sun;//возвели в квадрат
			squads += sun;//прибавили первое слагаемое в сумме квадратов
			sun = 0;//обнулили число
			if (i%2!=0)//если у нас уже есть координаты точки х и у
			{
				if (squads <= rad)// если x^2+y^2<=radius
				{
					cout << "Меньше, чем радиус - " << squads << endl;
					count += 1;//заметили нужную точку, отметили, что встретили ее
					squads = 0;
				}
				else // если x^2+y^2>radius
				{
					cout <<"Больше, чем радиус - " << squads << endl;
					squads = 0;
				}
			}	
		}
	va_end(param);
	return count;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Количество точек (1) - " << belong(10, 21, 1, 2, 3, 4, 9, 10, 2, 7, 2) << endl;
	cout << "Количество точек (2) - " << belong(8, 1, 1, 12, 33, 14, 9, 0, 2) << endl;
	cout << "Количество точек (3) - " << belong(2, 2, 0) << endl;
	return 0;}