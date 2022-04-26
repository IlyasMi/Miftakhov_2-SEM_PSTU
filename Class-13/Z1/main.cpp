#include "Money.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<Money> Tvec;
Money s;//добавим глобальную переменную Money для сравнения с заданным значением

//добавим предикат для сравнения заданного значения с объектом Money
struct Greater_s
{
	bool operator() (Money m)
	{
		if (m > s) return true;
		else return false;
	}
};


//формирование вектора
Tvec make_vector(int n)
{
	Money a;
	Tvec v;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}

//печать вектора
void print_vector(Tvec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

//поиск среднего
Money srednee(Tvec v)
{
	Money sum = v[0];
	for (int i = 1; i < v.size(); i++)
		sum = sum + v[i];
	return sum / v.size();
}

//функция добавления
void mult(Money& m)
{
	m = m * s;
}


int main()
{
	int n;
	cout << "Enter n >> ";
	cin >> n;

	Tvec v = make_vector(n);
	print_vector(v);

	int pos;
	cout << "Enter pos for add >> ";
	cin >> pos;

	Tvec::iterator i;//создали итератор
	cout << "Add min: ";
	i = min_element(v.begin(), v.end());
	Money min = (*i);//нашли макс элемент
	int count = 0;
	for (i = v.begin(); i != v.end(); i++)
	{
		count++;
		if (count == pos) break;
	}
	v.insert(i, min);//добавили макс элемент в вектор
	print_vector(v);

	s = srednee(v);
	cout << "Average: " << s << "\n";
	cout << "Del more average: ";
	v.erase(remove_if(v.begin(), v.end(), Greater_s()), v.end());//удалили 
	print_vector(v);

	cout << "Multiple average: ";
	s = srednee(v);
	for_each(v.begin(), v.end(), mult);
	print_vector(v);

	return 0;
}