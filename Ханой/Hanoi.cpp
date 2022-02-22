#include<iostream>
using namespace std;
int hanoi(int n, int i, int k)
{
	if (n == 1)
	{
		cout << n << "," << i << "," << k << endl;
	}
	else
	{
		int tmp = 6 - i - k;
		hanoi(n - 1, i, tmp);
		cout << n << "," << i << "," << k << endl;
		hanoi(n - 1, tmp, k);
	}
	return 2;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	hanoi(3, 1, 2);


	return 0;
}