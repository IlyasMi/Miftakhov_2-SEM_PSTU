#include<iostream>
using namespace std;

struct Beast
{
	int element;
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
Beast* del_point(Beast*beg)
{
	Beast*p = beg;
	int count = 0;

	while (p->next != 0) 
	{
		p = p->next;
		count++;
		if (p->element % 2 == 0)
		{
			cout << count << endl;
			//p = p->next;
			Beast*p = beg;
			for (int i = 1; i < count&&p->next != 0; i++)
			{
				p = p->next;
			}
			Beast* r = p->next;//ставим указатель r на k-й элемент
			p->next = r->next;//связываем k-1 и k+1 элемент
delete r;//удаляем k-й элемент из памяти
	return beg;

			break;
			
			
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Beast* beg = make_list(5);
	
	del_point(beg);
print_list(beg);
	return 0;
}