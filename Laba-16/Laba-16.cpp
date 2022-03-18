#include<iostream>
#include<string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	string str = "strl";
	string fullstr = "submissionstrl";
	int strl = str.size(); int fullstrl = fullstr.size(); int result = -1;
	if (strl != 0 && fullstrl != 0)
	{
		int i; int Pos;
		int table[256];
		for (int i = 0; i < 256; i++)
		{
			table[i] = strl;
		}
		for (i = strl - 2; i >= 0; i--)
		{
			if (table[int((unsigned char)str[i])] == strl)
			{
				table[int((unsigned char)str[i])] = strl - i - 1;
			}
		}
		Pos = strl - 1;
		while (Pos < fullstrl)
		{
			if (str[strl - 1] != fullstr[Pos])
			{
				Pos += table[int((unsigned char)fullstr[Pos])];
			}
			else
			{
				for (i = strl - 1; i >= 0; i--)
				{
					if (str[i] != fullstr[Pos - strl + i + 1])
					{
						Pos += table[int((unsigned char)fullstr[Pos - strl + i + 1])];
						break;
					}
					else if (i == 0)
					{
						return Pos - strl + 1;

					}
				} 
			}
		}
	}
}