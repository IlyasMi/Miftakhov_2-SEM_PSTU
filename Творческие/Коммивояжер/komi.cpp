#include<iostream>
#include<string>

#include <SFML/Graphics.hpp>

using namespace std;
string st;
struct pare
{
	int main;
	int dop;
	int os_x;
	int os_y;
};
int made_arr(int(&arr)[9][8])
{
	arr[0][0] = -1;
	arr[0][1] = 6;
	arr[0][2] = 6;
	arr[0][3] = 4;
	arr[0][4] = 10;
	arr[0][5] = -1;
	arr[0][6] = -1;
	arr[0][7] = 0;
	arr[1][0] = 4;
	arr[1][1] = -1;
	arr[1][2] = -1;
	arr[1][3] = -1;
	arr[1][4] = 2;
	arr[1][5] = -1;
	arr[1][6] = -1;
	arr[1][7] = 0;
	arr[2][0] = 8;
	arr[2][1] = -1;
	arr[2][2] = -1;
	arr[2][3] = 2;
	arr[2][4] = -1;
	arr[2][5] = 1;
	arr[2][6] = -1;
	arr[2][7] = 0;
	arr[3][0] = 2;
	arr[3][1] = -1;
	arr[3][2] = 1;
	arr[3][3] = -1;
	arr[3][4] = -1;
	arr[3][5] = 10;
	arr[3][6] = -1;
	arr[3][7] = 0;
	arr[4][0] = 7;
	arr[4][1] = 5;
	arr[4][2] = -1;
	arr[4][3] = -1;
	arr[4][4] = -1;
	arr[4][5] = 2;
	arr[4][6] = 7;
	arr[4][7] = 0;
	arr[5][0] = -1;
	arr[5][1] = -1;
	arr[5][2] = 0;
	arr[5][3] = 8;
	arr[5][4] = 3;
	arr[5][5] = -1;
	arr[5][6] = 2;
	arr[5][7] = 0;
	arr[6][0] = -1;
	arr[6][1] = -1;
	arr[6][2] = -1;
	arr[6][3] = -1;
	arr[6][4] = 4;
	arr[6][5] = 6;
	arr[6][6] = -1;
	arr[6][7] = 0;
	arr[7][0] = 0;
	arr[7][1] = 0;
	arr[7][2] = 0;
	arr[7][3] = 0;
	arr[7][4] = 0;
	arr[7][5] = 0;
	arr[7][6] = 0;
	arr[7][7] = 0;
	arr[8][7] = 0;
	return arr[9][8];
}
void show_arr(int(&arr)[9][8])
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (arr[i][j] < 0)
			{
				cout << "M";
				cout << "\t";
			}
			else
			{
				cout << arr[i][j];
				cout << "\t";
			}

		}
		cout << endl;
	}
	cout << "                                       " << endl;
	cout << "                                       " << endl;
	cout << "                                       " << endl;
}
int min_line(int(&arr)[9][8], int i)
{
	int min = 100;
	for (int j = 0; j < 7; j++)
	{
		if ((arr[i][j] < min) && (arr[i][j] >= 0))
		{
			min = arr[i][j];
		}
	}
	return min;
}
int min_column(int(&arr)[9][8], int j)
{
	int min = 100;
	for (int i = 0; i < 7; i++)
	{
		if ((arr[i][j] < min) && (arr[i][j] >= 0))
		{
			min = arr[i][j];
		}
	}
	return min;
}
int reduction_lines(int(&arr)[9][8])
{
	for (int i = 0; i < 7; i++)
	{
		arr[i][7] = min_line(arr, i);
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			arr[i][j] = arr[i][j] - arr[i][7];
		}
	}
	return arr[9][8];
}
int reduction_columns(int(&arr)[9][8])
{
	for (int i = 0; i < 7; i++)
	{
		arr[7][i] = min_column(arr, i);
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			arr[i][j] = arr[i][j] - arr[7][j];
		}
	}
	return arr[9][8];
}
int mark(int(&arr)[9][8], int a, int b)
{
	int sum;

	int line = a;
	int column = b;
	int min_line = 100;
	int min_column = 100;
	for (int i = 0; i < 7; i++)
	{
		if ((arr[line][i] < min_line) && (i != b) && (arr[line][i] >= 0))
		{
			min_line = arr[line][i];
		}
	}
	for (int i = 0; i < 7; i++)
	{
		if ((arr[i][column] < min_column) && (i != a) && (arr[i][column] >= 0))
		{
			min_column = arr[i][column];
		}
	}
	sum = min_column + min_line;
	return sum;
}
int reduction_arr(int(&arr)[9][8], int(&arr1)[9][8])
{
	int result;
	for (int i = 0; i < 7; i++)
	{
		int a;
		int b;
		int temp1 = 0;
		int temp2 = 0;
		reduction_lines(arr);
		reduction_columns(arr);
		pare mas[8][8];
		int max_secret = 0;
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				mas[i][j].main = arr[i][j];
				mas[i][j].dop = 0;
			}
		}
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (arr[i][j] == 0)
				{
					mas[i][j].dop = mark(arr, i, j);
				}
			}
		}
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (mas[i][j].main == 0)
				{

					if (mas[i][j].dop > max_secret)
					{
						max_secret = mas[i][j].dop;
						temp1 = i;
						temp2 = j;
					}
				}
			}
		}

		for (int i = 0; i < 7; i++)
		{
			arr[temp1][i] = -1;
			arr[i][temp2] = -1;
		}
		arr[temp2][temp1] = -1;
		show_arr(arr);
		for (int i = 0; i < 8; i++)
		{
			arr[7][i] = 0;

		}
		for (int i = 0; i < 8; i++)
		{
			arr[i][7] = 0;
		}
	
		cout << temp1 + 1 << "->" << temp2 + 1 << endl;
		arr[8][7] += arr1[temp1][temp2];
	}
	st = to_string(arr[8][7]);
	return arr[8][7];
}
int main()
{
	setlocale(LC_ALL, "rus");

	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Salesman problem");
	window.setFramerateLimit(60);

	sf::Image image;
	image.loadFromFile("C:/Users/79024/Desktop/Fon.jpg");
	image.createMaskFromColor(image.getPixel(0, 0));

	sf::Texture texture;
	texture.loadFromImage(image);

	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::Font font;
	if (!font.loadFromFile("C:/Github/komi/komi/arialmt.ttf"))
	{
		return 2;
	}
	
	
	//создаем массив точек, по которым будут рисоваться линии:
	sf::VertexArray lines_1_2_1(sf::Lines, 16 /*количество точек*/);

	//далее для каждой из точек задаем свою позицию:
	lines_1_2_1[0].position = sf::Vector2f(40, 200);
	lines_1_2_1[1].position = sf::Vector2f(230, 50);
	//и т.д.
	
	//далее для каждой точки указываем цвет(так можно создавать градиенты):
	lines_1_2_1[0].color = sf::Color::White;
	lines_1_2_1[1].color = sf::Color::White;

	sf::VertexArray lines_1_2_2(sf::Lines, 16 /*количество точек*/);

	lines_1_2_2[0].position = sf::Vector2f(41, 201);
	lines_1_2_2[1].position = sf::Vector2f(231, 51);
	lines_1_2_2[0].color = sf::Color::White;
	lines_1_2_2[1].color = sf::Color::White;
	
	sf::VertexArray lines_2_5_1(sf::Lines, 16 /*количество точек*/);

	lines_2_5_1[0].position = sf::Vector2f(230, 50);
	lines_2_5_1[1].position = sf::Vector2f(430, 50);
	lines_2_5_1[0].color = sf::Color::White;
	lines_2_5_1[1].color = sf::Color::White;

	sf::VertexArray lines_2_5_2(sf::Lines, 16 /*количество точек*/);

	lines_2_5_2[0].position = sf::Vector2f(231, 51);
	lines_2_5_2[1].position = sf::Vector2f(431, 51);
	lines_2_5_2[0].color = sf::Color::White;
	lines_2_5_2[1].color = sf::Color::White;

	sf::VertexArray lines_5_7_1(sf::Lines, 16 /*количество точек*/);

	lines_5_7_1[0].position = sf::Vector2f(430, 50);
	lines_5_7_1[1].position = sf::Vector2f(630, 50);
	lines_5_7_1[0].color = sf::Color::White;
	lines_5_7_1[1].color = sf::Color::White;

	sf::VertexArray lines_5_7_2(sf::Lines, 16 /*количество точек*/);

	lines_5_7_2[0].position = sf::Vector2f(431, 51);
	lines_5_7_2[1].position = sf::Vector2f(631, 51);
	lines_5_7_2[0].color = sf::Color::White;
	lines_5_7_2[1].color = sf::Color::White;

	sf::VertexArray lines_7_6_1(sf::Lines, 16 /*количество точек*/);

	lines_7_6_1[0].position = sf::Vector2f(630, 50);
	lines_7_6_1[1].position = sf::Vector2f(630, 200);
	lines_7_6_1[0].color = sf::Color::White;
	lines_7_6_1[1].color = sf::Color::White;

	sf::VertexArray lines_7_6_2(sf::Lines, 16 /*количество точек*/);

	lines_7_6_2[0].position = sf::Vector2f(631, 51);
	lines_7_6_2[1].position = sf::Vector2f(631, 201);
	lines_7_6_2[0].color = sf::Color::White;
	lines_7_6_2[1].color = sf::Color::White;

	sf::VertexArray lines_6_4_1(sf::Lines, 16 /*количество точек*/);

	lines_6_4_1[0].position = sf::Vector2f(630, 200);
	lines_6_4_1[1].position = sf::Vector2f(480, 330);
	lines_6_4_1[0].color = sf::Color::White;
	lines_6_4_1[1].color = sf::Color::White;

	sf::VertexArray lines_6_4_2(sf::Lines, 16 /*количество точек*/);

	lines_6_4_1[0].position = sf::Vector2f(631, 201);
	lines_6_4_1[1].position = sf::Vector2f(481, 331);
	lines_6_4_1[0].color = sf::Color::White;
	lines_6_4_1[1].color = sf::Color::White;


	sf::VertexArray lines_4_3_1(sf::Lines, 16 /*количество точек*/);

	lines_4_3_1[0].position = sf::Vector2f(480, 330);
	lines_4_3_1[1].position = sf::Vector2f(330, 200);
	lines_4_3_1[0].color = sf::Color::White;
	lines_4_3_1[1].color = sf::Color::White;

	sf::VertexArray lines_4_3_2(sf::Lines, 16 /*количество точек*/);

	lines_4_3_2[0].position = sf::Vector2f(481, 331);
	lines_4_3_2[1].position = sf::Vector2f(331, 201);
	lines_4_3_2[0].color = sf::Color::White;
	lines_4_3_2[1].color = sf::Color::White;

	sf::VertexArray lines_6_3_1(sf::Lines, 16 /*количество точек*/);

	lines_6_3_1[0].position = sf::Vector2f(630, 200);
	lines_6_3_1[1].position = sf::Vector2f(330, 200);
	lines_6_3_1[0].color = sf::Color::White;
	lines_6_3_1[1].color = sf::Color::White;

	sf::VertexArray lines_6_3_2(sf::Lines, 16 /*количество точек*/);

	lines_6_3_2[0].position = sf::Vector2f(631, 201);
	lines_6_3_2[1].position = sf::Vector2f(331, 201);
	lines_6_3_2[0].color = sf::Color::White;
	lines_6_3_2[1].color = sf::Color::White;

	sf::VertexArray lines_3_1_1(sf::Lines, 16 /*количество точек*/);

	lines_3_1_1[0].position = sf::Vector2f(330, 200);
	lines_3_1_1[1].position = sf::Vector2f(40, 200);
	lines_3_1_1[0].color = sf::Color::White;
	lines_3_1_1[1].color = sf::Color::White;

	sf::VertexArray lines_3_1_2(sf::Lines, 16 /*количество точек*/);

	lines_3_1_2[0].position = sf::Vector2f(331, 201);
	lines_3_1_2[1].position = sf::Vector2f(41, 201);
	lines_3_1_2[0].color = sf::Color::White;
	lines_3_1_2[1].color = sf::Color::White;

	sf::VertexArray lines_1_4_1(sf::Lines, 16 /*количество точек*/);

	lines_1_4_1[0].position = sf::Vector2f(40, 200);
	lines_1_4_1[1].position = sf::Vector2f(480, 330);
	lines_1_4_1[0].color = sf::Color::White;
	lines_1_4_1[1].color = sf::Color::White;

	sf::VertexArray lines_1_4_2(sf::Lines, 16 /*количество точек*/);

	lines_1_4_2[0].position = sf::Vector2f(41, 201);
	lines_1_4_2[1].position = sf::Vector2f(481, 331);
	lines_1_4_2[0].color = sf::Color::White;
	lines_1_4_2[1].color = sf::Color::White;
	
	
	sf::VertexArray lines_1_5_1(sf::Lines, 16 /*количество точек*/);

	lines_1_5_1[0].position = sf::Vector2f(40, 200);
	lines_1_5_1[1].position = sf::Vector2f(430, 50);
	lines_1_5_1[0].color = sf::Color::White;
	lines_1_5_1[1].color = sf::Color::White;

	sf::VertexArray lines_1_5_2(sf::Lines, 16 /*количество точек*/);

	lines_1_5_2[0].position = sf::Vector2f(41, 201);
	lines_1_5_2[1].position = sf::Vector2f(431, 51);
	lines_1_5_2[0].color = sf::Color::White;
	lines_1_5_2[1].color = sf::Color::White;

	sf::VertexArray lines_5_6_1(sf::Lines, 16 /*количество точек*/);

	lines_5_6_1[0].position = sf::Vector2f(430, 50);
	lines_5_6_1[1].position = sf::Vector2f(630, 200);
	lines_5_6_1[0].color = sf::Color::White;
	lines_5_6_1[1].color = sf::Color::White;

	sf::VertexArray lines_5_6_2(sf::Lines, 16 /*количество точек*/);

	lines_5_6_2[0].position = sf::Vector2f(431, 51);
	lines_5_6_2[1].position = sf::Vector2f(631, 201);
	lines_5_6_2[0].color = sf::Color::White;
	lines_5_6_2[1].color = sf::Color::White;
	
	// Создаём текст
	sf::Text text_1("1", font,30);
	text_1.setStyle(sf::Text::Bold);
	text_1.setFillColor(sf::Color::White);
	text_1.setPosition(30, 175);

	sf::CircleShape circle_1;
	circle_1.setRadius(30);
	circle_1.setFillColor(sf::Color::Blue);
	circle_1.setOutlineColor(sf::Color::Blue);
	circle_1.setOutlineThickness(5);
	circle_1.setPosition(10, 170);
	//пара
	sf::Text text_2("2", font, 30);
	text_2.setStyle(sf::Text::Bold);
	text_2.setFillColor(sf::Color::White);
	text_2.setPosition(225, 25);

		sf::CircleShape circle_2;
		circle_2.setRadius(30);
		circle_2.setFillColor(sf::Color::Blue);
		circle_2.setOutlineColor(sf::Color::Blue);
		circle_2.setOutlineThickness(5);
		circle_2.setPosition(200, 20);
		//пара

		sf::Text text_5("5", font, 30);
		text_5.setStyle(sf::Text::Bold);
		text_5.setFillColor(sf::Color::White);
		text_5.setPosition(425, 25);

		sf::CircleShape circle_5;
		circle_5.setRadius(30);
		circle_5.setFillColor(sf::Color::Blue);
		circle_5.setOutlineColor(sf::Color::Blue);
		circle_5.setOutlineThickness(5);
		circle_5.setPosition(400, 20);
		//пара

		sf::Text text_7("7", font, 30);
		text_7.setStyle(sf::Text::Bold);
		text_7.setFillColor(sf::Color::White);
		text_7.setPosition(625, 25);

		sf::CircleShape circle_7;
		circle_7.setRadius(30);
		circle_7.setFillColor(sf::Color::Blue);
		circle_7.setOutlineColor(sf::Color::Blue);
		circle_7.setOutlineThickness(5);
		circle_7.setPosition(600, 20);
		//пара

		sf::Text text_6("6", font, 30);
		text_6.setStyle(sf::Text::Bold);
		text_6.setFillColor(sf::Color::White);
		text_6.setPosition(625, 175);

		sf::CircleShape circle_6;
		circle_6.setRadius(30);
		circle_6.setFillColor(sf::Color::Blue);
		circle_6.setOutlineColor(sf::Color::Blue);
		circle_6.setOutlineThickness(5);
		circle_6.setPosition(600, 170);
		//пара

		sf::Text text_3("3", font, 30);
		text_3.setStyle(sf::Text::Bold);
		text_3.setFillColor(sf::Color::White);
		text_3.setPosition(325, 175);

		sf::CircleShape circle_3;
		circle_3.setRadius(30);
		circle_3.setFillColor(sf::Color::Blue);
		circle_3.setOutlineColor(sf::Color::Blue);
		circle_3.setOutlineThickness(5);
		circle_3.setPosition(300, 170);
		//пара

		sf::Text text_4("4", font, 30);
		text_4.setStyle(sf::Text::Bold);
		text_4.setFillColor(sf::Color::White);
		text_4.setPosition(475, 305);

		sf::CircleShape circle_4;
		circle_4.setRadius(30);
		circle_4.setFillColor(sf::Color::Blue);
		circle_4.setOutlineColor(sf::Color::Blue);
		circle_4.setOutlineThickness(5);
		circle_4.setPosition(450, 300);
		//пара



		sf::Text ves_1_2("6", font, 20);
		ves_1_2.setStyle(sf::Text::Bold);
		ves_1_2.setFillColor(sf::Color::White);
		ves_1_2.setPosition(75, 125);

		sf::Text ves_1_5("10", font, 20);
		ves_1_5.setStyle(sf::Text::Bold);
		ves_1_5.setFillColor(sf::Color::White);
		ves_1_5.setPosition(105, 145);

		sf::Text ves_1_3("6", font, 20);
		ves_1_3.setStyle(sf::Text::Bold);
		ves_1_3.setFillColor(sf::Color::White);
		ves_1_3.setPosition(105, 175);

		sf::Text ves_1_4("4", font, 20);
		ves_1_4.setStyle(sf::Text::Bold);
		ves_1_4.setFillColor(sf::Color::White);
		ves_1_4.setPosition(105, 198);

		sf::Text ves_2_1("4", font, 20);
		ves_2_1.setStyle(sf::Text::Bold);
		ves_2_1.setFillColor(sf::Color::White);
		ves_2_1.setPosition(150, 70);

		sf::Text ves_2_5("2", font, 20);
		ves_2_5.setStyle(sf::Text::Bold);
		ves_2_5.setFillColor(sf::Color::White);
		ves_2_5.setPosition(280, 25);


		sf::Text ves_5_2("5", font, 20);
		ves_5_2.setStyle(sf::Text::Bold);
		ves_5_2.setFillColor(sf::Color::White);
		ves_5_2.setPosition(380, 25);

		sf::Text ves_5_1("7", font, 20);
		ves_5_1.setStyle(sf::Text::Bold);
		ves_5_1.setFillColor(sf::Color::White);
		ves_5_1.setPosition(350, 50);


		sf::Text ves_5_7("7", font, 20);
		ves_5_7.setStyle(sf::Text::Bold);
		ves_5_7.setFillColor(sf::Color::White);
		ves_5_7.setPosition(480, 25);

		sf::Text ves_5_6("2", font, 20);
		ves_5_6.setStyle(sf::Text::Bold);
		ves_5_6.setFillColor(sf::Color::White);
		ves_5_6.setPosition(480, 60);

		sf::Text ves_7_5("4", font, 20);
		ves_7_5.setStyle(sf::Text::Bold);
		ves_7_5.setFillColor(sf::Color::White);
		ves_7_5.setPosition(580, 25);

		sf::Text ves_7_6("6", font, 20);
		ves_7_6.setStyle(sf::Text::Bold);
		ves_7_6.setFillColor(sf::Color::White);
		ves_7_6.setPosition(640, 85);

		sf::Text ves_6_3("0", font, 20);
		ves_6_3.setStyle(sf::Text::Bold);
		ves_6_3.setFillColor(sf::Color::White);
		ves_6_3.setPosition(555, 170);

		sf::Text ves_6_5("3", font, 20);
		ves_6_5.setStyle(sf::Text::Bold);
		ves_6_5.setFillColor(sf::Color::White);
		ves_6_5.setPosition(555, 120);

		sf::Text ves_6_4("8", font, 20);
		ves_6_4.setStyle(sf::Text::Bold);
		ves_6_4.setFillColor(sf::Color::White);
		ves_6_4.setPosition(565, 225);

		sf::Text ves_4_6("10", font, 20);
		ves_4_6.setStyle(sf::Text::Bold);
		ves_4_6.setFillColor(sf::Color::White);
		ves_4_6.setPosition(500, 265);

		sf::Text ves_4_3("1", font, 20);
		ves_4_3.setStyle(sf::Text::Bold);
		ves_4_3.setFillColor(sf::Color::White);
		ves_4_3.setPosition(440, 265);

		sf::Text ves_4_1("2", font, 20);
		ves_4_1.setStyle(sf::Text::Bold);
		ves_4_1.setFillColor(sf::Color::White);
		ves_4_1.setPosition(400, 280);

		sf::Text ves_3_1("8", font, 20);
		ves_3_1.setStyle(sf::Text::Bold);
		ves_3_1.setFillColor(sf::Color::White);
		ves_3_1.setPosition(260, 170);

		sf::Text ves_3_6("1", font, 20);
		ves_3_6.setStyle(sf::Text::Bold);
		ves_3_6.setFillColor(sf::Color::White);
		ves_3_6.setPosition(380, 170);

		sf::Text ves_3_4("2", font, 20);
		ves_3_4.setStyle(sf::Text::Bold);
		ves_3_4.setFillColor(sf::Color::White);
		ves_3_4.setPosition(380, 215);

		sf::Text key("Press Enter to run OR Press Escape to exit", font, 20);
		key.setStyle(sf::Text::Bold);
		key.setFillColor(sf::Color::White);
		key.setPosition(200, 400);

		sf::Text marsh("                Route                ", font, 20);
		marsh.setStyle(sf::Text::Bold);
		marsh.setFillColor(sf::Color::White);
		marsh.setPosition(200, 500);
		
		sf::Text len("   WAY   ", font, 20);
		len.setStyle(sf::Text::Bold);
		len.setFillColor(sf::Color::White);
		len.setPosition(400, 550);


	sf::Event event;
	
	while (window.isOpen())
	{
		
		
			
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				// Получаем нажатую клавишу - выполняем соответствующее действие
				if (event.key.code == sf::Keyboard::Escape) window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
				case sf::Keyboard::Enter:  // обработка нажатия Escape
					
					int arr[9][8];
					int arr1[9][8];
					arr[9][8] = made_arr(arr);
					arr1[9][8] = made_arr(arr1);
					show_arr(arr);
					cout << reduction_arr(arr, arr1);
					marsh.setString("6->7->5->2->1->4->3->6");
					
					len.setString(st);
				
					break;
				}
			}
		}

		// Выполняем необходимые действия по отрисовке
		window.clear();
		window.draw(sprite);
		window.draw(lines_1_2_1);
		window.draw(lines_1_2_2);
		window.draw(lines_2_5_1);
		window.draw(lines_2_5_2);
		window.draw(lines_5_7_1);
		window.draw(lines_5_7_2);
		window.draw(lines_7_6_1);
		window.draw(lines_7_6_2);
		window.draw(lines_6_4_1);
		window.draw(lines_6_4_2);
		window.draw(lines_4_3_1);
		window.draw(lines_4_3_2);
		window.draw(lines_6_3_1);
		window.draw(lines_6_3_2);
		window.draw(lines_3_1_1);
		window.draw(lines_3_1_2);
		window.draw(lines_1_4_1);
		window.draw(lines_1_4_2);
		window.draw(lines_1_5_1);
		window.draw(lines_1_5_2);
		window.draw(lines_5_6_1);
		window.draw(lines_5_6_2);
		window.draw(ves_1_2);
		window.draw(ves_1_5);
		window.draw(ves_1_3);
		window.draw(ves_1_4);
		window.draw(ves_2_1);
		window.draw(ves_2_5);
		window.draw(ves_5_2);
		window.draw(ves_5_1);
		window.draw(ves_5_7);
		window.draw(ves_5_6);
		window.draw(ves_7_5);
		window.draw(ves_7_6);
		window.draw(ves_6_3);
		window.draw(ves_6_5);
		window.draw(ves_6_4);
		window.draw(ves_4_6);
		window.draw(ves_4_3);
		window.draw(ves_4_1);
		window.draw(ves_3_1);
		window.draw(ves_3_6);
		window.draw(ves_3_4);
		window.draw(circle_1);
		window.draw(text_1);
		window.draw(circle_2);
		window.draw(text_2); 
		window.draw(circle_3);
		window.draw(text_3);
		window.draw(circle_4);
		window.draw(text_4);
		window.draw(circle_5);
		window.draw(text_5);
		window.draw(circle_6);
		window.draw(text_6);
		window.draw(circle_7);
		window.draw(text_7);
		window.draw(key);
		window.draw(marsh);
		window.draw(len);
		window.display();
	}
	
}