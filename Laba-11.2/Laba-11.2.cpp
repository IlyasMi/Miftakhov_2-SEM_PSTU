#include<iostream>
using namespace std;

struct Beast
{
	char element[20];
	Beast* next;
}*beg;

Beast* make_list(int n)
{
	Beast* beg;//указатель на первый элемент
	Beast* p, *r;//вспомогательные указатели
	beg = new(Beast);//выделяем память под первый элемент
	cout << "\n?";
	cin >> beg->element;//вводим значение информационного поля
	beg->next = 0;//обнуляем адресное поле
	//ставим на этот элемент указатель p (последний элемент)
	p = beg;

	for (int i = 0; i < n - 1; i++)
	{
		r = new(Beast);//создаем новый элемент
		cout << "\n?";
		cin >> r->element;
		r->next = 0;
		p->next = r;//связываем p и r
		//ставим на r указатель p (последний элемент)
		p = r;
	}

	return beg;//возвращаем beg как результат функции

}

void print_list(Beast* beg)
//печать списка
{
	while (beg != nullptr)
	{
		cout << beg->element << "\t";
		beg = beg->next;//переход к следующему элементу
	}
}

Beast* add_point(Beast*beg)
{
	int k = 1;
	while (k <= 5)
	{
		Beast*p = beg;//встали на первый элемент
		Beast*New = new(Beast);//создали новый элемент
		cout << "Key?"; cin >> New->element;
		for (int i = 0; i < k - 1 && p != 0; i++)
			p = p->next;//проходим по списку до(k-1) элемента или до конца
		if (p != 0)//если k-й элемент существует
		{
			New->next = p->next;//связываем New и k-й элемент
			p->next = New;//связываем (k-1)элемент и New
		}


		k += 2;
	}
	return beg;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Beast* beg = make_list(5);

	add_point(beg);
	print_list(beg); 
	return 0;
}