#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

char zadacha2(int x)
{
	if (x < 0) {
		return '-';
	}
	else if (x > 0) {
		return '+';
	}
	else {
		return '0';
	}
}

int f(int m, int i, int c)
{
	if (i == 0) {
		return 0;
	}

	if (i > 0) {
		return ((m * f(m, i - 1, c) + i) % c);
	}
}

double rectangle(double a, double b)
{
	return a * b;
}

double triangle(double a, double h)
{
	return a * h / 2;
}

double circle(double r)
{
	double pi = atan(1) * 4;
	return pi * r * r;
}

int poisk(string str, char a) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == a) {
			return i;
			break;
		}
	}
}

int proverka_int(int a) {
	int flag = 0;
	while (true) {
		if (flag == 1) {
			cin >> a;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(100000, '\n');
				cout << "Данные некорректны! Повторите попытку ввода: ";
			}
			else
				return a;
		}

		else {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100000, '\n');
				cout << "Данные некорректны! Повторите попытку ввода: ";
			}
			else {
				return a;
			}
			flag = 1;
		}
	}
}

bool check(string str) { // проверка на допустимые символы
	int counter = 0;
	for (int i = 0; i < str.length(); i++) {
		if (('A' <= str[i]) && (str[i] <= 'Z') || ('0' <= str[i]) && (str[i] <= '9')) {
			counter++;
		}
	}
	return (str.size() == counter);
}

bool check2(string str, int n) { // проверка на допустимые символы в данной сс
	string str1 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int counter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == str1[i]) {
				counter++;
			}
		}
	}
	return (str.size() == counter);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int counter = 1;
	while (counter != 0) {
		int n;
		cout << "Введите номер задачи (для выхода введите 0): ";
		cin >> n;
		cout << endl;

		switch (n)
		{
		case 1:
		{
			fstream file("C:\\Users\\Ivan\\Desktop\\example1.txt");
			cout << "Файл создан!" << endl;
			double s = 0;

			if (file.is_open()) {
				cout << "Файл открыт!" << endl;
				string str;
				int counter = 0;
				cout << "Введите 10 чисел каждое с новой строки: " << endl;
				for (int i = 0; i < 10; i++) {
					double c;
					cin >> c;
					file << c << ' ';
				}
				double c = 0;
				cout << "Числа записаны!" << endl;
				file.seekg(0); // возвращение в начало файла
				while (!file.eof()) {
					if (file >> c) {
						s += c;
					}
					else {
						file.clear();
						file.ignore(1, ' ');
					}
				}
				cout << "Сумма чисел равна: " << s << endl;
			}

			else {
				cout << "Ошибка открытия файла!" << endl;
			}
			break;
		}

		case 2:
		{
			int x;
			cout << "Введите число: ";
			cin >> x;
			if (zadacha2(x) != '0') {
				cout << "Знак введенного числа: " << zadacha2(x) << endl;
			}
			else {
				cout << "Знак отсутствует" << endl;
			}
			break;
		}

		case 3:
		{
			int x;
			cout << "Укажите номер фигуры, площадь которой необходимо найти (прямоугольник - 1; треугольник - 2; круг - 3)" << endl;
			cout << "Номер фигуры: ";
			cin >> x;
			if (x == 1) {
				double a, b;
				cout << "Введите длину первой стороны: ";
				cin >> a;
				cout << "Введите длину второй стороны: ";
				cin >> b;
				if ((a <= 0) || (b <= 0)) {

					cout << "Данные некорректны";
					break;
				}
				else {
					cout << "Площадь прямоугольника равна " << rectangle(a, b) << endl;
				}
			}

			else if (x == 2) {
				double a, h;
				cout << "Введите длину основания треугольника: ";
				cin >> a;
				cout << "Введите длину высоты треугольника: ";
				cin >> h;
				if ((a <= 0) || (h <= 0)) {
					cout << endl;
					cout << "Данные некорректны" << endl;
					break;
				}
				else {
					cout << "Площадь треугольника равна " << triangle(a, h) << endl;
				}
			}

			else if (x == 3) {
				double r;
				cout << "Введите радиус круга: ";
				cin >> r;
				if (r <= 0) {

					cout << "Данные некорректны";
				}
				else {
					cout << "Площадь круга равна " << circle(r) << endl;
				}
			}
			else {
				cout << "Ошибка. Введенные данные некорректны!" << endl;
			}
			break;
		}

		case 4:
		{
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					cout << "* ";
				}
				for (int n = 0; n < 18; n++) {
					cout << "- ";
				}
				cout << endl;
			}
			for (int m = 0; m < 6; m++) {
				for (int c = 0; c < 26; c++) {
					cout << "- ";
				}
				cout << endl;

			}
			break;
		}

		case 5:
		{
			int num = 7;
			double PI = atan(1) * 4;
			for (double y = 2; y >= 0; y -= 0.2) {
				for (double x = 0; x <= num; x += 0.2) {

					if ((0.1 + x >= asin(y - 1)) && (x - 0.1 <= asin(y - 1)) || (0.1 + x >= PI - asin(y - 1)) && (x - 0.1 <= PI - asin(y - 1)) ||
						(2 * PI - (0.1 + x) <= -asin(y - 1)) && (2 * PI - (x - 0.1) >= -asin(y - 1))) {
						cout << '*';
					}

					else {
						cout << ' ';
					}

				}
				cout << endl;
			}

			break;
		}

		case 6:
		{
			string str;
			int sum = 0, counter = 0, count = 0, flag = 0;
			int x = 0, c = 0, m = 0, flagv = 0, flagx = 0, fx = 0, flag49 = 0, flagL = 0;
			cout << "Введите римскую запись числа: ";
			cin >> str;
			int len = str.length();

			if (len == 1) {
				counter += 1;
				switch (str[0])
				{
				case 'I':
					sum += 1;
					break;
				case 'V':
					sum += 5;
					break;
				case 'X':
					sum += 10;
					break;
				case 'L':
					sum += 50;
					break;
				case 'C':
					sum += 100;
					break;
				case 'D':
					sum += 500;
					break;
				case 'M':
					sum += 1000;
					break;
				default:
					break;
				}
			}

			else if (len > 1) {
				for (int i = 0; i < len - 1; i++) {
					switch (str[i])
					{
					case 'I':
						if ((str[i + 1] == 'I') && (count < 3)) {
							if (flag == 0) {
								sum += 2;
								counter += 2;
								count += 2;
								flag = 1;
								i++;
							}
						}
						else if ((str[i + 1] == 'V') && (flag == 0) && (flagv == 0)) {
							sum += 4;
							counter += 2;
							i++;
							flag = 1;
							flag49 = 1;
						}
						else if ((str[i + 1] == 'X') && (flag == 0)) {
							sum += 9;
							counter += 2;
							i++;
							flag = 1;
							flag49 = 1;
						}
						else if ((count < 3) && (flag49 == 0)) {
							sum += 1;
							counter += 1;
							count += 1;
						}
						break;

					case 'V':
						if ((str[i + 1] != 'V') && (str[i + 1] != 'X') && (str[i + 1] != 'L') && (str[i + 1] != 'C') && (str[i + 1] != 'D') && (str[i + 1] != 'M') && (flagv == 0)) {
							sum += 5;
							counter += 1;
							flagv = 1;
						}
						break;

					case 'X':
						if ((str[i + 1] == 'X') && (x < 3)) {
							if (fx == 0) {
								sum += 20;
								x += 2;
								counter += 2;
								fx = 1;
								i++;
							}
						}
						else if (str[i + 1] == 'L') {
							sum += 40;
							counter += 2;
							i++;
						}
						else if (str[i + 1] == 'C') {
							sum += 90;
							counter += 2;
							i++;
						}
						else if ((str[i + 1] != 'D') && (str[i + 1] != 'M') && (str[i + 1] != 'X') && (flagx == 0)) {
							sum += 10;
							counter += 1;
							flagx = 1;
						}
						break;

					case 'L':
						if ((str[i + 1] != 'C') && (str[i + 1] != 'D') && (str[i + 1] != 'M') && (flagL == 0)) {
							sum += 50;
							counter += 1;
							flagL = 1;
						}
						break;

					case 'C':
						if (str[i + 1] == 'D') {
							sum += 400;
							counter += 2;
							i++;
						}
						else if (str[i + 1] == 'M') {
							sum += 900;
							counter += 2;
							i++;
						}
						else if (c < 3) {
							sum += 100;
							counter += 1;
							c += 1;
						}
						break;

					case 'D':
						if ((str[i + 1] != 'D') && (str[i + 1] != 'M')) {
							sum += 500;
							counter += 1;
						}
						break;

					case 'M':
						if (m < 3) {
							sum += 1000;
							counter += 1;
							m += 1;
						}

					default:
						break;
					}
				}

				if ((counter + 1) == str.length()) { // считывание повторяющихся символов в конце
					switch (str[len - 1])
					{
					case 'I':
						if ((str[len - 2] == 'I') && (count < 3)) {
							sum += 1;
							counter += 1;
						}
						else if ((flagx == 0) && (flag49 == 0)) {
							sum += 1;
							counter += 1;
						}
						break;

					case 'X':
						if ((str[len - 2] == 'X') && (x < 3)) {
							sum += 10;
							counter += 1;
						}
						break;

					case 'C':
						if ((str[len - 2] == 'C') && (c < 3)) {
							sum += 100;
							counter += 1;
						}
						break;

					default:
						break;
					}
				}
			}

			if (counter == str.length()) {   // если вся запись римского числа верная - выводим полученное число
				cout << "Полученное число: " << sum << endl;
			}
			else {
				cout << "Данные некорректны!" << endl;
			}

			//cout << sum << endl;
			//cout << counter;
			cout << endl;
			break;
		}

		case 7:
		{
			int m, i, c;
			cout << "Введите целое число m: ";
			cin >> m;
			cout << "Введите целое число i: ";
			cin >> i;
			cout << "Введите целое число c: ";
			cin >> c;
			cout << "Полученное псевдослучайное число: " << f(m, i, c) << endl;
			break;
		}

		case 8:
		{
			double a[3][4] = { {5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0} };
			double b[4][2] = { {1.2, 0.5}, {2.8, 0.4}, {5, 1}, {2, 1.5} };
			double c[3][2] = { 0 };
			int m1 = 0, m2 = 0, m3 = 0, flag = 0;
			double n1 = 0, n2 = 0, n3 = 0, n4 = 0, m4 = 0, sumv = 0, sumk = 0, sumd = 0;

			cout << "Матрица A:" << endl;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 4; j++) {
					cout << a[i][j] << ' ';
				}
				cout << endl;
			}
			cout << endl;

			cout << "Матрица B:" << endl;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 2; j++) {
					cout << b[i][j] << ' ';
				}
				cout << endl;
			}
			cout << endl;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 2; j++) {
					for (int k = 0; k < 4; k++) {
						c[i][j] += a[i][k] * b[k][j];
					}
				}
			}

			cout << "Матрица С = AxB:" << endl;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 2; j++) {
					cout << c[i][j] << ' ';
					sumd += c[i][j];
				}
				cout << endl;
			}
			cout << endl;

			for (int i = 0; i < 3; i++) {
				if (c[i][0] > n1) {
					n1 = c[i][0];
					m1 = i + 1;
				}
				if (flag == 0) {
					n2 = c[0][0];
					n4 = c[0][1];
					flag = 1;
				}
				else if (c[i][0] < n2) {
					n2 = c[i][0];
					m2 = i + 1;
				}
				if (c[i][1] > n3) {
					n3 = c[i][1];
					m3 = i + 1;
				}
				if (c[i][1] < n4) {
					n4 = c[i][1];
					m4 = i + 1;
				}
				sumv += c[i][0];
				sumk += c[i][1];
			}

			cout << "Больше денег с продажи выручил - " << m1 << " продавец" << endl;
			cout << "Меньше денег с продажи выручил - " << m2 << " продавец" << endl;
			cout << "Наибольшие комиссионные получил - " << m3 << " продавец" << endl;
			cout << "Наименьшие комиссионные получил - " << m4 << " продавец" << endl;
			cout << "Общая сумма выручки - " << sumv << endl;
			cout << "Общая сумма комиссионных - " << sumk << endl;
			cout << "Общая сумма денег - " << sumd << endl;
			cout << endl;
			break;
		}

		case 9:
		{
			int n1, n2;
			string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			vector <char> mass;
			vector <int> chislo;
			cout << "Введите систему счисления исходного числа (2 - 36): ";
			cin >> n1;
			n1 = proverka_int(n1);
			bool flag = 1; // флаг для проверки всех условий

			if (n1 == 10) { // перевод из 10 сс в любую
				int str1;
				cout << "Введите исходное число: ";
				cin >> str1;
				str1 = proverka_int(str1);
				cout << "Введите систему счисления, в которую необходимо перевести исходное число: ";
				cin >> n2;
				n2 = proverka_int(n2);

				if ((n2 > 1) && (n2 < 37)) { // условие на основание сс (от 2 до 36)
					while (str1 > 0) {
						mass.push_back(str[str1 % n2]);
						str1 /= n2;
					}
				}

				else {
					flag = 0;
				}
			}

			else if ((n1 > 1) && (n1 < 37) && (n1 != 10)) { // перевод из остальных сс в любую
				string str1;
				cout << "Введите исходное число: ";
				cin >> str1;

				if (check(str1) && check2(str1, n1)) { // проверка на допустимые символы
					cout << "Введите систему счисления, в которую необходимо перевести исходное число: ";
					cin >> n2;
					n2 = proverka_int(n2);

					// перевод в 10-ю сс
					if ((n2 > 1) && (n2 < 37)) { // условие на основание сс (от 2 до 36)
						int sum = 0;
						for (int i = 0; i < str1.size(); i++) {
							sum += poisk(str, str1[i]) * pow(n1, str1.size() - i - 1);
						}

						// перевод в n2-ю сс
						while (sum > 0) {
							mass.push_back(str[sum % n2]);
							sum /= n2;
						}
					}

					else {
						flag = 0;
					}
				}

				else {
					flag = 0;
				}
			}

			else {
				flag = 0;
			}


			if (flag) { // если все данные введены верно
				int x;
				for (int c = 0; c < mass.size() / 2; c++) { // полученное число записано справа налево, поэтому меняем местами все элементы массива
					x = mass[c];
					mass[c] = mass[mass.size() - c - 1];
					mass[mass.size() - c - 1] = x;
				}

				cout << "Полученное число: ";

				for (int y = 0; y < mass.size(); y++) {
					cout << (char)mass[y];
				}
				cout << endl;
			}

			else {
				cout << "Данные некорректны!" << endl;
			}

			break;
		}

		case 0:
		{
			counter = 0;
			break;
		}

		default:
			cout << "Ошибка. Введенные данные некорректны!" << endl << endl;
			break;
		}
	}
}