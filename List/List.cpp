#include "stdafx.h"
//#include "TLink.h"
#include "../TPolinom/TPolinom.h"
#include <locale.h>
#include <iostream>
using namespace std;


int main() {
	string s = "1.";
	s = s + "2.";
	s[s.length() - 2]--;
	cout << s << endl;
	s.erase(s.length() - 2, 2);
	cout << s;
}



/*
int main() {
	//setlocale(LC_CTYPE, "Russian");
	char op;
	int mas[100][2];
	do {
		int n;
		cout << "Enter the number of monomials in the polynomial P:" << endl;
		cin >> n;
		cout << "Enter polynomial P in the format coefficient + degree:" << endl;
		for (int i = 0; i < n; i++) {
			cin >> mas[i][0];
			cin >> mas[i][1];
		}
		
		char op1;
		do {
			TPolinom P(mas, n);
			cout << "P = ";
			P.Print();
			cout << "1. Add 2 polynomials (P + Q);" << endl;
			cout << "2. Multiply a polynomial by a constant (P * c);" << endl;
			cout << "3. Subtraction of polynomials (P - Q)." << endl;
			cin >> op1;
			int n1 = 1;
			int mas1[100][2] = { 0,0 };
			if (op1 != '2')
			{
				cout << "Enter the number of monomials in the polynomial Q:" << endl;
				cin >> n1;
				cout << "Enter the polynomial Q in the format coefficient + degree:" << endl;
				for (int i = 0; i < n1; i++)
				{
					cin >> mas1[i][0];
					cin >> mas1[i][1];
				}
			}
			TPolinom Q(mas1, n1);
			if (op1 != '2') {
				cout << "Q = ";
				Q.Print();
			}
			switch (op1) {
			case '1': 
				P += Q;
				cout << "P + Q = ";
				P.Print();
				break;
			case '2': 
				cout << "Enter a constant:" << endl;
				int c;
				cin >> c;
				P *= c;
				cout << "P * " << c << " = ";
				P.Print();
				break;
			case '3': P -= Q;
				cout << "P - Q = ";
				P.Print();
				break;
			default: cout << "Invalid input. Enter value again:" << endl;
			}
			if ((op1 >= '1') && (op1 <= '3')) {
				do {
					cout << "1. Carry out a new operation with a polynomial P;" << endl; //Провести новую операцию с полиномом
					cout << "2. Reinsert polynomial P;" << endl;                         //Ввести полином P заново
					cout << "3. Shutdown." << endl;
					cin >> op;
					switch (op) {
					case '1': op1 = '0';
					case '2':
					case '3': break;
					default: cout << "Invalid input. Enter value again:" << endl;
					}
				} while ((op < '1') || (op > '3'));
			}
		} while ((op1 < '1') || (op1 > '3'));
	} while (op != '3');
	return 0;
}

*/