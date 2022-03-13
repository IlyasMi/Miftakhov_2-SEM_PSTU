#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	int tmp = 0;
	int arr[5] = { 34, 213, 99, 0, 515 };
	cout << "Введите номер элемента для замены от 0 до 4: ";
	cin >> n;
	cout << endl;
	if (n != 4)
		{
			
				tmp = arr[n];
				arr[n] = arr[n + 1];
				arr[n + 1] = tmp;
			
		}
		else if (n == 4)
		{
			
				tmp = arr[n];
				arr[n] = arr[n - 1];
				arr[n - 1] = tmp;
			
		}
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}