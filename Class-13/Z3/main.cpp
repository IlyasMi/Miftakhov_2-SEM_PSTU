#include "Money.h"
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

typedef multiset<Money> Tmset;//определяем тип работы с мультисет
typedef multiset<Money>::iterator it;//итератор
Money s;

//добавим предикат для сравнения заданного значения с объектом Money
struct Greater_s
{
	bool operator() (Money m)
	{
		if (m > s) return true;
		else return false;
	}
};

//создание мн-ва
Tmset make_multiset(int n)
{
	Tmset m;
	Money a;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		m.insert(a);
	}
	return m;
}

//печать мн-ва
void print_multiset(Tmset m)
{
	it i = m.begin();
	while (i != m.end())
	{
		cout << *i;
		i++;
	}
	cout << "\n";
}

//среднее
Money srednee(Tmset m)
{
	it i = m.begin();
	Money sum;//сумма элементов
	int n = 1;//количество элементов
	while (i != m.end())
	{
		sum = sum + (*i);
		n++;
		i++;
	}

	return sum / n;
}

//умножение
void multi(Money& m)
{
	m = m * s;
}

bool operator< (const Money& m1, const Money& m2)
{
	return (m1 < m2);
}

int main()
{
	int n;//размер
	cout << "Enter n >> ";
	cin >> n;

	Tmset m = make_multiset(n);//создаём мн-во
	print_multiset(m);

	cout << "Add min: ";//добавляем мин элемент
	//так как это мн-во, то данные упорядочены, в определённое место вставить элемент не получится
	//поэтому нам достаточно просто добавить в начало минимальный элемент
	it i = m.begin();
	Money min = (*i);
	m.insert(min);
	print_multiset(m);

	s = srednee(m);//удалить больше среднего
	cout << "Average: " << s << "\n";
	cout << "Del more average: ";
	m.erase(remove_if(m.begin(), m.end(), Greater_s()), m.end());
	print_multiset(m);

	cout << "Multiple srednee: ";//умножить на среднее
	for_each(m.begin(), m.end(), multi);
	print_multiset(m);
	return 0;
}
