#include<iostream>
#include<string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	string str = "strl";
	string full = "ststststrsltstlstrlss";
	int i, j, strlen, fullen; int k = 0;
	strlen = str.size(); fullen = full.size();
	int*d = new int[fullen];
	char*low = new char[fullen];
	char*del = new char[fullen - strlen];
	i = 0; j = -1;
	d[0] = -1;
	while (i < strlen - 1)
	{
		while (j >= 0 && str[j] != str[i])
		{
			j = d[j];
		}
		++i; ++j;
		if (str[i] == str[j])
		{
			d[i] = d[j];
		}
		else
		{
			d[i] = j;
		}
	}
	i = 0; j = 0;
	for (i = 0, j = 0; (i <= fullen - 1) && (j <= strlen - 1); i++, j++)
	{
		while ((j >= 0) && (str[j] != full[i]))
		{
			j = d[j];
		}
	}
	delete[]d;
	int pos = i - j;
	cout<< pos << endl;
	for (k; k <= fullen; k++)
	{
		low[k] = full[k];
	}
	k = 0;
	while (k <= fullen)
	{
		cout << low[k];
		k++;
	}
	cout << endl;
	if (j == strlen)
	{
		k = 0;
		for (k; k <= fullen; k++)
		{
			if (k == pos)
			{
				for (k = pos; k <= fullen; k++)
				{
					del[k] = low[k + strlen];
				}
			}
			else if (k != pos)
			{
				del[k] = low[k];
			}
		}
		k = 0;
		while (k <= fullen - strlen)
		{
			cout<< del[k];
			k++;
		}
	}
	else { return -1; }
}