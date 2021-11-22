#include <iostream>
#include <vector>
using namespace std;

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

bool check(string str) {
	int counter = 0;
	for (int i = 0; i < str.length(); i++) {   // проверка на буквы
		if (('A' <= str[i]) && (str[i] <= 'Z')) {
			counter++;
		}
	}
	return (str.size() == counter);
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int n1, n2;
	string str;
	str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vector <char> mass;
	vector <int> chislo;
	cout << "Введите систему счисления исходного числа (2 - 36): ";
	cin >> n1;
	n1 = proverka_int(n1);
	bool flag = 1;

	if (n1 == 10) {
		int str1;
		cout << "Введите исходное число: ";
		cin >> str1;
		str1 = proverka_int(str1);
		cout << "Введите систему счисления, в которую необходимо перевести исходное число: ";
		cin >> n2;
		n2 = proverka_int(n2);

		if ((n2 > 1) && (n2 < 37) && (n2 != 10)) {
			while (str1 > 0) {
				mass.push_back(str[str1 % n2]);
				str1 /= n2;
			}
		}

		else {
			flag = 0;
		}
	}

	else if ((n1 > 1) && (n1 < 37) && (n1 != 10)) {
		string str1;
		cout << "Введите исходное число: ";
		cin >> str1;

		if (check(str1)) {
			cout << "Введите систему счисления, в которую необходимо перевести исходное число: ";
			cin >> n2;
			n2 = proverka_int(n2);

			if ((n2 > 1) && (n2 < 37) && (n2 != 10)) {
				int counter = 0;
				int sum = 0;
				for (int i = 0; i < str1.size(); i++) {
					sum += poisk(str, str1[i]) * pow(n1, str1.size() - i - 1);
				}

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


	if (flag) {
		int x;
		for (int c = 0; c < mass.size() / 2; c++) {
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
}