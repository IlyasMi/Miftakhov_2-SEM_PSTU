#include<iostream>
using namespace std;
template<typename T>
struct Node 
{
	T data;
	Node<T>* next;
};
template<typename T>
struct queue
{
	int size = 0;
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
};
template<typename T>
void new_queue(queue<T>& q, const int& n)
{
	T a;
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите элемент очереди: ";
		cin >> a;
		cout << endl;
		push(q, a);
	}
}
template<typename T>
void push(queue<T>& q, const int& a)
{
	if (q.head != nullptr)
	{
		Node<T>*new_node = new Node<T>;
		q.size++;
		new_node->data = a;
		new_node->next = nullptr;
		q.tail->next = new_node;
		q.tail = new_node;
	}
	else
	{
		Node<T>*new_node = new Node<T>;
		new_node->data = a;
		q.head = new_node;
		q.tail = new_node;
		q.size = 1;
	}
}
template<typename T>
void pop(queue<T>& q)
{
	Node<T>* tmp = q.head;
	q.head = q.head->next;
	q.size--;
	delete tmp;
}

template<typename T>
void print_queue(queue<T>& q) 
{
	Node<T>*tmp = q.head;
	cout << "начало - ";
	while (tmp != nullptr)
	{
		cout << tmp->data << " -> ";
		tmp = tmp->next;
	}
	cout << "КОНЕЦ";
	cout << endl;
}

template<typename T>
void add_element(queue<T>& q)
{
	int k = 0;
	while (k <= q.size)
	{
		if (k % 2 != 0)
		{
			
			T a;
			cout << "введите элемент для добавления: " << endl;
			cin >> a;
			push(q, a);
			push(q, q.head->data);
			pop(q);
		}
		k++;
	}

}


int main()
{
	setlocale(LC_ALL, "Russian");
	queue<char> q;
	int n;
	do
	{
		cout << "Введите кол-во элементов очереди: ";
		cin >> n;
		cout << endl;
	} while (n <= 0);
	new_queue(q, n);
	print_queue(q);
	int k = 1;
	add_element(q);
	cout << endl;
	print_queue(q);
	return 0;
}