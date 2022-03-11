#include<iostream>
#include<stack>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	stack<int> moon;
	stack<int> sun;
	int n;
	cout << "Введите количество элементов стека - ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int data;
		cout << "Введите элемент очереди: ";
		cin >> data;
		moon.push(data);
		cout << endl;
	}
	for (int i = 1; i <= n; i++)
	{
		if (moon.top() % 2 == 0)
		{
			moon.pop();
		}
		else
		{
			sun.push(moon.top());
			moon.pop();
		}
	}
	while (!sun.empty())
	{
		cout << " -> " << sun.top();
		sun.pop();	
	}

	return 0;
}
