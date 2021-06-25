#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	int a, p, q;
	cout << "enter an integer" << endl;
	cin >> a;
	for (p = sizeof(a) * 8 - 1; p >= 0; --p)
	{
		cout << ((int)(a >> p) & 1);
	}

	float t;
	cout << endl << "enter a real number" << endl;
	cin >> t;
	int n = *((int*)&t);
	int h;
	for (h = sizeof(t) * 8 - 1; h >= 0; --h)
	{
		cout << ((int)(n >> h) & 1);
	}

  
	int z,m;
    char c;
	cout << endl << "enter the symbol" << endl;
	cin >> c;
	m = (int)c;
	for (z = sizeof(c) * 8 - 1; z >= 0; --z)
	cout << ((int)(m >> z) & 1);
	cout << endl;
	system("pause");
	return 0;

}