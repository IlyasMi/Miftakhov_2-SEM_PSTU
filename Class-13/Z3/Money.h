#pragma once
#include <iostream>

using namespace std;

class Money
{
protected:
	long rub;
	int kop;
public:
	//конструкторы
	Money(void);
	Money(long, int);
	Money(const Money&);

	//деструктор
	~Money(void);

	//селекторы
	long Get_Rub();
	int Get_Kop();

	//модификаторы
	void Set_Rub(long);
	void Set_Kop(int);

	Money operator= (const Money&);//оператор присваивания
	const Money& operator+ (const Money&);//сложение
	const Money& operator- (const Money&);//вычитание
	const Money& operator/ (int);//деление
	const Money& operator* (const Money&);//умножение
	bool operator> (const Money&);//оператор >
	bool operator< (const Money&);//оператор <
	bool operator!= (const Money&);//оператор !=
	bool operator== (const Money&);//оператор ==

	//дружественные функции ввода/вывода
	friend ostream& operator<< (ostream& out, const Money& m);
	friend istream& operator>> (istream& in, Money& m);
};