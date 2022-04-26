#include "Money.h"
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef queue<Money> Que;//���������� ����
typedef vector<Money> Vec;//���������� ������
Money a;

//������� �������� ��� ��������� ��������� �������� � �������� Money
struct Greater_s
{
	bool operator() (Money m)
	{
		if (m > a) return true;
		else return false;
	}
};

//�-�� ��� ������������ �����
Que make_queue(int n)
{
	Que s;
	Money m;

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		s.push(m);
	}
	return s;
}

//�������� ���� � ������
Vec copy_queue_to_vector(Que s)
{
	Vec v;
	while (!s.empty())
	{
		v.push_back(s.front());
		s.pop();
	}
	return v;
}

//�������� ������ � ����
Que copy_vector_to_queue(Vec v)
{
	Que s;
	for (int i = 0; i < v.size(); i++)
		s.push(v[i]);
	return s;
}

//����� �����
void print_queue(Que s)
{
	Vec temp;
	temp = copy_queue_to_vector(s);//�������� ���� � ������

	while (!s.empty())
	{
		cout << s.front() << " ";
		s.pop();
	}

	s = copy_vector_to_queue(temp);//�������� ������ � ����
	cout << "\n";
}

//����� ��������
Money srednee(Vec v)
{
	Money sum = v[0];
	for (int i = 1; i < v.size(); i++)
		sum = sum + v[i];
	return sum / v.size();
}

//����������
void multi(Money& m)
{
	m = m * a;
}

int main()
{
	int n;
	cout << "Enter n >> ";
	cin >> n;

	Que s = make_queue(n);
	print_queue(s);

	int pos;
	cout << "Enter pos for add >> ";
	cin >> pos;

	cout << "Add min: ";
	Vec temp = copy_queue_to_vector(s);
	Vec::iterator i = min_element(temp.begin(), temp.end());
	Money min = (*i);
	int count = 0;
	for (i = temp.begin(); i < temp.end(); i++)
	{
		count++;
		if (count == pos) break;
	}
	temp.insert(i, min);
	s = copy_vector_to_queue(temp);
	print_queue(s);

	a = srednee(temp);
	cout << "Average: " << a << "\n";
	cout << "Del more average: ";
	temp = copy_queue_to_vector(s);
	temp.erase(remove_if(temp.begin(), temp.end(), Greater_s()), temp.end());
	s = copy_vector_to_queue(temp);
	print_queue(s);

	cout << "Multiple average: ";
	temp = copy_queue_to_vector(s);
	for_each(temp.begin(), temp.end(), multi);
	s = copy_vector_to_queue(temp);
	print_queue(s);

	return 0;
}