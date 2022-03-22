#include<iostream>
#include<cstring>
#include<string>
#include<random>
#include<stdlib.h>
#include<time.h>
#include <functional>
using namespace std;

string name[30] = { "Иван", "Андрей", "Антон", "Амин", "Роберт", "Георгий", "Борис", "Владислав", "Дмитрий", "Никита", "Данила", "Артем", "Парвиз", "Сергей", "Илья", "Григорий", "Артур", "Денис", "Алексей", "Александр", "Валерий", "Дамир", "Михаил", "Константин", "Николай", "Герман", "Иннокентий", "Богдан", "Станислав", "Сурман" };
string patronymic[30] = { "Иванович", "Андреевич", "Антонович", "Аминович", "Робертович", "Георгиевич", "Борисович", "Владиславович", "Дмитриевич", "Никитович","Данилович", "Артемович", "Парвизович", "Сергеевич", "Ильич", "Григорьевич", "Артурович", "Денисович", "Алексеевич", "Александрович", "Валерьевич", "Дамирович", "Михайлович", "Константинович", "Николаевич", "Германович", "Иннокентьевич", "Богданович", "Станиславович", "Сурманович" };
string surname[30] = { "Карпов", "Афанасьев", "Власов","Маслов","Исаков","Тихонов","Аксёнов","Гаврилов","Родионов","Котов","Горбунов","Кудряшов","Быков","Зуев","Третьяков","Савельев","Панов","Рыбаков","Суворов","Абрамов","Воронов","Мухин","Архипов","Трофимов","Мартынов","Емельянов","Горшков","Чернов","Овчинников","Селезнёв" };
string ID[30] = { "5717","5321","2323","8321","3232","9999","9210","0105","6521","8891","1118","5617","9596","3490","9085","7254","7152","2015","8047","0001","3281","2131","8328","3727","2814","9348","2388","4211","3284","5521" };
string dates[30] = { "12.12.2011","18.05.1030","09.01.2000","21.03.2003","19.10.2010","23.09.2009","24.10.2010","25.11.2011","26.12.2012","27.01.1988","28.02.1967","29.04.1999","30.05.1867","31.12.1999","01.06.1976","02.07.1980","03.08.1982","04.09.1955","05.10.1948","06.11.2014","16.05.1977","29.06.2004","19.02.2001","09.11.1996","27.03.2002","30.10.2000","27.08.2022","28.02.2019","29.10.1932","30.09.2014" };
int coll_num = 0;
struct Human
{
	Human()
	{
		full_name = "NULL";
		id_number = "NULL";
		birthday = "NULL";
	}
	string full_name;
	string	id_number;
	string birthday;
};
struct hash_table
{
	Human*array;
	hash_table(int size)
	{
		array = new Human[size];
	}
	~hash_table()
	{
		delete[]array;
	}
	void find_index(string id_number, const int size);
	void add(Human tmp, const int size);
};
void show_table(hash_table*table, const int size);
void show(const Human tmp);
Human creator();
string get_random_name(); string get_random_birthday(); string get_random_id(); 
void print_Humans(const Human* const array, const int size);
int get_random_num();
int get_sum_id(string str);
int hash_function(string str, const int size);
void fill_creator(Human*array, const int count);
void hash_table::find_index(string id_number, const int size)
{
	int hash = hash_function(id_number, size);
	int index = hash;
	while (array[index].id_number != id_number && index < size)
	{
		index++;
	}
	if (index >= size)
	{
		index = 0;
		while (array[index].id_number != id_number && index < hash)
		{
			index++;
		}
		if (index >= hash)
		{
			cout << "Челобаки с номером паспорта: " << id_number << " нет" << endl;
		}
		else
		{
			cout << "Челобака с номером паспорта: " << id_number << " найдена с индексом: " << index << " ))" << endl;
		}
	}
	else
	{
		cout << "Челобака с номером паспорта: " << id_number << " найдена с индексом: " << index << " ))" << endl;
	}
}
void hash_table::add(Human tmp, const int size)
{
	int index = hash_function(tmp.id_number, size);
	int hash = index;
	if (array[index].full_name == "NULL")
	{
		array[index] = tmp;
		return;
	}
	else
	{
		while (index < size)
		{
			if (array[index].full_name == "NULL")
			{
				array[index] = tmp;
				return;
			}
			index++;
			coll_num++;
		}
		if (index >= size)
		{
			index = 0;
			coll_num++;
			while (index < hash)
			{
				if (array[index].full_name == "NULL")
				{
					array[index] = tmp;
					return;
				}
				index++;
				coll_num++;
			}
		}
	}
}
Human creator()
{
	Human tmp;
	tmp.full_name = get_random_name();
	tmp.birthday = get_random_birthday();
	tmp.id_number = get_random_id();
	return tmp;
}
string get_random_name()
{
	return(surname[get_random_num()] + " " + name[get_random_num()] + " " + patronymic[get_random_num()]);
}
string get_random_birthday()
{
	return dates[get_random_num()];
}
string get_random_id()
{
	return ID[get_random_num()];
}
void show(const Human tmp)
{
	cout << "ФИО:           " << tmp.full_name<<endl;
	cout << "Дата рождения: " << tmp.birthday << endl;
	cout << "№ паспорта:    " << tmp.id_number << endl;
}
void print_Humans(const Human* const array, const int size)
{
	for (int i = 0; i < size; i++)
	{
		show(array[i]);
	}
}
void fill_creator(Human*array, const int count)
{
	for (int i = 0; i < count; i++)
	{
		array[i] = creator();
	}
}
int get_random_num()
{
	return rand() % 30;
}
int get_sum_id(string str)
{
	string yam = ID[11];
	int sum = stoi(yam);
	return sum;
}
int hash_function(string str, const int size)
{
	double a = 0.618*get_sum_id(str);
	double c = size * (a - static_cast<int>(a));
	return static_cast<int>(c);
}
void show_table(hash_table*table, const int size)
{
	for (int i = 0; i < size; i++)
	{
		show(table->array[i]);
	}
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	int size;
		cout << "Введите количество элементов в массиве(не менее 100): ";
		cin >> size;
	cout << endl;
	Human*array = new Human[size];
	hash_table table(size);
	fill_creator(array, size);
	for (int i = 0; i < size; i++)
	{
		table.add(array[i], size);
	}
	show_table(&table, size);
	table.find_index("5617", size);
	cout << endl << "===============" << endl;
	show_table(&table, size);
	cout << "Кол-во колллизий для " << size << " записей равно " << coll_num << endl;
	delete[] array;
	return 0;
}