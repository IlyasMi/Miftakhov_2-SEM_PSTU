#include<iostream>
#include<queue>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	priority_queue<char> q;
	cout << "Введите длину очереди: ";
	int n;
	cin >> n;
	cout << endl;
	for (int i = 1; i <= n; i++) 
	{
		cout << "Введите элемент очереди: ";
		char a;
		cin >> a;
		q.push(a);  // добавляем в очередь элементы
		cout << endl;
	}
	cout << endl;
	if (!q.empty()) cout << "Очередь не пуста!";  // проверяем пуста ли очередь (нет)
	cout << endl;
	for (int i = 0; i <= n/2; i++)
	{
		cout << "Введите элемент очереди: ";
		char a;
		cin >> a;
		q.push(a);  // добавляем в очередь элементы
		cout << endl;
	}
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	return 0;
}