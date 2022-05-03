#include<iostream>
using namespace std;
class moon
{
public:
	int data;
	moon*next;
	void push(class moon**top, int elem);
	void pop(class moon**top);
	void print(class moon*top);

};
void push(class moon**top, int elem)//двойной указатель чтоб вершина изменялась во всем коде, а не только в ф-ции, добавляемый элемент
{
	moon*q;//указатель на структуру
	q = new moon();//выделение места под узел
	q->data = elem;//в поле дата внесли элем
	if (top == NULL) { *top = q; }//если вершины нет(стек пуст), то этот элемент будет ею
	else
	{
		q->next = *top;//если вершина уже есть, то в адресное поле записываем верх
		*top = q;//новый элемент-новая вершинка
	}

}
void pop(class moon**top)
{
	moon*q = *top;//структурный указатель на вершинку
	moon*prev = nullptr;//указатель на пред элем пуст
	while (q != nullptr)//пока указатель настоящего элема не нуль
	{
		if (q->data % 2 == 0)//если встретилось четное число в инфополе
		{
			if (q == *top)//если этот элем -вершинка
			{
				*top = q->next;//вершиной станет следующий элем
				free(q);//добби свободен
				q->data = 0;//чистим поля узла
				q->next = 0;

			}
			else
			{
				prev->next = q->next;//связываем пред элем с настоящим
				free(q);//аналогично выше
				q->data = 0;
				q->next = 0;

			}
			prev = q;//пред элем - настоящий
			q = q->next;// перешли к след.элему
			break;//вышли из while
		}
	}
}
void print(class moon*top)
{
	moon*q = top;
	while (q != nullptr)
	{
		cout << " -> " << q->data;
		q = q->next;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	moon*top = 0;
	int n;
	cout << "Введите количество элементов стека - ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int elem;
		cout << "Введите элемент: ";
		cin >> elem;
		push(&top, elem);
		cout << endl;
	}
	cout << endl;
	print(top);
	pop(&top);
	print(top);
	return 0;
}