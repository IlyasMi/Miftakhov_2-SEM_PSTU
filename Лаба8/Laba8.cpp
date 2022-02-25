#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<fstream>
#include<string>
#include<fstream>
using namespace std;

struct Film
{
	char name[50];
	char producter[50];
	char country[50];
	int money;
	
};


int main()
{
	setlocale(LC_ALL, "Russian");
	FILE *outfile;
	outfile = fopen("Film.txt", "w");
	if (outfile == NULL) { cout << "Error" << endl; exit(1); }
	Film best[4];    //= { "The Road", "Jonh Hillkout", "USA", 27 };
	best[0]= { "The Road ", "Jonh Hillkout", " USA ", 27 };
	best[1] = { "The Monkey ", "Kriss Hillkout", " Africa ", 2 };
	best[2] = { "The Rabbit ", "Jonh Lennon",  "Russia ", 279 };
	best[3] = { "Helen ", "Lisa Rasmus", " UK ", 10 };

	cout << endl;
	Film*line = new Film[4];
	line[0]=best[0];
	line[1]=best[1];
	line[2]=best[2];
	line[3]=best[3];
	for (int i = 0; i < 4; i++)
	{
		cout << line[i].name << line[i].producter << line[i].country << line[i].money << endl;
	}
	cout << endl;
	Film*gline = new Film[2];
	gline[0] = line[0];
	gline[1] = line[1];
	for (int i = 0; i < 2; i++)
	{
		cout << gline[i].name << gline[i].producter << gline[i].country << gline[i].money << endl;
	}
	cout << endl;
	Film*ggline = new Film[3];
	ggline[0] = gline[0];
	ggline[1] = { "The Pudge ", " Christopher Nolan ", " USA ", 4234 };
	ggline[2] = gline[1];
	for (int i = 0; i < 3; i++)
	{
		cout << ggline[i].name << ggline[i].producter << ggline[i].country << ggline[i].money << endl;
	}
	best[0] = ggline[0];
	best[1] = ggline[1];
	best[2] = ggline[2];
	fwrite(&best, sizeof(struct Film), 1, outfile);
	if (fwrite != 0) {
		cout << "contents to file written successfully !";
	}
	else {
		cout << "error writing file !";
	}
	cout << endl;
	delete[] line;
	delete[] gline;
	delete[] ggline;
	// close file
fclose(outfile);
	cout << endl;
	FILE *outfil;
	outfil = fopen("Film.txt", "r");
	if (outfil == NULL) { cout << "Error" << endl; exit(5); }
	 //read file contents till end of file

	while (fread(&best, sizeof(struct Film), 1, outfil))
		for (int i = 0; i < 3; i++)
		{
			cout << best[i].name << " " << best[i].producter << " " << best[i].country << " " << best[i].money << endl;
		}
fclose(outfil);//вывод строки ВСЕ

	return 0;
}