// Скопировать из файла F1 в файл F2 все строки, в которых есть слова,
// совпадающие с первым словом.
// Определить количество согласных букв в последней строке файла F2.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	ifstream in("f1.txt");
	ofstream out("f2.txt");
	string line, firstWord, word;
	while (getline(in, line))
	{
		stringstream ss(line);
		bool hasEquals = false;
		ss >> firstWord;
		while (ss >> word)
		{
			if (word == firstWord)
			{
				hasEquals = true;
				break;
			}
		}
		if (hasEquals) out << line << endl;
	}
	string consonants("bcdfghjklmnpqrstvwxz");
	int consCount = 0;
	for (auto it = line.begin(); it != line.end(); it++)
		if (consonants.find(*it) != string::npos)
			consCount++;
	cout << "Consonants count: " << consCount;
	in.close();
	out.close();
	return 0;
}