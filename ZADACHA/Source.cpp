#include<iostream>
#include<Windows.h>

using namespace std;

void imput(double arg [3][4]) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			cin >> arg[i][j];
}

void newmat(double mas[3][3], int iobm, double arg[3][4]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (j != iobm) {
				if (j > iobm) mas[i][j - 1] = arg[i][j];
				else mas[i][j] = arg[i][j];
			}
		}
	}
}

double determinate(double mas[3][3]) {
	double det = 
		mas[0][0] * mas[1][1] * mas[2][2] + 
		mas[0][1] * mas[1][2] * mas[2][0] + 
		mas[0][2] * mas[1][0] * mas[2][1] - 
		mas[0][2] * mas[1][1] * mas[2][0] - 
		mas[0][1] * mas[1][0] * mas[2][2] - 
		mas[0][0] * mas[1][2] * mas[2][1];
	return (det);
}


void main() {
	system("chcp 1251 >> NUL");
	cout << "Введіть аргументи системи" << endl;
	double arg[3][4], mas[3][3], det, detx, dety, detz, x, y, z;
	imput(arg);
	newmat(mas, 3, arg);
	det = determinate(mas);
	if (det != 0) {
		newmat(mas, 0, arg);
		detx = determinate(mas);

		newmat(mas, 1, arg);
		dety = determinate(mas);

		newmat(mas, 2, arg);
		detz = determinate(mas);
		x = det / detx;
		y = det / dety;
		z = det / detz;
		cout << "Корені:\tx=" << x << "\ty=" << y << "\tz=" << z << endl;
	}
	else cout << "Безліч коренів!" << endl;
	system("pause");
}