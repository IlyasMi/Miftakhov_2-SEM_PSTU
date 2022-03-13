#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	char arr[10] = { 'G', 'Y', 'b', 'r', 'i', '=', 'H', 'L', 'H', '=' };
	char tmp;
	cout << "Исходный массив: ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
	for (int i = 0; i < 10 - 1; i++)
	{
		for (int j = 10 - 1; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
	cout << "Отсортированный массив: ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
		char key;
		cout << "Enter key: ";
		cin >> key;
		int left = 0;
		int mid = 0;
		int right = 10;
		bool found = false;
		while ((left <= right) && found != true)
		{
			mid = left + ((key - arr[left])*(right - left)) / (arr[right] - arr[left]);
			if (arr[mid] < key) { left = mid + 1; }
			else if (arr[mid] > key) { right = mid + 1; }
			else { found = true; }
		}
		if (arr[left] == key)
		{
			arr[left] = '*';
		}
		else if (arr[right] == key);
		{
			arr[right] = '*';
		}
		cout << "Измененный: ";
		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		char stk;
		for (int i = 0; i < 10 - 1; i++)
		{
			for (int j = 10 - 1; j > 0; j--)
			{
				if (arr[j] < arr[j - 1])
				{
					stk = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = stk;
				}
			}
		}
		cout << "Отсортированный массив: ";
		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	
		char key1;
		cout << "Enter key: ";
		cin >> key1;
		int left1 = 1;
		int mid1 = 1;
		int right1 = 10;
		bool found1 = false;
		while ((left1 <= right1) && found1 != true)
		{
			mid1 = left1 + ((key1 - arr[left1])*(right1 - left1)) / (arr[right1] - arr[left1]);
			if (arr[mid1] < key1) { left1 = mid1 + 1; }
			else if (arr[mid1] > key1) { right1 = mid1 + 1; }
			else { found1 = true; }
		}
		if (arr[left1] == key1)
		{
			arr[left1] = '*';
		}
		else if (arr[right1] == key1);
		{
			arr[right1] = '*';
		}
		cout << "Измененный: ";
		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		char tm;
		for (int i = 0; i < 10 - 1; i++)
		{
			for (int j = 10 - 1; j > 0; j--)
			{
				if (arr[j] < arr[j - 1])
				{
					tm = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tm;
				}
			}
		}
		cout << "Отсортированный массив: ";
		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	return 0;
}